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
#define __ExpectedVersionDate                                     "Jan 12 2011"
#define __ExpectedVersionTime                                     "15:00:31"
#define __ActualVersionDate                                        0x87B950
#define __ActualVersionTime                                        0x87B95C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x524EE0
#define __MemChecker1                                              0x798300
#define __MemChecker2                                              0x596D60
#define __MemChecker3                                              0x596CB0
#define __MemChecker4                                              0x7B2250
#define __EncryptPad0                                              0x911538
#define __EncryptPad1                                              0x91D208
#define __EncryptPad2                                              0x9142A0
#define __EncryptPad3                                              0x913EA0
#define __EncryptPad4                                              0x91EC38
#define __AC1                                                      0x6A5550
#define __AC2                                                      0x4E7DE5
#define __AC3                                                      0x4FA828
#define __AC4                                                      0x4FFB68
#define __AC5                                                      0x50BD4E
#define __AC6                                                      0x50F48E
#define __AC7                                                      0x50790B
#define __AC1_Data                                                 0x862AFD

// Direct Input
#define DI8__Main                                                  0xB7B324
#define DI8__Keyboard                                              0xB7B328
#define DI8__Mouse                                                 0xB7B32C
#define __AltTimerReady                                            0xAFFA7E
#define __Attack                                                   0xB6356A
#define __Autofire                                                 0xB6356B
#define __BindList                                                 0x90BB10
#define __Clicks                                                   0xAFE730
#define __CommandList                                              0x90C4F0
#define __CurrentMapLabel                                          0xBA65C0
#define __CurrentSocial                                            0x907978
#define __DoAbilityAvailable                                       0xAFFA18
#define __DoAbilityList                                            0xB35488
#define __do_loot                                                  0x4BD020
#define __DrawHandler                                              0x115A89C
#define __GroupCount                                               0xAF851A
#define __Guilds                                                   0xAFDB10
#define __gWorld                                                   0xAFA3D4
#define __HotkeyPage                                               0xB5C874
#define __HWnd                                                     0xB7B060
#define __InChatMode                                               0xAFE668
#define __LastTell                                                 0xB003A0
#define __LMouseHeldTime                                           0xAFE79C
#define __Mouse                                                    0xB7B330
#define __MouseLook                                                0xAFE6FE
#define __MouseEventTime                                           0xB636CC
#define __NetStatusToggle                                          0xAFE701
#define __PCNames                                                  0xAFFDE4
#define __RangeAttackReady                                         0xAFFA7C
#define __RMouseHeldTime                                           0xAFE798
#define __RunWalkState                                             0xAFE66C
#define __ScreenMode                                               0xA47D60
#define __ScreenX                                                  0xAFE620
#define __ScreenY                                                  0xAFE624
#define __ScreenXMax                                               0xAFE628
#define __ScreenYMax                                               0xAFE62C
#define __ServerHost                                               0xAF845C
#define __ServerName                                               0xB35448
#define __ShiftKeyDown                                             0xAFED2C
#define __ShowNames                                                0xAFFCB4
#define __Socials                                                  0xB35548


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xAFA4A8
#define instEQZoneInfo                                             0xAFE8E8
#define instKeypressHandler                                        0xB636B0
#define pinstActiveBanker                                          0xAFA47C
#define pinstActiveCorpse                                          0xAFA480
#define pinstActiveGMaster                                         0xAFA484
#define pinstActiveMerchant                                        0xAFA478
#define pinstAltAdvManager                                         0xA48C00
#define pinstAuraMgr                                               0x93161C
#define pinstBandageTarget                                         0xAFA464
#define pinstCamActor                                              0xA486EC
#define pinstCDBStr                                                0xA47D54
#define pinstCDisplay                                              0xAFA48C
#define pinstCEverQuest                                            0xB7B4A8
#define pinstCharData                                              0xAFA448
#define pinstCharSpawn                                             0xAFA470
#define pinstControlledMissile                                     0xAFA444
#define pinstControlledPlayer                                      0xAFA470
#define pinstCSidlManager                                          0x115AD6C
#define pinstCXWndManager                                          0x115AD64
#define instDynamicZone                                            0xAFE4F0
#define pinstDZMember                                              0xAFE600
#define pinstDZTimerInfo                                           0xAFE604
#define pinstEQItemList                                            0xAF772C
#define instEQMisc                                                 0xA47D00
#define pinstEQSoundManager                                        0xA48C24
#define instExpeditionLeader                                       0xAFE53A
#define instExpeditionName                                         0xAFE57A
#define pinstGroup                                                 0xAF8516
#define pinstImeManager                                            0x115AD70
#define pinstLocalPlayer                                           0xAFA45C
#define pinstMercenaryData                                         0xB63A44
#define pinstModelPlayer                                           0xAFA488
#define pinstPCData                                                0xAFA448
#define pinstSkillMgr                                              0xB78114
#define pinstSpawnManager                                          0xB77F30
#define pinstSpellManager                                          0xB78120
#define pinstSpellSets                                             0xB5C878
#define pinstStringTable                                           0xAFA3F0
#define pinstSwitchManager                                         0xAF815C
#define pinstTarget                                                0xAFA474
#define pinstTargetObject                                          0xAFA44C
#define pinstTargetSwitch                                          0xAFA450
#define pinstTaskMember                                            0xA47CE0
#define pinstTrackTarget                                           0xAFA468
#define pinstTradeTarget                                           0xAFA458
#define instTributeActive                                          0xA47D25
#define pinstViewActor                                             0xA486E8
#define pinstWorldData                                             0xAFA42C


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x92EEE0
#define pinstCAudioTriggersWindow                                  0x92EEAC
#define pinstCCharacterSelect                                      0xA485D0
#define pinstCFacePick                                             0xA48580
#define pinstCNoteWnd                                              0xA48588
#define pinstCBookWnd                                              0xA4858C
#define pinstCPetInfoWnd                                           0xA48590
#define pinstCTrainWnd                                             0xA48594
#define pinstCSkillsWnd                                            0xA48598
#define pinstCSkillsSelectWnd                                      0xA4859C
#define pinstCCombatSkillSelectWnd                                 0xA485A0
#define pinstCFriendsWnd                                           0xA485A4
#define pinstCAuraWnd                                              0xA485A8
#define pinstCRespawnWnd                                           0xA485AC
#define pinstCBandolierWnd                                         0xA485B0
#define pinstCPotionBeltWnd                                        0xA485B4
#define pinstCAAWnd                                                0xA485B8
#define pinstCGroupSearchFiltersWnd                                0xA485BC
#define pinstCLoadskinWnd                                          0xA485C0
#define pinstCAlarmWnd                                             0xA485C4
#define pinstCMusicPlayerWnd                                       0xA485C8
#define pinstCMailWnd                                              0xA485D4
#define pinstCMailCompositionWnd                                   0xA485D8
#define pinstCMailAddressBookWnd                                   0xA485DC
#define pinstCRaidWnd                                              0xA485E4
#define pinstCRaidOptionsWnd                                       0xA485E8
#define pinstCBreathWnd                                            0xA485EC
#define pinstCMapViewWnd                                           0xA485F0
#define pinstCMapToolbarWnd                                        0xA485F4
#define pinstCEditLabelWnd                                         0xA485F8
#define pinstCTargetWnd                                            0xA485FC
#define pinstCColorPickerWnd                                       0xA48600
#define pinstCPlayerWnd                                            0xA48604
#define pinstCOptionsWnd                                           0xA48608
#define pinstCBuffWindowNORMAL                                     0xA4860C
#define pinstCBuffWindowSHORT                                      0xA48610
#define pinstCharacterCreation                                     0xA48614
#define pinstCCursorAttachment                                     0xA48618
#define pinstCCastingWnd                                           0xA4861C
#define pinstCCastSpellWnd                                         0xA48620
#define pinstCSpellBookWnd                                         0xA48624
#define pinstCInventoryWnd                                         0xA48628
#define pinstCBankWnd                                              0xA4862C
#define pinstCQuantityWnd                                          0xA48630
#define pinstCLootWnd                                              0xA48634
#define pinstCActionsWnd                                           0xA48638
#define pinstCCombatAbilityWnd                                     0xA4863C
#define pinstCMerchantWnd                                          0xA48640
#define pinstCTradeWnd                                             0xA48644
#define pinstCSelectorWnd                                          0xA48648
#define pinstCBazaarWnd                                            0xA4864C
#define pinstCBazaarSearchWnd                                      0xA48650
#define pinstCGiveWnd                                              0xA48668
#define pinstCTrackingWnd                                          0xA4866C
#define pinstCInspectWnd                                           0xA48670
#define pinstCSocialEditWnd                                        0xA48674
#define pinstCFeedbackWnd                                          0xA48678
#define pinstCBugReportWnd                                         0xA4867C
#define pinstCVideoModesWnd                                        0xA48680
#define pinstCTextEntryWnd                                         0xA48688
#define pinstCFileSelectionWnd                                     0xA4868C
#define pinstCCompassWnd                                           0xA48690
#define pinstCPlayerNotesWnd                                       0xA48694
#define pinstCGemsGameWnd                                          0xA48698
#define pinstCTimeLeftWnd                                          0xA4869C
#define pinstCPetitionQWnd                                         0xA486B0
#define pinstCSoulmarkWnd                                          0xA486B4
#define pinstCStoryWnd                                             0xA486B8
#define pinstCJournalTextWnd                                       0xA486BC
#define pinstCJournalCatWnd                                        0xA486C0
#define pinstCBodyTintWnd                                          0xA486C4
#define pinstCServerListWnd                                        0xA486C8
#define pinstCAvaZoneWnd                                           0xA486D0
#define pinstCBlockedBuffWnd                                       0xA486D4
#define pinstCBlockedPetBuffWnd                                    0xA486D8
#define pinstCInvSlotMgr                                           0xA486E0
#define pinstCContainerMgr                                         0xA486E4
#define pinstCAdventureLeaderboardWnd                              0xBA3AD8
#define pinstCAdventureRequestWnd                                  0xBA3AF4
#define pinstCAltStorageWnd                                        0xBA3B54
#define pinstCAdventureStatsWnd                                    0xBA3B10
#define pinstCBarterMerchantWnd                                    0xBA3D20
#define pinstCBarterSearchWnd                                      0xBA3D3C
#define pinstCBarterWnd                                            0xBA3D58
#define pinstCChatManager                                          0xBA3FFC
#define pinstCDynamicZoneWnd                                       0xBA40F4
#define pinstCEQMainWnd                                            0xBA4168
#define pinstCFellowshipWnd                                        0xBA41CC
#define pinstCFindLocationWnd                                      0xBA4200
#define pinstCGroupSearchWnd                                       0xBA42B0
#define pinstCGroupWnd                                             0xBA42CC
#define pinstCGuildBankWnd                                         0xBA42E8
#define pinstCGuildMgmtWnd                                         0xBA6320
#define pinstCGuildTributeMasterWnd                                0xBA6340
#define pinstCHotButtonWnd                                         0xBA6374
#define pinstCHotButtonWnd1                                        0xBA6374
#define pinstCHotButtonWnd2                                        0xBA6378
#define pinstCHotButtonWnd3                                        0xBA637C
#define pinstCHotButtonWnd4                                        0xBA6380
#define pinstCItemDisplayManager                                   0xBA642C
#define pinstCItemExpTransferWnd                                   0xBA644C
#define pinstCLeadershipWnd                                        0xBA64E8
#define pinstCLFGuildWnd                                           0xBA6504
#define pinstCMIZoneSelectWnd                                      0xBA6674
#define pinstCAdventureMerchantWnd                                 0xBA679C
#define pinstCConfirmationDialog                                   0xBA67B8
#define pinstCPopupWndManager                                      0xBA67B8
#define pinstCProgressionSelectionWnd                              0xBA67EC
#define pinstCPvPLeaderboardWnd                                    0xBA6808
#define pinstCPvPStatsWnd                                          0xBA6824
#define pinstCSystemInfoDialogBox                                  0xBA6968
#define pinstCTargetOfTargetWnd                                    0xBA7470
#define pinstCTaskSelectWnd                                        0xBA74A4
#define pinstCTaskTemplateSelectWnd                                0xBA74C0
#define pinstCTaskWnd                                              0xBA74DC
#define pinstCTipWndOFDAY                                          0xBA7558
#define pinstCTipWndCONTEXT                                        0xBA755C
#define pinstCTitleWnd                                             0xBA7578
#define pinstCTradeskillWnd                                        0xBA75BC
#define pinstCTributeBenefitWnd                                    0xBA7608
#define pinstCTributeMasterWnd                                     0xBA7624
#define pinstCContextMenuManager                                   0x115ADC8
#define pinstCVoiceMacroWnd                                        0xB78314
#define pinstCHtmlWnd                                              0xB78360


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D0C10
#define __ConvertItemTags                                          0x4C26A0
#define __ExecuteCmd                                               0x4AE350
#define __get_melee_range                                          0x4B43B0
#define __GetGaugeValueFromEQ                                      0x6A43D0
#define __GetLabelFromEQ                                           0x6A54F0
#define __GetXTargetType                                           0x718280
#define __LoadFrontEnd                                             0x595C90
#define __NewUIINI                                                 0x6A3F80
#define __ProcessGameEvents                                        0x508080
#define CrashDetected                                              0x595A90
#define DrawNetStatus                                              0x5314C0
#define Util__FastTime                                             0x798AB0
#define Expansion_HoT                                              0xAFFC14

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483900
#define AltAdvManager__IsAbilityReady                              0x483940
#define AltAdvManager__GetAltAbility                               0x483B20

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x438F60

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5B37D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5BDB70

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x75F310

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5D59A0
#define CChatManager__InitContextMenu                              0x5D6170

