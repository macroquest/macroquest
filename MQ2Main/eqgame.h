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
#define __ExpectedVersionDate                                     "Mar 18 2009"
#define __ExpectedVersionTime                                     "16:30:33"
#define __ActualVersionDate                                        0x7DBF1C
#define __ActualVersionTime                                        0x7DBF28

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x50A860
#define __MemChecker1                                              0x6B42C0
#define __MemChecker2                                              0x5606D0
#define __MemChecker3                                              0x560620
#define __MemChecker4                                              0x6762E0
#define __EncryptPad0                                              0x8616B0
#define __EncryptPad1                                              0x86BD08
#define __EncryptPad2                                              0x8640F0
#define __EncryptPad3                                              0x863CF0
#define __EncryptPad4                                              0x86B3D8

// Direct Input
#define DI8__Main                                                  0xADAAA4
#define DI8__Keyboard                                              0xADAAA8
#define DI8__Mouse                                                 0xADAAAC
#define __AltTimerReady                                            0xA65562
#define __Attack                                                   0xAC5006
#define __Autofire                                                 0xAC5007
#define __BindList                                                 0x85C660
#define __Clicks                                                   0xA64278
#define __CommandList                                              0x85CEC0
#define __CurrentMapLabel                                          0xB05CE0
#define __CurrentSocial                                            0x858690
#define __DoAbilityAvailable                                       0xA654FC
#define __DoAbilityList                                            0xA9AB1C
#define __do_loot                                                  0x4B2700
#define __DrawHandler                                              0xB1514C
#define __GroupCount                                               0xA46E42
#define __Guilds                                                   0xA489C0
#define __gWorld                                                   0xA48900
#define __HotkeyPage                                               0xAC1F08
#define __HWnd                                                     0xADA7E4
#define __InChatMode                                               0xA641B0
#define __LastTell                                                 0xA65E74
#define __LMouseHeldTime                                           0xA64298
#define __Mouse                                                    0xADAAB0
#define __MouseLook                                                0xA64246
#define __MouseEventTime                                           0xAC5110
#define __NetStatusToggle                                          0xA64249
#define __PCNames                                                  0xA658B8
#define __RangeAttackReady                                         0xA65560
#define __RMouseHeldTime                                           0xA64294
#define __RunWalkState                                             0xA641B4
#define __ScreenMode                                               0x996710
#define __ScreenX                                                  0xA64168
#define __ScreenY                                                  0xA6416C
#define __ScreenXMax                                               0xA64170
#define __ScreenYMax                                               0xA64174
#define __ServerHost                                               0xA46D84
#define __ServerName                                               0xA9AADC
#define __ShiftKeyDown                                             0xA64818
#define __ShowNames                                                0xA6578C
#define __Socials                                                  0xA9ABDC


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA60610
#define instEQZoneInfo                                             0xA643E4
#define instKeypressHandler                                        0xAC50F4
#define pinstActiveBanker                                          0xA48998
#define pinstActiveCorpse                                          0xA4899C
#define pinstActiveGMaster                                         0xA489A0
#define pinstActiveMerchant                                        0xA48994
#define pinstAltAdvManager                                         0x997570
#define pinstAuraMgr                                               0x87FFD4
#define pinstBandageTarget                                         0xA48980
#define pinstCamActor                                              0x997060
#define pinstCDBStr                                                0x996700
#define pinstCDisplay                                              0xA489A8
#define pinstCEverQuest                                            0xADAC28
#define pinstCharData                                              0xA48964
#define pinstCharSpawn                                             0xA4898C
#define pinstControlledMissile                                     0xA48960
#define pinstControlledPlayer                                      0xA4898C
#define pinstCSidlManager                                          0xB148D0
#define pinstCXWndManager                                          0xB148C8
#define instDynamicZone                                            0xA63BB8
#define pinstDZMember                                              0xA63CC8
#define pinstDZTimerInfo                                           0xA63CCC
#define pinstEQItemList                                            0xA48948
#define instEQMisc                                                 0x9966B8
#define pinstEQSoundManager                                        0x997594
#define instExpeditionLeader                                       0xA63C02
#define instExpeditionName                                         0xA63C42
#define pinstGroup                                                 0xA46E3E
#define pinstImeManager                                            0xB148D4
#define pinstLocalPlayer                                           0xA48978
#define pinstModelPlayer                                           0xA489A4
#define pinstPCData                                                0xA48964
#define pinstSkillMgr                                              0xAD78FC
#define pinstSpawnManager                                          0xAD787C
#define pinstSpellManager                                          0xAD7900
#define pinstSpellSets                                             0xAC1F0C
#define pinstStringTable                                           0xA4891C
#define pinstSwitchManager                                         0xA46A84
#define pinstTarget                                                0xA48990
#define pinstTargetObject                                          0xA48968
#define pinstTargetSwitch                                          0xA4896C
#define pinstTaskMember                                            0x996698
#define pinstTrackTarget                                           0xA48984
#define pinstTradeTarget                                           0xA48974
#define instTributeActive                                          0x9966DD
#define pinstViewActor                                             0x99705C
#define pinstWorldData                                             0xA48944


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x87D880
#define pinstCAudioTriggersWindow                                  0x87D84C
#define pinstCCharacterSelect                                      0x996F6C
#define pinstCFacePick                                             0x996F20
#define pinstCNoteWnd                                              0x996F24
#define pinstCBookWnd                                              0x996F28
#define pinstCPetInfoWnd                                           0x996F2C
#define pinstCTrainWnd                                             0x996F30
#define pinstCSkillsWnd                                            0x996F34
#define pinstCSkillsSelectWnd                                      0x996F38
#define pinstCCombatSkillSelectWnd                                 0x996F3C
#define pinstCFriendsWnd                                           0x996F40
#define pinstCAuraWnd                                              0x996F44
#define pinstCRespawnWnd                                           0x996F48
#define pinstCBandolierWnd                                         0x996F4C
#define pinstCPotionBeltWnd                                        0x996F50
#define pinstCAAWnd                                                0x996F54
#define pinstCGroupSearchFiltersWnd                                0x996F58
#define pinstCLoadskinWnd                                          0x996F5C
#define pinstCAlarmWnd                                             0x996F60
#define pinstCMusicPlayerWnd                                       0x996F64
#define pinstCMailWnd                                              0x996F70
#define pinstCMailCompositionWnd                                   0x996F74
#define pinstCMailAddressBookWnd                                   0x996F78
#define pinstCRaidWnd                                              0x996F80
#define pinstCRaidOptionsWnd                                       0x996F84
#define pinstCBreathWnd                                            0x996F88
#define pinstCMapViewWnd                                           0x996F8C
#define pinstCMapToolbarWnd                                        0x996F90
#define pinstCEditLabelWnd                                         0x996F94
#define pinstCTargetWnd                                            0x996F98
#define pinstCColorPickerWnd                                       0x996F9C
#define pinstCPlayerWnd                                            0x996FA0
#define pinstCOptionsWnd                                           0x996FA4
#define pinstCBuffWindowNORMAL                                     0x996FA8
#define pinstCBuffWindowSHORT                                      0x996FAC
#define pinstCharacterCreation                                     0x996FB0
#define pinstCCursorAttachment                                     0x996FB4
#define pinstCCastingWnd                                           0x996FB8
#define pinstCCastSpellWnd                                         0x996FBC
#define pinstCSpellBookWnd                                         0x996FC0
#define pinstCInventoryWnd                                         0x996FC4
#define pinstCBankWnd                                              0x996FC8
#define pinstCQuantityWnd                                          0x996FCC
#define pinstCLootWnd                                              0x996FD0
#define pinstCActionsWnd                                           0x996FD4
#define pinstCCombatAbilityWnd                                     0x996FD8
#define pinstCMerchantWnd                                          0x996FDC
#define pinstCTradeWnd                                             0x996FE0
#define pinstCSelectorWnd                                          0x996FE4
#define pinstCBazaarWnd                                            0x996FE8
#define pinstCBazaarSearchWnd                                      0x996FEC
#define pinstCGiveWnd                                              0x996FF0
#define pinstCTrackingWnd                                          0x996FF4
#define pinstCInspectWnd                                           0x996FF8
#define pinstCSocialEditWnd                                        0x996FFC
#define pinstCFeedbackWnd                                          0x997000
#define pinstCBugReportWnd                                         0x997004
#define pinstCVideoModesWnd                                        0x997008
#define pinstCTextEntryWnd                                         0x997010
#define pinstCFileSelectionWnd                                     0x997014
#define pinstCCompassWnd                                           0x997018
#define pinstCPlayerNotesWnd                                       0x99701C
#define pinstCGemsGameWnd                                          0x997020
#define pinstCTimeLeftWnd                                          0x997024
#define pinstCPetitionQWnd                                         0x99702C
#define pinstCSoulmarkWnd                                          0x997030
#define pinstCStoryWnd                                             0x997034
#define pinstCJournalTextWnd                                       0x997038
#define pinstCJournalCatWnd                                        0x99703C
#define pinstCBodyTintWnd                                          0x997040
#define pinstCServerListWnd                                        0x997044
#define pinstCAvaZoneWnd                                           0x997048
#define pinstCBlockedBuffWnd                                       0x99704C
#define pinstCBlockedPetBuffWnd                                    0x997050
#define pinstCInvSlotMgr                                           0x997054
#define pinstCContainerMgr                                         0x997058
#define pinstCAdventureLeaderboardWnd                              0xB03210
#define pinstCAdventureRequestWnd                                  0xB0322C
#define pinstCAltStorageWnd                                        0xB0328C
#define pinstCAdventureStatsWnd                                    0xB03248
#define pinstCBarterMerchantWnd                                    0xB03458
#define pinstCBarterSearchWnd                                      0xB03474
#define pinstCBarterWnd                                            0xB03490
#define pinstCChatManager                                          0xB03734
#define pinstCDynamicZoneWnd                                       0xB0382C
#define pinstCEQMainWnd                                            0xB038A0
#define pinstCFellowshipWnd                                        0xB03904
#define pinstCFindLocationWnd                                      0xB03938
#define pinstCGroupSearchWnd                                       0xB039E8
#define pinstCGroupWnd                                             0xB03A04
#define pinstCGuildBankWnd                                         0xB03A20
#define pinstCGuildMgmtWnd                                         0xB05A58
#define pinstCGuildTributeMasterWnd                                0xB05A78
#define pinstCHotButtonWnd                                         0xB05A94
#define pinstCHotButtonWnd1                                        0xB05A94
#define pinstCHotButtonWnd2                                        0xB05A98
#define pinstCHotButtonWnd3                                        0xB05A9C
#define pinstCHotButtonWnd4                                        0xB05AA0
#define pinstCItemDisplayManager                                   0xB05B4C
#define pinstCItemExpTransferWnd                                   0xB05B6C
#define pinstCLeadershipWnd                                        0xB05C08
#define pinstCLFGuildWnd                                           0xB05C24
#define pinstCMIZoneSelectWnd                                      0xB05D94
#define pinstCAdventureMerchantWnd                                 0xB05E8C
#define pinstCConfirmationDialog                                   0xB05EA8
#define pinstCPopupWndManager                                      0xB05EA8
#define pinstCProgressionSelectionWnd                              0xB05EDC
#define pinstCPvPLeaderboardWnd                                    0xB05EF8
#define pinstCPvPStatsWnd                                          0xB05F14
#define pinstCSystemInfoDialogBox                                  0xB05FC8
#define pinstCTargetOfTargetWnd                                    0xB068D4
#define pinstCTaskSelectWnd                                        0xB06908
#define pinstCTaskTemplateSelectWnd                                0xB06924
#define pinstCTaskWnd                                              0xB06940
#define pinstCTipWndOFDAY                                          0xB069BC
#define pinstCTipWndCONTEXT                                        0xB069C0
#define pinstCTitleWnd                                             0xB069DC
#define pinstCTradeskillWnd                                        0xB06A20
#define pinstCTributeBenefitWnd                                    0xB06A6C
#define pinstCTributeMasterWnd                                     0xB06A88
#define pinstCContextMenuManager                                   0xB1492C
#define pinstCVoiceMacroWnd                                        0xAD7AE4
#define pinstCHtmlWnd                                              0xAD7B20


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C5480
#define __ConvertItemTags                                          0x4B7B10
#define __ExecuteCmd                                               0x4A6560
#define __get_melee_range                                          0x4AB9C0
#define __GetGaugeValueFromEQ                                      0x63E470
#define __GetLabelFromEQ                                           0x63F190
#define __NewUIINI                                                 0x63E050
#define __ProcessGameEvents                                        0x4F4740
#define CrashDetected                                              0x55F3A0
#define DrawNetStatus                                              0x5130B0
#define Util__FastTime                                             0x6B49D0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47F110
#define AltAdvManager__IsAbilityReady                              0x47F150
#define AltAdvManager__GetAltAbility                               0x47F330

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x577160

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x580590

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6E2CE0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5963B0
#define CChatManager__InitContextMenu                              0x596B50

