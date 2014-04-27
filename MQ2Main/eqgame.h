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
#define __ExpectedVersionDate                                     "Dec 13 2011"
#define __ExpectedVersionTime                                     "18:09:42"
#define __ActualVersionDate                                        0x8D9F7C
#define __ActualVersionTime                                        0x8D9F88

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x531DD0
#define __MemChecker1                                              0x7E7400
#define __MemChecker2                                              0x5B0C90
#define __MemChecker3                                              0x5B0BE0
#define __MemChecker4                                              0x809930
#define __EncryptPad0                                              0x9A9AA0
#define __EncryptPad1                                              0xA1E050
#define __EncryptPad2                                              0x9C1AB0
#define __EncryptPad3                                              0x9C16B0
#define __EncryptPad4                                              0xA1FB00
#define __AC1                                                      0x6D8AF0
#define __AC2                                                      0x4EDD15
#define __AC3                                                      0x500988
#define __AC4                                                      0x506334
#define __AC5                                                      0x51250C
#define __AC6                                                      0x515D9E
#define __AC7                                                      0x50E06B
#define __AC1_Data                                                 0x8BFD4D
// Direct Input
#define DI8__Main                                                  0xC9CC50
#define DI8__Keyboard                                              0xC9CC54
#define DI8__Mouse                                                 0xC9CC58
#define __AltTimerReady                                            0xB652A9
#define __Attack                                                   0xC98A9E
#define __Autofire                                                 0xC98A9F
#define __BindList                                                 0x992C68
#define __Clicks                                                   0xC225AC
#define __CommandList                                              0x994258
#define __CurrentMapLabel                                          0xCC8930
#define __CurrentSocial                                            0x97F48C
//#define __DoAbilityAvailable                                       0x0
#define __DoAbilityList                                            0xC59478
#define __do_loot                                                  0x4C1C20
#define __DrawHandler                                              0x13255CC
#define __GroupCount                                               0xC1316A
#define __Guilds                                                   0xC154F8
#define __gWorld                                                   0xC15424
#define __HotkeyPage                                               0xC82054
#define __HWnd                                                     0xC9C9A0
#define __InChatMode                                               0xC224E4
#define __LastTell                                                 0xC24390
#define __LMouseHeldTime                                           0xC22618
#define __Mouse                                                    0xC9CC5C
#define __MouseLook                                                0xC2257A
#define __MouseEventTime                                           0xC98D84
#define __NetStatusToggle                                          0xC2257D
#define __PCNames                                                  0xC23A34
#define __RangeAttackReady                                         0xC236CC
#define __RMouseHeldTime                                           0xC22614
#define __RunWalkState                                             0xC224E8
#define __ScreenMode                                               0xB62608
#define __ScreenX                                                  0xC22498
#define __ScreenY                                                  0xC2249C
#define __ScreenXMax                                               0xC224A0
#define __ScreenYMax                                               0xC224A4
#define __ServerHost                                               0xC130AC
#define __ServerName                                               0xC59438
#define __ShiftKeyDown                                             0xC22B64
#define __ShowNames                                                0xC238D8
#define __Socials                                                  0xC59538


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xC1EE10
#define instEQZoneInfo                                             0xC22760
#define instKeypressHandler                                        0xC98D80
#define pinstActiveBanker                                          0xC154CC
#define pinstActiveCorpse                                          0xC154D0
#define pinstActiveGMaster                                         0xC154D4
#define pinstActiveMerchant                                        0xC154C8
#define pinstAltAdvManager                                         0xB63538
#define pinstAuraMgr                                               0xA32790
#define pinstBandageTarget                                         0xC154B4
#define pinstCamActor                                              0xB62FB0
#define pinstCDBStr                                                0xB625E0
#define pinstCDisplay                                              0xC154DC
#define pinstCEverQuest                                            0xC9CDD8
#define pinstCharData                                              0xC15498
#define pinstCharSpawn                                             0xC154C0
#define pinstControlledMissile                                     0xC15494
#define pinstControlledPlayer                                      0xC154C0
#define pinstCSidlManager                                          0x1325A9C
#define pinstCXWndManager                                          0x1325A94
#define instDynamicZone                                            0xC1E868
#define pinstDZMember                                              0xC1E978
#define pinstDZTimerInfo                                           0xC1E97C
#define pinstEQItemList                                            0xC12210
#define instEQMisc                                                 0xB62548
#define pinstEQSoundManager                                        0xB635A8
#define instExpeditionLeader                                       0xC1E8B2
#define instExpeditionName                                         0xC1E8F2
#define pinstGroup                                                 0xC13166
#define pinstImeManager                                            0x1325AA0
#define pinstLocalPlayer                                           0xC154AC
#define pinstMercenaryData                                         0xC99200
#define pinstModelPlayer                                           0xC154D8
#define pinstPCData                                                0xC15498
#define pinstSkillMgr                                              0xC99818
#define pinstSpawnManager                                          0xC994A0
#define pinstSpellManager                                          0xC99858
#define pinstSpellSets                                             0xC91DAC
#define pinstStringTable                                           0xC15440
#define pinstSwitchManager                                         0xC12D78
#define pinstTarget                                                0xC154C4
#define pinstTargetObject                                          0xC1549C
#define pinstTargetSwitch                                          0xC154A0
#define pinstTaskMember                                            0xB62510
#define pinstTrackTarget                                           0xC154B8
#define pinstTradeTarget                                           0xC154A8
#define instTributeActive                                          0xB6256D
#define pinstViewActor                                             0xB62FAC
#define pinstWorldData                                             0xC1547C


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0xA2FEF0
#define pinstCAudioTriggersWindow                                  0xA2FE88
#define pinstCCharacterSelect                                      0xB62E78
#define pinstCFacePick                                             0xB62E28
#define pinstCNoteWnd                                              0xB62E30
#define pinstCBookWnd                                              0xB62E34
#define pinstCPetInfoWnd                                           0xB62E38
#define pinstCTrainWnd                                             0xB62E3C
#define pinstCSkillsWnd                                            0xB62E40
#define pinstCSkillsSelectWnd                                      0xB62E44
#define pinstCCombatSkillSelectWnd                                 0xB62E48
#define pinstCFriendsWnd                                           0xB62E4C
#define pinstCAuraWnd                                              0xB62E50
#define pinstCRespawnWnd                                           0xB62E54
#define pinstCBandolierWnd                                         0xB62E58
#define pinstCPotionBeltWnd                                        0xB62E5C
#define pinstCAAWnd                                                0xB62E60
#define pinstCGroupSearchFiltersWnd                                0xB62E64
#define pinstCLoadskinWnd                                          0xB62E68
#define pinstCAlarmWnd                                             0xB62E6C
#define pinstCMusicPlayerWnd                                       0xB62E70
#define pinstCMailWnd                                              0xB62E7C
#define pinstCMailCompositionWnd                                   0xB62E80
#define pinstCMailAddressBookWnd                                   0xB62E84
#define pinstCRaidWnd                                              0xB62E8C
#define pinstCRaidOptionsWnd                                       0xB62E90
#define pinstCBreathWnd                                            0xB62E94
#define pinstCMapViewWnd                                           0xB62E98
#define pinstCMapToolbarWnd                                        0xB62E9C
#define pinstCEditLabelWnd                                         0xB62EA0
#define pinstCTargetWnd                                            0xB62EA4
#define pinstCColorPickerWnd                                       0xB62EA8
#define pinstCPlayerWnd                                            0xB62EAC
#define pinstCOptionsWnd                                           0xB62EB0
#define pinstCBuffWindowNORMAL                                     0xB62EB4
#define pinstCBuffWindowSHORT                                      0xB62EB8
#define pinstCharacterCreation                                     0xB62EBC
#define pinstCCursorAttachment                                     0xB62EC0
#define pinstCCastingWnd                                           0xB62EC4
#define pinstCCastSpellWnd                                         0xB62EC8
#define pinstCSpellBookWnd                                         0xB62ECC
#define pinstCInventoryWnd                                         0xB62ED0
#define pinstCBankWnd                                              0xB62ED4
#define pinstCQuantityWnd                                          0xB62ED8
#define pinstCLootWnd                                              0xB62EDC
#define pinstCActionsWnd                                           0xB62EE0
#define pinstCCombatAbilityWnd                                     0xB62EE4
#define pinstCMerchantWnd                                          0xB62EE8
#define pinstCTradeWnd                                             0xB62EEC
#define pinstCSelectorWnd                                          0xB62EF0
#define pinstCBazaarWnd                                            0xB62EF4
#define pinstCBazaarSearchWnd                                      0xB62EF8
#define pinstCGiveWnd                                              0xB62F14
#define pinstCTrackingWnd                                          0xB62F1C
#define pinstCInspectWnd                                           0xB62F20
#define pinstCSocialEditWnd                                        0xB62F24
#define pinstCFeedbackWnd                                          0xB62F28
#define pinstCBugReportWnd                                         0xB62F2C
#define pinstCVideoModesWnd                                        0xB62F30
#define pinstCTextEntryWnd                                         0xB62F38
#define pinstCFileSelectionWnd                                     0xB62F3C
#define pinstCCompassWnd                                           0xB62F40
#define pinstCPlayerNotesWnd                                       0xB62F44
#define pinstCGemsGameWnd                                          0xB62F48
#define pinstCTimeLeftWnd                                          0xB62F4C
#define pinstCPetitionQWnd                                         0xB62F60
#define pinstCSoulmarkWnd                                          0xB62F64
#define pinstCStoryWnd                                             0xB62F68
#define pinstCJournalTextWnd                                       0xB62F6C
#define pinstCJournalCatWnd                                        0xB62F70
#define pinstCBodyTintWnd                                          0xB62F74
#define pinstCServerListWnd                                        0xB62F78
#define pinstCAvaZoneWnd                                           0xB62F80
#define pinstCBlockedBuffWnd                                       0xB62F84
#define pinstCBlockedPetBuffWnd                                    0xB62F88
#define pinstCInvSlotMgr                                           0xB62FA4
#define pinstCContainerMgr                                         0xB62FA8
#define pinstCAdventureLeaderboardWnd                              0xCC5500
#define pinstCAdventureRequestWnd                                  0xCC54C8
#define pinstCAltStorageWnd                                        0xCC5578
#define pinstCAdventureStatsWnd                                    0xCC5500
#define pinstCBarterMerchantWnd                                    0xCC59D0
#define pinstCBarterSearchWnd                                      0xCC5A08
#define pinstCBarterWnd                                            0xCC5A40
#define pinstCChatManager                                          0xCC5E38
#define pinstCDynamicZoneWnd                                       0xCC6028
#define pinstCEQMainWnd                                            0xCC60E8
#define pinstCFellowshipWnd                                        0xCC61B0
#define pinstCFindLocationWnd                                      0xCC6218
#define pinstCGroupSearchWnd                                       0xCC6378
#define pinstCGroupWnd                                             0xCC63B0
#define pinstCGuildBankWnd                                         0xCC63E8
#define pinstCGuildMgmtWnd                                         0xCC8458
#define pinstCGuildTributeMasterWnd                                0xCCA078
#define pinstCHotButtonWnd                                         0xCC84AC
#define pinstCHotButtonWnd1                                        0xCC84AC
#define pinstCHotButtonWnd2                                        0xCC84B0
#define pinstCHotButtonWnd3                                        0xCC84B4
#define pinstCHotButtonWnd4                                        0xCC850C
#define pinstCItemDisplayManager                                   0xCC8628
#define pinstCItemExpTransferWnd                                   0xCC8664
#define pinstCLeadershipWnd                                        0xCC8790
#define pinstCLFGuildWnd                                           0xCC87C8
#define pinstCMIZoneSelectWnd                                      0xCC8A60
#define pinstCAdventureMerchantWnd                                 0xCC8D10
#define pinstCConfirmationDialog                                   0xCC8D48
#define pinstCPopupWndManager                                      0xCC8D48
#define pinstCProgressionSelectionWnd                              0xCC8DB0
#define pinstCPvPLeaderboardWnd                                    0xCC8DE8
#define pinstCPvPStatsWnd                                          0xCC8E20
#define pinstCSystemInfoDialogBox                                  0xCC9108
#define pinstCTargetOfTargetWnd                                    0xCC9D28
#define pinstCTaskSelectWnd                                        0xCC9D90
#define pinstCTaskTemplateSelectWnd                                0xCC9DC8
#define pinstCTaskWnd                                              0xCC9E00
#define pinstCTipWndOFDAY                                          0xCC9EF8
#define pinstCTipWndCONTEXT                                        0xCC9EFC
#define pinstCTitleWnd                                             0xCC9F30
#define pinstCTradeskillWnd                                        0xCC9FA8
#define pinstCTributeBenefitWnd                                    0xCCA040
#define pinstCTributeMasterWnd                                     0xCCA078
#define pinstCContextMenuManager                                   0x1325AF8
#define pinstCVoiceMacroWnd                                        0xC99BA0
#define pinstCHtmlWnd                                              0xC99C18


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D6480
#define __ConvertItemTags                                          0x4C7480
#define __ExecuteCmd                                               0x4B3200
#define __EQGetTime                                                0x7E8870
#define __get_melee_range                                          0x4B9300
#define __GetGaugeValueFromEQ                                      0x6D78A0
#define __GetLabelFromEQ                                           0x6D8A90
#define __GetXTargetType                                           0x754CD0
#define __LoadFrontEnd                                             0x5AFC00
#define __NewUIINI                                                 0x6D7440
#define __ProcessGameEvents                                        0x50E850
#define CrashDetected                                              0x5AFA00
#define DrawNetStatus                                              0x53F630
#define Util__FastTime                                             0x7E7C90
#define Expansion_HoT                                              0xC23838
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x4864F0
#define AltAdvManager__IsAbilityReady                              0x4865D0
#define AltAdvManager__GetAltAbility                               0x486830

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43ABB0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5CD4C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5D76C0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x520570

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5EF940
#define CChatManager__InitContextMenu                              0x5F0270

