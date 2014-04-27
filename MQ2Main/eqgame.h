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
#define __ExpectedVersionDate                                     "Aug 16 2011"
#define __ExpectedVersionTime                                     "15:48:52"
#define __ActualVersionDate                                        0x8AEE54
#define __ActualVersionTime                                        0x8AEE60

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x528990
#define __MemChecker1                                              0x7BFCF0
#define __MemChecker2                                              0x5A1180
#define __MemChecker3                                              0x5A10D0
#define __MemChecker4                                              0x7E1BD0
#define __EncryptPad0                                              0x950B50
#define __EncryptPad1                                              0x95CDB0
#define __EncryptPad2                                              0x9538E8
#define __EncryptPad3                                              0x9534E8
#define __EncryptPad4                                              0x95E858
#define __AC1                                                      0x6BE2C0
#define __AC2                                                      0x4EA4F5
#define __AC3                                                      0x4FCD58
#define __AC4                                                      0x502734
#define __AC5                                                      0x50E9FC
#define __AC6                                                      0x51215E
#define __AC7                                                      0x50A65B
#define __AC1_Data                                                 0x895EED
// Direct Input
#define DI8__Main                                                  0xBC13BC
#define DI8__Keyboard                                              0xBC13C0
#define DI8__Mouse                                                 0xBC13C4
#define __AltTimerReady                                            0xB597A6
#define __Attack                                                   0xBBD2C2
#define __Autofire                                                 0xBBD2C3
#define __BindList                                                 0x94B0A8
#define __Clicks                                                   0xB58450
#define __CommandList                                              0x94BA98
#define __CurrentMapLabel                                          0xBED0C8
#define __CurrentSocial                                            0x9469D8
#define __DoAbilityAvailable                                       0xB59740
#define __DoAbilityList                                            0xB8F1E0
#define __do_loot                                                  0x4BF0C0
#define __DrawHandler                                              0x1247AA4
#define __GroupCount                                               0xB51E22
#define __Guilds                                                   0xB541B0
#define __gWorld                                                   0xB540DC
#define __HotkeyPage                                               0xBB65CC
#define __HWnd                                                     0xBC10F8
#define __InChatMode                                               0xB58388
#define __LastTell                                                 0xB5A0F8
#define __LMouseHeldTime                                           0xB584BC
#define __Mouse                                                    0xBC13C8
#define __MouseLook                                                0xB5841E
#define __MouseEventTime                                           0xBBD574
#define __NetStatusToggle                                          0xB58421
#define __PCNames                                                  0xB59B3C
#define __RangeAttackReady                                         0xB597A4
#define __RMouseHeldTime                                           0xB584B8
#define __RunWalkState                                             0xB5838C
#define __ScreenMode                                               0xAA1358
#define __ScreenX                                                  0xB58340
#define __ScreenY                                                  0xB58344
#define __ScreenXMax                                               0xB58348
#define __ScreenYMax                                               0xB5834C
#define __ServerHost                                               0xB51D64
#define __ServerName                                               0xB8F1A0
#define __ShiftKeyDown                                             0xB58A4C
#define __ShowNames                                                0xB599E0
#define __Socials                                                  0xB8F2A0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xB54CB8
#define instEQZoneInfo                                             0xB58608
#define instKeypressHandler                                        0xBBD570
#define pinstActiveBanker                                          0xB54184
#define pinstActiveCorpse                                          0xB54188
#define pinstActiveGMaster                                         0xB5418C
#define pinstActiveMerchant                                        0xB54180
#define pinstAltAdvManager                                         0xAA2280
#define pinstAuraMgr                                               0x9714F0
#define pinstBandageTarget                                         0xB5416C
#define pinstCamActor                                              0xAA1CF8
#define pinstCDBStr                                                0xAA1330
#define pinstCDisplay                                              0xB54194
#define pinstCEverQuest                                            0xBC1540
#define pinstCharData                                              0xB54150
#define pinstCharSpawn                                             0xB54178
#define pinstControlledMissile                                     0xB5414C
#define pinstControlledPlayer                                      0xB54178
#define pinstCSidlManager                                          0x1247F74
#define pinstCXWndManager                                          0x1247F6C
#define instDynamicZone                                            0xB54710
#define pinstDZMember                                              0xB54820
#define pinstDZTimerInfo                                           0xB54824
#define pinstEQItemList                                            0xB50EC8
#define instEQMisc                                                 0xAA12A8
#define pinstEQSoundManager                                        0xAA22F0
#define instExpeditionLeader                                       0xB5475A
#define instExpeditionName                                         0xB5479A
#define pinstGroup                                                 0xB51E1E
#define pinstImeManager                                            0x1247F78
#define pinstLocalPlayer                                           0xB54164
#define pinstMercenaryData                                         0xBBD9D8
#define pinstModelPlayer                                           0xB54190
#define pinstPCData                                                0xB54150
#define pinstSkillMgr                                              0xBBDFA0
#define pinstSpawnManager                                          0xBBDC38
#define pinstSpellManager                                          0xBBDFE0
#define pinstSpellSets                                             0xBB65D0
#define pinstStringTable                                           0xB540F8
#define pinstSwitchManager                                         0xB51A30
#define pinstTarget                                                0xB5417C
#define pinstTargetObject                                          0xB54154
#define pinstTargetSwitch                                          0xB54158
#define pinstTaskMember                                            0xAA1270
#define pinstTrackTarget                                           0xB54170
#define pinstTradeTarget                                           0xB54160
#define instTributeActive                                          0xAA12CD
#define pinstViewActor                                             0xAA1CF4
#define pinstWorldData                                             0xB54134


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x96EC50
#define pinstCAudioTriggersWindow                                  0x96EBE8
#define pinstCCharacterSelect                                      0xAA1BC8
#define pinstCFacePick                                             0xAA1B78
#define pinstCNoteWnd                                              0xAA1B80
#define pinstCBookWnd                                              0xAA1B84
#define pinstCPetInfoWnd                                           0xAA1B88
#define pinstCTrainWnd                                             0xAA1B8C
#define pinstCSkillsWnd                                            0xAA1B90
#define pinstCSkillsSelectWnd                                      0xAA1B94
#define pinstCCombatSkillSelectWnd                                 0xAA1B98
#define pinstCFriendsWnd                                           0xAA1B9C
#define pinstCAuraWnd                                              0xAA1BA0
#define pinstCRespawnWnd                                           0xAA1BA4
#define pinstCBandolierWnd                                         0xAA1BA8
#define pinstCPotionBeltWnd                                        0xAA1BAC
#define pinstCAAWnd                                                0xAA1BB0
#define pinstCGroupSearchFiltersWnd                                0xAA1BB4
#define pinstCLoadskinWnd                                          0xAA1BB8
#define pinstCAlarmWnd                                             0xAA1BBC
#define pinstCMusicPlayerWnd                                       0xAA1BC0
#define pinstCMailWnd                                              0xAA1BCC
#define pinstCMailCompositionWnd                                   0xAA1BD0
#define pinstCMailAddressBookWnd                                   0xAA1BD4
#define pinstCRaidWnd                                              0xAA1BDC
#define pinstCRaidOptionsWnd                                       0xAA1BE0
#define pinstCBreathWnd                                            0xAA1BE4
#define pinstCMapViewWnd                                           0xAA1BE8
#define pinstCMapToolbarWnd                                        0xAA1BEC
#define pinstCEditLabelWnd                                         0xAA1BF0
#define pinstCTargetWnd                                            0xAA1BF4
#define pinstCColorPickerWnd                                       0xAA1BF8
#define pinstCPlayerWnd                                            0xAA1BFC
#define pinstCOptionsWnd                                           0xAA1C00
#define pinstCBuffWindowNORMAL                                     0xAA1C04
#define pinstCBuffWindowSHORT                                      0xAA1C08
#define pinstCharacterCreation                                     0xAA1C0C
#define pinstCCursorAttachment                                     0xAA1C10
#define pinstCCastingWnd                                           0xAA1C14
#define pinstCCastSpellWnd                                         0xAA1C18
#define pinstCSpellBookWnd                                         0xAA1C1C
#define pinstCInventoryWnd                                         0xAA1C20
#define pinstCBankWnd                                              0xAA1C24
#define pinstCQuantityWnd                                          0xAA1C28
#define pinstCLootWnd                                              0xAA1C2C
#define pinstCActionsWnd                                           0xAA1C30
#define pinstCCombatAbilityWnd                                     0xAA1C34
#define pinstCMerchantWnd                                          0xAA1C38
#define pinstCTradeWnd                                             0xAA1C3C
#define pinstCSelectorWnd                                          0xAA1C40
#define pinstCBazaarWnd                                            0xAA1C44
#define pinstCBazaarSearchWnd                                      0xAA1C48
#define pinstCGiveWnd                                              0xAA1C64
#define pinstCTrackingWnd                                          0xAA1C68
#define pinstCInspectWnd                                           0xAA1C6C
#define pinstCSocialEditWnd                                        0xAA1C70
#define pinstCFeedbackWnd                                          0xAA1C74
#define pinstCBugReportWnd                                         0xAA1C78
#define pinstCVideoModesWnd                                        0xAA1C7C
#define pinstCTextEntryWnd                                         0xAA1C84
#define pinstCFileSelectionWnd                                     0xAA1C88
#define pinstCCompassWnd                                           0xAA1C8C
#define pinstCPlayerNotesWnd                                       0xAA1C90
#define pinstCGemsGameWnd                                          0xAA1C94
#define pinstCTimeLeftWnd                                          0xAA1C98
#define pinstCPetitionQWnd                                         0xAA1CAC
#define pinstCSoulmarkWnd                                          0xAA1CB0
#define pinstCStoryWnd                                             0xAA1CB4
#define pinstCJournalTextWnd                                       0xAA1CB8
#define pinstCJournalCatWnd                                        0xAA1CBC
#define pinstCBodyTintWnd                                          0xAA1CC0
#define pinstCServerListWnd                                        0xAA1CC4
#define pinstCAvaZoneWnd                                           0xAA1CCC
#define pinstCBlockedBuffWnd                                       0xAA1CD0
#define pinstCBlockedPetBuffWnd                                    0xAA1CD4
#define pinstCInvSlotMgr                                           0xAA1CEC
#define pinstCContainerMgr                                         0xAA1CF0
#define pinstCAdventureLeaderboardWnd                              0xBE9C98
#define pinstCAdventureRequestWnd                                  0xBE9C60
#define pinstCAltStorageWnd                                        0xBE9D10
#define pinstCAdventureStatsWnd                                    0xBE9C98
#define pinstCBarterMerchantWnd                                    0xBEA168
#define pinstCBarterSearchWnd                                      0xBEA1A0
#define pinstCBarterWnd                                            0xBEA1D8
#define pinstCChatManager                                          0xBEA5D0
#define pinstCDynamicZoneWnd                                       0xBEA7C0
#define pinstCEQMainWnd                                            0xBEA880
#define pinstCFellowshipWnd                                        0xBEA948
#define pinstCFindLocationWnd                                      0xBEA9B0
#define pinstCGroupSearchWnd                                       0xBEAB10
#define pinstCGroupWnd                                             0xBEAB48
#define pinstCGuildBankWnd                                         0xBEAB80
#define pinstCGuildMgmtWnd                                         0xBECBF0
#define pinstCGuildTributeMasterWnd                                0xBECC28
#define pinstCHotButtonWnd                                         0xBECC78
#define pinstCHotButtonWnd1                                        0xBECC78
#define pinstCHotButtonWnd2                                        0xBECC7C
#define pinstCHotButtonWnd3                                        0xBECC80
#define pinstCHotButtonWnd4                                        0xBECC84
#define pinstCItemDisplayManager                                   0xBECDC0
#define pinstCItemExpTransferWnd                                   0xBECDFC
#define pinstCLeadershipWnd                                        0xBECF28
#define pinstCLFGuildWnd                                           0xBECF60
#define pinstCMIZoneSelectWnd                                      0xBED1F8
#define pinstCAdventureMerchantWnd                                 0xBED4A8
#define pinstCConfirmationDialog                                   0xBED4E0
#define pinstCPopupWndManager                                      0xBED4E0
#define pinstCProgressionSelectionWnd                              0xBED548
#define pinstCPvPLeaderboardWnd                                    0xBED580
#define pinstCPvPStatsWnd                                          0xBED5B8
#define pinstCSystemInfoDialogBox                                  0xBED840
#define pinstCTargetOfTargetWnd                                    0xBEE440
#define pinstCTaskSelectWnd                                        0xBEE4A8
#define pinstCTaskTemplateSelectWnd                                0xBEE4E0
#define pinstCTaskWnd                                              0xBEE518
#define pinstCTipWndOFDAY                                          0xBEE690
#define pinstCTipWndCONTEXT                                        0xBEE694
#define pinstCTitleWnd                                             0xBEE6C8
#define pinstCTradeskillWnd                                        0xBEE740
#define pinstCTributeBenefitWnd                                    0xBEE7D8
#define pinstCTributeMasterWnd                                     0xBEE810
#define pinstCContextMenuManager                                   0x1247FD0
#define pinstCVoiceMacroWnd                                        0xBBE2F8
#define pinstCHtmlWnd                                              0xBBE370


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D3520
#define __ConvertItemTags                                          0x4C48A0
#define __ExecuteCmd                                               0x4B06B0
#define __get_melee_range                                          0x4B66B0
#define __GetGaugeValueFromEQ                                      0x6BD140
#define __GetLabelFromEQ                                           0x6BE260
#define __GetXTargetType                                           0x735270
#define __LoadFrontEnd                                             0x5A00B0
#define __NewUIINI                                                 0x6BCCF0
#define __ProcessGameEvents                                        0x50ADE0
#define CrashDetected                                              0x59FEB0
#define DrawNetStatus                                              0x534FB0
#define Util__FastTime                                             0x7C04F0
#define Expansion_HoT                                              0xB59940

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483D50
#define AltAdvManager__IsAbilityReady                              0x483E00
#define AltAdvManager__GetAltAbility                               0x484040

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x4394D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5BDD20

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C8010

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x7861B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5DFDD0
#define CChatManager__InitContextMenu                              0x5E05A0

