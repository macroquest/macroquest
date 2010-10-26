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
#define __ExpectedVersionDate                                     "Oct 20 2010"
#define __ExpectedVersionTime                                     "17:58:58"
#define __ActualVersionDate                                        0x879790
#define __ActualVersionTime                                        0x87979C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x525040
#define __MemChecker1                                              0x724200
#define __MemChecker2                                              0x596490
#define __MemChecker3                                              0x5963E0
#define __MemChecker4                                              0x7B0960
#define __EncryptPad0                                              0x90F4E0
#define __EncryptPad1                                              0x919790
#define __EncryptPad2                                              0x912220
#define __EncryptPad3                                              0x911E20
#define __EncryptPad4                                              0x91CB10
#define __AC1                                                      0x6A4450
#define __AC2                                                      0x4E7FE5
#define __AC3                                                      0x4FA938
#define __AC4                                                      0x4FFC68
#define __AC5                                                      0x50BE3E
#define __AC6                                                      0x50F58E
#define __AC7                                                      0x507A0B
#define __AC1_Data                                                 0x860F8D

// Direct Input
#define DI8__Main                                                  0xB791BC
#define DI8__Keyboard                                              0xB791C0
#define DI8__Mouse                                                 0xB791C4
#define __AltTimerReady                                            0xAFD922
#define __Attack                                                   0xB61406
#define __Autofire                                                 0xB61407
#define __BindList                                                 0x909AE8
#define __Clicks                                                   0xAFC5D8
#define __CommandList                                              0x90A4B8
#define __CurrentMapLabel                                          0xBA4458
#define __CurrentSocial                                            0x90595C
#define __DoAbilityAvailable                                       0xAFD8BC
#define __DoAbilityList                                            0xB33324
#define __do_loot                                                  0x4BD2C0
#define __DrawHandler                                              0x11587B4
#define __GroupCount                                               0xAF63CA
#define __Guilds                                                   0xAFB9B8
#define __gWorld                                                   0xAF8284
#define __HotkeyPage                                               0xB5A710
#define __HWnd                                                     0xB78EF8
#define __InChatMode                                               0xAFC510
#define __LastTell                                                 0xAFE23C
#define __LMouseHeldTime                                           0xAFC644
#define __Mouse                                                    0xB791C8
#define __MouseLook                                                0xAFC5A6
#define __MouseEventTime                                           0xB61568
#define __NetStatusToggle                                          0xAFC5A9
#define __PCNames                                                  0xAFDC80
#define __RangeAttackReady                                         0xAFD920
#define __RMouseHeldTime                                           0xAFC640
#define __RunWalkState                                             0xAFC514
#define __ScreenMode                                               0xA45C20
#define __ScreenX                                                  0xAFC4C8
#define __ScreenY                                                  0xAFC4CC
#define __ScreenXMax                                               0xAFC4D0
#define __ScreenYMax                                               0xAFC4D4
#define __ServerHost                                               0xAF630C
#define __ServerName                                               0xB332E4
#define __ShiftKeyDown                                             0xAFCBD4
#define __ShowNames                                                0xAFDB54
#define __Socials                                                  0xB333E4


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xAF8350
#define instEQZoneInfo                                             0xAFC790
#define instKeypressHandler                                        0xB6154C
#define pinstActiveBanker                                          0xAF8328
#define pinstActiveCorpse                                          0xAF832C
#define pinstActiveGMaster                                         0xAF8330
#define pinstActiveMerchant                                        0xAF8324
#define pinstAltAdvManager                                         0xA46AB8
#define pinstAuraMgr                                               0x92F4DC
#define pinstBandageTarget                                         0xAF8310
#define pinstCamActor                                              0xA465A4
#define pinstCDBStr                                                0xA45C14
#define pinstCDisplay                                              0xAF8338
#define pinstCEverQuest                                            0xB79340
#define pinstCharData                                              0xAF82F4
#define pinstCharSpawn                                             0xAF831C
#define pinstControlledMissile                                     0xAF82F0
#define pinstControlledPlayer                                      0xAF831C
#define pinstCSidlManager                                          0x1158C84
#define pinstCXWndManager                                          0x1158C7C
#define instDynamicZone                                            0xAFC398
#define pinstDZMember                                              0xAFC4A8
#define pinstDZTimerInfo                                           0xAFC4AC
#define pinstEQItemList                                            0xAF55E0
#define instEQMisc                                                 0xA45BC0
#define pinstEQSoundManager                                        0xA46ADC
#define instExpeditionLeader                                       0xAFC3E2
#define instExpeditionName                                         0xAFC422
#define pinstGroup                                                 0xAF63C6
#define pinstImeManager                                            0x1158C88
#define pinstLocalPlayer                                           0xAF8308
#define pinstMercenaryData                                         0xB618DC
#define pinstModelPlayer                                           0xAF8334
#define pinstPCData                                                0xAF82F4
#define pinstSkillMgr                                              0xB75FAC
#define pinstSpawnManager                                          0xB75DC8
#define pinstSpellManager                                          0xB75FB8
#define pinstSpellSets                                             0xB5A714
#define pinstStringTable                                           0xAF82A0
#define pinstSwitchManager                                         0xAF600C
#define pinstTarget                                                0xAF8320
#define pinstTargetObject                                          0xAF82F8
#define pinstTargetSwitch                                          0xAF82FC
#define pinstTaskMember                                            0xA45BA0
#define pinstTrackTarget                                           0xAF8314
#define pinstTradeTarget                                           0xAF8304
#define instTributeActive                                          0xA45BF1
#define pinstViewActor                                             0xA465A0
#define pinstWorldData                                             0xAF82D8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x92CDA0
#define pinstCAudioTriggersWindow                                  0x92CD6C
#define pinstCCharacterSelect                                      0xA46488
#define pinstCFacePick                                             0xA46438
#define pinstCNoteWnd                                              0xA46440
#define pinstCBookWnd                                              0xA46444
#define pinstCPetInfoWnd                                           0xA46448
#define pinstCTrainWnd                                             0xA4644C
#define pinstCSkillsWnd                                            0xA46450
#define pinstCSkillsSelectWnd                                      0xA46454
#define pinstCCombatSkillSelectWnd                                 0xA46458
#define pinstCFriendsWnd                                           0xA4645C
#define pinstCAuraWnd                                              0xA46460
#define pinstCRespawnWnd                                           0xA46464
#define pinstCBandolierWnd                                         0xA46468
#define pinstCPotionBeltWnd                                        0xA4646C
#define pinstCAAWnd                                                0xA46470
#define pinstCGroupSearchFiltersWnd                                0xA46474
#define pinstCLoadskinWnd                                          0xA46478
#define pinstCAlarmWnd                                             0xA4647C
#define pinstCMusicPlayerWnd                                       0xA46480
#define pinstCMailWnd                                              0xA4648C
#define pinstCMailCompositionWnd                                   0xA46490
#define pinstCMailAddressBookWnd                                   0xA46494
#define pinstCRaidWnd                                              0xA4649C
#define pinstCRaidOptionsWnd                                       0xA464A0
#define pinstCBreathWnd                                            0xA464A4
#define pinstCMapViewWnd                                           0xA464A8
#define pinstCMapToolbarWnd                                        0xA464AC
#define pinstCEditLabelWnd                                         0xA464B0
#define pinstCTargetWnd                                            0xA464B4
#define pinstCColorPickerWnd                                       0xA464B8
#define pinstCPlayerWnd                                            0xA464BC
#define pinstCOptionsWnd                                           0xA464C0
#define pinstCBuffWindowNORMAL                                     0xA464C4
#define pinstCBuffWindowSHORT                                      0xA464C8
#define pinstCharacterCreation                                     0xA464CC
#define pinstCCursorAttachment                                     0xA464D0
#define pinstCCastingWnd                                           0xA464D4
#define pinstCCastSpellWnd                                         0xA464D8
#define pinstCSpellBookWnd                                         0xA464DC
#define pinstCInventoryWnd                                         0xA464E0
#define pinstCBankWnd                                              0xA464E4
#define pinstCQuantityWnd                                          0xA464E8
#define pinstCLootWnd                                              0xA464EC
#define pinstCActionsWnd                                           0xA464F0
#define pinstCCombatAbilityWnd                                     0xA464F4
#define pinstCMerchantWnd                                          0xA464F8
#define pinstCTradeWnd                                             0xA464FC
#define pinstCSelectorWnd                                          0xA46500
#define pinstCBazaarWnd                                            0xA46504
#define pinstCBazaarSearchWnd                                      0xA46508
#define pinstCGiveWnd                                              0xA46520
#define pinstCTrackingWnd                                          0xA46524
#define pinstCInspectWnd                                           0xA46528
#define pinstCSocialEditWnd                                        0xA4652C
#define pinstCFeedbackWnd                                          0xA46530
#define pinstCBugReportWnd                                         0xA46534
#define pinstCVideoModesWnd                                        0xA46538
#define pinstCTextEntryWnd                                         0xA46540
#define pinstCFileSelectionWnd                                     0xA46544
#define pinstCCompassWnd                                           0xA46548
#define pinstCPlayerNotesWnd                                       0xA4654C
#define pinstCGemsGameWnd                                          0xA46550
#define pinstCTimeLeftWnd                                          0xA46554
#define pinstCPetitionQWnd                                         0xA46568
#define pinstCSoulmarkWnd                                          0xA4656C
#define pinstCStoryWnd                                             0xA46570
#define pinstCJournalTextWnd                                       0xA46574
#define pinstCJournalCatWnd                                        0xA46578
#define pinstCBodyTintWnd                                          0xA4657C
#define pinstCServerListWnd                                        0xA46580
#define pinstCAvaZoneWnd                                           0xA46588
#define pinstCBlockedBuffWnd                                       0xA4658C
#define pinstCBlockedPetBuffWnd                                    0xA46590
#define pinstCInvSlotMgr                                           0xA46598
#define pinstCContainerMgr                                         0xA4659C
#define pinstCAdventureLeaderboardWnd                              0xBA1970
#define pinstCAdventureRequestWnd                                  0xBA198C
#define pinstCAltStorageWnd                                        0xBA19EC
#define pinstCAdventureStatsWnd                                    0xBA19A8
#define pinstCBarterMerchantWnd                                    0xBA1BB8
#define pinstCBarterSearchWnd                                      0xBA1BD4
#define pinstCBarterWnd                                            0xBA1BF0
#define pinstCChatManager                                          0xBA1E94
#define pinstCDynamicZoneWnd                                       0xBA1F8C
#define pinstCEQMainWnd                                            0xBA2000
#define pinstCFellowshipWnd                                        0xBA2064
#define pinstCFindLocationWnd                                      0xBA2098
#define pinstCGroupSearchWnd                                       0xBA2148
#define pinstCGroupWnd                                             0xBA2164
#define pinstCGuildBankWnd                                         0xBA2180
#define pinstCGuildMgmtWnd                                         0xBA41B8
#define pinstCGuildTributeMasterWnd                                0xBA41D8
#define pinstCHotButtonWnd                                         0xBA420C
#define pinstCHotButtonWnd1                                        0xBA420C
#define pinstCHotButtonWnd2                                        0xBA4210
#define pinstCHotButtonWnd3                                        0xBA4214
#define pinstCHotButtonWnd4                                        0xBA4218
#define pinstCItemDisplayManager                                   0xBA42C4
#define pinstCItemExpTransferWnd                                   0xBA42E4
#define pinstCLeadershipWnd                                        0xBA4380
#define pinstCLFGuildWnd                                           0xBA439C
#define pinstCMIZoneSelectWnd                                      0xBA450C
#define pinstCAdventureMerchantWnd                                 0xBA4634
#define pinstCConfirmationDialog                                   0xBA4650
#define pinstCPopupWndManager                                      0xBA4650
#define pinstCProgressionSelectionWnd                              0xBA4684
#define pinstCPvPLeaderboardWnd                                    0xBA46A0
#define pinstCPvPStatsWnd                                          0xBA46BC
#define pinstCSystemInfoDialogBox                                  0xBA4800
#define pinstCTargetOfTargetWnd                                    0xBA5308
#define pinstCTaskSelectWnd                                        0xBA533C
#define pinstCTaskTemplateSelectWnd                                0xBA5358
#define pinstCTaskWnd                                              0xBA5374
#define pinstCTipWndOFDAY                                          0xBA53F0
#define pinstCTipWndCONTEXT                                        0xBA53F4
#define pinstCTitleWnd                                             0xBA5410
#define pinstCTradeskillWnd                                        0xBA5454
#define pinstCTributeBenefitWnd                                    0xBA54A0
#define pinstCTributeMasterWnd                                     0xBA54BC
#define pinstCContextMenuManager                                   0x1158CE0
#define pinstCVoiceMacroWnd                                        0xB761AC
#define pinstCHtmlWnd                                              0xB761F8


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D0F30
#define __ConvertItemTags                                          0x4C2940
#define __ExecuteCmd                                               0x4AE760
#define __get_melee_range                                          0x4B46F0
#define __GetGaugeValueFromEQ                                      0x6A32D0
#define __GetLabelFromEQ                                           0x6A43F0
#define __GetXTargetType                                           0x716890
#define __LoadFrontEnd                                             0x5953B0
#define __NewUIINI                                                 0x6A2DF0
#define __ProcessGameEvents                                        0x508180
#define CrashDetected                                              0x5951B0
#define DrawNetStatus                                              0x5315B0
#define Util__FastTime                                             0x7249B0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x4838F0
#define AltAdvManager__IsAbilityReady                              0x483930
#define AltAdvManager__GetAltAbility                               0x483B10

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439130

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5B2E30

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5BCF10

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x7668E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5D4D30
#define CChatManager__InitContextMenu                              0x5D5500

