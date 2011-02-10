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
#define __ExpectedVersionDate                                     "Dec  7 2010"
#define __ExpectedVersionTime                                     "14:04:53"
#define __ActualVersionDate                                        0x87A918
#define __ActualVersionTime                                        0x87A924

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x524D80
#define __MemChecker1                                              0x797E60
#define __MemChecker2                                              0x596AC0
#define __MemChecker3                                              0x596A10
#define __MemChecker4                                              0x7B1ED0
#define __EncryptPad0                                              0x910538
#define __EncryptPad1                                              0x91C1F8
#define __EncryptPad2                                              0x9132A0
#define __EncryptPad3                                              0x912EA0
#define __EncryptPad4                                              0x91DC28
#define __AC1                                                      0x6A5300
#define __AC2                                                      0x4E7D15
#define __AC3                                                      0x4FA658
#define __AC4                                                      0x4FF988
#define __AC5                                                      0x50BB3E
#define __AC6                                                      0x50F29E
#define __AC7                                                      0x5076FB
#define __AC1_Data                                                 0x86271D

// Direct Input
#define DI8__Main                                                  0xB7A2EC
#define DI8__Keyboard                                              0xB7A2F0
#define DI8__Mouse                                                 0xB7A2F4
#define __AltTimerReady                                            0xAFEA52
#define __Attack                                                   0xB62536
#define __Autofire                                                 0xB62537
#define __BindList                                                 0x90AB10
#define __Clicks                                                   0xAFD708
#define __CommandList                                              0x90B4F0
#define __CurrentMapLabel                                          0xBA5588
#define __CurrentSocial                                            0x906978
#define __DoAbilityAvailable                                       0xAFE9EC
#define __DoAbilityList                                            0xB34454
#define __do_loot                                                  0x4BD040
#define __DrawHandler                                              0x1159864
#define __GroupCount                                               0xAF74F2
#define __Guilds                                                   0xAFCAE8
#define __gWorld                                                   0xAF93AC
#define __HotkeyPage                                               0xB5B840
#define __HWnd                                                     0xB7A028
#define __InChatMode                                               0xAFD640
#define __LastTell                                                 0xAFF36C
#define __LMouseHeldTime                                           0xAFD774
#define __Mouse                                                    0xB7A2F8
#define __MouseLook                                                0xAFD6D6
#define __MouseEventTime                                           0xB62698
#define __NetStatusToggle                                          0xAFD6D9
#define __PCNames                                                  0xAFEDB0
#define __RangeAttackReady                                         0xAFEA50
#define __RMouseHeldTime                                           0xAFD770
#define __RunWalkState                                             0xAFD644
#define __ScreenMode                                               0xA46D40
#define __ScreenX                                                  0xAFD5F8
#define __ScreenY                                                  0xAFD5FC
#define __ScreenXMax                                               0xAFD600
#define __ScreenYMax                                               0xAFD604
#define __ServerHost                                               0xAF7434
#define __ServerName                                               0xB34414
#define __ShiftKeyDown                                             0xAFDD04
#define __ShowNames                                                0xAFEC84
#define __Socials                                                  0xB34514


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xAF9480
#define instEQZoneInfo                                             0xAFD8C0
#define instKeypressHandler                                        0xB6267C
#define pinstActiveBanker                                          0xAF9454
#define pinstActiveCorpse                                          0xAF9458
#define pinstActiveGMaster                                         0xAF945C
#define pinstActiveMerchant                                        0xAF9450
#define pinstAltAdvManager                                         0xA47BD8
#define pinstAuraMgr                                               0x9305FC
#define pinstBandageTarget                                         0xAF943C
#define pinstCamActor                                              0xA476C4
#define pinstCDBStr                                                0xA46D34
#define pinstCDisplay                                              0xAF9464
#define pinstCEverQuest                                            0xB7A470
#define pinstCharData                                              0xAF9420
#define pinstCharSpawn                                             0xAF9448
#define pinstControlledMissile                                     0xAF941C
#define pinstControlledPlayer                                      0xAF9448
#define pinstCSidlManager                                          0x1159D34
#define pinstCXWndManager                                          0x1159D2C
#define instDynamicZone                                            0xAFD4C8
#define pinstDZMember                                              0xAFD5D8
#define pinstDZTimerInfo                                           0xAFD5DC
#define pinstEQItemList                                            0xAF6704
#define instEQMisc                                                 0xA46CE0
#define pinstEQSoundManager                                        0xA47BFC
#define instExpeditionLeader                                       0xAFD512
#define instExpeditionName                                         0xAFD552
#define pinstGroup                                                 0xAF74EE
#define pinstImeManager                                            0x1159D38
#define pinstLocalPlayer                                           0xAF9434
#define pinstMercenaryData                                         0xB62A0C
#define pinstModelPlayer                                           0xAF9460
#define pinstPCData                                                0xAF9420
#define pinstSkillMgr                                              0xB770DC
#define pinstSpawnManager                                          0xB76EF8
#define pinstSpellManager                                          0xB770E8
#define pinstSpellSets                                             0xB5B844
#define pinstStringTable                                           0xAF93C8
#define pinstSwitchManager                                         0xAF7134
#define pinstTarget                                                0xAF944C
#define pinstTargetObject                                          0xAF9424
#define pinstTargetSwitch                                          0xAF9428
#define pinstTaskMember                                            0xA46CC0
#define pinstTrackTarget                                           0xAF9440
#define pinstTradeTarget                                           0xAF9430
#define instTributeActive                                          0xA46D05
#define pinstViewActor                                             0xA476C0
#define pinstWorldData                                             0xAF9404


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x92DEC0
#define pinstCAudioTriggersWindow                                  0x92DE8C
#define pinstCCharacterSelect                                      0xA475A8
#define pinstCFacePick                                             0xA47558
#define pinstCNoteWnd                                              0xA47560
#define pinstCBookWnd                                              0xA47564
#define pinstCPetInfoWnd                                           0xA47568
#define pinstCTrainWnd                                             0xA4756C
#define pinstCSkillsWnd                                            0xA47570
#define pinstCSkillsSelectWnd                                      0xA47574
#define pinstCCombatSkillSelectWnd                                 0xA47578
#define pinstCFriendsWnd                                           0xA4757C
#define pinstCAuraWnd                                              0xA47580
#define pinstCRespawnWnd                                           0xA47584
#define pinstCBandolierWnd                                         0xA47588
#define pinstCPotionBeltWnd                                        0xA4758C
#define pinstCAAWnd                                                0xA47590
#define pinstCGroupSearchFiltersWnd                                0xA47594
#define pinstCLoadskinWnd                                          0xA47598
#define pinstCAlarmWnd                                             0xA4759C
#define pinstCMusicPlayerWnd                                       0xA475A0
#define pinstCMailWnd                                              0xA475AC
#define pinstCMailCompositionWnd                                   0xA475B0
#define pinstCMailAddressBookWnd                                   0xA475B4
#define pinstCRaidWnd                                              0xA475BC
#define pinstCRaidOptionsWnd                                       0xA475C0
#define pinstCBreathWnd                                            0xA475C4
#define pinstCMapViewWnd                                           0xA475C8
#define pinstCMapToolbarWnd                                        0xA475CC
#define pinstCEditLabelWnd                                         0xA475D0
#define pinstCTargetWnd                                            0xA475D4
#define pinstCColorPickerWnd                                       0xA475D8
#define pinstCPlayerWnd                                            0xA475DC
#define pinstCOptionsWnd                                           0xA475E0
#define pinstCBuffWindowNORMAL                                     0xA475E4
#define pinstCBuffWindowSHORT                                      0xA475E8
#define pinstCharacterCreation                                     0xA475EC
#define pinstCCursorAttachment                                     0xA475F0
#define pinstCCastingWnd                                           0xA475F4
#define pinstCCastSpellWnd                                         0xA475F8
#define pinstCSpellBookWnd                                         0xA475FC
#define pinstCInventoryWnd                                         0xA47600
#define pinstCBankWnd                                              0xA47604
#define pinstCQuantityWnd                                          0xA47608
#define pinstCLootWnd                                              0xA4760C
#define pinstCActionsWnd                                           0xA47610
#define pinstCCombatAbilityWnd                                     0xA47614
#define pinstCMerchantWnd                                          0xA47618
#define pinstCTradeWnd                                             0xA4761C
#define pinstCSelectorWnd                                          0xA47620
#define pinstCBazaarWnd                                            0xA47624
#define pinstCBazaarSearchWnd                                      0xA47628
#define pinstCGiveWnd                                              0xA47640
#define pinstCTrackingWnd                                          0xA47644
#define pinstCInspectWnd                                           0xA47648
#define pinstCSocialEditWnd                                        0xA4764C
#define pinstCFeedbackWnd                                          0xA47650
#define pinstCBugReportWnd                                         0xA47654
#define pinstCVideoModesWnd                                        0xA47658
#define pinstCTextEntryWnd                                         0xA47660
#define pinstCFileSelectionWnd                                     0xA47664
#define pinstCCompassWnd                                           0xA47668
#define pinstCPlayerNotesWnd                                       0xA4766C
#define pinstCGemsGameWnd                                          0xA47670
#define pinstCTimeLeftWnd                                          0xA47674
#define pinstCPetitionQWnd                                         0xA47688
#define pinstCSoulmarkWnd                                          0xA4768C
#define pinstCStoryWnd                                             0xA47690
#define pinstCJournalTextWnd                                       0xA47694
#define pinstCJournalCatWnd                                        0xA47698
#define pinstCBodyTintWnd                                          0xA4769C
#define pinstCServerListWnd                                        0xA476A0
#define pinstCAvaZoneWnd                                           0xA476A8
#define pinstCBlockedBuffWnd                                       0xA476AC
#define pinstCBlockedPetBuffWnd                                    0xA476B0
#define pinstCInvSlotMgr                                           0xA476B8
#define pinstCContainerMgr                                         0xA476BC
#define pinstCAdventureLeaderboardWnd                              0xBA2AA0
#define pinstCAdventureRequestWnd                                  0xBA2ABC
#define pinstCAltStorageWnd                                        0xBA2B1C
#define pinstCAdventureStatsWnd                                    0xBA2AD8
#define pinstCBarterMerchantWnd                                    0xBA2CE8
#define pinstCBarterSearchWnd                                      0xBA2D04
#define pinstCBarterWnd                                            0xBA2D20
#define pinstCChatManager                                          0xBA2FC4
#define pinstCDynamicZoneWnd                                       0xBA30BC
#define pinstCEQMainWnd                                            0xBA3130
#define pinstCFellowshipWnd                                        0xBA3194
#define pinstCFindLocationWnd                                      0xBA31C8
#define pinstCGroupSearchWnd                                       0xBA3278
#define pinstCGroupWnd                                             0xBA3294
#define pinstCGuildBankWnd                                         0xBA32B0
#define pinstCGuildMgmtWnd                                         0xBA52E8
#define pinstCGuildTributeMasterWnd                                0xBA5308
#define pinstCHotButtonWnd                                         0xBA533C
#define pinstCHotButtonWnd1                                        0xBA533C
#define pinstCHotButtonWnd2                                        0xBA5340
#define pinstCHotButtonWnd3                                        0xBA5344
#define pinstCHotButtonWnd4                                        0xBA5348
#define pinstCItemDisplayManager                                   0xBA53F4
#define pinstCItemExpTransferWnd                                   0xBA5414
#define pinstCLeadershipWnd                                        0xBA54B0
#define pinstCLFGuildWnd                                           0xBA54CC
#define pinstCMIZoneSelectWnd                                      0xBA563C
#define pinstCAdventureMerchantWnd                                 0xBA5764
#define pinstCConfirmationDialog                                   0xBA5780
#define pinstCPopupWndManager                                      0xBA5780
#define pinstCProgressionSelectionWnd                              0xBA57B4
#define pinstCPvPLeaderboardWnd                                    0xBA57D0
#define pinstCPvPStatsWnd                                          0xBA57EC
#define pinstCSystemInfoDialogBox                                  0xBA5930
#define pinstCTargetOfTargetWnd                                    0xBA6438
#define pinstCTaskSelectWnd                                        0xBA646C
#define pinstCTaskTemplateSelectWnd                                0xBA6488
#define pinstCTaskWnd                                              0xBA64A4
#define pinstCTipWndOFDAY                                          0xBA6520
#define pinstCTipWndCONTEXT                                        0xBA6524
#define pinstCTitleWnd                                             0xBA6540
#define pinstCTradeskillWnd                                        0xBA6584
#define pinstCTributeBenefitWnd                                    0xBA65D0
#define pinstCTributeMasterWnd                                     0xBA65EC
#define pinstCContextMenuManager                                   0x1159D90
#define pinstCVoiceMacroWnd                                        0xB772DC
#define pinstCHtmlWnd                                              0xB77328


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D0BD0
#define __ConvertItemTags                                          0x4C26C0
#define __ExecuteCmd                                               0x4AE360
#define __get_melee_range                                          0x4B43D0
#define __GetGaugeValueFromEQ                                      0x6A4180
#define __GetLabelFromEQ                                           0x6A52A0
#define __GetXTargetType                                           0x717E70
#define __LoadFrontEnd                                             0x5959F0
#define __NewUIINI                                                 0x6A3D30
#define __ProcessGameEvents                                        0x507E70
#define CrashDetected                                              0x5957F0
#define DrawNetStatus                                              0x5313A0
#define Util__FastTime                                             0x798610


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483840
#define AltAdvManager__IsAbilityReady                              0x483880
#define AltAdvManager__GetAltAbility                               0x483A60

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x438FD0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5B3590

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5BD570

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x75EC80

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5D5590
#define CChatManager__InitContextMenu                              0x5D5D60

