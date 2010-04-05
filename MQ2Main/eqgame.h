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
#define __ExpectedVersionDate                                     "Dec 14 2009"
#define __ExpectedVersionTime                                     "13:55:50"
#define __ActualVersionDate                                        0x817B40
#define __ActualVersionTime                                        0x817B4C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x510F90
#define __MemChecker1                                              0x6E0690
#define __MemChecker2                                              0x570C20
#define __MemChecker3                                              0x570B70
#define __MemChecker4                                              0x694850
#define __EncryptPad0                                              0x8A8190
#define __EncryptPad1                                              0x8B3290
#define __EncryptPad2                                              0x8AADC8
#define __EncryptPad3                                              0x8AA9C8
#define __EncryptPad4                                              0x8B28D8
#define __AC1                                                      0x65C860
#define __AC2                                                      0x4D90C5
#define __AC3                                                      0x4ED048
#define __AC4                                                      0x4F0F18
#define __AC5                                                      0x4FB668
#define __AC6                                                      0x4FEAEB
#define __AC7                                                      0x4F7B94
#define __AC1_Data                                                 0x800080

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
#define __do_loot                                                  0x4B1DC0
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
#define __CastRay                                                  0x4C5B20
#define __ConvertItemTags                                          0x4B7440
#define __ExecuteCmd                                               0x4A3AD0
#define __get_melee_range                                          0x4A9420
#define __GetGaugeValueFromEQ                                      0x65B720
#define __GetLabelFromEQ                                           0x65C800
#define __LoadFrontEnd                                             0x56FAF0
#define __NewUIINI                                                 0x65B2B0
#define __ProcessGameEvents                                        0x4F7F80
#define CrashDetected                                              0x56F8F0
#define DrawNetStatus                                              0x519B20
#define Util__FastTime                                             0x6E0DE0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47ACF0
#define AltAdvManager__IsAbilityReady                              0x47AD30
#define AltAdvManager__GetAltAbility                               0x47AF10

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x58CC60

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x596470

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x70EAC0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5AC500
#define CChatManager__InitContextMenu                              0x5ACCD0

// CChatService
#define CChatService__GetNumberOfFriends                           0x6CAFB0
#define CChatService__GetFriendName                                0x6CAFC0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5B0ED0
#define CChatWindow__Clear                                         0x5B1840
#define CChatWindow__WndNotification                               0x5B1A30

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6F8B40
#define CComboWnd__Draw                                            0x6F8D00
#define CComboWnd__GetCurChoice                                    0x6F8AE0
#define CComboWnd__GetListRect                                     0x6F8FF0
#define CComboWnd__GetTextRect                                     0x6F8B70
#define CComboWnd__InsertChoice                                    0x6F9060
#define CComboWnd__SetColors                                       0x6F8A70
#define CComboWnd__SetChoice                                       0x6F8AA0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5B8F00
#define CContainerWnd__vftable                                     0x81F4A0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46DE60
#define CDisplay__GetClickedActor                                  0x467130
#define CDisplay__GetUserDefinedColor                              0x466250
#define CDisplay__GetWorldFilePath                                 0x4656C0
#define CDisplay__is3dON                                           0x464800
#define CDisplay__ReloadUI                                         0x477EE0
#define CDisplay__WriteTextHD2                                     0x469E80

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x586BA0
#define CEditBaseWnd__SetSel                                       0x71AF60

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x701A90
#define CEditWnd__GetCharIndexPt                                   0x702A60
#define CEditWnd__GetDisplayString                                 0x701C30
#define CEditWnd__GetHorzOffset                                    0x701EC0
#define CEditWnd__GetLineForPrintableChar                          0x702510
#define CEditWnd__GetSelStartPt                                    0x702CB0
#define CEditWnd__GetSTMLSafeText                                  0x702060
#define CEditWnd__PointFromPrintableChar                           0x702620
#define CEditWnd__SelectableCharFromPoint                          0x7027A0
#define CEditWnd__SetEditable                                      0x702030

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D97A0
#define CEverQuest__DropHeldItemOnGround                           0x4DDCC0
#define CEverQuest__dsp_chat                                       0x4DF410
#define CEverQuest__DoTellWindow                                   0x4DDE40
#define CEverQuest__EnterZone                                      0x4F0EB0
#define CEverQuest__GetBodyTypeDesc                                0x4D69A0
#define CEverQuest__GetClassDesc                                   0x4D61E0
#define CEverQuest__GetClassThreeLetterCode                        0x4D67E0
#define CEverQuest__GetDeityDesc                                   0x4D7010
#define CEverQuest__GetLangDesc                                    0x4D6D30
#define CEverQuest__GetRaceDesc                                    0x4D6FE0
#define CEverQuest__InterpretCmd                                   0x4DFF70
#define CEverQuest__LeftClickedOnPlayer                            0x4F29E0
#define CEverQuest__LMouseUp                                       0x4F62D0
#define CEverQuest__RightClickedOnPlayer                           0x4F6B70
#define CEverQuest__RMouseUp                                       0x4F7B50
#define CEverQuest__SetGameState                                   0x4D9C30
#define CEverQuest__Emote                                          0x4DF630

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5C5780
#define CGaugeWnd__CalcLinesFillRect                               0x5C57E0
#define CGaugeWnd__Draw                                            0x5C5C30