// CChatService
#define CChatService__GetNumberOfFriends                           0x70BE30
#define CChatService__GetFriendName                                0x70BE40

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5D97D0
#define CChatWindow__Clear                                         0x5DA130
#define CChatWindow__WndNotification                               0x5DA320

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7509E0
#define CComboWnd__Draw                                            0x750BA0
#define CComboWnd__GetCurChoice                                    0x7508A0
#define CComboWnd__GetListRect                                     0x750E90
#define CComboWnd__GetTextRect                                     0x750A10
#define CComboWnd__InsertChoice                                    0x750F00
#define CComboWnd__SetColors                                       0x750830
#define CComboWnd__SetChoice                                       0x750860

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5E2FB0
#define CContainerWnd__vftable                                     0x880E90

// CDisplay 
#define CDisplay__CleanGameUI                                      0x4762B0
#define CDisplay__GetClickedActor                                  0x46F160
#define CDisplay__GetUserDefinedColor                              0x46DD60
#define CDisplay__GetWorldFilePath                                 0x46D1F0
#define CDisplay__is3dON                                           0x46C320
#define CDisplay__ReloadUI                                         0x480AE0
#define CDisplay__WriteTextHD2                                     0x472040

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5ACF50
#define CEditBaseWnd__SetSel                                       0x773ED0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7599B0
#define CEditWnd__GetCharIndexPt                                   0x75A970
#define CEditWnd__GetDisplayString                                 0x759B40
#define CEditWnd__GetHorzOffset                                    0x759DD0
#define CEditWnd__GetLineForPrintableChar                          0x75A420
#define CEditWnd__GetSelStartPt                                    0x75ABC0
#define CEditWnd__GetSTMLSafeText                                  0x759F70
#define CEditWnd__PointFromPrintableChar                           0x75A530
#define CEditWnd__SelectableCharFromPoint                          0x75A6B0
#define CEditWnd__SetEditable                                      0x759F40

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4E8710
#define CEverQuest__DropHeldItemOnGround                           0x4F5D20
#define CEverQuest__dsp_chat                                       0x4EEAA0
#define CEverQuest__DoTellWindow                                   0x4ED280
#define CEverQuest__EnterZone                                      0x4FFC00
#define CEverQuest__GetBodyTypeDesc                                0x4E5580
#define CEverQuest__GetClassDesc                                   0x4E4DC0
#define CEverQuest__GetClassThreeLetterCode                        0x4E53C0
#define CEverQuest__GetDeityDesc                                   0x4E5BF0
#define CEverQuest__GetLangDesc                                    0x4E5910
#define CEverQuest__GetRaceDesc                                    0x4E5BC0
#define CEverQuest__InterpretCmd                                   0x4EF600
#define CEverQuest__LeftClickedOnPlayer                            0x501D80
#define CEverQuest__LMouseUp                                       0x5079D0
#define CEverQuest__RightClickedOnPlayer                           0x506860
#define CEverQuest__RMouseUp                                       0x5079D0
#define CEverQuest__SetGameState                                   0x4E8BA0
#define CEverQuest__Emote                                          0x4EECC0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5EFEC0
#define CGaugeWnd__CalcLinesFillRect                               0x5EFF20
#define CGaugeWnd__Draw                                            0x5F0370

