#ifdef PRIVATE
#include "eqgame-private.h"
#endif

#define pinstCContainerMgr                                      0x621430 
#define pinstCSocialEditWnd                                     0x6213EC 
#define pinstCInspectWnd                                        0x6213E8 
#define pinstCTrackingWnd                                       0x6213E4 
#define pinstCGemsGameWnd                                       0x62140C 
#define pinstCBazaarWnd                                         0x6213D8 
#define pinstCBazaarSearchWnd                                   0x6213DC 
#define pinstCTradeWnd                                          0x6213D0 
#define pinstCGiveWnd                                           0x6213E0 
#define pinstCMerchantWnd                                       0x6213CC 
#define pinstCLootWnd                                           0x6213C0 
#define pinstCBankWnd                                           0x6213B8 
#define pinstCInventoryWnd                                      0x6213B4 
#define pinstCSpellBookWnd                                      0x6213B0 
#define pinstCCastSpellWnd                                      0x6213AC 
#define pinstCCastingWnd                                        0x6213A8 
#define pinstCCursorAttachment                                  0x6213A4 
#define pinstCJournalCatWnd                                     0x621424 
#define pinstCContextMenuManager                                0x7A86C0 
#define pinstCChatManager                                       0x79cfb0 
#define pinstCBuffWindowSHORT                                   0x621398 
#define pinstCBuffWindowNORMAL                                  0x62139C 
//something missing here 
#define pinstCPopupWndManager                                   0x79D404 
#define pinstCNoteWnd                                           0x621334 
#define pinstCHelpWnd                                           0x621338 
#define pinstCTipWndCONTEXT                                     0x79DD08 
#define pinstCTipWndOFDAY                                       0x79DD04 
#define pinstCBookWnd                                           0x62133C 
#define pinstCFriendsWnd                                        0x621354 
#define pinstCMusicPlayerWnd                                    0x621368 
#define pinstCAlarmWnd                                          0x621364 
#define pinstCLoadskinWnd                                       0x621360 
#define pinstCPetInfoWnd                                        0x621340 
#define pinstCTrainWnd                                          0x621344 
#define pinstCSkillsWnd                                         0x621348 
#define pinstCSkillsSelectWnd                                   0x62134C 
#define pinstCCombatSkillSelectWnd                              0x621350 
#define pinstCAAWnd                                             0x621358 
#define pinstCGroupWnd                                          0x79D1A0 
#define pinstCGroupSearchWnd                                    0x79D188 
#define pinstCGroupSearchFiltersWnd                             0x62135C 
#define pinstCRaidWnd                                           0x62136C 
#define pinstCRaidOptionsWnd                                    0x621370 
#define pinstCBreathWnd                                         0x621374 
#define pinstCMapViewWnd                                        0x621378 
#define pinstCMapToolbarWnd                                     0x62137C 
#define pinstCEditLabelWnd                                      0x621380 
#define pinstCTargetWnd                                         0x621384 
#define pinstCColorPickerWnd                                    0x62138C 
#define pinstCHotButtonWnd                                      0x621388 
#define pinstCPlayerWnd                                         0x621390 
#define pinstCConfirmationDialog                                0x621328
#define pinstCFacePick                                          0x62132C 
#define pinstCQuantityWnd                                       0x621330   
#define pinstCTextEntryWnd                                      0x6213BC   
#define pinstCFileSelectionWnd                                  0x6213FC   
#define pinstCActionsWnd                                        0x621400   
#define pinstCCombatAbilityWnd                                  0x6213C4   
#define pinstCSelectorWnd                                       0x6213C8  
#define pinstCCompassWnd                                        0x6213D4   
#define pinstCJournalTextWnd                                    0x621404   
#define pinstCStoryWnd                                          0x621420   
//same here 
#define pinstCFindLocationWnd                                   0x79D10C 
#define pinstCBodyTintWnd                                       0x621428 
#define pinstCGuildMgmtWnd                                      0x79D1B8 
#define pinstCAdventureRequestWnd                               0x79CD48 
#define pinstCAdventureMerchantWnd                              0x79CD30 
#define pinstCAdventureStatsWnd                                 0x79CD60 
#define pinstCAdventureLeaderboardWnd                           0x79CD18 
#define pinstCSystemInfoDialogBox                               0x79DC84 
#define pinstCTributeBenefitWnd                                 0x79DD74 
#define pinstCLeadershipWindow                                  0x79D2B4 
#define pinstCTributeMasterWnd                                  0x79DD8C 
#define pinstCInvSlotMgr                                        0x62142C 
#define pinstCOptionsWnd                                        0x621394 
#define pinstCFeedbackWnd                                       0x6213F0 
#define pinstCBugReportWnd                                      0x6213F4 
#define pinstCVideoModesWnd                                     0x6213F8 
#define pinstCPlayerNotesWnd                                    0x621408 
#define pinstCTimeLeftWnd                                       0x621410 
#define pinstCPetitionQWnd                                      0x621414 
#define pinstCSoulmarkWnd                                       0x621418                    