// CGuild
#define CGuild__FindMemberByName                                   0x41AF90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5DE6E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5E7D70
#define CInvSlotMgr__MoveItem                                      0x5E7F10

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5E7600
#define CInvSlot__SliderComplete                                   0x5E6710

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5E8EB0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x659160
#define CItemDisplayWnd__UpdateStrings                             0x5E9B60

// CLabel 
#define CLabel__Draw                                               0x5FC230

// CListWnd 
#define CListWnd__AddColumn                                        0x6F2560
#define CListWnd__AddColumn1                                       0x6F1FE0
#define CListWnd__AddLine                                          0x6F1B50
#define CListWnd__AddString                                        0x6F1CF0
#define CListWnd__CalculateFirstVisibleLine                        0x6EE810
#define CListWnd__CalculateVSBRange                                0x6F0A30
#define CListWnd__ClearAllSel                                      0x6EDD60
#define CListWnd__CloseAndUpdateEditWindow                         0x6EEE90
#define CListWnd__Compare                                          0x6EF230
#define CListWnd__Draw                                             0x6F06B0
#define CListWnd__DrawColumnSeparators                             0x6F0520
#define CListWnd__DrawHeader                                       0x6EDFF0
#define CListWnd__DrawItem                                         0x6EFB40
#define CListWnd__DrawLine                                         0x6F0190
#define CListWnd__DrawSeparator                                    0x6F05C0
#define CListWnd__EnsureVisible                                    0x6EE8A0
#define CListWnd__ExtendSel                                        0x6EFA60
#define CListWnd__GetColumnMinWidth                                0x6EDAF0
#define CListWnd__GetColumnWidth                                   0x6EDA30
#define CListWnd__GetCurSel                                        0x6ED420
#define CListWnd__GetHeaderRect                                    0x6ED5B0
#define CListWnd__GetItemAtPoint                                   0x6EEBA0
#define CListWnd__GetItemAtPoint1                                  0x6EEC10
#define CListWnd__GetItemData                                      0x6ED7E0
#define CListWnd__GetItemHeight                                    0x6EE480
#define CListWnd__GetItemIcon                                      0x6ED970
#define CListWnd__GetItemRect                                      0x6EE980
#define CListWnd__GetItemText                                      0x6ED820
#define CListWnd__GetSelList                                       0x6F1EC0
#define CListWnd__GetSeparatorRect                                 0x6EF170
#define CListWnd__RemoveLine                                       0x6F2510
#define CListWnd__SetColors                                        0x6ED510
#define CListWnd__SetColumnJustification                           0x6EDBD0
#define CListWnd__SetColumnWidth                                   0x6EDAB0
#define CListWnd__SetCurSel                                        0x6ED460
#define CListWnd__SetItemColor                                     0x6F16E0
#define CListWnd__SetItemData                                      0x6EDE00
#define CListWnd__SetItemText                                      0x6F1660
#define CListWnd__ShiftColumnSeparator                             0x6EF970
#define CListWnd__Sort                                             0x6F25A0
#define CListWnd__ToggleSel                                        0x6EDCD0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x611AE0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x61DAC0
#define CMerchantWnd__RequestBuyItem                               0x61FA00
#define CMerchantWnd__RequestSellItem                              0x61FE20
#define CMerchantWnd__SelectBuySellSlot                            0x61EE90

