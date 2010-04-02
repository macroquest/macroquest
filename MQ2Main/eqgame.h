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
#define __ExpectedVersionDate                                     "Apr 16 2008"
#define __ExpectedVersionTime                                     "17:57:58"
#define __ActualVersionDate                                        0x71A354
#define __ActualVersionTime                                        0x71A360

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FB950
#define __MemChecker1                                              0x665310
#define __MemChecker2                                              0x530100
#define __MemChecker3                                              0x530050
#define __MemChecker4                                              0x629680
#define __EncryptPad0                                              0x775120
#define __EncryptPad1                                              0x77EEB8
#define __EncryptPad2                                              0x777A98
#define __EncryptPad3                                              0x777698
#define __EncryptPad4                                              0x77E598

// Direct Input
#define DI8__Main                                                  0x9BD4BC
#define DI8__Keyboard                                              0x9BD4C0
#define DI8__Mouse                                                 0x9BD4C4
#define __AltTimerReady                                            0x94A23A
#define __Attack                                                   0x9A7B7E
#define __Autofire                                                 0x9A7B7F
#define __BindList                                                 0x7702C8
#define __Clicks                                                   0x948F58
#define __CommandList                                              0x770AD8
#define __CurrentMapLabel                                          0x9E86D8
#define __CurrentSocial                                            0x76C544
#define __DoAbilityAvailable                                       0x94A1D4
#define __DoAbilityList                                            0x97F69C
#define __do_loot                                                  0x4A55F0
#define __DrawHandler                                              0x9F79B4
#define __GroupCount                                               0x92946A
#define __GroupLeader                                              0x9297BC
#define __Guilds                                                   0x92B188
#define __gWorld                                                   0x92B0C4
#define __HotkeyPage                                               0x9A6A88
#define __HWnd                                                     0x9BD1FC
#define __InChatMode                                               0x948E90
#define __LastTell                                                 0x94AB34
#define __LMouseHeldTime                                           0x948F78
#define __Mouse                                                    0x9BD4C8
#define __MouseLook                                                0x948F26
#define __NetStatusToggle                                          0x948F28
#define __PCNames                                                  0x94A58C
#define __RangeAttackReady                                         0x94A238
#define __RMouseHeldTime                                           0x948F74
#define __RunWalkState                                             0x948E94
#define __ScreenMode                                               0x878DD0
#define __ScreenX                                                  0x948E48
#define __ScreenY                                                  0x948E4C
#define __ScreenXMax                                               0x948E50
#define __ScreenYMax                                               0x948E54
#define __ServerHost                                               0x9293B4
#define __ServerName                                               0x97F65C
#define __ShiftKeyDown                                             0x9494F0
#define __ShowNames                                                0x94A464
#define __Socials                                                  0x97F75C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x942DD8
#define instEQZoneInfo                                             0x9490C4
#define instKeypressHandler                                        0x9A7C68
#define pinstActiveBanker                                          0x92B15C
#define pinstActiveCorpse                                          0x92B160
#define pinstActiveGMaster                                         0x92B164
#define pinstActiveMerchant                                        0x92B158
#define pinstAltAdvManager                                         0x879C20
#define pinstAuraMgr                                               0x784C6C
#define pinstBandageTarget                                         0x92B144
#define pinstCamActor                                              0x879710
#define pinstCDBStr                                                0x878DC0
#define pinstCDisplay                                              0x92B16C
#define pinstCEverQuest                                            0x9BD640
#define pinstCharData                                              0x92B128
#define pinstCharSpawn                                             0x92B150
#define pinstControlledMissile                                     0x92B124
#define pinstControlledPlayer                                      0x92B150
#define pinstCSidlManager                                          0x9F7180
#define pinstCXWndManager                                          0x9F7178
#define instDynamicZone                                            0x948898
#define pinstDZMember                                              0x9489A8
#define pinstDZTimerInfo                                           0x9489AC
#define pinstEQItemList                                            0x92B10C
#define instEQMisc                                                 0x878D78
#define pinstEQSoundManager                                        0x879C44
#define instExpeditionLeader                                       0x9488E2
#define instExpeditionName                                         0x948922
#define instGroup                                                  0x929660
#define pinstGroup                                                 0x929466
#define pinstImeManager                                            0x9F7184
#define pinstLocalPlayer                                           0x92B13C
#define pinstModelPlayer                                           0x92B168
#define pinstPCData                                                0x92B128
#define pinstSkillMgr                                              0x9BA42C
#define pinstSpawnManager                                          0x9BA3AC
#define pinstSpellManager                                          0x9BA430
#define pinstSpellSets                                             0x9A6A8C
#define pinstStringTable                                           0x92B0E0
#define pinstSwitchManager                                         0x9290B4
#define pinstTarget                                                0x92B154
#define pinstTargetObject                                          0x92B12C
#define pinstTargetSwitch                                          0x92B130
#define pinstTaskMember                                            0x878D58
#define pinstTrackTarget                                           0x92B148
#define pinstTradeTarget                                           0x92B138
#define instTributeActive                                          0x878D9D
#define pinstViewActor                                             0x87970C
#define pinstWorldData                                             0x92B108


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x782520
#define pinstCAudioTriggersWindow                                  0x7824EC
#define pinstCCharacterSelect                                      0x879620
#define pinstCFacePick                                             0x8795D8
#define pinstCNoteWnd                                              0x8795DC
#define pinstCBookWnd                                              0x8795E0
#define pinstCPetInfoWnd                                           0x8795E4
#define pinstCTrainWnd                                             0x8795E8
#define pinstCSkillsWnd                                            0x8795EC
#define pinstCSkillsSelectWnd                                      0x8795F0
#define pinstCCombatSkillSelectWnd                                 0x8795F4
#define pinstCFriendsWnd                                           0x8795F8
#define pinstCAuraWnd                                              0x8795FC
#define pinstCRespawnWnd                                           0x879600
#define pinstCBandolierWnd                                         0x879604
#define pinstCPotionBeltWnd                                        0x879608
#define pinstCAAWnd                                                0x87960C
#define pinstCGroupSearchFiltersWnd                                0x879610
#define pinstCLoadskinWnd                                          0x879614
#define pinstCAlarmWnd                                             0x879618
#define pinstCMusicPlayerWnd                                       0x87961C
#define pinstCMailWnd                                              0x879624
#define pinstCMailCompositionWnd                                   0x879628
#define pinstCMailAddressBookWnd                                   0x87962C
#define pinstCRaidWnd                                              0x879634
#define pinstCRaidOptionsWnd                                       0x879638
#define pinstCBreathWnd                                            0x87963C
#define pinstCMapViewWnd                                           0x879640
#define pinstCMapToolbarWnd                                        0x879644
#define pinstCEditLabelWnd                                         0x879648
#define pinstCTargetWnd                                            0x87964C
#define pinstCColorPickerWnd                                       0x879650
#define pinstCPlayerWnd                                            0x879654
#define pinstCOptionsWnd                                           0x879658
#define pinstCBuffWindowNORMAL                                     0x87965C
#define pinstCBuffWindowSHORT                                      0x879660
#define pinstCharacterCreation                                     0x879664
#define pinstCCursorAttachment                                     0x879668
#define pinstCCastingWnd                                           0x87966C
#define pinstCCastSpellWnd                                         0x879670
#define pinstCSpellBookWnd                                         0x879674
#define pinstCInventoryWnd                                         0x879678
#define pinstCBankWnd                                              0x87967C
#define pinstCQuantityWnd                                          0x879680
#define pinstCLootWnd                                              0x879684
#define pinstCActionsWnd                                           0x879688
#define pinstCCombatAbilityWnd                                     0x87968C
#define pinstCMerchantWnd                                          0x879690
#define pinstCTradeWnd                                             0x879694
#define pinstCSelectorWnd                                          0x879698
#define pinstCBazaarWnd                                            0x87969C
#define pinstCBazaarSearchWnd                                      0x8796A0
#define pinstCGiveWnd                                              0x8796A4
#define pinstCTrackingWnd                                          0x8796A8
#define pinstCInspectWnd                                           0x8796AC
#define pinstCSocialEditWnd                                        0x8796B0
#define pinstCFeedbackWnd                                          0x8796B4
#define pinstCBugReportWnd                                         0x8796B8
#define pinstCVideoModesWnd                                        0x8796BC
#define pinstCTextEntryWnd                                         0x8796C4
#define pinstCFileSelectionWnd                                     0x8796C8
#define pinstCCompassWnd                                           0x8796CC
#define pinstCPlayerNotesWnd                                       0x8796D0
#define pinstCGemsGameWnd                                          0x8796D4
#define pinstCTimeLeftWnd                                          0x8796D8
#define pinstCPetitionQWnd                                         0x8796DC
#define pinstCSoulmarkWnd                                          0x8796E0
#define pinstCStoryWnd                                             0x8796E4
#define pinstCJournalTextWnd                                       0x8796E8
#define pinstCJournalCatWnd                                        0x8796EC
#define pinstCBodyTintWnd                                          0x8796F0
#define pinstCServerListWnd                                        0x8796F4
#define pinstCAvaZoneWnd                                           0x8796F8
#define pinstCBlockedBuffWnd                                       0x8796FC
#define pinstCBlockedPetBuffWnd                                    0x879700
#define pinstCInvSlotMgr                                           0x879704
#define pinstCContainerMgr                                         0x879708
#define pinstCAdventureLeaderboardWnd                              0x9E5C28
#define pinstCAdventureRequestWnd                                  0x9E5C44
#define pinstCAltStorageWnd                                        0x9E5CA4
#define pinstCAdventureStatsWnd                                    0x9E5C60
#define pinstCBarterMerchantWnd                                    0x9E5E70
#define pinstCBarterSearchWnd                                      0x9E5E8C
#define pinstCBarterWnd                                            0x9E5EA8
#define pinstCChatManager                                          0x9E614C
#define pinstCDynamicZoneWnd                                       0x9E6244
#define pinstCEQMainWnd                                            0x9E6330
#define pinstCFellowshipWnd                                        0x9E6318
#define pinstCFindLocationWnd                                      0x9E634C
#define pinstCGroupSearchWnd                                       0x9E63FC
#define pinstCGroupWnd                                             0x9E6418
#define pinstCGuildBankWnd                                         0x9E6434
#define pinstCGuildMgmtWnd                                         0x9E8450
#define pinstCGuildTributeMasterWnd                                0x9E8470
#define pinstCHotButtonWnd                                         0x9E848C
#define pinstCHotButtonWnd1                                        0x9E848C
#define pinstCHotButtonWnd2                                        0x9E8490
#define pinstCHotButtonWnd3                                        0x9E8494
#define pinstCHotButtonWnd4                                        0x9E8498
#define pinstCItemDisplayManager                                   0x9E8544
#define pinstCItemExpTransferWnd                                   0x9E8564
#define pinstCLeadershipWnd                                        0x9E8600
#define pinstCLFGuildWnd                                           0x9E861C
#define pinstCMIZoneSelectWnd                                      0x9E8740
#define pinstCAdventureMerchantWnd                                 0x9E8838
#define pinstCConfirmationDialog                                   0x9E8854
#define pinstCPopupWndManager                                      0x9E8854
#define pinstCProgressionSelectionWnd                              0x9E8888
#define pinstCPvPLeaderboardWnd                                    0x9E88A4
#define pinstCPvPStatsWnd                                          0x9E88C0
#define pinstCSystemInfoDialogBox                                  0x9E8970
#define pinstCTargetOfTargetWnd                                    0x9E9264
#define pinstCTaskSelectWnd                                        0x9E9280
#define pinstCTaskTemplateSelectWnd                                0x9E929C
#define pinstCTaskWnd                                              0x9E92B8
#define pinstCTipWndOFDAY                                          0x9E9334
#define pinstCTipWndCONTEXT                                        0x9E9338
#define pinstCTitleWnd                                             0x9E9354
#define pinstCTradeskillWnd                                        0x9E9398
#define pinstCTributeBenefitWnd                                    0x9E93E4
#define pinstCTributeMasterWnd                                     0x9E9400
#define pinstCContextMenuManager                                   0x9F71DC
#define pinstCVoiceMacroWnd                                        0x9BA51C
#define pinstCHtmlWnd                                              0x9BA538


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B7680
#define __ConvertItemTags                                          0x4AA970
#define __ExecuteCmd                                               0x499EA0
#define __get_melee_range                                          0x49F060
#define __GetGaugeValueFromEQ                                      0x5FB080
#define __GetLabelFromEQ                                           0x5FB880
#define __NewUIINI                                                 0x5FAC70
#define __ProcessGameEvents                                        0x4E6D60
#define CrashDetected                                              0x52EDD0
#define DrawNetStatus                                              0x4FE740
#define Util__FastTime                                             0x665A20


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x4736F0
#define AltAdvManager__IsAbilityReady                              0x473730
#define AltAdvManager__GetAltAbility                               0x473910

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5462A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54F3E0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6912C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x564520
#define CChatManager__InitContextMenu                              0x564CB0