// CChatService
#define CChatService__GetNumberOfFriends                           0x70D270
#define CChatService__GetFriendName                                0x70D280

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5DA030
#define CChatWindow__Clear                                         0x5DA990
#define CChatWindow__WndNotification                               0x5DAB80

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x748F10
#define CComboWnd__Draw                                            0x7490D0
#define CComboWnd__GetCurChoice                                    0x748DD0
#define CComboWnd__GetListRect                                     0x7493C0
#define CComboWnd__GetTextRect                                     0x748F40
#define CComboWnd__InsertChoice                                    0x749430
#define CComboWnd__SetColors                                       0x748D60
#define CComboWnd__SetChoice                                       0x748D90

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5E3D00
#define CContainerWnd__vftable                                     0x882018

// CDisplay 
#define CDisplay__CleanGameUI                                      0x476220
#define CDisplay__GetClickedActor                                  0x46F1C0
#define CDisplay__GetUserDefinedColor                              0x46DBA0
#define CDisplay__GetWorldFilePath                                 0x46D030
#define CDisplay__is3dON                                           0x46C160
#define CDisplay__ReloadUI                                         0x480A40
#define CDisplay__WriteTextHD2                                     0x471FB0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5AD5D0
#define CEditBaseWnd__SetSel                                       0x76C2B0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x751E00
#define CEditWnd__GetCharIndexPt                                   0x752DC0
#define CEditWnd__GetDisplayString                                 0x751F90
#define CEditWnd__GetHorzOffset                                    0x752220
#define CEditWnd__GetLineForPrintableChar                          0x752870
#define CEditWnd__GetSelStartPt                                    0x753010
#define CEditWnd__GetSTMLSafeText                                  0x7523C0
#define CEditWnd__PointFromPrintableChar                           0x752980
#define CEditWnd__SelectableCharFromPoint                          0x752B00
#define CEditWnd__SetEditable                                      0x752390

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4E8440
#define CEverQuest__DropHeldItemOnGround                           0x4F5A30
#define CEverQuest__dsp_chat                                       0x4EE7C0
#define CEverQuest__DoTellWindow                                   0x4ECF90
#define CEverQuest__EnterZone                                      0x4FF920
#define CEverQuest__GetBodyTypeDesc                                0x4E52B0
#define CEverQuest__GetClassDesc                                   0x4E4AF0
#define CEverQuest__GetClassThreeLetterCode                        0x4E50F0
#define CEverQuest__GetDeityDesc                                   0x4E5920
#define CEverQuest__GetLangDesc                                    0x4E5640
#define CEverQuest__GetRaceDesc                                    0x4E58F0
#define CEverQuest__InterpretCmd                                   0x4EF320
#define CEverQuest__LeftClickedOnPlayer                            0x501A70
#define CEverQuest__LMouseUp                                       0x505400
#define CEverQuest__RightClickedOnPlayer                           0x506550
#define CEverQuest__RMouseUp                                       0x5076C0
#define CEverQuest__SetGameState                                   0x4E88D0
#define CEverQuest__Emote                                          0x4EE9E0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5F0C40
#define CGaugeWnd__CalcLinesFillRect                               0x5F0CA0
#define CGaugeWnd__Draw                                            0x5F10F0

