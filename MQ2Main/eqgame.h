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
#define __ExpectedVersionDate                                     "Aug 16 2012"
#define __ExpectedVersionTime                                     "21:16:54"
#define __ActualVersionDate                                        0x912660
#define __ActualVersionTime                                        0x91266C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x535E10
#define __MemChecker1                                              0x81C280
#define __MemChecker2                                              0x5BAF90
#define __MemChecker3                                              0x5BAEE0
#define __MemChecker4                                              0x83E950
#define __EncryptPad0                                              0x9EB888
#define __EncryptPad1                                              0xA65938
#define __EncryptPad2                                              0xA04618
#define __EncryptPad3                                              0xA04218
#define __EncryptPad4                                              0xA673E0
#define __AC1                                                      0x6FA470
#define __AC2                                                      0x4F2255
#define __AC3                                                      0x5043A8
#define __AC4                                                      0x509B14
#define __AC5                                                      0x5158F8
#define __AC6                                                      0x5192BB
#define __AC7                                                      0x51127B
#define __AC1_Data                                                 0x8F838D
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
#define __do_loot                                                  0x4C5BD0
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
#define __CastRay                                                  0x4DA2D0
#define __ConvertItemTags                                          0x4CB2F0
#define __ExecuteCmd                                               0x4B6DF0
#define __EQGetTime                                                0x81D6F0
#define __get_melee_range                                          0x4BD0B0
#define __GetGaugeValueFromEQ                                      0x6F9220
#define __GetLabelFromEQ                                           0x6FA410
#define __GetXTargetType                                           0x779380
#define __LoadFrontEnd                                             0x5B9EF0
#define __NewUIINI                                                 0x6F8DD0
#define __ProcessGameEvents                                        0x511A60
#define CrashDetected                                              0x5BC910
#define DrawNetStatus                                              0x5438C0
#define Util__FastTime                                             0x81CB50
#define Expansion_HoT                                              0xC71A98
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x489F50
#define AltAdvManager__IsAbilityReady                              0x48A000
#define AltAdvManager__GetAltAbility                               0x48A260

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43CEF0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5E0FD0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5EAF30

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x523F20

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x604480
#define CChatManager__InitContextMenu                              0x604DB0

// CChatService
#define CChatService__GetNumberOfFriends                           0x76F480
#define CChatService__GetFriendName                                0x76F490

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x609B70
#define CChatWindow__Clear                                         0x609720
#define CChatWindow__WndNotification                               0x609F80

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7CBE10
#define CComboWnd__Draw                                            0x7CBFD0
#define CComboWnd__GetCurChoice                                    0x7CBC30
#define CComboWnd__GetListRect                                     0x7CC2B0
#define CComboWnd__GetTextRect                                     0x7CBE40
#define CComboWnd__InsertChoice                                    0x7CC320
#define CComboWnd__SetColors                                       0x7CBBC0
#define CComboWnd__SetChoice                                       0x7CBBF0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x611C60
#define CContainerWnd__vftable                                     0x91B0C0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47D770
#define CDisplay__GetClickedActor                                  0x4761F0
#define CDisplay__GetUserDefinedColor                              0x474AE0
#define CDisplay__GetWorldFilePath                                 0x474000
#define CDisplay__is3dON                                           0x473100
#define CDisplay__ReloadUI                                         0x486E80
#define CDisplay__WriteTextHD2                                     0x4792A0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5D8BF0
#define CEditBaseWnd__SetSel                                       0x7EC900

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7D54B0
#define CEditWnd__GetCharIndexPt                                   0x7D6480
#define CEditWnd__GetDisplayString                                 0x7D5650
#define CEditWnd__GetHorzOffset                                    0x7D58E0
#define CEditWnd__GetLineForPrintableChar                          0x7D5F30
#define CEditWnd__GetSelStartPt                                    0x7D66C0
#define CEditWnd__GetSTMLSafeText                                  0x7D5A80
#define CEditWnd__PointFromPrintableChar                           0x7D6040
#define CEditWnd__SelectableCharFromPoint                          0x7D61C0
#define CEditWnd__SetEditable                                      0x7D5A50

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4F29A0
#define CEverQuest__DropHeldItemOnGround                           0x4FF860
#define CEverQuest__dsp_chat                                       0x4F8C00
#define CEverQuest__DoTellWindow                                   0x4F73F0
#define CEverQuest__EnterZone                                      0x509CA0
#define CEverQuest__GetBodyTypeDesc                                0x4EF7A0
#define CEverQuest__GetClassDesc                                   0x4EEFE0
#define CEverQuest__GetClassThreeLetterCode                        0x4EF5E0
#define CEverQuest__GetDeityDesc                                   0x4EFE50
#define CEverQuest__GetLangDesc                                    0x4EFB30
#define CEverQuest__GetRaceDesc                                    0x4EFE20
#define CEverQuest__InterpretCmd                                   0x4F9710
#define CEverQuest__LeftClickedOnPlayer                            0x50B980
#define CEverQuest__LMouseUp                                       0x50F0A0
#define CEverQuest__RightClickedOnPlayer                           0x510260
#define CEverQuest__RMouseUp                                       0x511240
#define CEverQuest__SetGameState                                   0x4F2E30
#define CEverQuest__Emote                                          0x4F8E20

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x61FB40
#define CGaugeWnd__CalcLinesFillRect                               0x61FBA0
#define CGaugeWnd__Draw                                            0x61FFF0

