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
#define __ExpectedVersionDate                                     "Jul 19 2011"
#define __ExpectedVersionTime                                     "11:05:29"
#define __ActualVersionDate                                        0x8ADE44
#define __ActualVersionTime                                        0x8ADE50

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x528910
#define __MemChecker1                                              0x7BEE00
#define __MemChecker2                                              0x5A10D0
#define __MemChecker3                                              0x5A1020
#define __MemChecker4                                              0x7E0F10
#define __EncryptPad0                                              0x94FB50
#define __EncryptPad1                                              0x95BDB0
#define __EncryptPad2                                              0x9528E8
#define __EncryptPad3                                              0x9524E8
#define __EncryptPad4                                              0x95D858
#define __AC1                                                      0x6BD820
#define __AC2                                                      0x4EA5F5
#define __AC3                                                      0x4FCE08
#define __AC4                                                      0x502644
#define __AC5                                                      0x50E93C
#define __AC6                                                      0x51209E
#define __AC7                                                      0x50A59B
#define __AC1_Data                                                 0x8951AD
// Direct Input
#define DI8__Main                                                  0xBC03BC
#define DI8__Keyboard                                              0xBC03C0
#define DI8__Mouse                                                 0xBC03C4
#define __AltTimerReady                                            0xB587A6
#define __Attack                                                   0xBBC2C2
#define __Autofire                                                 0xBBC2C3
#define __BindList                                                 0x94A0A8
#define __Clicks                                                   0xB57450
#define __CommandList                                              0x94AA98
#define __CurrentMapLabel                                          0xBEC0C8
#define __CurrentSocial                                            0x9459D8
#define __DoAbilityAvailable                                       0xB58740
#define __DoAbilityList                                            0xB8E1E0
#define __do_loot                                                  0x4BF2B0
#define __DrawHandler                                              0x1246AA4
#define __GroupCount                                               0xB50E22
#define __Guilds                                                   0xB531B0
#define __gWorld                                                   0xB530DC
#define __HotkeyPage                                               0xBB55CC
#define __HWnd                                                     0xBC00F8
#define __InChatMode                                               0xB57388
#define __LastTell                                                 0xB590F8
#define __LMouseHeldTime                                           0xB574BC
#define __Mouse                                                    0xBC03C8
#define __MouseLook                                                0xB5741E
#define __MouseEventTime                                           0xBBC574
#define __NetStatusToggle                                          0xB57421
#define __PCNames                                                  0xB58B3C
#define __RangeAttackReady                                         0xB587A4
#define __RMouseHeldTime                                           0xB574B8
#define __RunWalkState                                             0xB5738C
#define __ScreenMode                                               0xAA0358
#define __ScreenX                                                  0xB57340
#define __ScreenY                                                  0xB57344
#define __ScreenXMax                                               0xB57348
#define __ScreenYMax                                               0xB5734C
#define __ServerHost                                               0xB50D64
#define __ServerName                                               0xB8E1A0
#define __ShiftKeyDown                                             0xB57A4C
#define __ShowNames                                                0xB589E0
#define __Socials                                                  0xB8E2A0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xB53CB8
#define instEQZoneInfo                                             0xB57608
#define instKeypressHandler                                        0xBBC570
#define pinstActiveBanker                                          0xB53184
#define pinstActiveCorpse                                          0xB53188
#define pinstActiveGMaster                                         0xB5318C
#define pinstActiveMerchant                                        0xB53180
#define pinstAltAdvManager                                         0xAA1280
#define pinstAuraMgr                                               0x9704F0
#define pinstBandageTarget                                         0xB5316C
#define pinstCamActor                                              0xAA0CF8
#define pinstCDBStr                                                0xAA0330
#define pinstCDisplay                                              0xB53194
#define pinstCEverQuest                                            0xBC0540
#define pinstCharData                                              0xB53150
#define pinstCharSpawn                                             0xB53178
#define pinstControlledMissile                                     0xB5314C
#define pinstControlledPlayer                                      0xB53178
#define pinstCSidlManager                                          0x1246F74
#define pinstCXWndManager                                          0x1246F6C
#define instDynamicZone                                            0xB53710
#define pinstDZMember                                              0xB53820
#define pinstDZTimerInfo                                           0xB53824
#define pinstEQItemList                                            0xB4FEC8
#define instEQMisc                                                 0xAA02A8
#define pinstEQSoundManager                                        0xAA12F0
#define instExpeditionLeader                                       0xB5375A
#define instExpeditionName                                         0xB5379A
#define pinstGroup                                                 0xB50E1E
#define pinstImeManager                                            0x1246F78
#define pinstLocalPlayer                                           0xB53164
#define pinstMercenaryData                                         0xBBC9D8
#define pinstModelPlayer                                           0xB53190
#define pinstPCData                                                0xB53150
#define pinstSkillMgr                                              0xBBCFA0
#define pinstSpawnManager                                          0xBBCC38
#define pinstSpellManager                                          0xBBCFE0
#define pinstSpellSets                                             0xBB55D0
#define pinstStringTable                                           0xB530F8
#define pinstSwitchManager                                         0xB50A30
#define pinstTarget                                                0xB5317C
#define pinstTargetObject                                          0xB53154
#define pinstTargetSwitch                                          0xB53158
#define pinstTaskMember                                            0xAA0270
#define pinstTrackTarget                                           0xB53170
#define pinstTradeTarget                                           0xB53160
#define instTributeActive                                          0xAA02CD
#define pinstViewActor                                             0xAA0CF4
#define pinstWorldData                                             0xB53134


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x96DC50
#define pinstCAudioTriggersWindow                                  0x96DBE8
#define pinstCCharacterSelect                                      0xAA0BC8
#define pinstCFacePick                                             0xAA0B78
#define pinstCNoteWnd                                              0xAA0B80
#define pinstCBookWnd                                              0xAA0B84
#define pinstCPetInfoWnd                                           0xAA0B88
#define pinstCTrainWnd                                             0xAA0B8C
#define pinstCSkillsWnd                                            0xAA0B90
#define pinstCSkillsSelectWnd                                      0xAA0B94
#define pinstCCombatSkillSelectWnd                                 0xAA0B98
#define pinstCFriendsWnd                                           0xAA0B9C
#define pinstCAuraWnd                                              0xAA0BA0
#define pinstCRespawnWnd                                           0xAA0BA4
#define pinstCBandolierWnd                                         0xAA0BA8
#define pinstCPotionBeltWnd                                        0xAA0BAC
#define pinstCAAWnd                                                0xAA0BB0
#define pinstCGroupSearchFiltersWnd                                0xAA0BB4
#define pinstCLoadskinWnd                                          0xAA0BB8
#define pinstCAlarmWnd                                             0xAA0BBC
#define pinstCMusicPlayerWnd                                       0xAA0BC0
#define pinstCMailWnd                                              0xAA0BCC
#define pinstCMailCompositionWnd                                   0xAA0BD0
#define pinstCMailAddressBookWnd                                   0xAA0BD4
#define pinstCRaidWnd                                              0xAA0BDC
#define pinstCRaidOptionsWnd                                       0xAA0BE0
#define pinstCBreathWnd                                            0xAA0BE4
#define pinstCMapViewWnd                                           0xAA0BE8
#define pinstCMapToolbarWnd                                        0xAA0BEC
#define pinstCEditLabelWnd                                         0xAA0BF0
#define pinstCTargetWnd                                            0xAA0BF4
#define pinstCColorPickerWnd                                       0xAA0BF8
#define pinstCPlayerWnd                                            0xAA0BFC
#define pinstCOptionsWnd                                           0xAA0C00
#define pinstCBuffWindowNORMAL                                     0xAA0C04
#define pinstCBuffWindowSHORT                                      0xAA0C08
#define pinstCharacterCreation                                     0xAA0C0C
#define pinstCCursorAttachment                                     0xAA0C10
#define pinstCCastingWnd                                           0xAA0C14
#define pinstCCastSpellWnd                                         0xAA0C18
#define pinstCSpellBookWnd                                         0xAA0C1C
#define pinstCInventoryWnd                                         0xAA0C20
#define pinstCBankWnd                                              0xAA0C24
#define pinstCQuantityWnd                                          0xAA0C28
#define pinstCLootWnd                                              0xAA0C2C
#define pinstCActionsWnd                                           0xAA0C30
#define pinstCCombatAbilityWnd                                     0xAA0C34
#define pinstCMerchantWnd                                          0xAA0C38
#define pinstCTradeWnd                                             0xAA0C3C
#define pinstCSelectorWnd                                          0xAA0C40
#define pinstCBazaarWnd                                            0xAA0C44
#define pinstCBazaarSearchWnd                                      0xAA0C48
#define pinstCGiveWnd                                              0xAA0C64
#define pinstCTrackingWnd                                          0xAA0C68
#define pinstCInspectWnd                                           0xAA0C6C
#define pinstCSocialEditWnd                                        0xAA0C70
#define pinstCFeedbackWnd                                          0xAA0C74
#define pinstCBugReportWnd                                         0xAA0C78
#define pinstCVideoModesWnd                                        0xAA0C7C
#define pinstCTextEntryWnd                                         0xAA0C84
#define pinstCFileSelectionWnd                                     0xAA0C88
#define pinstCCompassWnd                                           0xAA0C8C
#define pinstCPlayerNotesWnd                                       0xAA0C90
#define pinstCGemsGameWnd                                          0xAA0C94
#define pinstCTimeLeftWnd                                          0xAA0C98
#define pinstCPetitionQWnd                                         0xAA0CAC
#define pinstCSoulmarkWnd                                          0xAA0CB0
#define pinstCStoryWnd                                             0xAA0CB4
#define pinstCJournalTextWnd                                       0xAA0CB8
#define pinstCJournalCatWnd                                        0xAA0CBC
#define pinstCBodyTintWnd                                          0xAA0CC0
#define pinstCServerListWnd                                        0xAA0CC4
#define pinstCAvaZoneWnd                                           0xAA0CCC
#define pinstCBlockedBuffWnd                                       0xAA0CD0
#define pinstCBlockedPetBuffWnd                                    0xAA0CD4
#define pinstCInvSlotMgr                                           0xAA0CEC
#define pinstCContainerMgr                                         0xAA0CF0
#define pinstCAdventureLeaderboardWnd                              0xBE8C98
#define pinstCAdventureRequestWnd                                  0xBE8C60
#define pinstCAltStorageWnd                                        0xBE8D10
#define pinstCAdventureStatsWnd                                    0xBE8C98
#define pinstCBarterMerchantWnd                                    0xBE9168
#define pinstCBarterSearchWnd                                      0xBE91A0
#define pinstCBarterWnd                                            0xBE91D8
#define pinstCChatManager                                          0xBE95D0
#define pinstCDynamicZoneWnd                                       0xBE97C0
#define pinstCEQMainWnd                                            0xBE9880
#define pinstCFellowshipWnd                                        0xBE9948
#define pinstCFindLocationWnd                                      0xBE99B0
#define pinstCGroupSearchWnd                                       0xBE9B10
#define pinstCGroupWnd                                             0xBE9B48
#define pinstCGuildBankWnd                                         0xBE9B80
#define pinstCGuildMgmtWnd                                         0xBEBBF0
#define pinstCGuildTributeMasterWnd                                0xBEBC28
#define pinstCHotButtonWnd                                         0xBEBC78
#define pinstCHotButtonWnd1                                        0xBEBC78
#define pinstCHotButtonWnd2                                        0xBEBC7C
#define pinstCHotButtonWnd3                                        0xBEBC80
#define pinstCHotButtonWnd4                                        0xBEBC84
#define pinstCItemDisplayManager                                   0xBEBDC0
#define pinstCItemExpTransferWnd                                   0xBEBDFC
#define pinstCLeadershipWnd                                        0xBEBF28
#define pinstCLFGuildWnd                                           0xBEBF60
#define pinstCMIZoneSelectWnd                                      0xBEC1F8
#define pinstCAdventureMerchantWnd                                 0xBEC4A8
#define pinstCConfirmationDialog                                   0xBEC4E0
#define pinstCPopupWndManager                                      0xBEC4E0
#define pinstCProgressionSelectionWnd                              0xBEC548
#define pinstCPvPLeaderboardWnd                                    0xBEC580
#define pinstCPvPStatsWnd                                          0xBEC5B8
#define pinstCSystemInfoDialogBox                                  0xBEC840
#define pinstCTargetOfTargetWnd                                    0xBED440
#define pinstCTaskSelectWnd                                        0xBED4A8
#define pinstCTaskTemplateSelectWnd                                0xBED4E0
#define pinstCTaskWnd                                              0xBED518
#define pinstCTipWndOFDAY                                          0xBED690
#define pinstCTipWndCONTEXT                                        0xBED694
#define pinstCTitleWnd                                             0xBED6C8
#define pinstCTradeskillWnd                                        0xBED740
#define pinstCTributeBenefitWnd                                    0xBED7D8
#define pinstCTributeMasterWnd                                     0xBED810
#define pinstCContextMenuManager                                   0x1246FD0
#define pinstCVoiceMacroWnd                                        0xBBD2F8
#define pinstCHtmlWnd                                              0xBBD370


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D36D0
#define __ConvertItemTags                                          0x4C4A90
#define __ExecuteCmd                                               0x4B0920
#define __get_melee_range                                          0x4B68A0
#define __GetGaugeValueFromEQ                                      0x6BC6A0
#define __GetLabelFromEQ                                           0x6BD7C0
#define __GetXTargetType                                           0x7344C0
#define __LoadFrontEnd                                             0x5A0000
#define __NewUIINI                                                 0x6BC250
#define __ProcessGameEvents                                        0x50AD20
#define CrashDetected                                              0x59FE00
#define DrawNetStatus                                              0x534F70
#define Util__FastTime                                             0x7BF640
#define Expansion_HoT                                              0xB58940

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483E10
#define AltAdvManager__IsAbilityReady                              0x483F30
#define AltAdvManager__GetAltAbility                               0x4841B0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x4396A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5BDBA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C7940

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x785230

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5DFB00
#define CChatManager__InitContextMenu                              0x5E02D0