#define pinstCSidlManager										0x7A86A4 
#define pinstCDisplay											0x736C3C 
#define pinstCEverQuest											0x7946B8 
#define pinstPCData												0x736C18 
#define pinstCharData											0x736C18      
#define pinstCharSpawn											0x736C10 
#define pinstSpawnList											0x736BD8 
#define pinstSpawnListTail										0x736BFC 
#define pinstWorldData											0x736BD4 
#define pinstSpellManager										0x791114 
#define pinstActiveMerchant										0x736C28  
#define pinstSelectedItem										0x79D234 
#define pinstGroup												0x7352A8 
#define pinstTarget												0x736C1C              
#define pinstSwitchManager										0x6D4480 
#define pinstEQItemList											0x736BDC 
#define pinstSpellSets											0x7349D4 

#define instEQZoneInfo											0x6D4704        

// Static functions 
#define DrawNetStatus											0x4B325F 
#define CrashDetected											0x4C38B2 

// EQ_LoadingS 
#define EQ_LoadingS__WriteTextHD								0x432A00 

// CEverQuest 
#define CEverQuest__dsp_chat                     0x499DF9 
#define CEverQuest__ClickedPlayer                0x497826 
#define CEverQuest__EnterZone                    0x49AC4D 
#define CEverQuest__InterpretCmd                 0x4A6B0B 
#define CEverQuest__RightClickedOnPlayer         0x4A2A05 
#define CEverQuest__LeftClickedOnPlayer          0x4A8CD0 
#define CEverQuest__GetRaceDesc                  0x491AC9 
#define CEverQuest__GetClassDesc                 0x491246 
#define CEverQuest__GetDeityDesc                 0x493257 
#define CEverQuest__GetBodyTypeDesc              0x491661 
#define CEverQuest__SetGameState                 0x49798D 

// EQ_Character 
#define EQ_Character__Max_Mana                   0x41E1F4 
#define EQ_Character__Max_HP                     0x41DFE7 
#define EQ_Character__Cur_HP                     0x421A0D 
#define EQ_Character__GetFocusCastingTimeModifier 0x4291AE 
#define EQ_Character__GetAACastingTimeModifier   0x42953B 
#define EQ_Character__CastSpell                  0x42D068 

// CXStr 
#define CXStr__CXStr                             0x40104C
#define CXStr__CXStr1							 0x401046 
#define CXStr__CXStr3                            0x59B950 
#define CXStr__dCXStr							 0x4CE35B
#define CXStr__operator_plus_equal1              0x59C9E0 
#define CXStr__operator_equal1                   0x59BB10

// CStmlWnd 
#define CStmlWnd__AppendSTML                     0x565D80 

// CChatWindow 
#define CChatWindow__CChatWindow                 0x4DF979 
#define CChatWindow__dCChatWindow                0x4B9619 

// CChatManager 
#define CChatManager__InitContextMenu            0x4DCEA1 
#define CChatManager__GetRGBAFromIndex           0x4DC53D 

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot				 0x4FA8F1 
#define CInvSlotMgr__MoveItem					 0x4fa29c 

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                 0x4FD3BB 
#define CItemDisplayWnd__SetSpell				 0x4FC923

// CLabel 
#define CLabel__Draw                             0x503219 

// CDisplay 
#define CDisplay__ReloadUI                       0x41865A 
#define CDisplay__CleanGameUI                    0x411813 
#define CDisplay__GetClickedActor                0x40D614 
#define CDisplay__WriteTextHD2                   0x41220F 
#define CDisplay__GetWorldFilePath               0x40BCB4

// EQ_Item 
#define EQ_Item__GetItemLinkHash                 0x432464 