// CChatService
#define CChatService__GetNumberOfFriends                           0x655B80
#define CChatService__GetFriendName                                0x655B90

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x568E20
#define CChatWindow__WndNotification                               0x569810

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6776A0
#define CComboWnd__Draw                                            0x677850
#define CComboWnd__GetCurChoice                                    0x677640
#define CComboWnd__GetListRect                                     0x677B10
#define CComboWnd__GetTextRect                                     0x6776D0
#define CComboWnd__InsertChoice                                    0x677B80
#define CComboWnd__SetColors                                       0x6775D0
#define CComboWnd__SetChoice                                       0x677600

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x570110
#define CContainerWnd__vftable                                     0x720C90

// CDisplay 
#define CDisplay__CleanGameUI                                      0x462880
#define CDisplay__GetClickedActor                                  0x45FFC0
#define CDisplay__GetUserDefinedColor                              0x45F140
#define CDisplay__GetWorldFilePath                                 0x45E6B0
#define CDisplay__is3dON                                           0x45D810
#define CDisplay__ReloadUI                                         0x46E3F0
#define CDisplay__WriteTextHD2                                     0x462F70

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x540320
#define CEditBaseWnd__SetSel                                       0x69C260

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x685520
#define CEditWnd__GetCharIndexPt                                   0x686380
#define CEditWnd__GetDisplayString                                 0x6856C0
#define CEditWnd__GetHorzOffset                                    0x685950
#define CEditWnd__GetLineForPrintableChar                          0x685E30
#define CEditWnd__GetSelStartPt                                    0x6865C0
#define CEditWnd__GetSTMLSafeText                                  0x685AF0
#define CEditWnd__PointFromPrintableChar                           0x685F40
#define CEditWnd__SelectableCharFromPoint                          0x6860C0
#define CEditWnd__SetEditable                                      0x685AC0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4CAEA0
#define CEverQuest__DropHeldItemOnGround                           0x4CF110
#define CEverQuest__dsp_chat                                       0x4D05F0
#define CEverQuest__DoTellWindow                                   0x4CF290
#define CEverQuest__EnterZone                                      0x4E5740
#define CEverQuest__GetBodyTypeDesc                                0x4C8320
#define CEverQuest__GetClassDesc                                   0x4C7A80
#define CEverQuest__GetClassThreeLetterCode                        0x4C8080
#define CEverQuest__GetDeityDesc                                   0x4C8990
#define CEverQuest__GetLangDesc                                    0x4C86B0
#define CEverQuest__GetRaceDesc                                    0x4C8960
#define CEverQuest__InterpretCmd                                   0x4D1020
#define CEverQuest__LeftClickedOnPlayer                            0x4E3F60
#define CEverQuest__LMouseUp                                       0x4E6540
#define CEverQuest__RightClickedOnPlayer                           0x4E4330
#define CEverQuest__RMouseUp                                       0x4E5D40
#define CEverQuest__SetGameState                                   0x4CB320
#define CEverQuest__Emote                                          0x4D07C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x57C4B0
#define CGaugeWnd__CalcLinesFillRect                               0x57C520
#define CGaugeWnd__Draw                                            0x57C8A0