// CGuild
#define CGuild__FindMemberByName                                   0x41BAA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x609180

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x6144E0
#define CInvSlotMgr__MoveItem                                      0x6148F0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x613990
#define CInvSlot__SliderComplete                                   0x612450
#define CInvSlot__GetItemBase                                      0x611BB0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x6155A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6A0B70
#define CItemDisplayWnd__UpdateStrings                             0x616470

// CLabel 
#define CLabel__Draw                                               0x62A660

// CListWnd 
#define CListWnd__AddColumn                                        0x7496C0
#define CListWnd__AddColumn1                                       0x748D80
#define CListWnd__AddLine                                          0x7488E0
#define CListWnd__AddString                                        0x748A80
#define CListWnd__CalculateFirstVisibleLine                        0x744BF0
#define CListWnd__CalculateVSBRange                                0x746F20
#define CListWnd__ClearAllSel                                      0x744140
#define CListWnd__CloseAndUpdateEditWindow                         0x747F50
#define CListWnd__Compare                                          0x7455F0
#define CListWnd__Draw                                             0x746B60
#define CListWnd__DrawColumnSeparators                             0x7469D0
#define CListWnd__DrawHeader                                       0x7443D0
#define CListWnd__DrawItem                                         0x745FF0
#define CListWnd__DrawLine                                         0x746650
#define CListWnd__DrawSeparator                                    0x746A70
#define CListWnd__EnsureVisible                                    0x744D50
#define CListWnd__ExtendSel                                        0x745F10
#define CListWnd__GetColumnMinWidth                                0x743E10
#define CListWnd__GetColumnWidth                                   0x743D50
#define CListWnd__GetCurSel                                        0x7435B0
#define CListWnd__GetHeaderRect                                    0x743730
#define CListWnd__GetItemAtPoint                                   0x745020
#define CListWnd__GetItemAtPoint1                                  0x745090
#define CListWnd__GetItemData                                      0x743950
#define CListWnd__GetItemHeight                                    0x744860
#define CListWnd__GetItemIcon                                      0x743B30
#define CListWnd__GetItemRect                                      0x744E20
#define CListWnd__GetItemText                                      0x7439E0
#define CListWnd__GetSelList                                       0x748C60
#define CListWnd__GetSeparatorRect                                 0x745540
#define CListWnd__RemoveLine                                       0x748C10
#define CListWnd__SetColors                                        0x7436A0
#define CListWnd__SetColumnJustification                           0x743FB0
#define CListWnd__SetColumnWidth                                   0x743DD0
#define CListWnd__SetCurSel                                        0x7435F0
#define CListWnd__SetItemColor                                     0x747C10
#define CListWnd__SetItemData                                      0x7441E0
#define CListWnd__SetItemText                                      0x7479F0
#define CListWnd__ShiftColumnSeparator                             0x747860
#define CListWnd__Sort                                             0x749E00
#define CListWnd__ToggleSel                                        0x7440B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x6405D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x651320
#define CMerchantWnd__RequestBuyItem                               0x654BE0
#define CMerchantWnd__RequestSellItem                              0x673AF0
#define CMerchantWnd__SelectBuySellSlot                            0x652640