// CChatService
#define CChatService__GetNumberOfFriends                           0x7488D0
#define CChatService__GetFriendName                                0x7488E0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5F5020
#define CChatWindow__Clear                                         0x5F4BE0
#define CChatWindow__WndNotification                               0x5F5430

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x795380
#define CComboWnd__Draw                                            0x795550
#define CComboWnd__GetCurChoice                                    0x7951C0
#define CComboWnd__GetListRect                                     0x795840
#define CComboWnd__GetTextRect                                     0x7953B0
#define CComboWnd__InsertChoice                                    0x7958B0
#define CComboWnd__SetColors                                       0x795150
#define CComboWnd__SetChoice                                       0x795180

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5FE880
#define CContainerWnd__vftable                                     0x8E19A8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47A1F0
#define CDisplay__GetClickedActor                                  0x473130
#define CDisplay__GetUserDefinedColor                              0x471A60
#define CDisplay__GetWorldFilePath                                 0x470F10
#define CDisplay__is3dON                                           0x470020
#define CDisplay__ReloadUI                                         0x483310
#define CDisplay__WriteTextHD2                                     0x4760E0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5C7480
#define CEditBaseWnd__SetSel                                       0x7B81E0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x79EA30
#define CEditWnd__GetCharIndexPt                                   0x79FA10
#define CEditWnd__GetDisplayString                                 0x79EBE0
#define CEditWnd__GetHorzOffset                                    0x79EE70
#define CEditWnd__GetLineForPrintableChar                          0x79F4C0
#define CEditWnd__GetSelStartPt                                    0x79FC60
#define CEditWnd__GetSTMLSafeText                                  0x79F010
#define CEditWnd__PointFromPrintableChar                           0x79F5D0
#define CEditWnd__SelectableCharFromPoint                          0x79F750
#define CEditWnd__SetEditable                                      0x79EFE0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EE460
#define CEverQuest__DropHeldItemOnGround                           0x4FB390
#define CEverQuest__dsp_chat                                       0x4F4680
#define CEverQuest__DoTellWindow                                   0x4F2DF0
#define CEverQuest__EnterZone                                      0x5062C0
#define CEverQuest__GetBodyTypeDesc                                0x4EB240
#define CEverQuest__GetClassDesc                                   0x4EAA80
#define CEverQuest__GetClassThreeLetterCode                        0x4EB080
#define CEverQuest__GetDeityDesc                                   0x4EB8F0
#define CEverQuest__GetLangDesc                                    0x4EB5D0
#define CEverQuest__GetRaceDesc                                    0x4EB8C0
#define CEverQuest__InterpretCmd                                   0x4F5230
#define CEverQuest__LeftClickedOnPlayer                            0x508390
#define CEverQuest__LMouseUp                                       0x50BEF0
#define CEverQuest__RightClickedOnPlayer                           0x50D050
#define CEverQuest__RMouseUp                                       0x50E030
#define CEverQuest__SetGameState                                   0x4EE8F0
#define CEverQuest__Emote                                          0x4F48A0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x60C030
#define CGaugeWnd__CalcLinesFillRect                               0x60C090
#define CGaugeWnd__Draw                                            0x60C4E0