// CChatService
#define CChatService__GetNumberOfFriends                           0x728FD0
#define CChatService__GetFriendName                                0x728FE0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5E4900
#define CChatWindow__Clear                                         0x5E5250
#define CChatWindow__WndNotification                               0x5E5430

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x76FDC0
#define CComboWnd__Draw                                            0x76FF80
#define CComboWnd__GetCurChoice                                    0x76FC80
#define CComboWnd__GetListRect                                     0x770250
#define CComboWnd__GetTextRect                                     0x76FDF0
#define CComboWnd__InsertChoice                                    0x7702C0
#define CComboWnd__SetColors                                       0x76FC10
#define CComboWnd__SetChoice                                       0x76FC40

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5EE680
#define CContainerWnd__vftable                                     0x8B66A0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x477AD0
#define CDisplay__GetClickedActor                                  0x470B10
#define CDisplay__GetUserDefinedColor                              0x46F4F0
#define CDisplay__GetWorldFilePath                                 0x46E9A0
#define CDisplay__is3dON                                           0x46DAD0
#define CDisplay__ReloadUI                                         0x480BA0
#define CDisplay__WriteTextHD2                                     0x473840

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B7D70
#define CEditBaseWnd__SetSel                                       0x793A10

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7791F0
#define CEditWnd__GetCharIndexPt                                   0x77A180
#define CEditWnd__GetDisplayString                                 0x779380
#define CEditWnd__GetHorzOffset                                    0x779610
#define CEditWnd__GetLineForPrintableChar                          0x779C50
#define CEditWnd__GetSelStartPt                                    0x77A3C0
#define CEditWnd__GetSTMLSafeText                                  0x7797A0
#define CEditWnd__PointFromPrintableChar                           0x779D60
#define CEditWnd__SelectableCharFromPoint                          0x779ED0
#define CEditWnd__SetEditable                                      0x779770

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EAC20
#define CEverQuest__DropHeldItemOnGround                           0x4F8210
#define CEverQuest__dsp_chat                                       0x4F10C0
#define CEverQuest__DoTellWindow                                   0x4EF7E0
#define CEverQuest__EnterZone                                      0x5026C0
#define CEverQuest__GetBodyTypeDesc                                0x4E7A90
#define CEverQuest__GetClassDesc                                   0x4E72D0
#define CEverQuest__GetClassThreeLetterCode                        0x4E78D0
#define CEverQuest__GetDeityDesc                                   0x4E8100
#define CEverQuest__GetLangDesc                                    0x4E7E20
#define CEverQuest__GetRaceDesc                                    0x4E80D0
#define CEverQuest__InterpretCmd                                   0x4F1CD0
#define CEverQuest__LeftClickedOnPlayer                            0x5047C0
#define CEverQuest__LMouseUp                                       0x508340
#define CEverQuest__RightClickedOnPlayer                           0x5094A0
#define CEverQuest__RMouseUp                                       0x50A620
#define CEverQuest__SetGameState                                   0x4EB0B0
#define CEverQuest__Emote                                          0x4F12E0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5FB8A0
#define CGaugeWnd__CalcLinesFillRect                               0x5FB900
#define CGaugeWnd__Draw                                            0x5FBD50