// CChatService
#define CChatService__GetNumberOfFriends                           0x70D490
#define CChatService__GetFriendName                                0x70D4A0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5DA4A0
#define CChatWindow__Clear                                         0x5DAE00
#define CChatWindow__WndNotification                               0x5DAFF0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x749340
#define CComboWnd__Draw                                            0x749500
#define CComboWnd__GetCurChoice                                    0x749200
#define CComboWnd__GetListRect                                     0x7497F0
#define CComboWnd__GetTextRect                                     0x749370
#define CComboWnd__InsertChoice                                    0x749860
#define CComboWnd__SetColors                                       0x749190
#define CComboWnd__SetChoice                                       0x7491C0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5E4180
#define CContainerWnd__vftable                                     0x883058

// CDisplay 
#define CDisplay__CleanGameUI                                      0x4762B0
#define CDisplay__GetClickedActor                                  0x46F280
#define CDisplay__GetUserDefinedColor                              0x46DC60
#define CDisplay__GetWorldFilePath                                 0x46D110
#define CDisplay__is3dON                                           0x46C240
#define CDisplay__ReloadUI                                         0x480AD0
#define CDisplay__WriteTextHD2                                     0x472040

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5AD760
#define CEditBaseWnd__SetSel                                       0x76C920

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7522F0
#define CEditWnd__GetCharIndexPt                                   0x7532B0
#define CEditWnd__GetDisplayString                                 0x752480
#define CEditWnd__GetHorzOffset                                    0x752710
#define CEditWnd__GetLineForPrintableChar                          0x752D60
#define CEditWnd__GetSelStartPt                                    0x753500
#define CEditWnd__GetSTMLSafeText                                  0x7528B0
#define CEditWnd__PointFromPrintableChar                           0x752E70
#define CEditWnd__SelectableCharFromPoint                          0x752FF0
#define CEditWnd__SetEditable                                      0x752880

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4E8510
#define CEverQuest__DropHeldItemOnGround                           0x4F5BF0
#define CEverQuest__dsp_chat                                       0x4EE980
#define CEverQuest__DoTellWindow                                   0x4ED150
#define CEverQuest__EnterZone                                      0x4FFB00
#define CEverQuest__GetBodyTypeDesc                                0x4E5380
#define CEverQuest__GetClassDesc                                   0x4E4BC0
#define CEverQuest__GetClassThreeLetterCode                        0x4E51C0
#define CEverQuest__GetDeityDesc                                   0x4E59F0
#define CEverQuest__GetLangDesc                                    0x4E5710
#define CEverQuest__GetRaceDesc                                    0x4E59C0
#define CEverQuest__InterpretCmd                                   0x4EF4E0
#define CEverQuest__LeftClickedOnPlayer                            0x501C80
#define CEverQuest__LMouseUp                                       0x505610
#define CEverQuest__RightClickedOnPlayer                           0x506760
#define CEverQuest__RMouseUp                                       0x5078D0
#define CEverQuest__SetGameState                                   0x4E89A0
#define CEverQuest__Emote                                          0x4EEBA0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5F11A0
#define CGaugeWnd__CalcLinesFillRect                               0x5F1200
#define CGaugeWnd__Draw                                            0x5F1650

