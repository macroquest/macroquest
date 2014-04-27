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
#define __ExpectedVersionDate                                     "Aug 15 2012"
#define __ExpectedVersionTime                                     "09:30:22"
#define __ActualVersionDate                                        0x9126A8
#define __ActualVersionTime                                        0x9126B4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x535DC0
#define __MemChecker1                                              0x81BF50
#define __MemChecker2                                              0x5BADE0
#define __MemChecker3                                              0x5BAD30
#define __MemChecker4                                              0x83E5F0
#define __EncryptPad0                                              0x9EB888
#define __EncryptPad1                                              0xA65938
#define __EncryptPad2                                              0xA04618
#define __EncryptPad3                                              0xA04218
#define __EncryptPad4                                              0xA673E0
#define __AC1                                                      0x6F9D30
#define __AC2                                                      0x4F2025
#define __AC3                                                      0x504148
#define __AC4                                                      0x5098B4
#define __AC5                                                      0x515698
#define __AC6                                                      0x51905B
#define __AC7                                                      0x51101B
#define __AC1_Data                                                 0x8F7FED
// Direct Input
#define DI8__Main                                                  0xCEBF60
#define DI8__Keyboard                                              0xCEBF64
#define DI8__Mouse                                                 0xCEBF68
#define __AltTimerReady                                            0xBB3301
#define __Attack                                                   0xCE7D26
#define __Autofire                                                 0xCE7D27
#define __BindList                                                 0x9D3D18
#define __Clicks                                                   0xC7080C
#define __CommandList                                              0x9D5368
#define __CurrentMapLabel                                          0xDF7DA0
#define __CurrentSocial                                            0x9BFEDC
#define __DoAbilityList                                            0xCA86FC
#define __do_loot                                                  0x4C5BA0
#define __DrawHandler                                              0x1454A6C
#define __GroupCount                                               0xC611C2
#define __Guilds                                                   0xC63758
#define __gWorld                                                   0xC63684
#define __HotkeyPage                                               0xCD12D8
#define __HWnd                                                     0xCEBCB0
#define __InChatMode                                               0xC70744
#define __LastTell                                                 0xC72614
#define __LMouseHeldTime                                           0xC70878
#define __Mouse                                                    0xCEBF6C
#define __MouseLook                                                0xC707DA
#define __MouseEventTime                                           0xCE8044
#define __NetStatusToggle                                          0xC707DD
#define __PCNames                                                  0xC71C94
#define __RangeAttackReady                                         0xC7192C
#define __RMouseHeldTime                                           0xC70874
#define __RunWalkState                                             0xC70748
#define __ScreenMode                                               0xBB0648
#define __ScreenX                                                  0xC706F8
#define __ScreenY                                                  0xC706FC
#define __ScreenXMax                                               0xC70700
#define __ScreenYMax                                               0xC70704
#define __ServerHost                                               0xC61104
#define __ServerName                                               0xCA86BC
#define __ShiftKeyDown                                             0xC70DC8
#define __ShowNames                                                0xC71B38
#define __Socials                                                  0xCA87BC


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xC6D070
#define instEQZoneInfo                                             0xC709C0
#define instKeypressHandler                                        0xCE8040
#define pinstActiveBanker                                          0xC6372C
#define pinstActiveCorpse                                          0xC63730
#define pinstActiveGMaster                                         0xC63734
#define pinstActiveMerchant                                        0xC63728
#define pinstAltAdvManager                                         0xBB1590
#define pinstAuraMgr                                               0xA807D0
#define pinstBandageTarget                                         0xC63714
#define pinstCamActor                                              0xBB1008
#define pinstCDBStr                                                0xBB0620
#define pinstCDisplay                                              0xC6373C
#define pinstCEverQuest                                            0xCEC0E8
#define pinstCharData                                              0xC636F8
#define pinstCharSpawn                                             0xC63720
#define pinstControlledMissile                                     0xC636F4
#define pinstControlledPlayer                                      0xC63720
#define pinstCSidlManager                                          0x1454FAC
#define pinstCXWndManager                                          0x1454FA4
#define instDynamicZone                                            0xC6CAC8
#define pinstDZMember                                              0xC6CBD8
#define pinstDZTimerInfo                                           0xC6CBDC
#define pinstEQItemList                                            0xC60270
#define instEQMisc                                                 0xBB0588
#define pinstEQSoundManager                                        0xBB1600
#define instExpeditionLeader                                       0xC6CB12
#define instExpeditionName                                         0xC6CB52
#define pinstGroup                                                 0xC611BE
#define pinstImeManager                                            0x1454FB0
#define pinstLocalPlayer                                           0xC6370C
#define pinstMercenaryData                                         0xCE84C0
#define pinstModelPlayer                                           0xC63738
#define pinstPCData                                                0xC636F8
#define pinstSkillMgr                                              0xCE8AF0
#define pinstSpawnManager                                          0xCE8760
#define pinstSpellManager                                          0xCE8B68
#define pinstSpellSets                                             0xCE1030
#define pinstStringTable                                           0xC636A0
#define pinstSwitchManager                                         0xC60DD0
#define pinstTarget                                                0xC63724
#define pinstTargetObject                                          0xC636FC
#define pinstTargetSwitch                                          0xC63700
#define pinstTaskMember                                            0xBB0550
#define pinstTrackTarget                                           0xC63718
#define pinstTradeTarget                                           0xC63708
#define instTributeActive                                          0xBB05AD
#define pinstViewActor                                             0xBB1004
#define pinstWorldData                                             0xC636DC


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0xA77810
#define pinstCAudioTriggersWindow                                  0xA777A8
#define pinstCCharacterSelect                                      0xBB0EB8
#define pinstCFacePick                                             0xBB0E68
#define pinstCNoteWnd                                              0xBB0E70
#define pinstCBookWnd                                              0xBB0E78
#define pinstCPetInfoWnd                                           0xBB0E7C
#define pinstCTrainWnd                                             0xBB0E80
#define pinstCSkillsWnd                                            0xBB0E84
#define pinstCSkillsSelectWnd                                      0xBB0E88
#define pinstCCombatSkillSelectWnd                                 0xBB0E8C
#define pinstCFriendsWnd                                           0xBB0E90
#define pinstCAuraWnd                                              0xBB0E94
#define pinstCRespawnWnd                                           0xBB0E98
#define pinstCBandolierWnd                                         0xBB0E9C
#define pinstCPotionBeltWnd                                        0xBB0EA0
#define pinstCAAWnd                                                0xBB0EA4
#define pinstCGroupSearchFiltersWnd                                0xBB0EA8
#define pinstCLoadskinWnd                                          0xBB0EAC
#define pinstCAlarmWnd                                             0xBB0EB0
#define pinstCMusicPlayerWnd                                       0xBB0EB4
#define pinstCMailWnd                                              0xBB0EBC
#define pinstCMailCompositionWnd                                   0xBB0EC0
#define pinstCMailAddressBookWnd                                   0xBB0EC4
#define pinstCRaidWnd                                              0xBB0ECC
#define pinstCRaidOptionsWnd                                       0xBB0ED0
#define pinstCBreathWnd                                            0xBB0ED4
#define pinstCMapViewWnd                                           0xBB0ED8
#define pinstCMapToolbarWnd                                        0xBB0EDC
#define pinstCEditLabelWnd                                         0xBB0EE0
#define pinstCTargetWnd                                            0xBB0EE4
#define pinstCColorPickerWnd                                       0xBB0EE8
#define pinstCPlayerWnd                                            0xBB0EEC
#define pinstCOptionsWnd                                           0xBB0EF0
#define pinstCBuffWindowNORMAL                                     0xBB0EF4
#define pinstCBuffWindowSHORT                                      0xBB0EF8
#define pinstCharacterCreation                                     0xBB0EFC
#define pinstCCursorAttachment                                     0xBB0F00
#define pinstCCastingWnd                                           0xBB0F04
#define pinstCCastSpellWnd                                         0xBB0F08
#define pinstCSpellBookWnd                                         0xBB0F0C
#define pinstCInventoryWnd                                         0xBB0F10
#define pinstCBankWnd                                              0xBB0F14
#define pinstCQuantityWnd                                          0xBB0F18
#define pinstCLootWnd                                              0xBB0F1C
#define pinstCActionsWnd                                           0xBB0F20
#define pinstCCombatAbilityWnd                                     0xBB0F24
#define pinstCMerchantWnd                                          0xBB0F28
#define pinstCTradeWnd                                             0xBB0F2C
#define pinstCSelectorWnd                                          0xBB0F30
#define pinstCBazaarWnd                                            0xBB0F34
#define pinstCBazaarSearchWnd                                      0xBB0F38
#define pinstCGiveWnd                                              0xBB0F54
#define pinstCTrackingWnd                                          0xBB0F5C
#define pinstCInspectWnd                                           0xBB0F60
#define pinstCSocialEditWnd                                        0xBB0F64
#define pinstCFeedbackWnd                                          0xBB0F68
#define pinstCBugReportWnd                                         0xBB0F6C
#define pinstCVideoModesWnd                                        0xBB0F70
#define pinstCTextEntryWnd                                         0xBB0F78
#define pinstCFileSelectionWnd                                     0xBB0F7C
#define pinstCCompassWnd                                           0xBB0F80
#define pinstCPlayerNotesWnd                                       0xBB0F84
#define pinstCGemsGameWnd                                          0xBB0F88
#define pinstCTimeLeftWnd                                          0xBB0F8C
#define pinstCPetitionQWnd                                         0xBB0FA0
#define pinstCSoulmarkWnd                                          0xBB0FA4
#define pinstCStoryWnd                                             0xBB0FA8
#define pinstCJournalTextWnd                                       0xBB0FAC
#define pinstCJournalCatWnd                                        0xBB0FB0
#define pinstCBodyTintWnd                                          0xBB0FB4
#define pinstCServerListWnd                                        0xBB0FB8
#define pinstCAvaZoneWnd                                           0xBB0FC0
#define pinstCBlockedBuffWnd                                       0xBB0FC4
#define pinstCBlockedPetBuffWnd                                    0xBB0FC8
#define pinstCInvSlotMgr                                           0xBB0FFC
#define pinstCContainerMgr                                         0xBB1000
#define pinstCAdventureLeaderboardWnd                              0xDF48D8
#define pinstCAdventureRequestWnd                                  0xDF48A0
#define pinstCAltStorageWnd                                        0xDF49E0
#define pinstCAdventureStatsWnd                                    0xDF48D8
#define pinstCBarterMerchantWnd                                    0xDF4E38
#define pinstCBarterSearchWnd                                      0xDF4E70
#define pinstCBarterWnd                                            0xDF4EA8
#define pinstCChatManager                                          0xDF52A0
#define pinstCDynamicZoneWnd                                       0xDF5490
#define pinstCEQMainWnd                                            0xDF5550
#define pinstCFellowshipWnd                                        0xDF5484
#define pinstCFindLocationWnd                                      0xDF5680
#define pinstCGroupSearchWnd                                       0xDF57E0
#define pinstCGroupWnd                                             0xDF5818
#define pinstCGuildBankWnd                                         0xDF5850
#define pinstCGuildMgmtWnd                                         0xDF78C0
#define pinstCGuildTributeMasterWnd                                0xDF9518
#define pinstCHotButtonWnd                                         0xDF7914
#define pinstCHotButtonWnd1                                        0xDF7914
#define pinstCHotButtonWnd2                                        0xDF7918
#define pinstCHotButtonWnd3                                        0xDF791C
#define pinstCHotButtonWnd4                                        0xDF795C
#define pinstCItemDisplayManager                                   0xDF7A90
#define pinstCItemExpTransferWnd                                   0xDF7ACC
#define pinstCLeadershipWnd                                        0xDF7BF8
#define pinstCLFGuildWnd                                           0xDF7C30
#define pinstCMIZoneSelectWnd                                      0xDF7ED0
#define pinstCAdventureMerchantWnd                                 0xDF8180
#define pinstCConfirmationDialog                                   0xDF81B8
#define pinstCPopupWndManager                                      0xDF81B8
#define pinstCProgressionSelectionWnd                              0xDF8220
#define pinstCPvPLeaderboardWnd                                    0xDF8258
#define pinstCPvPStatsWnd                                          0xDF8290
#define pinstCSystemInfoDialogBox                                  0xDF8578
#define pinstCTargetOfTargetWnd                                    0xDF91C8
#define pinstCTaskSelectWnd                                        0xDF8434
#define pinstCTaskTemplateSelectWnd                                0xDF9268
#define pinstCTaskWnd                                              0xDF92A0
#define pinstCTipWndOFDAY                                          0xDF9398
#define pinstCTipWndCONTEXT                                        0xDF939C
#define pinstCTitleWnd                                             0xDF93D0
#define pinstCTradeskillWnd                                        0xDF9448
#define pinstCTributeBenefitWnd                                    0xDF94E0
#define pinstCTributeMasterWnd                                     0xDF9518
#define pinstCContextMenuManager                                   0x1455008
#define pinstCVoiceMacroWnd                                        0xCE8EB0
#define pinstCHtmlWnd                                              0xCE8F28


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4DA2A0
#define __ConvertItemTags                                          0x4CB2C0
#define __ExecuteCmd                                               0x4B6DC0
#define __EQGetTime                                                0x81D3C0
#define __get_melee_range                                          0x4BD080
#define __GetGaugeValueFromEQ                                      0x6F8AE0
#define __GetLabelFromEQ                                           0x6F9CD0
#define __GetXTargetType                                           0x778DC0
#define __LoadFrontEnd                                             0x5B9D50
#define __NewUIINI                                                 0x6F8690
#define __ProcessGameEvents                                        0x511800
#define CrashDetected                                              0x5BC760
#define DrawNetStatus                                              0x5437A0
#define Util__FastTime                                             0x81C820
#define Expansion_HoT                                              0xC71A98
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x489E80
#define AltAdvManager__IsAbilityReady                              0x489F60
#define AltAdvManager__GetAltAbility                               0x48A1C0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43D010

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5E0EE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5EB090

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x523D70

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x6040D0
#define CChatManager__InitContextMenu                              0x604A00