// CGuild
#define CGuild__FindMemberByName                                   0x41BAA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x609E80

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x6152D0
#define CInvSlotMgr__MoveItem                                      0x6156E0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x614760
#define CInvSlot__SliderComplete                                   0x613130
#define CInvSlot__GetItemBase                                      0x612890

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x616450

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6A1A40
#define CItemDisplayWnd__UpdateStrings                             0x617330

// CLabel 
#define CLabel__Draw                                               0x62B530

// CListWnd 
#define CListWnd__AddColumn                                        0x741B50
#define CListWnd__AddColumn1                                       0x7411C0
#define CListWnd__AddLine                                          0x740D70
#define CListWnd__AddString                                        0x740F10
#define CListWnd__CalculateFirstVisibleLine                        0x73D080
#define CListWnd__CalculateVSBRange                                0x73F3B0
#define CListWnd__ClearAllSel                                      0x73C5D0
#define CListWnd__CloseAndUpdateEditWindow                         0x7403E0
#define CListWnd__Compare                                          0x73DA80
#define CListWnd__Draw                                             0x73EFF0
#define CListWnd__DrawColumnSeparators                             0x73EE60
#define CListWnd__DrawHeader                                       0x73C860
#define CListWnd__DrawItem                                         0x73E480
#define CListWnd__DrawLine                                         0x73EAE0
#define CListWnd__DrawSeparator                                    0x73EF00
#define CListWnd__EnsureVisible                                    0x73D1E0
#define CListWnd__ExtendSel                                        0x73E3A0
#define CListWnd__GetColumnMinWidth                                0x73C2A0
#define CListWnd__GetColumnWidth                                   0x73C1E0
#define CListWnd__GetCurSel                                        0x73BA30
#define CListWnd__GetHeaderRect                                    0x73BB90
#define CListWnd__GetItemAtPoint                                   0x73D4B0
#define CListWnd__GetItemAtPoint1                                  0x73D520
#define CListWnd__GetItemData                                      0x73BDE0
#define CListWnd__GetItemHeight                                    0x73CCF0
#define CListWnd__GetItemIcon                                      0x73BFC0
#define CListWnd__GetItemRect                                      0x73D2B0
#define CListWnd__GetItemText                                      0x73BE70
#define CListWnd__GetSelList                                       0x7410A0
#define CListWnd__GetSeparatorRect                                 0x73D9D0
#define CListWnd__RemoveLine                                       0x741B00
#define CListWnd__SetColors                                        0x73BB00
#define CListWnd__SetColumnJustification                           0x73C440
#define CListWnd__SetColumnWidth                                   0x73C260
#define CListWnd__SetCurSel                                        0x73BA70
#define CListWnd__SetItemColor                                     0x7400A0
#define CListWnd__SetItemData                                      0x73C670
#define CListWnd__SetItemText                                      0x73FE80
#define CListWnd__ShiftColumnSeparator                             0x73FCF0
#define CListWnd__Sort                                             0x742290
#define CListWnd__ToggleSel                                        0x73C540

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x641420

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x652290
#define CMerchantWnd__RequestBuyItem                               0x655B50
#define CMerchantWnd__RequestSellItem                              0x674A50
#define CMerchantWnd__SelectBuySellSlot                            0x6535B0