// CGuild
#define CGuild__FindMemberByName                                   0x41B980

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x60A2F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x615700
#define CInvSlotMgr__MoveItem                                      0x615B10

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x614B90
#define CInvSlot__SliderComplete                                   0x613560
#define CInvSlot__GetItemBase                                      0x612CC0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x616880

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6A1C90
#define CItemDisplayWnd__UpdateStrings                             0x617760

// CLabel 
#define CLabel__Draw                                               0x62B970

// CListWnd 
#define CListWnd__AddColumn                                        0x741F80
#define CListWnd__AddColumn1                                       0x741640
#define CListWnd__AddLine                                          0x7411A0
#define CListWnd__AddString                                        0x741340
#define CListWnd__CalculateFirstVisibleLine                        0x73D4B0
#define CListWnd__CalculateVSBRange                                0x73F7E0
#define CListWnd__ClearAllSel                                      0x73CA00
#define CListWnd__CloseAndUpdateEditWindow                         0x740810
#define CListWnd__Compare                                          0x73DEB0
#define CListWnd__Draw                                             0x73F420
#define CListWnd__DrawColumnSeparators                             0x73F290
#define CListWnd__DrawHeader                                       0x73CC90
#define CListWnd__DrawItem                                         0x73E8B0
#define CListWnd__DrawLine                                         0x73EF10
#define CListWnd__DrawSeparator                                    0x73F330
#define CListWnd__EnsureVisible                                    0x73D610
#define CListWnd__ExtendSel                                        0x73E7D0
#define CListWnd__GetColumnMinWidth                                0x73C6D0
#define CListWnd__GetColumnWidth                                   0x73C610
#define CListWnd__GetCurSel                                        0x73BE60
#define CListWnd__GetHeaderRect                                    0x73BFC0
#define CListWnd__GetItemAtPoint                                   0x73D8E0
#define CListWnd__GetItemAtPoint1                                  0x73D950
#define CListWnd__GetItemData                                      0x73C210
#define CListWnd__GetItemHeight                                    0x73D120
#define CListWnd__GetItemIcon                                      0x73C3F0
#define CListWnd__GetItemRect                                      0x73D6E0
#define CListWnd__GetItemText                                      0x73C2A0
#define CListWnd__GetSelList                                       0x741520
#define CListWnd__GetSeparatorRect                                 0x73DE00
#define CListWnd__RemoveLine                                       0x7414D0
#define CListWnd__SetColors                                        0x73BF30
#define CListWnd__SetColumnJustification                           0x73C870
#define CListWnd__SetColumnWidth                                   0x73C690
#define CListWnd__SetCurSel                                        0x73BEA0
#define CListWnd__SetItemColor                                     0x7404D0
#define CListWnd__SetItemData                                      0x73CAA0
#define CListWnd__SetItemText                                      0x7402B0
#define CListWnd__ShiftColumnSeparator                             0x740120
#define CListWnd__Sort                                             0x7426C0
#define CListWnd__ToggleSel                                        0x73C970

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x641860

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x6525C0
#define CMerchantWnd__RequestBuyItem                               0x655E80
#define CMerchantWnd__RequestSellItem                              0x674D70
#define CMerchantWnd__SelectBuySellSlot                            0x6538E0

