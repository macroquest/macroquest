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
#define __ExpectedVersionDate                                     "Feb 10 2009"
#define __ExpectedVersionTime                                     "16:02:02"
#define __ActualVersionDate                                        0x7D8E0C
#define __ActualVersionTime                                        0x7D8E18

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x50A8F0
#define __MemChecker1                                              0x6B1420
#define __MemChecker2                                              0x560460
#define __MemChecker3                                              0x5603B0
#define __MemChecker4                                              0x673A00
#define __EncryptPad0                                              0x85E450
#define __EncryptPad1                                              0x868998
#define __EncryptPad2                                              0x860E90
#define __EncryptPad3                                              0x860A90
#define __EncryptPad4                                              0x868068

// Direct Input
#define DI8__Main                                                  0xAD9C64
#define DI8__Keyboard                                              0xAD9C68
#define DI8__Mouse                                                 0xAD9C6C
#define __AltTimerReady                                            0xA64722
#define __Attack                                                   0xAC41C2
#define __Autofire                                                 0xAC41C3
#define __BindList                                                 0x859450
#define __Clicks                                                   0xA63438
#define __CommandList                                              0x859CB0
#define __CurrentMapLabel                                          0xB04EA0
#define __CurrentSocial                                            0x855680
#define __DoAbilityAvailable                                       0xA646BC
#define __DoAbilityList                                            0xA99CD8
#define __do_loot                                                  0x4B1E10
#define __DrawHandler                                              0xB14304
#define __GroupCount                                               0xA43AE2
#define __Guilds                                                   0xA45660
#define __gWorld                                                   0xA455A0
#define __HotkeyPage                                               0xAC10C4
#define __HWnd                                                     0xAD99A4
#define __InChatMode                                               0xA63370
#define __LastTell                                                 0xA65030
#define __LMouseHeldTime                                           0xA63458
#define __Mouse                                                    0xAD9C70
#define __MouseLook                                                0xA63406
#define __MouseEventTime                                           0xAC42CC
#define __NetStatusToggle                                          0xA63409
#define __PCNames                                                  0xA64A78
#define __RangeAttackReady                                         0xA64720
#define __RMouseHeldTime                                           0xA63454
#define __RunWalkState                                             0xA63374
#define __ScreenMode                                               0x9933B0
#define __ScreenX                                                  0xA63328
#define __ScreenY                                                  0xA6332C
#define __ScreenXMax                                               0xA63330
#define __ScreenYMax                                               0xA63334
#define __ServerHost                                               0xA43A24
#define __ServerName                                               0xA99C98
#define __ShiftKeyDown                                             0xA639D8
#define __ShowNames                                                0xA6494C
#define __Socials                                                  0xA99D98


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA5D2B0
#define instEQZoneInfo                                             0xA635A4
#define instKeypressHandler                                        0xAC42B0
#define pinstActiveBanker                                          0xA45638
#define pinstActiveCorpse                                          0xA4563C
#define pinstActiveGMaster                                         0xA45640
#define pinstActiveMerchant                                        0xA45634
#define pinstAltAdvManager                                         0x994210
#define pinstAuraMgr                                               0x87CC74
#define pinstBandageTarget                                         0xA45620
#define pinstCamActor                                              0x993D00
#define pinstCDBStr                                                0x9933A0
#define pinstCDisplay                                              0xA45648
#define pinstCEverQuest                                            0xAD9DE8
#define pinstCharData                                              0xA45604
#define pinstCharSpawn                                             0xA4562C
#define pinstControlledMissile                                     0xA45600
#define pinstControlledPlayer                                      0xA4562C
#define pinstCSidlManager                                          0xB13A88
#define pinstCXWndManager                                          0xB13A80
#define instDynamicZone                                            0xA62D78
#define pinstDZMember                                              0xA62E88
#define pinstDZTimerInfo                                           0xA62E8C
#define pinstEQItemList                                            0xA455E8
#define instEQMisc                                                 0x993358
#define pinstEQSoundManager                                        0x994234
#define instExpeditionLeader                                       0xA62DC2
#define instExpeditionName                                         0xA62E02
#define pinstGroup                                                 0xA43ADE
#define pinstImeManager                                            0xB13A8C
#define pinstLocalPlayer                                           0xA45618
#define pinstModelPlayer                                           0xA45644
#define pinstPCData                                                0xA45604
#define pinstSkillMgr                                              0xAD6ABC
#define pinstSpawnManager                                          0xAD6A3C
#define pinstSpellManager                                          0xAD6AC0
#define pinstSpellSets                                             0xAC10C8
#define pinstStringTable                                           0xA455BC
#define pinstSwitchManager                                         0xA43724
#define pinstTarget                                                0xA45630
#define pinstTargetObject                                          0xA45608
#define pinstTargetSwitch                                          0xA4560C
#define pinstTaskMember                                            0x993338
#define pinstTrackTarget                                           0xA45624
#define pinstTradeTarget                                           0xA45614
#define instTributeActive                                          0x99337D
#define pinstViewActor                                             0x993CFC
#define pinstWorldData                                             0xA455E4


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x87A520
#define pinstCAudioTriggersWindow                                  0x87A4EC
#define pinstCCharacterSelect                                      0x993C0C
#define pinstCFacePick                                             0x993BC0
#define pinstCNoteWnd                                              0x993BC4
#define pinstCBookWnd                                              0x993BC8
#define pinstCPetInfoWnd                                           0x993BCC
#define pinstCTrainWnd                                             0x993BD0
#define pinstCSkillsWnd                                            0x993BD4
#define pinstCSkillsSelectWnd                                      0x993BD8
#define pinstCCombatSkillSelectWnd                                 0x993BDC
#define pinstCFriendsWnd                                           0x993BE0
#define pinstCAuraWnd                                              0x993BE4
#define pinstCRespawnWnd                                           0x993BE8
#define pinstCBandolierWnd                                         0x993BEC
#define pinstCPotionBeltWnd                                        0x993BF0
#define pinstCAAWnd                                                0x993BF4
#define pinstCGroupSearchFiltersWnd                                0x993BF8
#define pinstCLoadskinWnd                                          0x993BFC
#define pinstCAlarmWnd                                             0x993C00
#define pinstCMusicPlayerWnd                                       0x993C04
#define pinstCMailWnd                                              0x993C10
#define pinstCMailCompositionWnd                                   0x993C14
#define pinstCMailAddressBookWnd                                   0x993C18
#define pinstCRaidWnd                                              0x993C20
#define pinstCRaidOptionsWnd                                       0x993C24
#define pinstCBreathWnd                                            0x993C28
#define pinstCMapViewWnd                                           0x993C2C
#define pinstCMapToolbarWnd                                        0x993C30
#define pinstCEditLabelWnd                                         0x993C34
#define pinstCTargetWnd                                            0x993C38
#define pinstCColorPickerWnd                                       0x993C3C
#define pinstCPlayerWnd                                            0x993C40
#define pinstCOptionsWnd                                           0x993C44
#define pinstCBuffWindowNORMAL                                     0x993C48
#define pinstCBuffWindowSHORT                                      0x993C4C
#define pinstCharacterCreation                                     0x993C50
#define pinstCCursorAttachment                                     0x993C54
#define pinstCCastingWnd                                           0x993C58
#define pinstCCastSpellWnd                                         0x993C5C
#define pinstCSpellBookWnd                                         0x993C60
#define pinstCInventoryWnd                                         0x993C64
#define pinstCBankWnd                                              0x993C68
#define pinstCQuantityWnd                                          0x993C6C
#define pinstCLootWnd                                              0x993C70
#define pinstCActionsWnd                                           0x993C74
#define pinstCCombatAbilityWnd                                     0x993C78
#define pinstCMerchantWnd                                          0x993C7C
#define pinstCTradeWnd                                             0x993C80
#define pinstCSelectorWnd                                          0x993C84
#define pinstCBazaarWnd                                            0x993C88
#define pinstCBazaarSearchWnd                                      0x993C8C
#define pinstCGiveWnd                                              0x993C90
#define pinstCTrackingWnd                                          0x993C94
#define pinstCInspectWnd                                           0x993C98
#define pinstCSocialEditWnd                                        0x993C9C
#define pinstCFeedbackWnd                                          0x993CA0
#define pinstCBugReportWnd                                         0x993CA4
#define pinstCVideoModesWnd                                        0x993CA8
#define pinstCTextEntryWnd                                         0x993CB0
#define pinstCFileSelectionWnd                                     0x993CB4
#define pinstCCompassWnd                                           0x993CB8
#define pinstCPlayerNotesWnd                                       0x993CBC
#define pinstCGemsGameWnd                                          0x993CC0
#define pinstCTimeLeftWnd                                          0x993CC4
#define pinstCPetitionQWnd                                         0x993CCC
#define pinstCSoulmarkWnd                                          0x993CD0
#define pinstCStoryWnd                                             0x993CD4
#define pinstCJournalTextWnd                                       0x993CD8
#define pinstCJournalCatWnd                                        0x993CDC
#define pinstCBodyTintWnd                                          0x993CE0
#define pinstCServerListWnd                                        0x993CE4
#define pinstCAvaZoneWnd                                           0x993CE8
#define pinstCBlockedBuffWnd                                       0x993CEC
#define pinstCBlockedPetBuffWnd                                    0x993CF0
#define pinstCInvSlotMgr                                           0x993CF4
#define pinstCContainerMgr                                         0x993CF8
#define pinstCAdventureLeaderboardWnd                              0xB023D0
#define pinstCAdventureRequestWnd                                  0xB023EC
#define pinstCAltStorageWnd                                        0xB0244C
#define pinstCAdventureStatsWnd                                    0xB02408
#define pinstCBarterMerchantWnd                                    0xB02618
#define pinstCBarterSearchWnd                                      0xB02634
#define pinstCBarterWnd                                            0xB02650
#define pinstCChatManager                                          0xB028F4
#define pinstCDynamicZoneWnd                                       0xB029EC
#define pinstCEQMainWnd                                            0xB02A60
#define pinstCFellowshipWnd                                        0xB02AC4
#define pinstCFindLocationWnd                                      0xB02AF8
#define pinstCGroupSearchWnd                                       0xB02BA8
#define pinstCGroupWnd                                             0xB02BC4
#define pinstCGuildBankWnd                                         0xB02BE0
#define pinstCGuildMgmtWnd                                         0xB04C18
#define pinstCGuildTributeMasterWnd                                0xB04C38
#define pinstCHotButtonWnd                                         0xB04C54
#define pinstCHotButtonWnd1                                        0xB04C54
#define pinstCHotButtonWnd2                                        0xB04C58
#define pinstCHotButtonWnd3                                        0xB04C5C
#define pinstCHotButtonWnd4                                        0xB04C60
#define pinstCItemDisplayManager                                   0xB04D0C
#define pinstCItemExpTransferWnd                                   0xB04D2C
#define pinstCLeadershipWnd                                        0xB04DC8
#define pinstCLFGuildWnd                                           0xB04DE4
#define pinstCMIZoneSelectWnd                                      0xB04F54
#define pinstCAdventureMerchantWnd                                 0xB0504C
#define pinstCConfirmationDialog                                   0xB05068
#define pinstCPopupWndManager                                      0xB05068
#define pinstCProgressionSelectionWnd                              0xB0509C
#define pinstCPvPLeaderboardWnd                                    0xB050B8
#define pinstCPvPStatsWnd                                          0xB050D4
#define pinstCSystemInfoDialogBox                                  0xB05184
#define pinstCTargetOfTargetWnd                                    0xB05A8C
#define pinstCTaskSelectWnd                                        0xB05AC0
#define pinstCTaskTemplateSelectWnd                                0xB05ADC
#define pinstCTaskWnd                                              0xB05AF8
#define pinstCTipWndOFDAY                                          0xB05B74
#define pinstCTipWndCONTEXT                                        0xB05B78
#define pinstCTitleWnd                                             0xB05B94
#define pinstCTradeskillWnd                                        0xB05BD8
#define pinstCTributeBenefitWnd                                    0xB05C24
#define pinstCTributeMasterWnd                                     0xB05C40
#define pinstCContextMenuManager                                   0xB13AE4
#define pinstCVoiceMacroWnd                                        0xAD6CA4
#define pinstCHtmlWnd                                              0xAD6CE0


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C49F0
#define __ConvertItemTags                                          0x4B7220
#define __ExecuteCmd                                               0x4A5F70
#define __get_melee_range                                          0x4AB410
#define __GetGaugeValueFromEQ                                      0x63BDE0
#define __GetLabelFromEQ                                           0x63CA60
#define __NewUIINI                                                 0x63B9C0
#define __ProcessGameEvents                                        0x4F4780
#define CrashDetected                                              0x55F130
#define DrawNetStatus                                              0x513000
#define Util__FastTime                                             0x6B1B30


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47EAD0
#define AltAdvManager__IsAbilityReady                              0x47EB10
#define AltAdvManager__GetAltAbility                               0x47EDE0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x576F00

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x580340

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6DFB00

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x595FD0
#define CChatManager__InitContextMenu                              0x596770

