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
#define __ExpectedVersionDate                                     "Jan 10 2012"
#define __ExpectedVersionTime                                     "11:51:57"
#define __ActualVersionDate                                        0x8D9F64
#define __ActualVersionTime                                        0x8D9F70

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x531EF0
#define __MemChecker1                                              0x7E7910
#define __MemChecker2                                              0x5B0F10
#define __MemChecker3                                              0x5B0E60
#define __MemChecker4                                              0x809BD0
#define __EncryptPad0                                              0x9A9AA0
#define __EncryptPad1                                              0xA1E050
#define __EncryptPad2                                              0x9C1AB0
#define __EncryptPad3                                              0x9C16B0
#define __EncryptPad4                                              0xA1FB00
#define __AC1                                                      0x6D9170
#define __AC2                                                      0x4EDE85
#define __AC3                                                      0x500B68
#define __AC4                                                      0x506514
#define __AC5                                                      0x5126EC
#define __AC6                                                      0x515F7E
#define __AC7                                                      0x50E24B
#define __AC1_Data                                                 0x8BFE5D
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
#define __DoAbilityList                                            0xC59478
#define __do_loot                                                  0x4C1C40
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
#define __CastRay                                                  0x4D64B0
#define __ConvertItemTags                                          0x4C74A0
#define __ExecuteCmd                                               0x4B31F0
#define __EQGetTime                                                0x7E8D80
#define __get_melee_range                                          0x4B9320
#define __GetGaugeValueFromEQ                                      0x6D7F20
#define __GetLabelFromEQ                                           0x6D9110
#define __GetXTargetType                                           0x7550E0
#define __LoadFrontEnd                                             0x5AFE80
#define __NewUIINI                                                 0x6D7AD0
#define __ProcessGameEvents                                        0x50EA30
#define CrashDetected                                              0x5AFC80
#define DrawNetStatus                                              0x53F840
#define Util__FastTime                                             0x7E81A0
#define Expansion_HoT                                              0xC23838
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x4865E0
#define AltAdvManager__IsAbilityReady                              0x4866E0
#define AltAdvManager__GetAltAbility                               0x486900

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43AA70

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5CD7B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5D7A30

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x520770

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5EFD40
#define CChatManager__InitContextMenu                              0x5F0670

// CChatService
#define CChatService__GetNumberOfFriends                           0x748EE0
#define CChatService__GetFriendName                                0x748EF0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5F5420
#define CChatWindow__Clear                                         0x5F4FE0
#define CChatWindow__WndNotification                               0x5F5830

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7953E0
#define CComboWnd__Draw                                            0x7955B0
#define CComboWnd__GetCurChoice                                    0x795220
#define CComboWnd__GetListRect                                     0x7958A0
#define CComboWnd__GetTextRect                                     0x795410
#define CComboWnd__InsertChoice                                    0x795910
#define CComboWnd__SetColors                                       0x7951B0
#define CComboWnd__SetChoice                                       0x7951E0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5FEDD0
#define CContainerWnd__vftable                                     0x8E1988

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47A250
#define CDisplay__GetClickedActor                                  0x473260
#define CDisplay__GetUserDefinedColor                              0x471B90
#define CDisplay__GetWorldFilePath                                 0x471040
#define CDisplay__is3dON                                           0x470150
#define CDisplay__ReloadUI                                         0x483370
#define CDisplay__WriteTextHD2                                     0x476140

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5C7770
#define CEditBaseWnd__SetSel                                       0x7B8360

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x79EAB0
#define CEditWnd__GetCharIndexPt                                   0x79FA90
#define CEditWnd__GetDisplayString                                 0x79EC60
#define CEditWnd__GetHorzOffset                                    0x79EEF0
#define CEditWnd__GetLineForPrintableChar                          0x79F540
#define CEditWnd__GetSelStartPt                                    0x79FCE0
#define CEditWnd__GetSTMLSafeText                                  0x79F090
#define CEditWnd__PointFromPrintableChar                           0x79F650
#define CEditWnd__SelectableCharFromPoint                          0x79F7D0
#define CEditWnd__SetEditable                                      0x79F060

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EE5D0
#define CEverQuest__DropHeldItemOnGround                           0x4FB570
#define CEverQuest__dsp_chat                                       0x4F4860
#define CEverQuest__DoTellWindow                                   0x4F2F80
#define CEverQuest__EnterZone                                      0x5064A0
#define CEverQuest__GetBodyTypeDesc                                0x4EB3B0
#define CEverQuest__GetClassDesc                                   0x4EABF0
#define CEverQuest__GetClassThreeLetterCode                        0x4EB1F0
#define CEverQuest__GetDeityDesc                                   0x4EBA60
#define CEverQuest__GetLangDesc                                    0x4EB740
#define CEverQuest__GetRaceDesc                                    0x4EBA30
#define CEverQuest__InterpretCmd                                   0x4F5410
#define CEverQuest__LeftClickedOnPlayer                            0x508570
#define CEverQuest__LMouseUp                                       0x50C0D0
#define CEverQuest__RightClickedOnPlayer                           0x50D230
#define CEverQuest__RMouseUp                                       0x50E210
#define CEverQuest__SetGameState                                   0x4EEA60
#define CEverQuest__Emote                                          0x4F4A80

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x60C3E0
#define CGaugeWnd__CalcLinesFillRect                               0x60C440
#define CGaugeWnd__Draw                                            0x60C890