// CGuild
#define CGuild__FindMemberByName                                   0x41BA90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x614A40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x620470
#define CInvSlotMgr__MoveItem                                      0x620880

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x61F920
#define CInvSlot__SliderComplete                                   0x61DD10
#define CInvSlot__GetItemBase                                      0x61D470

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x621660

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6BAA10
#define CItemDisplayWnd__UpdateStrings                             0x622550

// CLabel 
#define CLabel__Draw                                               0x636960

// CListWnd 
#define CListWnd__AddColumn                                        0x7689F0
#define CListWnd__AddColumn1                                       0x7680B0
#define CListWnd__AddLine                                          0x767C10
#define CListWnd__AddString                                        0x767DB0
#define CListWnd__CalculateFirstVisibleLine                        0x763F50
#define CListWnd__CalculateVSBRange                                0x766260
#define CListWnd__ClearAllSel                                      0x7634B0
#define CListWnd__CloseAndUpdateEditWindow                         0x767280
#define CListWnd__Compare                                          0x764930
#define CListWnd__Draw                                             0x765EA0
#define CListWnd__DrawColumnSeparators                             0x765D10
#define CListWnd__DrawHeader                                       0x763740
#define CListWnd__DrawItem                                         0x765330
#define CListWnd__DrawLine                                         0x765990
#define CListWnd__DrawSeparator                                    0x765DB0
#define CListWnd__EnsureVisible                                    0x7640A0
#define CListWnd__ExtendSel                                        0x765250
#define CListWnd__GetColumnMinWidth                                0x763180
#define CListWnd__GetColumnWidth                                   0x7630C0
#define CListWnd__GetCurSel                                        0x762910
#define CListWnd__GetHeaderRect                                    0x762AA0
#define CListWnd__GetItemAtPoint                                   0x764360
#define CListWnd__GetItemAtPoint1                                  0x7643D0
#define CListWnd__GetItemData                                      0x762CC0
#define CListWnd__GetItemHeight                                    0x763BD0
#define CListWnd__GetItemIcon                                      0x762EA0
#define CListWnd__GetItemRect                                      0x764160
#define CListWnd__GetItemText                                      0x762D50
#define CListWnd__GetSelList                                       0x767F90
#define CListWnd__GetSeparatorRect                                 0x764880
#define CListWnd__RemoveLine                                       0x767F40
#define CListWnd__SetColors                                        0x762A00
#define CListWnd__SetColumnJustification                           0x763320
#define CListWnd__SetColumnWidth                                   0x763140
#define CListWnd__SetCurSel                                        0x762950
#define CListWnd__SetItemColor                                     0x766F40
#define CListWnd__SetItemData                                      0x763550
#define CListWnd__SetItemText                                      0x766D20
#define CListWnd__ShiftColumnSeparator                             0x766B90
#define CListWnd__Sort                                             0x769130
#define CListWnd__ToggleSel                                        0x763420

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x64C8B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x65FCA0
#define CMerchantWnd__RequestBuyItem                               0x6635F0
#define CMerchantWnd__RequestSellItem                              0x6839D0
#define CMerchantWnd__SelectBuySellSlot                            0x661230