// CChatService
#define CChatService__GetNumberOfFriends                           0x6A1C10
#define CChatService__GetFriendName                                0x6A1C20

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x59A970
#define CChatWindow__Clear                                         0x59B2E0
#define CChatWindow__WndNotification                               0x59B3C0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6CA3D0
#define CComboWnd__Draw                                            0x6CA580
#define CComboWnd__GetCurChoice                                    0x6CA370
#define CComboWnd__GetListRect                                     0x6CA850
#define CComboWnd__GetTextRect                                     0x6CA400
#define CComboWnd__InsertChoice                                    0x6CA8C0
#define CComboWnd__SetColors                                       0x6CA300
#define CComboWnd__SetChoice                                       0x6CA330

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A1F60
#define CContainerWnd__vftable                                     0x7DF9C0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46D720
#define CDisplay__GetClickedActor                                  0x46AE50
#define CDisplay__GetUserDefinedColor                              0x469F70
#define CDisplay__GetWorldFilePath                                 0x4694A0
#define CDisplay__is3dON                                           0x468610
#define CDisplay__ReloadUI                                         0x47BD30
#define CDisplay__WriteTextHD2                                     0x46DE90

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x570FA0
#define CEditBaseWnd__SetSel                                       0x6EAEB0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6D3010
#define CEditWnd__GetCharIndexPt                                   0x6D3E60
#define CEditWnd__GetDisplayString                                 0x6D31A0
#define CEditWnd__GetHorzOffset                                    0x6D3430
#define CEditWnd__GetLineForPrintableChar                          0x6D3910
#define CEditWnd__GetSelStartPt                                    0x6D40B0
#define CEditWnd__GetSTMLSafeText                                  0x6D35D0
#define CEditWnd__PointFromPrintableChar                           0x6D3A20
#define CEditWnd__SelectableCharFromPoint                          0x6D3BA0
#define CEditWnd__SetEditable                                      0x6D35A0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D8080
#define CEverQuest__DropHeldItemOnGround                           0x4DC4E0
#define CEverQuest__dsp_chat                                       0x4DDA00
#define CEverQuest__DoTellWindow                                   0x4DC660
#define CEverQuest__EnterZone                                      0x4F3140
#define CEverQuest__GetBodyTypeDesc                                0x4D5300
#define CEverQuest__GetClassDesc                                   0x4D4B40
#define CEverQuest__GetClassThreeLetterCode                        0x4D5140
#define CEverQuest__GetDeityDesc                                   0x4D5970
#define CEverQuest__GetLangDesc                                    0x4D5690
#define CEverQuest__GetRaceDesc                                    0x4D5940
#define CEverQuest__InterpretCmd                                   0x4DE490
#define CEverQuest__LeftClickedOnPlayer                            0x4F18E0
#define CEverQuest__LMouseUp                                       0x4F3F20
#define CEverQuest__RightClickedOnPlayer                           0x4F1CB0
#define CEverQuest__RMouseUp                                       0x4F3740
#define CEverQuest__SetGameState                                   0x4D8500
#define CEverQuest__Emote                                          0x4DDBF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5AEB50
#define CGaugeWnd__CalcLinesFillRect                               0x5AEBB0
#define CGaugeWnd__Draw                                            0x5AEFC0

