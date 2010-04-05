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
#define __ExpectedVersionDate                                     "Apr  6 2009"
#define __ExpectedVersionTime                                     "16:53:04"
#define __ActualVersionDate                                        0x7DDFAC
#define __ActualVersionTime                                        0x7DDFB8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x50B940
#define __MemChecker1                                              0x6B59A0
#define __MemChecker2                                              0x561D10
#define __MemChecker3                                              0x561C60
#define __MemChecker4                                              0x677AD0
#define __EncryptPad0                                              0x863710
#define __EncryptPad1                                              0x86DDE0
#define __EncryptPad2                                              0x866168
#define __EncryptPad3                                              0x865D68
#define __EncryptPad4                                              0x86D4B0

// Direct Input
#define DI8__Main                                                  0xAE4884
#define DI8__Keyboard                                              0xAE4888
#define DI8__Mouse                                                 0xAE488C
#define __AltTimerReady                                            0xA6F342
#define __Attack                                                   0xACEDE6
#define __Autofire                                                 0xACEDE7
#define __BindList                                                 0x85E688
#define __Clicks                                                   0xA6E058
#define __CommandList                                              0x85EEF8
#define __CurrentMapLabel                                          0xB0FAC0
#define __CurrentSocial                                            0x85A6A4
#define __DoAbilityAvailable                                       0xA6F2DC
#define __DoAbilityList                                            0xAA48FC
#define __do_loot                                                  0x4B2F20
#define __DrawHandler                                              0xB1EF2C
#define __GroupCount                                               0xA48F22
#define __Guilds                                                   0xA4AAA0
#define __gWorld                                                   0xA4A9E0
#define __HotkeyPage                                               0xACBCE8
#define __HWnd                                                     0xAE45C4
#define __InChatMode                                               0xA6DF90
#define __LastTell                                                 0xA6FC54
#define __LMouseHeldTime                                           0xA6E078
#define __Mouse                                                    0xAE4890
#define __MouseLook                                                0xA6E026
#define __MouseEventTime                                           0xACEEF0
#define __NetStatusToggle                                          0xA6E029
#define __PCNames                                                  0xA6F698
#define __RangeAttackReady                                         0xA6F340
#define __RMouseHeldTime                                           0xA6E074
#define __RunWalkState                                             0xA6DF94
#define __ScreenMode                                               0x9987F0
#define __ScreenX                                                  0xA6DF48
#define __ScreenY                                                  0xA6DF4C
#define __ScreenXMax                                               0xA6DF50
#define __ScreenYMax                                               0xA6DF54
#define __ServerHost                                               0xA48E64
#define __ServerName                                               0xAA48BC
#define __ShiftKeyDown                                             0xA6E5F8
#define __ShowNames                                                0xA6F56C
#define __Socials                                                  0xAA49BC


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA6A3F0
#define instEQZoneInfo                                             0xA6E1C4
#define instKeypressHandler                                        0xACEED4
#define pinstActiveBanker                                          0xA4AA78
#define pinstActiveCorpse                                          0xA4AA7C
#define pinstActiveGMaster                                         0xA4AA80
#define pinstActiveMerchant                                        0xA4AA74
#define pinstAltAdvManager                                         0x999650
#define pinstAuraMgr                                               0x8820B4
#define pinstBandageTarget                                         0xA4AA60
#define pinstCamActor                                              0x999140
#define pinstCDBStr                                                0x9987E0
#define pinstCDisplay                                              0xA4AA88
#define pinstCEverQuest                                            0xAE4A08
#define pinstCharData                                              0xA4AA44
#define pinstCharSpawn                                             0xA4AA6C
#define pinstControlledMissile                                     0xA4AA40
#define pinstControlledPlayer                                      0xA4AA6C
#define pinstCSidlManager                                          0xB1E6B0
#define pinstCXWndManager                                          0xB1E6A8
#define instDynamicZone                                            0xA6D998
#define pinstDZMember                                              0xA6DAA8
#define pinstDZTimerInfo                                           0xA6DAAC
#define pinstEQItemList                                            0xA4AA28
#define instEQMisc                                                 0x998798
#define pinstEQSoundManager                                        0x999674
#define instExpeditionLeader                                       0xA6D9E2
#define instExpeditionName                                         0xA6DA22
#define pinstGroup                                                 0xA48F1E
#define pinstImeManager                                            0xB1E6B4
#define pinstLocalPlayer                                           0xA4AA58
#define pinstMercenaryData                                         0xACF248
#define pinstModelPlayer                                           0xA4AA84
#define pinstPCData                                                0xA4AA44
#define pinstSkillMgr                                              0xAE16DC
#define pinstSpawnManager                                          0xAE165C
#define pinstSpellManager                                          0xAE16E0
#define pinstSpellSets                                             0xACBCEC
#define pinstStringTable                                           0xA4A9FC
#define pinstSwitchManager                                         0xA48B64
#define pinstTarget                                                0xA4AA70
#define pinstTargetObject                                          0xA4AA48
#define pinstTargetSwitch                                          0xA4AA4C
#define pinstTaskMember                                            0x998778
#define pinstTrackTarget                                           0xA4AA64
#define pinstTradeTarget                                           0xA4AA54
#define instTributeActive                                          0x9987BD
#define pinstViewActor                                             0x99913C
#define pinstWorldData                                             0xA4AA24


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x87F960
#define pinstCAudioTriggersWindow                                  0x87F92C
#define pinstCCharacterSelect                                      0x99904C
#define pinstCFacePick                                             0x999000
#define pinstCNoteWnd                                              0x999004
#define pinstCBookWnd                                              0x999008
#define pinstCPetInfoWnd                                           0x99900C
#define pinstCTrainWnd                                             0x999010
#define pinstCSkillsWnd                                            0x999014
#define pinstCSkillsSelectWnd                                      0x999018
#define pinstCCombatSkillSelectWnd                                 0x99901C
#define pinstCFriendsWnd                                           0x999020
#define pinstCAuraWnd                                              0x999024
#define pinstCRespawnWnd                                           0x999028
#define pinstCBandolierWnd                                         0x99902C
#define pinstCPotionBeltWnd                                        0x999030
#define pinstCAAWnd                                                0x999034
#define pinstCGroupSearchFiltersWnd                                0x999038
#define pinstCLoadskinWnd                                          0x99903C
#define pinstCAlarmWnd                                             0x999040
#define pinstCMusicPlayerWnd                                       0x999044
#define pinstCMailWnd                                              0x999050
#define pinstCMailCompositionWnd                                   0x999054
#define pinstCMailAddressBookWnd                                   0x999058
#define pinstCRaidWnd                                              0x999060
#define pinstCRaidOptionsWnd                                       0x999064
#define pinstCBreathWnd                                            0x999068
#define pinstCMapViewWnd                                           0x99906C
#define pinstCMapToolbarWnd                                        0x999070
#define pinstCEditLabelWnd                                         0x999074
#define pinstCTargetWnd                                            0x999078
#define pinstCColorPickerWnd                                       0x99907C
#define pinstCPlayerWnd                                            0x999080
#define pinstCOptionsWnd                                           0x999084
#define pinstCBuffWindowNORMAL                                     0x999088
#define pinstCBuffWindowSHORT                                      0x99908C
#define pinstCharacterCreation                                     0x999090
#define pinstCCursorAttachment                                     0x999094
#define pinstCCastingWnd                                           0x999098
#define pinstCCastSpellWnd                                         0x99909C
#define pinstCSpellBookWnd                                         0x9990A0
#define pinstCInventoryWnd                                         0x9990A4
#define pinstCBankWnd                                              0x9990A8
#define pinstCQuantityWnd                                          0x9990AC
#define pinstCLootWnd                                              0x9990B0
#define pinstCActionsWnd                                           0x9990B4
#define pinstCCombatAbilityWnd                                     0x9990B8
#define pinstCMerchantWnd                                          0x9990BC
#define pinstCTradeWnd                                             0x9990C0
#define pinstCSelectorWnd                                          0x9990C4
#define pinstCBazaarWnd                                            0x9990C8
#define pinstCBazaarSearchWnd                                      0x9990CC
#define pinstCGiveWnd                                              0x9990D0
#define pinstCTrackingWnd                                          0x9990D4
#define pinstCInspectWnd                                           0x9990D8
#define pinstCSocialEditWnd                                        0x9990DC
#define pinstCFeedbackWnd                                          0x9990E0
#define pinstCBugReportWnd                                         0x9990E4
#define pinstCVideoModesWnd                                        0x9990E8
#define pinstCTextEntryWnd                                         0x9990F0
#define pinstCFileSelectionWnd                                     0x9990F4
#define pinstCCompassWnd                                           0x9990F8
#define pinstCPlayerNotesWnd                                       0x9990FC
#define pinstCGemsGameWnd                                          0x999100
#define pinstCTimeLeftWnd                                          0x999104
#define pinstCPetitionQWnd                                         0x99910C
#define pinstCSoulmarkWnd                                          0x999110
#define pinstCStoryWnd                                             0x999114
#define pinstCJournalTextWnd                                       0x999118
#define pinstCJournalCatWnd                                        0x99911C
#define pinstCBodyTintWnd                                          0x999120
#define pinstCServerListWnd                                        0x999124
#define pinstCAvaZoneWnd                                           0x999128
#define pinstCBlockedBuffWnd                                       0x99912C
#define pinstCBlockedPetBuffWnd                                    0x999130
#define pinstCInvSlotMgr                                           0x999134
#define pinstCContainerMgr                                         0x999138
#define pinstCAdventureLeaderboardWnd                              0xB0CFF0
#define pinstCAdventureRequestWnd                                  0xB0D00C
#define pinstCAltStorageWnd                                        0xB0D06C
#define pinstCAdventureStatsWnd                                    0xB0D028
#define pinstCBarterMerchantWnd                                    0xB0D238
#define pinstCBarterSearchWnd                                      0xB0D254
#define pinstCBarterWnd                                            0xB0D270
#define pinstCChatManager                                          0xB0D514
#define pinstCDynamicZoneWnd                                       0xB0D60C
#define pinstCEQMainWnd                                            0xB0D680
#define pinstCFellowshipWnd                                        0xB0D6E4
#define pinstCFindLocationWnd                                      0xB0D718
#define pinstCGroupSearchWnd                                       0xB0D7C8
#define pinstCGroupWnd                                             0xB0D7E4
#define pinstCGuildBankWnd                                         0xB0D800
#define pinstCGuildMgmtWnd                                         0xB0F838
#define pinstCGuildTributeMasterWnd                                0xB0F858
#define pinstCHotButtonWnd                                         0xB0F874
#define pinstCHotButtonWnd1                                        0xB0F874
#define pinstCHotButtonWnd2                                        0xB0F878
#define pinstCHotButtonWnd3                                        0xB0F87C
#define pinstCHotButtonWnd4                                        0xB0F880
#define pinstCItemDisplayManager                                   0xB0F92C
#define pinstCItemExpTransferWnd                                   0xB0F94C
#define pinstCLeadershipWnd                                        0xB0F9E8
#define pinstCLFGuildWnd                                           0xB0FA04
#define pinstCMIZoneSelectWnd                                      0xB0FB74
#define pinstCAdventureMerchantWnd                                 0xB0FC6C
#define pinstCConfirmationDialog                                   0xB0FC88
#define pinstCPopupWndManager                                      0xB0FC88
#define pinstCProgressionSelectionWnd                              0xB0FCBC
#define pinstCPvPLeaderboardWnd                                    0xB0FCD8
#define pinstCPvPStatsWnd                                          0xB0FCF4
#define pinstCSystemInfoDialogBox                                  0xB0FDA8
#define pinstCTargetOfTargetWnd                                    0xB106B4
#define pinstCTaskSelectWnd                                        0xB106E8
#define pinstCTaskTemplateSelectWnd                                0xB10704
#define pinstCTaskWnd                                              0xB10720
#define pinstCTipWndOFDAY                                          0xB1079C
#define pinstCTipWndCONTEXT                                        0xB107A0
#define pinstCTitleWnd                                             0xB107BC
#define pinstCTradeskillWnd                                        0xB10800
#define pinstCTributeBenefitWnd                                    0xB1084C
#define pinstCTributeMasterWnd                                     0xB10868
#define pinstCContextMenuManager                                   0xB1E70C
#define pinstCVoiceMacroWnd                                        0xAE18C4
#define pinstCHtmlWnd                                              0xAE1900


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C5E80
#define __ConvertItemTags                                          0x4B8330
#define __ExecuteCmd                                               0x4A6C40
#define __get_melee_range                                          0x4AC0F0
#define __GetGaugeValueFromEQ                                      0x63FE50
#define __GetLabelFromEQ                                           0x640B70
#define __NewUIINI                                                 0x63FA30
#define __ProcessGameEvents                                        0x4F55F0
#define CrashDetected                                              0x5609E0
#define DrawNetStatus                                              0x5140B0
#define Util__FastTime                                             0x6B60B0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47F4E0
#define AltAdvManager__IsAbilityReady                              0x47F520
#define AltAdvManager__GetAltAbility                               0x47F700

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5788B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x582190

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6E4350

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x597A70
#define CChatManager__InitContextMenu                              0x598210