// CGuild
#define CGuild__FindMemberByName                                   0x417AA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x592DA0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x59C1A0
#define CInvSlotMgr__MoveItem                                      0x59C340

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x59AB80
#define CInvSlot__SliderComplete                                   0x59B090

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5AB270
#define CItemDisplayWnd__SetSpell                                  0x5F8FA0

// CLabel 
#define CLabel__Draw                                               0x5B0AB0

// CListWnd 
#define CListWnd__AddColumn                                        0x6773E0
#define CListWnd__AddColumn1                                       0x676F20
#define CListWnd__AddLine                                          0x676AB0
#define CListWnd__AddString                                        0x676C80
#define CListWnd__CalculateFirstVisibleLine                        0x673E70
#define CListWnd__CalculateVSBRange                                0x675A80
#define CListWnd__ClearAllSel                                      0x6735C0
#define CListWnd__CloseAndUpdateEditWindow                         0x674470
#define CListWnd__Compare                                          0x674800
#define CListWnd__Draw                                             0x675780
#define CListWnd__DrawColumnSeparators                             0x6755F0
#define CListWnd__DrawHeader                                       0x673790
#define CListWnd__DrawItem                                         0x674F00
#define CListWnd__DrawLine                                         0x6752A0
#define CListWnd__DrawSeparator                                    0x675690
#define CListWnd__EnsureVisible                                    0x673EC0
#define CListWnd__ExtendSel                                        0x674E30
#define CListWnd__GetColumnMinWidth                                0x673360
#define CListWnd__GetColumnWidth                                   0x6732A0
#define CListWnd__GetCurSel                                        0x672D70
#define CListWnd__GetHeaderRect                                    0x672E70
#define CListWnd__GetItemAtPoint                                   0x674190
#define CListWnd__GetItemAtPoint1                                  0x674200
#define CListWnd__GetItemData                                      0x673050
#define CListWnd__GetItemHeight                                    0x673C00
#define CListWnd__GetItemIcon                                      0x6731E0
#define CListWnd__GetItemRect                                      0x673F80
#define CListWnd__GetItemText                                      0x673090
#define CListWnd__GetSelList                                       0x676E00
#define CListWnd__GetSeparatorRect                                 0x674740
#define CListWnd__RemoveLine                                       0x676DB0
#define CListWnd__SetColors                                        0x672DD0
#define CListWnd__SetColumnJustification                           0x6733C0
#define CListWnd__SetColumnWidth                                   0x673320
#define CListWnd__SetCurSel                                        0x672DB0
#define CListWnd__SetItemColor                                     0x676680
#define CListWnd__SetItemData                                      0x673660
#define CListWnd__SetItemText                                      0x676600
#define CListWnd__ShiftColumnSeparator                             0x674DA0
#define CListWnd__Sort                                             0x677410
#define CListWnd__ToggleSel                                        0x673530

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C57C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C72A0
#define CMerchantWnd__RequestBuyItem                               0x5C85D0
#define CMerchantWnd__RequestSellItem                              0x5C74F0
#define CMerchantWnd__SelectBuySellSlot                            0x5C8300

