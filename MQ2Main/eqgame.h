// Class instances
#define pinstCContextMenuManager                                0x78F168
#define pinstCCursorAttachment                                  0x6074EC
#define pinstCSocialEditWnd                                     0x607530
#define pinstCInvSlotMgr                                        0x607570
#define pinstCContainerMgr                                      0x607574
#define pinstCChatManager                                       0x783B90
#define pinstCConfirmationDialog                                0x607474
#define pinstCFacePick                                          0x60747C
#define pinstCItemDisplayMgr                                    0x783E14
#define pinstCSpellDisplayMgr                                   0x783FA0
#define pinstCNoteWnd                                           0x607480
#define pinstCHelpWnd                                           0x607484
#define pinstCTipWndOFDAY                                       0x784870
#define pinstCTipWndCONTEXT                                     0x784874
#define pinstCBookWnd                                           0x607488
#define pinstCFriendsWnd                                        0x60749C
#define pinstCMusicPlayerWnd                                    0x6074B0
#define pinstCAlarmWnd                                          0x6074AC
#define pinstCLoadskinWnd                                       0x6074A8
#define pinstCPetInfoWnd                                        0x60748C
#define pinstCTrainWnd                                          0x607490
#define pinstCSkillsWnd                                         0x607494
#define pinstCSkillsSelectWnd                                   0x607498
#define pinstCAAWnd                                             0x6074A0
#define pinstCGroupWnd                                          0x783D54
#define pinstCJournalNPCWnd                                     0x78481C
#define pinstCGroupSearchWnd                                    0x783D3C
#define pinstCGroupSearchFiltersWnd                             0x6074A4
#define pinstCRaidWnd                                           0x6074B4
#define pinstCRaidOptionsWnd                                    0x6074B8
#define pinstCBreathWnd                                         0x6074BC
#define pinstCMapToolbarWnd                                     0x6074C4
#define pinstCMapViewWnd                                        0x6074C0
#define pinstCEditLabelWnd                                      0x6074C8
#define pinstCOptionsWnd                                        0x6074DC
#define pinstCBuffWindowSHORT                                   0x6074E0
#define pinstCBuffWindowNORMAL                                  0x6074E4
#define pinstCTargetWnd                                         0x6074CC
#define pinstCColorPickerWnd                                    0x6074D4
#define pinstCHotButtonWnd                                      0x6074D0
#define pinstCPlayerWnd                                         0x6074D8
#define pinstCCastingWnd                                        0x6074F0
#define pinstCCastSpellWnd                                      0x6074F4
#define pinstCSpellBookWnd                                      0x6074F8
#define pinstCInventoryWnd                                      0x6074FC
#define pinstCBankWnd                                           0x607500
#define pinstCQuantityWnd                                       0x607504
#define pinstCTextEntryWnd                                      0x607540
#define pinstCFileSelectionWnd                                  0x607544
#define pinstCLootWnd                                           0x607508
#define pinstCActionsWnd                                        0x60750C
#define pinstCMerchantWnd                                       0x607510
#define pinstCTradeWnd                                          0x607514
#define pinstCBazaarWnd                                         0x60751C
#define pinstCBazaarSearchWnd                                   0x607520
#define pinstCGiveWnd                                           0x607524
#define pinstCSelectorWnd                                       0x607518
#define pinstCTrackingWnd                                       0x607528
#define pinstCInspectWnd                                        0x60752C
#define pinstCFeedbackWnd                                       0x607534
#define pinstCBugReportWnd                                      0x607538
#define pinstCVideoModesWnd                                     0x60753C
#define pinstCCompassWnd                                        0x607548
#define pinstCPlayerNotesWnd                                    0x60754C
#define pinstCGemsGameWnd                                       0x607550
#define pinstCStoryWnd                                          0x607560
#define pinstCFindLocationWnd                                   0x783CC0
#define pinstCAdventureRequestWnd                               0x783928
#define pinstCAdventureStatsWnd                                 0x783940
#define pinstCAdventureLeaderboardWnd                           0x7838F8
#define pinstCBodyTintWnd                                       0x60756C
#define pinstCGuildMgmtWnd                                      0x783D6C
#define pinstCJournalTextWnd                                    0x607564
#define pinstCJournalCatWnd                                     0x607568
#define pinstCPetitionQWnd                                      0x607558
#define pinstCSoulmarkWnd                                       0x60755C
#define pinstCTimeLeftWnd                                       0x607554 