// CGuild
#define CGuild__FindMemberByName                                   0x41CE60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x63A070

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x644390
#define CInvSlotMgr__MoveItem                                      0x645040

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x643A20
#define CInvSlot__SliderComplete                                   0x641DE0
#define CInvSlot__GetItemBase                                      0x641460

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x645E00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6F67D0
#define CItemDisplayWnd__UpdateStrings                             0x646E50

// CLabel 
#define CLabel__Draw                                               0x65E0D0

// CListWnd 
#define CListWnd__AddColumn                                        0x7C1900
#define CListWnd__AddColumn1                                       0x7C0F80
#define CListWnd__AddLine                                          0x7C0AE0
#define CListWnd__AddString                                        0x7C0C80
#define CListWnd__CalculateFirstVisibleLine                        0x7BCD50
#define CListWnd__CalculateVSBRange                                0x7BF150
#define CListWnd__ClearAllSel                                      0x7BC2A0
#define CListWnd__CloseAndUpdateEditWindow                         0x7C0150
#define CListWnd__Compare                                          0x7BD7F0
#define CListWnd__Draw                                             0x7BED90
#define CListWnd__DrawColumnSeparators                             0x7BEC20
#define CListWnd__DrawHeader                                       0x7BC530
#define CListWnd__DrawItem                                         0x7BE1F0
#define CListWnd__DrawLine                                         0x7BE8E0
#define CListWnd__DrawSeparator                                    0x7BECC0
#define CListWnd__EnsureVisible                                    0x7BCEB0
#define CListWnd__ExtendSel                                        0x7BE110
#define CListWnd__GetColumnMinWidth                                0x7BBF70
#define CListWnd__GetColumnWidth                                   0x7BBEB0
#define CListWnd__GetCurSel                                        0x7BB670
#define CListWnd__GetHeaderRect                                    0x7BB7D0
#define CListWnd__GetItemAtPoint                                   0x7BD180
#define CListWnd__GetItemAtPoint1                                  0x7BD1F0
#define CListWnd__GetItemData                                      0x7BBAB0
#define CListWnd__GetItemHeight                                    0x7BC9C0
#define CListWnd__GetItemIcon                                      0x7BBC90
#define CListWnd__GetItemRect                                      0x7BCF80
#define CListWnd__GetItemText                                      0x7BBB40
#define CListWnd__GetSelList                                       0x7C0E60
#define CListWnd__GetSeparatorRect                                 0x7BD740
#define CListWnd__RemoveLine                                       0x7C0E10
#define CListWnd__SetColors                                        0x7BB740
#define CListWnd__SetColumnJustification                           0x7BC110
#define CListWnd__SetColumnWidth                                   0x7BBF30
#define CListWnd__SetCurSel                                        0x7BB6B0
#define CListWnd__SetItemColor                                     0x7BFE00
#define CListWnd__SetItemData                                      0x7BC340
#define CListWnd__SetItemText                                      0x7BFC30
#define CListWnd__ShiftColumnSeparator                             0x7BFAA0
#define CListWnd__Sort                                             0x7C2060
#define CListWnd__ToggleSel                                        0x7BC210

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x676B90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x692090
#define CMerchantWnd__RequestBuyItem                               0x698230
#define CMerchantWnd__RequestSellItem                              0x6BA7E0
#define CMerchantWnd__SelectBuySellSlot                            0x692340