// CChatService
#define CChatService__GetNumberOfFriends                           0x76EDD0
#define CChatService__GetFriendName                                0x76EDE0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x6097C0
#define CChatWindow__Clear                                         0x609370
#define CChatWindow__WndNotification                               0x609BD0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7CBAD0
#define CComboWnd__Draw                                            0x7CBC90
#define CComboWnd__GetCurChoice                                    0x7CB8F0
#define CComboWnd__GetListRect                                     0x7CBF70
#define CComboWnd__GetTextRect                                     0x7CBB00
#define CComboWnd__InsertChoice                                    0x7CBFE0
#define CComboWnd__SetColors                                       0x7CB880
#define CComboWnd__SetChoice                                       0x7CB8B0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x611910
#define CContainerWnd__vftable                                     0x91B100

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47D720
#define CDisplay__GetClickedActor                                  0x4761B0
#define CDisplay__GetUserDefinedColor                              0x474AA0
#define CDisplay__GetWorldFilePath                                 0x473FC0
#define CDisplay__is3dON                                           0x4730C0
#define CDisplay__ReloadUI                                         0x486DB0
#define CDisplay__WriteTextHD2                                     0x479250

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5D8AD0
#define CEditBaseWnd__SetSel                                       0x7EC4C0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7D5170
#define CEditWnd__GetCharIndexPt                                   0x7D6140
#define CEditWnd__GetDisplayString                                 0x7D5310
#define CEditWnd__GetHorzOffset                                    0x7D55A0
#define CEditWnd__GetLineForPrintableChar                          0x7D5BF0
#define CEditWnd__GetSelStartPt                                    0x7D6380
#define CEditWnd__GetSTMLSafeText                                  0x7D5740
#define CEditWnd__PointFromPrintableChar                           0x7D5D00
#define CEditWnd__SelectableCharFromPoint                          0x7D5E80
#define CEditWnd__SetEditable                                      0x7D5710

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4F2770
#define CEverQuest__DropHeldItemOnGround                           0x4FF600
#define CEverQuest__dsp_chat                                       0x4F89A0
#define CEverQuest__DoTellWindow                                   0x4F7190
#define CEverQuest__EnterZone                                      0x509A40
#define CEverQuest__GetBodyTypeDesc                                0x4EF570
#define CEverQuest__GetClassDesc                                   0x4EEDB0
#define CEverQuest__GetClassThreeLetterCode                        0x4EF3B0
#define CEverQuest__GetDeityDesc                                   0x4EFC20
#define CEverQuest__GetLangDesc                                    0x4EF900
#define CEverQuest__GetRaceDesc                                    0x4EFBF0
#define CEverQuest__InterpretCmd                                   0x4F94B0
#define CEverQuest__LeftClickedOnPlayer                            0x50B720
#define CEverQuest__LMouseUp                                       0x50EE40
#define CEverQuest__RightClickedOnPlayer                           0x510000
#define CEverQuest__RMouseUp                                       0x510FE0
#define CEverQuest__SetGameState                                   0x4F2C00
#define CEverQuest__Emote                                          0x4F8BC0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x61F790
#define CGaugeWnd__CalcLinesFillRect                               0x61F7F0
#define CGaugeWnd__Draw                                            0x61FC40