// CObfuscator
#define CObfuscator__doit                                          0x63CAE0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x68CF70
#define CSidlManager__CreateLabel                                  0x5F2470

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x541D50
#define CSidlScreenWnd__CalculateVSBRange                          0x67D2F0
#define CSidlScreenWnd__ConvertToRes                               0x69C140
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x67EC10
#define CSidlScreenWnd__CSidlScreenWnd1                            0x67FA50
#define CSidlScreenWnd__CSidlScreenWnd2                            0x67FB00
#define CSidlScreenWnd__dCSidlScreenWnd                            0x67F4A0
#define CSidlScreenWnd__DrawSidlPiece                              0x67E8F0
#define CSidlScreenWnd__EnableIniStorage                           0x67E400
#define CSidlScreenWnd__GetSidlPiece                               0x67EAF0
#define CSidlScreenWnd__Init1                                      0x67F8C0
#define CSidlScreenWnd__LoadIniInfo                                0x67ECC0
#define CSidlScreenWnd__LoadIniListWnd                             0x67E550
#define CSidlScreenWnd__LoadSidlScreen                             0x67E710
#define CSidlScreenWnd__StoreIniInfo                               0x67E010
#define CSidlScreenWnd__WndNotification                            0x67E850

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51FC20

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x69CE60
#define CSliderWnd__SetValue                                       0x69CF60
#define CSliderWnd__SetNumTicks                                    0x69D4D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F7C40

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x69A3F0
#define CStmlWnd__CalculateVSBRange                                0x675A80
#define CStmlWnd__CanBreakAtCharacter                              0x692900
#define CStmlWnd__FastForwardToEndOfTag                            0x693400
#define CStmlWnd__ForceParseNow                                    0x69A840
#define CStmlWnd__GetNextTagPiece                                  0x693320
#define CStmlWnd__GetSTMLText                                      0x568DC0
#define CStmlWnd__GetThisChar                                      0x6BA830
#define CStmlWnd__GetVisiableText                                  0x694620
#define CStmlWnd__InitializeWindowVariables                        0x696760
#define CStmlWnd__MakeStmlColorTag                                 0x691EC0
#define CStmlWnd__MakeWndNotificationTag                           0x691F60
#define CStmlWnd__SetSTMLText                                      0x696870
#define CStmlWnd__StripFirstSTMLLines                              0x69A180
#define CStmlWnd__UpdateHistoryString                              0x694E80