// CChatService
#define CChatService__GetNumberOfFriends                           0x6A4970
#define CChatService__GetFriendName                                0x6A4980

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x59AD30
#define CChatWindow__Clear                                         0x59B6B0
#define CChatWindow__WndNotification                               0x59B790

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6CD680
#define CComboWnd__Draw                                            0x6CD830
#define CComboWnd__GetCurChoice                                    0x6CD620
#define CComboWnd__GetListRect                                     0x6CDAF0
#define CComboWnd__GetTextRect                                     0x6CD6B0
#define CComboWnd__InsertChoice                                    0x6CDB60
#define CComboWnd__SetColors                                       0x6CD5B0
#define CComboWnd__SetChoice                                       0x6CD5E0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A2480
#define CContainerWnd__vftable                                     0x7E2AD0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46DC30
#define CDisplay__GetClickedActor                                  0x46B380
#define CDisplay__GetUserDefinedColor                              0x46A4A0
#define CDisplay__GetWorldFilePath                                 0x4699C0
#define CDisplay__is3dON                                           0x468B30
#define CDisplay__ReloadUI                                         0x47C2B0
#define CDisplay__WriteTextHD2                                     0x46E3A0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x571200
#define CEditBaseWnd__SetSel                                       0x6EE110

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6D6220
#define CEditWnd__GetCharIndexPt                                   0x6D7060
#define CEditWnd__GetDisplayString                                 0x6D63B0
#define CEditWnd__GetHorzOffset                                    0x6D6640
#define CEditWnd__GetLineForPrintableChar                          0x6D6B10
#define CEditWnd__GetSelStartPt                                    0x6D72A0
#define CEditWnd__GetSTMLSafeText                                  0x6D67D0
#define CEditWnd__PointFromPrintableChar                           0x6D6C20
#define CEditWnd__SelectableCharFromPoint                          0x6D6DA0
#define CEditWnd__SetEditable                                      0x6D67A0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D8B80
#define CEverQuest__DropHeldItemOnGround                           0x4DCF90
#define CEverQuest__dsp_chat                                       0x4DE460
#define CEverQuest__DoTellWindow                                   0x4DD110
#define CEverQuest__EnterZone                                      0x4F3100
#define CEverQuest__GetBodyTypeDesc                                0x4D5E00
#define CEverQuest__GetClassDesc                                   0x4D5640
#define CEverQuest__GetClassThreeLetterCode                        0x4D5C40
#define CEverQuest__GetDeityDesc                                   0x4D6470
#define CEverQuest__GetLangDesc                                    0x4D6190
#define CEverQuest__GetRaceDesc                                    0x4D6440
#define CEverQuest__InterpretCmd                                   0x4DEEF0
#define CEverQuest__LeftClickedOnPlayer                            0x4F18A0
#define CEverQuest__LMouseUp                                       0x4F3EE0
#define CEverQuest__RightClickedOnPlayer                           0x4F1C70
#define CEverQuest__RMouseUp                                       0x4F3700
#define CEverQuest__SetGameState                                   0x4D9000
#define CEverQuest__Emote                                          0x4DE650

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5AF340
#define CGaugeWnd__CalcLinesFillRect                               0x5AF3A0
#define CGaugeWnd__Draw                                            0x5AF7B0

