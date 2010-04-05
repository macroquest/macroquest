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
#define __ExpectedVersionDate                                     "Dec 17 2009"
#define __ExpectedVersionTime                                     "13:40:14"
#define __ActualVersionDate                                        0x817BC8
#define __ActualVersionTime                                        0x817BD4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x511100
#define __MemChecker1                                              0x6E0440
#define __MemChecker2                                              0x570E90
#define __MemChecker3                                              0x570DE0
#define __MemChecker4                                              0x694750
#define __EncryptPad0                                              0x8A8190
#define __EncryptPad1                                              0x8B3290
#define __EncryptPad2                                              0x8AADC8
#define __EncryptPad3                                              0x8AA9C8
#define __EncryptPad4                                              0x8B28D8
#define __AC1                                                      0x65C640
#define __AC2                                                      0x4D9195
#define __AC3                                                      0x4ED168
#define __AC4                                                      0x4F1038
#define __AC5                                                      0x4FB788
#define __AC6                                                      0x4FEC0B
#define __AC7                                                      0x4F7CB4
#define __AC1_Data                                                 0x8003D0

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
#define __do_loot                                                  0x4B1ED0
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
#define __CastRay                                                  0x4C5C30
#define __ConvertItemTags                                          0x4B7550
#define __ExecuteCmd                                               0x4A3C10
#define __get_melee_range                                          0x4A9530
#define __GetGaugeValueFromEQ                                      0x65B500
#define __GetLabelFromEQ                                           0x65C5E0
#define __GetXTargetType                                           0x74E570
#define __LoadFrontEnd                                             0x56FD50
#define __NewUIINI                                                 0x65B090
#define __ProcessGameEvents                                        0x4F80A0
#define CrashDetected                                              0x56FB50
#define DrawNetStatus                                              0x519C40
#define Util__FastTime                                             0x6E0B50


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47ADE0
#define AltAdvManager__IsAbilityReady                              0x47AE20
#define AltAdvManager__GetAltAbility                               0x47B0C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x58CD20

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5965E0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x70EA90

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5AC400
#define CChatManager__InitContextMenu                              0x5ACBD0

// CChatService
#define CChatService__GetNumberOfFriends                           0x6CAF40
#define CChatService__GetFriendName                                0x6CAF50

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5B0DD0
#define CChatWindow__Clear                                         0x5B1740
#define CChatWindow__WndNotification                               0x5B1930

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6F8A10
#define CComboWnd__Draw                                            0x6F8BD0
#define CComboWnd__GetCurChoice                                    0x6F89B0
#define CComboWnd__GetListRect                                     0x6F8EC0
#define CComboWnd__GetTextRect                                     0x6F8A40
#define CComboWnd__InsertChoice                                    0x6F8F30
#define CComboWnd__SetColors                                       0x6F8940
#define CComboWnd__SetChoice                                       0x6F8970

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5B8DD0
#define CContainerWnd__vftable                                     0x81F528

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46DF50
#define CDisplay__GetClickedActor                                  0x467260
#define CDisplay__GetUserDefinedColor                              0x466380
#define CDisplay__GetWorldFilePath                                 0x4657F0
#define CDisplay__is3dON                                           0x464930
#define CDisplay__ReloadUI                                         0x477FD0
#define CDisplay__WriteTextHD2                                     0x469F70

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x586D50
#define CEditBaseWnd__SetSel                                       0x71AF60

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x701A00
#define CEditWnd__GetCharIndexPt                                   0x7029D0
#define CEditWnd__GetDisplayString                                 0x701BA0
#define CEditWnd__GetHorzOffset                                    0x701E30
#define CEditWnd__GetLineForPrintableChar                          0x702480
#define CEditWnd__GetSelStartPt                                    0x702C20
#define CEditWnd__GetSTMLSafeText                                  0x701FD0
#define CEditWnd__PointFromPrintableChar                           0x702590
#define CEditWnd__SelectableCharFromPoint                          0x702710
#define CEditWnd__SetEditable                                      0x701FA0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D9870
#define CEverQuest__DropHeldItemOnGround                           0x4DDDE0
#define CEverQuest__dsp_chat                                       0x4DF530
#define CEverQuest__DoTellWindow                                   0x4DDF60
#define CEverQuest__EnterZone                                      0x4F0FD0
#define CEverQuest__GetBodyTypeDesc                                0x4D6A70
#define CEverQuest__GetClassDesc                                   0x4D62B0
#define CEverQuest__GetClassThreeLetterCode                        0x4D68B0
#define CEverQuest__GetDeityDesc                                   0x4D70E0
#define CEverQuest__GetLangDesc                                    0x4D6E00
#define CEverQuest__GetRaceDesc                                    0x4D70B0
#define CEverQuest__InterpretCmd                                   0x4E0090
#define CEverQuest__LeftClickedOnPlayer                            0x4F2B00
#define CEverQuest__LMouseUp                                       0x4F63F0
#define CEverQuest__RightClickedOnPlayer                           0x4F6C90
#define CEverQuest__RMouseUp                                       0x4F7C70
#define CEverQuest__SetGameState                                   0x4D9D00
#define CEverQuest__Emote                                          0x4DF750

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5C5660
#define CGaugeWnd__CalcLinesFillRect                               0x5C56C0
#define CGaugeWnd__Draw                                            0x5C5B10