// CGuild
#define CGuild__FindMemberByName                                   0x4217B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5C7040

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D05B0
#define CInvSlotMgr__MoveItem                                      0x5D0750

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5CEF70
#define CInvSlot__SliderComplete                                   0x5CF480

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5DF4F0
#define CItemDisplayWnd__SetSpell                                  0x639B40

// CLabel 
#define CLabel__Draw                                               0x5E4DF0

// CListWnd 
#define CListWnd__AddColumn                                        0x6C4B80
#define CListWnd__AddColumn1                                       0x6C4650
#define CListWnd__AddLine                                          0x6C4180
#define CListWnd__AddString                                        0x6C4380
#define CListWnd__CalculateFirstVisibleLine                        0x6C1560
#define CListWnd__CalculateVSBRange                                0x6C31C0
#define CListWnd__ClearAllSel                                      0x6C0C90
#define CListWnd__CloseAndUpdateEditWindow                         0x6C1BA5
#define CListWnd__Compare                                          0x6C1F30
#define CListWnd__Draw                                             0x6C2EB0
#define CListWnd__DrawColumnSeparators                             0x6C2D20
#define CListWnd__DrawHeader                                       0x6C0E60
#define CListWnd__DrawItem                                         0x6C2640
#define CListWnd__DrawLine                                         0x6C29C0
#define CListWnd__DrawSeparator                                    0x6C2DC0
#define CListWnd__EnsureVisible                                    0x6C15B0
#define CListWnd__ExtendSel                                        0x6C2560
#define CListWnd__GetColumnMinWidth                                0x6C0AA0
#define CListWnd__GetColumnWidth                                   0x6C09E0
#define CListWnd__GetCurSel                                        0x6C04A0
#define CListWnd__GetHeaderRect                                    0x6C05B0
#define CListWnd__GetItemAtPoint                                   0x6C18B0
#define CListWnd__GetItemAtPoint1                                  0x6C1920
#define CListWnd__GetItemData                                      0x6C0790
#define CListWnd__GetItemHeight                                    0x6C12F0
#define CListWnd__GetItemIcon                                      0x6C0920
#define CListWnd__GetItemRect                                      0x6C1690
#define CListWnd__GetItemText                                      0x6C07D0
#define CListWnd__GetSelList                                       0x6C4530
#define CListWnd__GetSeparatorRect                                 0x6C1E70
#define CListWnd__RemoveLine                                       0x6C4B30
#define CListWnd__SetColors                                        0x6C0520
#define CListWnd__SetColumnJustification                           0x6C0B00
#define CListWnd__SetColumnWidth                                   0x6C0A60
#define CListWnd__SetCurSel                                        0x6C04E0
#define CListWnd__SetItemColor                                     0x6C3DF0
#define CListWnd__SetItemData                                      0x6C0D30
#define CListWnd__SetItemText                                      0x6C3D70
#define CListWnd__ShiftColumnSeparator                             0x6C24D0
#define CListWnd__Sort                                             0x6C4BB0
#define CListWnd__ToggleSel                                        0x6C0C00

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5F9F50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x605100
#define CMerchantWnd__RequestBuyItem                               0x606480
#define CMerchantWnd__RequestSellItem                              0x605350
#define CMerchantWnd__SelectBuySellSlot                            0x6061B0