// CChatService
#define CChatService__GetNumberOfFriends                           0x6A5F80
#define CChatService__GetFriendName                                0x6A5F90

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x59C3F0
#define CChatWindow__Clear                                         0x59CD60
#define CChatWindow__WndNotification                               0x59CE40

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6CEE60
#define CComboWnd__Draw                                            0x6CF010
#define CComboWnd__GetCurChoice                                    0x6CEE00
#define CComboWnd__GetListRect                                     0x6CF2D0
#define CComboWnd__GetTextRect                                     0x6CEE90
#define CComboWnd__InsertChoice                                    0x6CF340
#define CComboWnd__SetColors                                       0x6CED90
#define CComboWnd__SetChoice                                       0x6CEDC0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A39F0
#define CContainerWnd__vftable                                     0x7E4B60

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46DF80
#define CDisplay__GetClickedActor                                  0x46B6A0
#define CDisplay__GetUserDefinedColor                              0x46A7C0
#define CDisplay__GetWorldFilePath                                 0x469CE0
#define CDisplay__is3dON                                           0x468E50
#define CDisplay__ReloadUI                                         0x47C630
#define CDisplay__WriteTextHD2                                     0x46E6F0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5728A0
#define CEditBaseWnd__SetSel                                       0x6EF750

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6D79F0
#define CEditWnd__GetCharIndexPt                                   0x6D8830
#define CEditWnd__GetDisplayString                                 0x6D7B80
#define CEditWnd__GetHorzOffset                                    0x6D7E10
#define CEditWnd__GetLineForPrintableChar                          0x6D82E0
#define CEditWnd__GetSelStartPt                                    0x6D8A70
#define CEditWnd__GetSTMLSafeText                                  0x6D7FA0
#define CEditWnd__PointFromPrintableChar                           0x6D83F0
#define CEditWnd__SelectableCharFromPoint                          0x6D8570
#define CEditWnd__SetEditable                                      0x6D7F70

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D96E0
#define CEverQuest__DropHeldItemOnGround                           0x4DDD60
#define CEverQuest__dsp_chat                                       0x4DF280
#define CEverQuest__DoTellWindow                                   0x4DDEE0
#define CEverQuest__EnterZone                                      0x4F3F40
#define CEverQuest__GetBodyTypeDesc                                0x4D6960
#define CEverQuest__GetClassDesc                                   0x4D61A0
#define CEverQuest__GetClassThreeLetterCode                        0x4D67A0
#define CEverQuest__GetDeityDesc                                   0x4D6FD0
#define CEverQuest__GetLangDesc                                    0x4D6CF0
#define CEverQuest__GetRaceDesc                                    0x4D6FA0
#define CEverQuest__InterpretCmd                                   0x4DFD10
#define CEverQuest__LeftClickedOnPlayer                            0x4F26E0
#define CEverQuest__LMouseUp                                       0x4F4D40
#define CEverQuest__RightClickedOnPlayer                           0x4F2AB0
#define CEverQuest__RMouseUp                                       0x4F4540
#define CEverQuest__SetGameState                                   0x4D9B60
#define CEverQuest__Emote                                          0x4DF470

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5B08B0
#define CGaugeWnd__CalcLinesFillRect                               0x5B0910
#define CGaugeWnd__Draw                                            0x5B0D20