// CBankWnd 
#define CBankWnd__GetNumBankSlots                0x4CE447 

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg        0x4D0B17 

// CMerchantWnd 
#define CMerchantWnd__SelectBuySellSlot          0x50B8EA 
#define CMerchantWnd__RequestBuyItem             0x50AAFB 
#define CMerchantWnd__RequestSellItem            0x50AE6A 

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet               0x51CD44 

// MapViewMap 
#define MapViewMap__SaveEx                       0x5066C0 
#define EQ_PC__DestroyHeldItemOrMoney            0x435308 

// CSidlScreenWnd 
#define CSidlScreenWnd__CSidlScreenWnd1          0x550970 
#define CSidlScreenWnd__dCSidlScreenWnd          0x550010 
#define CSidlScreenWnd__CreateChildrenFromSidl   0x54F390 
#define CSidlScreenWnd__GetChildItem             0x54ECF0 
#define CSidlScreenWnd__WndNotification          0x54EF10 
#define CSidlScreenWnd__CalculateHSBRange        0x54E4C0 
#define CSidlScreenWnd__CalculateVSBRange        0x54E580 
#define CSidlScreenWnd__ConvertToRes             0x54EC70 
#define CSidlScreenWnd__CSidlScreenWnd2          0x550970 
#define CSidlScreenWnd__DrawBackground           0x5501A0 
#define CSidlScreenWnd__DrawSidlPiece            0x54EFB0 
#define CSidlScreenWnd__EnableIniStorage         0x54EC20 
#define CSidlScreenWnd__GetSidlPiece             0x54F250 
#define CSidlScreenWnd__HandleRButtonDown        0x54ED60 
#define CSidlScreenWnd__Init1                    0x550530 
#define CSidlScreenWnd__LoadIniInfo              0x54F440 
#define CSidlScreenWnd__LoadIniListWnd           0x54FD70 
#define CSidlScreenWnd__LoadSidlScreen           0x54EE40 
#define CSidlScreenWnd__OnResize                 0x54E630 
#define CSidlScreenWnd__SetScreen                0x550130 
#define CSidlScreenWnd__StoreIniInfo             0x54E7B0 
#define CSidlScreenWnd__StoreIniListWnd          0x54FE20 

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1   0x575110 

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead			 0x55c8c0         

// CXWnd 
#define CXWnd__GetInnerRect						0x403d4a 
#define CXWnd__PostDraw							0x4ad5c3 
#define CXWnd__DrawChildren						0x555420 
#define CXWnd__GetWindowTextA					0x4c8f3a 
#define CXWnd__GetHitTestRect					0x551f90 
#define CXWnd__SetFocus							0x552c10 
#define CXWnd__SetKeyTooltip					0x551970 
#define CXWnd__GetFirstChildWnd					0x550f90 
#define CXWnd__GetNextSib						0x550fb0 
#define CXWnd__DrawTooltip						0x555190 
#define CXWnd__GetXMLTooltip					0x550c80 
#define CXWnd__GetCursorToDisplay				0x550fd0 
#define CXWnd__HitTest							0x5541e0 
#define CXWnd__Move								0x553b40 
#define CXWnd__DoAllDrawing						0x555270 
#define CXWnd__DrawTileBox						0x552e00 
#define CXWnd__DrawCloseBox						0x552ee0 
#define CXWnd__DrawMinimizeBox					0x552d20 
#define CXWnd__Resize							0x554b60 
#define CXWnd__GetMinimizedRect					0x553cd0 
#define CXWnd__Bottom							0x5549e0 
#define CXWnd__DrawNC							0x554ef0 
#define CXWnd__SetAttributesFromSidl			0x554aa0 
#define CXWnd__Left								0x554840 
#define CXWnd__RequestDockInfo					0x551f10 
#define CXWnd__GetScreenRect					0x5516e0 
#define CXWnd__GetClientClipRect				0x551450 
#define CXWnd__ProcessTransition				0x553d20 
#define CXWnd__GetScreenClipRect				0x554a30 
#define CXWnd__DrawTitleBar						0x552fc0 
#define CXWnd__Move1							0x553bd0 
#define CXWnd__Center							0x554770 
#define CXWnd__Right							0x554770 
#define CXWnd__DrawBackground					0x554440 
#define CXWnd__DrawHScrollbar					0x553620 
#define CXWnd__DrawVScrollbar					0x553220 
#define CXWnd__IsReallyVisible					0x550f60 
#define CXWnd__GetChildWndAt					0x554160 
#define CXWnd__SetMouseOver						0x551950 
#define CXWnd__IsValid							0x403d0e 
#define CXWnd__GetTooltip						0x550e90 
#define CXWnd__GetDragDropCursor				0x551400 
#define CXWnd__Deactivate						0x54e7a0 
#define CXWnd__DrawCursor						0x550eb0 
#define CXWnd__GetCloseBoxTemplate				0x551570 
#define CXWnd__GetTileBoxTemplate				0x5515c0 
#define CXWnd__GetMinimizeBoxTemplate			0x5515a0 
#define CXWnd__BringToTop						0x550f00 
#define CXWnd__DrawLasso						0x554300 
#define CXWnd__GetNextChildWnd					0x554140 
#define CXWnd__SetFirstChildPointer				0x551930 
#define CXWnd__SetNextSibPointer				0x551940 
#define CXWnd__GetClientRect					0x403d4f 
#define CXWnd__DrawColoredRect					0x551110 
#define CXWnd__QueryDropOK						0x5513c0 
#define CXWnd__QueryClickStickDropOK			0x551410 
#define CXWnd__GetUntileSize					0x403d30 
#define CXWnd__StartFade						0x550f20 
#define CXWnd__IsDescendantOf					0x5514d0 
#define CXWnd__ClrFocus							0x550e40 
#define CXWnd__GetTooltipRect					0x551320 
#define CXWnd__IsActive							0x5514c0 
#define CXWnd__Refade							0x550ee0 
#define CXWnd__GetBorderFrame					0x551510 
#define CXWnd__SetVScrollPos					0x5512e0 
#define CXWnd__DrawTooltipAtPoint				0x5545a0