#define pinstCDisplay					0x0071D8DC
#define pinstCEverQuest					0x0077B298
#define pinstCharData					0x0071D8B8
#define pinstCharSpawn                  0x0071D8B0
#define pinstSpawnList					0x0071D878
#define pinstSpawnListTail				0x0071D89C
#define pinstWorldData					0x0071D874
#define pinstSpellManager				0x00777C84
#define pinstActiveMerchant             0x0071D8C8
#define pinstSelectedItem               0x00783DE8
#define pinstGroup						0x0071BF48
#define pinstTarget						0x0071D8BC
#define pinstSwitchManager				0x006BA5AC
#define pinstEQItemList					0x0071D87C
#define pinstSpellSets					0x0071ab94

// Class member function offsets
/*
// static
    GetPrivateProfileString("Function Locations","MemChecker","0",szBuffer,MAX_STRING,ClientINI);       EQADDR_MEMCHECK = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","MemChecker2","0",szBuffer,MAX_STRING,ClientINI);      EQADDR_MEMCHECK2 = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","MemCheckAddr1","0",szBuffer,MAX_STRING,ClientINI);        EQADDR_MEMCHECKADDR1 = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","MemCheckAddr2","0",szBuffer,MAX_STRING,ClientINI);        EQADDR_MEMCHECKADDR2 = strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","MemChecker3","0",szBuffer,MAX_STRING,ClientINI);      EQADDR_MEMCHECK3 = strtoul(szBuffer,NULL,16);

    GetPrivateProfileString("Function Locations","ConvertItemTags","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CONVERTITEMTAGS = (DWORD)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","ProcessGameEvents","0",szBuffer,MAX_STRING,ClientINI); ProcessGameEvents = (fEQProcGameEvts)strtoul(szBuffer,NULL,16);
	GetPrivateProfileString("Function Locations","SendMessage","0",szBuffer,MAX_STRING,ClientINI); send_message = (fEQSendMessage)strtoul(szBuffer,NULL,16);
    GetPrivateProfileString("Function Locations","NewUIINI","0",szBuffer,MAX_STRING,ClientINI);         NewUIINI = (fEQNewUIINI)strtoul(szBuffer,NULL,16);
/**/


// CEverQuest
#define CEverQuest__dsp_chat					0x0049544B
//    GetPrivateProfileString("Function Locations","WriteChatColor","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_DSPCHAT = strtoul(szBuffer,NULL,16);
#define CEverQuest__ClickedPlayer			    0x00490D36
//    GetPrivateProfileString("Function Locations","ScreenSpawn","0",szBuffer,MAX_STRING,ClientINI);      ScreenSpawn = (fEQScreenSpawn)strtoul(szBuffer,NULL,16); // currently static
#define CEverQuest__EnterZone					0x0049621D
//    GetPrivateProfileString("Function Locations","Zoning","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_ZONING = (DWORD)strtoul(szBuffer,NULL,16);
#define CEverQuest__InterpretCmd				0x0049FFA6
//    GetPrivateProfileString("Function Locations","Commands","0",szBuffer,MAX_STRING,ClientINI);         EQADDR_COMMANDS = strtoul(szBuffer,NULL,16);
#define CEverQuest__RightClickedOnPlayer		0x0049BF25
//    GetPrivateProfileString("Function Locations","RClickTarget","0",szBuffer,MAX_STRING,ClientINI); EQADDR_RCLICKTARGET = (DWORD)strtoul(szBuffer,NULL,16);
#define	CEverQuest__LeftClickedOnPlayer			0x004A200A
//    GetPrivateProfileString("Function Locations","LClickTarget","0",szBuffer,MAX_STRING,ClientINI); EQADDR_LCLICKTARGET = (DWORD)strtoul(szBuffer,NULL,16);
#define	CEverQuest__GetRaceDesc					0x0048AEE1
//	GetPrivateProfileString("Function Locations","GetRaceByID","0",szBuffer,MAX_STRING,ClientINI);      GetRaceByID = (fEQGetStringByID)strtoul(szBuffer,NULL,16);// currently static
#define	CEverQuest__GetClassDesc				0x0048A697
//    GetPrivateProfileString("Function Locations","GetClassByID","0",szBuffer,MAX_STRING,ClientINI);     GetClassByID = (fEQGetStringByID)strtoul(szBuffer,NULL,16);// currently static
#define CEverQuest__GetDeityDesc				0x0048C55F
//    GetPrivateProfileString("Function Locations","GetDeityByID","0",szBuffer,MAX_STRING,ClientINI);     GetDeityByID = (fEQGetStringByID)strtoul(szBuffer,NULL,16);// currently static
#define CEverQuest__GetBodyTypeDesc				0x0048ABD9
//    GetPrivateProfileString("Function Locations","GetBodyTypeByID","0",szBuffer,MAX_STRING,ClientINI);  GetBodyTypeByID = (fEQGetStringByID)strtoul(szBuffer,NULL,16);// currently static


