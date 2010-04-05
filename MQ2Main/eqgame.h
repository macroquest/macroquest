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
#define __ExpectedVersionDate                                     "Mar 11 2009"
#define __ExpectedVersionTime                                     "18:43:34"
#define __ActualVersionDate                                        0x7DAF54
#define __ActualVersionTime                                        0x7DAF60

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x50A9A0
#define __MemChecker1                                              0x6B3810
#define __MemChecker2                                              0x560800
#define __MemChecker3                                              0x560750
#define __MemChecker4                                              0x675A10
#define __EncryptPad0                                              0x8606A0
#define __EncryptPad1                                              0x86ACF8
#define __EncryptPad2                                              0x8630E0
#define __EncryptPad3                                              0x862CE0
#define __EncryptPad4                                              0x86A3C8

// Direct Input
#define DI8__Main                                                  0xADC204
#define DI8__Keyboard                                              0xADC208
#define DI8__Mouse                                                 0xADC20C
#define __AltTimerReady                                            0xA66CC2
#define __Attack                                                   0xAC6766
#define __Autofire                                                 0xAC6767
#define __BindList                                                 0x85B650
#define __Clicks                                                   0xA659D8
#define __CommandList                                              0x85BEB0
#define __CurrentMapLabel                                          0xB07440
#define __CurrentSocial                                            0x857680
#define __DoAbilityAvailable                                       0xA66C5C
#define __DoAbilityList                                            0xA9C27C
#define __do_loot                                                  0x4B2960
#define __DrawHandler                                              0xB168A4
#define __GroupCount                                               0xA45E42
#define __Guilds                                                   0xA479C0
#define __gWorld                                                   0xA47900
#define __HotkeyPage                                               0xAC3668
#define __HWnd                                                     0xADBF44
#define __InChatMode                                               0xA65910
#define __LastTell                                                 0xA675D4
#define __LMouseHeldTime                                           0xA659F8
#define __Mouse                                                    0xADC210
#define __MouseLook                                                0xA659A6
#define __MouseEventTime                                           0xAC6870
#define __NetStatusToggle                                          0xA659A9
#define __PCNames                                                  0xA67018
#define __RangeAttackReady                                         0xA66CC0
#define __RMouseHeldTime                                           0xA659F4
#define __RunWalkState                                             0xA65914
#define __ScreenMode                                               0x995710
#define __ScreenX                                                  0xA658C8
#define __ScreenY                                                  0xA658CC
#define __ScreenXMax                                               0xA658D0
#define __ScreenYMax                                               0xA658D4
#define __ServerHost                                               0xA45D84
#define __ServerName                                               0xA9C23C
#define __ShiftKeyDown                                             0xA65F78
#define __ShowNames                                                0xA66EEC
#define __Socials                                                  0xA9C33C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA5F610
#define instEQZoneInfo                                             0xA65B44
#define instKeypressHandler                                        0xAC6854
#define pinstActiveBanker                                          0xA47998
#define pinstActiveCorpse                                          0xA4799C
#define pinstActiveGMaster                                         0xA479A0
#define pinstActiveMerchant                                        0xA47994
#define pinstAltAdvManager                                         0x996570
#define pinstAuraMgr                                               0x87EFD4
#define pinstBandageTarget                                         0xA47980
#define pinstCamActor                                              0x996060
#define pinstCDBStr                                                0x995700
#define pinstCDisplay                                              0xA479A8
#define pinstCEverQuest                                            0xADC388
#define pinstCharData                                              0xA47964
#define pinstCharSpawn                                             0xA4798C
#define pinstControlledMissile                                     0xA47960
#define pinstControlledPlayer                                      0xA4798C
#define pinstCSidlManager                                          0xB16028
#define pinstCXWndManager                                          0xB16020
#define instDynamicZone                                            0xA65318
#define pinstDZMember                                              0xA65428
#define pinstDZTimerInfo                                           0xA6542C
#define pinstEQItemList                                            0xA47948
#define instEQMisc                                                 0x9956B8
#define pinstEQSoundManager                                        0x996594
#define instExpeditionLeader                                       0xA65362
#define instExpeditionName                                         0xA653A2
#define pinstGroup                                                 0xA45E3E
#define pinstImeManager                                            0xB1602C
#define pinstLocalPlayer                                           0xA47978
#define pinstModelPlayer                                           0xA479A4
#define pinstPCData                                                0xA47964
#define pinstSkillMgr                                              0xAD905C
#define pinstSpawnManager                                          0xAD8FDC
#define pinstSpellManager                                          0xAD9060
#define pinstSpellSets                                             0xAC366C
#define pinstStringTable                                           0xA4791C
#define pinstSwitchManager                                         0xA45A84
#define pinstTarget                                                0xA47990
#define pinstTargetObject                                          0xA47968
#define pinstTargetSwitch                                          0xA4796C
#define pinstTaskMember                                            0x995698
#define pinstTrackTarget                                           0xA47984
#define pinstTradeTarget                                           0xA47974
#define instTributeActive                                          0x9956DD
#define pinstViewActor                                             0x99605C
#define pinstWorldData                                             0xA47944


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x87C880
#define pinstCAudioTriggersWindow                                  0x87C84C
#define pinstCCharacterSelect                                      0x995F6C
#define pinstCFacePick                                             0x995F20
#define pinstCNoteWnd                                              0x995F24
#define pinstCBookWnd                                              0x995F28
#define pinstCPetInfoWnd                                           0x995F2C
#define pinstCTrainWnd                                             0x995F30
#define pinstCSkillsWnd                                            0x995F34
#define pinstCSkillsSelectWnd                                      0x995F38
#define pinstCCombatSkillSelectWnd                                 0x995F3C
#define pinstCFriendsWnd                                           0x995F40
#define pinstCAuraWnd                                              0x995F44
#define pinstCRespawnWnd                                           0x995F48
#define pinstCBandolierWnd                                         0x995F4C
#define pinstCPotionBeltWnd                                        0x995F50
#define pinstCAAWnd                                                0x995F54
#define pinstCGroupSearchFiltersWnd                                0x995F58
#define pinstCLoadskinWnd                                          0x995F5C
#define pinstCAlarmWnd                                             0x995F60
#define pinstCMusicPlayerWnd                                       0x995F64
#define pinstCMailWnd                                              0x995F70
#define pinstCMailCompositionWnd                                   0x995F74
#define pinstCMailAddressBookWnd                                   0x995F78
#define pinstCRaidWnd                                              0x995F80
#define pinstCRaidOptionsWnd                                       0x995F84
#define pinstCBreathWnd                                            0x995F88
#define pinstCMapViewWnd                                           0x995F8C
#define pinstCMapToolbarWnd                                        0x995F90
#define pinstCEditLabelWnd                                         0x995F94
#define pinstCTargetWnd                                            0x995F98
#define pinstCColorPickerWnd                                       0x995F9C
#define pinstCPlayerWnd                                            0x995FA0
#define pinstCOptionsWnd                                           0x995FA4
#define pinstCBuffWindowNORMAL                                     0x995FA8
#define pinstCBuffWindowSHORT                                      0x995FAC
#define pinstCharacterCreation                                     0x995FB0
#define pinstCCursorAttachment                                     0x995FB4
#define pinstCCastingWnd                                           0x995FB8
#define pinstCCastSpellWnd                                         0x995FBC
#define pinstCSpellBookWnd                                         0x995FC0
#define pinstCInventoryWnd                                         0x995FC4
#define pinstCBankWnd                                              0x995FC8
#define pinstCQuantityWnd                                          0x995FCC
#define pinstCLootWnd                                              0x995FD0
#define pinstCActionsWnd                                           0x995FD4
#define pinstCCombatAbilityWnd                                     0x995FD8
#define pinstCMerchantWnd                                          0x995FDC
#define pinstCTradeWnd                                             0x995FE0
#define pinstCSelectorWnd                                          0x995FE4
#define pinstCBazaarWnd                                            0x995FE8
#define pinstCBazaarSearchWnd                                      0x995FEC
#define pinstCGiveWnd                                              0x995FF0
#define pinstCTrackingWnd                                          0x995FF4
#define pinstCInspectWnd                                           0x995FF8
#define pinstCSocialEditWnd                                        0x995FFC
#define pinstCFeedbackWnd                                          0x996000
#define pinstCBugReportWnd                                         0x996004
#define pinstCVideoModesWnd                                        0x996008
#define pinstCTextEntryWnd                                         0x996010
#define pinstCFileSelectionWnd                                     0x996014
#define pinstCCompassWnd                                           0x996018
#define pinstCPlayerNotesWnd                                       0x99601C
#define pinstCGemsGameWnd                                          0x996020
#define pinstCTimeLeftWnd                                          0x996024
#define pinstCPetitionQWnd                                         0x99602C
#define pinstCSoulmarkWnd                                          0x996030
#define pinstCStoryWnd                                             0x996034
#define pinstCJournalTextWnd                                       0x996038
#define pinstCJournalCatWnd                                        0x99603C
#define pinstCBodyTintWnd                                          0x996040
#define pinstCServerListWnd                                        0x996044
#define pinstCAvaZoneWnd                                           0x996048
#define pinstCBlockedBuffWnd                                       0x99604C
#define pinstCBlockedPetBuffWnd                                    0x996050
#define pinstCInvSlotMgr                                           0x996054
#define pinstCContainerMgr                                         0x996058
#define pinstCAdventureLeaderboardWnd                              0xB04970
#define pinstCAdventureRequestWnd                                  0xB0498C
#define pinstCAltStorageWnd                                        0xB049EC
#define pinstCAdventureStatsWnd                                    0xB049A8
#define pinstCBarterMerchantWnd                                    0xB04BB8
#define pinstCBarterSearchWnd                                      0xB04BD4
#define pinstCBarterWnd                                            0xB04BF0
#define pinstCChatManager                                          0xB04E94
#define pinstCDynamicZoneWnd                                       0xB04F8C
#define pinstCEQMainWnd                                            0xB05000
#define pinstCFellowshipWnd                                        0xB05064
#define pinstCFindLocationWnd                                      0xB05098
#define pinstCGroupSearchWnd                                       0xB05148
#define pinstCGroupWnd                                             0xB05164
#define pinstCGuildBankWnd                                         0xB05180
#define pinstCGuildMgmtWnd                                         0xB071B8
#define pinstCGuildTributeMasterWnd                                0xB071D8
#define pinstCHotButtonWnd                                         0xB071F4
#define pinstCHotButtonWnd1                                        0xB071F4
#define pinstCHotButtonWnd2                                        0xB071F8
#define pinstCHotButtonWnd3                                        0xB071FC
#define pinstCHotButtonWnd4                                        0xB07200
#define pinstCItemDisplayManager                                   0xB072AC
#define pinstCItemExpTransferWnd                                   0xB072CC
#define pinstCLeadershipWnd                                        0xB07368
#define pinstCLFGuildWnd                                           0xB07384
#define pinstCMIZoneSelectWnd                                      0xB074F4
#define pinstCAdventureMerchantWnd                                 0xB075EC
#define pinstCConfirmationDialog                                   0xB07608
#define pinstCPopupWndManager                                      0xB07608
#define pinstCProgressionSelectionWnd                              0xB0763C
#define pinstCPvPLeaderboardWnd                                    0xB07658
#define pinstCPvPStatsWnd                                          0xB07674
#define pinstCSystemInfoDialogBox                                  0xB07724
#define pinstCTargetOfTargetWnd                                    0xB0802C
#define pinstCTaskSelectWnd                                        0xB08060
#define pinstCTaskTemplateSelectWnd                                0xB0807C
#define pinstCTaskWnd                                              0xB08098
#define pinstCTipWndOFDAY                                          0xB08114
#define pinstCTipWndCONTEXT                                        0xB08118
#define pinstCTitleWnd                                             0xB08134
#define pinstCTradeskillWnd                                        0xB08178
#define pinstCTributeBenefitWnd                                    0xB081C4
#define pinstCTributeMasterWnd                                     0xB081E0
#define pinstCContextMenuManager                                   0xB16084
#define pinstCVoiceMacroWnd                                        0xAD9244
#define pinstCHtmlWnd                                              0xAD9280


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C56E0
#define __ConvertItemTags                                          0x4B7D70
#define __ExecuteCmd                                               0x4A6750
#define __get_melee_range                                          0x4ABC20
#define __GetGaugeValueFromEQ                                      0x63DCB0
#define __GetLabelFromEQ                                           0x63E9D0
#define __NewUIINI                                                 0x63D890
#define __ProcessGameEvents                                        0x4F4890
#define CrashDetected                                              0x55F4D0
#define DrawNetStatus                                              0x5131B0
#define Util__FastTime                                             0x6B3F60


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47F280
#define AltAdvManager__IsAbilityReady                              0x47F2C0
#define AltAdvManager__GetAltAbility                               0x47F4A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x577440

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x580880

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6E2020

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x596930
#define CChatManager__InitContextMenu                              0x5970D0