// CObfuscator
#define CObfuscator__doit                                          0x67D050

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6DB350
#define CSidlManager__CreateLabel                                  0x632BB0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6CC0A0
#define CSidlScreenWnd__CalculateVSBRange                          0x6E1070
#define CSidlScreenWnd__ConvertToRes                               0x6EAD90
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6CC510
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6CD600
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6CD6B0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6CCDB0
#define CSidlScreenWnd__DrawSidlPiece                              0x6CC1E0
#define CSidlScreenWnd__EnableIniStorage                           0x6CBCE0
#define CSidlScreenWnd__GetSidlPiece                               0x6CC3E0
#define CSidlScreenWnd__Init1                                      0x6CD460
#define CSidlScreenWnd__LoadIniInfo                                0x6CC5D0
#define CSidlScreenWnd__LoadIniListWnd                             0x6CBE30
#define CSidlScreenWnd__LoadSidlScreen                             0x6CD000
#define CSidlScreenWnd__StoreIniInfo                               0x6CB8F0
#define CSidlScreenWnd__WndNotification                            0x6CD1E0
#define CSidlScreenWnd__GetChildItem                               0x6CBD40

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x535530

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6EC250
#define CSliderWnd__SetValue                                       0x6EC350
#define CSliderWnd__SetNumTicks                                    0x6EC8D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x638310

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6E9020
#define CStmlWnd__CalculateVSBRange                                0x6E1070
#define CStmlWnd__CanBreakAtCharacter                              0x6E11B0
#define CStmlWnd__FastForwardToEndOfTag                            0x6E1D40
#define CStmlWnd__ForceParseNow                                    0x6E9490
#define CStmlWnd__GetNextTagPiece                                  0x6E1C60
#define CStmlWnd__GetSTMLText                                      0x59A910
#define CStmlWnd__GetThisChar                                      0x70E590
#define CStmlWnd__GetVisiableText                                  0x6E2F50
#define CStmlWnd__InitializeWindowVariables                        0x6E5100
#define CStmlWnd__MakeStmlColorTag                                 0x6E0770
#define CStmlWnd__MakeWndNotificationTag                           0x6E0810
#define CStmlWnd__SetSTMLText                                      0x6E5220
#define CStmlWnd__StripFirstSTMLLines                              0x6E8DA0
#define CStmlWnd__UpdateHistoryString                              0x6E37B0