// EQ_Character
#define EQ_Character__Max_Mana					0x0041A9CA
//    GetPrivateProfileString("Function Locations","MaxMana","0",szBuffer,MAX_STRING,ClientINI);          EQADDR_MAXMANA = strtoul(szBuffer,NULL,16);
#define EQ_Character__Max_HP					0x0041A861
//    GetPrivateProfileString("Function Locations","EQCharacterMaxHP","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_GETMAXHP = (DWORD)strtoul(szBuffer,NULL,16);
#define EQ_Character__Cur_HP                    0x0041E537
//    GetPrivateProfileString("Function Locations","EQCharacterCurHP","0",szBuffer,MAX_STRING,ClientINI);             EQADDR_GETCURHP = (DWORD)strtoul(szBuffer,NULL,16);
#define EQ_Character__GetFocusCastingTimeModifier 0x0042568C
//    GetPrivateProfileString("Function Locations","GetFocusCastingTimeModifier","0",szBuffer,MAX_STRING,ClientINI);  EQADDR_GETFOCUSCASTINGTIMEMODIFIER = (DWORD)strtoul(szBuffer,NULL,16);
#define EQ_Character__GetAACastingTimeModifier	0x004259F8
//    GetPrivateProfileString("Function Locations","GetAACastingTimeModifier","0",szBuffer,MAX_STRING,ClientINI); EQADDR_GETAACASTINGTIMEMODIFIER = (DWORD)strtoul(szBuffer,NULL,16);
#define EQ_Character__CastSpell					0x004296EC
//    GetPrivateProfileString("Function Locations","CastSpell","0",szBuffer,MAX_STRING,ClientINI);        EQADDR_CASTSPELL = (DWORD)strtoul(szBuffer,NULL,16);


// CXStr
#define CXStr__CXStr3							0x00586BB0
//    GetPrivateProfileString("Function Locations","CXStrConstructor","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CXSTRCONSTRUCTOR = (DWORD)strtoul(szBuffer,NULL,16);
#define CXStr__dCXStr							0x00401076
//    GetPrivateProfileString("Function Locations","CXStrDeconstructor","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CXSTRCONSTRUCTOR = (DWORD)strtoul(szBuffer,NULL,16);
#define CXStr__operator_plus_equal1				0x00587C40
//    GetPrivateProfileString("Function Locations","CXStrAppend","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CXSTRAPPEND = (DWORD)strtoul(szBuffer,NULL,16); 
#define	CXStr__operator_equal1					0x00586D70
//    GetPrivateProfileString("Function Locations","CXStrSet","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CXSTRSET = (DWORD)strtoul(szBuffer,NULL,16); 

/*
// CStmlWnd
    GetPrivateProfileString("Function Locations","CStmlWndAppend","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_APPENDSTML = (DWORD)strtoul(szBuffer,NULL,16);
/**/