// CGuild
#define CGuild__FindMemberByName                                   0x41BC10

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x624A10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x630AD0
#define CInvSlotMgr__MoveItem                                      0x631410

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x630160
#define CInvSlot__SliderComplete                                   0x62E590
#define CInvSlot__GetItemBase                                      0x62DC50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x632170

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6D54E0
#define CItemDisplayWnd__UpdateStrings                             0x6331B0

// CLabel 
#define CLabel__Draw                                               0x647740

// CListWnd 
#define CListWnd__AddColumn                                        0x78D6A0
#define CListWnd__AddColumn1                                       0x78CD10
#define CListWnd__AddLine                                          0x78C8C0
#define CListWnd__AddString                                        0x78CA60
#define CListWnd__CalculateFirstVisibleLine                        0x788BC0
#define CListWnd__CalculateVSBRange                                0x78AF30
#define CListWnd__ClearAllSel                                      0x788100
#define CListWnd__CloseAndUpdateEditWindow                         0x78BF20
#define CListWnd__Compare                                          0x789680
#define CListWnd__Draw                                             0x78AB70
#define CListWnd__DrawColumnSeparators                             0x78AA00
#define CListWnd__DrawHeader                                       0x788390
#define CListWnd__DrawItem                                         0x78A080
#define CListWnd__DrawLine                                         0x78A6C0
#define CListWnd__DrawSeparator                                    0x78AAA0
#define CListWnd__EnsureVisible                                    0x788D20
#define CListWnd__ExtendSel                                        0x789FA0
#define CListWnd__GetColumnMinWidth                                0x787DD0
#define CListWnd__GetColumnWidth                                   0x787D10
#define CListWnd__GetCurSel                                        0x787580
#define CListWnd__GetHeaderRect                                    0x7876F0
#define CListWnd__GetItemAtPoint                                   0x789000
#define CListWnd__GetItemAtPoint1                                  0x789070
#define CListWnd__GetItemData                                      0x787910
#define CListWnd__GetItemHeight                                    0x788820
#define CListWnd__GetItemIcon                                      0x787AF0
#define CListWnd__GetItemRect                                      0x788DF0
#define CListWnd__GetItemText                                      0x7879A0
#define CListWnd__GetSelList                                       0x78CBF0
#define CListWnd__GetSeparatorRect                                 0x7895D0
#define CListWnd__RemoveLine                                       0x78D650
#define CListWnd__SetColors                                        0x787650
#define CListWnd__SetColumnJustification                           0x787F70
#define CListWnd__SetColumnWidth                                   0x787D90
#define CListWnd__SetCurSel                                        0x7875C0
#define CListWnd__SetItemColor                                     0x78BBD0
#define CListWnd__SetItemData                                      0x7881A0
#define CListWnd__SetItemText                                      0x78BA10
#define CListWnd__ShiftColumnSeparator                             0x78B880
#define CListWnd__Sort                                             0x78DDE0
#define CListWnd__ToggleSel                                        0x788070

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x65D970

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x673060
#define CMerchantWnd__RequestBuyItem                               0x679380
#define CMerchantWnd__RequestSellItem                              0x69A850
#define CMerchantWnd__SelectBuySellSlot                            0x6732F0