// CChatService
#define CChatService__GetNumberOfFriends                           0x6A3EC0
#define CChatService__GetFriendName                                0x6A3ED0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x59B2B0
#define CChatWindow__Clear                                         0x59BC30
#define CChatWindow__WndNotification                               0x59BD10

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6CCD40
#define CComboWnd__Draw                                            0x6CCEF0
#define CComboWnd__GetCurChoice                                    0x6CCCE0
#define CComboWnd__GetListRect                                     0x6CD1B0
#define CComboWnd__GetTextRect                                     0x6CCD70
#define CComboWnd__InsertChoice                                    0x6CD220
#define CComboWnd__SetColors                                       0x6CCC70
#define CComboWnd__SetChoice                                       0x6CCCA0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A2740
#define CContainerWnd__vftable                                     0x7E1B08

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46DDB0
#define CDisplay__GetClickedActor                                  0x46B4D0
#define CDisplay__GetUserDefinedColor                              0x46A5F0
#define CDisplay__GetWorldFilePath                                 0x469B10
#define CDisplay__is3dON                                           0x468C80
#define CDisplay__ReloadUI                                         0x47C430
#define CDisplay__WriteTextHD2                                     0x46E520

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x571330
#define CEditBaseWnd__SetSel                                       0x6ED470

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6D5780
#define CEditWnd__GetCharIndexPt                                   0x6D65C0
#define CEditWnd__GetDisplayString                                 0x6D5910
#define CEditWnd__GetHorzOffset                                    0x6D5BA0
#define CEditWnd__GetLineForPrintableChar                          0x6D6070
#define CEditWnd__GetSelStartPt                                    0x6D6800
#define CEditWnd__GetSTMLSafeText                                  0x6D5D30
#define CEditWnd__PointFromPrintableChar                           0x6D6180
#define CEditWnd__SelectableCharFromPoint                          0x6D6300
#define CEditWnd__SetEditable                                      0x6D5D00

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D8C80
#define CEverQuest__DropHeldItemOnGround                           0x4DD090
#define CEverQuest__dsp_chat                                       0x4DE5B0
#define CEverQuest__DoTellWindow                                   0x4DD210
#define CEverQuest__EnterZone                                      0x4F3250
#define CEverQuest__GetBodyTypeDesc                                0x4D5F00
#define CEverQuest__GetClassDesc                                   0x4D5740
#define CEverQuest__GetClassThreeLetterCode                        0x4D5D40
#define CEverQuest__GetDeityDesc                                   0x4D6570
#define CEverQuest__GetLangDesc                                    0x4D6290
#define CEverQuest__GetRaceDesc                                    0x4D6540
#define CEverQuest__InterpretCmd                                   0x4DF040
#define CEverQuest__LeftClickedOnPlayer                            0x4F19F0
#define CEverQuest__LMouseUp                                       0x4F4030
#define CEverQuest__RightClickedOnPlayer                           0x4F1DC0
#define CEverQuest__RMouseUp                                       0x4F3850
#define CEverQuest__SetGameState                                   0x4D9100
#define CEverQuest__Emote                                          0x4DE7A0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5AF670
#define CGaugeWnd__CalcLinesFillRect                               0x5AF6D0
#define CGaugeWnd__Draw                                            0x5AFAE0