// CObfuscator
#define CObfuscator__doit                                          0x6F8F30

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7819F0
#define CSidlManager__CreateLabel                                  0x6B3840

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B9F00
#define CSidlScreenWnd__CalculateVSBRange                          0x5B9E30
#define CSidlScreenWnd__ConvertToRes                               0x7938F0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x772330
#define CSidlScreenWnd__CSidlScreenWnd1                            0x773450
#define CSidlScreenWnd__CSidlScreenWnd2                            0x773500
#define CSidlScreenWnd__dCSidlScreenWnd                            0x772C70
#define CSidlScreenWnd__DrawSidlPiece                              0x771E00
#define CSidlScreenWnd__EnableIniStorage                           0x7715F0
#define CSidlScreenWnd__GetSidlPiece                               0x772010
#define CSidlScreenWnd__Init1                                      0x7732B0
#define CSidlScreenWnd__LoadIniInfo                                0x7723E0
#define CSidlScreenWnd__LoadIniListWnd                             0x771740
#define CSidlScreenWnd__LoadSidlScreen                             0x772EC0
#define CSidlScreenWnd__StoreIniInfo                               0x7711F0
#define CSidlScreenWnd__StoreIniVis                                0x771580
#define CSidlScreenWnd__WndNotification                            0x7730A0
#define CSidlScreenWnd__GetChildItem                               0x771650

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x56D050

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7942F0
#define CSliderWnd__SetValue                                       0x794400
#define CSliderWnd__SetNumTicks                                    0x7949B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B8630

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x790F80
#define CStmlWnd__CalculateHSBRange                                0x788630
#define CStmlWnd__CalculateVSBRange                                0x7886B0
#define CStmlWnd__CanBreakAtCharacter                              0x788820
#define CStmlWnd__FastForwardToEndOfTag                            0x7894F0
#define CStmlWnd__ForceParseNow                                    0x7914B0
#define CStmlWnd__GetNextTagPiece                                  0x789410
#define CStmlWnd__GetSTMLText                                      0x5E48A0
#define CStmlWnd__GetThisChar                                      0x7B8F00
#define CStmlWnd__GetVisiableText                                  0x78A950
#define CStmlWnd__InitializeWindowVariables                        0x78CF20
#define CStmlWnd__MakeStmlColorTag                                 0x787550
#define CStmlWnd__MakeWndNotificationTag                           0x7875F0
#define CStmlWnd__SetSTMLText                                      0x78D040
#define CStmlWnd__StripFirstSTMLLines                              0x790C30
#define CStmlWnd__UpdateHistoryString                              0x78B1E0