// CObfuscator
#define CObfuscator__doit                                          0x720680

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7A74F0
#define CSidlManager__CreateLabel                                  0x6CDC90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5C9940
#define CSidlScreenWnd__CalculateVSBRange                          0x5C9860
#define CSidlScreenWnd__ConvertToRes                               0x7B8240
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x797A20
#define CSidlScreenWnd__CSidlScreenWnd1                            0x798C00
#define CSidlScreenWnd__CSidlScreenWnd2                            0x798CB0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x798390
#define CSidlScreenWnd__DrawSidlPiece                              0x7974E0
#define CSidlScreenWnd__EnableIniStorage                           0x796C90
#define CSidlScreenWnd__GetSidlPiece                               0x797700
#define CSidlScreenWnd__Init1                                      0x798A50
#define CSidlScreenWnd__LoadIniInfo                                0x797AE0
#define CSidlScreenWnd__LoadIniListWnd                             0x796DE0
#define CSidlScreenWnd__LoadSidlScreen                             0x7985F0
#define CSidlScreenWnd__StoreIniInfo                               0x796890
#define CSidlScreenWnd__StoreIniVis                                0x796C20
#define CSidlScreenWnd__WndNotification                            0x798840
#define CSidlScreenWnd__GetChildItem                               0x796CF0

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x57BEC0
#define CSkillMgr__GetSkillCap                                     0x57BF30

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7C0510
#define CSliderWnd__SetValue                                       0x7C0610
#define CSliderWnd__SetNumTicks                                    0x7C0BC0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6D3270

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7B58A0
#define CStmlWnd__CalculateHSBRange                                0x7ACEC0
#define CStmlWnd__CalculateVSBRange                                0x7ACF50
#define CStmlWnd__CanBreakAtCharacter                              0x7AD0D0
#define CStmlWnd__FastForwardToEndOfTag                            0x7ADDA0
#define CStmlWnd__ForceParseNow                                    0x7B5DD0
#define CStmlWnd__GetNextTagPiece                                  0x7ADCC0
#define CStmlWnd__GetSTMLText                                      0x5F4880
#define CStmlWnd__GetThisChar                                      0x7E0AD0
#define CStmlWnd__GetVisiableText                                  0x7AF220
#define CStmlWnd__InitializeWindowVariables                        0x7B1810
#define CStmlWnd__MakeStmlColorTag                                 0x7ABDE0
#define CStmlWnd__MakeWndNotificationTag                           0x7ABE80
#define CStmlWnd__SetSTMLText                                      0x7B1930
#define CStmlWnd__StripFirstSTMLLines                              0x7B5540
#define CStmlWnd__UpdateHistoryString                              0x7AFAC0

// CTabWnd 
#define CTabWnd__Draw                                              0x7B99C0
#define CTabWnd__DrawCurrentPage                                   0x7B9240
#define CTabWnd__DrawTab                                           0x7B9010
#define CTabWnd__GetCurrentPage                                    0x7B9600
#define CTabWnd__GetPageClientRect                                 0x7B8CC0
#define CTabWnd__GetPageFromTabIndex                               0x7B8F40
#define CTabWnd__GetPageInnerRect                                  0x7B8D20
#define CTabWnd__GetTabInnerRect                                   0x7B8EC0
#define CTabWnd__GetTabRect                                        0x7B8DB0
#define CTabWnd__InsertPage                                        0x7B9C50
#define CTabWnd__SetPage                                           0x7B9640
#define CTabWnd__SetPageRect                                       0x7B98F0
#define CTabWnd__UpdatePage                                        0x7B9BD0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x418050

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x799030

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7BA870

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7864E0

// CXRect 
#define CXRect__CenterPoint                                        0x51F860

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416260
#define CXStr__CXStr1                                              0x77FB30
#define CXStr__CXStr3                                              0x7E50F0
#define CXStr__dCXStr                                              0x4873C0
#define CXStr__operator_equal                                      0x7E5260
#define CXStr__operator_equal1                                     0x7E52B0
#define CXStr__operator_plus_equal1                                0x7E6340