// CGuild
#define CGuild__FindMemberByName                                   0x421690

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5C7BB0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D11B0
#define CInvSlotMgr__MoveItem                                      0x5D1350

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5CFB70
#define CInvSlot__SliderComplete                                   0x5D0080

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5DFFD0
#define CItemDisplayWnd__SetSpell                                  0x63BA00

// CLabel 
#define CLabel__Draw                                               0x5E5960

// CListWnd 
#define CListWnd__AddColumn                                        0x6C7560
#define CListWnd__AddColumn1                                       0x6C7040
#define CListWnd__AddLine                                          0x6C6B30
#define CListWnd__AddString                                        0x6C6D20
#define CListWnd__CalculateFirstVisibleLine                        0x6C3DF0
#define CListWnd__CalculateVSBRange                                0x6C5B90
#define CListWnd__ClearAllSel                                      0x6C3520
#define CListWnd__CloseAndUpdateEditWindow                         0x6C4415
#define CListWnd__Compare                                          0x6C4790
#define CListWnd__Draw                                             0x6C5880
#define CListWnd__DrawColumnSeparators                             0x6C56F0
#define CListWnd__DrawHeader                                       0x6C36F0
#define CListWnd__DrawItem                                         0x6C5020
#define CListWnd__DrawLine                                         0x6C5390
#define CListWnd__DrawSeparator                                    0x6C5790
#define CListWnd__EnsureVisible                                    0x6C3E40
#define CListWnd__ExtendSel                                        0x6C4F40
#define CListWnd__GetColumnMinWidth                                0x6C32B0
#define CListWnd__GetColumnWidth                                   0x6C31F0
#define CListWnd__GetCurSel                                        0x6C2C00
#define CListWnd__GetHeaderRect                                    0x6C2D70
#define CListWnd__GetItemAtPoint                                   0x6C4120
#define CListWnd__GetItemAtPoint1                                  0x6C4190
#define CListWnd__GetItemData                                      0x6C2FA0
#define CListWnd__GetItemHeight                                    0x6C3B80
#define CListWnd__GetItemIcon                                      0x6C3130
#define CListWnd__GetItemRect                                      0x6C3F10
#define CListWnd__GetItemText                                      0x6C2FE0
#define CListWnd__GetSelList                                       0x6C6F20
#define CListWnd__GetSeparatorRect                                 0x6C46D0
#define CListWnd__RemoveLine                                       0x6C6ED0
#define CListWnd__SetColors                                        0x6C2CD0
#define CListWnd__SetColumnJustification                           0x6C3390
#define CListWnd__SetColumnWidth                                   0x6C3270
#define CListWnd__SetCurSel                                        0x6C2C40
#define CListWnd__SetItemColor                                     0x6C67A0
#define CListWnd__SetItemData                                      0x6C35C0
#define CListWnd__SetItemText                                      0x6C6720
#define CListWnd__ShiftColumnSeparator                             0x6C4EB0
#define CListWnd__Sort                                             0x6C75A0
#define CListWnd__ToggleSel                                        0x6C3490

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5FAAB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x605BF0
#define CMerchantWnd__RequestBuyItem                               0x606F70
#define CMerchantWnd__RequestSellItem                              0x605E40
#define CMerchantWnd__SelectBuySellSlot                            0x606CA0