// CObfuscator
#define CObfuscator__doit                                          0x6DCF30

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x75AB60
#define CSidlManager__CreateLabel                                  0x69AB20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5AF9A0
#define CSidlScreenWnd__CalculateVSBRange                          0x5AF8C0
#define CSidlScreenWnd__ConvertToRes                               0x76C800
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x74B420
#define CSidlScreenWnd__CSidlScreenWnd1                            0x74C510
#define CSidlScreenWnd__CSidlScreenWnd2                            0x74C5C0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x74BCD0
#define CSidlScreenWnd__DrawSidlPiece                              0x74B0E0
#define CSidlScreenWnd__EnableIniStorage                           0x74ABB0
#define CSidlScreenWnd__GetSidlPiece                               0x74B2F0
#define CSidlScreenWnd__Init1                                      0x74C370
#define CSidlScreenWnd__LoadIniInfo                                0x74B4D0
#define CSidlScreenWnd__LoadIniListWnd                             0x74AD00
#define CSidlScreenWnd__LoadSidlScreen                             0x74BF20
#define CSidlScreenWnd__StoreIniInfo                               0x74A7B0
#define CSidlScreenWnd__StoreIniVis                                0x74AB40
#define CSidlScreenWnd__WndNotification                            0x74C0F0
#define CSidlScreenWnd__GetChildItem                               0x74AC10

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x563440

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x76D1F0
#define CSliderWnd__SetValue                                       0x76D2F0
#define CSliderWnd__SetNumTicks                                    0x76D8A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x69F890

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x769E90
#define CStmlWnd__CalculateHSBRange                                0x7615A0
#define CStmlWnd__CalculateVSBRange                                0x761510
#define CStmlWnd__CanBreakAtCharacter                              0x761710
#define CStmlWnd__FastForwardToEndOfTag                            0x7623F0
#define CStmlWnd__ForceParseNow                                    0x76A3C0
#define CStmlWnd__GetNextTagPiece                                  0x762310
#define CStmlWnd__GetSTMLText                                      0x5DA440
#define CStmlWnd__GetThisChar                                      0x791750
#define CStmlWnd__GetVisiableText                                  0x763840
#define CStmlWnd__InitializeWindowVariables                        0x765E10
#define CStmlWnd__MakeStmlColorTag                                 0x760430
#define CStmlWnd__MakeWndNotificationTag                           0x7604D0
#define CStmlWnd__SetSTMLText                                      0x765F30
#define CStmlWnd__StripFirstSTMLLines                              0x769B40
#define CStmlWnd__UpdateHistoryString                              0x7640D0