// CSliderWnd 
#define CSliderWnd__GetValue					0x5808d0 
#define CSliderWnd__UpdateThumb					0x5808b0 
#define CSliderWnd__SetValue					0x580aa0                 

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars				0x4cdfa9 
#define CEditBaseWnd__SetSel					0x577090 

// CComboWnd 
#define CComboWnd__HitTest						0x4d4d21 
#define CComboWnd__DeleteAll					0x57bff0 
#define CComboWnd__InsertChoice					0x57c640 
#define CComboWnd__Draw							0x57c1f0 
#define CComboWnd__GetButtonRect				0x57c020 
#define CComboWnd__GetTextRect					0x57c080 
#define CComboWnd__GetListRect					0x57c5e0 
#define CComboWnd__GetCurChoice					0x57bfb0 
#define CComboWnd__SetColors					0x57BF80

// CListWnd 
#define CListWnd__CalculateFirstVisibleLine		0x567960 
#define CListWnd__Sort							0x576cc0 
#define CListWnd__DrawSeparator					0x520017 
#define CListWnd__ShiftColumnSeparator			0x568850 
#define CListWnd__GetItemText					0x566b20 
#define CListWnd__ExtendSel						0x5688e0 
#define CListWnd__SetItemColor					0x569f70 
#define CListWnd__DrawColumnSeparators			0x561110 
#define CListWnd__CalculateLineHeights			0x567900 
#define CListWnd__SetItemText					0x569eb0 
#define CListWnd__CloseAndUpdateEditWindow      0x567f60 
#define CListWnd__Compare						0x5682a0 
#define CListWnd__CalculateVSBRange				0x5694d0 
#define CListWnd__GetItemHeight					0x567790 
#define CListWnd__AddLine						0x56a330 
#define CListWnd__AddString						0x56a4b0 
#define CListWnd__Draw							0x569130 
#define CListWnd__ClearAllSel					0x567190 
#define CListWnd__GetSelList					0x56a650 
#define CListWnd__GetItemAtPoint				0x567c60 
#define CListWnd__GetItemAtPoint1				0x567cd0 
#define CListWnd__GetSeparatorRect				0x5681f0 
#define CListWnd__EnsureVisible					0x5679b0 
#define CListWnd__GetHeaderRect					0x5668e0 
#define CListWnd__DrawHeader					0x569060 
#define CListWnd__GetItemRect					0x567a80 
#define CListWnd__DrawBackground				0x566920 
#define CListWnd__DrawLine						0x568d00 
#define CListWnd__DrawItem						0x568a8c 
#define CListWnd__SetVScrollPos					0x568440 
#define CListWnd__GetColumnMinWidth				0x566d90 
#define CListWnd__ToggleSel						0x5670d0 
#define CListWnd__SetCurSel						0x5670b0 
#define CListWnd__GetItemData					0x566ae0 
#define CListWnd__GetItemIcon					0x566ba0 
#define CListWnd__SetItemData					0x567240 
#define CListWnd__IsLineEnabled					0x567280 
#define CListWnd__GetColumnWidth				0x566cc0 
#define CListWnd__GetColumnFlags				0x566c60 
#define CListWnd__SetColumnWidth				0x566d40 
#define CListWnd__GetCurSel						0x566aa0 
#define CListWnd__GetCursorToDisplay			0x5669b0 
#define CListWnd__SetColors						0x566850 