// CTabWnd 
#define CTabWnd__Draw                                              0x6ED6F0
#define CTabWnd__DrawCurrentPage                                   0x6ED080
#define CTabWnd__DrawTab                                           0x6ECE60
#define CTabWnd__GetCurrentPage                                    0x6ED380
#define CTabWnd__GetPageClientRect                                 0x6ECB30
#define CTabWnd__GetPageFromTabIndex                               0x6ECD90
#define CTabWnd__GetPageInnerRect                                  0x6ECB90
#define CTabWnd__GetTabInnerRect                                   0x6ECD10
#define CTabWnd__GetTabRect                                        0x6ECC20
#define CTabWnd__IndexInBounds                                     0x6ECE2D
#define CTabWnd__InsertPage                                        0x6ED960
#define CTabWnd__SetPage                                           0x6ED3C0
#define CTabWnd__SetPageRect                                       0x6ED620
#define CTabWnd__UpdatePage                                        0x6ED8E0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41DCA0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6CDA10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6F1C60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6C0210

// CXRect 
#define CXRect__CenterPoint                                        0x576590

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x504470
#define CXStr__CXStr1                                              0x5326A0
#define CXStr__CXStr3                                              0x6B3230
#define CXStr__dCXStr                                              0x6E1350
#define CXStr__operator_equal1                                     0x6B33F0
#define CXStr__operator_plus_equal1                                0x6B42F0