// CGuild
#define CGuild__FindMemberByName                                   0x41CE50

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x639CC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x643FF0
#define CInvSlotMgr__MoveItem                                      0x644CA0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x643680
#define CInvSlot__SliderComplete                                   0x641A40
#define CInvSlot__GetItemBase                                      0x6410C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x645A60

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6F6090
#define CItemDisplayWnd__UpdateStrings                             0x646AB0

// CLabel 
#define CLabel__Draw                                               0x65DBF0

// CListWnd 
#define CListWnd__AddColumn                                        0x7C1450
#define CListWnd__AddColumn1                                       0x7C0A80
#define CListWnd__AddLine                                          0x7C0630
#define CListWnd__AddString                                        0x7C07D0
#define CListWnd__CalculateFirstVisibleLine                        0x7BC8A0
#define CListWnd__CalculateVSBRange                                0x7BECA0
#define CListWnd__ClearAllSel                                      0x7BBDF0
#define CListWnd__CloseAndUpdateEditWindow                         0x7BFCA0
#define CListWnd__Compare                                          0x7BD340
#define CListWnd__Draw                                             0x7BE8E0
#define CListWnd__DrawColumnSeparators                             0x7BE770
#define CListWnd__DrawHeader                                       0x7BC080
#define CListWnd__DrawItem                                         0x7BDD40
#define CListWnd__DrawLine                                         0x7BE430
#define CListWnd__DrawSeparator                                    0x7BE810
#define CListWnd__EnsureVisible                                    0x7BCA00
#define CListWnd__ExtendSel                                        0x7BDC60
#define CListWnd__GetColumnMinWidth                                0x7BBAC0
#define CListWnd__GetColumnWidth                                   0x7BBA00
#define CListWnd__GetCurSel                                        0x7BB1A0
#define CListWnd__GetHeaderRect                                    0x7BB320
#define CListWnd__GetItemAtPoint                                   0x7BCCD0
#define CListWnd__GetItemAtPoint1                                  0x7BCD40
#define CListWnd__GetItemData                                      0x7BB600
#define CListWnd__GetItemHeight                                    0x7BC510
#define CListWnd__GetItemIcon                                      0x7BB7E0
#define CListWnd__GetItemRect                                      0x7BCAD0
#define CListWnd__GetItemText                                      0x7BB690
#define CListWnd__GetSelList                                       0x7C0960
#define CListWnd__GetSeparatorRect                                 0x7BD290
#define CListWnd__RemoveLine                                       0x7C1400
#define CListWnd__SetColors                                        0x7BB290
#define CListWnd__SetColumnJustification                           0x7BBC60
#define CListWnd__SetColumnWidth                                   0x7BBA80
#define CListWnd__SetCurSel                                        0x7BB1E0
#define CListWnd__SetItemColor                                     0x7BF950
#define CListWnd__SetItemData                                      0x7BBE90
#define CListWnd__SetItemText                                      0x7BF780
#define CListWnd__ShiftColumnSeparator                             0x7BF5F0
#define CListWnd__Sort                                             0x7C1BB0
#define CListWnd__ToggleSel                                        0x7BBD60

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x676660

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x691B00
#define CMerchantWnd__RequestBuyItem                               0x697C70
#define CMerchantWnd__RequestSellItem                              0x6BA1A0
#define CMerchantWnd__SelectBuySellSlot                            0x691DB0