// CChatService
#define CChatService__GetNumberOfFriends                           0x728600
#define CChatService__GetFriendName                                0x728610

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5E4630
#define CChatWindow__Clear                                         0x5E4F80
#define CChatWindow__WndNotification                               0x5E5160

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x76EE10
#define CComboWnd__Draw                                            0x76EFD0
#define CComboWnd__GetCurChoice                                    0x76ECD0
#define CComboWnd__GetListRect                                     0x76F2A0
#define CComboWnd__GetTextRect                                     0x76EE40
#define CComboWnd__InsertChoice                                    0x76F310
#define CComboWnd__SetColors                                       0x76EC60
#define CComboWnd__SetChoice                                       0x76EC90

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5EE400
#define CContainerWnd__vftable                                     0x8B5698

// CDisplay 
#define CDisplay__CleanGameUI                                      0x477BF0
#define CDisplay__GetClickedActor                                  0x470C30
#define CDisplay__GetUserDefinedColor                              0x46F610
#define CDisplay__GetWorldFilePath                                 0x46EAC0
#define CDisplay__is3dON                                           0x46DBF0
#define CDisplay__ReloadUI                                         0x480C50
#define CDisplay__WriteTextHD2                                     0x473960

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B7BF0
#define CEditBaseWnd__SetSel                                       0x792A90

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x778240
#define CEditWnd__GetCharIndexPt                                   0x7791D0
#define CEditWnd__GetDisplayString                                 0x7783D0
#define CEditWnd__GetHorzOffset                                    0x778660
#define CEditWnd__GetLineForPrintableChar                          0x778CA0
#define CEditWnd__GetSelStartPt                                    0x779410
#define CEditWnd__GetSTMLSafeText                                  0x7787F0
#define CEditWnd__PointFromPrintableChar                           0x778DB0
#define CEditWnd__SelectableCharFromPoint                          0x778F20
#define CEditWnd__SetEditable                                      0x7787C0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EAD20
#define CEverQuest__DropHeldItemOnGround                           0x4F82C0
#define CEverQuest__dsp_chat                                       0x4F1170
#define CEverQuest__DoTellWindow                                   0x4EF8E0
#define CEverQuest__EnterZone                                      0x5025D0
#define CEverQuest__GetBodyTypeDesc                                0x4E7B90
#define CEverQuest__GetClassDesc                                   0x4E73D0
#define CEverQuest__GetClassThreeLetterCode                        0x4E79D0
#define CEverQuest__GetDeityDesc                                   0x4E8200
#define CEverQuest__GetLangDesc                                    0x4E7F20
#define CEverQuest__GetRaceDesc                                    0x4E81D0
#define CEverQuest__InterpretCmd                                   0x4F1D80
#define CEverQuest__LeftClickedOnPlayer                            0x504700
#define CEverQuest__LMouseUp                                       0x508280
#define CEverQuest__RightClickedOnPlayer                           0x5093E0
#define CEverQuest__RMouseUp                                       0x50A560
#define CEverQuest__SetGameState                                   0x4EB1B0
#define CEverQuest__Emote                                          0x4F1390

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5FB500
#define CGaugeWnd__CalcLinesFillRect                               0x5FB560
#define CGaugeWnd__Draw                                            0x5FB9B0