// CXWnd 
#define CXWnd__BringToTop                                          0x6C52D0
#define CXWnd__Center                                              0x6C8DE0
#define CXWnd__ClrFocus                                            0x6C4FB0
#define CXWnd__DoAllDrawing                                        0x6C9B70
#define CXWnd__DrawChildren                                        0x6C9CA0
#define CXWnd__DrawColoredRect                                     0x6C5540
#define CXWnd__DrawTooltip                                         0x6C99A0
#define CXWnd__DrawTooltipAtPoint                                  0x6C8B90
#define CXWnd__GetBorderFrame                                      0x6C59C0
#define CXWnd__GetChildWndAt                                       0x6C86B0
#define CXWnd__GetClientClipRect                                   0x6C5900
#define CXWnd__GetScreenClipRect                                   0x6C9000
#define CXWnd__GetScreenRect                                       0x6C5BD0
#define CXWnd__GetTooltipRect                                      0x6C5760
#define CXWnd__GetWindowTextA                                      0x569D00
#define CXWnd__IsActive                                            0x6CEB40
#define CXWnd__IsDescendantOf                                      0x6C5970
#define CXWnd__IsReallyVisible                                     0x6C8690
#define CXWnd__IsType                                              0x6EEBC0
#define CXWnd__Move                                                0x6C8260
#define CXWnd__Move1                                               0x6C9800
#define CXWnd__ProcessTransition                                   0x6C5290
#define CXWnd__Refade                                              0x6C5060
#define CXWnd__Resize                                              0x6C5C90
#define CXWnd__Right                                               0x6C8F40
#define CXWnd__SetFocus                                            0x6C7440
#define CXWnd__SetKeyTooltip                                       0x6C5EB0
#define CXWnd__SetMouseOver                                        0x6C5E80
#define CXWnd__StartFade                                           0x6C5310
#define CXWnd__GetChildItem                                        0x6C9170

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6CFF80
#define CXWndManager__DrawWindows                                  0x6CFB90
#define CXWndManager__GetKeyboardFlags                             0x6CE7D0
#define CXWndManager__HandleKeyboardMsg                            0x6CED40
#define CXWndManager__RemoveWnd                                    0x6CEC60