// CObfuscator
#define CObfuscator__doit                                          0x67F060

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6DDAE0
#define CSidlManager__CreateLabel                                  0x634A90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x573410
#define CSidlScreenWnd__CalculateVSBRange                          0x6E35E0
#define CSidlScreenWnd__ConvertToRes                               0x6ED350
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6CED00
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6CFDD0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6CFE80
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6CF5A0
#define CSidlScreenWnd__DrawSidlPiece                              0x6CE9D0
#define CSidlScreenWnd__EnableIniStorage                           0x6CE620
#define CSidlScreenWnd__GetSidlPiece                               0x6CEBD0
#define CSidlScreenWnd__Init1                                      0x6CFC40
#define CSidlScreenWnd__LoadIniInfo                                0x6CEDB0
#define CSidlScreenWnd__LoadIniListWnd                             0x6CE770
#define CSidlScreenWnd__LoadSidlScreen                             0x6CF7F0
#define CSidlScreenWnd__StoreIniInfo                               0x6CE230
#define CSidlScreenWnd__WndNotification                            0x6CF9C0
#define CSidlScreenWnd__GetChildItem                               0x6CE680

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x535850

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6EE800
#define CSliderWnd__SetValue                                       0x6EE900
#define CSliderWnd__SetNumTicks                                    0x6EEE70

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x63A1F0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6EB5D0
#define CStmlWnd__CalculateVSBRange                                0x6E35E0
#define CStmlWnd__CanBreakAtCharacter                              0x6E3720
#define CStmlWnd__FastForwardToEndOfTag                            0x6E42E0
#define CStmlWnd__ForceParseNow                                    0x6EBA50
#define CStmlWnd__GetNextTagPiece                                  0x6E4200
#define CStmlWnd__GetSTMLText                                      0x59B250
#define CStmlWnd__GetThisChar                                      0x710B10
#define CStmlWnd__GetVisiableText                                  0x6E5520
#define CStmlWnd__InitializeWindowVariables                        0x6E76F0
#define CStmlWnd__MakeStmlColorTag                                 0x6E2C80
#define CStmlWnd__MakeWndNotificationTag                           0x6E2D20
#define CStmlWnd__SetSTMLText                                      0x6E7820
#define CStmlWnd__StripFirstSTMLLines                              0x6EB360
#define CStmlWnd__UpdateHistoryString                              0x6E5D90