// CGuild
#define CGuild__FindMemberByName                                   0x41BB20

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x6146D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x620100
#define CInvSlotMgr__MoveItem                                      0x620510

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x61F5B0
#define CInvSlot__SliderComplete                                   0x61D9A0
#define CInvSlot__GetItemBase                                      0x61D100

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x6212F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6B9F60
#define CItemDisplayWnd__UpdateStrings                             0x6221E0

// CLabel 
#define CLabel__Draw                                               0x636640

// CListWnd 
#define CListWnd__AddColumn                                        0x767A40
#define CListWnd__AddColumn1                                       0x7670B0
#define CListWnd__AddLine                                          0x766C60
#define CListWnd__AddString                                        0x766E00
#define CListWnd__CalculateFirstVisibleLine                        0x762FA0
#define CListWnd__CalculateVSBRange                                0x7652B0
#define CListWnd__ClearAllSel                                      0x762500
#define CListWnd__CloseAndUpdateEditWindow                         0x7662D0
#define CListWnd__Compare                                          0x763980
#define CListWnd__Draw                                             0x764EF0
#define CListWnd__DrawColumnSeparators                             0x764D60
#define CListWnd__DrawHeader                                       0x762790
#define CListWnd__DrawItem                                         0x764380
#define CListWnd__DrawLine                                         0x7649E0
#define CListWnd__DrawSeparator                                    0x764E00
#define CListWnd__EnsureVisible                                    0x7630F0
#define CListWnd__ExtendSel                                        0x7642A0
#define CListWnd__GetColumnMinWidth                                0x7621D0
#define CListWnd__GetColumnWidth                                   0x762110
#define CListWnd__GetCurSel                                        0x761980
#define CListWnd__GetHeaderRect                                    0x761AF0
#define CListWnd__GetItemAtPoint                                   0x7633B0
#define CListWnd__GetItemAtPoint1                                  0x763420
#define CListWnd__GetItemData                                      0x761D10
#define CListWnd__GetItemHeight                                    0x762C20
#define CListWnd__GetItemIcon                                      0x761EF0
#define CListWnd__GetItemRect                                      0x7631B0
#define CListWnd__GetItemText                                      0x761DA0
#define CListWnd__GetSelList                                       0x766F90
#define CListWnd__GetSeparatorRect                                 0x7638D0
#define CListWnd__RemoveLine                                       0x7679F0
#define CListWnd__SetColors                                        0x761A50
#define CListWnd__SetColumnJustification                           0x762370
#define CListWnd__SetColumnWidth                                   0x762190
#define CListWnd__SetCurSel                                        0x7619C0
#define CListWnd__SetItemColor                                     0x765F90
#define CListWnd__SetItemData                                      0x7625A0
#define CListWnd__SetItemText                                      0x765D70
#define CListWnd__ShiftColumnSeparator                             0x765BE0
#define CListWnd__Sort                                             0x768180
#define CListWnd__ToggleSel                                        0x762470

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x64C590

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x65F150
#define CMerchantWnd__RequestBuyItem                               0x662AA0
#define CMerchantWnd__RequestSellItem                              0x682EB0
#define CMerchantWnd__SelectBuySellSlot                            0x6606E0