// CGuild
#define CGuild__FindMemberByName                                   0x421660

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5C8DF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D23C0
#define CInvSlotMgr__MoveItem                                      0x5D2560

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5D0D80
#define CInvSlot__SliderComplete                                   0x5D1290

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5E1310
#define CItemDisplayWnd__SetSpell                                  0x63DC10

// CLabel 
#define CLabel__Draw                                               0x5E6BE0

// CListWnd 
#define CListWnd__AddColumn                                        0x6C9680
#define CListWnd__AddColumn1                                       0x6C9160
#define CListWnd__AddLine                                          0x6C8C50
#define CListWnd__AddString                                        0x6C8E40
#define CListWnd__CalculateFirstVisibleLine                        0x6C5F10
#define CListWnd__CalculateVSBRange                                0x6C7CB0
#define CListWnd__ClearAllSel                                      0x6C5640
#define CListWnd__CloseAndUpdateEditWindow                         0x6C6535
#define CListWnd__Compare                                          0x6C68B0
#define CListWnd__Draw                                             0x6C79A0
#define CListWnd__DrawColumnSeparators                             0x6C7810
#define CListWnd__DrawHeader                                       0x6C5810
#define CListWnd__DrawItem                                         0x6C7140
#define CListWnd__DrawLine                                         0x6C74B0
#define CListWnd__DrawSeparator                                    0x6C78B0
#define CListWnd__EnsureVisible                                    0x6C5F60
#define CListWnd__ExtendSel                                        0x6C7060
#define CListWnd__GetColumnMinWidth                                0x6C53D0
#define CListWnd__GetColumnWidth                                   0x6C5310
#define CListWnd__GetCurSel                                        0x6C4D20
#define CListWnd__GetHeaderRect                                    0x6C4E90
#define CListWnd__GetItemAtPoint                                   0x6C6240
#define CListWnd__GetItemAtPoint1                                  0x6C62B0
#define CListWnd__GetItemData                                      0x6C50C0
#define CListWnd__GetItemHeight                                    0x6C5CA0
#define CListWnd__GetItemIcon                                      0x6C5250
#define CListWnd__GetItemRect                                      0x6C6030
#define CListWnd__GetItemText                                      0x6C5100
#define CListWnd__GetSelList                                       0x6C9040
#define CListWnd__GetSeparatorRect                                 0x6C67F0
#define CListWnd__RemoveLine                                       0x6C8FF0
#define CListWnd__SetColors                                        0x6C4DF0
#define CListWnd__SetColumnJustification                           0x6C54B0
#define CListWnd__SetColumnWidth                                   0x6C5390
#define CListWnd__SetCurSel                                        0x6C4D60
#define CListWnd__SetItemColor                                     0x6C88C0
#define CListWnd__SetItemData                                      0x6C56E0
#define CListWnd__SetItemText                                      0x6C8840
#define CListWnd__ShiftColumnSeparator                             0x6C6FD0
#define CListWnd__Sort                                             0x6C96C0
#define CListWnd__ToggleSel                                        0x6C55B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5FBD70

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x606EC0
#define CMerchantWnd__RequestBuyItem                               0x608240
#define CMerchantWnd__RequestSellItem                              0x607110
#define CMerchantWnd__SelectBuySellSlot                            0x607F70