// CObfuscator
#define CObfuscator__doit                                          0x6DBF10

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7621F0
#define CSidlManager__CreateLabel                                  0x6999C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5AF000
#define CSidlScreenWnd__CalculateVSBRange                          0x752690
#define CSidlScreenWnd__ConvertToRes                               0x773DB0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x752B60
#define CSidlScreenWnd__CSidlScreenWnd1                            0x753C50
#define CSidlScreenWnd__CSidlScreenWnd2                            0x753D00
#define CSidlScreenWnd__dCSidlScreenWnd                            0x753410
#define CSidlScreenWnd__DrawSidlPiece                              0x752820
#define CSidlScreenWnd__EnableIniStorage                           0x752210
#define CSidlScreenWnd__GetSidlPiece                               0x752A30
#define CSidlScreenWnd__Init1                                      0x753AB0
#define CSidlScreenWnd__LoadIniInfo                                0x752C10
#define CSidlScreenWnd__LoadIniListWnd                             0x752360
#define CSidlScreenWnd__LoadSidlScreen                             0x753660
#define CSidlScreenWnd__StoreIniInfo                               0x751E10
#define CSidlScreenWnd__StoreIniVis                                0x7521A0
#define CSidlScreenWnd__WndNotification                            0x753830
#define CSidlScreenWnd__GetChildItem                               0x752270

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x562A60

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x774800
#define CSliderWnd__SetValue                                       0x774900
#define CSliderWnd__SetNumTicks                                    0x774EB0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x69E750

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x771440
#define CStmlWnd__CalculateHSBRange                                0x768B70
#define CStmlWnd__CalculateVSBRange                                0x768AE0
#define CStmlWnd__CanBreakAtCharacter                              0x768CD0
#define CStmlWnd__FastForwardToEndOfTag                            0x7699A0
#define CStmlWnd__ForceParseNow                                    0x771970
#define CStmlWnd__GetNextTagPiece                                  0x7698C0
#define CStmlWnd__GetSTMLText                                      0x5D9770
#define CStmlWnd__GetThisChar                                      0x798E50
#define CStmlWnd__GetVisiableText                                  0x76ADF0
#define CStmlWnd__InitializeWindowVariables                        0x76D3C0
#define CStmlWnd__MakeStmlColorTag                                 0x767A00
#define CStmlWnd__MakeWndNotificationTag                           0x767AA0
#define CStmlWnd__SetSTMLText                                      0x76D4E0
#define CStmlWnd__StripFirstSTMLLines                              0x7710F0
#define CStmlWnd__UpdateHistoryString                              0x76B680