// CObfuscator
#define CObfuscator__doit                                          0x6F83B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x780B50
#define CSidlManager__CreateLabel                                  0x6B2D00

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B9D80
#define CSidlScreenWnd__CalculateVSBRange                          0x5B9CB0
#define CSidlScreenWnd__ConvertToRes                               0x792970
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x771380
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7724A0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x772550
#define CSidlScreenWnd__dCSidlScreenWnd                            0x771CC0
#define CSidlScreenWnd__DrawSidlPiece                              0x770E50
#define CSidlScreenWnd__EnableIniStorage                           0x770640
#define CSidlScreenWnd__GetSidlPiece                               0x771060
#define CSidlScreenWnd__Init1                                      0x772300
#define CSidlScreenWnd__LoadIniInfo                                0x771430
#define CSidlScreenWnd__LoadIniListWnd                             0x770790
#define CSidlScreenWnd__LoadSidlScreen                             0x771F10
#define CSidlScreenWnd__StoreIniInfo                               0x770240
#define CSidlScreenWnd__StoreIniVis                                0x7705D0
#define CSidlScreenWnd__WndNotification                            0x7720F0
#define CSidlScreenWnd__GetChildItem                               0x7706A0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x56D020

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x793460
#define CSliderWnd__SetValue                                       0x793560
#define CSliderWnd__SetNumTicks                                    0x793B10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B7B80

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x790010
#define CStmlWnd__CalculateHSBRange                                0x7876D0
#define CStmlWnd__CalculateVSBRange                                0x787750
#define CStmlWnd__CanBreakAtCharacter                              0x7878C0
#define CStmlWnd__FastForwardToEndOfTag                            0x7885A0
#define CStmlWnd__ForceParseNow                                    0x790540
#define CStmlWnd__GetNextTagPiece                                  0x7884C0
#define CStmlWnd__GetSTMLText                                      0x5E45D0
#define CStmlWnd__GetThisChar                                      0x7B8010
#define CStmlWnd__GetVisiableText                                  0x7899E0
#define CStmlWnd__InitializeWindowVariables                        0x78BFB0
#define CStmlWnd__MakeStmlColorTag                                 0x7865D0
#define CStmlWnd__MakeWndNotificationTag                           0x786670
#define CStmlWnd__SetSTMLText                                      0x78C0D0
#define CStmlWnd__StripFirstSTMLLines                              0x78FCC0
#define CStmlWnd__UpdateHistoryString                              0x78A270