// CObfuscator
#define CObfuscator__doit                                          0x6DCDE0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x75A5C0
#define CSidlManager__CreateLabel                                  0x69A8D0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5AF760
#define CSidlScreenWnd__CalculateVSBRange                          0x5AF680
#define CSidlScreenWnd__ConvertToRes                               0x76C190
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x74AFB0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x74C0A0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x74C150
#define CSidlScreenWnd__dCSidlScreenWnd                            0x74B860
#define CSidlScreenWnd__DrawSidlPiece                              0x74AC70
#define CSidlScreenWnd__EnableIniStorage                           0x74A740
#define CSidlScreenWnd__GetSidlPiece                               0x74AE80
#define CSidlScreenWnd__Init1                                      0x74BF00
#define CSidlScreenWnd__LoadIniInfo                                0x74B060
#define CSidlScreenWnd__LoadIniListWnd                             0x74A890
#define CSidlScreenWnd__LoadSidlScreen                             0x74BAB0
#define CSidlScreenWnd__StoreIniInfo                               0x74A340
#define CSidlScreenWnd__StoreIniVis                                0x74A6D0
#define CSidlScreenWnd__WndNotification                            0x74BC80
#define CSidlScreenWnd__GetChildItem                               0x74A7A0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x5632A0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x76CB80
#define CSliderWnd__SetValue                                       0x76CC80
#define CSliderWnd__SetNumTicks                                    0x76D230

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x69F650

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7697F0
#define CStmlWnd__CalculateHSBRange                                0x760F10
#define CStmlWnd__CalculateVSBRange                                0x760E80
#define CStmlWnd__CanBreakAtCharacter                              0x761070
#define CStmlWnd__FastForwardToEndOfTag                            0x761D50
#define CStmlWnd__ForceParseNow                                    0x769D20
#define CStmlWnd__GetNextTagPiece                                  0x761C70
#define CStmlWnd__GetSTMLText                                      0x5D9FD0
#define CStmlWnd__GetThisChar                                      0x7912B0
#define CStmlWnd__GetVisiableText                                  0x7631A0
#define CStmlWnd__InitializeWindowVariables                        0x765770
#define CStmlWnd__MakeStmlColorTag                                 0x75FDA0
#define CStmlWnd__MakeWndNotificationTag                           0x75FE40
#define CStmlWnd__SetSTMLText                                      0x765890
#define CStmlWnd__StripFirstSTMLLines                              0x7694A0
#define CStmlWnd__UpdateHistoryString                              0x763A30