// CObfuscator
#define CObfuscator__doit                                          0x681180

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6DFE20
#define CSidlManager__CreateLabel                                  0x636C40

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5748D0
#define CSidlScreenWnd__CalculateVSBRange                          0x6E5910
#define CSidlScreenWnd__ConvertToRes                               0x6EF630
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6D0ED0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6D1FA0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6D2050
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6D1770
#define CSidlScreenWnd__DrawSidlPiece                              0x6D0BA0
#define CSidlScreenWnd__EnableIniStorage                           0x6D0740
#define CSidlScreenWnd__GetSidlPiece                               0x6D0DA0
#define CSidlScreenWnd__Init1                                      0x6D1E10
#define CSidlScreenWnd__LoadIniInfo                                0x6D0F80
#define CSidlScreenWnd__LoadIniListWnd                             0x6D0890
#define CSidlScreenWnd__LoadSidlScreen                             0x6D19C0
#define CSidlScreenWnd__StoreIniInfo                               0x6D0350
#define CSidlScreenWnd__WndNotification                            0x6D1B90
#define CSidlScreenWnd__GetChildItem                               0x6D07A0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x536900

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6F0AD0
#define CSliderWnd__SetValue                                       0x6F0BD0
#define CSliderWnd__SetNumTicks                                    0x6F1140

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x63C3F0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6ED8B0
#define CStmlWnd__CalculateVSBRange                                0x6E5910
#define CStmlWnd__CanBreakAtCharacter                              0x6E5A50
#define CStmlWnd__FastForwardToEndOfTag                            0x6E65C0
#define CStmlWnd__ForceParseNow                                    0x6EDD30
#define CStmlWnd__GetNextTagPiece                                  0x6E64E0
#define CStmlWnd__GetSTMLText                                      0x59C390
#define CStmlWnd__GetThisChar                                      0x713140
#define CStmlWnd__GetVisiableText                                  0x6E7800
#define CStmlWnd__InitializeWindowVariables                        0x6E99D0
#define CStmlWnd__MakeStmlColorTag                                 0x6E4FB0
#define CStmlWnd__MakeWndNotificationTag                           0x6E5050
#define CStmlWnd__SetSTMLText                                      0x6E9B00
#define CStmlWnd__StripFirstSTMLLines                              0x6ED640
#define CStmlWnd__UpdateHistoryString                              0x6E8070