// CTabWnd 
#define CTabWnd__Draw                                              0x794A10
#define CTabWnd__DrawCurrentPage                                   0x7942E0
#define CTabWnd__DrawTab                                           0x7940C0
#define CTabWnd__GetCurrentPage                                    0x7946A0
#define CTabWnd__GetPageClientRect                                 0x793D70
#define CTabWnd__GetPageFromTabIndex                               0x793FF0
#define CTabWnd__GetPageInnerRect                                  0x793DD0
#define CTabWnd__GetTabInnerRect                                   0x793F70
#define CTabWnd__GetTabRect                                        0x793E60
#define CTabWnd__InsertPage                                        0x794CA0
#define CTabWnd__SetPage                                           0x7946E0
#define CTabWnd__SetPageRect                                       0x794940
#define CTabWnd__UpdatePage                                        0x794C20

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x418100

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7728D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x795890

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x760880

// CXRect 
#define CXRect__CenterPoint                                        0x5358F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x522160
#define CXStr__CXStr1                                              0x6E0300
#define CXStr__CXStr3                                              0x7BC5E0
#define CXStr__dCXStr                                              0x471CE0
#define CXStr__operator_equal                                      0x7BC750
#define CXStr__operator_equal1                                     0x7BC7A0
#define CXStr__operator_plus_equal1                                0x7BD830