// CGuild
#define CGuild__FindMemberByName                                   0x421420

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5C78C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D0EA0
#define CInvSlotMgr__MoveItem                                      0x5D1040

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5CF860
#define CInvSlot__SliderComplete                                   0x5CFD70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5DFD30
#define CItemDisplayWnd__SetSpell                                  0x63C220

// CLabel 
#define CLabel__Draw                                               0x5E5610

// CListWnd 
#define CListWnd__AddColumn                                        0x6C7E90
#define CListWnd__AddColumn1                                       0x6C7970
#define CListWnd__AddLine                                          0x6C7460
#define CListWnd__AddString                                        0x6C7650
#define CListWnd__CalculateFirstVisibleLine                        0x6C4720
#define CListWnd__CalculateVSBRange                                0x6C64C0
#define CListWnd__ClearAllSel                                      0x6C3E50
#define CListWnd__CloseAndUpdateEditWindow                         0x6C4D45
#define CListWnd__Compare                                          0x6C50C0
#define CListWnd__Draw                                             0x6C61B0
#define CListWnd__DrawColumnSeparators                             0x6C6020
#define CListWnd__DrawHeader                                       0x6C4020
#define CListWnd__DrawItem                                         0x6C5950
#define CListWnd__DrawLine                                         0x6C5CC0
#define CListWnd__DrawSeparator                                    0x6C60C0
#define CListWnd__EnsureVisible                                    0x6C4770
#define CListWnd__ExtendSel                                        0x6C5870
#define CListWnd__GetColumnMinWidth                                0x6C3BE0
#define CListWnd__GetColumnWidth                                   0x6C3B20
#define CListWnd__GetCurSel                                        0x6C3510
#define CListWnd__GetHeaderRect                                    0x6C36A0
#define CListWnd__GetItemAtPoint                                   0x6C4A50
#define CListWnd__GetItemAtPoint1                                  0x6C4AC0
#define CListWnd__GetItemData                                      0x6C38D0
#define CListWnd__GetItemHeight                                    0x6C44B0
#define CListWnd__GetItemIcon                                      0x6C3A60
#define CListWnd__GetItemRect                                      0x6C4840
#define CListWnd__GetItemText                                      0x6C3910
#define CListWnd__GetSelList                                       0x6C7850
#define CListWnd__GetSeparatorRect                                 0x6C5000
#define CListWnd__RemoveLine                                       0x6C7800
#define CListWnd__SetColors                                        0x6C3600
#define CListWnd__SetColumnJustification                           0x6C3CC0
#define CListWnd__SetColumnWidth                                   0x6C3BA0
#define CListWnd__SetCurSel                                        0x6C3550
#define CListWnd__SetItemColor                                     0x6C70D0
#define CListWnd__SetItemData                                      0x6C3EF0
#define CListWnd__SetItemText                                      0x6C7050
#define CListWnd__ShiftColumnSeparator                             0x6C57E0
#define CListWnd__Sort                                             0x6C7ED0
#define CListWnd__ToggleSel                                        0x6C3DC0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5FA770

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x6058A0
#define CMerchantWnd__RequestBuyItem                               0x606C30
#define CMerchantWnd__RequestSellItem                              0x605AF0
#define CMerchantWnd__SelectBuySellSlot                            0x606960