// CGuild
#define CGuild__FindMemberByName                                   0x41BC00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x624690

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x6306F0
#define CInvSlotMgr__MoveItem                                      0x631030

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x62FD80
#define CInvSlot__SliderComplete                                   0x62E1B0
#define CInvSlot__GetItemBase                                      0x62D870

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x631D90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6D4E40
#define CItemDisplayWnd__UpdateStrings                             0x632DD0

// CLabel 
#define CLabel__Draw                                               0x647380

// CListWnd 
#define CListWnd__AddColumn                                        0x78D640
#define CListWnd__AddColumn1                                       0x78CD00
#define CListWnd__AddLine                                          0x78C860
#define CListWnd__AddString                                        0x78CA00
#define CListWnd__CalculateFirstVisibleLine                        0x788B60
#define CListWnd__CalculateVSBRange                                0x78AED0
#define CListWnd__ClearAllSel                                      0x7880A0
#define CListWnd__CloseAndUpdateEditWindow                         0x78BEC0
#define CListWnd__Compare                                          0x789620
#define CListWnd__Draw                                             0x78AB10
#define CListWnd__DrawColumnSeparators                             0x78A9A0
#define CListWnd__DrawHeader                                       0x788330
#define CListWnd__DrawItem                                         0x78A020
#define CListWnd__DrawLine                                         0x78A660
#define CListWnd__DrawSeparator                                    0x78AA40
#define CListWnd__EnsureVisible                                    0x788CC0
#define CListWnd__ExtendSel                                        0x789F40
#define CListWnd__GetColumnMinWidth                                0x787D70
#define CListWnd__GetColumnWidth                                   0x787CB0
#define CListWnd__GetCurSel                                        0x787520
#define CListWnd__GetHeaderRect                                    0x787690
#define CListWnd__GetItemAtPoint                                   0x788FA0
#define CListWnd__GetItemAtPoint1                                  0x789010
#define CListWnd__GetItemData                                      0x7878B0
#define CListWnd__GetItemHeight                                    0x7887C0
#define CListWnd__GetItemIcon                                      0x787A90
#define CListWnd__GetItemRect                                      0x788D90
#define CListWnd__GetItemText                                      0x787940
#define CListWnd__GetSelList                                       0x78CBE0
#define CListWnd__GetSeparatorRect                                 0x789570
#define CListWnd__RemoveLine                                       0x78CB90
#define CListWnd__SetColors                                        0x7875F0
#define CListWnd__SetColumnJustification                           0x787F10
#define CListWnd__SetColumnWidth                                   0x787D30
#define CListWnd__SetCurSel                                        0x787560
#define CListWnd__SetItemColor                                     0x78BB70
#define CListWnd__SetItemData                                      0x788140
#define CListWnd__SetItemText                                      0x78B9B0
#define CListWnd__ShiftColumnSeparator                             0x78B820
#define CListWnd__Sort                                             0x78DD80
#define CListWnd__ToggleSel                                        0x788010

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x65D5F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x672AD0
#define CMerchantWnd__RequestBuyItem                               0x678DC0
#define CMerchantWnd__RequestSellItem                              0x69A210
#define CMerchantWnd__SelectBuySellSlot                            0x672D60