// CEditWnd 
#define CEditWnd__GetLineForPrintableChar       0x57d370 
#define CEditWnd__PointFromPrintableChar        0x57d480 
#define CEditWnd__GetCharIndexPt				0x57d8c0 
#define CEditWnd__SetWindowTextA				0x586690 
#define CEditWnd__DrawMultiline					0x58e450 
#define CEditWnd__GetHorzOffset					0x594f10 
#define CEditWnd__GetSTMLSafeText				0x57d030 
#define CEditWnd__DrawCaret						0x57ca80 
#define CEditWnd__SetEditable					0x57d000 
#define CEditWnd__GetCaretPt					0x57e370 
#define CEditWnd__SelectableCharFromPoint       0x5874b0 
#define CEditWnd__GetSelStartPt					0x57dae0 
#define CEditWnd__GetSelEndPt					0x57db00 
#define CEditWnd__GetDisplayString				0x57D350        
            

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect					0x4ebd81 
#define CGaugeWnd__CalcLinesFillRect			0x4ebddd 
#define CGaugeWnd__SetAttributesFromSidl        0x51dc01 
#define CGaugeWnd__Draw							0x4ec0dd      

// CStmlWnd 
#define CStmlWnd__GetCursorToDisplay			0x561140 
#define CStmlWnd__GetSTMLText					0x4df95b 
#define CStmlWnd__GetVisiableText				0x52094d 
#define CStmlWnd__CanBreakAtCharacter			0x55d990 
#define CStmlWnd__GetThisChar					0x55d690 
#define CStmlWnd__InitializeWindowVariables     0x561c50 
#define CStmlWnd__FastForwardPastSpaces         0x55e390 
#define CStmlWnd__GetNextTagPiece				0x55e500 
#define CStmlWnd__GetNextChar					0x55de50 
#define CStmlWnd__UpdateHistoryString			0x55ccc0 
#define CStmlWnd__MakeStmlColorTag				0x55ce20 
#define CStmlWnd__FastForwardToEndOfTag         0x55e6f0 
#define CStmlWnd__MakeWndNotificationTag        0x55cec0 
#define CStmlWnd__StripFirstSTMLLines			0x565b00 
#define CStmlWnd__CalculateHSBRange				0x55d850 
#define CStmlWnd__CalculateVSBRange				0x55d7f0 
#define CStmlWnd__InitializeTempVariables       0x55d640 
#define CStmlWnd__CanGoBackward					0x55da10        

// CTabWnd 
#define CTabWnd__Draw							0x57bcd0 
#define CTabWnd__GetPageFromTabIndex			0x57aff0 
#define CTabWnd__InsertPage						0x57bbc0 
#define CTabWnd__SetPage						0x57b2a0 
#define CTabWnd__UpdatePage						0x57b460 
#define CTabWnd__SetPageRect					0x57b3b0 
#define CTabWnd__GetTabInnerRect				0x57b200 
#define CTabWnd__GetPageInnerRect				0x57af30 
#define CTabWnd__GetTabRect						0x57b100 
#define CTabWnd__DrawCurrentPage				0x57b7c0 
#define CTabWnd__DrawTab						0x57b540 
#define CTabWnd__GetPageClientRect				0x57aed0 
#define CTabWnd__IndexInBounds					0x57afd0 
#define CTabWnd__GetNumTabs						0x57afc0 
#define CTabWnd__GetCurrentTabIndex				0x57aec0 
#define CTabWnd__GetCurrentPage					0x57b0f0                    