// CTabWnd 
#define CTabWnd__Draw                                              0x775DA0
#define CTabWnd__DrawCurrentPage                                   0x775680
#define CTabWnd__DrawTab                                           0x775460
#define CTabWnd__GetCurrentPage                                    0x775A40
#define CTabWnd__GetPageClientRect                                 0x775110
#define CTabWnd__GetPageFromTabIndex                               0x775390
#define CTabWnd__GetPageInnerRect                                  0x775170
#define CTabWnd__GetTabInnerRect                                   0x775310
#define CTabWnd__GetTabRect                                        0x775200
#define CTabWnd__InsertPage                                        0x776030
#define CTabWnd__SetPage                                           0x775A80
#define CTabWnd__SetPageRect                                       0x775CD0
#define CTabWnd__UpdatePage                                        0x775FB0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x418080

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x754080

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x776C90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x742510

// CXRect 
#define CXRect__CenterPoint                                        0x5B26C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x51E870
#define CXStr__CXStr1                                              0x401410
#define CXStr__CXStr3                                              0x721C10
#define CXStr__dCXStr                                              0x4702F0
#define CXStr__operator_equal1                                     0x721DD0
#define CXStr__operator_plus_equal1                                0x722E60

// CXWnd 
#define CXWnd__BringToTop                                          0x74A3E0
#define CXWnd__Center                                              0x74F260
#define CXWnd__ClrFocus                                            0x74A210
#define CXWnd__DoAllDrawing                                        0x74FBE0
#define CXWnd__DrawChildren                                        0x74FD30
#define CXWnd__DrawColoredRect                                     0x74A6C0
#define CXWnd__DrawTooltip                                         0x74F190
#define CXWnd__DrawTooltipAtPoint                                  0x74E4E0
#define CXWnd__GetBorderFrame                                      0x74AB70
#define CXWnd__GetChildWndAt                                       0x74D960
#define CXWnd__GetClientClipRect                                   0x74A980
#define CXWnd__GetScreenClipRect                                   0x74E9A0
#define CXWnd__GetScreenRect                                       0x74AC90
#define CXWnd__GetTooltipRect                                      0x74A7D0
#define CXWnd__GetWindowTextA                                      0x5A0460
#define CXWnd__IsActive                                            0x7551B0
#define CXWnd__IsDescendantOf                                      0x74AA60
#define CXWnd__IsReallyVisible                                     0x74D940
#define CXWnd__IsType                                              0x779A90
#define CXWnd__Move                                                0x74D090
#define CXWnd__Move1                                               0x74EEF0
#define CXWnd__ProcessTransition                                   0x74A390
#define CXWnd__Refade                                              0x74A310
#define CXWnd__Resize                                              0x74AD60
#define CXWnd__Right                                               0x74E8B0
#define CXWnd__SetFocus                                            0x74C4A0
#define CXWnd__SetKeyTooltip                                       0x74AF50
#define CXWnd__SetMouseOver                                        0x74EC40
#define CXWnd__StartFade                                           0x74A410
#define CXWnd__GetChildItem                                        0x74EBB0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x756710
#define CXWndManager__DrawWindows                                  0x756390
#define CXWndManager__GetKeyboardFlags                             0x754E10
#define CXWndManager__HandleKeyboardMsg                            0x755480
#define CXWndManager__RemoveWnd                                    0x7552D0