// CChatWindow
#define CChatWindow__CChatWindow				0x004D7D96
//    GetPrivateProfileString("Function Locations","CChatWindowConstructor","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CCHATWINDOWCONSTRUCTOR = (DWORD)strtoul(szBuffer,NULL,16);
#define CChatWindow__dCChatWindow				0x004D857B
//    GetPrivateProfileString("Function Locations","CChatWindowDeconstructor","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CCHATWINDOWDECONSTRUCTOR = (DWORD)strtoul(szBuffer,NULL,16);
/**/

// CChatManager
#define CChatManager__InitContextMenu			0x004D52BE
//    GetPrivateProfileString("Function Locations","CChatManagerInitContextMenu","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CHATMANAGERINITCONTEXTMENU = (DWORD)strtoul(szBuffer,NULL,16);
#define CChatManager__GetRGBAFromIndex			0x004D4986
//    GetPrivateProfileString("Function Locations","CChatManagerGetRGBAFromIndex","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_CCHATMANAGERGETRGBAFROMINDEX = (DWORD)strtoul(szBuffer,NULL,16);
/**/

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem				0x004F322D
//    GetPrivateProfileString("Function Locations","ItemDisplaySetItem","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_ITEMDISPLAYSETITEM = (DWORD)strtoul(szBuffer,NULL,16); 

/*
// CLabel
    GetPrivateProfileString("Function Locations","CLabelDraw","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_EQLABELS = (DWORD)strtoul(szBuffer,NULL,16);
/**/

// CDisplay
#define CDisplay__CleanGameUI					0x0040FC97
//	GetPrivateProfileString("Function Locations","CleanGameUI","0",szBuffer,MAX_STRING,ClientINI); EQADDR_CLEANUI = (DWORD)strtoul(szBuffer,NULL,16);
#define CDisplay__GetClickedActor				0x0040BB73
//    GetPrivateProfileString("Function Locations","ScreenItem","0",szBuffer,MAX_STRING,ClientINI);       ScreenItem = (fEQScreenItem)strtoul(szBuffer,NULL,16);

/*
// MapViewMap
    GetPrivateProfileString("Function Locations","WriteMapfile","0",szBuffer,MAX_STRING,ClientINI); EQADDR_WRITEMAPFILE = (DWORD)strtoul(szBuffer,NULL,16);
/**/
#define EQ_Item__GetItemLinkHash				0x0042EDC4
// EQ_Item
//    GetPrivateProfileString("Function Locations","GetItemLinkHash","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_GETITEMLINKHASH = (DWORD)strtoul(szBuffer,NULL,16);


// CBankWnd
#define CBankWnd__GetNumBankSlots				0x004C4C35
//    GetPrivateProfileString("Function Locations","GetNumBankSlots","0",szBuffer,MAX_STRING,ClientINI);   EQADDR_GETNUMBANKSLOTS = (DWORD)strtoul(szBuffer,NULL,16);


// CMerchantWnd
#define CMerchantWnd__SelectBuySellSlot			0x0050022A
//    GetPrivateProfileString("Function Locations","SelectItem","0",szBuffer,MAX_STRING,ClientINI);      cmdSelectItem = (fEQSelectItem)strtoul(szBuffer,NULL,16);
#define CMerchantWnd__RequestBuyItem			0x004FFB45
//    GetPrivateProfileString("Function Locations","BuyItem","0",szBuffer,MAX_STRING,ClientINI);         cmdBuyItem = (fEQBuyItem)strtoul(szBuffer,NULL,16);
#define CMerchantWnd__RequestSellItem			0x004FFD3E
//    GetPrivateProfileString("Function Locations","SellItem","0",szBuffer,MAX_STRING,ClientINI);         cmdSellItem = (fEQSellItem)strtoul(szBuffer,NULL,16);


// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet				0x0051081C
//    GetPrivateProfileString("Function Locations","LoadSpells","0",szBuffer,MAX_STRING,ClientINI);       cmdLoadSpells = (fEQLoadSpells)strtoul(szBuffer,NULL,16);