// CDBStr
#define CDBStr__GetString                                          0x466F80

// EQ_Character 
#define EQ_Character__CastRay                                      0x71A680
#define EQ_Character__CastSpell                                    0x42F350
#define EQ_Character__Cur_HP                                       0x43C2D0
#define EQ_Character__GetAACastingTimeModifier                     0x429E70
#define EQ_Character__GetCharInfo2                                 0x692DD0
#define EQ_Character__GetFocusCastingTimeModifier                  0x425910
#define EQ_Character__GetFocusRangeModifier                        0x425A50
#define EQ_Character__Max_Endurance                                0x519120
#define EQ_Character__Max_HP                                       0x4371D0
#define EQ_Character__Max_Mana                                     0x518F50
#define EQ_Character__doCombatAbility                              0x517E80
#define EQ_Character__UseSkill                                     0x4423C0
#define EQ_Character__GetConLevel                                  0x514450

// EQ_Item 
#define EQ_Item__CanDrop                                           0x502140
#define EQ_Item__GetItemLinkHash                                   0x686AF0
#define EQ_Item__IsStackable                                       0x67D930

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47FCB0
#define EQ_LoadingS__Array                                         0x857930

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51BF90
#define EQ_PC__GetAltAbilityIndex                                  0x68B330
#define EQ_PC__GetCombatAbility                                    0x68B3C0
#define EQ_PC__GetCombatAbilityTimer                               0x68B470
#define EQ_PC__GetItemTimerValue                                   0x516DC0
#define EQ_PC__HasLoreItem                                         0x51A460

// EQItemList 
#define EQItemList__dEQItemList                                    0x4A9B30
#define EQItemList__EQItemList                                     0x4A9A80

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x466940

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5207F0
#define EQPlayer__dEQPlayer                                        0x5247C0
#define EQPlayer__DoAttack                                         0x5317E0
#define EQPlayer__EQPlayer                                         0x528430
#define EQPlayer__SetNameSpriteState                               0x522790
#define EQPlayer__SetNameSpriteTint                                0x520860
#define EQPlayer__IsBodyType_j                                     0x71A050
#define EQPlayer__IsTargetable                                     0x71A1E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5294F0
#define EQPlayerManager__GetSpawnByName                            0x5297D0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x503DE0
#define KeypressHandler__AttachKeyToEqCommand                      0x503E20
#define KeypressHandler__ClearCommandStateArray                    0x503BF0
#define KeypressHandler__HandleKeyDown                             0x5027A0
#define KeypressHandler__HandleKeyUp                               0x502AB0
#define KeypressHandler__SaveKeymapping                            0x503CC0

// MapViewMap 
#define MapViewMap__Clear                                          0x5F5620
#define MapViewMap__SaveEx                                         0x5F5FF0

#define OtherCharData__GetAltCurrency                              0x6AA440

// StringTable 
#define StringTable__getString                                     0x67D2D0