// CObfuscator
#define CObfuscator__doit                                          0x6A4F10

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x70A360
#define CSidlManager__CreateLabel                                  0x6520A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x588C60
#define CSidlScreenWnd__CalculateVSBRange                          0x6FA790
#define CSidlScreenWnd__ConvertToRes                               0x71AE40
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6FAC60
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6FBD50
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6FBE00
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6FB500
#define CSidlScreenWnd__DrawSidlPiece                              0x6FA920
#define CSidlScreenWnd__EnableIniStorage                           0x6FA480
#define CSidlScreenWnd__GetSidlPiece                               0x6FAB30
#define CSidlScreenWnd__Init1                                      0x6FBBB0
#define CSidlScreenWnd__LoadIniInfo                                0x6FAD20
#define CSidlScreenWnd__LoadIniListWnd                             0x6FA5D0
#define CSidlScreenWnd__LoadSidlScreen                             0x6FB750
#define CSidlScreenWnd__StoreIniInfo                               0x6FA090
#define CSidlScreenWnd__StoreIniVis                                0x6FA410
#define CSidlScreenWnd__WndNotification                            0x6FB930
#define CSidlScreenWnd__GetChildItem                               0x6FA4E0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x53D690

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x71C3A0
#define CSliderWnd__SetValue                                       0x71C4A0
#define CSliderWnd__SetNumTicks                                    0x71CA50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x656EC0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x719120
#define CStmlWnd__CalculateHSBRange                                0x710D50
#define CStmlWnd__CalculateVSBRange                                0x710CC0
#define CStmlWnd__CanBreakAtCharacter                              0x710ED0
#define CStmlWnd__FastForwardToEndOfTag                            0x711B30
#define CStmlWnd__ForceParseNow                                    0x719570
#define CStmlWnd__GetNextTagPiece                                  0x711A50
#define CStmlWnd__GetSTMLText                                      0x5B0E70
#define CStmlWnd__GetThisChar                                      0x7400A0
#define CStmlWnd__GetVisiableText                                  0x712EF0
#define CStmlWnd__InitializeWindowVariables                        0x715180
#define CStmlWnd__MakeStmlColorTag                                 0x70FBE0
#define CStmlWnd__MakeWndNotificationTag                           0x70FC80
#define CStmlWnd__SetSTMLText                                      0x7152A0
#define CStmlWnd__StripFirstSTMLLines                              0x718EA0
#define CStmlWnd__UpdateHistoryString                              0x713750

// CTabWnd 
#define CTabWnd__Draw                                              0x71D870
#define CTabWnd__DrawCurrentPage                                   0x71D200
#define CTabWnd__DrawTab                                           0x71CFE0
#define CTabWnd__GetCurrentPage                                    0x71D500
#define CTabWnd__GetPageClientRect                                 0x71CCB0
#define CTabWnd__GetPageFromTabIndex                               0x71CF10
#define CTabWnd__GetPageInnerRect                                  0x71CD10
#define CTabWnd__GetTabInnerRect                                   0x71CE90
#define CTabWnd__GetTabRect                                        0x71CDA0
#define CTabWnd__InsertPage                                        0x71DB00
#define CTabWnd__SetPage                                           0x71D540
#define CTabWnd__SetPageRect                                       0x71D7A0
#define CTabWnd__UpdatePage                                        0x71DA80

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417550

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6FC180

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x71E710

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6EC6D0

// CXRect 
#define CXRect__CenterPoint                                        0x58C2E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x415870
#define CXStr__CXStr1                                              0x53A860
#define CXStr__CXStr3                                              0x6DE0A0
#define CXStr__dCXStr                                              0x468120
#define CXStr__operator_equal1                                     0x6DE260
#define CXStr__operator_plus_equal1                                0x6DF2A0