// CXWnd 
#define CXWnd__BringToTop                                          0x768770
#define CXWnd__Center                                              0x76D760
#define CXWnd__ClrFocus                                            0x768590
#define CXWnd__DoAllDrawing                                        0x76E080
#define CXWnd__DrawChildren                                        0x76E1C0
#define CXWnd__DrawColoredRect                                     0x768A50
#define CXWnd__DrawTooltip                                         0x76D690
#define CXWnd__DrawTooltipAtPoint                                  0x76CDC0
#define CXWnd__GetBorderFrame                                      0x768F40
#define CXWnd__GetChildWndAt                                       0x76C280
#define CXWnd__GetClientClipRect                                   0x768D10
#define CXWnd__GetScreenClipRect                                   0x76D2F0
#define CXWnd__GetScreenRect                                       0x769080
#define CXWnd__GetTooltipRect                                      0x768B60
#define CXWnd__GetWindowTextA                                      0x5AB120
#define CXWnd__IsActive                                            0x773A00
#define CXWnd__IsDescendantOf                                      0x768E70
#define CXWnd__IsReallyVisible                                     0x76C260
#define CXWnd__IsType                                              0x798690
#define CXWnd__Move                                                0x76B720
#define CXWnd__Move1                                               0x76B7E0
#define CXWnd__ProcessTransition                                   0x768720
#define CXWnd__Refade                                              0x7686A0
#define CXWnd__Resize                                              0x769140
#define CXWnd__Right                                               0x76D200
#define CXWnd__SetFocus                                            0x76A950
#define CXWnd__SetKeyTooltip                                       0x769390
#define CXWnd__SetMouseOver                                        0x76D580
#define CXWnd__StartFade                                           0x7687B0
#define CXWnd__GetChildItem                                        0x76D4F0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x774F70
#define CXWndManager__DrawWindows                                  0x774BF0
#define CXWndManager__GetKeyboardFlags                             0x773660
#define CXWndManager__HandleKeyboardMsg                            0x773CD0
#define CXWndManager__RemoveWnd                                    0x773B20