// CTabWnd 
#define CTabWnd__Draw                                              0x76E710
#define CTabWnd__DrawCurrentPage                                   0x76E070
#define CTabWnd__DrawTab                                           0x76DE50
#define CTabWnd__GetCurrentPage                                    0x76E3B0
#define CTabWnd__GetPageClientRect                                 0x76DB00
#define CTabWnd__GetPageFromTabIndex                               0x76DD80
#define CTabWnd__GetPageInnerRect                                  0x76DB60
#define CTabWnd__GetTabInnerRect                                   0x76DD00
#define CTabWnd__GetTabRect                                        0x76DBF0
#define CTabWnd__InsertPage                                        0x76E9A0
#define CTabWnd__SetPage                                           0x76E3F0
#define CTabWnd__SetPageRect                                       0x76E640
#define CTabWnd__UpdatePage                                        0x76E920

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417F40

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x74C940

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x76F5B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x73AE00

// CXRect 
#define CXRect__CenterPoint                                        0x5B3060

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4161E0
#define CXStr__CXStr1                                              0x401410
#define CXStr__CXStr3                                              0x795D10
#define CXStr__dCXStr                                              0x46AA20
#define CXStr__operator_equal1                                     0x795ED0
#define CXStr__operator_plus_equal1                                0x796F60