// CObfuscator
#define CObfuscator__doit                                          0x67F9F0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6DE600
#define CSidlManager__CreateLabel                                  0x6352B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6CF320
#define CSidlScreenWnd__CalculateVSBRange                          0x6E42A0
#define CSidlScreenWnd__ConvertToRes                               0x6EDFF0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6CF7A0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6D0870
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6D0920
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6D0040
#define CSidlScreenWnd__DrawSidlPiece                              0x6CF470
#define CSidlScreenWnd__EnableIniStorage                           0x6CEF60
#define CSidlScreenWnd__GetSidlPiece                               0x6CF670
#define CSidlScreenWnd__Init1                                      0x6D06E0
#define CSidlScreenWnd__LoadIniInfo                                0x6CF850
#define CSidlScreenWnd__LoadIniListWnd                             0x6CF0B0
#define CSidlScreenWnd__LoadSidlScreen                             0x6D0290
#define CSidlScreenWnd__StoreIniInfo                               0x6CEB70
#define CSidlScreenWnd__WndNotification                            0x6D0460
#define CSidlScreenWnd__GetChildItem                               0x6CEFC0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x535790

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6EF4A0
#define CSliderWnd__SetValue                                       0x6EF5A0
#define CSliderWnd__SetNumTicks                                    0x6EFB10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x63AA10

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6EC260
#define CStmlWnd__CalculateVSBRange                                0x6E42A0
#define CStmlWnd__CanBreakAtCharacter                              0x6E43E0
#define CStmlWnd__FastForwardToEndOfTag                            0x6E4F70
#define CStmlWnd__ForceParseNow                                    0x6EC6E0
#define CStmlWnd__GetNextTagPiece                                  0x6E4E90
#define CStmlWnd__GetSTMLText                                      0x59ACD0
#define CStmlWnd__GetThisChar                                      0x711BD0
#define CStmlWnd__GetVisiableText                                  0x6E61B0
#define CStmlWnd__InitializeWindowVariables                        0x6E8380
#define CStmlWnd__MakeStmlColorTag                                 0x6E3940
#define CStmlWnd__MakeWndNotificationTag                           0x6E39E0
#define CStmlWnd__SetSTMLText                                      0x6E84B0
#define CStmlWnd__StripFirstSTMLLines                              0x6EBFF0
#define CStmlWnd__UpdateHistoryString                              0x6E6A20