// CGuild
#define CGuild__FindMemberByName                                   0x41B060

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5DE5C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5E7C10
#define CInvSlotMgr__MoveItem                                      0x5E7DB0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5E74A0
#define CInvSlot__SliderComplete                                   0x5E65B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5E8D50

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x658F40
#define CItemDisplayWnd__UpdateStrings                             0x5E9A00

// CLabel 
#define CLabel__Draw                                               0x5FC0F0

// CListWnd 
#define CListWnd__AddColumn                                        0x6F2420
#define CListWnd__AddColumn1                                       0x6F1EA0
#define CListWnd__AddLine                                          0x6F1A10
#define CListWnd__AddString                                        0x6F1BB0
#define CListWnd__CalculateFirstVisibleLine                        0x6EE6D0
#define CListWnd__CalculateVSBRange                                0x6F08F0
#define CListWnd__ClearAllSel                                      0x6EDC20
#define CListWnd__CloseAndUpdateEditWindow                         0x6EED50
#define CListWnd__Compare                                          0x6EF0F0
#define CListWnd__Draw                                             0x6F0570
#define CListWnd__DrawColumnSeparators                             0x6F03E0
#define CListWnd__DrawHeader                                       0x6EDEB0
#define CListWnd__DrawItem                                         0x6EFA00
#define CListWnd__DrawLine                                         0x6F0050
#define CListWnd__DrawSeparator                                    0x6F0480
#define CListWnd__EnsureVisible                                    0x6EE760
#define CListWnd__ExtendSel                                        0x6EF920
#define CListWnd__GetColumnMinWidth                                0x6ED9B0
#define CListWnd__GetColumnWidth                                   0x6ED8F0
#define CListWnd__GetCurSel                                        0x6ED300
#define CListWnd__GetHeaderRect                                    0x6ED470
#define CListWnd__GetItemAtPoint                                   0x6EEA60
#define CListWnd__GetItemAtPoint1                                  0x6EEAD0
#define CListWnd__GetItemData                                      0x6ED6A0
#define CListWnd__GetItemHeight                                    0x6EE340
#define CListWnd__GetItemIcon                                      0x6ED830
#define CListWnd__GetItemRect                                      0x6EE840
#define CListWnd__GetItemText                                      0x6ED6E0
#define CListWnd__GetSelList                                       0x6F1D80
#define CListWnd__GetSeparatorRect                                 0x6EF030
#define CListWnd__RemoveLine                                       0x6F23D0
#define CListWnd__SetColors                                        0x6ED3D0
#define CListWnd__SetColumnJustification                           0x6EDA90
#define CListWnd__SetColumnWidth                                   0x6ED970
#define CListWnd__SetCurSel                                        0x6ED340
#define CListWnd__SetItemColor                                     0x6F15A0
#define CListWnd__SetItemData                                      0x6EDCC0
#define CListWnd__SetItemText                                      0x6F1520
#define CListWnd__ShiftColumnSeparator                             0x6EF830
#define CListWnd__Sort                                             0x6F2460
#define CListWnd__ToggleSel                                        0x6EDB90

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x6119C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x61D9D0
#define CMerchantWnd__RequestBuyItem                               0x61F910
#define CMerchantWnd__RequestSellItem                              0x61FD30
#define CMerchantWnd__SelectBuySellSlot                            0x61EDA0