// CTabWnd 
#define CTabWnd__Draw                                              0x6EFC80
#define CTabWnd__DrawCurrentPage                                   0x6EF620
#define CTabWnd__DrawTab                                           0x6EF400
#define CTabWnd__GetCurrentPage                                    0x6EF920
#define CTabWnd__GetPageClientRect                                 0x6EF0D0
#define CTabWnd__GetPageFromTabIndex                               0x6EF330
#define CTabWnd__GetPageInnerRect                                  0x6EF130
#define CTabWnd__GetTabInnerRect                                   0x6EF2B0
#define CTabWnd__GetTabRect                                        0x6EF1C0
#define CTabWnd__IndexInBounds                                     0x6EF3CD
#define CTabWnd__InsertPage                                        0x6EFEF0
#define CTabWnd__SetPage                                           0x6EF960
#define CTabWnd__SetPageRect                                       0x6EFBB0
#define CTabWnd__UpdatePage                                        0x6EFE70

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41DB90

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6D01E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6F4200

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6C28F0

// CXRect 
#define CXRect__CenterPoint                                        0x576AD0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x41C010
#define CXStr__CXStr1                                              0x6BD8D0
#define CXStr__CXStr3                                              0x6B5660
#define CXStr__dCXStr                                              0x631020
#define CXStr__operator_equal1                                     0x6B5820
#define CXStr__operator_plus_equal1                                0x6B6720