// CTabWnd 
#define CTabWnd__Draw                                              0x7958B0
#define CTabWnd__DrawCurrentPage                                   0x795180
#define CTabWnd__DrawTab                                           0x794F60
#define CTabWnd__GetCurrentPage                                    0x795540
#define CTabWnd__GetPageClientRect                                 0x794C10
#define CTabWnd__GetPageFromTabIndex                               0x794E90
#define CTabWnd__GetPageInnerRect                                  0x794C70
#define CTabWnd__GetTabInnerRect                                   0x794E10
#define CTabWnd__GetTabRect                                        0x794D00
#define CTabWnd__InsertPage                                        0x795B40
#define CTabWnd__SetPage                                           0x795580
#define CTabWnd__SetPageRect                                       0x7957E0
#define CTabWnd__UpdatePage                                        0x795AC0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x418060

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x773880

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x796730

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x761870

// CXRect 
#define CXRect__CenterPoint                                        0x535940

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x522220
#define CXStr__CXStr1                                              0x75C780
#define CXStr__CXStr3                                              0x7BD4D0
#define CXStr__dCXStr                                              0x44F070
#define CXStr__operator_equal                                      0x7BD640
#define CXStr__operator_equal1                                     0x7BD690
#define CXStr__operator_plus_equal1                                0x7BE720