// CObfuscator
#define CObfuscator__doit                                          0x6A4DB0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x70A2C0
#define CSidlManager__CreateLabel                                  0x651EE0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6FA700
#define CSidlScreenWnd__CalculateVSBRange                          0x6FA620
#define CSidlScreenWnd__ConvertToRes                               0x71AE40
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6FABD0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6FBCC0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6FBD70
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6FB470
#define CSidlScreenWnd__DrawSidlPiece                              0x6FA890
#define CSidlScreenWnd__EnableIniStorage                           0x6FA310
#define CSidlScreenWnd__GetSidlPiece                               0x6FAAA0
#define CSidlScreenWnd__Init1                                      0x6FBB20
#define CSidlScreenWnd__LoadIniInfo                                0x6FAC90
#define CSidlScreenWnd__LoadIniListWnd                             0x6FA460
#define CSidlScreenWnd__LoadSidlScreen                             0x6FB6C0
#define CSidlScreenWnd__StoreIniInfo                               0x6F9F20
#define CSidlScreenWnd__StoreIniVis                                0x6FA2A0
#define CSidlScreenWnd__WndNotification                            0x6FB8A0
#define CSidlScreenWnd__GetChildItem                               0x6FA370

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x53D850

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x71C390
#define CSliderWnd__SetValue                                       0x71C490
#define CSliderWnd__SetNumTicks                                    0x71CA40

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x656CA0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x719110
#define CStmlWnd__CalculateHSBRange                                0x710D20
#define CStmlWnd__CalculateVSBRange                                0x710C90
#define CStmlWnd__CanBreakAtCharacter                              0x710EA0
#define CStmlWnd__FastForwardToEndOfTag                            0x711B20
#define CStmlWnd__ForceParseNow                                    0x719560
#define CStmlWnd__GetNextTagPiece                                  0x711A40
#define CStmlWnd__GetSTMLText                                      0x5B0D70
#define CStmlWnd__GetThisChar                                      0x7400E0
#define CStmlWnd__GetVisiableText                                  0x712EE0
#define CStmlWnd__InitializeWindowVariables                        0x715170
#define CStmlWnd__MakeStmlColorTag                                 0x70FBB0
#define CStmlWnd__MakeWndNotificationTag                           0x70FC50
#define CStmlWnd__SetSTMLText                                      0x715290
#define CStmlWnd__StripFirstSTMLLines                              0x718E90
#define CStmlWnd__UpdateHistoryString                              0x713740

// CTabWnd 
#define CTabWnd__Draw                                              0x71D860
#define CTabWnd__DrawCurrentPage                                   0x71D1F0
#define CTabWnd__DrawTab                                           0x71CFD0
#define CTabWnd__GetCurrentPage                                    0x71D4F0
#define CTabWnd__GetPageClientRect                                 0x71CCA0
#define CTabWnd__GetPageFromTabIndex                               0x71CF00
#define CTabWnd__GetPageInnerRect                                  0x71CD00
#define CTabWnd__GetTabInnerRect                                   0x71CE80
#define CTabWnd__GetTabRect                                        0x71CD90
#define CTabWnd__InsertPage                                        0x71DAF0
#define CTabWnd__SetPage                                           0x71D530
#define CTabWnd__SetPageRect                                       0x71D790
#define CTabWnd__UpdatePage                                        0x71DA70

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417640

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6FC0F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x71E750

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6EC4D0

// CXRect 
#define CXRect__CenterPoint                                        0x58C3A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4158B0
#define CXStr__CXStr1                                              0x720D00
#define CXStr__CXStr3                                              0x6DDE50
#define CXStr__dCXStr                                              0x711130
#define CXStr__operator_equal1                                     0x6DE010
#define CXStr__operator_plus_equal1                                0x6DF050