// CTabWnd 
#define CTabWnd__Draw                                              0x6F1ED0
#define CTabWnd__DrawCurrentPage                                   0x6F18F0
#define CTabWnd__DrawTab                                           0x6F16D0
#define CTabWnd__GetCurrentPage                                    0x6F1B70
#define CTabWnd__GetPageClientRect                                 0x6F13A0
#define CTabWnd__GetPageFromTabIndex                               0x6F1600
#define CTabWnd__GetPageInnerRect                                  0x6F1400
#define CTabWnd__GetTabInnerRect                                   0x6F1580
#define CTabWnd__GetTabRect                                        0x6F1490
#define CTabWnd__IndexInBounds                                     0x0
#define CTabWnd__InsertPage                                        0x6F2140
#define CTabWnd__SetPage                                           0x6F1BB0
#define CTabWnd__SetPageRect                                       0x6F1E00
#define CTabWnd__UpdatePage                                        0x6F20C0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41DB50

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6D23B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6F6490

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6C4A10

// CXRect 
#define CXRect__CenterPoint                                        0x577F40

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x505540
#define CXStr__CXStr1                                              0x60E3D0
#define CXStr__CXStr3                                              0x6B7800
#define CXStr__dCXStr                                              0x60E3E0
#define CXStr__operator_equal1                                     0x6B79C0
#define CXStr__operator_plus_equal1                                0x6B88C0