// CTabWnd 
#define CTabWnd__Draw                                              0x69E250
#define CTabWnd__DrawCurrentPage                                   0x69DC70
#define CTabWnd__DrawTab                                           0x69DA50
#define CTabWnd__GetCurrentPage                                    0x69DEF0
#define CTabWnd__GetPageClientRect                                 0x69D720
#define CTabWnd__GetPageFromTabIndex                               0x69D980
#define CTabWnd__GetPageInnerRect                                  0x69D780
#define CTabWnd__GetTabInnerRect                                   0x69D900
#define CTabWnd__GetTabRect                                        0x69D810
#define CTabWnd__IndexInBounds                                     0x69DA1D
#define CTabWnd__InsertPage                                        0x69E470
#define CTabWnd__SetPage                                           0x69DF30
#define CTabWnd__SetPageRect                                       0x69E180
#define CTabWnd__UpdatePage                                        0x69E3F0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x413F90

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x67FE60

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6A3960

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x672AE0

// CXRect 
#define CXRect__CenterPoint                                        0x545A00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4123E0
#define CXStr__CXStr1                                              0x66DAC0
#define CXStr__CXStr3                                              0x667170
#define CXStr__dCXStr                                              0x403580
#define CXStr__operator_equal1                                     0x667330
#define CXStr__operator_plus_equal1                                0x668230