// CTabWnd 
#define CTabWnd__Draw                                              0x76E1D0
#define CTabWnd__DrawCurrentPage                                   0x76DAB0
#define CTabWnd__DrawTab                                           0x76D890
#define CTabWnd__GetCurrentPage                                    0x76DE70
#define CTabWnd__GetPageClientRect                                 0x76D490
#define CTabWnd__GetPageFromTabIndex                               0x76D7C0
#define CTabWnd__GetPageInnerRect                                  0x76D4F0
#define CTabWnd__GetTabInnerRect                                   0x76D740
#define CTabWnd__GetTabRect                                        0x76D630
#define CTabWnd__InsertPage                                        0x76E460
#define CTabWnd__SetPage                                           0x76DEB0
#define CTabWnd__SetPageRect                                       0x76E100
#define CTabWnd__UpdatePage                                        0x76E3E0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x418060

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x74C4D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x76F070

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x73A990

// CXRect 
#define CXRect__CenterPoint                                        0x5B2E20

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416250
#define CXStr__CXStr1                                              0x401410
#define CXStr__CXStr3                                              0x795870
#define CXStr__dCXStr                                              0x470270
#define CXStr__operator_equal1                                     0x795A30
#define CXStr__operator_plus_equal1                                0x796AC0

// CXWnd 
#define CXWnd__BringToTop                                          0x742870
#define CXWnd__Center                                              0x747790
#define CXWnd__ClrFocus                                            0x7426A0
#define CXWnd__DoAllDrawing                                        0x748110
#define CXWnd__DrawChildren                                        0x748260
#define CXWnd__DrawColoredRect                                     0x742B60
#define CXWnd__DrawTooltip                                         0x7476C0
#define CXWnd__DrawTooltipAtPoint                                  0x7469C0
#define CXWnd__GetBorderFrame                                      0x7430A0
#define CXWnd__GetChildWndAt                                       0x745E40
#define CXWnd__GetClientClipRect                                   0x742E20
#define CXWnd__GetScreenClipRect                                   0x746E80
#define CXWnd__GetScreenRect                                       0x7431C0
#define CXWnd__GetTooltipRect                                      0x742C70
#define CXWnd__GetWindowTextA                                      0x5A0AA0
#define CXWnd__IsActive                                            0x74D600
#define CXWnd__IsDescendantOf                                      0x742F90
#define CXWnd__IsReallyVisible                                     0x745E20
#define CXWnd__IsType                                              0x771E90
#define CXWnd__Move                                                0x745570
#define CXWnd__Move1                                               0x747420
#define CXWnd__ProcessTransition                                   0x742820
#define CXWnd__Refade                                              0x7427A0
#define CXWnd__Resize                                              0x743290
#define CXWnd__Right                                               0x746D90
#define CXWnd__SetFocus                                            0x744980
#define CXWnd__SetKeyTooltip                                       0x743480
#define CXWnd__SetMouseOver                                        0x747170
#define CXWnd__StartFade                                           0x7428B0
#define CXWnd__GetChildItem                                        0x7470E0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x74EB60
#define CXWndManager__DrawWindows                                  0x74E7E0
#define CXWndManager__GetKeyboardFlags                             0x74D260
#define CXWndManager__HandleKeyboardMsg                            0x74D8D0
#define CXWndManager__RemoveWnd                                    0x74D720