// CObfuscator
#define CObfuscator__doit                                          0x7421D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7DDBB0
#define CSidlManager__CreateLabel                                  0x6EDD10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5DCB60
#define CSidlScreenWnd__CalculateVSBRange                          0x5DCA80
#define CSidlScreenWnd__ConvertToRes                               0x7EC3A0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7CE120
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7CF360
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7CF410
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7CEAF0
#define CSidlScreenWnd__DrawSidlPiece                              0x7CDBC0
#define CSidlScreenWnd__EnableIniStorage                           0x7CD380
#define CSidlScreenWnd__GetSidlPiece                               0x7CDDE0
#define CSidlScreenWnd__Init1                                      0x7CF1B0
#define CSidlScreenWnd__LoadIniInfo                                0x7CE1E0
#define CSidlScreenWnd__LoadIniListWnd                             0x7CD4D0
#define CSidlScreenWnd__LoadSidlScreen                             0x7CED50
#define CSidlScreenWnd__StoreIniInfo                               0x7CCF50
#define CSidlScreenWnd__StoreIniVis                                0x7CD310
#define CSidlScreenWnd__WndNotification                            0x7CEFA0
#define CSidlScreenWnd__GetChildItem                               0x7CD3E0

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x582880
#define CSkillMgr__GetSkillCap                                     0x5828F0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7F4620
#define CSliderWnd__SetValue                                       0x7F4720
#define CSliderWnd__SetNumTicks                                    0x7F4CD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6F3D30

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7E9810
#define CStmlWnd__CalculateHSBRange                                0x7E0DD0
#define CStmlWnd__CalculateVSBRange                                0x7E0E60
#define CStmlWnd__CanBreakAtCharacter                              0x7E0FD0
#define CStmlWnd__FastForwardToEndOfTag                            0x7E1CC0
#define CStmlWnd__ForceParseNow                                    0x7E9E00
#define CStmlWnd__GetNextTagPiece                                  0x7E1BE0
#define CStmlWnd__GetSTMLText                                      0x608C10
#define CStmlWnd__GetThisChar                                      0x815090
#define CStmlWnd__GetVisiableText                                  0x7E3120
#define CStmlWnd__InitializeWindowVariables                        0x7E5710
#define CStmlWnd__MakeStmlColorTag                                 0x7DFCF0
#define CStmlWnd__MakeWndNotificationTag                           0x7DFD90
#define CStmlWnd__SetSTMLText                                      0x7E5840
#define CStmlWnd__StripFirstSTMLLines                              0x7E94B0
#define CStmlWnd__UpdateHistoryString                              0x7E39C0