// CXWnd 
#define CXWnd__BringToTop                                          0x678410
#define CXWnd__Center                                              0x67C0D0
#define CXWnd__ClrFocus                                            0x6780F0
#define CXWnd__DoAllDrawing                                        0x67CBC0
#define CXWnd__DrawChildren                                        0x67CCF0
#define CXWnd__DrawColoredRect                                     0x6786A0
#define CXWnd__DrawTooltip                                         0x67CAE0
#define CXWnd__DrawTooltipAtPoint                                  0x67BEA0
#define CXWnd__GetBorderFrame                                      0x678B60
#define CXWnd__GetChildWndAt                                       0x67B940
#define CXWnd__GetClientClipRect                                   0x678A90
#define CXWnd__GetFirstChildWnd                                    0x6784C0
#define CXWnd__GetNextChildWnd                                     0x67B900
#define CXWnd__GetNextSib                                          0x6784E0
#define CXWnd__GetScreenClipRect                                   0x67C2F0
#define CXWnd__GetScreenRect                                       0x678D20
#define CXWnd__GetTooltipRect                                      0x6788C0
#define CXWnd__GetWindowTextA                                      0x539400
#define CXWnd__IsActive                                            0x680F60
#define CXWnd__IsDescendantOf                                      0x678B10
#define CXWnd__IsReallyVisible                                     0x67B8E0
#define CXWnd__IsType                                              0x69F350
#define CXWnd__Move                                                0x67B390
#define CXWnd__Move1                                               0x67B430
#define CXWnd__ProcessTransition                                   0x6783D0
#define CXWnd__Refade                                              0x6781A0
#define CXWnd__Resize                                              0x678DF0
#define CXWnd__Right                                               0x67C230
#define CXWnd__SetFirstChildPointer                                0x678FD0
#define CXWnd__SetFocus                                            0x67A400
#define CXWnd__SetKeyTooltip                                       0x679040
#define CXWnd__SetMouseOver                                        0x679010
#define CXWnd__SetNextSibPointer                                   0x678FF0
#define CXWnd__StartFade                                           0x678430

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x682450
#define CXWndManager__DrawWindows                                  0x682090
#define CXWndManager__GetFirstChildWnd                             0x681900
#define CXWndManager__GetKeyboardFlags                             0x680C20
#define CXWndManager__HandleKeyboardMsg                            0x681150
#define CXWndManager__RemoveWnd                                    0x681070