// CXWnd 
#define CXWnd__BringToTop                                          0x6C7C90
#define CXWnd__Center                                              0x6CB720
#define CXWnd__ClrFocus                                            0x6C79A0
#define CXWnd__DoAllDrawing                                        0x6CC4E0
#define CXWnd__DrawChildren                                        0x6CC610
#define CXWnd__DrawColoredRect                                     0x6C7F10
#define CXWnd__DrawTooltip                                         0x6CC300
#define CXWnd__DrawTooltipAtPoint                                  0x6CB4E0
#define CXWnd__GetBorderFrame                                      0x6C83F0
#define CXWnd__GetChildWndAt                                       0x6CB020
#define CXWnd__GetClientClipRect                                   0x6C8300
#define CXWnd__GetScreenClipRect                                   0x6CB940
#define CXWnd__GetScreenRect                                       0x6C8590
#define CXWnd__GetTooltipRect                                      0x6C8160
#define CXWnd__GetWindowTextA                                      0x56A070
#define CXWnd__IsActive                                            0x6D12F0
#define CXWnd__IsDescendantOf                                      0x6C8380
#define CXWnd__IsReallyVisible                                     0x6CB000
#define CXWnd__IsType                                              0x6F1160
#define CXWnd__Move                                                0x6CABE0
#define CXWnd__Move1                                               0x6CC160
#define CXWnd__ProcessTransition                                   0x6C7C50
#define CXWnd__Refade                                              0x6C7A50
#define CXWnd__Resize                                              0x6C8660
#define CXWnd__Right                                               0x6CB880
#define CXWnd__SetFocus                                            0x6C9E10
#define CXWnd__SetKeyTooltip                                       0x6C8870
#define CXWnd__SetMouseOver                                        0x6C8840
#define CXWnd__StartFade                                           0x6C7CD0
#define CXWnd__GetChildItem                                        0x6CBAB0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6D26F0
#define CXWndManager__DrawWindows                                  0x6D2300
#define CXWndManager__GetKeyboardFlags                             0x6D0FA0
#define CXWndManager__HandleKeyboardMsg                            0x6D14F0
#define CXWndManager__RemoveWnd                                    0x6D1410