// CDBStr
#define CDBStr__GetString                                          0x46AA10

// EQ_Character 
#define EQ_Character__CastRay                                      0x6FB0D0
#define EQ_Character__CastSpell                                    0x42FF30
#define EQ_Character__Cur_HP                                       0x438CA0
#define EQ_Character__GetAACastingTimeModifier                     0x425360
#define EQ_Character__GetCharInfo2                                 0x6F9E20
#define EQ_Character__GetFocusCastingTimeModifier                  0x420A70
#define EQ_Character__GetFocusRangeModifier                        0x420C50
#define EQ_Character__Max_Endurance                                0x539550
#define EQ_Character__Max_HP                                       0x433C70
#define EQ_Character__Max_Mana                                     0x539350
#define EQ_Character__doCombatAbility                              0x5381C0
#define EQ_Character__UseSkill                                     0x447560
#define EQ_Character__GetConLevel                                  0x532FE0
#define EQ_Character__IsExpansionFlag                              0x40D8E0
#define EQ_Character__TotalEffect                                  0x429590

// EQ_Item 
#define EQ_Item__CanDrop                                           0x519130
#define EQ_Item__CreateItemTagString                               0x6E9590
#define EQ_Item__IsStackable                                       0x6DD850

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x484930
#define EQ_LoadingS__Array                                         0x908ED8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x53D4D0
#define EQ_PC__GetAltAbilityIndex                                  0x6EF8C0
#define EQ_PC__GetCombatAbility                                    0x6EF950
#define EQ_PC__GetCombatAbilityTimer                               0x6EFA00
#define EQ_PC__GetItemTimerValue                                   0x537FF0
#define EQ_PC__HasLoreItem                                         0x6F8980