// CDBStr
#define CDBStr__GetString                                          0x45C180

// EQ_Character 
#define EQ_Character__CastRay                                      0x6C6730
#define EQ_Character__CastSpell                                    0x424FA0
#define EQ_Character__Cur_HP                                       0x431730
#define EQ_Character__GetAACastingTimeModifier                     0x41F980
#define EQ_Character__GetCharInfo2                                 0x647FD0
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B5B0
#define EQ_Character__GetFocusRangeModifier                        0x41B6E0
#define EQ_Character__Max_Endurance                                0x42CD30
#define EQ_Character__Max_HP                                       0x42CBB0
#define EQ_Character__Max_Mana                                     0x504870
#define EQ_Character__doCombatAbility                              0x503530
#define EQ_Character__UseSkill                                     0x437820
#define EQ_Character__GetConLevel                                  0x4FFC20

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F37B0
#define EQ_Item__GetItemLinkHash                                   0x63C190
#define EQ_Item__IsStackable                                       0x633060

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4747D0
#define EQ_LoadingS__Array                                         0x76E7D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x5078B0
#define EQ_PC__GetAltAbilityIndex                                  0x640CF0
#define EQ_PC__GetCombatAbility                                    0x640D80
#define EQ_PC__GetCombatAbilityTimer                               0x640E30
#define EQ_PC__GetItemTimerValue                                   0x502480
#define EQ_PC__HasLoreItem                                         0x505D10

// EQItemList 
#define EQItemList__dEQItemList                                    0x49D790
#define EQItemList__EQItemList                                     0x49D6E0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45BAF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50C070
#define EQPlayer__dEQPlayer                                        0x510950
#define EQPlayer__DoAttack                                         0x51C740
#define EQPlayer__EQPlayer                                         0x513630
#define EQPlayer__SetNameSpriteState                               0x50E890
#define EQPlayer__SetNameSpriteTint                                0x50C0E0
#define EQPlayer__IsBodyType_j                                     0x6C6100

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5146A0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F53C0
#define KeypressHandler__AttachKeyToEqCommand                      0x4F5400
#define KeypressHandler__ClearCommandStateArray                    0x4F51D0
#define KeypressHandler__HandleKeyDown                             0x4F3DB0
#define KeypressHandler__HandleKeyUp                               0x4F40B0
#define KeypressHandler__SaveKeymapping                            0x4F52A0

// MapViewMap 
#define MapViewMap__Clear                                          0x5C0EB0
#define MapViewMap__SaveEx                                         0x5C1880

#define OtherCharData__GetAltCurrency                              0x65E340

// StringTable 
#define StringTable__getString                                     0x632A30