// CTabWnd 
#define CTabWnd__Draw                                              0x7F0220
#define CTabWnd__DrawCurrentPage                                   0x7EFAA0
#define CTabWnd__DrawTab                                           0x7EF870
#define CTabWnd__GetCurrentPage                                    0x7EFE60
#define CTabWnd__GetPageClientRect                                 0x7EF520
#define CTabWnd__GetPageFromTabIndex                               0x7EF7A0
#define CTabWnd__GetPageInnerRect                                  0x7EF580
#define CTabWnd__GetTabInnerRect                                   0x7EF720
#define CTabWnd__GetTabRect                                        0x7EF610
#define CTabWnd__InsertPage                                        0x7F04B0
#define CTabWnd__SetPage                                           0x7EFEA0
#define CTabWnd__SetPageRect                                       0x7F0150
#define CTabWnd__UpdatePage                                        0x7F0430

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x419390

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7CF790

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7ED6D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7BA100

// CXRect 
#define CXRect__CenterPoint                                        0x522E90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x52E780
#define CXStr__CXStr1                                              0x420190
#define CXStr__CXStr3                                              0x8196B0
#define CXStr__dCXStr                                              0x52EBE0
#define CXStr__operator_equal                                      0x819820
#define CXStr__operator_equal1                                     0x819870
#define CXStr__operator_plus_equal1                                0x81A980