// CXWnd 
#define CXWnd__BringToTop                                          0x6C9DB0
#define CXWnd__Center                                              0x6CD7F0
#define CXWnd__ClrFocus                                            0x6C9AC0
#define CXWnd__DoAllDrawing                                        0x6CE600
#define CXWnd__DrawChildren                                        0x6CE730
#define CXWnd__DrawColoredRect                                     0x6CA030
#define CXWnd__DrawTooltip                                         0x6CE420
#define CXWnd__DrawTooltipAtPoint                                  0x6CD5B0
#define CXWnd__GetBorderFrame                                      0x6CA510
#define CXWnd__GetChildWndAt                                       0x6CD0F0
#define CXWnd__GetClientClipRect                                   0x6CA420
#define CXWnd__GetScreenClipRect                                   0x6CDA10
#define CXWnd__GetScreenRect                                       0x6CA6B0
#define CXWnd__GetTooltipRect                                      0x6CA280
#define CXWnd__GetWindowTextA                                      0x56B5D0
#define CXWnd__IsActive                                            0x6D34C0
#define CXWnd__IsDescendantOf                                      0x6CA4A0
#define CXWnd__IsReallyVisible                                     0x6CD0D0
#define CXWnd__IsType                                              0x6F3340
#define CXWnd__Move                                                0x6CCCB0
#define CXWnd__Move1                                               0x6CE280
#define CXWnd__ProcessTransition                                   0x6C9D70
#define CXWnd__Refade                                              0x6C9B70
#define CXWnd__Resize                                              0x6CA780
#define CXWnd__Right                                               0x6CD950
#define CXWnd__SetFocus                                            0x6CBEE0
#define CXWnd__SetKeyTooltip                                       0x6CA990
#define CXWnd__SetMouseOver                                        0x6CA960
#define CXWnd__StartFade                                           0x6C9DF0
#define CXWnd__GetChildItem                                        0x6CDBD0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6D4940
#define CXWndManager__DrawWindows                                  0x6D4550
#define CXWndManager__GetKeyboardFlags                             0x6D3170
#define CXWndManager__HandleKeyboardMsg                            0x6D36C0
#define CXWndManager__RemoveWnd                                    0x6D35E0