// CTabWnd 
#define CTabWnd__Draw                                              0x6F0920
#define CTabWnd__DrawCurrentPage                                   0x6F02C0
#define CTabWnd__DrawTab                                           0x6F00A0
#define CTabWnd__GetCurrentPage                                    0x6F05C0
#define CTabWnd__GetPageClientRect                                 0x6EFD70
#define CTabWnd__GetPageFromTabIndex                               0x6EFFD0
#define CTabWnd__GetPageInnerRect                                  0x6EFDD0
#define CTabWnd__GetTabInnerRect                                   0x6EFF50
#define CTabWnd__GetTabRect                                        0x6EFE60
#define CTabWnd__IndexInBounds                                     0x6F0079
#define CTabWnd__InsertPage                                        0x6F0B90
#define CTabWnd__SetPage                                           0x6F0600
#define CTabWnd__SetPageRect                                       0x6F0850
#define CTabWnd__UpdatePage                                        0x6F0B10

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41D930

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6D0C80

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6F4EF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6C3200

// CXRect 
#define CXRect__CenterPoint                                        0x5767F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x41BDB0
#define CXStr__CXStr1                                              0x6BC920
#define CXStr__CXStr3                                              0x6B6120
#define CXStr__dCXStr                                              0x40FAC0
#define CXStr__operator_equal1                                     0x6B62E0
#define CXStr__operator_plus_equal1                                0x6B71E0