// CXWnd 
#define CXWnd__BringToTop                                          0x7C4AA0
#define CXWnd__Center                                              0x7CA450
#define CXWnd__ClrFocus                                            0x7C48D0
#define CXWnd__DoAllDrawing                                        0x7CA2E0
#define CXWnd__DrawChildren                                        0x7CA420
#define CXWnd__DrawColoredRect                                     0x7C4DC0
#define CXWnd__DrawTooltip                                         0x7C4FB0
#define CXWnd__DrawTooltipAtPoint                                  0x7C9550
#define CXWnd__GetBorderFrame                                      0x7C53D0
#define CXWnd__GetChildWndAt                                       0x7C8740
#define CXWnd__GetClientClipRect                                   0x7C5150
#define CXWnd__GetScreenClipRect                                   0x7C9A80
#define CXWnd__GetScreenRect                                       0x7C5500
#define CXWnd__GetTooltipRect                                      0x7C4ED0
#define CXWnd__GetWindowTextA                                      0x522A10
#define CXWnd__IsActive                                            0x7D08D0
#define CXWnd__IsDescendantOf                                      0x7C52C0
#define CXWnd__IsReallyVisible                                     0x7C8720
#define CXWnd__IsType                                              0x7F1B70
#define CXWnd__Move                                                0x7C7E90
#define CXWnd__Move1                                               0x7C9FB0
#define CXWnd__ProcessTransition                                   0x7C4A50
#define CXWnd__Refade                                              0x7C49D0
#define CXWnd__Resize                                              0x7C55D0
#define CXWnd__Right                                               0x7C9990
#define CXWnd__SetFocus                                            0x7C7000
#define CXWnd__SetKeyTooltip                                       0x7C5820
#define CXWnd__SetMouseOver                                        0x7C9DA0
#define CXWnd__StartFade                                           0x7C4AD0
#define CXWnd__GetChildItem                                        0x7C9CE0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7D1E30
#define CXWndManager__DrawWindows                                  0x7D1AB0
#define CXWndManager__GetKeyboardFlags                             0x7D0520
#define CXWndManager__HandleKeyboardMsg                            0x7D0BA0
#define CXWndManager__RemoveWnd                                    0x7D09F0