// CXWnd 
#define CXWnd__BringToTop                                          0x769720
#define CXWnd__Center                                              0x76E710
#define CXWnd__ClrFocus                                            0x769540
#define CXWnd__DoAllDrawing                                        0x76F030
#define CXWnd__DrawChildren                                        0x76F170
#define CXWnd__DrawColoredRect                                     0x769A00
#define CXWnd__DrawTooltip                                         0x76E640
#define CXWnd__DrawTooltipAtPoint                                  0x76DD20
#define CXWnd__GetBorderFrame                                      0x769EF0
#define CXWnd__GetChildWndAt                                       0x76D1E0
#define CXWnd__GetClientClipRect                                   0x769CC0
#define CXWnd__GetScreenClipRect                                   0x76E250
#define CXWnd__GetScreenRect                                       0x76A030
#define CXWnd__GetTooltipRect                                      0x769B10
#define CXWnd__GetWindowTextA                                      0x5AB1A0
#define CXWnd__IsActive                                            0x7749B0
#define CXWnd__IsDescendantOf                                      0x769E20
#define CXWnd__IsReallyVisible                                     0x76D1C0
#define CXWnd__IsType                                              0x799520
#define CXWnd__Move                                                0x76C680
#define CXWnd__Move1                                               0x76C740
#define CXWnd__ProcessTransition                                   0x7696D0
#define CXWnd__Refade                                              0x769650
#define CXWnd__Resize                                              0x76A0F0
#define CXWnd__Right                                               0x76E160
#define CXWnd__SetFocus                                            0x76B8B0
#define CXWnd__SetKeyTooltip                                       0x76A340
#define CXWnd__SetMouseOver                                        0x76E530
#define CXWnd__StartFade                                           0x769760
#define CXWnd__GetChildItem                                        0x76E4A0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x775F20
#define CXWndManager__DrawWindows                                  0x775BA0
#define CXWndManager__GetKeyboardFlags                             0x774610
#define CXWndManager__HandleKeyboardMsg                            0x774C80
#define CXWndManager__RemoveWnd                                    0x774AD0