// CObfuscator
#define CObfuscator__doit                                          0x742690

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7DDF80
#define CSidlManager__CreateLabel                                  0x6EE2D0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5DCCA0
#define CSidlScreenWnd__CalculateVSBRange                          0x5DCBC0
#define CSidlScreenWnd__ConvertToRes                               0x7EC7E0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7CE460
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7CF6A0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7CF750
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7CEE30
#define CSidlScreenWnd__DrawSidlPiece                              0x7CDF00
#define CSidlScreenWnd__EnableIniStorage                           0x7CD6C0
#define CSidlScreenWnd__GetSidlPiece                               0x7CE120
#define CSidlScreenWnd__Init1                                      0x7CF4F0
#define CSidlScreenWnd__LoadIniInfo                                0x7CE520
#define CSidlScreenWnd__LoadIniListWnd                             0x7CD810
#define CSidlScreenWnd__LoadSidlScreen                             0x7CF090
#define CSidlScreenWnd__StoreIniInfo                               0x7CD290
#define CSidlScreenWnd__StoreIniVis                                0x7CD650
#define CSidlScreenWnd__WndNotification                            0x7CF2E0
#define CSidlScreenWnd__GetChildItem                               0x7CD720

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x582910
#define CSkillMgr__GetSkillCap                                     0x582980

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7F4960
#define CSliderWnd__SetValue                                       0x7F4A60
#define CSliderWnd__SetNumTicks                                    0x7F5010

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6F4460

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7E9C70
#define CStmlWnd__CalculateHSBRange                                0x7E11B0
#define CStmlWnd__CalculateVSBRange                                0x7E1240
#define CStmlWnd__CanBreakAtCharacter                              0x7E13C0
#define CStmlWnd__FastForwardToEndOfTag                            0x7E2100
#define CStmlWnd__ForceParseNow                                    0x7EA260
#define CStmlWnd__GetNextTagPiece                                  0x7E2020
#define CStmlWnd__GetSTMLText                                      0x608FC0
#define CStmlWnd__GetThisChar                                      0x8153C0
#define CStmlWnd__GetVisiableText                                  0x7E3580
#define CStmlWnd__InitializeWindowVariables                        0x7E5B70
#define CStmlWnd__MakeStmlColorTag                                 0x7E00B0
#define CStmlWnd__MakeWndNotificationTag                           0x7E0150
#define CStmlWnd__SetSTMLText                                      0x7E5CA0
#define CStmlWnd__StripFirstSTMLLines                              0x7E9910
#define CStmlWnd__UpdateHistoryString                              0x7E3E20

// CTabWnd 
#define CTabWnd__Draw                                              0x7F0560
#define CTabWnd__DrawCurrentPage                                   0x7EFDE0
#define CTabWnd__DrawTab                                           0x7EFBB0
#define CTabWnd__GetCurrentPage                                    0x7F01A0
#define CTabWnd__GetPageClientRect                                 0x7EF860
#define CTabWnd__GetPageFromTabIndex                               0x7EFAE0
#define CTabWnd__GetPageInnerRect                                  0x7EF8C0
#define CTabWnd__GetTabInnerRect                                   0x7EFA60
#define CTabWnd__GetTabRect                                        0x7EF950
#define CTabWnd__InsertPage                                        0x7F07F0
#define CTabWnd__SetPage                                           0x7F01E0
#define CTabWnd__SetPageRect                                       0x7F0490
#define CTabWnd__UpdatePage                                        0x7F0770

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4193C0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7CFAD0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7EDA10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7BA560

// CXRect 
#define CXRect__CenterPoint                                        0x523040

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4174B0
#define CXStr__CXStr1                                              0x6A0DF0
#define CXStr__CXStr3                                              0x8199E0
#define CXStr__dCXStr                                              0x401020
#define CXStr__operator_equal                                      0x819B50
#define CXStr__operator_equal1                                     0x819BA0
#define CXStr__operator_plus_equal1                                0x81ACB0