// CObfuscator
#define CObfuscator__doit                                          0x720260

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7A74F0
#define CSidlManager__CreateLabel                                  0x6CD680

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5C9650
#define CSidlScreenWnd__CalculateVSBRange                          0x5C9570
#define CSidlScreenWnd__ConvertToRes                               0x7B80C0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7979B0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x798B80
#define CSidlScreenWnd__CSidlScreenWnd2                            0x798C30
#define CSidlScreenWnd__dCSidlScreenWnd                            0x798320
#define CSidlScreenWnd__DrawSidlPiece                              0x797480
#define CSidlScreenWnd__EnableIniStorage                           0x796C30
#define CSidlScreenWnd__GetSidlPiece                               0x797690
#define CSidlScreenWnd__Init1                                      0x7989D0
#define CSidlScreenWnd__LoadIniInfo                                0x797A70
#define CSidlScreenWnd__LoadIniListWnd                             0x796D80
#define CSidlScreenWnd__LoadSidlScreen                             0x798580
#define CSidlScreenWnd__StoreIniInfo                               0x796830
#define CSidlScreenWnd__StoreIniVis                                0x796BC0
#define CSidlScreenWnd__WndNotification                            0x7987C0
#define CSidlScreenWnd__GetChildItem                               0x796C90

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x57BCB0
#define CSkillMgr__GetSkillCap                                     0x57BD20

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7C0230
#define CSliderWnd__SetValue                                       0x7C0330
#define CSliderWnd__SetNumTicks                                    0x7C08E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6D2BD0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7B5720
#define CStmlWnd__CalculateHSBRange                                0x7ACD30
#define CStmlWnd__CalculateVSBRange                                0x7ACDC0
#define CStmlWnd__CanBreakAtCharacter                              0x7ACF40
#define CStmlWnd__FastForwardToEndOfTag                            0x7ADC20
#define CStmlWnd__ForceParseNow                                    0x7B5C50
#define CStmlWnd__GetNextTagPiece                                  0x7ADB40
#define CStmlWnd__GetSTMLText                                      0x5F4480
#define CStmlWnd__GetThisChar                                      0x7E05C0
#define CStmlWnd__GetVisiableText                                  0x7AF0A0
#define CStmlWnd__InitializeWindowVariables                        0x7B1690
#define CStmlWnd__MakeStmlColorTag                                 0x7ABC50
#define CStmlWnd__MakeWndNotificationTag                           0x7ABCF0
#define CStmlWnd__SetSTMLText                                      0x7B17B0
#define CStmlWnd__StripFirstSTMLLines                              0x7B53C0
#define CStmlWnd__UpdateHistoryString                              0x7AF940