// CDBStr
#define CDBStr__GetString                                          0x46C330

// EQ_Character 
#define EQ_Character__CastRay                                      0x716950
#define EQ_Character__CastSpell                                    0x430380
#define EQ_Character__Cur_HP                                       0x439190
#define EQ_Character__GetAACastingTimeModifier                     0x4253F0
#define EQ_Character__GetCharInfo2                                 0x7156F0
#define EQ_Character__GetFocusCastingTimeModifier                  0x420B70
#define EQ_Character__GetFocusRangeModifier                        0x420D40
#define EQ_Character__Max_Endurance                                0x53D9C0
#define EQ_Character__Max_HP                                       0x434150
#define EQ_Character__Max_Mana                                     0x53D7C0
#define EQ_Character__doCombatAbility                              0x53C640
#define EQ_Character__UseSkill                                     0x447A20
#define EQ_Character__GetConLevel                                  0x537810
#define EQ_Character__IsExpansionFlag                              0x40D8E0
#define EQ_Character__TotalEffect                                  0x429900

// EQ_Item 
#define EQ_Item__CanDrop                                           0x51C270
#define EQ_Item__CreateItemTagString                               0x7041E0
#define EQ_Item__IsStackable                                       0x6F95B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4850F0
#define EQ_LoadingS__Array                                         0x949468

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x540EF0
#define EQ_PC__GetAltAbilityIndex                                  0x70A670
#define EQ_PC__GetCombatAbility                                    0x70A700
#define EQ_PC__GetCombatAbilityTimer                               0x70A7B0
#define EQ_PC__GetItemTimerValue                                   0x53C460
#define EQ_PC__HasLoreItem                                         0x714240

// EQItemList 
#define EQItemList__EQItemList                                     0x4B4950
#define EQItemList__add_item                                       0x4B48E0
#define EQItemList__delete_item                                    0x4B4D00
#define EQItemList__FreeItemList                                   0x4B4C30

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46BB20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x545AD0
#define EQPlayer__dEQPlayer                                        0x54A5D0
#define EQPlayer__DoAttack                                         0x55B400
#define EQPlayer__EQPlayer                                         0x54FEA0
#define EQPlayer__SetNameSpriteState                               0x547F40
#define EQPlayer__SetNameSpriteTint                                0x545B40
#define EQPlayer__IsBodyType_j                                     0x716210
#define EQPlayer__IsTargetable                                     0x7164D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x551170
#define EQPlayerManager__GetSpawnByName                            0x551400

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x521C40
#define KeypressHandler__AttachKeyToEqCommand                      0x521C80
#define KeypressHandler__ClearCommandStateArray                    0x521A50
#define KeypressHandler__HandleKeyDown                             0x520450
#define KeypressHandler__HandleKeyUp                               0x520760
#define KeypressHandler__SaveKeymapping                            0x521B20

// MapViewMap 
#define MapViewMap__Clear                                          0x647F30
#define MapViewMap__SaveEx                                         0x648900

#define PlayerPointManager__GetAltCurrency                         0x705370

// StringTable 
#define StringTable__getString                                     0x6F91B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x53F680