// CXWnd 
#define CXWnd__BringToTop                                          0x6C85C0
#define CXWnd__Center                                              0x6CC010
#define CXWnd__ClrFocus                                            0x6C82D0
#define CXWnd__DoAllDrawing                                        0x6CCE20
#define CXWnd__DrawChildren                                        0x6CCF50
#define CXWnd__DrawColoredRect                                     0x6C8850
#define CXWnd__DrawTooltip                                         0x6CCC40
#define CXWnd__DrawTooltipAtPoint                                  0x6CBDD0
#define CXWnd__GetBorderFrame                                      0x6C8D30
#define CXWnd__GetChildWndAt                                       0x6CB910
#define CXWnd__GetClientClipRect                                   0x6C8C40
#define CXWnd__GetScreenClipRect                                   0x6CC230
#define CXWnd__GetScreenRect                                       0x6C8ED0
#define CXWnd__GetTooltipRect                                      0x6C8AA0
#define CXWnd__GetWindowTextA                                      0x569F40
#define CXWnd__IsActive                                            0x6D1D90
#define CXWnd__IsDescendantOf                                      0x6C8CC0
#define CXWnd__IsReallyVisible                                     0x6CB8F0
#define CXWnd__IsType                                              0x6F1E10
#define CXWnd__Move                                                0x6CB4D0
#define CXWnd__Move1                                               0x6CCAA0
#define CXWnd__ProcessTransition                                   0x6C8580
#define CXWnd__Refade                                              0x6C8380
#define CXWnd__Resize                                              0x6C8FA0
#define CXWnd__Right                                               0x6CC170
#define CXWnd__SetFocus                                            0x6CA700
#define CXWnd__SetKeyTooltip                                       0x6C91B0
#define CXWnd__SetMouseOver                                        0x6C9180
#define CXWnd__StartFade                                           0x6C8600
#define CXWnd__GetChildItem                                        0x6CC3F0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6D3190
#define CXWndManager__DrawWindows                                  0x6D2DA0
#define CXWndManager__GetKeyboardFlags                             0x6D1A40
#define CXWndManager__HandleKeyboardMsg                            0x6D1F90
#define CXWndManager__RemoveWnd                                    0x6D1EB0