// CTabWnd 
#define CTabWnd__Draw                                              0x7B9750
#define CTabWnd__DrawCurrentPage                                   0x7B8FD0
#define CTabWnd__DrawTab                                           0x7B8DA0
#define CTabWnd__GetCurrentPage                                    0x7B9390
#define CTabWnd__GetPageClientRect                                 0x7B8A50
#define CTabWnd__GetPageFromTabIndex                               0x7B8CD0
#define CTabWnd__GetPageInnerRect                                  0x7B8AB0
#define CTabWnd__GetTabInnerRect                                   0x7B8C50
#define CTabWnd__GetTabRect                                        0x7B8B40
#define CTabWnd__InsertPage                                        0x7B99E0
#define CTabWnd__SetPage                                           0x7B93D0
#define CTabWnd__SetPageRect                                       0x7B9680
#define CTabWnd__UpdatePage                                        0x7B9960

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x418080

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x798FB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7BA5F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x786480

// CXRect 
#define CXRect__CenterPoint                                        0x51F660

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416130
#define CXStr__CXStr1                                              0x77FAD0
#define CXStr__CXStr3                                              0x7E4BE0
#define CXStr__dCXStr                                              0x4627D0
#define CXStr__operator_equal                                      0x7E4D50
#define CXStr__operator_equal1                                     0x7E4DA0
#define CXStr__operator_plus_equal1                                0x7E5E30