// CDBStr
#define CDBStr__GetString                                          0x4677D0

// EQ_Character 
#define EQ_Character__CastRay                                      0x71F390
#define EQ_Character__CastSpell                                    0x42F210
#define EQ_Character__Cur_HP                                       0x43C870
#define EQ_Character__GetAACastingTimeModifier                     0x429D10
#define EQ_Character__GetCharInfo2                                 0x697120
#define EQ_Character__GetFocusCastingTimeModifier                  0x425780
#define EQ_Character__GetFocusRangeModifier                        0x4258C0
#define EQ_Character__Max_Endurance                                0x51A2E0
#define EQ_Character__Max_HP                                       0x437770
#define EQ_Character__Max_Mana                                     0x51A110
#define EQ_Character__doCombatAbility                              0x519020
#define EQ_Character__UseSkill                                     0x442960
#define EQ_Character__GetConLevel                                  0x5155E0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x503210
#define EQ_Item__GetItemLinkHash                                   0x68AC20
#define EQ_Item__IsStackable                                       0x681A60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4805D0
#define EQ_LoadingS__Array                                         0x85CB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51D150
#define EQ_PC__GetAltAbilityIndex                                  0x68F510
#define EQ_PC__GetCombatAbility                                    0x68F5A0
#define EQ_PC__GetCombatAbilityTimer                               0x68F650
#define EQ_PC__GetItemTimerValue                                   0x517F70
#define EQ_PC__HasLoreItem                                         0x51B620

// EQItemList 
#define EQItemList__dEQItemList                                    0x4AA830
#define EQItemList__EQItemList                                     0x4AA780

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x467190

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x521990
#define EQPlayer__dEQPlayer                                        0x5259E0
#define EQPlayer__DoAttack                                         0x532B80
#define EQPlayer__EQPlayer                                         0x529670
#define EQPlayer__SetNameSpriteState                               0x523960
#define EQPlayer__SetNameSpriteTint                                0x521A00
#define EQPlayer__IsBodyType_j                                     0x71ECA0
#define EQPlayer__IsTargetable                                     0x71EE30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x52A750
#define EQPlayerManager__GetSpawnByName                            0x52AA30

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x504EB0
#define KeypressHandler__AttachKeyToEqCommand                      0x504EF0
#define KeypressHandler__ClearCommandStateArray                    0x504CC0
#define KeypressHandler__HandleKeyDown                             0x503870
#define KeypressHandler__HandleKeyUp                               0x503B80
#define KeypressHandler__SaveKeymapping                            0x504D90

// MapViewMap 
#define MapViewMap__Clear                                          0x5F7440
#define MapViewMap__SaveEx                                         0x5F7E10

#define OtherCharData__GetAltCurrency                              0x6AE820

// StringTable 
#define StringTable__getString                                     0x681400