// CXWnd 
#define CXWnd__BringToTop                                          0x78E3E0
#define CXWnd__Center                                              0x793D90
#define CXWnd__ClrFocus                                            0x78E200
#define CXWnd__DoAllDrawing                                        0x793C10
#define CXWnd__DrawChildren                                        0x793D50
#define CXWnd__DrawColoredRect                                     0x78E6F0
#define CXWnd__DrawTooltip                                         0x78E8E0
#define CXWnd__DrawTooltipAtPoint                                  0x792EE0
#define CXWnd__GetBorderFrame                                      0x78ECE0
#define CXWnd__GetChildWndAt                                       0x7920A0
#define CXWnd__GetClientClipRect                                   0x78EA80
#define CXWnd__GetScreenClipRect                                   0x793430
#define CXWnd__GetScreenRect                                       0x78EE10
#define CXWnd__GetTooltipRect                                      0x78E800
#define CXWnd__GetWindowTextA                                      0x51F900
#define CXWnd__IsActive                                            0x79A170
#define CXWnd__IsDescendantOf                                      0x78EBB0
#define CXWnd__IsReallyVisible                                     0x792080
#define CXWnd__IsType                                              0x7BD930
#define CXWnd__Move                                                0x7917B0
#define CXWnd__Move1                                               0x7938D0
#define CXWnd__ProcessTransition                                   0x78E390
#define CXWnd__Refade                                              0x78E310
#define CXWnd__Resize                                              0x78EEE0
#define CXWnd__Right                                               0x793340
#define CXWnd__SetFocus                                            0x7909C0
#define CXWnd__SetKeyTooltip                                       0x78F130
#define CXWnd__SetMouseOver                                        0x7936C0
#define CXWnd__StartFade                                           0x78E420
#define CXWnd__GetChildItem                                        0x793630

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x79B6E0
#define CXWndManager__DrawWindows                                  0x79B360
#define CXWndManager__GetKeyboardFlags                             0x799DC0
#define CXWndManager__HandleKeyboardMsg                            0x79A440
#define CXWndManager__RemoveWnd                                    0x79A290

// CDBStr
#define CDBStr__GetString                                          0x46E950

// EQ_Character 
#define EQ_Character__CastRay                                      0x7363E0
#define EQ_Character__CastSpell                                    0x431660
#define EQ_Character__Cur_HP                                       0x43A710
#define EQ_Character__GetAACastingTimeModifier                     0x4262E0
#define EQ_Character__GetCharInfo2                                 0x7350F0
#define EQ_Character__GetFocusCastingTimeModifier                  0x421820
#define EQ_Character__GetFocusRangeModifier                        0x4219F0
#define EQ_Character__Max_Endurance                                0x549D90
#define EQ_Character__Max_HP                                       0x4354C0
#define EQ_Character__Max_Mana                                     0x549B90
#define EQ_Character__doCombatAbility                              0x548A10
#define EQ_Character__UseSkill                                     0x449C40
#define EQ_Character__GetConLevel                                  0x542070
#define EQ_Character__IsExpansionFlag                              0x40DA00
#define EQ_Character__TotalEffect                                  0x42AAC0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x524DE0
#define EQ_Item__CreateItemTagString                               0x71E6C0
#define EQ_Item__IsStackable                                       0x713940

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x487BE0
#define EQ_LoadingS__Array                                         0x98DAA0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x54D650
#define EQ_PC__GetAltAbilityIndex                                  0x726670
#define EQ_PC__GetCombatAbility                                    0x726700
#define EQ_PC__GetCombatAbilityTimer                               0x7267B0
#define EQ_PC__GetItemTimerValue                                   0x5487D0
#define EQ_PC__HasLoreItem                                         0x547300

// EQItemList 
#define EQItemList__EQItemList                                     0x4B75E0
#define EQItemList__add_item                                       0x4B7570
#define EQItemList__delete_item                                    0x4B7990
#define EQItemList__FreeItemList                                   0x4B78C0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46DEF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x552710
#define EQPlayer__dEQPlayer                                        0x5572E0
#define EQPlayer__DoAttack                                         0x568660
#define EQPlayer__EQPlayer                                         0x55CCD0
#define EQPlayer__SetNameSpriteState                               0x554C20
#define EQPlayer__SetNameSpriteTint                                0x552780
#define EQPlayer__IsBodyType_j                                     0x735C80
#define EQPlayer__IsTargetable                                     0x735F50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x55E060
#define EQPlayerManager__GetSpawnByName                            0x55E2F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52A830
#define KeypressHandler__AttachKeyToEqCommand                      0x52A870
#define KeypressHandler__ClearCommandStateArray                    0x52A640
#define KeypressHandler__HandleKeyDown                             0x529000
#define KeypressHandler__HandleKeyUp                               0x529310
#define KeypressHandler__SaveKeymapping                            0x52A710

// MapViewMap 
#define MapViewMap__Clear                                          0x658EE0
#define MapViewMap__SaveEx                                         0x6598B0

#define PlayerPointManager__GetAltCurrency                         0x720D80

// StringTable 
#define StringTable__getString                                     0x720900

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x54BF20