// CXWnd 
#define CXWnd__BringToTop                                          0x78E380
#define CXWnd__Center                                              0x793D30
#define CXWnd__ClrFocus                                            0x78E1A0
#define CXWnd__DoAllDrawing                                        0x793BB0
#define CXWnd__DrawChildren                                        0x793CF0
#define CXWnd__DrawColoredRect                                     0x78E690
#define CXWnd__DrawTooltip                                         0x78E880
#define CXWnd__DrawTooltipAtPoint                                  0x792E30
#define CXWnd__GetBorderFrame                                      0x78EC80
#define CXWnd__GetChildWndAt                                       0x791FF0
#define CXWnd__GetClientClipRect                                   0x78EA20
#define CXWnd__GetScreenClipRect                                   0x793380
#define CXWnd__GetScreenRect                                       0x78EDB0
#define CXWnd__GetTooltipRect                                      0x78E7A0
#define CXWnd__GetWindowTextA                                      0x51F700
#define CXWnd__IsActive                                            0x79A0F0
#define CXWnd__IsDescendantOf                                      0x78EB50
#define CXWnd__IsReallyVisible                                     0x791FD0
#define CXWnd__IsType                                              0x7BD780
#define CXWnd__Move                                                0x791700
#define CXWnd__Move1                                               0x793870
#define CXWnd__ProcessTransition                                   0x78E330
#define CXWnd__Refade                                              0x78E2B0
#define CXWnd__Resize                                              0x78EE80
#define CXWnd__Right                                               0x793290
#define CXWnd__SetFocus                                            0x790910
#define CXWnd__SetKeyTooltip                                       0x78F0D0
#define CXWnd__SetMouseOver                                        0x793660
#define CXWnd__StartFade                                           0x78E3C0
#define CXWnd__GetChildItem                                        0x7935D0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x79B660
#define CXWndManager__DrawWindows                                  0x79B2E0
#define CXWndManager__GetKeyboardFlags                             0x799D40
#define CXWndManager__HandleKeyboardMsg                            0x79A3C0
#define CXWndManager__RemoveWnd                                    0x79A210