// CDBStr
#define CDBStr__GetString                                          0x471690

// EQ_Character 
#define EQ_Character__CastRay                                      0x75BE00
#define EQ_Character__CastSpell                                    0x433340
#define EQ_Character__Cur_HP                                       0x43CCB0
#define EQ_Character__GetAACastingTimeModifier                     0x427EE0
#define EQ_Character__GetCharInfo2                                 0x75A170
#define EQ_Character__GetFocusCastingTimeModifier                  0x422B80
#define EQ_Character__GetFocusRangeModifier                        0x422D50
#define EQ_Character__Max_Endurance                                0x54EF20
#define EQ_Character__Max_HP                                       0x437360
#define EQ_Character__Max_Mana                                     0x54ED20
#define EQ_Character__doCombatAbility                              0x54DB10
#define EQ_Character__UseSkill                                     0x44C860
#define EQ_Character__GetConLevel                                  0x546F90
#define EQ_Character__IsExpansionFlag                              0x40DDB0
#define EQ_Character__TotalEffect                                  0x42C7A0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x528570
#define EQ_Item__CreateItemTagString                               0x7402A0
#define EQ_Item__IsStackable                                       0x734550

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x48B4B0
#define EQ_LoadingS__Array                                         0x9CEA50

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x552B40
#define EQ_PC__GetAltAbilityIndex                                  0x74B4B0
#define EQ_PC__GetCombatAbility                                    0x74B540
#define EQ_PC__GetCombatAbilityTimer                               0x74B5F0
#define EQ_PC__GetItemTimerValue                                   0x54D880
#define EQ_PC__HasLoreItem                                         0x54C350

// EQItemList 
#define EQItemList__EQItemList                                     0x4BB3D0
#define EQItemList__add_item                                       0x4BB360
#define EQItemList__delete_item                                    0x4BB780
#define EQItemList__FreeItemList                                   0x4BB6B0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x470C60

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x557CE0
#define EQPlayer__dEQPlayer                                        0x55C9C0
#define EQPlayer__DoAttack                                         0x56EC20
#define EQPlayer__EQPlayer                                         0x562D30
#define EQPlayer__SetNameSpriteState                               0x55A210
#define EQPlayer__SetNameSpriteTint                                0x557D50
#define EQPlayer__IsBodyType_j                                     0x75B6A0
#define EQPlayer__IsTargetable                                     0x75B970

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5642D0
#define EQPlayerManager__GetSpawnByName                            0x564560

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52E0F0
#define KeypressHandler__AttachKeyToEqCommand                      0x52E130
#define KeypressHandler__ClearCommandStateArray                    0x52DF00
#define KeypressHandler__HandleKeyDown                             0x52C890
#define KeypressHandler__HandleKeyUp                               0x52CBA0
#define KeypressHandler__SaveKeymapping                            0x52DFD0

// MapViewMap 
#define MapViewMap__Clear                                          0x66F8B0
#define MapViewMap__SaveEx                                         0x672F60

#define PlayerPointManager__GetAltCurrency                         0x745CB0

// StringTable 
#define StringTable__getString                                     0x742450

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x551250