// CXWnd 
#define CXWnd__BringToTop                                          0x742CA0
#define CXWnd__Center                                              0x747BC0
#define CXWnd__ClrFocus                                            0x742AD0
#define CXWnd__DoAllDrawing                                        0x748540
#define CXWnd__DrawChildren                                        0x748690
#define CXWnd__DrawColoredRect                                     0x742F90
#define CXWnd__DrawTooltip                                         0x747AF0
#define CXWnd__DrawTooltipAtPoint                                  0x746E40
#define CXWnd__GetBorderFrame                                      0x7434D0
#define CXWnd__GetChildWndAt                                       0x7462C0
#define CXWnd__GetClientClipRect                                   0x743250
#define CXWnd__GetScreenClipRect                                   0x747300
#define CXWnd__GetScreenRect                                       0x7435F0
#define CXWnd__GetTooltipRect                                      0x7430A0
#define CXWnd__GetWindowTextA                                      0x5A0D10
#define CXWnd__IsActive                                            0x74DA70
#define CXWnd__IsDescendantOf                                      0x7433C0
#define CXWnd__IsReallyVisible                                     0x7462A0
#define CXWnd__IsType                                              0x7723B0
#define CXWnd__Move                                                0x7459F0
#define CXWnd__Move1                                               0x747850
#define CXWnd__ProcessTransition                                   0x742C50
#define CXWnd__Refade                                              0x742BD0
#define CXWnd__Resize                                              0x7436C0
#define CXWnd__Right                                               0x747210
#define CXWnd__SetFocus                                            0x744E00
#define CXWnd__SetKeyTooltip                                       0x7438B0
#define CXWnd__SetMouseOver                                        0x7475A0
#define CXWnd__StartFade                                           0x742CE0
#define CXWnd__GetChildItem                                        0x747510

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x74F050
#define CXWndManager__DrawWindows                                  0x74ECD0
#define CXWndManager__GetKeyboardFlags                             0x74D6D0
#define CXWndManager__HandleKeyboardMsg                            0x74DD40
#define CXWndManager__RemoveWnd                                    0x74DB90