// CXWnd 
#define CXWnd__BringToTop                                          0x6F2A50
#define CXWnd__Center                                              0x6F7290
#define CXWnd__ClrFocus                                            0x6F2860
#define CXWnd__DoAllDrawing                                        0x6F80E0
#define CXWnd__DrawChildren                                        0x6F8230
#define CXWnd__DrawColoredRect                                     0x6F2D30
#define CXWnd__DrawTooltip                                         0x6F7F30
#define CXWnd__DrawTooltipAtPoint                                  0x6F7040
#define CXWnd__GetBorderFrame                                      0x6F3170
#define CXWnd__GetChildWndAt                                       0x6F6870
#define CXWnd__GetClientClipRect                                   0x6F2FF0
#define CXWnd__GetScreenClipRect                                   0x6F74B0
#define CXWnd__GetScreenRect                                       0x6F3300
#define CXWnd__GetTooltipRect                                      0x6F2E40
#define CXWnd__GetWindowTextA                                      0x57ABC0
#define CXWnd__IsActive                                            0x6FD260
#define CXWnd__IsDescendantOf                                      0x6F30A0
#define CXWnd__IsReallyVisible                                     0x6F6850
#define CXWnd__IsType                                              0x721670
#define CXWnd__Move                                                0x6F6010
#define CXWnd__Move1                                               0x6F7D10
#define CXWnd__ProcessTransition                                   0x6F2A00
#define CXWnd__Refade                                              0x6F2970
#define CXWnd__Resize                                              0x6F33D0
#define CXWnd__Right                                               0x6F73F0
#define CXWnd__SetFocus                                            0x6F4BE0
#define CXWnd__SetKeyTooltip                                       0x6F35B0
#define CXWnd__SetMouseOver                                        0x6F7740
#define CXWnd__StartFade                                           0x6F2A90
#define CXWnd__GetChildItem                                        0x6F76C0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6FE7B0
#define CXWndManager__DrawWindows                                  0x6FE430
#define CXWndManager__GetKeyboardFlags                             0x6FCEB0
#define CXWndManager__HandleKeyboardMsg                            0x6FD530
#define CXWndManager__RemoveWnd                                    0x6FD380

// CDBStr
#define CDBStr__GetString                                          0x463280

// EQ_Character 
#define EQ_Character__CastRay                                      0x74C3F0
#define EQ_Character__CastSpell                                    0x42DD40
#define EQ_Character__Cur_HP                                       0x436F60
#define EQ_Character__GetAACastingTimeModifier                     0x423C10
#define EQ_Character__GetCharInfo2                                 0x6BBE70
#define EQ_Character__GetFocusCastingTimeModifier                  0x41F460
#define EQ_Character__GetFocusRangeModifier                        0x41F5A0
#define EQ_Character__Max_Endurance                                0x5200A0
#define EQ_Character__Max_HP                                       0x432140
#define EQ_Character__Max_Mana                                     0x51FED0
#define EQ_Character__doCombatAbility                              0x51EDE0
#define EQ_Character__UseSkill                                     0x440F10
#define EQ_Character__GetConLevel                                  0x51B100

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5088D0
#define EQ_Item__GetItemLinkHash                                   0x6AE860
#define EQ_Item__IsStackable                                       0x6A5690

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47BF90
#define EQ_LoadingS__Array                                         0x8A0D78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x522F30
#define EQ_PC__GetAltAbilityIndex                                  0x6B3B20
#define EQ_PC__GetCombatAbility                                    0x6B3BB0
#define EQ_PC__GetCombatAbilityTimer                               0x6B3C60
#define EQ_PC__GetItemTimerValue                                   0x51DD30
#define EQ_PC__HasLoreItem                                         0x5213F0

// EQItemList 
#define EQItemList__dEQItemList                                    0x4A7AC0
#define EQItemList__EQItemList                                     0x4A7A10

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x462BE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5278F0
#define EQPlayer__dEQPlayer                                        0x52BAA0
#define EQPlayer__DoAttack                                         0x539AF0
#define EQPlayer__EQPlayer                                         0x52F830
#define EQPlayer__SetNameSpriteState                               0x529A00
#define EQPlayer__SetNameSpriteTint                                0x527960
#define EQPlayer__IsBodyType_j                                     0x74BD00
#define EQPlayer__IsTargetable                                     0x74BE90

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5309E0
#define EQPlayerManager__GetSpawnByName                            0x530CC0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50A550
#define KeypressHandler__AttachKeyToEqCommand                      0x50A590
#define KeypressHandler__ClearCommandStateArray                    0x50A360
#define KeypressHandler__HandleKeyDown                             0x508EE0
#define KeypressHandler__HandleKeyUp                               0x5091F0
#define KeypressHandler__SaveKeymapping                            0x50A430

// MapViewMap 
#define MapViewMap__Clear                                          0x60D060
#define MapViewMap__SaveEx                                         0x60DA30

#define OtherCharData__GetAltCurrency                              0x6D3A70

// StringTable 
#define StringTable__getString                                     0x6A5030