// CDBStr
#define CDBStr__GetString                                          0x46C430

// EQ_Character 
#define EQ_Character__CastRay                                      0x715EE0
#define EQ_Character__CastSpell                                    0x430550
#define EQ_Character__Cur_HP                                       0x439360
#define EQ_Character__GetAACastingTimeModifier                     0x4254E0
#define EQ_Character__GetCharInfo2                                 0x714C80
#define EQ_Character__GetFocusCastingTimeModifier                  0x420C40
#define EQ_Character__GetFocusRangeModifier                        0x420E10
#define EQ_Character__Max_Endurance                                0x53D840
#define EQ_Character__Max_HP                                       0x434320
#define EQ_Character__Max_Mana                                     0x53D640
#define EQ_Character__doCombatAbility                              0x53C4C0
#define EQ_Character__UseSkill                                     0x447BF0
#define EQ_Character__GetConLevel                                  0x537650
#define EQ_Character__IsExpansionFlag                              0x40DA00
#define EQ_Character__TotalEffect                                  0x429A40

// EQ_Item 
#define EQ_Item__CanDrop                                           0x51C120
#define EQ_Item__CreateItemTagString                               0x703630
#define EQ_Item__IsStackable                                       0x6F8A30

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x485260
#define EQ_LoadingS__Array                                         0x948468

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x540D70
#define EQ_PC__GetAltAbilityIndex                                  0x709C10
#define EQ_PC__GetCombatAbility                                    0x709CA0
#define EQ_PC__GetCombatAbilityTimer                               0x709D50
#define EQ_PC__GetItemTimerValue                                   0x53C2E0
#define EQ_PC__HasLoreItem                                         0x7137E0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B4BC0
#define EQItemList__add_item                                       0x4B4B50
#define EQItemList__delete_item                                    0x4B4F70
#define EQItemList__FreeItemList                                   0x4B4EA0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46BC20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x545920
#define EQPlayer__dEQPlayer                                        0x54A410
#define EQPlayer__DoAttack                                         0x55B2A0
#define EQPlayer__EQPlayer                                         0x54FCE0
#define EQPlayer__SetNameSpriteState                               0x547D90
#define EQPlayer__SetNameSpriteTint                                0x545990
#define EQPlayer__IsBodyType_j                                     0x7157A0
#define EQPlayer__IsTargetable                                     0x715A60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x550FB0
#define EQPlayerManager__GetSpawnByName                            0x551240

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x521B80
#define KeypressHandler__AttachKeyToEqCommand                      0x521BC0
#define KeypressHandler__ClearCommandStateArray                    0x521990
#define KeypressHandler__HandleKeyDown                             0x520390
#define KeypressHandler__HandleKeyUp                               0x5206A0
#define KeypressHandler__SaveKeymapping                            0x521A60

// MapViewMap 
#define MapViewMap__Clear                                          0x647C10
#define MapViewMap__SaveEx                                         0x6485E0

#define PlayerPointManager__GetAltCurrency                         0x7047C0

// StringTable 
#define StringTable__getString                                     0x6F8630

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x53F500