// CDBStr
#define CDBStr__GetString                                          0x46AAC0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6FB1D0
#define EQ_Character__CastSpell                                    0x42FED0
#define EQ_Character__Cur_HP                                       0x438C30
#define EQ_Character__GetAACastingTimeModifier                     0x425320
#define EQ_Character__GetCharInfo2                                 0x6F9F60
#define EQ_Character__GetFocusCastingTimeModifier                  0x4209D0
#define EQ_Character__GetFocusRangeModifier                        0x420BB0
#define EQ_Character__Max_Endurance                                0x5396D0
#define EQ_Character__Max_HP                                       0x433C00
#define EQ_Character__Max_Mana                                     0x5394D0
#define EQ_Character__doCombatAbility                              0x538340
#define EQ_Character__UseSkill                                     0x4474F0
#define EQ_Character__GetConLevel                                  0x5330F0
#define EQ_Character__TotalEffect                                  0x429550

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5192B0
#define EQ_Item__CreateItemTagString                               0x6E96F0
#define EQ_Item__IsStackable                                       0x6DD9A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4849F0
#define EQ_LoadingS__Array                                         0x909ED8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x53D650
#define EQ_PC__GetAltAbilityIndex                                  0x6EFA00
#define EQ_PC__GetCombatAbility                                    0x6EFA90
#define EQ_PC__GetCombatAbilityTimer                               0x6EFB40
#define EQ_PC__GetItemTimerValue                                   0x538170
#define EQ_PC__HasLoreItem                                         0x6F8AC0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B25D0
#define EQItemList__add_item                                       0x4B2560
#define EQItemList__delete_item                                    0x4B2980
#define EQItemList__FreeItemList                                   0x4B28B0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46A290

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x541FF0
#define EQPlayer__dEQPlayer                                        0x546970
#define EQPlayer__DoAttack                                         0x5575C0
#define EQPlayer__EQPlayer                                         0x54C160
#define EQPlayer__SetNameSpriteState                               0x544400
#define EQPlayer__SetNameSpriteTint                                0x542060
#define EQPlayer__IsBodyType_j                                     0x6FAAA0
#define EQPlayer__IsTargetable                                     0x6FAC70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x54D410
#define EQPlayerManager__GetSpawnByName                            0x54D7B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x51E170
#define KeypressHandler__AttachKeyToEqCommand                      0x51E1B0
#define KeypressHandler__ClearCommandStateArray                    0x51DF80
#define KeypressHandler__HandleKeyDown                             0x51CA10
#define KeypressHandler__HandleKeyUp                               0x51CD20
#define KeypressHandler__SaveKeymapping                            0x51E050

// MapViewMap 
#define MapViewMap__Clear                                          0x63CF00
#define MapViewMap__SaveEx                                         0x63D8D0

#define PlayerPointManager__GetAltCurrency                         0x6EAF30

// StringTable 
#define StringTable__getString                                     0x6DD1B0