// EQItemList 
#define EQItemList__EQItemList                                     0x4B25E0
#define EQItemList__add_item                                       0x4B2570
#define EQItemList__delete_item                                    0x4B2990
#define EQItemList__FreeItemList                                   0x4B28C0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46A200

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x541E70
#define EQPlayer__dEQPlayer                                        0x5467E0
#define EQPlayer__DoAttack                                         0x557410
#define EQPlayer__EQPlayer                                         0x54BFF0
#define EQPlayer__SetNameSpriteState                               0x544280
#define EQPlayer__SetNameSpriteTint                                0x541EE0
#define EQPlayer__IsBodyType_j                                     0x6FA9D0
#define EQPlayer__IsTargetable                                     0x6FAB70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x54D2A0
#define EQPlayerManager__GetSpawnByName                            0x54D6A0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x51DFF0
#define KeypressHandler__AttachKeyToEqCommand                      0x51E030
#define KeypressHandler__ClearCommandStateArray                    0x51DE00
#define KeypressHandler__HandleKeyDown                             0x51C890
#define KeypressHandler__HandleKeyUp                               0x51CBA0
#define KeypressHandler__SaveKeymapping                            0x51DED0

// MapViewMap 
#define MapViewMap__Clear                                          0x63CAC0
#define MapViewMap__SaveEx                                         0x63D490

#define PlayerPointManager__GetAltCurrency                         0x6EADD0

// StringTable 
#define StringTable__getString                                     0x6DD060