// CDBStr
#define CDBStr__GetString                                          0x467600

// EQ_Character 
#define EQ_Character__CastRay                                      0x71CBC0
#define EQ_Character__CastSpell                                    0x42F250
#define EQ_Character__Cur_HP                                       0x43C730
#define EQ_Character__GetAACastingTimeModifier                     0x429D90
#define EQ_Character__GetCharInfo2                                 0x695030
#define EQ_Character__GetFocusCastingTimeModifier                  0x425850
#define EQ_Character__GetFocusRangeModifier                        0x425990
#define EQ_Character__Max_Endurance                                0x5192F0
#define EQ_Character__Max_HP                                       0x437630
#define EQ_Character__Max_Mana                                     0x519120
#define EQ_Character__doCombatAbility                              0x518030
#define EQ_Character__UseSkill                                     0x442820
#define EQ_Character__GetConLevel                                  0x5145F0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x502260
#define EQ_Item__GetItemLinkHash                                   0x688B00
#define EQ_Item__IsStackable                                       0x67F940

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x480370
#define EQ_LoadingS__Array                                         0x859B30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51C160
#define EQ_PC__GetAltAbilityIndex                                  0x68D420
#define EQ_PC__GetCombatAbility                                    0x68D4B0
#define EQ_PC__GetCombatAbilityTimer                               0x68D560
#define EQ_PC__GetItemTimerValue                                   0x516F80
#define EQ_PC__HasLoreItem                                         0x51A630

// EQItemList 
#define EQItemList__dEQItemList                                    0x4AA310
#define EQItemList__EQItemList                                     0x4AA260

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x466FC0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x520990
#define EQPlayer__dEQPlayer                                        0x5249C0
#define EQPlayer__DoAttack                                         0x531B00
#define EQPlayer__EQPlayer                                         0x5286C0
#define EQPlayer__SetNameSpriteState                               0x522960
#define EQPlayer__SetNameSpriteTint                                0x520A00
#define EQPlayer__IsBodyType_j                                     0x71C590
#define EQPlayer__IsTargetable                                     0x71C720

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5297A0
#define EQPlayerManager__GetSpawnByName                            0x529A80

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x503F00
#define KeypressHandler__AttachKeyToEqCommand                      0x503F40
#define KeypressHandler__ClearCommandStateArray                    0x503D10
#define KeypressHandler__HandleKeyDown                             0x5028C0
#define KeypressHandler__HandleKeyUp                               0x502BD0
#define KeypressHandler__SaveKeymapping                            0x503DE0

// MapViewMap 
#define MapViewMap__Clear                                          0x5F6180
#define MapViewMap__SaveEx                                         0x5F6B50

#define OtherCharData__GetAltCurrency                              0x6AC660

// StringTable 
#define StringTable__getString                                     0x67F2E0