// CDBStr
#define CDBStr__GetString                                          0x46E880

// EQ_Character 
#define EQ_Character__CastRay                                      0x735EF0
#define EQ_Character__CastSpell                                    0x431790
#define EQ_Character__Cur_HP                                       0x43A850
#define EQ_Character__GetAACastingTimeModifier                     0x426410
#define EQ_Character__GetCharInfo2                                 0x734BF0
#define EQ_Character__GetFocusCastingTimeModifier                  0x421940
#define EQ_Character__GetFocusRangeModifier                        0x421B10
#define EQ_Character__Max_Endurance                                0x549B30
#define EQ_Character__Max_HP                                       0x435600
#define EQ_Character__Max_Mana                                     0x549930
#define EQ_Character__doCombatAbility                              0x5487B0
#define EQ_Character__UseSkill                                     0x449D80
#define EQ_Character__GetConLevel                                  0x541E80
#define EQ_Character__IsExpansionFlag                              0x40D900
#define EQ_Character__TotalEffect                                  0x42ABF0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x524C60
#define EQ_Item__CreateItemTagString                               0x71E370
#define EQ_Item__IsStackable                                       0x7135E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x487AF0
#define EQ_LoadingS__Array                                         0x98DAA0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x54D3F0
#define EQ_PC__GetAltAbilityIndex                                  0x726170
#define EQ_PC__GetCombatAbility                                    0x726200
#define EQ_PC__GetCombatAbilityTimer                               0x7262B0
#define EQ_PC__GetItemTimerValue                                   0x548570
#define EQ_PC__HasLoreItem                                         0x5470A0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B75F0
#define EQItemList__add_item                                       0x4B7580
#define EQItemList__delete_item                                    0x4B79A0
#define EQItemList__FreeItemList                                   0x4B78D0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46DE20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5524F0
#define EQPlayer__dEQPlayer                                        0x557070
#define EQPlayer__DoAttack                                         0x5683B0
#define EQPlayer__EQPlayer                                         0x55CA60
#define EQPlayer__SetNameSpriteState                               0x5549B0
#define EQPlayer__SetNameSpriteTint                                0x552560
#define EQPlayer__IsBodyType_j                                     0x735790
#define EQPlayer__IsTargetable                                     0x735A60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x55DDF0
#define EQPlayerManager__GetSpawnByName                            0x55E080

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52A710
#define KeypressHandler__AttachKeyToEqCommand                      0x52A750
#define KeypressHandler__ClearCommandStateArray                    0x52A520
#define KeypressHandler__HandleKeyDown                             0x528EE0
#define KeypressHandler__HandleKeyUp                               0x5291F0
#define KeypressHandler__SaveKeymapping                            0x52A5F0

// MapViewMap 
#define MapViewMap__Clear                                          0x658B60
#define MapViewMap__SaveEx                                         0x659530

#define PlayerPointManager__GetAltCurrency                         0x720960

// StringTable 
#define StringTable__getString                                     0x7204E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x54BCC0