// CXWnd 
#define CXWnd__BringToTop                                          0x6F2B80
#define CXWnd__Center                                              0x6F73C0
#define CXWnd__ClrFocus                                            0x6F29A0
#define CXWnd__DoAllDrawing                                        0x6F8210
#define CXWnd__DrawChildren                                        0x6F8360
#define CXWnd__DrawColoredRect                                     0x6F2E60
#define CXWnd__DrawTooltip                                         0x6F8060
#define CXWnd__DrawTooltipAtPoint                                  0x6F7170
#define CXWnd__GetBorderFrame                                      0x6F32A0
#define CXWnd__GetChildWndAt                                       0x6F69A0
#define CXWnd__GetClientClipRect                                   0x6F3120
#define CXWnd__GetScreenClipRect                                   0x6F75E0
#define CXWnd__GetScreenRect                                       0x6F3430
#define CXWnd__GetTooltipRect                                      0x6F2F70
#define CXWnd__GetWindowTextA                                      0x57A920
#define CXWnd__IsActive                                            0x6FD2F0
#define CXWnd__IsDescendantOf                                      0x6F31D0
#define CXWnd__IsReallyVisible                                     0x6F6980
#define CXWnd__IsType                                              0x721570
#define CXWnd__Move                                                0x6F6140
#define CXWnd__Move1                                               0x6F7E40
#define CXWnd__ProcessTransition                                   0x6F2B30
#define CXWnd__Refade                                              0x6F2AB0
#define CXWnd__Resize                                              0x6F3500
#define CXWnd__Right                                               0x6F7520
#define CXWnd__SetFocus                                            0x6F4D10
#define CXWnd__SetKeyTooltip                                       0x6F36E0
#define CXWnd__SetMouseOver                                        0x6F7870
#define CXWnd__StartFade                                           0x6F2BC0
#define CXWnd__GetChildItem                                        0x6F77F0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6FE840
#define CXWndManager__DrawWindows                                  0x6FE4C0
#define CXWndManager__GetKeyboardFlags                             0x6FCF40
#define CXWndManager__HandleKeyboardMsg                            0x6FD5C0
#define CXWndManager__RemoveWnd                                    0x6FD410

// CDBStr
#define CDBStr__GetString                                          0x463170

// EQ_Character 
#define EQ_Character__CastRay                                      0x74C150
#define EQ_Character__CastSpell                                    0x42DC90
#define EQ_Character__Cur_HP                                       0x436EC0
#define EQ_Character__GetAACastingTimeModifier                     0x423B10
#define EQ_Character__GetCharInfo2                                 0x6BBFC0
#define EQ_Character__GetFocusCastingTimeModifier                  0x41F350
#define EQ_Character__GetFocusRangeModifier                        0x41F490
#define EQ_Character__Max_Endurance                                0x51FFA0
#define EQ_Character__Max_HP                                       0x4320A0
#define EQ_Character__Max_Mana                                     0x51FDD0
#define EQ_Character__doCombatAbility                              0x51ECE0
#define EQ_Character__UseSkill                                     0x440E70
#define EQ_Character__GetConLevel                                  0x51AFD0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x508780
#define EQ_Item__GetItemLinkHash                                   0x6AE9C0
#define EQ_Item__IsStackable                                       0x6A57F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47BDE0
#define EQ_LoadingS__Array                                         0x8A0D78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x522E30
#define EQ_PC__GetAltAbilityIndex                                  0x6B3C80
#define EQ_PC__GetCombatAbility                                    0x6B3D10
#define EQ_PC__GetCombatAbilityTimer                               0x6B3DC0
#define EQ_PC__GetItemTimerValue                                   0x51DC30
#define EQ_PC__HasLoreItem                                         0x5212F0

// EQItemList 
#define EQItemList__dEQItemList                                    0x4A7980
#define EQItemList__EQItemList                                     0x4A78D0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x462AD0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5277E0
#define EQPlayer__dEQPlayer                                        0x52B9B0
#define EQPlayer__DoAttack                                         0x539920
#define EQPlayer__EQPlayer                                         0x52F6F0
#define EQPlayer__SetNameSpriteState                               0x5298F0
#define EQPlayer__SetNameSpriteTint                                0x527850
#define EQPlayer__IsBodyType_j                                     0x74BA60
#define EQPlayer__IsTargetable                                     0x74BBF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5308A0
#define EQPlayerManager__GetSpawnByName                            0x530B80

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50A400
#define KeypressHandler__AttachKeyToEqCommand                      0x50A440
#define KeypressHandler__ClearCommandStateArray                    0x50A210
#define KeypressHandler__HandleKeyDown                             0x508D90
#define KeypressHandler__HandleKeyUp                               0x5090A0
#define KeypressHandler__SaveKeymapping                            0x50A2E0

// MapViewMap 
#define MapViewMap__Clear                                          0x60D180
#define MapViewMap__SaveEx                                         0x60DB50

#define OtherCharData__GetAltCurrency                              0x6D3CA0

// StringTable 
#define StringTable__getString                                     0x6A5190