// CDBStr
#define CDBStr__GetString                                          0x46ABF0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6F9C30
#define EQ_Character__CastSpell                                    0x42FF30
#define EQ_Character__Cur_HP                                       0x438DF0
#define EQ_Character__GetAACastingTimeModifier                     0x425370
#define EQ_Character__GetCharInfo2                                 0x6F8980
#define EQ_Character__GetFocusCastingTimeModifier                  0x420A80
#define EQ_Character__GetFocusRangeModifier                        0x420C60
#define EQ_Character__Max_Endurance                                0x5394B0
#define EQ_Character__Max_HP                                       0x433B40
#define EQ_Character__Max_Mana                                     0x5392E0
#define EQ_Character__doCombatAbility                              0x538140
#define EQ_Character__UseSkill                                     0x447750
#define EQ_Character__GetConLevel                                  0x533990

// EQ_Item 
#define EQ_Item__CanDrop                                           0x519400
#define EQ_Item__GetItemLinkHash                                   0x6E8290
#define EQ_Item__IsStackable                                       0x6DC9B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4849E0
#define EQ_LoadingS__Array                                         0x907EB8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x53D020
#define EQ_PC__GetAltAbilityIndex                                  0x6EE4D0
#define EQ_PC__GetCombatAbility                                    0x6EE560
#define EQ_PC__GetCombatAbilityTimer                               0x6EE610
#define EQ_PC__GetItemTimerValue                                   0x537F70
#define EQ_PC__HasLoreItem                                         0x6F74E0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B2920
#define EQItemList__add_item                                       0x4B28B0
#define EQItemList__delete_item                                    0x4B2CD0
#define EQItemList__FreeItemList                                   0x4B2C00

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46A400

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5419A0
#define EQPlayer__dEQPlayer                                        0x5462D0
#define EQPlayer__DoAttack                                         0x556DF0
#define EQPlayer__EQPlayer                                         0x54BB00
#define EQPlayer__SetNameSpriteState                               0x543DB0
#define EQPlayer__SetNameSpriteTint                                0x541A10
#define EQPlayer__IsBodyType_j                                     0x6F9530
#define EQPlayer__IsTargetable                                     0x6F96D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x54CDA0
#define EQPlayerManager__GetSpawnByName                            0x54D140

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x51E290
#define KeypressHandler__AttachKeyToEqCommand                      0x51E2D0
#define KeypressHandler__ClearCommandStateArray                    0x51E0A0
#define KeypressHandler__HandleKeyDown                             0x51CB70
#define KeypressHandler__HandleKeyUp                               0x51CE80
#define KeypressHandler__SaveKeymapping                            0x51E170

// MapViewMap 
#define MapViewMap__Clear                                          0x63BC70
#define MapViewMap__SaveEx                                         0x63C640

#define PlayerPointManager__GetAltCurrency                         0x6E9AD0

// StringTable 
#define StringTable__getString                                     0x6DC190