// CXWnd 
#define CXWnd__BringToTop                                          0x7C4DF0
#define CXWnd__Center                                              0x7CA790
#define CXWnd__ClrFocus                                            0x7C4C20
#define CXWnd__DoAllDrawing                                        0x7CA620
#define CXWnd__DrawChildren                                        0x7CA760
#define CXWnd__DrawColoredRect                                     0x7C5100
#define CXWnd__DrawTooltip                                         0x7C52F0
#define CXWnd__DrawTooltipAtPoint                                  0x7C9890
#define CXWnd__GetBorderFrame                                      0x7C5710
#define CXWnd__GetChildWndAt                                       0x7C8A80
#define CXWnd__GetClientClipRect                                   0x7C5490
#define CXWnd__GetScreenClipRect                                   0x7C9DC0
#define CXWnd__GetScreenRect                                       0x7C5840
#define CXWnd__GetTooltipRect                                      0x7C5210
#define CXWnd__GetWindowTextA                                      0x522BC0
#define CXWnd__IsActive                                            0x7D0C10
#define CXWnd__IsDescendantOf                                      0x7C5600
#define CXWnd__IsReallyVisible                                     0x7C8A60
#define CXWnd__IsType                                              0x7F1E60
#define CXWnd__Move                                                0x7C81D0
#define CXWnd__Move1                                               0x7CA2F0
#define CXWnd__ProcessTransition                                   0x7C4DA0
#define CXWnd__Refade                                              0x7C4D20
#define CXWnd__Resize                                              0x7C5910
#define CXWnd__Right                                               0x7C9CD0
#define CXWnd__SetFocus                                            0x7C7340
#define CXWnd__SetKeyTooltip                                       0x7C5B60
#define CXWnd__SetMouseOver                                        0x7CA0E0
#define CXWnd__StartFade                                           0x7C4E20
#define CXWnd__GetChildItem                                        0x7CA020

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7D2170
#define CXWndManager__DrawWindows                                  0x7D1DF0
#define CXWndManager__GetKeyboardFlags                             0x7D0860
#define CXWndManager__HandleKeyboardMsg                            0x7D0EE0
#define CXWndManager__RemoveWnd                                    0x7D0D30

// CDBStr
#define CDBStr__GetString                                          0x4716E0

// EQ_Character 
#define EQ_Character__CastRay                                      0x75C4A0
#define EQ_Character__CastSpell                                    0x433240
#define EQ_Character__Cur_HP                                       0x43CB90
#define EQ_Character__GetAACastingTimeModifier                     0x427E10
#define EQ_Character__GetCharInfo2                                 0x75A720
#define EQ_Character__GetFocusCastingTimeModifier                  0x422AF0
#define EQ_Character__GetFocusRangeModifier                        0x422CC0
#define EQ_Character__Max_Endurance                                0x54EFF0
#define EQ_Character__Max_HP                                       0x437240
#define EQ_Character__Max_Mana                                     0x54EDF0
#define EQ_Character__doCombatAbility                              0x54DBE0
#define EQ_Character__UseSkill                                     0x44C740
#define EQ_Character__GetConLevel                                  0x547050
#define EQ_Character__IsExpansionFlag                              0x40DD20
#define EQ_Character__TotalEffect                                  0x42C6A0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5286F0
#define EQ_Item__CreateItemTagString                               0x740730
#define EQ_Item__IsStackable                                       0x734980

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x48B550
#define EQ_LoadingS__Array                                         0x9CEA50

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x552C10
#define EQ_PC__GetAltAbilityIndex                                  0x74BAD0
#define EQ_PC__GetCombatAbility                                    0x74BB60
#define EQ_PC__GetCombatAbilityTimer                               0x74BC10
#define EQ_PC__GetItemTimerValue                                   0x54D950
#define EQ_PC__HasLoreItem                                         0x54C410

// EQItemList 
#define EQItemList__EQItemList                                     0x4BB400
#define EQItemList__add_item                                       0x4BB390
#define EQItemList__delete_item                                    0x4BB7B0
#define EQItemList__FreeItemList                                   0x4BB6E0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x470CB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x557DB0
#define EQPlayer__dEQPlayer                                        0x55CA30
#define EQPlayer__DoAttack                                         0x56EC80
#define EQPlayer__EQPlayer                                         0x562D80
#define EQPlayer__SetNameSpriteState                               0x55A290
#define EQPlayer__SetNameSpriteTint                                0x557E20
#define EQPlayer__IsBodyType_j                                     0x75BD40
#define EQPlayer__IsTargetable                                     0x75C010

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x564320
#define EQPlayerManager__GetSpawnByName                            0x564610

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52E170
#define KeypressHandler__AttachKeyToEqCommand                      0x52E1B0
#define KeypressHandler__ClearCommandStateArray                    0x52DF80
#define KeypressHandler__HandleKeyDown                             0x52C910
#define KeypressHandler__HandleKeyUp                               0x52CC20
#define KeypressHandler__SaveKeymapping                            0x52E050

// MapViewMap 
#define MapViewMap__Clear                                          0x66FDE0
#define MapViewMap__SaveEx                                         0x673490

#define PlayerPointManager__GetAltCurrency                         0x746060

// StringTable 
#define StringTable__getString                                     0x742910

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x551320