// CDBStr
#define CDBStr__GetString                                          0x467480

// EQ_Character 
#define EQ_Character__CastRay                                      0x71DC70
#define EQ_Character__CastSpell                                    0x42EF70
#define EQ_Character__Cur_HP                                       0x43C3E0
#define EQ_Character__GetAACastingTimeModifier                     0x429AB0
#define EQ_Character__GetCharInfo2                                 0x695AF0
#define EQ_Character__GetFocusCastingTimeModifier                  0x425570
#define EQ_Character__GetFocusRangeModifier                        0x4256B0
#define EQ_Character__Max_Endurance                                0x519260
#define EQ_Character__Max_HP                                       0x4372E0
#define EQ_Character__Max_Mana                                     0x519090
#define EQ_Character__doCombatAbility                              0x517FA0
#define EQ_Character__UseSkill                                     0x4424D0
#define EQ_Character__GetConLevel                                  0x514530

// EQ_Item 
#define EQ_Item__CanDrop                                           0x502100
#define EQ_Item__GetItemLinkHash                                   0x689490
#define EQ_Item__IsStackable                                       0x6802D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x480200
#define EQ_LoadingS__Array                                         0x85AB40

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51C0D0
#define EQ_PC__GetAltAbilityIndex                                  0x68DEF0
#define EQ_PC__GetCombatAbility                                    0x68DF80
#define EQ_PC__GetCombatAbilityTimer                               0x68E030
#define EQ_PC__GetItemTimerValue                                   0x516EC0
#define EQ_PC__HasLoreItem                                         0x51A5A0

// EQItemList 
#define EQItemList__dEQItemList                                    0x4AA120
#define EQItemList__EQItemList                                     0x4AA070

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x466E40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x520930
#define EQPlayer__dEQPlayer                                        0x524960
#define EQPlayer__DoAttack                                         0x531A10
#define EQPlayer__EQPlayer                                         0x5285F0
#define EQPlayer__SetNameSpriteState                               0x522900
#define EQPlayer__SetNameSpriteTint                                0x5209A0
#define EQPlayer__IsBodyType_j                                     0x71D640
#define EQPlayer__IsTargetable                                     0x71D7D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5296D0
#define EQPlayerManager__GetSpawnByName                            0x5299B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x503DA0
#define KeypressHandler__AttachKeyToEqCommand                      0x503DE0
#define KeypressHandler__ClearCommandStateArray                    0x503BB0
#define KeypressHandler__HandleKeyDown                             0x502760
#define KeypressHandler__HandleKeyUp                               0x502A70
#define KeypressHandler__SaveKeymapping                            0x503C80

// MapViewMap 
#define MapViewMap__Clear                                          0x5F5E40
#define MapViewMap__SaveEx                                         0x5F6810

#define OtherCharData__GetAltCurrency                              0x6AD130

// StringTable 
#define StringTable__getString                                     0x67FC70
