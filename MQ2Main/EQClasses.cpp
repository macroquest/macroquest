/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2004 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW


#include "MQ2Main.h"

// MANUAL IMPORTS
#ifdef EQ_Item__GetItemLinkHash
REVERSE_DETOUR(char * EQ_Item::GetItemLinkHash(char *),EQ_Item__GetItemLinkHash); // Lax 11-14-2003
#endif
#ifdef CStmlWnd__AppendSTML
REVERSE_DETOUR(class CXSize& CStmlWnd::AppendSTML(class CXSize*,class CXStr),CStmlWnd__AppendSTML);
#endif

REVERSE_VIRTUAL_DETOUR(void CChatWindow::operator delete[](void*),0x04);

REVERSE_VIRTUAL_DETOUR(bool CXWnd::IsValid(void)const,0);
REVERSE_VIRTUAL_DETOUR(int CXWnd::WndNotification(class CXWnd *,unsigned __int32,void *),0x80);
REVERSE_VIRTUAL_DETOUR(int CXWnd::Show(bool,bool),0x0C0);
REVERSE_VIRTUAL_DETOUR(int CXWnd::SetVScrollPos(int),0x100);
REVERSE_VIRTUAL_DETOUR(void CXWnd::SetWindowTextA(class CXStr),0xfc);

REVERSE_VIRTUAL_DETOUR(int CXWnd::HandleLButtonDown(class CXPoint *),0x34);
REVERSE_VIRTUAL_DETOUR(int CXWnd::HandleLButtonUp(class CXPoint *),0x38);
REVERSE_VIRTUAL_DETOUR(int CXWnd::HandleLButtonHeld(class CXPoint *),0x3C);
REVERSE_VIRTUAL_DETOUR(int CXWnd::HandleLButtonUpAfterHeld(class CXPoint *),0x40);
REVERSE_VIRTUAL_DETOUR(int CXWnd::HandleRButtonDown(class CXPoint *),0x44);
REVERSE_VIRTUAL_DETOUR(int CXWnd::HandleRButtonUp(class CXPoint *),0x48);
REVERSE_VIRTUAL_DETOUR(int CXWnd::HandleRButtonHeld(class CXPoint *),0x4C);
REVERSE_VIRTUAL_DETOUR(int CXWnd::HandleRButtonUpAfterHeld(class CXPoint *),0x50);


REVERSE_VIRTUAL_DETOUR(void CListWnd::DeleteAll(void),0x124);


// AUTO IMPORTS

#ifdef CAAWnd__CAAWnd
REVERSE_DETOUR( CAAWnd::CAAWnd(class CXWnd *),CAAWnd__CAAWnd);
#endif
#ifdef CAAWnd__Update
REVERSE_DETOUR(void  CAAWnd::Update(void),CAAWnd__Update);
#endif
#ifdef CAAWnd__UpdateSelected
REVERSE_DETOUR(void  CAAWnd::UpdateSelected(void),CAAWnd__UpdateSelected);
#endif
#ifdef CAAWnd__UpdateTimer
REVERSE_DETOUR(void  CAAWnd::UpdateTimer(void),CAAWnd__UpdateTimer);
#endif
#ifdef CAAWnd__Init
REVERSE_DETOUR(void  CAAWnd::Init(void),CAAWnd__Init);
#endif
#ifdef CAAWnd__Activate
REVERSE_DETOUR(void  CAAWnd::Activate(void),CAAWnd__Activate);
#endif
#ifdef CAAWnd__ShowAbility
REVERSE_DETOUR(void  CAAWnd::ShowAbility(int),CAAWnd__ShowAbility);
#endif
#ifdef CAAWnd__SendNewPercent
REVERSE_DETOUR(void  CAAWnd::SendNewPercent(void),CAAWnd__SendNewPercent);
#endif
#ifdef CAAWnd__ConfirmAASpend
REVERSE_DETOUR(void  CAAWnd::ConfirmAASpend(void),CAAWnd__ConfirmAASpend);
#endif
#ifdef CXStr__CXStr
REVERSE_DETOUR( CXStr::CXStr(class CXStr const &),CXStr__CXStr);
#endif
#ifdef CXMLSOMCursor__dCXMLSOMCursor
REVERSE_DETOUR( CXMLSOMCursor::~CXMLSOMCursor(void),CXMLSOMCursor__dCXMLSOMCursor);
#endif
#ifdef CKeyCXStrValueInt32__dCKeyCXStrValueInt32
REVERSE_DETOUR( CKeyCXStrValueInt32::~CKeyCXStrValueInt32(void),CKeyCXStrValueInt32__dCKeyCXStrValueInt32);
#endif
#ifdef COptionsWnd__KeyboardAssignmentData__dKeyboardAssignmentData
//REVERSE_DETOUR( COptionsWnd::KeyboardAssignmentData::~KeyboardAssignmentData(void),COptionsWnd__KeyboardAssignmentData__dKeyboardAssignmentData);
#endif
#ifdef CXStr__dCXStr
REVERSE_DETOUR( CXStr::~CXStr(void),CXStr__dCXStr);
#endif
#ifdef CUITextureInfo__CUITextureInfo
REVERSE_DETOUR( CUITextureInfo::CUITextureInfo(class CXStr,int),CUITextureInfo__CUITextureInfo);
#endif
#ifdef CXMLSOMNodePtr__dCXMLSOMNodePtr
REVERSE_DETOUR( CXMLSOMNodePtr::~CXMLSOMNodePtr(void),CXMLSOMNodePtr__dCXMLSOMNodePtr);
#endif
#ifdef CXMLSOMNode__dCXMLSOMNode
REVERSE_DETOUR( CXMLSOMNode::~CXMLSOMNode(void),CXMLSOMNode__dCXMLSOMNode);
#endif
#ifdef CXMLSOMAttribute__dCXMLSOMAttribute
REVERSE_DETOUR( CXMLSOMAttribute::~CXMLSOMAttribute(void),CXMLSOMAttribute__dCXMLSOMAttribute);
#endif
#ifdef CActionsWnd__CActionsWnd
REVERSE_DETOUR( CActionsWnd::CActionsWnd(class CXWnd *),CActionsWnd__CActionsWnd);
#endif
#ifdef CActionsWnd__Activate
REVERSE_DETOUR(void  CActionsWnd::Activate(int),CActionsWnd__Activate);
#endif
#ifdef CActionsWnd__UpdateButtonText
REVERSE_DETOUR(void  CActionsWnd::UpdateButtonText(void),CActionsWnd__UpdateButtonText);
#endif
#ifdef CActionsWnd__GetCurrentPageEnum
REVERSE_DETOUR(int  CActionsWnd::GetCurrentPageEnum(void)const ,CActionsWnd__GetCurrentPageEnum);
#endif
#ifdef CActionsWnd__KeyMapUpdated
REVERSE_DETOUR(void  CActionsWnd::KeyMapUpdated(void),CActionsWnd__KeyMapUpdated);
#endif
#ifdef CActionsWnd__SelectSkillForAbilityBtn
REVERSE_DETOUR(void  CActionsWnd::SelectSkillForAbilityBtn(int),CActionsWnd__SelectSkillForAbilityBtn);
#endif
#ifdef CActionsWnd__GetAbilityBtn
REVERSE_DETOUR(class CButtonWnd *  CActionsWnd::GetAbilityBtn(int),CActionsWnd__GetAbilityBtn);
#endif
#ifdef CActionsWnd__SelectSkillForCombatBtn
REVERSE_DETOUR(void  CActionsWnd::SelectSkillForCombatBtn(int),CActionsWnd__SelectSkillForCombatBtn);
#endif
#ifdef CActionsWnd__GetCombatBtn
REVERSE_DETOUR(class CButtonWnd *  CActionsWnd::GetCombatBtn(int),CActionsWnd__GetCombatBtn);
#endif
#ifdef CActionsWnd__GetMenuBtn
REVERSE_DETOUR(class CButtonWnd *  CActionsWnd::GetMenuBtn(int),CActionsWnd__GetMenuBtn);
#endif
#ifdef CActionsWnd__RedirectActivateTo
REVERSE_DETOUR(int  CActionsWnd::RedirectActivateTo(class CPageWnd *),CActionsWnd__RedirectActivateTo);
#endif
#ifdef CActionsWnd__RedirectDeactivateTo
REVERSE_DETOUR(int  CActionsWnd::RedirectDeactivateTo(class CPageWnd *),CActionsWnd__RedirectDeactivateTo);
#endif
#ifdef CActionsWnd__RedirectOnProcessFrameTo
REVERSE_DETOUR(int  CActionsWnd::RedirectOnProcessFrameTo(class CPageWnd *),CActionsWnd__RedirectOnProcessFrameTo);
#endif
#ifdef CActionsWnd__RedirectWndNotificationTo
REVERSE_DETOUR(int  CActionsWnd::RedirectWndNotificationTo(class CPageWnd *,class CXWnd *,unsigned __int32,void *),CActionsWnd__RedirectWndNotificationTo);
#endif
#ifdef CActionsWnd__MainPageOnProcessFrame
REVERSE_DETOUR(int  CActionsWnd::MainPageOnProcessFrame(void),CActionsWnd__MainPageOnProcessFrame);
#endif
#ifdef CActionsWnd__MainPageWndNotification
REVERSE_DETOUR(int  CActionsWnd::MainPageWndNotification(class CXWnd *,unsigned __int32,void *),CActionsWnd__MainPageWndNotification);
#endif
#ifdef CActionsWnd__AbilitiesPageActivate
REVERSE_DETOUR(int  CActionsWnd::AbilitiesPageActivate(void),CActionsWnd__AbilitiesPageActivate);
#endif
#ifdef CActionsWnd__AbilitiesPageDeactivate
REVERSE_DETOUR(int  CActionsWnd::AbilitiesPageDeactivate(void),CActionsWnd__AbilitiesPageDeactivate);
#endif
#ifdef CActionsWnd__AbilitiesPageOnProcessFrame
REVERSE_DETOUR(int  CActionsWnd::AbilitiesPageOnProcessFrame(void),CActionsWnd__AbilitiesPageOnProcessFrame);
#endif
#ifdef CActionsWnd__AbilitiesPageWndNotification
REVERSE_DETOUR(int  CActionsWnd::AbilitiesPageWndNotification(class CXWnd *,unsigned __int32,void *),CActionsWnd__AbilitiesPageWndNotification);
#endif
#ifdef CActionsWnd__CombatPageActivate
REVERSE_DETOUR(int  CActionsWnd::CombatPageActivate(void),CActionsWnd__CombatPageActivate);
#endif
#ifdef CActionsWnd__CombatPageDeactivate
REVERSE_DETOUR(int  CActionsWnd::CombatPageDeactivate(void),CActionsWnd__CombatPageDeactivate);
#endif
#ifdef CActionsWnd__CombatPageOnProcessFrame
REVERSE_DETOUR(int  CActionsWnd::CombatPageOnProcessFrame(void),CActionsWnd__CombatPageOnProcessFrame);
#endif
#ifdef CActionsWnd__CombatPageWndNotification
REVERSE_DETOUR(int  CActionsWnd::CombatPageWndNotification(class CXWnd *,unsigned __int32,void *),CActionsWnd__CombatPageWndNotification);
#endif
#ifdef CActionsWnd__SocialsPageActivate
REVERSE_DETOUR(int  CActionsWnd::SocialsPageActivate(void),CActionsWnd__SocialsPageActivate);
#endif
#ifdef CActionsWnd__SocialsPageOnProcessFrame
REVERSE_DETOUR(int  CActionsWnd::SocialsPageOnProcessFrame(void),CActionsWnd__SocialsPageOnProcessFrame);
#endif
#ifdef CActionsWnd__SocialsPageWndNotification
REVERSE_DETOUR(int  CActionsWnd::SocialsPageWndNotification(class CXWnd *,unsigned __int32,void *),CActionsWnd__SocialsPageWndNotification);
#endif
#ifdef CAlarmWnd__CAlarmWnd
REVERSE_DETOUR( CAlarmWnd::CAlarmWnd(class CXWnd *),CAlarmWnd__CAlarmWnd);
#endif
#ifdef CAlarmWnd__Activate
REVERSE_DETOUR(void  CAlarmWnd::Activate(void),CAlarmWnd__Activate);
#endif
#ifdef CAlarmWnd__DoNeverButton
REVERSE_DETOUR(void  CAlarmWnd::DoNeverButton(void),CAlarmWnd__DoNeverButton);
#endif
#ifdef CEditBaseWnd__SetMaxChars
REVERSE_DETOUR(void  CEditBaseWnd::SetMaxChars(int),CEditBaseWnd__SetMaxChars);
#endif
#ifdef CBankWnd__CBankWnd
REVERSE_DETOUR( CBankWnd::CBankWnd(class CXWnd *,class CXStr),CBankWnd__CBankWnd);
#endif
#ifdef CBankWnd__Init
REVERSE_DETOUR(void  CBankWnd::Init(void),CBankWnd__Init);
#endif
#ifdef CBankWnd__Activate
REVERSE_DETOUR(void  CBankWnd::Activate(class EQPlayer *),CBankWnd__Activate);
#endif
#ifdef CBankWnd__Deactivate
REVERSE_DETOUR(void  CBankWnd::Deactivate(bool),CBankWnd__Deactivate);
#endif
#ifdef CBankWnd__ClickedMoneyButton
REVERSE_DETOUR(void  CBankWnd::ClickedMoneyButton(int,int),CBankWnd__ClickedMoneyButton);
#endif
#ifdef CBankWnd__GetBankQtyFromCoinType
REVERSE_DETOUR(long  CBankWnd::GetBankQtyFromCoinType(int),CBankWnd__GetBankQtyFromCoinType);
#endif
#ifdef CBankWnd__UpdateMoneyDisplay
REVERSE_DETOUR(void  CBankWnd::UpdateMoneyDisplay(void),CBankWnd__UpdateMoneyDisplay);
#endif
#ifdef CBankWnd__GetNumBankSlots
REVERSE_DETOUR(int  CBankWnd::GetNumBankSlots(void)const ,CBankWnd__GetNumBankSlots);
#endif
#ifdef CXRect__CenterPoint
REVERSE_DETOUR(class CXPoint  CXRect::CenterPoint(void)const ,CXRect__CenterPoint);
#endif
#ifdef CBazaarSearchWnd__CBazaarSearchWnd
REVERSE_DETOUR( CBazaarSearchWnd::CBazaarSearchWnd(class CXWnd *),CBazaarSearchWnd__CBazaarSearchWnd);
#endif
#ifdef CBazaarSearchWnd__InitListArray
REVERSE_DETOUR(void  CBazaarSearchWnd::InitListArray(void),CBazaarSearchWnd__InitListArray);
#endif
#ifdef CBazaarSearchWnd__Init
REVERSE_DETOUR(void  CBazaarSearchWnd::Init(void),CBazaarSearchWnd__Init);
#endif
#ifdef CBazaarSearchWnd__UpdatePlayerUpdateButton
REVERSE_DETOUR(void  CBazaarSearchWnd::UpdatePlayerUpdateButton(bool),CBazaarSearchWnd__UpdatePlayerUpdateButton);
#endif
#ifdef CBazaarSearchWnd__UpdatePlayerCombo
REVERSE_DETOUR(void  CBazaarSearchWnd::UpdatePlayerCombo(void),CBazaarSearchWnd__UpdatePlayerCombo);
#endif
#ifdef CBazaarSearchWnd__Activate
REVERSE_DETOUR(void  CBazaarSearchWnd::Activate(void),CBazaarSearchWnd__Activate);
#endif
#ifdef CBazaarSearchWnd__GetPriceString
REVERSE_DETOUR(char *  CBazaarSearchWnd::GetPriceString(unsigned long),CBazaarSearchWnd__GetPriceString);
#endif
#ifdef CBazaarSearchWnd__SortItemList
REVERSE_DETOUR(void  CBazaarSearchWnd::SortItemList(int),CBazaarSearchWnd__SortItemList);
#endif
#ifdef CBazaarSearchWnd__AddItemtoList
REVERSE_DETOUR(void  CBazaarSearchWnd::AddItemtoList(char *,unsigned long,char *,int,int),CBazaarSearchWnd__AddItemtoList);
#endif
#ifdef CBazaarSearchWnd__UpdateComboButtons
REVERSE_DETOUR(void  CBazaarSearchWnd::UpdateComboButtons(void),CBazaarSearchWnd__UpdateComboButtons);
#endif
#ifdef CBazaarSearchWnd__HandleBazaarMsg
REVERSE_DETOUR(void  CBazaarSearchWnd::HandleBazaarMsg(char *,int),CBazaarSearchWnd__HandleBazaarMsg);
#endif
#ifdef CBazaarSearchWnd__doQuery
REVERSE_DETOUR(void  CBazaarSearchWnd::doQuery(void),CBazaarSearchWnd__doQuery);
#endif
#ifdef CBazaarWnd__CBazaarWnd
REVERSE_DETOUR( CBazaarWnd::CBazaarWnd(class CXWnd *),CBazaarWnd__CBazaarWnd);
#endif
#ifdef CBazaarWnd__Init
REVERSE_DETOUR(void  CBazaarWnd::Init(void),CBazaarWnd__Init);
#endif
#ifdef CBazaarWnd__CreateBZRIniFilename
REVERSE_DETOUR(void  CBazaarWnd::CreateBZRIniFilename(void),CBazaarWnd__CreateBZRIniFilename);
#endif
#ifdef CBazaarWnd__AddBazaarText
REVERSE_DETOUR(void  CBazaarWnd::AddBazaarText(char *,int),CBazaarWnd__AddBazaarText);
#endif
#ifdef CBazaarWnd__ReturnItemByIndex
REVERSE_DETOUR(class EQ_Item *  CBazaarWnd::ReturnItemByIndex(int),CBazaarWnd__ReturnItemByIndex);
#endif
#ifdef CBazaarWnd__GetPriceString
REVERSE_DETOUR(char *  CBazaarWnd::GetPriceString(unsigned long),CBazaarWnd__GetPriceString);
#endif
#ifdef CBazaarWnd__HandleTraderMsg
REVERSE_DETOUR(void  CBazaarWnd::HandleTraderMsg(char *),CBazaarWnd__HandleTraderMsg);
#endif
#ifdef CBazaarWnd__RebuildItemArray
REVERSE_DETOUR(void  CBazaarWnd::RebuildItemArray(void),CBazaarWnd__RebuildItemArray);
#endif
#ifdef CBazaarWnd__BuildBazaarItemArray
REVERSE_DETOUR(void  CBazaarWnd::BuildBazaarItemArray(void),CBazaarWnd__BuildBazaarItemArray);
#endif
#ifdef CBazaarWnd__AddEquipmentToBazaarArray
REVERSE_DETOUR(void  CBazaarWnd::AddEquipmentToBazaarArray(class EQ_Item *,int,unsigned long),CBazaarWnd__AddEquipmentToBazaarArray);
#endif
#ifdef CBazaarWnd__Activate
REVERSE_DETOUR(void  CBazaarWnd::Activate(void),CBazaarWnd__Activate);
#endif
#ifdef CBazaarWnd__UpdatePriceButtons
REVERSE_DETOUR(void  CBazaarWnd::UpdatePriceButtons(void),CBazaarWnd__UpdatePriceButtons);
#endif
#ifdef CBazaarWnd__StoreSelectedPrice
REVERSE_DETOUR(bool  CBazaarWnd::StoreSelectedPrice(void),CBazaarWnd__StoreSelectedPrice);
#endif
#ifdef CBazaarWnd__UpdateButtons
REVERSE_DETOUR(void  CBazaarWnd::UpdateButtons(void),CBazaarWnd__UpdateButtons);
#endif
#ifdef CBazaarWnd__SelectBazaarSlotItem
REVERSE_DETOUR(void  CBazaarWnd::SelectBazaarSlotItem(int,class CTextureAnimation *),CBazaarWnd__SelectBazaarSlotItem);
#endif
#ifdef CBazaarWnd__SetMoneyButton
REVERSE_DETOUR(void  CBazaarWnd::SetMoneyButton(int,int),CBazaarWnd__SetMoneyButton);
#endif
#ifdef CBazaarWnd__GetQtyFromCoinType
REVERSE_DETOUR(long  CBazaarWnd::GetQtyFromCoinType(int),CBazaarWnd__GetQtyFromCoinType);
#endif
#ifdef CBazaarWnd__ClickedMoneyButton
REVERSE_DETOUR(void  CBazaarWnd::ClickedMoneyButton(int,int),CBazaarWnd__ClickedMoneyButton);
#endif
#ifdef CBazaarWnd__GetPrice
REVERSE_DETOUR(unsigned long  CBazaarWnd::GetPrice(void),CBazaarWnd__GetPrice);
#endif
#ifdef CBazaarWnd__UpdateBazaarListtoServer
REVERSE_DETOUR(int  CBazaarWnd::UpdateBazaarListtoServer(void),CBazaarWnd__UpdateBazaarListtoServer);
#endif
#ifdef CBazaarWnd__ToggleBzrItemActive
REVERSE_DETOUR(void  CBazaarWnd::ToggleBzrItemActive(int,bool),CBazaarWnd__ToggleBzrItemActive);
#endif
#ifdef CXWnd__GetWindowTextA
REVERSE_DETOUR(class CXStr  CXWnd::GetWindowTextA(void)const ,CXWnd__GetWindowTextA);
#endif
#ifdef CBodyTintWnd__CBodyTintWnd
REVERSE_DETOUR( CBodyTintWnd::CBodyTintWnd(class CXWnd *),CBodyTintWnd__CBodyTintWnd);
#endif
#ifdef CBodyTintWnd__Activate
REVERSE_DETOUR(void  CBodyTintWnd::Activate(void),CBodyTintWnd__Activate);
#endif
#ifdef CBodyTintWnd__GetTintChangeCount
REVERSE_DETOUR(void  CBodyTintWnd::GetTintChangeCount(void),CBodyTintWnd__GetTintChangeCount);
#endif
#ifdef CBodyTintWnd__GetReagentCount
REVERSE_DETOUR(void  CBodyTintWnd::GetReagentCount(void),CBodyTintWnd__GetReagentCount);
#endif
#ifdef CBodyTintWnd__BuildRBGTooltip
REVERSE_DETOUR(char *  CBodyTintWnd::BuildRBGTooltip(unsigned long,char * const),CBodyTintWnd__BuildRBGTooltip);
#endif
#ifdef CBodyTintWnd__GetItemTint
REVERSE_DETOUR(unsigned long  CBodyTintWnd::GetItemTint(int),CBodyTintWnd__GetItemTint);
#endif
#ifdef CBodyTintWnd__SetSlotLabels
REVERSE_DETOUR(void  CBodyTintWnd::SetSlotLabels(bool),CBodyTintWnd__SetSlotLabels);
#endif
#ifdef CBodyTintWnd__UpdateLocalTintColor
REVERSE_DETOUR(void  CBodyTintWnd::UpdateLocalTintColor(unsigned long),CBodyTintWnd__UpdateLocalTintColor);
#endif
#ifdef CBodyTintWnd__UpdateMaterialTintLocal
REVERSE_DETOUR(void  CBodyTintWnd::UpdateMaterialTintLocal(unsigned long),CBodyTintWnd__UpdateMaterialTintLocal);
#endif
#ifdef CBodyTintWnd__UpdateLabelsAndButtons
REVERSE_DETOUR(void  CBodyTintWnd::UpdateLabelsAndButtons(void),CBodyTintWnd__UpdateLabelsAndButtons);
#endif
#ifdef CBodyTintWnd__GetButtonTint
REVERSE_DETOUR(unsigned long  CBodyTintWnd::GetButtonTint(int),CBodyTintWnd__GetButtonTint);
#endif
#ifdef CBodyTintWnd__StoreModifiedBodyTints
REVERSE_DETOUR(void  CBodyTintWnd::StoreModifiedBodyTints(void),CBodyTintWnd__StoreModifiedBodyTints);
#endif
#ifdef CBodyTintWnd__ResetToOrigBodyTints
REVERSE_DETOUR(void  CBodyTintWnd::ResetToOrigBodyTints(void),CBodyTintWnd__ResetToOrigBodyTints);
#endif
#ifdef CXWnd__SetTooltip
REVERSE_DETOUR(void  CXWnd::SetTooltip(class CXStr),CXWnd__SetTooltip);
#endif
#ifdef CBookWnd__CBookWnd
REVERSE_DETOUR( CBookWnd::CBookWnd(class CXWnd *),CBookWnd__CBookWnd);
#endif
#ifdef CBookWnd__Activate
REVERSE_DETOUR(void  CBookWnd::Activate(void),CBookWnd__Activate);
#endif
#ifdef CBookWnd__SetBook
REVERSE_DETOUR(void  CBookWnd::SetBook(char *),CBookWnd__SetBook);
#endif
#ifdef CBookWnd__CheckBook
REVERSE_DETOUR(bool  CBookWnd::CheckBook(class EQ_Note *),CBookWnd__CheckBook);
#endif
#ifdef CBookWnd__DisplayText
REVERSE_DETOUR(void  CBookWnd::DisplayText(void),CBookWnd__DisplayText);
#endif
#ifdef CBookWnd__CleanPages
REVERSE_DETOUR(void  CBookWnd::CleanPages(void),CBookWnd__CleanPages);
#endif
#ifdef CBookWnd__ProcessText
REVERSE_DETOUR(void  CBookWnd::ProcessText(void),CBookWnd__ProcessText);
#endif
#ifdef CBookWnd__ShowButtons
REVERSE_DETOUR(void  CBookWnd::ShowButtons(void),CBookWnd__ShowButtons);
#endif
#ifdef COptionsWnd__KeyboardAssignmentData__KeyboardAssignmentData
//REVERSE_DETOUR( COptionsWnd::KeyboardAssignmentData::KeyboardAssignmentData(void),COptionsWnd__KeyboardAssignmentData__KeyboardAssignmentData);
#endif
#ifdef CXStr__CXStr1
REVERSE_DETOUR( CXStr::CXStr(void),CXStr__CXStr1);
#endif
#ifdef CBreathWnd__CBreathWnd
REVERSE_DETOUR( CBreathWnd::CBreathWnd(class CXWnd *),CBreathWnd__CBreathWnd);
#endif
#ifdef CBreathWnd__Init
REVERSE_DETOUR(void  CBreathWnd::Init(void),CBreathWnd__Init);
#endif
#ifdef CBreathWnd__Activate
REVERSE_DETOUR(void  CBreathWnd::Activate(void),CBreathWnd__Activate);
#endif
#ifdef CBuffWindow__CBuffWindow
//REVERSE_DETOUR( CBuffWindow::CBuffWindow(class CXWnd *,enum BuffWindowType),CBuffWindow__CBuffWindow);
#endif
#ifdef CTextureAnimation__operator_equal
REVERSE_DETOUR(class CTextureAnimation &  CTextureAnimation::operator=(class CTextureAnimation const &),CTextureAnimation__operator_equal);
#endif
#ifdef CBuffWindow__Init
REVERSE_DETOUR(void  CBuffWindow::Init(void),CBuffWindow__Init);
#endif
#ifdef CBuffWindow__Activate
REVERSE_DETOUR(void  CBuffWindow::Activate(void),CBuffWindow__Activate);
#endif
#ifdef CBuffWindow__HandleSpellInfoDisplay
REVERSE_DETOUR(void  CBuffWindow::HandleSpellInfoDisplay(class CXWnd *),CBuffWindow__HandleSpellInfoDisplay);
#endif
#ifdef CBuffWindow__RefreshIconArrangement
REVERSE_DETOUR(void  CBuffWindow::RefreshIconArrangement(void),CBuffWindow__RefreshIconArrangement);
#endif
#ifdef CBuffWindow__RefreshBuffDisplay
REVERSE_DETOUR(void  CBuffWindow::RefreshBuffDisplay(void),CBuffWindow__RefreshBuffDisplay);
#endif
#ifdef CBuffWindow__SetBuffIcon
REVERSE_DETOUR(void  CBuffWindow::SetBuffIcon(class CButtonWnd *,int,int),CBuffWindow__SetBuffIcon);
#endif
#ifdef CXRect__Move
REVERSE_DETOUR(void  CXRect::Move(class CXPoint),CXRect__Move);
#endif
#ifdef CTAFrameDraw__GetFrameSize
REVERSE_DETOUR(class CXSize  CTAFrameDraw::GetFrameSize(void)const ,CTAFrameDraw__GetFrameSize);
#endif
#ifdef STextureAnimationFrame__STextureAnimationFrame
REVERSE_DETOUR( STextureAnimationFrame::STextureAnimationFrame(void),STextureAnimationFrame__STextureAnimationFrame);
#endif
#ifdef CUITexturePiece__CUITexturePiece
REVERSE_DETOUR( CUITexturePiece::CUITexturePiece(void),CUITexturePiece__CUITexturePiece);
#endif
#ifdef STextureAnimationFrame__operator_equal
REVERSE_DETOUR(class STextureAnimationFrame &  STextureAnimationFrame::operator=(class STextureAnimationFrame const &),STextureAnimationFrame__operator_equal);
#endif
#ifdef CUITexturePiece__operator_equal
REVERSE_DETOUR(class CUITexturePiece &  CUITexturePiece::operator=(class CUITexturePiece const &),CUITexturePiece__operator_equal);
#endif
#ifdef CBugReportWnd__CBugReportWnd
REVERSE_DETOUR( CBugReportWnd::CBugReportWnd(class CXWnd *),CBugReportWnd__CBugReportWnd);
#endif
#ifdef CBugReportWnd__Activate
REVERSE_DETOUR(void  CBugReportWnd::Activate(void),CBugReportWnd__Activate);
#endif
#ifdef CBugReportWnd__UpdateLocation
REVERSE_DETOUR(void  CBugReportWnd::UpdateLocation(void),CBugReportWnd__UpdateLocation);
#endif
#ifdef CCastingWnd__CCastingWnd
REVERSE_DETOUR( CCastingWnd::CCastingWnd(class CXWnd *),CCastingWnd__CCastingWnd);
#endif
#ifdef CCastingWnd__Activate
REVERSE_DETOUR(void  CCastingWnd::Activate(void),CCastingWnd__Activate);
#endif
#ifdef CVideoModesWnd__Activate
REVERSE_DETOUR(void  CVideoModesWnd::Activate(void),CVideoModesWnd__Activate);
#endif
#ifdef CCastSpellWnd__CCastSpellWnd
REVERSE_DETOUR( CCastSpellWnd::CCastSpellWnd(class CXWnd *),CCastSpellWnd__CCastSpellWnd);
#endif
#ifdef CCastSpellWnd__Init
REVERSE_DETOUR(void  CCastSpellWnd::Init(void),CCastSpellWnd__Init);
#endif
#ifdef CCastSpellWnd__Activate
REVERSE_DETOUR(void  CCastSpellWnd::Activate(void),CCastSpellWnd__Activate);
#endif
#ifdef CCastSpellWnd__HandleSpellInfoDisplay
REVERSE_DETOUR(void  CCastSpellWnd::HandleSpellInfoDisplay(class CXWnd *),CCastSpellWnd__HandleSpellInfoDisplay);
#endif
#ifdef CCastSpellWnd__HandleSpellLeftClick
REVERSE_DETOUR(void  CCastSpellWnd::HandleSpellLeftClick(int),CCastSpellWnd__HandleSpellLeftClick);
#endif
#ifdef CCastSpellWnd__Unmemorize
REVERSE_DETOUR(void __cdecl CCastSpellWnd::Unmemorize(int),CCastSpellWnd__Unmemorize);
#endif
#ifdef CCastSpellWnd__UnmemorizeList
REVERSE_DETOUR(void __cdecl CCastSpellWnd::UnmemorizeList(int *,int),CCastSpellWnd__UnmemorizeList);
#endif
#ifdef CCastSpellWnd__HandleSpellRightClick
REVERSE_DETOUR(void  CCastSpellWnd::HandleSpellRightClick(int),CCastSpellWnd__HandleSpellRightClick);
#endif
#ifdef CCastSpellWnd__ForgetMemorizedSpell
REVERSE_DETOUR(void  CCastSpellWnd::ForgetMemorizedSpell(int),CCastSpellWnd__ForgetMemorizedSpell);
#endif
#ifdef CCastSpellWnd__IsBardSongPlaying
REVERSE_DETOUR(bool  CCastSpellWnd::IsBardSongPlaying(void),CCastSpellWnd__IsBardSongPlaying);
#endif
#ifdef CCastSpellWnd__RefreshSpellGemButtons
REVERSE_DETOUR(void  CCastSpellWnd::RefreshSpellGemButtons(void),CCastSpellWnd__RefreshSpellGemButtons);
#endif
#ifdef CCastSpellWnd__UpdateSpellGems
REVERSE_DETOUR(void  CCastSpellWnd::UpdateSpellGems(int),CCastSpellWnd__UpdateSpellGems);
#endif
#ifdef CCastSpellWnd__UpdateSpellGemTooltips
REVERSE_DETOUR(void  CCastSpellWnd::UpdateSpellGemTooltips(int),CCastSpellWnd__UpdateSpellGemTooltips);
#endif
#ifdef CCastSpellWnd__GetSpellGemColor
REVERSE_DETOUR(unsigned long  CCastSpellWnd::GetSpellGemColor(class EQ_Spell *),CCastSpellWnd__GetSpellGemColor);
#endif
#ifdef CCastSpellWnd__SpellBookDeactivating
REVERSE_DETOUR(void  CCastSpellWnd::SpellBookDeactivating(void),CCastSpellWnd__SpellBookDeactivating);
#endif
#ifdef CCastSpellWnd__KeyMapUpdated
REVERSE_DETOUR(void  CCastSpellWnd::KeyMapUpdated(void),CCastSpellWnd__KeyMapUpdated);
#endif
#ifdef CCastSpellWnd__ClearSpellCategories
REVERSE_DETOUR(void  CCastSpellWnd::ClearSpellCategories(void),CCastSpellWnd__ClearSpellCategories);
#endif
#ifdef CCastSpellWnd__SpellCategoryMajor__dSpellCategoryMajor
//REVERSE_DETOUR( CCastSpellWnd::SpellCategoryMajor::~SpellCategoryMajor(void),CCastSpellWnd__SpellCategoryMajor__dSpellCategoryMajor);
#endif
#ifdef CCastSpellWnd__SpellCategoryMinor__dSpellCategoryMinor
//REVERSE_DETOUR( CCastSpellWnd::SpellCategoryMinor::~SpellCategoryMinor(void),CCastSpellWnd__SpellCategoryMinor__dSpellCategoryMinor);
#endif
#ifdef CCastSpellWnd__RecacheCategorizedSpells
REVERSE_DETOUR(void  CCastSpellWnd::RecacheCategorizedSpells(void),CCastSpellWnd__RecacheCategorizedSpells);
#endif
#ifdef CCastSpellWnd__MakeSpellSelectMenu
REVERSE_DETOUR(void  CCastSpellWnd::MakeSpellSelectMenu(void),CCastSpellWnd__MakeSpellSelectMenu);
#endif
#ifdef CCastSpellWnd__CategorizeSpell
REVERSE_DETOUR(void  CCastSpellWnd::CategorizeSpell(int,int,int,int),CCastSpellWnd__CategorizeSpell);
#endif
#ifdef CCastSpellWnd__RecacheLoadoutContextMenu
REVERSE_DETOUR(void  CCastSpellWnd::RecacheLoadoutContextMenu(void),CCastSpellWnd__RecacheLoadoutContextMenu);
#endif
#ifdef CCharacterCreation__CCharacterCreation
REVERSE_DETOUR( CCharacterCreation::CCharacterCreation(class CXWnd *),CCharacterCreation__CCharacterCreation);
#endif
#ifdef CCharacterCreation__Init
REVERSE_DETOUR(void  CCharacterCreation::Init(void),CCharacterCreation__Init);
#endif
#ifdef CCharacterCreation__Activate
REVERSE_DETOUR(void  CCharacterCreation::Activate(void),CCharacterCreation__Activate);
#endif
#ifdef CCharacterCreation__NameGenerated
REVERSE_DETOUR(void  CCharacterCreation::NameGenerated(char *),CCharacterCreation__NameGenerated);
#endif
#ifdef CCharacterCreation__DoBackButton
REVERSE_DETOUR(void  CCharacterCreation::DoBackButton(void),CCharacterCreation__DoBackButton);
#endif
#ifdef CCharacterCreation__DoNextButton
REVERSE_DETOUR(void  CCharacterCreation::DoNextButton(void),CCharacterCreation__DoNextButton);
#endif
#ifdef CCharacterCreation__DoStatButton
REVERSE_DETOUR(void  CCharacterCreation::DoStatButton(int),CCharacterCreation__DoStatButton);
#endif
#ifdef CCharacterCreation__ActivateScreen
REVERSE_DETOUR(void  CCharacterCreation::ActivateScreen(int),CCharacterCreation__ActivateScreen);
#endif
#ifdef CCharacterCreation__RandomizeCharacter
REVERSE_DETOUR(void  CCharacterCreation::RandomizeCharacter(bool,bool),CCharacterCreation__RandomizeCharacter);
#endif
#ifdef CCharacterCreation__RandomizeFacialFeatures
REVERSE_DETOUR(void  CCharacterCreation::RandomizeFacialFeatures(void),CCharacterCreation__RandomizeFacialFeatures);
#endif
#ifdef CCharacterCreation__InitStats
REVERSE_DETOUR(void  CCharacterCreation::InitStats(bool),CCharacterCreation__InitStats);
#endif
#ifdef CCharacterCreation__InitNewPC
REVERSE_DETOUR(void  CCharacterCreation::InitNewPC(void),CCharacterCreation__InitNewPC);
#endif
#ifdef CCharacterCreation__InitStartingCities
REVERSE_DETOUR(void  CCharacterCreation::InitStartingCities(void),CCharacterCreation__InitStartingCities);
#endif
#ifdef CCharacterCreation__SetNewPCDeityFromBtnIndex
REVERSE_DETOUR(void  CCharacterCreation::SetNewPCDeityFromBtnIndex(int),CCharacterCreation__SetNewPCDeityFromBtnIndex);
#endif
#ifdef CCharacterCreation__UpdatePlayerFromNewPC
REVERSE_DETOUR(void  CCharacterCreation::UpdatePlayerFromNewPC(void),CCharacterCreation__UpdatePlayerFromNewPC);
#endif
#ifdef CCharacterCreation__UpdateScreenZeroButtons
REVERSE_DETOUR(void  CCharacterCreation::UpdateScreenZeroButtons(bool),CCharacterCreation__UpdateScreenZeroButtons);
#endif
#ifdef CCharacterCreation__GetRaceButtonIndex
REVERSE_DETOUR(int  CCharacterCreation::GetRaceButtonIndex(int),CCharacterCreation__GetRaceButtonIndex);
#endif
#ifdef CCharacterCreation__GetClassButtonIndex
REVERSE_DETOUR(int  CCharacterCreation::GetClassButtonIndex(int),CCharacterCreation__GetClassButtonIndex);
#endif
#ifdef CCharacterCreation__IsLackingExpansion
REVERSE_DETOUR(bool  CCharacterCreation::IsLackingExpansion(bool,bool),CCharacterCreation__IsLackingExpansion);
#endif
#ifdef CCharacterCreation__SelectStartingCity
REVERSE_DETOUR(void  CCharacterCreation::SelectStartingCity(int),CCharacterCreation__SelectStartingCity);
#endif
#ifdef CCharacterCreation__SelectedRaceButton
REVERSE_DETOUR(void  CCharacterCreation::SelectedRaceButton(int),CCharacterCreation__SelectedRaceButton);
#endif
#ifdef CCharacterCreation__SelectedClassButton
REVERSE_DETOUR(void  CCharacterCreation::SelectedClassButton(int),CCharacterCreation__SelectedClassButton);
#endif
#ifdef CCharacterCreation__SetPlayerAppearanceFromNewPC
REVERSE_DETOUR(void  CCharacterCreation::SetPlayerAppearanceFromNewPC(class EQPlayer *,class EQ_PC *,bool),CCharacterCreation__SetPlayerAppearanceFromNewPC);
#endif
#ifdef CCharacterCreation__HandleNameApprovalResponse
REVERSE_DETOUR(void  CCharacterCreation::HandleNameApprovalResponse(int),CCharacterCreation__HandleNameApprovalResponse);
#endif
#ifdef CCharacterCreation__SubmitNameToWorld
REVERSE_DETOUR(void  CCharacterCreation::SubmitNameToWorld(void),CCharacterCreation__SubmitNameToWorld);
#endif
#ifdef CCharacterCreation__FinalizeNewPCAndSendToWorld
REVERSE_DETOUR(void  CCharacterCreation::FinalizeNewPCAndSendToWorld(void),CCharacterCreation__FinalizeNewPCAndSendToWorld);
#endif
#ifdef CCharacterCreation__GetCharCreateText
REVERSE_DETOUR(char *  CCharacterCreation::GetCharCreateText(char *,int,int,int,int),CCharacterCreation__GetCharCreateText);
#endif
#ifdef CCharacterSelect__CCharacterSelect
REVERSE_DETOUR( CCharacterSelect::CCharacterSelect(class CXWnd *),CCharacterSelect__CCharacterSelect);
#endif
#ifdef CCharacterSelect__Init
REVERSE_DETOUR(void  CCharacterSelect::Init(void),CCharacterSelect__Init);
#endif
#ifdef CCharacterSelect__Activate
REVERSE_DETOUR(void  CCharacterSelect::Activate(void),CCharacterSelect__Activate);
#endif
#ifdef CCharacterSelect__EnableButtons
REVERSE_DETOUR(void  CCharacterSelect::EnableButtons(bool),CCharacterSelect__EnableButtons);
#endif
#ifdef CCharacterSelect__EnableEqMovementCommands
REVERSE_DETOUR(void  CCharacterSelect::EnableEqMovementCommands(bool),CCharacterSelect__EnableEqMovementCommands);
#endif
#ifdef CCharacterSelect__EnterWorld
REVERSE_DETOUR(void  CCharacterSelect::EnterWorld(void),CCharacterSelect__EnterWorld);
#endif
#ifdef CCharacterSelect__Quit
REVERSE_DETOUR(void  CCharacterSelect::Quit(void),CCharacterSelect__Quit);
#endif
#ifdef CCharacterSelect__EnterExplorationMode
REVERSE_DETOUR(void  CCharacterSelect::EnterExplorationMode(void),CCharacterSelect__EnterExplorationMode);
#endif
#ifdef CCharacterSelect__LeaveExplorationMode
REVERSE_DETOUR(void  CCharacterSelect::LeaveExplorationMode(void),CCharacterSelect__LeaveExplorationMode);
#endif
#ifdef CCharacterSelect__IsValidCharacterSelected
REVERSE_DETOUR(int  CCharacterSelect::IsValidCharacterSelected(void),CCharacterSelect__IsValidCharacterSelected);
#endif
#ifdef CCharacterSelect__IsEmptyCharacterSlot
REVERSE_DETOUR(int  CCharacterSelect::IsEmptyCharacterSlot(int),CCharacterSelect__IsEmptyCharacterSlot);
#endif
#ifdef CCharacterSelect__NumberOfCharacters
REVERSE_DETOUR(int  CCharacterSelect::NumberOfCharacters(void),CCharacterSelect__NumberOfCharacters);
#endif
#ifdef CCharacterSelect__IsEvil
REVERSE_DETOUR(unsigned char  CCharacterSelect::IsEvil(int,int,int),CCharacterSelect__IsEvil);
#endif
#ifdef CCharacterSelect__SelectCharacter
REVERSE_DETOUR(void  CCharacterSelect::SelectCharacter(int,int),CCharacterSelect__SelectCharacter);
#endif
#ifdef CCharacterSelect__SetLoadZonePlayerLocation
REVERSE_DETOUR(void  CCharacterSelect::SetLoadZonePlayerLocation(void),CCharacterSelect__SetLoadZonePlayerLocation);
#endif
#ifdef CCharacterSelect__DeleteCharacter
REVERSE_DETOUR(void  CCharacterSelect::DeleteCharacter(void),CCharacterSelect__DeleteCharacter);
#endif
#ifdef CCharacterSelect__UpdateButtonNames
REVERSE_DETOUR(void  CCharacterSelect::UpdateButtonNames(void),CCharacterSelect__UpdateButtonNames);
#endif
#ifdef CCharacterSelect__SetLocationByClass
REVERSE_DETOUR(void  CCharacterSelect::SetLocationByClass(class EQPlayer *,bool,int),CCharacterSelect__SetLocationByClass);
#endif
#ifdef CCharacterSelect__CreateExplorationModePlayers
REVERSE_DETOUR(void  CCharacterSelect::CreateExplorationModePlayers(void),CCharacterSelect__CreateExplorationModePlayers);
#endif
#ifdef CCharacterSelect__RemoveExplorationModePlayers
REVERSE_DETOUR(void  CCharacterSelect::RemoveExplorationModePlayers(void),CCharacterSelect__RemoveExplorationModePlayers);
#endif
#ifdef CCharacterSelect__SetRoomLocationByIndex
REVERSE_DETOUR(void  CCharacterSelect::SetRoomLocationByIndex(int,class EQPlayer *),CCharacterSelect__SetRoomLocationByIndex);
#endif
#ifdef CCharacterSelect__SwitchModel
REVERSE_DETOUR(void  CCharacterSelect::SwitchModel(class EQPlayer *,unsigned char,int,unsigned char,unsigned char),CCharacterSelect__SwitchModel);
#endif
#ifdef CChatManager__CChatManager
REVERSE_DETOUR( CChatManager::CChatManager(void),CChatManager__CChatManager);
#endif
#ifdef CChatManager__dCChatManager
REVERSE_DETOUR( CChatManager::~CChatManager(void),CChatManager__dCChatManager);
#endif
#ifdef CBookWnd__Init
REVERSE_DETOUR(void  CBookWnd::Init(void),CBookWnd__Init);
#endif
#ifdef CColorPickerWnd__Init
REVERSE_DETOUR(void  CColorPickerWnd::Init(void),CColorPickerWnd__Init);
#endif
#ifdef CCompassWnd__Init
REVERSE_DETOUR(void  CCompassWnd::Init(void),CCompassWnd__Init);
#endif
#ifdef CContainerWnd__Init
REVERSE_DETOUR(void  CContainerWnd::Init(void),CContainerWnd__Init);
#endif
#ifdef CGiveWnd__Init
REVERSE_DETOUR(void  CGiveWnd::Init(void),CGiveWnd__Init);
#endif
#ifdef CHelpWnd__Init
REVERSE_DETOUR(void  CHelpWnd::Init(void),CHelpWnd__Init);
#endif
#ifdef CMusicPlayerWnd__Init
REVERSE_DETOUR(void  CMusicPlayerWnd::Init(void),CMusicPlayerWnd__Init);
#endif
#ifdef CNoteWnd__Init
REVERSE_DETOUR(void  CNoteWnd::Init(void),CNoteWnd__Init);
#endif
#ifdef CPetInfoWnd__Init
REVERSE_DETOUR(void  CPetInfoWnd::Init(void),CPetInfoWnd__Init);
#endif
#ifdef CPlayerNotesWnd__Init
REVERSE_DETOUR(void  CPlayerNotesWnd::Init(void),CPlayerNotesWnd__Init);
#endif
#ifdef CTargetWnd__Init
REVERSE_DETOUR(void  CTargetWnd::Init(void),CTargetWnd__Init);
#endif
#ifdef UdpManager__ProcessIcmpErrors
REVERSE_DETOUR(void  UdpManager::ProcessIcmpErrors(void),UdpManager__ProcessIcmpErrors);
#endif
#ifdef CRaid__dCRaid
REVERSE_DETOUR( CRaid::~CRaid(void),CRaid__dCRaid);
#endif
#ifdef EQ_Note__dEQ_Note
REVERSE_DETOUR( EQ_Note::~EQ_Note(void),EQ_Note__dEQ_Note);
#endif
#ifdef EQ_Skill__dEQ_Skill
REVERSE_DETOUR( EQ_Skill::~EQ_Skill(void),EQ_Skill__dEQ_Skill);
#endif
#ifdef EQAnimation__dEQAnimation
REVERSE_DETOUR( EQAnimation::~EQAnimation(void),EQAnimation__dEQAnimation);
#endif
#ifdef KeypressHandler__dKeypressHandler
REVERSE_DETOUR( KeypressHandler::~KeypressHandler(void),KeypressHandler__dKeypressHandler);
#endif
#ifdef EQNewPlayerAnimation__InitAnimationData
REVERSE_DETOUR(void __cdecl EQNewPlayerAnimation::InitAnimationData(void),EQNewPlayerAnimation__InitAnimationData);
#endif
#ifdef CAAWnd__CancelAASpend
REVERSE_DETOUR(void  CAAWnd::CancelAASpend(void),CAAWnd__CancelAASpend);
#endif
#ifdef CChatManager__Process
REVERSE_DETOUR(void  CChatManager::Process(void),CChatManager__Process);
#endif
#ifdef CDisplay__DefineSoloMode
REVERSE_DETOUR(void  CDisplay::DefineSoloMode(void),CDisplay__DefineSoloMode);
#endif
#ifdef CEverQuest__InitCommands
REVERSE_DETOUR(void  CEverQuest::InitCommands(void),CEverQuest__InitCommands);
#endif
#ifdef CInvSlotMgr__Process
REVERSE_DETOUR(void  CInvSlotMgr::Process(void),CInvSlotMgr__Process);
#endif
#ifdef EQMissile__LeaveTrail
REVERSE_DETOUR(void  EQMissile::LeaveTrail(void),EQMissile__LeaveTrail);
#endif
#ifdef CChatManager__Activate
REVERSE_DETOUR(void  CChatManager::Activate(void),CChatManager__Activate);
#endif
#ifdef CChatManager__Deactivate
REVERSE_DETOUR(void  CChatManager::Deactivate(void),CChatManager__Deactivate);
#endif
#ifdef CChatManager__LoadChatInis
REVERSE_DETOUR(void  CChatManager::LoadChatInis(void),CChatManager__LoadChatInis);
#endif
#ifdef CChatManager__CreateChatWindow
REVERSE_DETOUR(void  CChatManager::CreateChatWindow(void),CChatManager__CreateChatWindow);
#endif
#ifdef CChatManager__CreateChatWindow1
REVERSE_DETOUR(void  CChatManager::CreateChatWindow(char *,char *,int,int,int,char *,int),CChatManager__CreateChatWindow1);
#endif
#ifdef CChatManager__FreeChatWindow
REVERSE_DETOUR(void  CChatManager::FreeChatWindow(class CChatWindow *),CChatManager__FreeChatWindow);
#endif
#ifdef CChatManager__GetActiveChatWindow
REVERSE_DETOUR(class CChatWindow *  CChatManager::GetActiveChatWindow(void),CChatManager__GetActiveChatWindow);
#endif
#ifdef CChatManager__AddText
REVERSE_DETOUR(void  CChatManager::AddText(class CXStr,int),CChatManager__AddText);
#endif
#ifdef CChatManager__SetChannelMap
REVERSE_DETOUR(void  CChatManager::SetChannelMap(int,class CChatWindow *),CChatManager__SetChannelMap);
#endif
#ifdef CChatManager__ClearChannelMap
REVERSE_DETOUR(void  CChatManager::ClearChannelMap(int),CChatManager__ClearChannelMap);
#endif
#ifdef CChatManager__GetChannelFromColor
REVERSE_DETOUR(int  CChatManager::GetChannelFromColor(int),CChatManager__GetChannelFromColor);
#endif
#ifdef CChatManager__GetChannelMap
REVERSE_DETOUR(class CChatWindow *  CChatManager::GetChannelMap(int),CChatManager__GetChannelMap);
#endif
#ifdef CChatManager__ClearChannelMaps
REVERSE_DETOUR(void  CChatManager::ClearChannelMaps(class CChatWindow *),CChatManager__ClearChannelMaps);
#endif
#ifdef CChatManager__SetActiveChatWindow
REVERSE_DETOUR(void  CChatManager::SetActiveChatWindow(class CChatWindow *),CChatManager__SetActiveChatWindow);
#endif
#ifdef CChatManager__SetLockedActiveChatWindow
REVERSE_DETOUR(void  CChatManager::SetLockedActiveChatWindow(class CChatWindow *),CChatManager__SetLockedActiveChatWindow);
#endif
#ifdef CChatManager__GetRGBAFromIndex
REVERSE_DETOUR(unsigned long  CChatManager::GetRGBAFromIndex(int),CChatManager__GetRGBAFromIndex);
#endif
#ifdef CChatManager__InitContextMenu
REVERSE_DETOUR(int  CChatManager::InitContextMenu(class CChatWindow *),CChatManager__InitContextMenu);
#endif
#ifdef CChatManager__UpdateContextMenus
REVERSE_DETOUR(void  CChatManager::UpdateContextMenus(class CChatWindow *),CChatManager__UpdateContextMenus);
#endif
#ifdef CChatManager__UpdateTellMenus
REVERSE_DETOUR(void  CChatManager::UpdateTellMenus(class CChatWindow *),CChatManager__UpdateTellMenus);
#endif
#ifdef CChatManager__GetAllVisibleText
REVERSE_DETOUR(class CXStr  CChatManager::GetAllVisibleText(class CXStr),CChatManager__GetAllVisibleText);
#endif
#ifdef CChatWindow__GetOutputWnd
REVERSE_DETOUR(class CStmlWnd *  CChatWindow::GetOutputWnd(void),CChatWindow__GetOutputWnd);
#endif
#ifdef CContextMenuManager__GetDefaultMenuIndex
REVERSE_DETOUR(int  CContextMenuManager::GetDefaultMenuIndex(void),CContextMenuManager__GetDefaultMenuIndex);
#endif
#ifdef CChatWindow__CChatWindow
REVERSE_DETOUR( CChatWindow::CChatWindow(class CXWnd *),CChatWindow__CChatWindow);
#endif
#ifdef CChatWindow__AddOutputText
REVERSE_DETOUR(void  CChatWindow::AddOutputText(class CXStr,int),CChatWindow__AddOutputText);
#endif
#ifdef CChatWindow__HistoryBack
REVERSE_DETOUR(void  CChatWindow::HistoryBack(void),CChatWindow__HistoryBack);
#endif
#ifdef CChatWindow__HistoryForward
REVERSE_DETOUR(void  CChatWindow::HistoryForward(void),CChatWindow__HistoryForward);
#endif
#ifdef CChatWindow__AddHistory
REVERSE_DETOUR(void  CChatWindow::AddHistory(class CXStr),CChatWindow__AddHistory);
#endif
#ifdef CChatWindow__GetInputText
REVERSE_DETOUR(class CXStr  CChatWindow::GetInputText(void),CChatWindow__GetInputText);
#endif
#ifdef CChatWindow__PageUp
REVERSE_DETOUR(void  CChatWindow::PageUp(void),CChatWindow__PageUp);
#endif
#ifdef CChatWindow__PageDown
REVERSE_DETOUR(void  CChatWindow::PageDown(void),CChatWindow__PageDown);
#endif
#ifdef CChatWindow__SetChatFont
REVERSE_DETOUR(void  CChatWindow::SetChatFont(int),CChatWindow__SetChatFont);
#endif
#ifdef CChatWindow__Clear
REVERSE_DETOUR(void  CChatWindow::Clear(void),CChatWindow__Clear);
#endif
#ifdef CStmlWnd__GetSTMLText
REVERSE_DETOUR(class CXStr  CStmlWnd::GetSTMLText(void)const ,CStmlWnd__GetSTMLText);
#endif
#ifdef CChatWindow__GetInputWnd
REVERSE_DETOUR(class CEditWnd *  CChatWindow::GetInputWnd(void),CChatWindow__GetInputWnd);
#endif
#ifdef CColorPickerWnd__CColorPickerWnd
REVERSE_DETOUR( CColorPickerWnd::CColorPickerWnd(class CXWnd *),CColorPickerWnd__CColorPickerWnd);
#endif
#ifdef CColorPickerWnd__SetTemplateColor
REVERSE_DETOUR(void  CColorPickerWnd::SetTemplateColor(int,unsigned long),CColorPickerWnd__SetTemplateColor);
#endif
#ifdef CColorPickerWnd__Activate
REVERSE_DETOUR(void  CColorPickerWnd::Activate(class CXWnd *,unsigned long),CColorPickerWnd__Activate);
#endif
#ifdef CColorPickerWnd__SetCurrentColor
REVERSE_DETOUR(void  CColorPickerWnd::SetCurrentColor(unsigned long),CColorPickerWnd__SetCurrentColor);
#endif
#ifdef CColorPickerWnd__UpdateCurrentColor
REVERSE_DETOUR(void  CColorPickerWnd::UpdateCurrentColor(void),CColorPickerWnd__UpdateCurrentColor);
#endif
#ifdef CColorPickerWnd__CheckMaxEditWnd
REVERSE_DETOUR(void  CColorPickerWnd::CheckMaxEditWnd(void),CColorPickerWnd__CheckMaxEditWnd);
#endif
#ifdef CColorPickerWnd__UpdateEditWndFromSlider
REVERSE_DETOUR(void  CColorPickerWnd::UpdateEditWndFromSlider(class CSliderWnd *,class CEditWnd *,int *),CColorPickerWnd__UpdateEditWndFromSlider);
#endif
#ifdef CColorPickerWnd__UpdateSliderFromEditWnd
REVERSE_DETOUR(void  CColorPickerWnd::UpdateSliderFromEditWnd(class CSliderWnd *,class CEditWnd *,int *),CColorPickerWnd__UpdateSliderFromEditWnd);
#endif
#ifdef CCompassWnd__CCompassWnd
REVERSE_DETOUR( CCompassWnd::CCompassWnd(class CXWnd *),CCompassWnd__CCompassWnd);
#endif
#ifdef CCompassWnd__Activate
REVERSE_DETOUR(void  CCompassWnd::Activate(void),CCompassWnd__Activate);
#endif
#ifdef CCompassWnd__PickNewTarget
REVERSE_DETOUR(void  CCompassWnd::PickNewTarget(void),CCompassWnd__PickNewTarget);
#endif
#ifdef CCompassWnd__SetSpeed
REVERSE_DETOUR(void  CCompassWnd::SetSpeed(void),CCompassWnd__SetSpeed);
#endif
#ifdef CCompassWnd__SenseHeading
REVERSE_DETOUR(void  CCompassWnd::SenseHeading(void),CCompassWnd__SenseHeading);
#endif
#ifdef CConfirmationDialog__CConfirmationDialog
REVERSE_DETOUR( CConfirmationDialog::CConfirmationDialog(class CXWnd *),CConfirmationDialog__CConfirmationDialog);
#endif
#ifdef CConfirmationDialog__Init
REVERSE_DETOUR(void  CConfirmationDialog::Init(void),CConfirmationDialog__Init);
#endif
#ifdef CConfirmationDialog__Activate
REVERSE_DETOUR(void  CConfirmationDialog::Activate(int,unsigned int,char const *),CConfirmationDialog__Activate);
#endif
#ifdef CConfirmationDialog__ExpireCurrentDialog
REVERSE_DETOUR(void  CConfirmationDialog::ExpireCurrentDialog(void),CConfirmationDialog__ExpireCurrentDialog);
#endif
#ifdef CConfirmationDialog__HandleButtonYesPressed
REVERSE_DETOUR(void  CConfirmationDialog::HandleButtonYesPressed(void),CConfirmationDialog__HandleButtonYesPressed);
#endif
#ifdef CConfirmationDialog__HandleButtonNoPressed
REVERSE_DETOUR(void  CConfirmationDialog::HandleButtonNoPressed(void),CConfirmationDialog__HandleButtonNoPressed);
#endif
#ifdef CConfirmationDialog__HandleButtonOkPressed
REVERSE_DETOUR(void  CConfirmationDialog::HandleButtonOkPressed(void),CConfirmationDialog__HandleButtonOkPressed);
#endif
#ifdef CConfirmationDialog__ProcessYes
REVERSE_DETOUR(void  CConfirmationDialog::ProcessYes(void),CConfirmationDialog__ProcessYes);
#endif
#ifdef CConfirmationDialog__ResetFocusOnClose
REVERSE_DETOUR(void  CConfirmationDialog::ResetFocusOnClose(void),CConfirmationDialog__ResetFocusOnClose);
#endif
#ifdef CConfirmationDialog__ProcessNo
REVERSE_DETOUR(void  CConfirmationDialog::ProcessNo(int),CConfirmationDialog__ProcessNo);
#endif
#ifdef CConfirmationDialog__SetNameApprovalData
REVERSE_DETOUR(void  CConfirmationDialog::SetNameApprovalData(char *,char *,int,int,char *),CConfirmationDialog__SetNameApprovalData);
#endif
#ifdef CContainerMgr__GetFreeContainerWnd
REVERSE_DETOUR(class CContainerWnd *  CContainerMgr::GetFreeContainerWnd(void),CContainerMgr__GetFreeContainerWnd);
#endif
#ifdef CContainerMgr__CContainerMgr
REVERSE_DETOUR( CContainerMgr::CContainerMgr(void),CContainerMgr__CContainerMgr);
#endif
#ifdef CContainerMgr__Process
REVERSE_DETOUR(void  CContainerMgr::Process(void),CContainerMgr__Process);
#endif
#ifdef CContainerMgr__OpenWorldContainer
REVERSE_DETOUR(void  CContainerMgr::OpenWorldContainer(class EQ_Container *,unsigned long),CContainerMgr__OpenWorldContainer);
#endif
#ifdef CContainerMgr__SetWorldContainerItem
REVERSE_DETOUR(void  CContainerMgr::SetWorldContainerItem(class EQ_Item *,int),CContainerMgr__SetWorldContainerItem);
#endif
#ifdef CContainerMgr__GetWorldContainerItem
REVERSE_DETOUR(class EQ_Item *  CContainerMgr::GetWorldContainerItem(int),CContainerMgr__GetWorldContainerItem);
#endif
#ifdef CContainerMgr__ClearWorldContainerItems
REVERSE_DETOUR(void  CContainerMgr::ClearWorldContainerItems(void),CContainerMgr__ClearWorldContainerItems);
#endif
#ifdef CContainerMgr__OpenContainer
REVERSE_DETOUR(void  CContainerMgr::OpenContainer(class EQ_Container *,int),CContainerMgr__OpenContainer);
#endif
#ifdef CContainerMgr__CloseEQContainer
REVERSE_DETOUR(void  CContainerMgr::CloseEQContainer(class EQ_Container *),CContainerMgr__CloseEQContainer);
#endif
#ifdef CContainerMgr__CloseContainer
REVERSE_DETOUR(void  CContainerMgr::CloseContainer(class EQ_Container *,bool),CContainerMgr__CloseContainer);
#endif
#ifdef CContainerMgr__CloseAllContainers
REVERSE_DETOUR(bool  CContainerMgr::CloseAllContainers(void),CContainerMgr__CloseAllContainers);
#endif
#ifdef CContainerWnd__CContainerWnd
REVERSE_DETOUR( CContainerWnd::CContainerWnd(class CXWnd *),CContainerWnd__CContainerWnd);
#endif
#ifdef CContainerWnd__Activate
REVERSE_DETOUR(void  CContainerWnd::Activate(void),CContainerWnd__Activate);
#endif
#ifdef CHelpWnd__Activate
REVERSE_DETOUR(void  CHelpWnd::Activate(void),CHelpWnd__Activate);
#endif
#ifdef CContainerWnd__HandleCombine
REVERSE_DETOUR(void  CContainerWnd::HandleCombine(void),CContainerWnd__HandleCombine);
#endif
#ifdef CContainerWnd__SetContainer
REVERSE_DETOUR(void  CContainerWnd::SetContainer(class EQ_Container *,int),CContainerWnd__SetContainer);
#endif
#ifdef CContainerWnd__CheckCloseable
REVERSE_DETOUR(void  CContainerWnd::CheckCloseable(void),CContainerWnd__CheckCloseable);
#endif
#ifdef CContainerWnd__ContainsNoDrop
REVERSE_DETOUR(bool  CContainerWnd::ContainsNoDrop(void),CContainerWnd__ContainsNoDrop);
#endif
#ifdef CXRect__operator_or
REVERSE_DETOUR(class CXRect  CXRect::operator|(class CXRect)const ,CXRect__operator_or);
#endif
#ifdef CContextMenu__CContextMenu
REVERSE_DETOUR( CContextMenu::CContextMenu(class CXWnd *,unsigned __int32,class CXRect),CContextMenu__CContextMenu);
#endif
#ifdef CContextMenu__AddMenuItem
REVERSE_DETOUR(int  CContextMenu::AddMenuItem(class CXStr,unsigned int,bool,unsigned long),CContextMenu__AddMenuItem);
#endif
#ifdef CContextMenu__AddSeparator
REVERSE_DETOUR(int  CContextMenu::AddSeparator(void),CContextMenu__AddSeparator);
#endif
#ifdef CContextMenu__RemoveAllMenuItems
REVERSE_DETOUR(void  CContextMenu::RemoveAllMenuItems(void),CContextMenu__RemoveAllMenuItems);
#endif
#ifdef CContextMenu__EnableMenuItem
REVERSE_DETOUR(void  CContextMenu::EnableMenuItem(int,bool),CContextMenu__EnableMenuItem);
#endif
#ifdef CContextMenu__CheckMenuItem
REVERSE_DETOUR(void  CContextMenu::CheckMenuItem(int,bool,bool),CContextMenu__CheckMenuItem);
#endif
#ifdef CContextMenu__Activate
REVERSE_DETOUR(void  CContextMenu::Activate(class CXPoint,int,int),CContextMenu__Activate);
#endif
#ifdef CContextMenuManager__CContextMenuManager
REVERSE_DETOUR( CContextMenuManager::CContextMenuManager(class CXWnd *,unsigned __int32,class CXRect),CContextMenuManager__CContextMenuManager);
#endif
#ifdef CContextMenuManager__RemoveMenu
REVERSE_DETOUR(int  CContextMenuManager::RemoveMenu(int,bool),CContextMenuManager__RemoveMenu);
#endif
#ifdef CContextMenuManager__AddMenu
REVERSE_DETOUR(int  CContextMenuManager::AddMenu(class CContextMenu *),CContextMenuManager__AddMenu);
#endif
#ifdef CContextMenuManager__PopupMenu
REVERSE_DETOUR(int  CContextMenuManager::PopupMenu(int,class CXPoint,class CXWnd *),CContextMenuManager__PopupMenu);
#endif
#ifdef CContextMenuManager__Flush
REVERSE_DETOUR(void  CContextMenuManager::Flush(void),CContextMenuManager__Flush);
#endif
#ifdef CContextMenuManager__CreateDefaultMenu
REVERSE_DETOUR(void  CContextMenuManager::CreateDefaultMenu(void),CContextMenuManager__CreateDefaultMenu);
#endif
#ifdef CContextMenuManager__WarnDefaultMenu
REVERSE_DETOUR(void  CContextMenuManager::WarnDefaultMenu(class CXWnd *),CContextMenuManager__WarnDefaultMenu);
#endif
#ifdef CContextMenuManager__HandleWindowMenuCommands
REVERSE_DETOUR(int  CContextMenuManager::HandleWindowMenuCommands(class CXWnd *,int),CContextMenuManager__HandleWindowMenuCommands);
#endif
#ifdef CXRect__Width
REVERSE_DETOUR(int  CXRect::Width(void)const ,CXRect__Width);
#endif
#ifdef CCursorAttachment__CCursorAttachment
REVERSE_DETOUR( CCursorAttachment::CCursorAttachment(class CXWnd *),CCursorAttachment__CCursorAttachment);
#endif
#ifdef CCursorAttachment__Init
REVERSE_DETOUR(void  CCursorAttachment::Init(void),CCursorAttachment__Init);
#endif
#ifdef CCursorAttachment__Activate
REVERSE_DETOUR(void  CCursorAttachment::Activate(class CTextureAnimation *,int,int,int),CCursorAttachment__Activate);
#endif
#ifdef CCursorAttachment__DrawButtonText
REVERSE_DETOUR(void  CCursorAttachment::DrawButtonText(void)const ,CCursorAttachment__DrawButtonText);
#endif
#ifdef CCursorAttachment__DrawQuantity
REVERSE_DETOUR(void  CCursorAttachment::DrawQuantity(void)const ,CCursorAttachment__DrawQuantity);
#endif
#ifdef CCursorAttachment__IsOkToActivate
REVERSE_DETOUR(bool  CCursorAttachment::IsOkToActivate(int),CCursorAttachment__IsOkToActivate);
#endif
#ifdef CCursorAttachment__RemoveAttachment
REVERSE_DETOUR(bool  CCursorAttachment::RemoveAttachment(void),CCursorAttachment__RemoveAttachment);
#endif
#ifdef CTextureAnimation__Reset
REVERSE_DETOUR(void  CTextureAnimation::Reset(void),CTextureAnimation__Reset);
#endif
#ifdef CEditLabelWnd__CEditLabelWnd
REVERSE_DETOUR( CEditLabelWnd::CEditLabelWnd(class CXWnd *),CEditLabelWnd__CEditLabelWnd);
#endif
#ifdef CEditLabelWnd__Activate
REVERSE_DETOUR(void  CEditLabelWnd::Activate(class CXWnd *,char *,int,unsigned long),CEditLabelWnd__Activate);
#endif
#ifdef CEQSuiteTextureLoader__dCEQSuiteTextureLoader
REVERSE_DETOUR( CEQSuiteTextureLoader::~CEQSuiteTextureLoader(void),CEQSuiteTextureLoader__dCEQSuiteTextureLoader);
#endif
#ifdef CEQSuiteTextureLoader__CreateTexture
REVERSE_DETOUR(unsigned int  CEQSuiteTextureLoader::CreateTexture(class CUITextureInfo const &),CEQSuiteTextureLoader__CreateTexture);
#endif
#ifdef CEQSuiteTextureLoader__UnloadAllTextures
REVERSE_DETOUR(void  CEQSuiteTextureLoader::UnloadAllTextures(void),CEQSuiteTextureLoader__UnloadAllTextures);
#endif
#ifdef CEQSuiteTextureLoader__GetTexture
REVERSE_DETOUR(struct T3D_tagBMINFO *  CEQSuiteTextureLoader::GetTexture(class CUITextureInfo const &),CEQSuiteTextureLoader__GetTexture);
#endif
#ifdef CUITextureInfo__GetName
REVERSE_DETOUR(class CXStr  CUITextureInfo::GetName(void)const ,CUITextureInfo__GetName);
#endif
#ifdef CEQSuiteTextureLoader__CEQSuiteTextureLoader
REVERSE_DETOUR( CEQSuiteTextureLoader::CEQSuiteTextureLoader(void),CEQSuiteTextureLoader__CEQSuiteTextureLoader);
#endif
#ifdef CExploreModeWnd__CExploreModeWnd
REVERSE_DETOUR( CExploreModeWnd::CExploreModeWnd(class CXWnd *),CExploreModeWnd__CExploreModeWnd);
#endif
#ifdef CExploreModeWnd__Activate
REVERSE_DETOUR(void  CExploreModeWnd::Activate(void),CExploreModeWnd__Activate);
#endif
#ifdef CFacePick__CFacePick
REVERSE_DETOUR( CFacePick::CFacePick(class CXWnd *),CFacePick__CFacePick);
#endif
#ifdef CFacePick__Init
REVERSE_DETOUR(void  CFacePick::Init(void),CFacePick__Init);
#endif
#ifdef CFacePick__ShowButtonGroup
REVERSE_DETOUR(void  CFacePick::ShowButtonGroup(int,bool),CFacePick__ShowButtonGroup);
#endif
#ifdef CFacePick__Activate
REVERSE_DETOUR(void  CFacePick::Activate(void),CFacePick__Activate);
#endif
#ifdef CFacePick__SetFaceSelectionsFromPlayer
REVERSE_DETOUR(void  CFacePick::SetFaceSelectionsFromPlayer(void),CFacePick__SetFaceSelectionsFromPlayer);
#endif
#ifdef CFacePick__CycleThroughFHEB
REVERSE_DETOUR(void  CFacePick::CycleThroughFHEB(int,int),CFacePick__CycleThroughFHEB);
#endif
#ifdef CFeedbackWnd__CFeedbackWnd
REVERSE_DETOUR( CFeedbackWnd::CFeedbackWnd(class CXWnd *),CFeedbackWnd__CFeedbackWnd);
#endif
#ifdef CFeedbackWnd__Activate
REVERSE_DETOUR(void  CFeedbackWnd::Activate(void),CFeedbackWnd__Activate);
#endif
#ifdef CFileSelectionWnd__CFileSelectionWnd
REVERSE_DETOUR( CFileSelectionWnd::CFileSelectionWnd(class CXWnd *),CFileSelectionWnd__CFileSelectionWnd);
#endif
#ifdef CFileSelectionWnd__Activate
REVERSE_DETOUR(void  CFileSelectionWnd::Activate(class CXWnd *,int),CFileSelectionWnd__Activate);
#endif
#ifdef CFileSelectionWnd__Callback
REVERSE_DETOUR(void  CFileSelectionWnd::Callback(bool),CFileSelectionWnd__Callback);
#endif
#ifdef CFileSelectionWnd__MakeFilePath
REVERSE_DETOUR(void  CFileSelectionWnd::MakeFilePath(void),CFileSelectionWnd__MakeFilePath);
#endif
#ifdef CFileSelectionWnd__GoSubdirectory
REVERSE_DETOUR(void  CFileSelectionWnd::GoSubdirectory(struct _ITEMIDLIST *),CFileSelectionWnd__GoSubdirectory);
#endif
#ifdef CFileSelectionWnd__UpdateButtons
REVERSE_DETOUR(void  CFileSelectionWnd::UpdateButtons(void),CFileSelectionWnd__UpdateButtons);
#endif
#ifdef CFileSelectionWnd__DirectoryEmpty
REVERSE_DETOUR(bool  CFileSelectionWnd::DirectoryEmpty(struct IShellFolder *,struct _ITEMIDLIST *),CFileSelectionWnd__DirectoryEmpty);
#endif
#ifdef CFileSelectionWnd__UpdateFileList
REVERSE_DETOUR(void  CFileSelectionWnd::UpdateFileList(void),CFileSelectionWnd__UpdateFileList);
#endif
#ifdef CFileSelectionWnd__ClearFileList
REVERSE_DETOUR(void  CFileSelectionWnd::ClearFileList(void),CFileSelectionWnd__ClearFileList);
#endif
#ifdef CFileSelectionWnd__GetPath
REVERSE_DETOUR(unsigned long  CFileSelectionWnd::GetPath(struct IShellFolder *,struct _ITEMIDLIST *,bool,class CXStr &),CFileSelectionWnd__GetPath);
#endif
#ifdef CFileSelectionWnd__GetSelectedFileCount
REVERSE_DETOUR(int  CFileSelectionWnd::GetSelectedFileCount(void),CFileSelectionWnd__GetSelectedFileCount);
#endif
#ifdef CFileSelectionWnd__GetSelectedFile
REVERSE_DETOUR(class CXStr  CFileSelectionWnd::GetSelectedFile(int),CFileSelectionWnd__GetSelectedFile);
#endif
#ifdef CXStr__Left
REVERSE_DETOUR(class CXStr  CXStr::Left(int)const ,CXStr__Left);
#endif
#ifdef CXStr__Right
REVERSE_DETOUR(class CXStr  CXStr::Right(int)const ,CXStr__Right);
#endif
#ifdef CFriendsWnd__CFriendsWnd
REVERSE_DETOUR( CFriendsWnd::CFriendsWnd(class CXWnd *),CFriendsWnd__CFriendsWnd);
#endif
#ifdef CFriendsWnd__UpdateFriendsList
REVERSE_DETOUR(void  CFriendsWnd::UpdateFriendsList(void),CFriendsWnd__UpdateFriendsList);
#endif
#ifdef CFriendsWnd__UpdateIgnoreList
REVERSE_DETOUR(void  CFriendsWnd::UpdateIgnoreList(void),CFriendsWnd__UpdateIgnoreList);
#endif
#ifdef CFriendsWnd__Activate
REVERSE_DETOUR(void  CFriendsWnd::Activate(void),CFriendsWnd__Activate);
#endif
#ifdef CFriendsWnd__AddFriend
REVERSE_DETOUR(void  CFriendsWnd::AddFriend(void),CFriendsWnd__AddFriend);
#endif
#ifdef CFriendsWnd__AddIgnore
REVERSE_DETOUR(void  CFriendsWnd::AddIgnore(void),CFriendsWnd__AddIgnore);
#endif
#ifdef CFriendsWnd__UpdateButtons
REVERSE_DETOUR(void  CFriendsWnd::UpdateButtons(void),CFriendsWnd__UpdateButtons);
#endif
#ifdef CGemsGameWnd__CGemsGameWnd
REVERSE_DETOUR( CGemsGameWnd::CGemsGameWnd(class CXWnd *),CGemsGameWnd__CGemsGameWnd);
#endif
#ifdef CGemsGameWnd__Init
REVERSE_DETOUR(void  CGemsGameWnd::Init(void),CGemsGameWnd__Init);
#endif
#ifdef CGemsGameWnd__Activate
REVERSE_DETOUR(void  CGemsGameWnd::Activate(void),CGemsGameWnd__Activate);
#endif
#ifdef CGemsGameWnd__Restart
REVERSE_DETOUR(void  CGemsGameWnd::Restart(void),CGemsGameWnd__Restart);
#endif
#ifdef CGemsGameWnd__AdvanceToNextWave
REVERSE_DETOUR(void  CGemsGameWnd::AdvanceToNextWave(void),CGemsGameWnd__AdvanceToNextWave);
#endif
#ifdef CGemsGameWnd__DoMatchScore
REVERSE_DETOUR(void  CGemsGameWnd::DoMatchScore(int),CGemsGameWnd__DoMatchScore);
#endif
#ifdef CGemsGameWnd__DrawSpellGem
REVERSE_DETOUR(void  CGemsGameWnd::DrawSpellGem(int,class CXRect,int,bool)const ,CGemsGameWnd__DrawSpellGem);
#endif
#ifdef CGemsGameWnd__SetPause
REVERSE_DETOUR(void  CGemsGameWnd::SetPause(bool),CGemsGameWnd__SetPause);
#endif
#ifdef CGemsGameWnd__TogglePause
REVERSE_DETOUR(void  CGemsGameWnd::TogglePause(void),CGemsGameWnd__TogglePause);
#endif
#ifdef CGemsGameWnd__SetNextUpdate
REVERSE_DETOUR(void  CGemsGameWnd::SetNextUpdate(void),CGemsGameWnd__SetNextUpdate);
#endif
#ifdef CGemsGameWnd__GetRndBlockImage
REVERSE_DETOUR(int  CGemsGameWnd::GetRndBlockImage(void),CGemsGameWnd__GetRndBlockImage);
#endif
#ifdef CGemsGameWnd__BadSpecial
REVERSE_DETOUR(bool  CGemsGameWnd::BadSpecial(int)const ,CGemsGameWnd__BadSpecial);
#endif
#ifdef CGemsGameWnd__ActivateSpecialMode
REVERSE_DETOUR(void  CGemsGameWnd::ActivateSpecialMode(int),CGemsGameWnd__ActivateSpecialMode);
#endif
#ifdef CGemsGameWnd__GetNextBlock
REVERSE_DETOUR(void  CGemsGameWnd::GetNextBlock(void),CGemsGameWnd__GetNextBlock);
#endif
#ifdef CGemsGameWnd__MoveCurBlock
REVERSE_DETOUR(void  CGemsGameWnd::MoveCurBlock(int),CGemsGameWnd__MoveCurBlock);
#endif
#ifdef CGemsGameWnd__ProcessMoveCurBlock
REVERSE_DETOUR(void  CGemsGameWnd::ProcessMoveCurBlock(int),CGemsGameWnd__ProcessMoveCurBlock);
#endif
#ifdef CGemsGameWnd__LegalBlockMove
REVERSE_DETOUR(bool  CGemsGameWnd::LegalBlockMove(int,int,int,int,bool),CGemsGameWnd__LegalBlockMove);
#endif
#ifdef CGemsGameWnd__MarkHigherBlocksFalling
REVERSE_DETOUR(void  CGemsGameWnd::MarkHigherBlocksFalling(int,int),CGemsGameWnd__MarkHigherBlocksFalling);
#endif
#ifdef CGemsGameWnd__ClearBlock
REVERSE_DETOUR(void  CGemsGameWnd::ClearBlock(struct _GemsBlock *),CGemsGameWnd__ClearBlock);
#endif
#ifdef CGemsGameWnd__ClearHighScores
REVERSE_DETOUR(void  CGemsGameWnd::ClearHighScores(void),CGemsGameWnd__ClearHighScores);
#endif
#ifdef CGemsGameWnd__ReadHighScores
REVERSE_DETOUR(void  CGemsGameWnd::ReadHighScores(void),CGemsGameWnd__ReadHighScores);
#endif
#ifdef CGemsGameWnd__WriteHighScores
REVERSE_DETOUR(void  CGemsGameWnd::WriteHighScores(void),CGemsGameWnd__WriteHighScores);
#endif
#ifdef CGemsGameWnd__CheckForNewHighScore
REVERSE_DETOUR(void  CGemsGameWnd::CheckForNewHighScore(void),CGemsGameWnd__CheckForNewHighScore);
#endif
#ifdef CGemsGameWnd__ProcessMatches
REVERSE_DETOUR(void  CGemsGameWnd::ProcessMatches(int),CGemsGameWnd__ProcessMatches);
#endif
#ifdef CGemsGameWnd__CheckForMatches
REVERSE_DETOUR(void  CGemsGameWnd::CheckForMatches(int,int),CGemsGameWnd__CheckForMatches);
#endif
#ifdef CGemsGameWnd__MakeBlockDrop
REVERSE_DETOUR(void  CGemsGameWnd::MakeBlockDrop(int,int,int),CGemsGameWnd__MakeBlockDrop);
#endif
#ifdef CGemsGameWnd__Update
REVERSE_DETOUR(void  CGemsGameWnd::Update(void),CGemsGameWnd__Update);
#endif
#ifdef CGemsGameWnd__UpdateDisplay
REVERSE_DETOUR(void  CGemsGameWnd::UpdateDisplay(void),CGemsGameWnd__UpdateDisplay);
#endif
#ifdef CGiveWnd__CGiveWnd
REVERSE_DETOUR( CGiveWnd::CGiveWnd(class CXWnd *),CGiveWnd__CGiveWnd);
#endif
#ifdef CGiveWnd__Activate
REVERSE_DETOUR(void  CGiveWnd::Activate(void),CGiveWnd__Activate);
#endif
#ifdef CGiveWnd__UpdateGiveDisplay
REVERSE_DETOUR(void  CGiveWnd::UpdateGiveDisplay(void),CGiveWnd__UpdateGiveDisplay);
#endif
#ifdef CGroupSearchFiltersWnd__CGroupSearchFiltersWnd
REVERSE_DETOUR( CGroupSearchFiltersWnd::CGroupSearchFiltersWnd(class CXWnd *),CGroupSearchFiltersWnd__CGroupSearchFiltersWnd);
#endif
#ifdef CGroupSearchFiltersWnd__Activate
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::Activate(void),CGroupSearchFiltersWnd__Activate);
#endif
#ifdef CGroupSearchFiltersWnd__ClearUiPointers
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::ClearUiPointers(void),CGroupSearchFiltersWnd__ClearUiPointers);
#endif
#ifdef CGroupSearchFiltersWnd__FetchUiPointers
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::FetchUiPointers(void),CGroupSearchFiltersWnd__FetchUiPointers);
#endif
#ifdef CGroupSearchFiltersWnd__InitPieces
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::InitPieces(void),CGroupSearchFiltersWnd__InitPieces);
#endif
#ifdef CGroupSearchFiltersWnd__ShouldFilterPlayer
REVERSE_DETOUR(bool  CGroupSearchFiltersWnd::ShouldFilterPlayer(char const *,char const *)const ,CGroupSearchFiltersWnd__ShouldFilterPlayer);
#endif
#ifdef CGroupSearchFiltersWnd__UseExclusiveSearchMode
REVERSE_DETOUR(bool  CGroupSearchFiltersWnd::UseExclusiveSearchMode(void)const ,CGroupSearchFiltersWnd__UseExclusiveSearchMode);
#endif
#ifdef CGroupSearchFiltersWnd__HandleUseIgnoreListSelected
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::HandleUseIgnoreListSelected(void),CGroupSearchFiltersWnd__HandleUseIgnoreListSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleUseFriendsListSelected
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::HandleUseFriendsListSelected(void),CGroupSearchFiltersWnd__HandleUseFriendsListSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleExcludeGuildsSelected
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::HandleExcludeGuildsSelected(void),CGroupSearchFiltersWnd__HandleExcludeGuildsSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleDesiredGuildsSelected
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::HandleDesiredGuildsSelected(void),CGroupSearchFiltersWnd__HandleDesiredGuildsSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleAddExcludedGuild
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::HandleAddExcludedGuild(void),CGroupSearchFiltersWnd__HandleAddExcludedGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveExcludedGuild
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::HandleRemoveExcludedGuild(void),CGroupSearchFiltersWnd__HandleRemoveExcludedGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveAllExcludedGuilds
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::HandleRemoveAllExcludedGuilds(void),CGroupSearchFiltersWnd__HandleRemoveAllExcludedGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__HandleAddDesiredGuild
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::HandleAddDesiredGuild(void),CGroupSearchFiltersWnd__HandleAddDesiredGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveDesiredGuild
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::HandleRemoveDesiredGuild(void),CGroupSearchFiltersWnd__HandleRemoveDesiredGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveAllDesiredGuilds
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::HandleRemoveAllDesiredGuilds(void),CGroupSearchFiltersWnd__HandleRemoveAllDesiredGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__UseIgnoreList
REVERSE_DETOUR(bool  CGroupSearchFiltersWnd::UseIgnoreList(void)const ,CGroupSearchFiltersWnd__UseIgnoreList);
#endif
#ifdef CGroupSearchFiltersWnd__UseFriendsList
REVERSE_DETOUR(bool  CGroupSearchFiltersWnd::UseFriendsList(void)const ,CGroupSearchFiltersWnd__UseFriendsList);
#endif
#ifdef CGroupSearchFiltersWnd__UseExcludedGuilds
REVERSE_DETOUR(bool  CGroupSearchFiltersWnd::UseExcludedGuilds(void)const ,CGroupSearchFiltersWnd__UseExcludedGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__UseDesiredGuilds
REVERSE_DETOUR(bool  CGroupSearchFiltersWnd::UseDesiredGuilds(void)const ,CGroupSearchFiltersWnd__UseDesiredGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__NameIsInIgnoreList
REVERSE_DETOUR(bool  CGroupSearchFiltersWnd::NameIsInIgnoreList(char const *)const ,CGroupSearchFiltersWnd__NameIsInIgnoreList);
#endif
#ifdef CGroupSearchFiltersWnd__NameIsInFriendsList
REVERSE_DETOUR(bool  CGroupSearchFiltersWnd::NameIsInFriendsList(char const *)const ,CGroupSearchFiltersWnd__NameIsInFriendsList);
#endif
#ifdef CGroupSearchFiltersWnd__GuildIsInExcludedGuildsList
REVERSE_DETOUR(bool  CGroupSearchFiltersWnd::GuildIsInExcludedGuildsList(char const *)const ,CGroupSearchFiltersWnd__GuildIsInExcludedGuildsList);
#endif
#ifdef CGroupSearchFiltersWnd__GuildIsInDesiredGuildsList
REVERSE_DETOUR(bool  CGroupSearchFiltersWnd::GuildIsInDesiredGuildsList(char const *)const ,CGroupSearchFiltersWnd__GuildIsInDesiredGuildsList);
#endif
#ifdef CGroupSearchFiltersWnd__Save
REVERSE_DETOUR(void  CGroupSearchFiltersWnd::Save(void)const ,CGroupSearchFiltersWnd__Save);
#endif
#ifdef CGroupSearchFiltersWnd__Load
REVERSE_DETOUR(bool  CGroupSearchFiltersWnd::Load(void),CGroupSearchFiltersWnd__Load);
#endif
#ifdef CGroupSearchWnd__CGroupSearchWnd
REVERSE_DETOUR( CGroupSearchWnd::CGroupSearchWnd(class CXWnd *),CGroupSearchWnd__CGroupSearchWnd);
#endif
#ifdef CGroupSearchWnd__Activate
REVERSE_DETOUR(void  CGroupSearchWnd::Activate(int),CGroupSearchWnd__Activate);
#endif
#ifdef CGroupSearchWnd__ClearUiPointers
REVERSE_DETOUR(void  CGroupSearchWnd::ClearUiPointers(void),CGroupSearchWnd__ClearUiPointers);
#endif
#ifdef CGroupSearchWnd__FetchUiPointers
REVERSE_DETOUR(void  CGroupSearchWnd::FetchUiPointers(void),CGroupSearchWnd__FetchUiPointers);
#endif
#ifdef CGroupSearchWnd__ResetGroupList
REVERSE_DETOUR(void  CGroupSearchWnd::ResetGroupList(void),CGroupSearchWnd__ResetGroupList);
#endif
#ifdef CGroupSearchWnd__AddGroupResult
REVERSE_DETOUR(void  CGroupSearchWnd::AddGroupResult(struct LfgGroupResult const *),CGroupSearchWnd__AddGroupResult);
#endif
#ifdef SListWndLine__dSListWndLine
REVERSE_DETOUR( SListWndLine::~SListWndLine(void),SListWndLine__dSListWndLine);
#endif
#ifdef CUITextureInfo__dCUITextureInfo
REVERSE_DETOUR( CUITextureInfo::~CUITextureInfo(void),CUITextureInfo__dCUITextureInfo);
#endif
#ifdef CUITexturePiece__dCUITexturePiece
REVERSE_DETOUR( CUITexturePiece::~CUITexturePiece(void),CUITexturePiece__dCUITexturePiece);
#endif
#ifdef SListWndCell__dSListWndCell
REVERSE_DETOUR( SListWndCell::~SListWndCell(void),SListWndCell__dSListWndCell);
#endif
#ifdef STextureAnimationFrame__dSTextureAnimationFrame
REVERSE_DETOUR( STextureAnimationFrame::~STextureAnimationFrame(void),STextureAnimationFrame__dSTextureAnimationFrame);
#endif
#ifdef CGroupSearchWnd__ResetPlayerList
REVERSE_DETOUR(void  CGroupSearchWnd::ResetPlayerList(void),CGroupSearchWnd__ResetPlayerList);
#endif
#ifdef CGroupSearchWnd__AddPlayerResult
REVERSE_DETOUR(void  CGroupSearchWnd::AddPlayerResult(struct LfgPlayerResult const *),CGroupSearchWnd__AddPlayerResult);
#endif
#ifdef CGroupSearchWnd__InitLfg
REVERSE_DETOUR(void  CGroupSearchWnd::InitLfg(void),CGroupSearchWnd__InitLfg);
#endif
#ifdef CGroupSearchWnd__InitLfp
REVERSE_DETOUR(void  CGroupSearchWnd::InitLfp(void),CGroupSearchWnd__InitLfp);
#endif
#ifdef CGroupSearchWnd__UpdatePlayerLabel
REVERSE_DETOUR(void  CGroupSearchWnd::UpdatePlayerLabel(void),CGroupSearchWnd__UpdatePlayerLabel);
#endif
#ifdef CGroupSearchWnd__UpdateGroupLabel
REVERSE_DETOUR(void  CGroupSearchWnd::UpdateGroupLabel(void),CGroupSearchWnd__UpdateGroupLabel);
#endif
#ifdef CGroupSearchWnd__RedirectOnProcessFrameTo
REVERSE_DETOUR(int  CGroupSearchWnd::RedirectOnProcessFrameTo(class CPageWnd *),CGroupSearchWnd__RedirectOnProcessFrameTo);
#endif
#ifdef CGroupSearchWnd__RedirectWndNotificationTo
REVERSE_DETOUR(int  CGroupSearchWnd::RedirectWndNotificationTo(class CPageWnd *,class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__RedirectWndNotificationTo);
#endif
#ifdef CGroupSearchWnd__PlayerInfoPageWndNotification
REVERSE_DETOUR(int  CGroupSearchWnd::PlayerInfoPageWndNotification(class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__PlayerInfoPageWndNotification);
#endif
#ifdef CGroupSearchWnd__GroupInfoPageWndNotification
REVERSE_DETOUR(int  CGroupSearchWnd::GroupInfoPageWndNotification(class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__GroupInfoPageWndNotification);
#endif
#ifdef CGroupSearchWnd__PlayerListPageWndNotification
REVERSE_DETOUR(int  CGroupSearchWnd::PlayerListPageWndNotification(class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__PlayerListPageWndNotification);
#endif
#ifdef CGroupSearchWnd__GroupListPageWndNotification
REVERSE_DETOUR(int  CGroupSearchWnd::GroupListPageWndNotification(class CXWnd *,unsigned __int32,void *),CGroupSearchWnd__GroupListPageWndNotification);
#endif
#ifdef CGroupSearchWnd__PlayerInfoPageOnProcessFrame
REVERSE_DETOUR(int  CGroupSearchWnd::PlayerInfoPageOnProcessFrame(void),CGroupSearchWnd__PlayerInfoPageOnProcessFrame);
#endif
#ifdef CGroupSearchWnd__GroupInfoPageOnProcessFrame
REVERSE_DETOUR(int  CGroupSearchWnd::GroupInfoPageOnProcessFrame(void),CGroupSearchWnd__GroupInfoPageOnProcessFrame);
#endif
#ifdef CGroupSearchWnd__HandlePlayerInfoPost
REVERSE_DETOUR(void  CGroupSearchWnd::HandlePlayerInfoPost(void),CGroupSearchWnd__HandlePlayerInfoPost);
#endif
#ifdef CGroupSearchWnd__HandlePlayerInfoUpdate
REVERSE_DETOUR(void  CGroupSearchWnd::HandlePlayerInfoUpdate(void),CGroupSearchWnd__HandlePlayerInfoUpdate);
#endif
#ifdef CGroupSearchWnd__HandlePlayerInfoRemove
REVERSE_DETOUR(void  CGroupSearchWnd::HandlePlayerInfoRemove(void),CGroupSearchWnd__HandlePlayerInfoRemove);
#endif
#ifdef CGroupSearchWnd__HandleGroupInfoPost
REVERSE_DETOUR(void  CGroupSearchWnd::HandleGroupInfoPost(void),CGroupSearchWnd__HandleGroupInfoPost);
#endif
#ifdef CGroupSearchWnd__HandleGroupInfoUpdate
REVERSE_DETOUR(void  CGroupSearchWnd::HandleGroupInfoUpdate(void),CGroupSearchWnd__HandleGroupInfoUpdate);
#endif
#ifdef CGroupSearchWnd__HandleGroupInfoRemove
REVERSE_DETOUR(void  CGroupSearchWnd::HandleGroupInfoRemove(void),CGroupSearchWnd__HandleGroupInfoRemove);
#endif
#ifdef CGroupSearchWnd__HandleSelectAllClasses
REVERSE_DETOUR(void  CGroupSearchWnd::HandleSelectAllClasses(void),CGroupSearchWnd__HandleSelectAllClasses);
#endif
#ifdef CGroupSearchWnd__HandleDeselectAllClasses
REVERSE_DETOUR(void  CGroupSearchWnd::HandleDeselectAllClasses(void),CGroupSearchWnd__HandleDeselectAllClasses);
#endif
#ifdef CGroupSearchWnd__HandleOpenFiltersWindow
REVERSE_DETOUR(void  CGroupSearchWnd::HandleOpenFiltersWindow(void),CGroupSearchWnd__HandleOpenFiltersWindow);
#endif
#ifdef CGroupSearchWnd__HandleQueryingForGroups
REVERSE_DETOUR(void  CGroupSearchWnd::HandleQueryingForGroups(void),CGroupSearchWnd__HandleQueryingForGroups);
#endif
#ifdef CGroupSearchWnd__HandleQueryingForPlayers
REVERSE_DETOUR(void  CGroupSearchWnd::HandleQueryingForPlayers(void),CGroupSearchWnd__HandleQueryingForPlayers);
#endif
#ifdef CGroupSearchWnd__SendServerLfgOn
REVERSE_DETOUR(void  CGroupSearchWnd::SendServerLfgOn(void),CGroupSearchWnd__SendServerLfgOn);
#endif
#ifdef CGroupSearchWnd__SendServerLfgOff
REVERSE_DETOUR(void  CGroupSearchWnd::SendServerLfgOff(void),CGroupSearchWnd__SendServerLfgOff);
#endif
#ifdef CGroupSearchWnd__SendServerLfpOn
REVERSE_DETOUR(void  CGroupSearchWnd::SendServerLfpOn(void),CGroupSearchWnd__SendServerLfpOn);
#endif
#ifdef CGroupSearchWnd__SendServerLfpOff
REVERSE_DETOUR(void  CGroupSearchWnd::SendServerLfpOff(void),CGroupSearchWnd__SendServerLfpOff);
#endif
#ifdef CGroupSearchWnd__ShowGroupDetails
REVERSE_DETOUR(void  CGroupSearchWnd::ShowGroupDetails(struct LfgGroupResult const *),CGroupSearchWnd__ShowGroupDetails);
#endif
#ifdef CGroupSearchWnd__PlayerShouldBeFiltered
REVERSE_DETOUR(bool  CGroupSearchWnd::PlayerShouldBeFiltered(struct LfgPlayerData const *)const ,CGroupSearchWnd__PlayerShouldBeFiltered);
#endif
#ifdef CGroupSearchWnd__FilterOutBadWords
REVERSE_DETOUR(void  CGroupSearchWnd::FilterOutBadWords(char const *,char *)const ,CGroupSearchWnd__FilterOutBadWords);
#endif
#ifdef CGroupSearchWnd__LockQueryButtonAtTime
REVERSE_DETOUR(void  CGroupSearchWnd::LockQueryButtonAtTime(long),CGroupSearchWnd__LockQueryButtonAtTime);
#endif
#ifdef CGroupSearchWnd__UpdateRemainingQueryLockedTime
REVERSE_DETOUR(void  CGroupSearchWnd::UpdateRemainingQueryLockedTime(long),CGroupSearchWnd__UpdateRemainingQueryLockedTime);
#endif
#ifdef CGroupSearchWnd__HandleGroupResultColSelected
REVERSE_DETOUR(void  CGroupSearchWnd::HandleGroupResultColSelected(int),CGroupSearchWnd__HandleGroupResultColSelected);
#endif
#ifdef CGroupSearchWnd__HandlePlayerResultColSelected
REVERSE_DETOUR(void  CGroupSearchWnd::HandlePlayerResultColSelected(int),CGroupSearchWnd__HandlePlayerResultColSelected);
#endif
#ifdef CGroupSearchWnd__HandleGroupResultRowSelected
REVERSE_DETOUR(void  CGroupSearchWnd::HandleGroupResultRowSelected(int),CGroupSearchWnd__HandleGroupResultRowSelected);
#endif
#ifdef CGroupSearchWnd__HandleDoubleClickedOnPlayer
REVERSE_DETOUR(void  CGroupSearchWnd::HandleDoubleClickedOnPlayer(char const *),CGroupSearchWnd__HandleDoubleClickedOnPlayer);
#endif
#ifdef CGroupSearchWnd__HandleNumericSort
REVERSE_DETOUR(void  CGroupSearchWnd::HandleNumericSort(class SListWndSortInfo *),CGroupSearchWnd__HandleNumericSort);
#endif
#ifdef CGroupSearchWnd__HandleGroupMakeupChanged
REVERSE_DETOUR(void  CGroupSearchWnd::HandleGroupMakeupChanged(void),CGroupSearchWnd__HandleGroupMakeupChanged);
#endif
#ifdef CGroupSearchWnd__CheckIfCurrentLfgInfoIsValid
REVERSE_DETOUR(int  CGroupSearchWnd::CheckIfCurrentLfgInfoIsValid(void)const ,CGroupSearchWnd__CheckIfCurrentLfgInfoIsValid);
#endif
#ifdef CGroupSearchWnd__CheckIfCurrentLfpInfoIsValid
REVERSE_DETOUR(int  CGroupSearchWnd::CheckIfCurrentLfpInfoIsValid(void)const ,CGroupSearchWnd__CheckIfCurrentLfpInfoIsValid);
#endif
#ifdef CGroupSearchWnd__UpdateLfgPostingStatus
REVERSE_DETOUR(void  CGroupSearchWnd::UpdateLfgPostingStatus(void),CGroupSearchWnd__UpdateLfgPostingStatus);
#endif
#ifdef CGroupSearchWnd__UpdateLfpPostingStatus
REVERSE_DETOUR(void  CGroupSearchWnd::UpdateLfpPostingStatus(void),CGroupSearchWnd__UpdateLfpPostingStatus);
#endif
#ifdef CGroupSearchWnd__GetDesiredPlayerMinLevel
REVERSE_DETOUR(int  CGroupSearchWnd::GetDesiredPlayerMinLevel(void)const ,CGroupSearchWnd__GetDesiredPlayerMinLevel);
#endif
#ifdef CGroupSearchWnd__GetDefaultLfgLevelRange
REVERSE_DETOUR(void  CGroupSearchWnd::GetDefaultLfgLevelRange(class EQ_PC const *,int *,int *)const ,CGroupSearchWnd__GetDefaultLfgLevelRange);
#endif
#ifdef CGroupSearchWnd__GetDefaultLfpLevelRange
REVERSE_DETOUR(void  CGroupSearchWnd::GetDefaultLfpLevelRange(class EQ_PC const *,int *,int *)const ,CGroupSearchWnd__GetDefaultLfpLevelRange);
#endif
#ifdef CGroupSearchWnd__GetDesiredPlayerMaxLevel
REVERSE_DETOUR(int  CGroupSearchWnd::GetDesiredPlayerMaxLevel(void)const ,CGroupSearchWnd__GetDesiredPlayerMaxLevel);
#endif
#ifdef CGroupSearchWnd__GetDesiredGroupMinLevel
REVERSE_DETOUR(int  CGroupSearchWnd::GetDesiredGroupMinLevel(void)const ,CGroupSearchWnd__GetDesiredGroupMinLevel);
#endif
#ifdef CGroupSearchWnd__GetDesiredGroupMaxLevel
REVERSE_DETOUR(int  CGroupSearchWnd::GetDesiredGroupMaxLevel(void)const ,CGroupSearchWnd__GetDesiredGroupMaxLevel);
#endif
#ifdef CGroupSearchWnd__IsLevelRangeValid
REVERSE_DETOUR(bool  CGroupSearchWnd::IsLevelRangeValid(int,int)const ,CGroupSearchWnd__IsLevelRangeValid);
#endif
#ifdef CGroupSearchWnd__GetDesiredClassesFlag
REVERSE_DETOUR(int  CGroupSearchWnd::GetDesiredClassesFlag(void)const ,CGroupSearchWnd__GetDesiredClassesFlag);
#endif
#ifdef CGroupSearchWnd__GetEqClassType
REVERSE_DETOUR(int  CGroupSearchWnd::GetEqClassType(int)const ,CGroupSearchWnd__GetEqClassType);
#endif
#ifdef CGroupSearchWnd__PopUpErrorMessage
REVERSE_DETOUR(void  CGroupSearchWnd::PopUpErrorMessage(int)const ,CGroupSearchWnd__PopUpErrorMessage);
#endif
#ifdef Util__SetBit
REVERSE_DETOUR(int __cdecl Util::SetBit(int,void *,int),Util__SetBit);
#endif
#ifdef _partyGroup__getNumMembers
REVERSE_DETOUR(int  _partyGroup::getNumMembers(void)const ,_partyGroup__getNumMembers);
#endif
#ifdef SListWndCell__SListWndCell
REVERSE_DETOUR( SListWndCell::SListWndCell(void),SListWndCell__SListWndCell);
#endif
#ifdef CGroupWnd__CGroupWnd
REVERSE_DETOUR( CGroupWnd::CGroupWnd(class CXWnd *),CGroupWnd__CGroupWnd);
#endif
#ifdef CGroupWnd__Init
REVERSE_DETOUR(void  CGroupWnd::Init(void),CGroupWnd__Init);
#endif
#ifdef CGroupWnd__Activate
REVERSE_DETOUR(void  CGroupWnd::Activate(void),CGroupWnd__Activate);
#endif
#ifdef CGroupWnd__SetInvited
REVERSE_DETOUR(void  CGroupWnd::SetInvited(bool),CGroupWnd__SetInvited);
#endif
#ifdef CGroupWnd__UpdateButtons
REVERSE_DETOUR(void  CGroupWnd::UpdateButtons(void),CGroupWnd__UpdateButtons);
#endif
#ifdef CGroupWnd__KeyMapUpdated
REVERSE_DETOUR(void  CGroupWnd::KeyMapUpdated(void),CGroupWnd__KeyMapUpdated);
#endif
#ifdef CGroupWnd__CreateLocalMenu
REVERSE_DETOUR(void  CGroupWnd::CreateLocalMenu(void),CGroupWnd__CreateLocalMenu);
#endif
#ifdef CGroupWnd__UpdateContextMenu
REVERSE_DETOUR(void  CGroupWnd::UpdateContextMenu(void),CGroupWnd__UpdateContextMenu);
#endif
#ifdef CGuildMgmtWnd__CGuildMgmtWnd
REVERSE_DETOUR( CGuildMgmtWnd::CGuildMgmtWnd(class CXWnd *),CGuildMgmtWnd__CGuildMgmtWnd);
#endif
#ifdef CGuildMgmtWnd__Init
REVERSE_DETOUR(void  CGuildMgmtWnd::Init(void),CGuildMgmtWnd__Init);
#endif
#ifdef CGuildMgmtWnd__UpdateButtons
REVERSE_DETOUR(void  CGuildMgmtWnd::UpdateButtons(void),CGuildMgmtWnd__UpdateButtons);
#endif
#ifdef CGuildMgmtWnd__Clean
REVERSE_DETOUR(void  CGuildMgmtWnd::Clean(void),CGuildMgmtWnd__Clean);
#endif
#ifdef CGuildMgmtWnd__SetMOTD
REVERSE_DETOUR(void  CGuildMgmtWnd::SetMOTD(char *,char *),CGuildMgmtWnd__SetMOTD);
#endif
#ifdef CGuildMgmtWnd__SetPlayerCount
REVERSE_DETOUR(void  CGuildMgmtWnd::SetPlayerCount(int),CGuildMgmtWnd__SetPlayerCount);
#endif
#ifdef CGuildMgmtWnd__CreatePersonalNotesFilename
REVERSE_DETOUR(void  CGuildMgmtWnd::CreatePersonalNotesFilename(void),CGuildMgmtWnd__CreatePersonalNotesFilename);
#endif
#ifdef CGuildMgmtWnd__LoadPersonalNotes
REVERSE_DETOUR(void  CGuildMgmtWnd::LoadPersonalNotes(void),CGuildMgmtWnd__LoadPersonalNotes);
#endif
#ifdef CGuildMgmtWnd__SavePersonalNotes
REVERSE_DETOUR(void  CGuildMgmtWnd::SavePersonalNotes(void),CGuildMgmtWnd__SavePersonalNotes);
#endif
#ifdef CGuildMgmtWnd__GetPersonalNote
REVERSE_DETOUR(char *  CGuildMgmtWnd::GetPersonalNote(char *),CGuildMgmtWnd__GetPersonalNote);
#endif
#ifdef CGuildMgmtWnd__SetPersonalNote
REVERSE_DETOUR(void  CGuildMgmtWnd::SetPersonalNote(char *,char *),CGuildMgmtWnd__SetPersonalNote);
#endif
#ifdef CGuildMgmtWnd__AddMember
REVERSE_DETOUR(void  CGuildMgmtWnd::AddMember(class GuildMember *),CGuildMgmtWnd__AddMember);
#endif
#ifdef CGuildMgmtWnd__RemoveMember
REVERSE_DETOUR(void  CGuildMgmtWnd::RemoveMember(class GuildMember *),CGuildMgmtWnd__RemoveMember);
#endif
#ifdef CGuildMgmtWnd__RenameMember
REVERSE_DETOUR(void  CGuildMgmtWnd::RenameMember(char *,char *),CGuildMgmtWnd__RenameMember);
#endif
#ifdef CGuildMgmtWnd__UpdateListMember
REVERSE_DETOUR(void  CGuildMgmtWnd::UpdateListMember(class GuildMember *,int),CGuildMgmtWnd__UpdateListMember);
#endif
#ifdef CGuildMgmtWnd__FindListMember
REVERSE_DETOUR(int  CGuildMgmtWnd::FindListMember(class GuildMember *),CGuildMgmtWnd__FindListMember);
#endif
#ifdef CGuildMgmtWnd__Activate
REVERSE_DETOUR(void  CGuildMgmtWnd::Activate(void),CGuildMgmtWnd__Activate);
#endif
#ifdef CGuildMgmtWnd__CleanAndRefillListWnd
REVERSE_DETOUR(void  CGuildMgmtWnd::CleanAndRefillListWnd(bool),CGuildMgmtWnd__CleanAndRefillListWnd);
#endif
#ifdef CGuildMgmtWnd__SortList
REVERSE_DETOUR(void  CGuildMgmtWnd::SortList(int,bool),CGuildMgmtWnd__SortList);
#endif
#ifdef CGuildMgmtWnd__DumpToFile
REVERSE_DETOUR(void  CGuildMgmtWnd::DumpToFile(char *),CGuildMgmtWnd__DumpToFile);
#endif
#ifdef CGuildMgmtWnd__LoadINI
REVERSE_DETOUR(void  CGuildMgmtWnd::LoadINI(void),CGuildMgmtWnd__LoadINI);
#endif
#ifdef CGuild__GetGuildMotd
REVERSE_DETOUR(char *  CGuild::GetGuildMotd(void),CGuild__GetGuildMotd);
#endif
#ifdef CGuild__GetGuildMotdAuthor
REVERSE_DETOUR(char *  CGuild::GetGuildMotdAuthor(void),CGuild__GetGuildMotdAuthor);
#endif
#ifdef EQPlayer__GetGuild
REVERSE_DETOUR(int  EQPlayer::GetGuild(void)const ,EQPlayer__GetGuild);
#endif
#ifdef CHelpWnd__CHelpWnd
REVERSE_DETOUR( CHelpWnd::CHelpWnd(class CXWnd *),CHelpWnd__CHelpWnd);
#endif
#ifdef CHelpWnd__SetFile
REVERSE_DETOUR(void  CHelpWnd::SetFile(char *),CHelpWnd__SetFile);
#endif
#ifdef CHotButtonWnd__CHotButtonWnd
REVERSE_DETOUR( CHotButtonWnd::CHotButtonWnd(class CXWnd *),CHotButtonWnd__CHotButtonWnd);
#endif
#ifdef CHotButtonWnd__Init
REVERSE_DETOUR(void  CHotButtonWnd::Init(void),CHotButtonWnd__Init);
#endif
#ifdef CHotButtonWnd__Activate
REVERSE_DETOUR(void  CHotButtonWnd::Activate(void),CHotButtonWnd__Activate);
#endif
#ifdef CHotButtonWnd__UpdatePage
REVERSE_DETOUR(void  CHotButtonWnd::UpdatePage(void),CHotButtonWnd__UpdatePage);
#endif
#ifdef CHotButtonWnd__DoHotButton
REVERSE_DETOUR(void  CHotButtonWnd::DoHotButton(int,int),CHotButtonWnd__DoHotButton);
#endif
#ifdef CHotButtonWnd__DoHotButtonRightClick
REVERSE_DETOUR(void  CHotButtonWnd::DoHotButtonRightClick(int),CHotButtonWnd__DoHotButtonRightClick);
#endif
#ifdef CInspectWnd__CInspectWnd
REVERSE_DETOUR( CInspectWnd::CInspectWnd(class CXWnd *),CInspectWnd__CInspectWnd);
#endif
#ifdef CInspectWnd__Init
REVERSE_DETOUR(void  CInspectWnd::Init(void),CInspectWnd__Init);
#endif
#ifdef CInspectWnd__Activate
REVERSE_DETOUR(void  CInspectWnd::Activate(struct _inspect *),CInspectWnd__Activate);
#endif
#ifdef CInspectWnd__AcceptInspectText
REVERSE_DETOUR(void  CInspectWnd::AcceptInspectText(void),CInspectWnd__AcceptInspectText);
#endif
#ifdef CInspectWnd__PlayerBeingDeleted
REVERSE_DETOUR(void  CInspectWnd::PlayerBeingDeleted(class EQPlayer *),CInspectWnd__PlayerBeingDeleted);
#endif
#ifdef CInventoryWnd__CInventoryWnd
REVERSE_DETOUR( CInventoryWnd::CInventoryWnd(class CXWnd *),CInventoryWnd__CInventoryWnd);
#endif
#ifdef CInventoryWnd__Init
REVERSE_DETOUR(void  CInventoryWnd::Init(void),CInventoryWnd__Init);
#endif
#ifdef CInventoryWnd__Activate
REVERSE_DETOUR(void  CInventoryWnd::Activate(void),CInventoryWnd__Activate);
#endif
#ifdef CInventoryWnd__DestroyHeld
REVERSE_DETOUR(void  CInventoryWnd::DestroyHeld(void),CInventoryWnd__DestroyHeld);
#endif
#ifdef CInventoryWnd__ClickedMoneyButton
REVERSE_DETOUR(void  CInventoryWnd::ClickedMoneyButton(int,int),CInventoryWnd__ClickedMoneyButton);
#endif
#ifdef CInventoryWnd__GetInventoryQtyFromCoinType
REVERSE_DETOUR(long  CInventoryWnd::GetInventoryQtyFromCoinType(int),CInventoryWnd__GetInventoryQtyFromCoinType);
#endif
#ifdef CInventoryWnd__UpdateMoneyDisplay
REVERSE_DETOUR(void  CInventoryWnd::UpdateMoneyDisplay(void),CInventoryWnd__UpdateMoneyDisplay);
#endif
#ifdef CInvSlot__CInvSlot
REVERSE_DETOUR( CInvSlot::CInvSlot(void),CInvSlot__CInvSlot);
#endif
#ifdef CInvSlot__SetInvSlotWnd
REVERSE_DETOUR(void  CInvSlot::SetInvSlotWnd(class CInvSlotWnd *),CInvSlot__SetInvSlotWnd);
#endif
#ifdef CInvSlot__SetItem
REVERSE_DETOUR(void  CInvSlot::SetItem(class EQ_Item *),CInvSlot__SetItem);
#endif
#ifdef CInvSlot__SliderComplete
REVERSE_DETOUR(void  CInvSlot::SliderComplete(int),CInvSlot__SliderComplete);
#endif
#ifdef CInvSlot__HandleLButtonUp
REVERSE_DETOUR(void  CInvSlot::HandleLButtonUp(class CXPoint,bool),CInvSlot__HandleLButtonUp);
#endif
#ifdef CInvSlot__HandleLButtonHeld
REVERSE_DETOUR(void  CInvSlot::HandleLButtonHeld(class CXPoint),CInvSlot__HandleLButtonHeld);
#endif
#ifdef CInvSlot__DoDrinkEatPoison
REVERSE_DETOUR(void  CInvSlot::DoDrinkEatPoison(class EQ_Item *,int),CInvSlot__DoDrinkEatPoison);
#endif
#ifdef CInvSlot__HandleRButtonUp
REVERSE_DETOUR(void  CInvSlot::HandleRButtonUp(class CXPoint),CInvSlot__HandleRButtonUp);
#endif
#ifdef CInvSlot__HandleRButtonHeld
REVERSE_DETOUR(void  CInvSlot::HandleRButtonHeld(class CXPoint),CInvSlot__HandleRButtonHeld);
#endif
#ifdef CInvSlot__HandleRButtonUpAfterHeld
REVERSE_DETOUR(void  CInvSlot::HandleRButtonUpAfterHeld(class CXPoint),CInvSlot__HandleRButtonUpAfterHeld);
#endif
#ifdef CInvSlot__IllegalBigBank
REVERSE_DETOUR(bool  CInvSlot::IllegalBigBank(int),CInvSlot__IllegalBigBank);
#endif
#ifdef CInvSlotMgr__CInvSlotMgr
REVERSE_DETOUR( CInvSlotMgr::CInvSlotMgr(void),CInvSlotMgr__CInvSlotMgr);
#endif
#ifdef CInvSlotMgr__MoveItem
REVERSE_DETOUR(int  CInvSlotMgr::MoveItem(int,int,int,int),CInvSlotMgr__MoveItem);
#endif
#ifdef CInvSlotMgr__CreateInvSlot
REVERSE_DETOUR(class CInvSlot *  CInvSlotMgr::CreateInvSlot(class CInvSlotWnd *),CInvSlotMgr__CreateInvSlot);
#endif
#ifdef CInvSlotMgr__FindInvSlot
REVERSE_DETOUR(class CInvSlot *  CInvSlotMgr::FindInvSlot(int),CInvSlotMgr__FindInvSlot);
#endif
#ifdef CInvSlotMgr__SelectSlot
REVERSE_DETOUR(void  CInvSlotMgr::SelectSlot(class CInvSlot *),CInvSlotMgr__SelectSlot);
#endif
#ifdef CInvSlotMgr__UpdateSlots
REVERSE_DETOUR(void  CInvSlotMgr::UpdateSlots(void),CInvSlotMgr__UpdateSlots);
#endif
#ifdef CItemDisplayWnd__CItemDisplayWnd
REVERSE_DETOUR( CItemDisplayWnd::CItemDisplayWnd(class CXWnd *),CItemDisplayWnd__CItemDisplayWnd);
#endif
#ifdef CItemDisplayWnd__UpdateStrings
REVERSE_DETOUR(void  CItemDisplayWnd::UpdateStrings(void),CItemDisplayWnd__UpdateStrings);
#endif
#ifdef CItemDisplayWnd__SetItem
REVERSE_DETOUR(void  CItemDisplayWnd::SetItem(class EQ_Item *,bool),CItemDisplayWnd__SetItem);
#endif
#ifdef CItemDisplayWnd__SetItemText
REVERSE_DETOUR(void  CItemDisplayWnd::SetItemText(char *),CItemDisplayWnd__SetItemText);
#endif
#ifdef CItemDisplayWnd__GetSizeString
REVERSE_DETOUR(void  CItemDisplayWnd::GetSizeString(int,char *),CItemDisplayWnd__GetSizeString);
#endif
#ifdef CItemDisplayWnd__CreateRaceString
REVERSE_DETOUR(class CXStr  CItemDisplayWnd::CreateRaceString(class EQ_Equipment *),CItemDisplayWnd__CreateRaceString);
#endif
#ifdef CItemDisplayWnd__CreateClassString
REVERSE_DETOUR(class CXStr  CItemDisplayWnd::CreateClassString(class EQ_Equipment *),CItemDisplayWnd__CreateClassString);
#endif
#ifdef CItemDisplayWnd__CreateMealSizeString
REVERSE_DETOUR(class CXStr  CItemDisplayWnd::CreateMealSizeString(class EQ_Equipment *),CItemDisplayWnd__CreateMealSizeString);
#endif
#ifdef CItemDisplayWnd__CreateModString
REVERSE_DETOUR(class CXStr  CItemDisplayWnd::CreateModString(class EQ_Equipment *,int,int,int *),CItemDisplayWnd__CreateModString);
#endif
#ifdef CItemDisplayWnd__CreateEquipmentStatusString
REVERSE_DETOUR(class CXStr  CItemDisplayWnd::CreateEquipmentStatusString(class EQ_Item *),CItemDisplayWnd__CreateEquipmentStatusString);
#endif
#ifdef CItemDisplayWnd__SetSpell
REVERSE_DETOUR(void  CItemDisplayWnd::SetSpell(int SpellID,bool HasSpellDescr,int),CItemDisplayWnd__SetSpell);
#endif
#ifdef CJournalCatWnd__CJournalCatWnd
REVERSE_DETOUR( CJournalCatWnd::CJournalCatWnd(class CXWnd *),CJournalCatWnd__CJournalCatWnd);
#endif
#ifdef CJournalCatWnd__Init
REVERSE_DETOUR(void  CJournalCatWnd::Init(void),CJournalCatWnd__Init);
#endif
#ifdef CJournalCatWnd__UpdateAll
REVERSE_DETOUR(void  CJournalCatWnd::UpdateAll(bool),CJournalCatWnd__UpdateAll);
#endif
#ifdef CJournalCatWnd__UpdateButtons
REVERSE_DETOUR(void  CJournalCatWnd::UpdateButtons(void),CJournalCatWnd__UpdateButtons);
#endif
#ifdef CJournalCatWnd__SelectCategory
REVERSE_DETOUR(void  CJournalCatWnd::SelectCategory(int),CJournalCatWnd__SelectCategory);
#endif
#ifdef CJournalCatWnd__Clean
REVERSE_DETOUR(void  CJournalCatWnd::Clean(void),CJournalCatWnd__Clean);
#endif
#ifdef CJournalCatWnd__BuildList
REVERSE_DETOUR(void  CJournalCatWnd::BuildList(void),CJournalCatWnd__BuildList);
#endif
#ifdef CJournalCatWnd__UpdateListWnd
REVERSE_DETOUR(void  CJournalCatWnd::UpdateListWnd(bool),CJournalCatWnd__UpdateListWnd);
#endif
#ifdef CJournalCatWnd__Activate
REVERSE_DETOUR(void  CJournalCatWnd::Activate(void),CJournalCatWnd__Activate);
#endif
#ifdef CJournalCatWnd__SortList
REVERSE_DETOUR(void  CJournalCatWnd::SortList(int,bool),CJournalCatWnd__SortList);
#endif
#ifdef CJournalCatWnd__LoadINI
REVERSE_DETOUR(void  CJournalCatWnd::LoadINI(void),CJournalCatWnd__LoadINI);
#endif
#ifdef CJournalCatWnd__StoreINI
REVERSE_DETOUR(void  CJournalCatWnd::StoreINI(void),CJournalCatWnd__StoreINI);
#endif
#ifdef CJournalNPCWnd__CJournalNPCWnd
REVERSE_DETOUR( CJournalNPCWnd::CJournalNPCWnd(class CXWnd *),CJournalNPCWnd__CJournalNPCWnd);
#endif
#ifdef CJournalNPCWnd__Init
REVERSE_DETOUR(void  CJournalNPCWnd::Init(void),CJournalNPCWnd__Init);
#endif
#ifdef CJournalNPCWnd__Activate
REVERSE_DETOUR(void  CJournalNPCWnd::Activate(void),CJournalNPCWnd__Activate);
#endif
#ifdef CJournalNPCWnd__UpdateAll
REVERSE_DETOUR(void  CJournalNPCWnd::UpdateAll(bool),CJournalNPCWnd__UpdateAll);
#endif
#ifdef CJournalNPCWnd__UpdateListWnd
REVERSE_DETOUR(void  CJournalNPCWnd::UpdateListWnd(bool),CJournalNPCWnd__UpdateListWnd);
#endif
#ifdef CJournalNPCWnd__SelectNPCIndex
REVERSE_DETOUR(void  CJournalNPCWnd::SelectNPCIndex(int),CJournalNPCWnd__SelectNPCIndex);
#endif
#ifdef CJournalNPCWnd__UpdateCategories
REVERSE_DETOUR(void  CJournalNPCWnd::UpdateCategories(void),CJournalNPCWnd__UpdateCategories);
#endif
#ifdef CJournalNPCWnd__UpdateButtons
REVERSE_DETOUR(void  CJournalNPCWnd::UpdateButtons(void),CJournalNPCWnd__UpdateButtons);
#endif
#ifdef CJournalNPCWnd__EnterIntoJournal
REVERSE_DETOUR(void  CJournalNPCWnd::EnterIntoJournal(char *,float,float,float,char *),CJournalNPCWnd__EnterIntoJournal);
#endif
#ifdef CJournalNPCWnd__DoBackups
REVERSE_DETOUR(void  CJournalNPCWnd::DoBackups(class CXStr),CJournalNPCWnd__DoBackups);
#endif
#ifdef CJournalNPCWnd__LoadJournal
REVERSE_DETOUR(void  CJournalNPCWnd::LoadJournal(int),CJournalNPCWnd__LoadJournal);
#endif
#ifdef CJournalNPCWnd__SaveJournal
REVERSE_DETOUR(void  CJournalNPCWnd::SaveJournal(void),CJournalNPCWnd__SaveJournal);
#endif
#ifdef CJournalNPCWnd__BuildList
REVERSE_DETOUR(void  CJournalNPCWnd::BuildList(void),CJournalNPCWnd__BuildList);
#endif
#ifdef CJournalNPCWnd__SortList
REVERSE_DETOUR(void  CJournalNPCWnd::SortList(int,bool),CJournalNPCWnd__SortList);
#endif
#ifdef CJournalNPCWnd__GetLogState
REVERSE_DETOUR(void  CJournalNPCWnd::GetLogState(void),CJournalNPCWnd__GetLogState);
#endif
#ifdef CJournalNPCWnd__StoreLogState
REVERSE_DETOUR(void  CJournalNPCWnd::StoreLogState(void),CJournalNPCWnd__StoreLogState);
#endif
#ifdef CJournalTextWnd__CJournalTextWnd
REVERSE_DETOUR( CJournalTextWnd::CJournalTextWnd(class CXWnd *),CJournalTextWnd__CJournalTextWnd);
#endif
#ifdef CJournalTextWnd__UpdateAll
REVERSE_DETOUR(void  CJournalTextWnd::UpdateAll(bool),CJournalTextWnd__UpdateAll);
#endif
#ifdef CJournalTextWnd__UpdateCategories
REVERSE_DETOUR(void  CJournalTextWnd::UpdateCategories(void),CJournalTextWnd__UpdateCategories);
#endif
#ifdef CJournalTextWnd__Activate
REVERSE_DETOUR(void  CJournalTextWnd::Activate(void),CJournalTextWnd__Activate);
#endif
#ifdef CJournalTextWnd__SetSearch
REVERSE_DETOUR(void  CJournalTextWnd::SetSearch(class CXStr),CJournalTextWnd__SetSearch);
#endif
#ifdef CJournalTextWnd__Clear
REVERSE_DETOUR(void  CJournalTextWnd::Clear(void),CJournalTextWnd__Clear);
#endif
#ifdef CJournalTextWnd__UpdateListWnd
REVERSE_DETOUR(void  CJournalTextWnd::UpdateListWnd(bool),CJournalTextWnd__UpdateListWnd);
#endif
#ifdef CJournalTextWnd__UpdateButtons
REVERSE_DETOUR(void  CJournalTextWnd::UpdateButtons(void),CJournalTextWnd__UpdateButtons);
#endif
#ifdef CJournalTextWnd__DisplayNPC
REVERSE_DETOUR(void  CJournalTextWnd::DisplayNPC(class JournalNPC *),CJournalTextWnd__DisplayNPC);
#endif
#ifdef CJournalTextWnd__BuildList
REVERSE_DETOUR(void  CJournalTextWnd::BuildList(void),CJournalTextWnd__BuildList);
#endif
#ifdef CJournalTextWnd__SelectEntryIndex
REVERSE_DETOUR(void  CJournalTextWnd::SelectEntryIndex(int),CJournalTextWnd__SelectEntryIndex);
#endif
#ifdef CJournalTextWnd__SortList
REVERSE_DETOUR(void  CJournalTextWnd::SortList(int,bool),CJournalTextWnd__SortList);
#endif
#ifdef CLoadskinWnd__CLoadskinWnd
REVERSE_DETOUR( CLoadskinWnd::CLoadskinWnd(class CXWnd *),CLoadskinWnd__CLoadskinWnd);
#endif
#ifdef CLoadskinWnd__UpdateSkinList
REVERSE_DETOUR(void  CLoadskinWnd::UpdateSkinList(void),CLoadskinWnd__UpdateSkinList);
#endif
#ifdef CLoadskinWnd__Activate
REVERSE_DETOUR(void  CLoadskinWnd::Activate(void),CLoadskinWnd__Activate);
#endif
#ifdef CLootWnd__CLootWnd
REVERSE_DETOUR( CLootWnd::CLootWnd(class CXWnd *),CLootWnd__CLootWnd);
#endif
#ifdef CLootWnd__Init
REVERSE_DETOUR(void  CLootWnd::Init(void),CLootWnd__Init);
#endif
#ifdef CLootWnd__Activate
REVERSE_DETOUR(void  CLootWnd::Activate(unsigned char,long,long,long,long),CLootWnd__Activate);
#endif
#ifdef CLootWnd__Deactivate1
REVERSE_DETOUR(void  CLootWnd::Deactivate(bool),CLootWnd__Deactivate1);
#endif
#ifdef CLootWnd__FinalizeLoot
REVERSE_DETOUR(void  CLootWnd::FinalizeLoot(void),CLootWnd__FinalizeLoot);
#endif
#ifdef CLootWnd__AddEquipmentToLootArray
REVERSE_DETOUR(void  CLootWnd::AddEquipmentToLootArray(class EQ_Item *),CLootWnd__AddEquipmentToLootArray);
#endif
#ifdef CLootWnd__AddNoteToLootArray
REVERSE_DETOUR(void  CLootWnd::AddNoteToLootArray(class EQ_Item *),CLootWnd__AddNoteToLootArray);
#endif
#ifdef CLootWnd__AddContainerToLootArray
REVERSE_DETOUR(void  CLootWnd::AddContainerToLootArray(class EQ_Item *),CLootWnd__AddContainerToLootArray);
#endif
#ifdef CLootWnd__RequestLootSlot
REVERSE_DETOUR(void  CLootWnd::RequestLootSlot(int,bool),CLootWnd__RequestLootSlot);
#endif
#ifdef CLootWnd__SlotLooted
REVERSE_DETOUR(void  CLootWnd::SlotLooted(int),CLootWnd__SlotLooted);
#endif
#ifdef CMapToolbarWnd__CMapToolbarWnd
REVERSE_DETOUR( CMapToolbarWnd::CMapToolbarWnd(class CXWnd *),CMapToolbarWnd__CMapToolbarWnd);
#endif
#ifdef CMapToolbarWnd__Activate
REVERSE_DETOUR(void  CMapToolbarWnd::Activate(void),CMapToolbarWnd__Activate);
#endif
#ifdef CMapToolbarWnd__SetAutoMapButton
REVERSE_DETOUR(void  CMapToolbarWnd::SetAutoMapButton(bool),CMapToolbarWnd__SetAutoMapButton);
#endif
#ifdef CEditLabelWnd__GetLabelText
REVERSE_DETOUR(class CXStr  CEditLabelWnd::GetLabelText(void),CEditLabelWnd__GetLabelText);
#endif
#ifdef CMapViewWnd__IsMappingEnabled
REVERSE_DETOUR(bool  CMapViewWnd::IsMappingEnabled(void),CMapViewWnd__IsMappingEnabled);
#endif
#ifdef CMapViewWnd__CMapViewWnd
REVERSE_DETOUR( CMapViewWnd::CMapViewWnd(class CXWnd *),CMapViewWnd__CMapViewWnd);
#endif
#ifdef CMapViewWnd__Init
REVERSE_DETOUR(void  CMapViewWnd::Init(void),CMapViewWnd__Init);
#endif
#ifdef CMapViewWnd__Activate
REVERSE_DETOUR(void  CMapViewWnd::Activate(void),CMapViewWnd__Activate);
#endif
#ifdef CMapViewWnd__ActivateAutoMapping
REVERSE_DETOUR(void  CMapViewWnd::ActivateAutoMapping(void),CMapViewWnd__ActivateAutoMapping);
#endif
#ifdef CMapViewWnd__DeactivateAutoMapping
REVERSE_DETOUR(void  CMapViewWnd::DeactivateAutoMapping(void),CMapViewWnd__DeactivateAutoMapping);
#endif
#ifdef CMapViewWnd__SetCurrentZone
//REVERSE_DETOUR(void  CMapViewWnd::SetCurrentZone(enum EQZoneIndex,struct T3D_XYZ *,struct T3D_XYZ *),CMapViewWnd__SetCurrentZone);
#endif
#ifdef MapViewMap__MapViewMap
REVERSE_DETOUR( MapViewMap::MapViewMap(void),MapViewMap__MapViewMap);
#endif
#ifdef MapViewMap__dMapViewMap
REVERSE_DETOUR( MapViewMap::~MapViewMap(void),MapViewMap__dMapViewMap);
#endif
#ifdef MapViewMap__Clear
REVERSE_DETOUR(void  MapViewMap::Clear(void),MapViewMap__Clear);
#endif
#ifdef MapViewMap__StartLine
REVERSE_DETOUR(void  MapViewMap::StartLine(float,float,float),MapViewMap__StartLine);
#endif
#ifdef MapViewMap__EndLine
REVERSE_DETOUR(void  MapViewMap::EndLine(float,float,float),MapViewMap__EndLine);
#endif
#ifdef MapViewMap__RemoveLine
REVERSE_DETOUR(void  MapViewMap::RemoveLine(void),MapViewMap__RemoveLine);
#endif
#ifdef MapViewMap__AddPoint
REVERSE_DETOUR(void  MapViewMap::AddPoint(float,float,float),MapViewMap__AddPoint);
#endif
#ifdef MapViewMap__AddLabel
REVERSE_DETOUR(void  MapViewMap::AddLabel(float,float,float,unsigned long,int,char *),MapViewMap__AddLabel);
#endif
#ifdef MapViewMap__RecalcLabelExtents
REVERSE_DETOUR(void  MapViewMap::RecalcLabelExtents(struct _mapviewlabel *),MapViewMap__RecalcLabelExtents);
#endif
#ifdef MapViewMap__RemoveLabel
REVERSE_DETOUR(void  MapViewMap::RemoveLabel(void),MapViewMap__RemoveLabel);
#endif
#ifdef MapViewMap__MoveLabel
REVERSE_DETOUR(void  MapViewMap::MoveLabel(struct _mapviewlabel *,float,float,float),MapViewMap__MoveLabel);
#endif
#ifdef MapViewMap__CalcLabelRenderOffsets
REVERSE_DETOUR(void  MapViewMap::CalcLabelRenderOffsets(class CXRect),MapViewMap__CalcLabelRenderOffsets);
#endif
#ifdef MapViewMap__IsLayerVisible
REVERSE_DETOUR(bool  MapViewMap::IsLayerVisible(int),MapViewMap__IsLayerVisible);
#endif
#ifdef MapViewMap__PointInMapViewArea
REVERSE_DETOUR(bool  MapViewMap::PointInMapViewArea(class CXPoint,class CXRect),MapViewMap__PointInMapViewArea);
#endif
#ifdef MapViewMap__PreCalcRenderValues
REVERSE_DETOUR(void  MapViewMap::PreCalcRenderValues(void),MapViewMap__PreCalcRenderValues);
#endif
#ifdef MapViewMap__TransformPoint
REVERSE_DETOUR(void  MapViewMap::TransformPoint(struct T3D_XYZ *),MapViewMap__TransformPoint);
#endif
#ifdef MapViewMap__Draw
REVERSE_DETOUR(void  MapViewMap::Draw(class CXRect),MapViewMap__Draw);
#endif
#ifdef MapViewMap__DrawClippedLine
REVERSE_DETOUR(bool  MapViewMap::DrawClippedLine(struct T3D_XYZ *,struct T3D_RGB,class CXRect),MapViewMap__DrawClippedLine);
#endif
#ifdef MapViewMap__Save
REVERSE_DETOUR(void  MapViewMap::Save(char *),MapViewMap__Save);
#endif
#ifdef MapViewMap__SaveEx
REVERSE_DETOUR(void  MapViewMap::SaveEx(char *,int),MapViewMap__SaveEx);
#endif
#ifdef MapViewMap__Load
REVERSE_DETOUR(void  MapViewMap::Load(char *),MapViewMap__Load);
#endif
#ifdef MapViewMap__LoadEx
REVERSE_DETOUR(bool  MapViewMap::LoadEx(char *,int),MapViewMap__LoadEx);
#endif
#ifdef MapViewMap__GetCurrentColor
REVERSE_DETOUR(unsigned long  MapViewMap::GetCurrentColor(void),MapViewMap__GetCurrentColor);
#endif
#ifdef MapViewMap__SetCurrentColor
REVERSE_DETOUR(void  MapViewMap::SetCurrentColor(unsigned long),MapViewMap__SetCurrentColor);
#endif
#ifdef MapViewMap__SetMarkedLine
REVERSE_DETOUR(void  MapViewMap::SetMarkedLine(struct _mapviewline *),MapViewMap__SetMarkedLine);
#endif
#ifdef MapViewMap__SetMarkedLineColor
REVERSE_DETOUR(void  MapViewMap::SetMarkedLineColor(unsigned long),MapViewMap__SetMarkedLineColor);
#endif
#ifdef MapViewMap__GetMarkedLineColor
REVERSE_DETOUR(unsigned long  MapViewMap::GetMarkedLineColor(void),MapViewMap__GetMarkedLineColor);
#endif
#ifdef MapViewMap__ClearActiveLayer
REVERSE_DETOUR(void  MapViewMap::ClearActiveLayer(void),MapViewMap__ClearActiveLayer);
#endif
#ifdef MapViewMap__RemoveLine1
REVERSE_DETOUR(void  MapViewMap::RemoveLine(struct _mapviewline *),MapViewMap__RemoveLine1);
#endif
#ifdef MapViewMap__RemoveLabel1
REVERSE_DETOUR(void  MapViewMap::RemoveLabel(struct _mapviewlabel *),MapViewMap__RemoveLabel1);
#endif
#ifdef CXRect__Normalize
REVERSE_DETOUR(void  CXRect::Normalize(void),CXRect__Normalize);
#endif
#ifdef CXRect__operator_and
REVERSE_DETOUR(class CXRect  CXRect::operator&(class CXRect)const ,CXRect__operator_and);
#endif
#ifdef MapViewMap__JoinLinesAtIntersect
REVERSE_DETOUR(void  MapViewMap::JoinLinesAtIntersect(bool),MapViewMap__JoinLinesAtIntersect);
#endif
#ifdef MapViewMap__SetZoneExtents
REVERSE_DETOUR(void  MapViewMap::SetZoneExtents(int,int,int,int),MapViewMap__SetZoneExtents);
#endif
#ifdef MapViewMap__SetZoom
REVERSE_DETOUR(void  MapViewMap::SetZoom(float),MapViewMap__SetZoom);
#endif
#ifdef MapViewMap__GetMinZ
REVERSE_DETOUR(int  MapViewMap::GetMinZ(void),MapViewMap__GetMinZ);
#endif
#ifdef MapViewMap__GetMaxZ
REVERSE_DETOUR(int  MapViewMap::GetMaxZ(void),MapViewMap__GetMaxZ);
#endif
#ifdef CMerchantWnd__CMerchantWnd
REVERSE_DETOUR( CMerchantWnd::CMerchantWnd(class CXWnd *),CMerchantWnd__CMerchantWnd);
#endif
#ifdef CMerchantWnd__Init
REVERSE_DETOUR(void  CMerchantWnd::Init(void),CMerchantWnd__Init);
#endif
#ifdef CMerchantWnd__Activate
REVERSE_DETOUR(void  CMerchantWnd::Activate(class EQPlayer *,float),CMerchantWnd__Activate);
#endif
#ifdef CMerchantWnd__HandleBuy
REVERSE_DETOUR(void  CMerchantWnd::HandleBuy(int),CMerchantWnd__HandleBuy);
#endif
#ifdef CMerchantWnd__HandleSell
REVERSE_DETOUR(void  CMerchantWnd::HandleSell(int),CMerchantWnd__HandleSell);
#endif
#ifdef CMerchantWnd__UpdateBuySellButtons
REVERSE_DETOUR(void  CMerchantWnd::UpdateBuySellButtons(void),CMerchantWnd__UpdateBuySellButtons);
#endif
#ifdef CMerchantWnd__SelectBuySellSlot
REVERSE_DETOUR(void  CMerchantWnd::SelectBuySellSlot(int,class CTextureAnimation *),CMerchantWnd__SelectBuySellSlot);
#endif
#ifdef CMerchantWnd__DisplayBuyOrSellPrice
REVERSE_DETOUR(void  CMerchantWnd::DisplayBuyOrSellPrice(bool,class EQ_Item *),CMerchantWnd__DisplayBuyOrSellPrice);
#endif
#ifdef CMerchantWnd__RequestBuyItem
REVERSE_DETOUR(void  CMerchantWnd::RequestBuyItem(int),CMerchantWnd__RequestBuyItem);
#endif
#ifdef CMerchantWnd__FinishBuyingItem
REVERSE_DETOUR(void  CMerchantWnd::FinishBuyingItem(struct _sell_msg *),CMerchantWnd__FinishBuyingItem);
#endif
#ifdef CMerchantWnd__RequestSellItem
REVERSE_DETOUR(void  CMerchantWnd::RequestSellItem(int),CMerchantWnd__RequestSellItem);
#endif
#ifdef CMerchantWnd__FinishSellingItem
REVERSE_DETOUR(void  CMerchantWnd::FinishSellingItem(struct _sell_msg *),CMerchantWnd__FinishSellingItem);
#endif
#ifdef CMerchantWnd__AddEquipmentToMercArray
REVERSE_DETOUR(void  CMerchantWnd::AddEquipmentToMercArray(class EQ_Equipment *),CMerchantWnd__AddEquipmentToMercArray);
#endif
#ifdef CMerchantWnd__AddNoteToMercArray
REVERSE_DETOUR(void  CMerchantWnd::AddNoteToMercArray(class EQ_Note *),CMerchantWnd__AddNoteToMercArray);
#endif
#ifdef CMerchantWnd__AddContainerToMercArray
REVERSE_DETOUR(void  CMerchantWnd::AddContainerToMercArray(class EQ_Container *),CMerchantWnd__AddContainerToMercArray);
#endif
#ifdef CMerchantWnd__ClearMerchantSlot
REVERSE_DETOUR(void  CMerchantWnd::ClearMerchantSlot(int),CMerchantWnd__ClearMerchantSlot);
#endif
#ifdef CMusicPlayerWnd__CMusicPlayerWnd
REVERSE_DETOUR( CMusicPlayerWnd::CMusicPlayerWnd(class CXWnd *),CMusicPlayerWnd__CMusicPlayerWnd);
#endif
#ifdef CMusicPlayerWnd__Activate
REVERSE_DETOUR(void  CMusicPlayerWnd::Activate(void),CMusicPlayerWnd__Activate);
#endif
#ifdef CMusicPlayerWnd__AutoStart
REVERSE_DETOUR(void  CMusicPlayerWnd::AutoStart(void),CMusicPlayerWnd__AutoStart);
#endif
#ifdef CMusicPlayerWnd__Update
REVERSE_DETOUR(void  CMusicPlayerWnd::Update(void),CMusicPlayerWnd__Update);
#endif
#ifdef CMusicPlayerWnd__UpdateButtons
REVERSE_DETOUR(void  CMusicPlayerWnd::UpdateButtons(void),CMusicPlayerWnd__UpdateButtons);
#endif
#ifdef CNoteWnd__CNoteWnd
REVERSE_DETOUR( CNoteWnd::CNoteWnd(class CXWnd *),CNoteWnd__CNoteWnd);
#endif
#ifdef CNoteWnd__Activate
REVERSE_DETOUR(void  CNoteWnd::Activate(void),CNoteWnd__Activate);
#endif
#ifdef CNoteWnd__CheckNote
REVERSE_DETOUR(bool  CNoteWnd::CheckNote(class EQ_Note *),CNoteWnd__CheckNote);
#endif
#ifdef CNoteWnd__SetNote
REVERSE_DETOUR(void  CNoteWnd::SetNote(char *),CNoteWnd__SetNote);
#endif
#ifdef CXStr__operator_lb_rb
REVERSE_DETOUR(char  CXStr::operator[](int)const ,CXStr__operator_lb_rb);
#endif
#ifdef COptionsWnd__COptionsWnd
REVERSE_DETOUR( COptionsWnd::COptionsWnd(class CXWnd *),COptionsWnd__COptionsWnd);
#endif
#ifdef COptionsWnd__SyncGeneralPage
REVERSE_DETOUR(void  COptionsWnd::SyncGeneralPage(void),COptionsWnd__SyncGeneralPage);
#endif
#ifdef COptionsWnd__SyncDisplayPage
REVERSE_DETOUR(void  COptionsWnd::SyncDisplayPage(void),COptionsWnd__SyncDisplayPage);
#endif
#ifdef COptionsWnd__SyncMousePage
REVERSE_DETOUR(void  COptionsWnd::SyncMousePage(void),COptionsWnd__SyncMousePage);
#endif
#ifdef COptionsWnd__SyncChatPage
REVERSE_DETOUR(void  COptionsWnd::SyncChatPage(void),COptionsWnd__SyncChatPage);
#endif
#ifdef COptionsWnd__SyncColorPage
REVERSE_DETOUR(void  COptionsWnd::SyncColorPage(void),COptionsWnd__SyncColorPage);
#endif
#ifdef COptionsWnd__InitKeyboardPage
REVERSE_DETOUR(void  COptionsWnd::InitKeyboardPage(void),COptionsWnd__InitKeyboardPage);
#endif
#ifdef COptionsWnd__InitKeyboardAssignments
REVERSE_DETOUR(void  COptionsWnd::InitKeyboardAssignments(void),COptionsWnd__InitKeyboardAssignments);
#endif
#ifdef COptionsWnd__RefreshCurrentKeyboardAssignmentList
REVERSE_DETOUR(void  COptionsWnd::RefreshCurrentKeyboardAssignmentList(void),COptionsWnd__RefreshCurrentKeyboardAssignmentList);
#endif
#ifdef COptionsWnd__AddKeyboardAssignment
REVERSE_DETOUR(void  COptionsWnd::AddKeyboardAssignment(int,int,int),COptionsWnd__AddKeyboardAssignment);
#endif
#ifdef COptionsWnd__Activate
REVERSE_DETOUR(void  COptionsWnd::Activate(void),COptionsWnd__Activate);
#endif
#ifdef COptionsWnd__ResetKeysToDefault
REVERSE_DETOUR(void  COptionsWnd::ResetKeysToDefault(void),COptionsWnd__ResetKeysToDefault);
#endif
#ifdef COptionsWnd__RedirectOnProcessFrameTo
REVERSE_DETOUR(int  COptionsWnd::RedirectOnProcessFrameTo(class CPageWnd *),COptionsWnd__RedirectOnProcessFrameTo);
#endif
#ifdef COptionsWnd__RedirectWndNotificationTo
REVERSE_DETOUR(int  COptionsWnd::RedirectWndNotificationTo(class CPageWnd *,class CXWnd *,unsigned __int32,void *),COptionsWnd__RedirectWndNotificationTo);
#endif
#ifdef COptionsWnd__RedirectHandleKeyboardMsgTo
REVERSE_DETOUR(int  COptionsWnd::RedirectHandleKeyboardMsgTo(class CPageWnd *,unsigned __int32,unsigned __int32,bool),COptionsWnd__RedirectHandleKeyboardMsgTo);
#endif
#ifdef COptionsWnd__RedirectDeactivateTo
REVERSE_DETOUR(int  COptionsWnd::RedirectDeactivateTo(class CPageWnd *),COptionsWnd__RedirectDeactivateTo);
#endif
#ifdef COptionsWnd__GeneralPageOnProcessFrame
REVERSE_DETOUR(int  COptionsWnd::GeneralPageOnProcessFrame(void),COptionsWnd__GeneralPageOnProcessFrame);
#endif
#ifdef COptionsWnd__GeneralPageWndNotification
REVERSE_DETOUR(int  COptionsWnd::GeneralPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__GeneralPageWndNotification);
#endif
#ifdef COptionsWnd__DisplayPageOnProcessFrame
REVERSE_DETOUR(int  COptionsWnd::DisplayPageOnProcessFrame(void),COptionsWnd__DisplayPageOnProcessFrame);
#endif
#ifdef COptionsWnd__DisplayPageWndNotification
REVERSE_DETOUR(int  COptionsWnd::DisplayPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__DisplayPageWndNotification);
#endif
#ifdef COptionsWnd__MousePageOnProcessFrame
REVERSE_DETOUR(int  COptionsWnd::MousePageOnProcessFrame(void),COptionsWnd__MousePageOnProcessFrame);
#endif
#ifdef COptionsWnd__MousePageWndNotification
REVERSE_DETOUR(int  COptionsWnd::MousePageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__MousePageWndNotification);
#endif
#ifdef COptionsWnd__KeyboardPageWndNotification
REVERSE_DETOUR(int  COptionsWnd::KeyboardPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__KeyboardPageWndNotification);
#endif
#ifdef COptionsWnd__KeyboardPageHandleKeyboardMsg
REVERSE_DETOUR(int  COptionsWnd::KeyboardPageHandleKeyboardMsg(unsigned __int32,unsigned __int32,bool),COptionsWnd__KeyboardPageHandleKeyboardMsg);
#endif
#ifdef COptionsWnd__KeyboardPageDeactivate
REVERSE_DETOUR(int  COptionsWnd::KeyboardPageDeactivate(void),COptionsWnd__KeyboardPageDeactivate);
#endif
#ifdef COptionsWnd__KeyboardPageCancelKeypressAssignment
REVERSE_DETOUR(void  COptionsWnd::KeyboardPageCancelKeypressAssignment(void),COptionsWnd__KeyboardPageCancelKeypressAssignment);
#endif
#ifdef COptionsWnd__ChatPageOnProcessFrame
REVERSE_DETOUR(int  COptionsWnd::ChatPageOnProcessFrame(void),COptionsWnd__ChatPageOnProcessFrame);
#endif
#ifdef COptionsWnd__ColorPageOnProcessFrame
REVERSE_DETOUR(int  COptionsWnd::ColorPageOnProcessFrame(void),COptionsWnd__ColorPageOnProcessFrame);
#endif
#ifdef COptionsWnd__ChatPageWndNotification
REVERSE_DETOUR(int  COptionsWnd::ChatPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__ChatPageWndNotification);
#endif
#ifdef COptionsWnd__ColorPageWndNotification
REVERSE_DETOUR(int  COptionsWnd::ColorPageWndNotification(class CXWnd *,unsigned __int32,void *),COptionsWnd__ColorPageWndNotification);
#endif
#ifdef COptionsWnd__SaveColors
REVERSE_DETOUR(void  COptionsWnd::SaveColors(int,int,int,int),COptionsWnd__SaveColors);
#endif
#ifdef COptionsWnd__RestoreDefaultColors
REVERSE_DETOUR(void  COptionsWnd::RestoreDefaultColors(void),COptionsWnd__RestoreDefaultColors);
#endif
#ifdef COptionsWnd__SetBagOptions
REVERSE_DETOUR(void  COptionsWnd::SetBagOptions(int,int),COptionsWnd__SetBagOptions);
#endif
#ifdef CPetInfoWnd__CPetInfoWnd
REVERSE_DETOUR( CPetInfoWnd::CPetInfoWnd(class CXWnd *),CPetInfoWnd__CPetInfoWnd);
#endif
#ifdef CPetInfoWnd__Activate
REVERSE_DETOUR(void  CPetInfoWnd::Activate(void),CPetInfoWnd__Activate);
#endif
#ifdef CPetInfoWnd__SetShowOnSummon
REVERSE_DETOUR(void  CPetInfoWnd::SetShowOnSummon(bool),CPetInfoWnd__SetShowOnSummon);
#endif
#ifdef CPetInfoWnd__Update
REVERSE_DETOUR(void  CPetInfoWnd::Update(void),CPetInfoWnd__Update);
#endif
#ifdef CPetInfoWnd__GetButton
REVERSE_DETOUR(class CButtonWnd *  CPetInfoWnd::GetButton(int),CPetInfoWnd__GetButton);
#endif
#ifdef CPetitionQWnd__CPetitionQWnd
REVERSE_DETOUR( CPetitionQWnd::CPetitionQWnd(class CXWnd *),CPetitionQWnd__CPetitionQWnd);
#endif
#ifdef CPetitionQWnd__UpdatePetitions
REVERSE_DETOUR(void  CPetitionQWnd::UpdatePetitions(void),CPetitionQWnd__UpdatePetitions);
#endif
#ifdef CPetitionQWnd__Activate
REVERSE_DETOUR(void  CPetitionQWnd::Activate(void),CPetitionQWnd__Activate);
#endif
#ifdef CPetitionQWnd__SetPriorityDisplay
REVERSE_DETOUR(void  CPetitionQWnd::SetPriorityDisplay(void),CPetitionQWnd__SetPriorityDisplay);
#endif
#ifdef CPetitionQWnd__AddGMText
REVERSE_DETOUR(void  CPetitionQWnd::AddGMText(void),CPetitionQWnd__AddGMText);
#endif
#ifdef CPetitionQWnd__CheckedOut
REVERSE_DETOUR(void  CPetitionQWnd::CheckedOut(struct petitionQtype const *,int),CPetitionQWnd__CheckedOut);
#endif
#ifdef CPetitionQWnd__UndoCheckout
REVERSE_DETOUR(void  CPetitionQWnd::UndoCheckout(void),CPetitionQWnd__UndoCheckout);
#endif
#ifdef CPetitionQWnd__ClearCurrentPet
REVERSE_DETOUR(void  CPetitionQWnd::ClearCurrentPet(void),CPetitionQWnd__ClearCurrentPet);
#endif
#ifdef CPetitionQWnd__FillFields
REVERSE_DETOUR(void  CPetitionQWnd::FillFields(void),CPetitionQWnd__FillFields);
#endif
#ifdef CPetitionQWnd__SetButtonsForPetition
REVERSE_DETOUR(void  CPetitionQWnd::SetButtonsForPetition(bool,bool),CPetitionQWnd__SetButtonsForPetition);
#endif
#ifdef CPetitionQWnd__LogPetitionText
REVERSE_DETOUR(void  CPetitionQWnd::LogPetitionText(void),CPetitionQWnd__LogPetitionText);
#endif
#ifdef CPetitionQWnd__GetCurrentPetitionersName
REVERSE_DETOUR(char *  CPetitionQWnd::GetCurrentPetitionersName(void),CPetitionQWnd__GetCurrentPetitionersName);
#endif
#ifdef CPlayerNotesWnd__CPlayerNotesWnd
REVERSE_DETOUR( CPlayerNotesWnd::CPlayerNotesWnd(class CXWnd *),CPlayerNotesWnd__CPlayerNotesWnd);
#endif
#ifdef CPlayerNotesWnd__Activate
REVERSE_DETOUR(void  CPlayerNotesWnd::Activate(void),CPlayerNotesWnd__Activate);
#endif
#ifdef CPlayerNotesWnd__SaveNotes
REVERSE_DETOUR(void  CPlayerNotesWnd::SaveNotes(void),CPlayerNotesWnd__SaveNotes);
#endif
#ifdef CPlayerNotesWnd__AppendText
REVERSE_DETOUR(void  CPlayerNotesWnd::AppendText(char *),CPlayerNotesWnd__AppendText);
#endif
#ifdef CPlayerWnd__CPlayerWnd
REVERSE_DETOUR( CPlayerWnd::CPlayerWnd(class CXWnd *),CPlayerWnd__CPlayerWnd);
#endif
#ifdef CPlayerWnd__Init
REVERSE_DETOUR(void  CPlayerWnd::Init(void),CPlayerWnd__Init);
#endif
#ifdef CPlayerWnd__Activate
REVERSE_DETOUR(void  CPlayerWnd::Activate(void),CPlayerWnd__Activate);
#endif
#ifdef CPlayerWnd__CreateLocalMenu
REVERSE_DETOUR(void  CPlayerWnd::CreateLocalMenu(void),CPlayerWnd__CreateLocalMenu);
#endif
#ifdef CPlayerWnd__UpdateContextMenu
REVERSE_DETOUR(void  CPlayerWnd::UpdateContextMenu(void),CPlayerWnd__UpdateContextMenu);
#endif
#ifdef CQuantityWnd__CQuantityWnd
REVERSE_DETOUR( CQuantityWnd::CQuantityWnd(class CXWnd *),CQuantityWnd__CQuantityWnd);
#endif
#ifdef CQuantityWnd__Activate
REVERSE_DETOUR(void  CQuantityWnd::Activate(class CXWnd *,int,int,int,int,bool),CQuantityWnd__Activate);
#endif
#ifdef CQuantityWnd__CheckMaxEditWnd
REVERSE_DETOUR(void  CQuantityWnd::CheckMaxEditWnd(void),CQuantityWnd__CheckMaxEditWnd);
#endif
#ifdef CQuantityWnd__UpdateEditWndFromSlider
REVERSE_DETOUR(void  CQuantityWnd::UpdateEditWndFromSlider(void),CQuantityWnd__UpdateEditWndFromSlider);
#endif
#ifdef CQuantityWnd__UpdateSliderFromEditWnd
REVERSE_DETOUR(void  CQuantityWnd::UpdateSliderFromEditWnd(void),CQuantityWnd__UpdateSliderFromEditWnd);
#endif
#ifdef CRaidOptionsWnd__CRaidOptionsWnd
REVERSE_DETOUR( CRaidOptionsWnd::CRaidOptionsWnd(class CXWnd *),CRaidOptionsWnd__CRaidOptionsWnd);
#endif
#ifdef CRaidOptionsWnd__Init
REVERSE_DETOUR(void  CRaidOptionsWnd::Init(void),CRaidOptionsWnd__Init);
#endif
#ifdef CRaidOptionsWnd__Activate
REVERSE_DETOUR(void  CRaidOptionsWnd::Activate(void),CRaidOptionsWnd__Activate);
#endif
#ifdef CRaidOptionsWnd__AddLooterToList
REVERSE_DETOUR(void  CRaidOptionsWnd::AddLooterToList(char *),CRaidOptionsWnd__AddLooterToList);
#endif
#ifdef CRaidOptionsWnd__ClearLooterList
REVERSE_DETOUR(void  CRaidOptionsWnd::ClearLooterList(void),CRaidOptionsWnd__ClearLooterList);
#endif
#ifdef CRaidOptionsWnd__UpdateComponents
REVERSE_DETOUR(void  CRaidOptionsWnd::UpdateComponents(void),CRaidOptionsWnd__UpdateComponents);
#endif
#ifdef CRaidOptionsWnd__InitializeClassColors
REVERSE_DETOUR(void  CRaidOptionsWnd::InitializeClassColors(void),CRaidOptionsWnd__InitializeClassColors);
#endif
#ifdef CRaidWnd__CRaidWnd
REVERSE_DETOUR( CRaidWnd::CRaidWnd(class CXWnd *),CRaidWnd__CRaidWnd);
#endif
#ifdef CRaidWnd__Init
REVERSE_DETOUR(void  CRaidWnd::Init(void),CRaidWnd__Init);
#endif
#ifdef CRaidWnd__Activate
REVERSE_DETOUR(void  CRaidWnd::Activate(void),CRaidWnd__Activate);
#endif
#ifdef CRaidWnd__AddPlayertoList
REVERSE_DETOUR(void  CRaidWnd::AddPlayertoList(char *,char *,char *,char *,int,int,bool),CRaidWnd__AddPlayertoList);
#endif
#ifdef CRaidWnd__RemovePlayerFromList
REVERSE_DETOUR(void  CRaidWnd::RemovePlayerFromList(char *,int),CRaidWnd__RemovePlayerFromList);
#endif
#ifdef CRaidWnd__SetRaidCount
REVERSE_DETOUR(void  CRaidWnd::SetRaidCount(int),CRaidWnd__SetRaidCount);
#endif
#ifdef CRaidWnd__ClearPlayerList
REVERSE_DETOUR(void  CRaidWnd::ClearPlayerList(void),CRaidWnd__ClearPlayerList);
#endif
#ifdef CRaidWnd__AddSeparator
REVERSE_DETOUR(void  CRaidWnd::AddSeparator(void),CRaidWnd__AddSeparator);
#endif
#ifdef CRaidWnd__SetRaidMemberRank
REVERSE_DETOUR(void  CRaidWnd::SetRaidMemberRank(char *,char *,int),CRaidWnd__SetRaidMemberRank);
#endif
#ifdef CRaidWnd__ChangePosition
REVERSE_DETOUR(void  CRaidWnd::ChangePosition(char *,int,int,int,bool),CRaidWnd__ChangePosition);
#endif
#ifdef CRaidWnd__ChangeRaidGroupLeader
REVERSE_DETOUR(void  CRaidWnd::ChangeRaidGroupLeader(char *,int,char *),CRaidWnd__ChangeRaidGroupLeader);
#endif
#ifdef CRaidWnd__UpdateMemberName
REVERSE_DETOUR(void  CRaidWnd::UpdateMemberName(char *,char *,int),CRaidWnd__UpdateMemberName);
#endif
#ifdef CRaidWnd__SetRaidTarget
REVERSE_DETOUR(void  CRaidWnd::SetRaidTarget(char *,int,char *,int),CRaidWnd__SetRaidTarget);
#endif
#ifdef CRaidWnd__UpdateLevelAverage
REVERSE_DETOUR(void  CRaidWnd::UpdateLevelAverage(int),CRaidWnd__UpdateLevelAverage);
#endif
#ifdef CRaidWnd__UpdateButtons
REVERSE_DETOUR(void  CRaidWnd::UpdateButtons(void),CRaidWnd__UpdateButtons);
#endif
#ifdef CRaidWnd__InitializeClassColors
REVERSE_DETOUR(void  CRaidWnd::InitializeClassColors(void),CRaidWnd__InitializeClassColors);
#endif
#ifdef CRaidWnd__SetPlayerClassColor
REVERSE_DETOUR(void  CRaidWnd::SetPlayerClassColor(int,int,int),CRaidWnd__SetPlayerClassColor);
#endif
#ifdef CRaidWnd__SetPlayerClassColor1
REVERSE_DETOUR(void  CRaidWnd::SetPlayerClassColor(char *,int,int),CRaidWnd__SetPlayerClassColor1);
#endif
#ifdef CRaidWnd__SetClassColor
REVERSE_DETOUR(void  CRaidWnd::SetClassColor(int,unsigned long),CRaidWnd__SetClassColor);
#endif
#ifdef CRaidWnd__ResortRaidGroupList
REVERSE_DETOUR(void  CRaidWnd::ResortRaidGroupList(int,int),CRaidWnd__ResortRaidGroupList);
#endif
#ifdef CRaidWnd__FindOpenIndexInGroup
REVERSE_DETOUR(int  CRaidWnd::FindOpenIndexInGroup(int),CRaidWnd__FindOpenIndexInGroup);
#endif
#ifdef CRaidWnd__FindIndexNotInGroupList
REVERSE_DETOUR(int  CRaidWnd::FindIndexNotInGroupList(char *),CRaidWnd__FindIndexNotInGroupList);
#endif
#ifdef CRaidWnd__FindPlayerIndexInGroup
REVERSE_DETOUR(int  CRaidWnd::FindPlayerIndexInGroup(char *,int),CRaidWnd__FindPlayerIndexInGroup);
#endif
#ifdef CSelectorWnd__CSelectorWnd
REVERSE_DETOUR( CSelectorWnd::CSelectorWnd(class CXWnd *),CSelectorWnd__CSelectorWnd);
#endif
#ifdef CSelectorWnd__Activate
REVERSE_DETOUR(void  CSelectorWnd::Activate(void),CSelectorWnd__Activate);
#endif
#ifdef CSelectorWnd__KeyMapUpdated
REVERSE_DETOUR(void  CSelectorWnd::KeyMapUpdated(void),CSelectorWnd__KeyMapUpdated);
#endif
#ifdef CSkillsSelectWnd__CSkillsSelectWnd
REVERSE_DETOUR( CSkillsSelectWnd::CSkillsSelectWnd(class CXWnd *),CSkillsSelectWnd__CSkillsSelectWnd);
#endif
#ifdef CSkillsSelectWnd__Refresh
REVERSE_DETOUR(void  CSkillsSelectWnd::Refresh(void),CSkillsSelectWnd__Refresh);
#endif
#ifdef CSkillsSelectWnd__UpdateAll
REVERSE_DETOUR(void  CSkillsSelectWnd::UpdateAll(void),CSkillsSelectWnd__UpdateAll);
#endif
#ifdef CSkillsSelectWnd__UpdateSkill
REVERSE_DETOUR(void  CSkillsSelectWnd::UpdateSkill(int),CSkillsSelectWnd__UpdateSkill);
#endif
#ifdef CSkillsSelectWnd__SetTypesToDisplay
REVERSE_DETOUR(void  CSkillsSelectWnd::SetTypesToDisplay(int),CSkillsSelectWnd__SetTypesToDisplay);
#endif
#ifdef CSkillsWnd__CSkillsWnd
REVERSE_DETOUR( CSkillsWnd::CSkillsWnd(class CXWnd *),CSkillsWnd__CSkillsWnd);
#endif
#ifdef CSkillsWnd__Activate
REVERSE_DETOUR(void  CSkillsWnd::Activate(void),CSkillsWnd__Activate);
#endif
#ifdef CSkillsWnd__SkillImproveOccurred
REVERSE_DETOUR(void  CSkillsWnd::SkillImproveOccurred(int),CSkillsWnd__SkillImproveOccurred);
#endif
#ifdef CSkillsWnd__UpdateAll
REVERSE_DETOUR(void  CSkillsWnd::UpdateAll(void),CSkillsWnd__UpdateAll);
#endif
#ifdef CSkillsWnd__UpdateSkill
REVERSE_DETOUR(void  CSkillsWnd::UpdateSkill(int),CSkillsWnd__UpdateSkill);
#endif
#ifdef CSocialEditWnd__CSocialEditWnd
REVERSE_DETOUR( CSocialEditWnd::CSocialEditWnd(class CXWnd *),CSocialEditWnd__CSocialEditWnd);
#endif
#ifdef CSocialEditWnd__Init
REVERSE_DETOUR(void  CSocialEditWnd::Init(void),CSocialEditWnd__Init);
#endif
#ifdef CSocialEditWnd__Activate
REVERSE_DETOUR(void  CSocialEditWnd::Activate(int),CSocialEditWnd__Activate);
#endif
#ifdef CSocialEditWnd__ClickedAccept
REVERSE_DETOUR(void  CSocialEditWnd::ClickedAccept(void),CSocialEditWnd__ClickedAccept);
#endif
#ifdef CSocialEditWnd__ClickedClear
REVERSE_DETOUR(void  CSocialEditWnd::ClickedClear(void),CSocialEditWnd__ClickedClear);
#endif
#ifdef CSocialEditWnd__ClickedTextColorButton
REVERSE_DETOUR(void  CSocialEditWnd::ClickedTextColorButton(int),CSocialEditWnd__ClickedTextColorButton);
#endif
#ifdef CSocialEditWnd__GetSocialTextColor
REVERSE_DETOUR(unsigned long  CSocialEditWnd::GetSocialTextColor(int),CSocialEditWnd__GetSocialTextColor);
#endif
#ifdef CSocialEditWnd__UpdateControlsFromSocial
REVERSE_DETOUR(void  CSocialEditWnd::UpdateControlsFromSocial(void),CSocialEditWnd__UpdateControlsFromSocial);
#endif
#ifdef CSoulmarkWnd__CSoulmarkWnd
REVERSE_DETOUR( CSoulmarkWnd::CSoulmarkWnd(class CXWnd *),CSoulmarkWnd__CSoulmarkWnd);
#endif
#ifdef CSoulmarkWnd__UpdateSoulmarks
REVERSE_DETOUR(void  CSoulmarkWnd::UpdateSoulmarks(struct soulMarkMsg *),CSoulmarkWnd__UpdateSoulmarks);
#endif
#ifdef CSoulmarkWnd__UpdateList
REVERSE_DETOUR(void  CSoulmarkWnd::UpdateList(void),CSoulmarkWnd__UpdateList);
#endif
#ifdef CSoulmarkWnd__Activate
REVERSE_DETOUR(void  CSoulmarkWnd::Activate(void),CSoulmarkWnd__Activate);
#endif
#ifdef CSoulmarkWnd__Activate1
REVERSE_DETOUR(void  CSoulmarkWnd::Activate(char *,char *),CSoulmarkWnd__Activate1);
#endif
#ifdef CSoulmarkWnd__SaveMarks
REVERSE_DETOUR(void  CSoulmarkWnd::SaveMarks(void),CSoulmarkWnd__SaveMarks);
#endif
#ifdef CSoulmarkWnd__FillFields
REVERSE_DETOUR(void  CSoulmarkWnd::FillFields(void),CSoulmarkWnd__FillFields);
#endif
#ifdef CSoulmarkWnd__Clear
REVERSE_DETOUR(void  CSoulmarkWnd::Clear(void),CSoulmarkWnd__Clear);
#endif
#ifdef CSoulmarkWnd__Inquire
REVERSE_DETOUR(void  CSoulmarkWnd::Inquire(char *,char *),CSoulmarkWnd__Inquire);
#endif
#ifdef CSoulmarkWnd__AddMark
REVERSE_DETOUR(void  CSoulmarkWnd::AddMark(int,char *,char *,char *),CSoulmarkWnd__AddMark);
#endif
#ifdef CSoulmarkWnd__Inquire1
REVERSE_DETOUR(void  CSoulmarkWnd::Inquire(char *),CSoulmarkWnd__Inquire1);
#endif
#ifdef CSoulmarkWnd__Praise
REVERSE_DETOUR(void  CSoulmarkWnd::Praise(char *),CSoulmarkWnd__Praise);
#endif
#ifdef CSoulmarkWnd__Warn
REVERSE_DETOUR(void  CSoulmarkWnd::Warn(char *),CSoulmarkWnd__Warn);
#endif
#ifdef CSpellBookWnd__CSpellBookWnd
REVERSE_DETOUR( CSpellBookWnd::CSpellBookWnd(class CXWnd *),CSpellBookWnd__CSpellBookWnd);
#endif
#ifdef CSpellBookWnd__Init
REVERSE_DETOUR(void  CSpellBookWnd::Init(void),CSpellBookWnd__Init);
#endif
#ifdef CSpellBookWnd__Activate
REVERSE_DETOUR(void  CSpellBookWnd::Activate(void),CSpellBookWnd__Activate);
#endif
#ifdef CSpellBookWnd__GetBookSlot
REVERSE_DETOUR(int __cdecl CSpellBookWnd::GetBookSlot(int),CSpellBookWnd__GetBookSlot);
#endif
#ifdef CSpellBookWnd__MemorizeSet
REVERSE_DETOUR(void  CSpellBookWnd::MemorizeSet(int *,int),CSpellBookWnd__MemorizeSet);
#endif
#ifdef CSpellBookWnd__ContinueSetMem
REVERSE_DETOUR(void  CSpellBookWnd::ContinueSetMem(void),CSpellBookWnd__ContinueSetMem);
#endif
#ifdef CSpellBookWnd__DelayedSpellMem
REVERSE_DETOUR(void  CSpellBookWnd::DelayedSpellMem(int,int,int),CSpellBookWnd__DelayedSpellMem);
#endif
#ifdef CSpellBookWnd__EndSetMem
REVERSE_DETOUR(void  CSpellBookWnd::EndSetMem(void),CSpellBookWnd__EndSetMem);
#endif
#ifdef CSpellBookWnd__AutoMemSpell
REVERSE_DETOUR(void  CSpellBookWnd::AutoMemSpell(int,int),CSpellBookWnd__AutoMemSpell);
#endif
#ifdef CSpellBookWnd__HandleLeftClickOnSpell
REVERSE_DETOUR(void  CSpellBookWnd::HandleLeftClickOnSpell(int),CSpellBookWnd__HandleLeftClickOnSpell);
#endif
#ifdef CSpellBookWnd__HandleRightClickOnSpell
REVERSE_DETOUR(void  CSpellBookWnd::HandleRightClickOnSpell(int),CSpellBookWnd__HandleRightClickOnSpell);
#endif
#ifdef CSpellBookWnd__CanStartMemming
REVERSE_DETOUR(bool  CSpellBookWnd::CanStartMemming(int),CSpellBookWnd__CanStartMemming);
#endif
#ifdef CSpellBookWnd__StartSpellMemorizationDrag
REVERSE_DETOUR(void  CSpellBookWnd::StartSpellMemorizationDrag(int,class CButtonWnd *),CSpellBookWnd__StartSpellMemorizationDrag);
#endif
#ifdef CSpellBookWnd__StartSpellMemorization
REVERSE_DETOUR(bool  CSpellBookWnd::StartSpellMemorization(int,int,bool),CSpellBookWnd__StartSpellMemorization);
#endif
#ifdef CSpellBookWnd__FinishMemorizing
REVERSE_DETOUR(void  CSpellBookWnd::FinishMemorizing(int,int),CSpellBookWnd__FinishMemorizing);
#endif
#ifdef CSpellBookWnd__GetSpellMemTicksLeft
REVERSE_DETOUR(int  CSpellBookWnd::GetSpellMemTicksLeft(void),CSpellBookWnd__GetSpellMemTicksLeft);
#endif
#ifdef CSpellBookWnd__StartSpellScribe
REVERSE_DETOUR(void  CSpellBookWnd::StartSpellScribe(int),CSpellBookWnd__StartSpellScribe);
#endif
#ifdef CSpellBookWnd__FinishScribing
REVERSE_DETOUR(void  CSpellBookWnd::FinishScribing(int,int),CSpellBookWnd__FinishScribing);
#endif
#ifdef CSpellBookWnd__GetSpellScribeTicksLeft
REVERSE_DETOUR(int  CSpellBookWnd::GetSpellScribeTicksLeft(void),CSpellBookWnd__GetSpellScribeTicksLeft);
#endif
#ifdef CSpellBookWnd__SwapSpellBookSlots
REVERSE_DETOUR(void  CSpellBookWnd::SwapSpellBookSlots(int,int),CSpellBookWnd__SwapSpellBookSlots);
#endif
#ifdef CSpellBookWnd__HandleSpellInfoDisplay
REVERSE_DETOUR(void  CSpellBookWnd::HandleSpellInfoDisplay(class CXWnd *),CSpellBookWnd__HandleSpellInfoDisplay);
#endif
#ifdef CSpellBookWnd__DisplaySpellInfo
REVERSE_DETOUR(void  CSpellBookWnd::DisplaySpellInfo(int),CSpellBookWnd__DisplaySpellInfo);
#endif
#ifdef CSpellBookWnd__TurnToPage
REVERSE_DETOUR(void  CSpellBookWnd::TurnToPage(int),CSpellBookWnd__TurnToPage);
#endif
#ifdef CSpellBookWnd__UpdateSpellBookDisplay
REVERSE_DETOUR(void  CSpellBookWnd::UpdateSpellBookDisplay(void),CSpellBookWnd__UpdateSpellBookDisplay);
#endif
#ifdef CSpellBookWnd__StopSpellBookAction
REVERSE_DETOUR(void  CSpellBookWnd::StopSpellBookAction(void),CSpellBookWnd__StopSpellBookAction);
#endif
#ifdef CSpellBookWnd__GetSpellDeletionConfirmation
REVERSE_DETOUR(void  CSpellBookWnd::GetSpellDeletionConfirmation(int),CSpellBookWnd__GetSpellDeletionConfirmation);
#endif
#ifdef CSpellBookWnd__RequestSpellDeletion
REVERSE_DETOUR(void  CSpellBookWnd::RequestSpellDeletion(int),CSpellBookWnd__RequestSpellDeletion);
#endif
#ifdef CSpellBookWnd__DeleteSpellFromBook
REVERSE_DETOUR(void  CSpellBookWnd::DeleteSpellFromBook(int,int),CSpellBookWnd__DeleteSpellFromBook);
#endif
#ifdef CXStr__Mid
REVERSE_DETOUR(class CXStr  CXStr::Mid(int,int)const ,CXStr__Mid);
#endif
#ifdef CTargetWnd__CTargetWnd
REVERSE_DETOUR( CTargetWnd::CTargetWnd(class CXWnd *),CTargetWnd__CTargetWnd);
#endif
#ifdef CTargetWnd__Activate
REVERSE_DETOUR(void  CTargetWnd::Activate(void),CTargetWnd__Activate);
#endif
#ifdef CTextEntryWnd__CTextEntryWnd
REVERSE_DETOUR( CTextEntryWnd::CTextEntryWnd(class CXWnd *),CTextEntryWnd__CTextEntryWnd);
#endif
#ifdef CTextEntryWnd__Activate
REVERSE_DETOUR(void  CTextEntryWnd::Activate(class CXWnd *,int,char *,int,int,char *),CTextEntryWnd__Activate);
#endif
#ifdef CTextEntryWnd__Callback
REVERSE_DETOUR(void  CTextEntryWnd::Callback(bool),CTextEntryWnd__Callback);
#endif
#ifdef CTextEntryWnd__UpdateButtons
REVERSE_DETOUR(void  CTextEntryWnd::UpdateButtons(void),CTextEntryWnd__UpdateButtons);
#endif
#ifdef CTextEntryWnd__GetEntryText
REVERSE_DETOUR(class CXStr  CTextEntryWnd::GetEntryText(void),CTextEntryWnd__GetEntryText);
#endif
#ifdef CTimeLeftWnd__CTimeLeftWnd
REVERSE_DETOUR( CTimeLeftWnd::CTimeLeftWnd(long),CTimeLeftWnd__CTimeLeftWnd);
#endif
#ifdef CTimeLeftWnd__Activate
REVERSE_DETOUR(void  CTimeLeftWnd::Activate(void),CTimeLeftWnd__Activate);
#endif
#ifdef CTipWnd__CTipWnd
REVERSE_DETOUR( CTipWnd::CTipWnd(class CXWnd *,int),CTipWnd__CTipWnd);
#endif
#ifdef CTipWnd__Activate
REVERSE_DETOUR(bool  CTipWnd::Activate(int,bool),CTipWnd__Activate);
#endif
#ifdef CTipWnd__UpdateButtons
REVERSE_DETOUR(void  CTipWnd::UpdateButtons(void),CTipWnd__UpdateButtons);
#endif
#ifdef CTipWnd__InitializeTipSettings
REVERSE_DETOUR(void  CTipWnd::InitializeTipSettings(void),CTipWnd__InitializeTipSettings);
#endif
#ifdef CTipWnd__CleanDayTips
REVERSE_DETOUR(void  CTipWnd::CleanDayTips(void),CTipWnd__CleanDayTips);
#endif
#ifdef CTipWnd__SelectRandomTip
REVERSE_DETOUR(int  CTipWnd::SelectRandomTip(void),CTipWnd__SelectRandomTip);
#endif
#ifdef CTipWnd__SetTOTD
REVERSE_DETOUR(void  CTipWnd::SetTOTD(int),CTipWnd__SetTOTD);
#endif
#ifdef CTipWnd__IsRecentTOTD
REVERSE_DETOUR(bool  CTipWnd::IsRecentTOTD(int),CTipWnd__IsRecentTOTD);
#endif
#ifdef CTipWnd__AddContextTip
REVERSE_DETOUR(void  CTipWnd::AddContextTip(int),CTipWnd__AddContextTip);
#endif
#ifdef CTipWnd__ShowHistoryTip
REVERSE_DETOUR(void  CTipWnd::ShowHistoryTip(int),CTipWnd__ShowHistoryTip);
#endif
#ifdef CTipWnd__LoadINISettings
REVERSE_DETOUR(void  CTipWnd::LoadINISettings(void),CTipWnd__LoadINISettings);
#endif
#ifdef CTipWnd__LoadDayTips
REVERSE_DETOUR(void  CTipWnd::LoadDayTips(void),CTipWnd__LoadDayTips);
#endif
#ifdef CTrackingWnd__CTrackingWnd
REVERSE_DETOUR( CTrackingWnd::CTrackingWnd(class CXWnd *),CTrackingWnd__CTrackingWnd);
#endif
#ifdef CTrackingWnd__Init
REVERSE_DETOUR(void  CTrackingWnd::Init(void),CTrackingWnd__Init);
#endif
#ifdef CTrackingWnd__Activate
REVERSE_DETOUR(void  CTrackingWnd::Activate(void),CTrackingWnd__Activate);
#endif
#ifdef CTrackingWnd__NotifyServerOfTrackingTarget
REVERSE_DETOUR(void  CTrackingWnd::NotifyServerOfTrackingTarget(int),CTrackingWnd__NotifyServerOfTrackingTarget);
#endif
#ifdef CTrackingWnd__UpdateTrackingControls
REVERSE_DETOUR(void  CTrackingWnd::UpdateTrackingControls(void),CTrackingWnd__UpdateTrackingControls);
#endif
#ifdef CTrackingWnd__GetTrackColor
REVERSE_DETOUR(unsigned long  CTrackingWnd::GetTrackColor(int),CTrackingWnd__GetTrackColor);
#endif
#ifdef CTrackingWnd__UpdateTrackingList
REVERSE_DETOUR(void  CTrackingWnd::UpdateTrackingList(bool),CTrackingWnd__UpdateTrackingList);
#endif
#ifdef CTrackingWnd__GenerateTrackingList
REVERSE_DETOUR(void  CTrackingWnd::GenerateTrackingList(void),CTrackingWnd__GenerateTrackingList);
#endif
#ifdef CTrackingWnd__SetTrackingList
REVERSE_DETOUR(void  CTrackingWnd::SetTrackingList(struct TrackingHit *,int),CTrackingWnd__SetTrackingList);
#endif
#ifdef CTrackingWnd__DoTrackSort
REVERSE_DETOUR(void  CTrackingWnd::DoTrackSort(bool),CTrackingWnd__DoTrackSort);
#endif
#ifdef CTrackingWnd__DoTrackFilter
REVERSE_DETOUR(void  CTrackingWnd::DoTrackFilter(bool),CTrackingWnd__DoTrackFilter);
#endif
#ifdef CTrackingWnd__RemovePlayerFromTracking
REVERSE_DETOUR(void  CTrackingWnd::RemovePlayerFromTracking(class EQPlayer *),CTrackingWnd__RemovePlayerFromTracking);
#endif
#ifdef CTrackingWnd__RemovePlayerFromTracking1
REVERSE_DETOUR(void  CTrackingWnd::RemovePlayerFromTracking(int),CTrackingWnd__RemovePlayerFromTracking1);
#endif
#ifdef CTrackingWnd__RemoveFromListWndByData
REVERSE_DETOUR(void  CTrackingWnd::RemoveFromListWndByData(unsigned int),CTrackingWnd__RemoveFromListWndByData);
#endif
#ifdef CTrackingWnd__GetListIdByData
REVERSE_DETOUR(int  CTrackingWnd::GetListIdByData(unsigned int),CTrackingWnd__GetListIdByData);
#endif
#ifdef CTradeWnd__CTradeWnd
REVERSE_DETOUR( CTradeWnd::CTradeWnd(class CXWnd *),CTradeWnd__CTradeWnd);
#endif
#ifdef CTradeWnd__Init
REVERSE_DETOUR(void  CTradeWnd::Init(void),CTradeWnd__Init);
#endif
#ifdef CTradeWnd__Activate
REVERSE_DETOUR(void  CTradeWnd::Activate(class EQPlayer *,bool),CTradeWnd__Activate);
#endif
#ifdef CTradeWnd__ClickedCancelButton
REVERSE_DETOUR(void  CTradeWnd::ClickedCancelButton(void),CTradeWnd__ClickedCancelButton);
#endif
#ifdef CTradeWnd__ClickedTradeButton
REVERSE_DETOUR(void  CTradeWnd::ClickedTradeButton(void),CTradeWnd__ClickedTradeButton);
#endif
#ifdef CTradeWnd__ClickedMoneyButton
REVERSE_DETOUR(void  CTradeWnd::ClickedMoneyButton(int),CTradeWnd__ClickedMoneyButton);
#endif
#ifdef CTradeWnd__UpdateTradeDisplay
REVERSE_DETOUR(void  CTradeWnd::UpdateTradeDisplay(void),CTradeWnd__UpdateTradeDisplay);
#endif
#ifdef CTradeWnd__IsMyTradeSlot
REVERSE_DETOUR(bool  CTradeWnd::IsMyTradeSlot(int,bool *),CTradeWnd__IsMyTradeSlot);
#endif
#ifdef CTradeWnd__TradeItemChanged
REVERSE_DETOUR(void  CTradeWnd::TradeItemChanged(int,int),CTradeWnd__TradeItemChanged);
#endif
#ifdef CTradeWnd__CompleteTrade
REVERSE_DETOUR(void  CTradeWnd::CompleteTrade(void),CTradeWnd__CompleteTrade);
#endif
#ifdef CTradeWnd__AddEquipmentToHisTradeArray
REVERSE_DETOUR(void  CTradeWnd::AddEquipmentToHisTradeArray(class EQ_Equipment *),CTradeWnd__AddEquipmentToHisTradeArray);
#endif
#ifdef CTradeWnd__AddNoteToHisTradeArray
REVERSE_DETOUR(void  CTradeWnd::AddNoteToHisTradeArray(class EQ_Note *),CTradeWnd__AddNoteToHisTradeArray);
#endif
#ifdef CTradeWnd__AddContainerToHisTradeArray
REVERSE_DETOUR(void  CTradeWnd::AddContainerToHisTradeArray(class EQ_Container *),CTradeWnd__AddContainerToHisTradeArray);
#endif
#ifdef CTradeWnd__DeleteItemFromHisTradeArray
REVERSE_DETOUR(void  CTradeWnd::DeleteItemFromHisTradeArray(int),CTradeWnd__DeleteItemFromHisTradeArray);
#endif
#ifdef CTradeWnd__DropItemIntoTrade
REVERSE_DETOUR(void  CTradeWnd::DropItemIntoTrade(void),CTradeWnd__DropItemIntoTrade);
#endif
#ifdef CTradeWnd__DropMoneyIntoTrade
//REVERSE_DETOUR(CTradeWnd::DropMoneyIntoTrade(void),CTradeWnd__DropMoneyIntoTrade);
#endif
#ifdef CTradeWnd__SetMyReadyTrade
REVERSE_DETOUR(void  CTradeWnd::SetMyReadyTrade(bool),CTradeWnd__SetMyReadyTrade);
#endif
#ifdef CTradeWnd__SetHisReadyTrade
REVERSE_DETOUR(void  CTradeWnd::SetHisReadyTrade(bool),CTradeWnd__SetHisReadyTrade);
#endif
#ifdef CTradeWnd__SetHisMoney
REVERSE_DETOUR(void  CTradeWnd::SetHisMoney(int,long),CTradeWnd__SetHisMoney);
#endif
#ifdef CTrainWnd__CTrainWnd
REVERSE_DETOUR( CTrainWnd::CTrainWnd(class CXWnd *),CTrainWnd__CTrainWnd);
#endif
#ifdef CTrainWnd__Activate
REVERSE_DETOUR(void  CTrainWnd::Activate(void),CTrainWnd__Activate);
#endif
#ifdef CTrainWnd__UpdateRight
REVERSE_DETOUR(void  CTrainWnd::UpdateRight(void),CTrainWnd__UpdateRight);
#endif
#ifdef CTrainWnd__UpdateAll
REVERSE_DETOUR(void  CTrainWnd::UpdateAll(bool),CTrainWnd__UpdateAll);
#endif
#ifdef CTrainWnd__SkillName
REVERSE_DETOUR(char *  CTrainWnd::SkillName(int),CTrainWnd__SkillName);
#endif
#ifdef CTrainWnd__SkillValue
REVERSE_DETOUR(int  CTrainWnd::SkillValue(int),CTrainWnd__SkillValue);
#endif
#ifdef CTrainWnd__SwapSkill
REVERSE_DETOUR(void  CTrainWnd::SwapSkill(int,int),CTrainWnd__SwapSkill);
#endif
#ifdef CTrainWnd__SortNames
REVERSE_DETOUR(void  CTrainWnd::SortNames(int),CTrainWnd__SortNames);
#endif
#ifdef CTrainWnd__SortSkill
REVERSE_DETOUR(void  CTrainWnd::SortSkill(int),CTrainWnd__SortSkill);
#endif
#ifdef CTrainWnd__UpdateSkill
REVERSE_DETOUR(void  CTrainWnd::UpdateSkill(int),CTrainWnd__UpdateSkill);
#endif
#ifdef CTrainWnd__SkillChanged
REVERSE_DETOUR(void  CTrainWnd::SkillChanged(int),CTrainWnd__SkillChanged);
#endif
#ifdef CTrainWnd__SetGMData
REVERSE_DETOUR(void  CTrainWnd::SetGMData(int *,unsigned char *,float),CTrainWnd__SetGMData);
#endif
#ifdef CTrainWnd__Train
REVERSE_DETOUR(void  CTrainWnd::Train(void),CTrainWnd__Train);
#endif
#ifdef CVideoModesWnd__CVideoModesWnd
REVERSE_DETOUR( CVideoModesWnd::CVideoModesWnd(class CXWnd *),CVideoModesWnd__CVideoModesWnd);
#endif
#ifdef CVideoModesWnd__Init
REVERSE_DETOUR(void  CVideoModesWnd::Init(void),CVideoModesWnd__Init);
#endif
#ifdef CVideoModesWnd__Update
REVERSE_DETOUR(void  CVideoModesWnd::Update(void),CVideoModesWnd__Update);
#endif
#ifdef CVideoModesWnd__UpdateSelection
REVERSE_DETOUR(void  CVideoModesWnd::UpdateSelection(unsigned int),CVideoModesWnd__UpdateSelection);
#endif
#ifdef CVideoModesWnd__RestoreOldMode
REVERSE_DETOUR(void  CVideoModesWnd::RestoreOldMode(void),CVideoModesWnd__RestoreOldMode);
#endif
#ifdef CGuild__CGuild
REVERSE_DETOUR( CGuild::CGuild(void),CGuild__CGuild);
#endif
#ifdef CGuild__GetGuildName
REVERSE_DETOUR(char *  CGuild::GetGuildName(int),CGuild__GetGuildName);
#endif
#ifdef CGuild__ValidGuildName
REVERSE_DETOUR(bool  CGuild::ValidGuildName(int),CGuild__ValidGuildName);
#endif
#ifdef CGuild__GetGuildIndex
REVERSE_DETOUR(int  CGuild::GetGuildIndex(char *),CGuild__GetGuildIndex);
#endif
#ifdef CGuild__SendPublicCommentChange
REVERSE_DETOUR(void  CGuild::SendPublicCommentChange(char *,char *),CGuild__SendPublicCommentChange);
#endif
#ifdef CGuild__DemoteMember
REVERSE_DETOUR(void  CGuild::DemoteMember(class GuildMember *),CGuild__DemoteMember);
#endif
#ifdef CGuild__SetGuildMotd
REVERSE_DETOUR(void  CGuild::SetGuildMotd(struct guildmotdSet *),CGuild__SetGuildMotd);
#endif
#ifdef CGuild__HandleGuildMessage
REVERSE_DETOUR(void  CGuild::HandleGuildMessage(struct connection_t *,unsigned __int32,char *,unsigned __int32),CGuild__HandleGuildMessage);
#endif
#ifdef CGuild__InitializeFromDump
REVERSE_DETOUR(void  CGuild::InitializeFromDump(char *),CGuild__InitializeFromDump);
#endif
#ifdef CGuild__AddGuildMember
REVERSE_DETOUR(void  CGuild::AddGuildMember(class GuildMember *),CGuild__AddGuildMember);
#endif
#ifdef CGuild__DeleteAllMembers
REVERSE_DETOUR(void  CGuild::DeleteAllMembers(void),CGuild__DeleteAllMembers);
#endif
#ifdef CGuild__HandleGuildInvite
REVERSE_DETOUR(void  CGuild::HandleGuildInvite(struct connection_t *,unsigned __int32,char *,unsigned __int32),CGuild__HandleGuildInvite);
#endif
#ifdef CGuild__HandleAddGuildMember
REVERSE_DETOUR(void  CGuild::HandleAddGuildMember(char *,int),CGuild__HandleAddGuildMember);
#endif
#ifdef CGuild__HandleRemoveGuildMember
REVERSE_DETOUR(void  CGuild::HandleRemoveGuildMember(char *,int),CGuild__HandleRemoveGuildMember);
#endif
#ifdef CGuild__HandleDeleteGuildResponse
REVERSE_DETOUR(void  CGuild::HandleDeleteGuildResponse(char *),CGuild__HandleDeleteGuildResponse);
#endif
#ifdef CGuild__UpdatePublicComment
REVERSE_DETOUR(void  CGuild::UpdatePublicComment(char *),CGuild__UpdatePublicComment);
#endif
#ifdef CGuild__UpdateMemberStatus
REVERSE_DETOUR(void  CGuild::UpdateMemberStatus(char *),CGuild__UpdateMemberStatus);
#endif
#ifdef CGuild__HandleMemberLevelUpdate
REVERSE_DETOUR(void  CGuild::HandleMemberLevelUpdate(char *),CGuild__HandleMemberLevelUpdate);
#endif
#ifdef CGuild__UpdateGuildMemberOnWindow
REVERSE_DETOUR(void  CGuild::UpdateGuildMemberOnWindow(class GuildMember *),CGuild__UpdateGuildMemberOnWindow);
#endif
#ifdef CGuild__ChangeGuildMemberName
REVERSE_DETOUR(void  CGuild::ChangeGuildMemberName(char *),CGuild__ChangeGuildMemberName);
#endif
#ifdef CGuild__FindMemberByName
REVERSE_DETOUR(class GuildMember *  CGuild::FindMemberByName(char *),CGuild__FindMemberByName);
#endif
#ifdef GuildMember__GuildMember
REVERSE_DETOUR( GuildMember::GuildMember(void),GuildMember__GuildMember);
#endif
#ifdef ChannelServerApi__ChannelServerApi
REVERSE_DETOUR( ChannelServerApi::ChannelServerApi(char *,int,char *,char *,class ChannelServerHandler *,bool,bool,char *),ChannelServerApi__ChannelServerApi);
#endif
#ifdef ChannelServerApi__dChannelServerApi
REVERSE_DETOUR( ChannelServerApi::~ChannelServerApi(void),ChannelServerApi__dChannelServerApi);
#endif
#ifdef ChannelServerApi__FreeChannelList
REVERSE_DETOUR(void  ChannelServerApi::FreeChannelList(void),ChannelServerApi__FreeChannelList);
#endif
#ifdef ChannelServerApi__GetStatus
//REVERSE_DETOUR(enum ChannelServerApi::Status  ChannelServerApi::GetStatus(void),ChannelServerApi__GetStatus);
#endif
#ifdef ChannelServerApi__SendMessageA
REVERSE_DETOUR(void  ChannelServerApi::SendMessageA(char *),ChannelServerApi__SendMessageA);
#endif
#ifdef ChannelServerApi__SortBuddyList
REVERSE_DETOUR(void  ChannelServerApi::SortBuddyList(void),ChannelServerApi__SortBuddyList);
#endif
#ifdef UdpManager__Release
REVERSE_DETOUR(void  UdpManager::Release(void),UdpManager__Release);
#endif
#ifdef ChannelServerApi__SetBuddyStatus
//REVERSE_DETOUR(void  ChannelServerApi::SetBuddyStatus(char *,enum ChannelServerApi::BuddyStatus),ChannelServerApi__SetBuddyStatus);
#endif
#ifdef UdpConnection__Release
REVERSE_DETOUR(void  UdpConnection::Release(void),UdpConnection__Release);
#endif
#ifdef ChannelServerApi__GiveTime
REVERSE_DETOUR(void  ChannelServerApi::GiveTime(void),ChannelServerApi__GiveTime);
#endif
#ifdef ChannelServerApi__GetChannelNumber
REVERSE_DETOUR(int  ChannelServerApi::GetChannelNumber(char *),ChannelServerApi__GetChannelNumber);
#endif
#ifdef ChannelServerApi__GetChannelName
REVERSE_DETOUR(char *  ChannelServerApi::GetChannelName(int),ChannelServerApi__GetChannelName);
#endif
#ifdef ChannelServerApi__Strncpy
REVERSE_DETOUR(char * __cdecl ChannelServerApi::Strncpy(char *,char *,int),ChannelServerApi__Strncpy);
#endif
#ifdef ChannelServerApi__SmartResize
REVERSE_DETOUR(void * __cdecl ChannelServerApi::SmartResize(void *,int,int),ChannelServerApi__SmartResize);
#endif
#ifdef ChannelServerApi__GetNextField
REVERSE_DETOUR(int __cdecl ChannelServerApi::GetNextField(char *,int,char * *,char),ChannelServerApi__GetNextField);
#endif
#ifdef JournalNPC__JournalNPC
REVERSE_DETOUR( JournalNPC::JournalNPC(void),JournalNPC__JournalNPC);
#endif
#ifdef JournalNPC__dJournalNPC
REVERSE_DETOUR( JournalNPC::~JournalNPC(void),JournalNPC__dJournalNPC);
#endif
#ifdef JournalNPC__AllocateArray
REVERSE_DETOUR(void  JournalNPC::AllocateArray(void),JournalNPC__AllocateArray);
#endif
#ifdef JournalNPC__CleanEntries
REVERSE_DETOUR(void  JournalNPC::CleanEntries(void),JournalNPC__CleanEntries);
#endif
#ifdef JournalNPC__GetText
REVERSE_DETOUR(char * __cdecl JournalNPC::GetText(int),JournalNPC__GetText);
#endif
#ifdef JournalNPC__GetEntry
REVERSE_DETOUR(struct JournalEntry *  JournalNPC::GetEntry(int),JournalNPC__GetEntry);
#endif
#ifdef JournalNPC__FindEntryByHash
REVERSE_DETOUR(struct JournalEntry *  JournalNPC::FindEntryByHash(int),JournalNPC__FindEntryByHash);
#endif
#ifdef JournalNPC__FindEntryByCategory
REVERSE_DETOUR(struct JournalEntry *  JournalNPC::FindEntryByCategory(int,int),JournalNPC__FindEntryByCategory);
#endif
#ifdef JournalNPC__FindThisText
REVERSE_DETOUR(int  JournalNPC::FindThisText(char *,bool,int),JournalNPC__FindThisText);
#endif
#ifdef JournalNPC__AddEntry
REVERSE_DETOUR(int  JournalNPC::AddEntry(long,float,float,float,int,int),JournalNPC__AddEntry);
#endif
#ifdef JournalNPC__AddEntry1
REVERSE_DETOUR(int  JournalNPC::AddEntry(long,float,float,float,char *,int),JournalNPC__AddEntry1);
#endif
#ifdef JournalNPC__DeleteEntryByIndex
REVERSE_DETOUR(int  JournalNPC::DeleteEntryByIndex(int),JournalNPC__DeleteEntryByIndex);
#endif
#ifdef JournalNPC__DeleteEntryByHash
REVERSE_DETOUR(int  JournalNPC::DeleteEntryByHash(int),JournalNPC__DeleteEntryByHash);
#endif
#ifdef JournalNPC__ConvertCategory
REVERSE_DETOUR(void  JournalNPC::ConvertCategory(int,int),JournalNPC__ConvertCategory);
#endif
#ifdef JournalNPC__ComputeLatestTime
REVERSE_DETOUR(void  JournalNPC::ComputeLatestTime(void),JournalNPC__ComputeLatestTime);
#endif
#ifdef ConversationJournal__ConversationJournal
REVERSE_DETOUR( ConversationJournal::ConversationJournal(void),ConversationJournal__ConversationJournal);
#endif
#ifdef ConversationJournal__dConversationJournal
REVERSE_DETOUR( ConversationJournal::~ConversationJournal(void),ConversationJournal__dConversationJournal);
#endif
#ifdef ConversationJournal__Clean
REVERSE_DETOUR(void  ConversationJournal::Clean(void),ConversationJournal__Clean);
#endif
#ifdef ConversationJournal__AllocateNPCArray
REVERSE_DETOUR(void  ConversationJournal::AllocateNPCArray(void),ConversationJournal__AllocateNPCArray);
#endif
#ifdef ConversationJournal__AllocateCatArray
REVERSE_DETOUR(void  ConversationJournal::AllocateCatArray(void),ConversationJournal__AllocateCatArray);
#endif
#ifdef ConversationJournal__GetNPC
REVERSE_DETOUR(class JournalNPC *  ConversationJournal::GetNPC(int),ConversationJournal__GetNPC);
#endif
#ifdef ConversationJournal__FindNPCByNameZone
REVERSE_DETOUR(class JournalNPC *  ConversationJournal::FindNPCByNameZone(char *,int),ConversationJournal__FindNPCByNameZone);
#endif
#ifdef ConversationJournal__DeleteNPC
REVERSE_DETOUR(int  ConversationJournal::DeleteNPC(char *,int),ConversationJournal__DeleteNPC);
#endif
#ifdef ConversationJournal__AddNPC
REVERSE_DETOUR(class JournalNPC *  ConversationJournal::AddNPC(char *,int),ConversationJournal__AddNPC);
#endif
#ifdef ConversationJournal__AddEntry
REVERSE_DETOUR(int  ConversationJournal::AddEntry(char *,int,long,float,float,float,char *,int),ConversationJournal__AddEntry);
#endif
#ifdef ConversationJournal__AddCategory
REVERSE_DETOUR(struct JournalCategory *  ConversationJournal::AddCategory(int),ConversationJournal__AddCategory);
#endif
#ifdef ConversationJournal__FindFreeID
REVERSE_DETOUR(int  ConversationJournal::FindFreeID(void),ConversationJournal__FindFreeID);
#endif
#ifdef ConversationJournal__AddCategory1
REVERSE_DETOUR(struct JournalCategory *  ConversationJournal::AddCategory(char *,char *,int),ConversationJournal__AddCategory1);
#endif
#ifdef ConversationJournal__DeleteCategory
REVERSE_DETOUR(void  ConversationJournal::DeleteCategory(int),ConversationJournal__DeleteCategory);
#endif
#ifdef ConversationJournal__GetCategory
REVERSE_DETOUR(struct JournalCategory *  ConversationJournal::GetCategory(int),ConversationJournal__GetCategory);
#endif
#ifdef ConversationJournal__GetCategory1
REVERSE_DETOUR(struct JournalCategory *  ConversationJournal::GetCategory(char *),ConversationJournal__GetCategory1);
#endif
#ifdef ConversationJournal__GetCategoryList
REVERSE_DETOUR(struct JournalCategory * *  ConversationJournal::GetCategoryList(void),ConversationJournal__GetCategoryList);
#endif
#ifdef ConversationJournal__Save
REVERSE_DETOUR(int  ConversationJournal::Save(char *),ConversationJournal__Save);
#endif
#ifdef ConversationJournal__Load
REVERSE_DETOUR(int  ConversationJournal::Load(char *),ConversationJournal__Load);
#endif
#ifdef ConversationJournal__ReadCategory
REVERSE_DETOUR(void  ConversationJournal::ReadCategory(struct _iobuf *),ConversationJournal__ReadCategory);
#endif
#ifdef JournalNPC__ReadEntry
REVERSE_DETOUR(int  JournalNPC::ReadEntry(struct _iobuf *),JournalNPC__ReadEntry);
#endif
#ifdef ConversationJournal__ReadNPC
REVERSE_DETOUR(class JournalNPC *  ConversationJournal::ReadNPC(struct _iobuf *),ConversationJournal__ReadNPC);
#endif
#ifdef CRaid__CRaid
REVERSE_DETOUR( CRaid::CRaid(void),CRaid__CRaid);
#endif
#ifdef CRaid__HandleS2CRaidMessage
REVERSE_DETOUR(void  CRaid::HandleS2CRaidMessage(char *),CRaid__HandleS2CRaidMessage);
#endif
#ifdef CRaid__HandleC2SRaidMessage
REVERSE_DETOUR(void  CRaid::HandleC2SRaidMessage(char *),CRaid__HandleC2SRaidMessage);
#endif
#ifdef CRaid__IsInRaid
REVERSE_DETOUR(bool  CRaid::IsInRaid(void),CRaid__IsInRaid);
#endif
#ifdef CRaid__IsInvited
REVERSE_DETOUR(bool  CRaid::IsInvited(void),CRaid__IsInvited);
#endif
#ifdef CRaid__ClearInvitedState
REVERSE_DETOUR(void  CRaid::ClearInvitedState(void),CRaid__ClearInvitedState);
#endif
#ifdef CRaid__IsRaidLeader
REVERSE_DETOUR(bool  CRaid::IsRaidLeader(void),CRaid__IsRaidLeader);
#endif
#ifdef CRaid__IsRaidGroupLeader
REVERSE_DETOUR(bool  CRaid::IsRaidGroupLeader(void),CRaid__IsRaidGroupLeader);
#endif
#ifdef CRaid__SetTargetRaidPlayer
REVERSE_DETOUR(void  CRaid::SetTargetRaidPlayer(char *),CRaid__SetTargetRaidPlayer);
#endif
#ifdef CRaid__InitializeRaid
REVERSE_DETOUR(void  CRaid::InitializeRaid(char *),CRaid__InitializeRaid);
#endif
#ifdef CRaid__RaidCreated
REVERSE_DETOUR(void  CRaid::RaidCreated(struct CreateRaidMessage *),CRaid__RaidCreated);
#endif
#ifdef CRaid__AddRaidMember
REVERSE_DETOUR(void  CRaid::AddRaidMember(struct RaidAddMember *),CRaid__AddRaidMember);
#endif
#ifdef CRaid__DeleteRaidMember
REVERSE_DETOUR(void  CRaid::DeleteRaidMember(struct SCRaidMessage *),CRaid__DeleteRaidMember);
#endif
#ifdef CRaid__ChangeLeadership
REVERSE_DETOUR(void  CRaid::ChangeLeadership(char *),CRaid__ChangeLeadership);
#endif
#ifdef CRaid__RenameMember
REVERSE_DETOUR(void  CRaid::RenameMember(struct RenameRaidMember *),CRaid__RenameMember);
#endif
#ifdef CRaid__HandlePositionChange
REVERSE_DETOUR(void  CRaid::HandlePositionChange(struct SCRaidMessage *),CRaid__HandlePositionChange);
#endif
#ifdef CRaid__RaidGroupLeaderChange
REVERSE_DETOUR(void  CRaid::RaidGroupLeaderChange(struct SCRaidMessage *),CRaid__RaidGroupLeaderChange);
#endif
#ifdef CRaid__SetLootTypeResponse
REVERSE_DETOUR(void  CRaid::SetLootTypeResponse(struct SCRaidMessage *),CRaid__SetLootTypeResponse);
#endif
#ifdef CRaid__HandleSetLootType
REVERSE_DETOUR(void  CRaid::HandleSetLootType(int),CRaid__HandleSetLootType);
#endif
#ifdef CRaid__HandleAddLooter
REVERSE_DETOUR(void  CRaid::HandleAddLooter(char *),CRaid__HandleAddLooter);
#endif
#ifdef UdpMisc__GetValue32
REVERSE_DETOUR(unsigned int __cdecl UdpMisc::GetValue32(void const *),UdpMisc__GetValue32);
#endif
#ifdef Util__GetValue32
//REVERSE_DETOUR(unsigned int __cdecl Util::GetValue32(void const *),Util__GetValue32);
#endif
#ifdef CRaid__HandleRemoveLooter
REVERSE_DETOUR(void  CRaid::HandleRemoveLooter(char *),CRaid__HandleRemoveLooter);
#endif
#ifdef CRaid__CreateInviteRaid
REVERSE_DETOUR(void  CRaid::CreateInviteRaid(void),CRaid__CreateInviteRaid);
#endif
#ifdef CRaid__SendInviteResponse
REVERSE_DETOUR(void  CRaid::SendInviteResponse(bool),CRaid__SendInviteResponse);
#endif
#ifdef CRaid__SendLeadershipChange
REVERSE_DETOUR(void  CRaid::SendLeadershipChange(char *),CRaid__SendLeadershipChange);
#endif
#ifdef CRaid__RemoveRaidMember
REVERSE_DETOUR(void  CRaid::RemoveRaidMember(void),CRaid__RemoveRaidMember);
#endif
#ifdef CRaid__SetLootType
REVERSE_DETOUR(void  CRaid::SetLootType(char *),CRaid__SetLootType);
#endif
#ifdef CRaid__GetLootType
REVERSE_DETOUR(int  CRaid::GetLootType(void),CRaid__GetLootType);
#endif
#ifdef CRaid__AddRaidLooter
REVERSE_DETOUR(void  CRaid::AddRaidLooter(void),CRaid__AddRaidLooter);
#endif
#ifdef CRaid__RemoveRaidLooter
REVERSE_DETOUR(void  CRaid::RemoveRaidLooter(void),CRaid__RemoveRaidLooter);
#endif
#ifdef CRaid__SendRaidChat
REVERSE_DETOUR(void  CRaid::SendRaidChat(char *),CRaid__SendRaidChat);
#endif
#ifdef CRaid__ResetWindow
REVERSE_DETOUR(void  CRaid::ResetWindow(void),CRaid__ResetWindow);
#endif
#ifdef CRaid__UpdateClassColor
REVERSE_DETOUR(void  CRaid::UpdateClassColor(int,unsigned long),CRaid__UpdateClassColor);
#endif
#ifdef CRaid__HandleCreateInviteRaid
REVERSE_DETOUR(void  CRaid::HandleCreateInviteRaid(struct CSRaidMessage *),CRaid__HandleCreateInviteRaid);
#endif
#ifdef CRaid__GetNumRaidMembers
REVERSE_DETOUR(int  CRaid::GetNumRaidMembers(void),CRaid__GetNumRaidMembers);
#endif
#ifdef CRaid__GetRaidMemberAt
REVERSE_DETOUR(struct RaidMember *  CRaid::GetRaidMemberAt(int),CRaid__GetRaidMemberAt);
#endif
#ifdef CRaid__SetRaidLeader
REVERSE_DETOUR(void  CRaid::SetRaidLeader(char *),CRaid__SetRaidLeader);
#endif
#ifdef CRaid__FindPlayerIndex
REVERSE_DETOUR(int  CRaid::FindPlayerIndex(char *),CRaid__FindPlayerIndex);
#endif
#ifdef CRaid__IsRaidMember
REVERSE_DETOUR(bool  CRaid::IsRaidMember(char *),CRaid__IsRaidMember);
#endif
#ifdef CRaid__FindOpenIndex
REVERSE_DETOUR(int  CRaid::FindOpenIndex(void),CRaid__FindOpenIndex);
#endif
#ifdef CRaid__FindRaidGroupLeader
REVERSE_DETOUR(int  CRaid::FindRaidGroupLeader(int),CRaid__FindRaidGroupLeader);
#endif
#ifdef CRaid__ResetRaid
REVERSE_DETOUR(void  CRaid::ResetRaid(void),CRaid__ResetRaid);
#endif
#ifdef CRaid__DetermineRaidChanges
REVERSE_DETOUR(void  CRaid::DetermineRaidChanges(char *),CRaid__DetermineRaidChanges);
#endif
#ifdef CRaid__SendRaidMsg
REVERSE_DETOUR(void  CRaid::SendRaidMsg(int,char *,char *,int),CRaid__SendRaidMsg);
#endif
#ifdef CRaid__UpdateOptionsWindow
REVERSE_DETOUR(void  CRaid::UpdateOptionsWindow(void),CRaid__UpdateOptionsWindow);
#endif
#ifdef CRaid__IsRaidLooter
REVERSE_DETOUR(bool  CRaid::IsRaidLooter(char *),CRaid__IsRaidLooter);
#endif
#ifdef CRaid__UpdateLevelAverage
REVERSE_DETOUR(void  CRaid::UpdateLevelAverage(void),CRaid__UpdateLevelAverage);
#endif
#ifdef CDisplay__CDisplay
REVERSE_DETOUR( CDisplay::CDisplay(struct HWND__ *),CDisplay__CDisplay);
#endif
#ifdef CDisplay__dCDisplay
REVERSE_DETOUR( CDisplay::~CDisplay(void),CDisplay__dCDisplay);
#endif
#ifdef CDisplay__ResetRenderWindow
REVERSE_DETOUR(void  CDisplay::ResetRenderWindow(void),CDisplay__ResetRenderWindow);
#endif
#ifdef CDisplay__SetCCreateCamera
REVERSE_DETOUR(void  CDisplay::SetCCreateCamera(int),CDisplay__SetCCreateCamera);
#endif
#ifdef CDisplay__SetBoneSpriteTint
REVERSE_DETOUR(int  CDisplay::SetBoneSpriteTint(struct T3D_DAG *,struct T3D_RGB *),CDisplay__SetBoneSpriteTint);
#endif
#ifdef CDisplay__ReplaceMaterial
REVERSE_DETOUR(int  CDisplay::ReplaceMaterial(char *,char *,struct T3D_HIERARCHICALSPRITEINSTANCE *,struct T3D_RGB *,int),CDisplay__ReplaceMaterial);
#endif
#ifdef CDisplay__ReplaceCloakMaterials
REVERSE_DETOUR(int  CDisplay::ReplaceCloakMaterials(int,struct T3D_HIERARCHICALSPRITEINSTANCE *,struct T3D_RGB *),CDisplay__ReplaceCloakMaterials);
#endif
#ifdef CDisplay__InitEverQuestLocale
//REVERSE_DETOUR(void  CDisplay::InitEverQuestLocale(enum EQLocalize::languages),CDisplay__InitEverQuestLocale);
#endif
#ifdef CDisplay__ReloadUI
REVERSE_DETOUR(void  CDisplay::ReloadUI(bool),CDisplay__ReloadUI);
#endif
#ifdef CDisplay__HandleMaterial
REVERSE_DETOUR(void  CDisplay::HandleMaterial(class EQ_PC *,int,class EQ_Item *,class EQ_Item *),CDisplay__HandleMaterial);
#endif
#ifdef CDisplay__FixHeading
REVERSE_DETOUR(float  CDisplay::FixHeading(float),CDisplay__FixHeading);
#endif
#ifdef CDisplay__HeadingDiff
REVERSE_DETOUR(float  CDisplay::HeadingDiff(float,float,float *),CDisplay__HeadingDiff);
#endif
#ifdef CDisplay__DeleteParticleCloudInstance
REVERSE_DETOUR(void  CDisplay::DeleteParticleCloudInstance(struct T3D_PARTICLECLOUDINSTANCE * *),CDisplay__DeleteParticleCloudInstance);
#endif
#ifdef CDisplay__ProcessParticleEmitter
REVERSE_DETOUR(void  CDisplay::ProcessParticleEmitter(class EQSwitch *),CDisplay__ProcessParticleEmitter);
#endif
#ifdef CDisplay__SlideSwitchLeftRight
REVERSE_DETOUR(bool  CDisplay::SlideSwitchLeftRight(class EQSwitch *,float,int,float),CDisplay__SlideSwitchLeftRight);
#endif
#ifdef CDisplay__ProcessSwitches
REVERSE_DETOUR(void  CDisplay::ProcessSwitches(void),CDisplay__ProcessSwitches);
#endif
#ifdef CDisplay__default_cameras
REVERSE_DETOUR(void  CDisplay::default_cameras(void),CDisplay__default_cameras);
#endif
#ifdef CDisplay__is_3dON
REVERSE_DETOUR(int  CDisplay::is_3dON(void),CDisplay__is_3dON);
#endif
#ifdef CDisplay__is_ParticleSystemON
REVERSE_DETOUR(int  CDisplay::is_ParticleSystemON(void),CDisplay__is_ParticleSystemON);
#endif
#ifdef CDisplay__InitCommonLights
REVERSE_DETOUR(void  CDisplay::InitCommonLights(void),CDisplay__InitCommonLights);
#endif
#ifdef CDisplay__GetNewPCIniFlag
REVERSE_DETOUR(int  CDisplay::GetNewPCIniFlag(int,int),CDisplay__GetNewPCIniFlag);
#endif
#ifdef CDisplay__ShouldLoadNewPcModel
REVERSE_DETOUR(int  CDisplay::ShouldLoadNewPcModel(int,int),CDisplay__ShouldLoadNewPcModel);
#endif
#ifdef CDisplay__GetIniRaceName
REVERSE_DETOUR(char *  CDisplay::GetIniRaceName(int),CDisplay__GetIniRaceName);
#endif
#ifdef CDisplay__InitWorld
REVERSE_DETOUR(void  CDisplay::InitWorld(void),CDisplay__InitWorld);
#endif
#ifdef CDisplay__InitDDraw
REVERSE_DETOUR(void  CDisplay::InitDDraw(void),CDisplay__InitDDraw);
#endif
#ifdef CDisplay__InitNewUI
REVERSE_DETOUR(void  CDisplay::InitNewUI(void),CDisplay__InitNewUI);
#endif
#ifdef CXWndDrawTemplate__operator_equal
REVERSE_DETOUR(class CXWndDrawTemplate &  CXWndDrawTemplate::operator=(class CXWndDrawTemplate const &),CXWndDrawTemplate__operator_equal);
#endif
#ifdef CButtonDrawTemplate__operator_equal
REVERSE_DETOUR(class CButtonDrawTemplate &  CButtonDrawTemplate::operator=(class CButtonDrawTemplate const &),CButtonDrawTemplate__operator_equal);
#endif
#ifdef CScrollbarTemplate__operator_equal
REVERSE_DETOUR(class CScrollbarTemplate &  CScrollbarTemplate::operator=(class CScrollbarTemplate const &),CScrollbarTemplate__operator_equal);
#endif
#ifdef CTAFrameDraw__operator_equal
REVERSE_DETOUR(class CTAFrameDraw &  CTAFrameDraw::operator=(class CTAFrameDraw const &),CTAFrameDraw__operator_equal);
#endif
#ifdef CDisplay__InitCharSelectUI
REVERSE_DETOUR(void  CDisplay::InitCharSelectUI(void),CDisplay__InitCharSelectUI);
#endif
#ifdef CDisplay__InitGameUI
REVERSE_DETOUR(void  CDisplay::InitGameUI(void),CDisplay__InitGameUI);
#endif
#ifdef CDisplay__CleanCharSelectUI
REVERSE_DETOUR(void  CDisplay::CleanCharSelectUI(void),CDisplay__CleanCharSelectUI);
#endif
#ifdef CDisplay__CleanGameUI
REVERSE_DETOUR(void  CDisplay::CleanGameUI(void),CDisplay__CleanGameUI);
#endif
#ifdef CDisplay__CleanUpNewUI
REVERSE_DETOUR(void  CDisplay::CleanUpNewUI(void),CDisplay__CleanUpNewUI);
#endif
#ifdef CDisplay__ActivateMainUI
REVERSE_DETOUR(void  CDisplay::ActivateMainUI(bool),CDisplay__ActivateMainUI);
#endif
#ifdef CDisplay__DeactivateMainUI
REVERSE_DETOUR(void  CDisplay::DeactivateMainUI(void),CDisplay__DeactivateMainUI);
#endif
#ifdef CDisplay__NewUIProcessEscape
REVERSE_DETOUR(void  CDisplay::NewUIProcessEscape(void),CDisplay__NewUIProcessEscape);
#endif
#ifdef CDisplay__KeyMapUpdated
REVERSE_DETOUR(void  CDisplay::KeyMapUpdated(void),CDisplay__KeyMapUpdated);
#endif
#ifdef CDisplay__GetWorldFilePath
REVERSE_DETOUR(bool const  CDisplay::GetWorldFilePath(char *,char const *),CDisplay__GetWorldFilePath);
#endif
#ifdef CDisplay__LoadWorldFile
REVERSE_DETOUR(unsigned char  CDisplay::LoadWorldFile(char *,char *,int,unsigned char),CDisplay__LoadWorldFile);
#endif
#ifdef CDisplay__LoadNPCFromS3D
REVERSE_DETOUR(unsigned char  CDisplay::LoadNPCFromS3D(char *,char *,char *),CDisplay__LoadNPCFromS3D);
#endif
#ifdef CDisplay__LoadBMPFile
REVERSE_DETOUR(unsigned char  CDisplay::LoadBMPFile(void),CDisplay__LoadBMPFile);
#endif
#ifdef CDisplay__StartWorldDisplay
//REVERSE_DETOUR(void  CDisplay::StartWorldDisplay(enum EQZoneIndex),CDisplay__StartWorldDisplay);
#endif
#ifdef CDisplay__StartWorldDisplay_Bailout
REVERSE_DETOUR(void  CDisplay::StartWorldDisplay_Bailout(char const *),CDisplay__StartWorldDisplay_Bailout);
#endif
#ifdef CDisplay__StopWorldDisplay
REVERSE_DETOUR(void  CDisplay::StopWorldDisplay(void),CDisplay__StopWorldDisplay);
#endif
#ifdef CDisplay__SetGammaCorrection
REVERSE_DETOUR(void  CDisplay::SetGammaCorrection(float),CDisplay__SetGammaCorrection);
#endif
#ifdef CDisplay__SetPCloudDensity
REVERSE_DETOUR(void  CDisplay::SetPCloudDensity(int),CDisplay__SetPCloudDensity);
#endif
#ifdef CDisplay__CleanUpDDraw
REVERSE_DETOUR(void  CDisplay::CleanUpDDraw(void),CDisplay__CleanUpDDraw);
#endif
#ifdef CDisplay__IsShield
REVERSE_DETOUR(unsigned int  CDisplay::IsShield(int)const ,CDisplay__IsShield);
#endif
#ifdef CDisplay__GetItemType
REVERSE_DETOUR(int  CDisplay::GetItemType(int),CDisplay__GetItemType);
#endif
#ifdef CDisplay__GetUserDefinedColor
REVERSE_DETOUR(unsigned long __cdecl CDisplay::GetUserDefinedColor(int),CDisplay__GetUserDefinedColor);
#endif
#ifdef CDisplay__SetUserDefinedColor
REVERSE_DETOUR(void __cdecl CDisplay::SetUserDefinedColor(int,int,int,int),CDisplay__SetUserDefinedColor);
#endif
#ifdef CDisplay__InitUserDefinedColors
REVERSE_DETOUR(void  CDisplay::InitUserDefinedColors(void),CDisplay__InitUserDefinedColors);
#endif
#ifdef CDisplay__WriteTextHD2
REVERSE_DETOUR(int __cdecl CDisplay::WriteTextHD2(char const *,int,int,int),CDisplay__WriteTextHD2);
#endif
#ifdef CXWndManager__GetDisplayWidth
REVERSE_DETOUR(unsigned __int32  CXWndManager::GetDisplayWidth(void)const ,CXWndManager__GetDisplayWidth);
#endif
#ifdef CXWndManager__GetFont
REVERSE_DETOUR(class CTextureFont *  CXWndManager::GetFont(int)const ,CXWndManager__GetFont);
#endif
#ifdef CDisplay__SetActorScaleFactor
REVERSE_DETOUR(void  CDisplay::SetActorScaleFactor(struct T3D_tagACTORINSTANCE *,float,unsigned char),CDisplay__SetActorScaleFactor);
#endif
#ifdef CDisplay__ShowDisplay
REVERSE_DETOUR(void  CDisplay::ShowDisplay(void),CDisplay__ShowDisplay);
#endif
#ifdef CDisplay__CheckForScreenModeToggle
REVERSE_DETOUR(void  CDisplay::CheckForScreenModeToggle(void),CDisplay__CheckForScreenModeToggle);
#endif
#ifdef CDisplay__Render_World
REVERSE_DETOUR(void  CDisplay::Render_World(void),CDisplay__Render_World);
#endif
#ifdef CDisplay__SetSpecialEnvironment
//REVERSE_DETOUR(void  CDisplay::SetSpecialEnvironment(enum EnvironmentType),CDisplay__SetSpecialEnvironment);
#endif
#ifdef CDisplay__SetGenericEnvironment
REVERSE_DETOUR(void  CDisplay::SetGenericEnvironment(void),CDisplay__SetGenericEnvironment);
#endif
#ifdef CDisplay__SetupEmitterEnvironment
REVERSE_DETOUR(void  CDisplay::SetupEmitterEnvironment(void),CDisplay__SetupEmitterEnvironment);
#endif
#ifdef CDisplay__UpdateMobileEmitterLocations
REVERSE_DETOUR(void  CDisplay::UpdateMobileEmitterLocations(void),CDisplay__UpdateMobileEmitterLocations);
#endif
#ifdef CDisplay__RealRender_World
REVERSE_DETOUR(void  CDisplay::RealRender_World(void),CDisplay__RealRender_World);
#endif
#ifdef CDisplay__Render_MinWorld
REVERSE_DETOUR(void  CDisplay::Render_MinWorld(void),CDisplay__Render_MinWorld);
#endif
#ifdef CDisplay__StartWeather
REVERSE_DETOUR(void  CDisplay::StartWeather(int,unsigned char),CDisplay__StartWeather);
#endif
#ifdef CDisplay__ProcessWeather
REVERSE_DETOUR(void  CDisplay::ProcessWeather(void),CDisplay__ProcessWeather);
#endif
#ifdef CDisplay__StopWeather
REVERSE_DETOUR(void  CDisplay::StopWeather(int,unsigned char),CDisplay__StopWeather);
#endif
#ifdef CDisplay__LightningStrike
REVERSE_DETOUR(void  CDisplay::LightningStrike(void),CDisplay__LightningStrike);
#endif
#ifdef CDisplay__GetNearestPlayerInView
REVERSE_DETOUR(class EQPlayer *  CDisplay::GetNearestPlayerInView(float,bool),CDisplay__GetNearestPlayerInView);
#endif
#ifdef CDisplay__ProcessEffects
REVERSE_DETOUR(void  CDisplay::ProcessEffects(void),CDisplay__ProcessEffects);
#endif
#ifdef CDisplay__ProcessCloud
REVERSE_DETOUR(void  CDisplay::ProcessCloud(void),CDisplay__ProcessCloud);
#endif
#ifdef CDisplay__DDrawUpdateDisplay
REVERSE_DETOUR(void  CDisplay::DDrawUpdateDisplay(void),CDisplay__DDrawUpdateDisplay);
#endif
#ifdef CDisplay__SetViewActor
REVERSE_DETOUR(void  CDisplay::SetViewActor(struct T3D_tagACTORINSTANCE *),CDisplay__SetViewActor);
#endif
#ifdef CDisplay__SwitchToDefaultCameraMode
REVERSE_DETOUR(void  CDisplay::SwitchToDefaultCameraMode(void),CDisplay__SwitchToDefaultCameraMode);
#endif
#ifdef CDisplay__SetYon
REVERSE_DETOUR(void  CDisplay::SetYon(float),CDisplay__SetYon);
#endif
#ifdef CDisplay__SetActorYon
REVERSE_DETOUR(void  CDisplay::SetActorYon(float),CDisplay__SetActorYon);
#endif
#ifdef CDisplay__SetViewAngle
REVERSE_DETOUR(void  CDisplay::SetViewAngle(int),CDisplay__SetViewAngle);
#endif
#ifdef CDisplay__UpdateCameraAfterModeSwitch
REVERSE_DETOUR(void  CDisplay::UpdateCameraAfterModeSwitch(void),CDisplay__UpdateCameraAfterModeSwitch);
#endif
#ifdef CDisplay__ChangeVideoMode
REVERSE_DETOUR(void  CDisplay::ChangeVideoMode(void),CDisplay__ChangeVideoMode);
#endif
#ifdef CDisplay__ToggleView
REVERSE_DETOUR(void  CDisplay::ToggleView(void),CDisplay__ToggleView);
#endif
#ifdef CDisplay__SetFog
REVERSE_DETOUR(void  CDisplay::SetFog(bool,float,float,unsigned char,unsigned char,unsigned char),CDisplay__SetFog);
#endif
#ifdef CDisplay__ClearScreen
REVERSE_DETOUR(void  CDisplay::ClearScreen(void),CDisplay__ClearScreen);
#endif
#ifdef CDisplay__CreatePlayerActor
REVERSE_DETOUR(void  CDisplay::CreatePlayerActor(class EQPlayer *),CDisplay__CreatePlayerActor);
#endif
#ifdef CDisplay__SetActorUserData
REVERSE_DETOUR(void  CDisplay::SetActorUserData(struct T3D_tagACTORINSTANCE *,void *),CDisplay__SetActorUserData);
#endif
#ifdef CDisplay__CreateLight
REVERSE_DETOUR(struct T3D_POINTLIGHT *  CDisplay::CreateLight(unsigned char,float,float,float,float),CDisplay__CreateLight);
#endif
#ifdef CDisplay__GetIntensity
REVERSE_DETOUR(unsigned char  CDisplay::GetIntensity(unsigned char),CDisplay__GetIntensity);
#endif
#ifdef CDisplay__DeleteLight
REVERSE_DETOUR(void  CDisplay::DeleteLight(struct T3D_POINTLIGHT *),CDisplay__DeleteLight);
#endif
#ifdef CDisplay__PlaySoundAtLocation
REVERSE_DETOUR(void  CDisplay::PlaySoundAtLocation(float,float,float,int),CDisplay__PlaySoundAtLocation);
#endif
#ifdef CDisplay__SetUserRender
REVERSE_DETOUR(long  CDisplay::SetUserRender(int),CDisplay__SetUserRender);
#endif
#ifdef CDisplay__GetClickedActor
REVERSE_DETOUR(struct T3D_tagACTORINSTANCE *  CDisplay::GetClickedActor(unsigned long,unsigned long,bool),CDisplay__GetClickedActor);
#endif
#ifdef CDisplay__CreateActor
REVERSE_DETOUR(struct T3D_tagACTORINSTANCE *  CDisplay::CreateActor(char *,float,float,float,float,float,float,bool,bool),CDisplay__CreateActor);
#endif
#ifdef CDisplay__SetActorBoundingRadius
REVERSE_DETOUR(float  CDisplay::SetActorBoundingRadius(struct T3D_tagACTORINSTANCE *,float,float),CDisplay__SetActorBoundingRadius);
#endif
#ifdef CDisplay__DeleteActor
REVERSE_DETOUR(void  CDisplay::DeleteActor(struct T3D_tagACTORINSTANCE *),CDisplay__DeleteActor);
#endif
#ifdef CDisplay__dupActorHierarchicalSprite
REVERSE_DETOUR(struct T3D_HIERARCHICALSPRITEINSTANCE *  CDisplay::dupActorHierarchicalSprite(struct T3D_tagACTORINSTANCE *),CDisplay__dupActorHierarchicalSprite);
#endif
#ifdef CDisplay__ToggleCharacterNameSprites
REVERSE_DETOUR(void  CDisplay::ToggleCharacterNameSprites(bool),CDisplay__ToggleCharacterNameSprites);
#endif
#ifdef CDisplay__ToggleNpcNameSprites
REVERSE_DETOUR(void  CDisplay::ToggleNpcNameSprites(bool),CDisplay__ToggleNpcNameSprites);
#endif
#ifdef CDisplay__TurnInfravisionEffectOn
REVERSE_DETOUR(int  CDisplay::TurnInfravisionEffectOn(void),CDisplay__TurnInfravisionEffectOn);
#endif
#ifdef CDisplay__TurnInfravisionEffectOff
REVERSE_DETOUR(int  CDisplay::TurnInfravisionEffectOff(void),CDisplay__TurnInfravisionEffectOff);
#endif
#ifdef CDisplay__SpurtBloodOnDag
REVERSE_DETOUR(void  CDisplay::SpurtBloodOnDag(struct T3D_DAG *),CDisplay__SpurtBloodOnDag);
#endif
#ifdef CDisplay__SetDayPeriod
REVERSE_DETOUR(void  CDisplay::SetDayPeriod(unsigned char),CDisplay__SetDayPeriod);
#endif
#ifdef CDisplay__SetSkyLayer
REVERSE_DETOUR(void  CDisplay::SetSkyLayer(int),CDisplay__SetSkyLayer);
#endif
#ifdef CDisplay__GetSkyTime
REVERSE_DETOUR(int  CDisplay::GetSkyTime(int *,int *),CDisplay__GetSkyTime);
#endif
#ifdef CDisplay__SetSunLight
REVERSE_DETOUR(void  CDisplay::SetSunLight(void),CDisplay__SetSunLight);
#endif
#ifdef CDisplay__SetSkyBackground
REVERSE_DETOUR(void  CDisplay::SetSkyBackground(void),CDisplay__SetSkyBackground);
#endif
#ifdef CDisplay__ProcessSky
REVERSE_DETOUR(void  CDisplay::ProcessSky(void),CDisplay__ProcessSky);
#endif
#ifdef CDisplay__SimpleDistance
REVERSE_DETOUR(float  CDisplay::SimpleDistance(float,float,float,float,float,float,float),CDisplay__SimpleDistance);
#endif
#ifdef CDisplay__TrueDistance
REVERSE_DETOUR(float  CDisplay::TrueDistance(float,float,float,float,float,float,float),CDisplay__TrueDistance);
#endif
#ifdef CDisplay__PlayerSimpleDistance
REVERSE_DETOUR(float  CDisplay::PlayerSimpleDistance(class EQPlayer *,class EQPlayer *,float),CDisplay__PlayerSimpleDistance);
#endif
#ifdef CDisplay__PlayerDistance
REVERSE_DETOUR(float  CDisplay::PlayerDistance(class EQPlayer *,class EQPlayer *,float),CDisplay__PlayerDistance);
#endif
#ifdef CDisplay__hideGrassObjects
REVERSE_DETOUR(void  CDisplay::hideGrassObjects(void),CDisplay__hideGrassObjects);
#endif
#ifdef CDisplay__updateGrassObjects
REVERSE_DETOUR(void  CDisplay::updateGrassObjects(void),CDisplay__updateGrassObjects);
#endif
#ifdef CDisplay__loadGrassObjects
REVERSE_DETOUR(void  CDisplay::loadGrassObjects(char *),CDisplay__loadGrassObjects);
#endif
#ifdef CDisplay__SetAmbientLight
REVERSE_DETOUR(void  CDisplay::SetAmbientLight(float),CDisplay__SetAmbientLight);
#endif
#ifdef CDisplay__SetViewActorByName
REVERSE_DETOUR(void  CDisplay::SetViewActorByName(char *),CDisplay__SetViewActorByName);
#endif
#ifdef CDisplay__SetActorSpriteTint
REVERSE_DETOUR(void  CDisplay::SetActorSpriteTint(struct _EQRGB *,struct T3D_tagACTORINSTANCE *),CDisplay__SetActorSpriteTint);
#endif
#ifdef CActionsWnd__MainPageActivate
REVERSE_DETOUR(int  CActionsWnd::MainPageActivate(void),CActionsWnd__MainPageActivate);
#endif
#ifdef CActionsWnd__MainPageDeactivate
REVERSE_DETOUR(int  CActionsWnd::MainPageDeactivate(void),CActionsWnd__MainPageDeactivate);
#endif
#ifdef CActionsWnd__SocialsPageDeactivate
REVERSE_DETOUR(int  CActionsWnd::SocialsPageDeactivate(void),CActionsWnd__SocialsPageDeactivate);
#endif
#ifdef CGroupSearchWnd__GroupListPageOnProcessFrame
REVERSE_DETOUR(int  CGroupSearchWnd::GroupListPageOnProcessFrame(void),CGroupSearchWnd__GroupListPageOnProcessFrame);
#endif
#ifdef CGroupSearchWnd__PlayerListPageOnProcessFrame
REVERSE_DETOUR(int  CGroupSearchWnd::PlayerListPageOnProcessFrame(void),CGroupSearchWnd__PlayerListPageOnProcessFrame);
#endif
#ifdef COptionsWnd__KeyboardPageOnProcessFrame
REVERSE_DETOUR(int  COptionsWnd::KeyboardPageOnProcessFrame(void),COptionsWnd__KeyboardPageOnProcessFrame);
#endif
#ifdef CDisplay__GetFloorHeight
REVERSE_DETOUR(float  CDisplay::GetFloorHeight(float,float,float),CDisplay__GetFloorHeight);
#endif
#ifdef CDisplay__GenericSphereColl
REVERSE_DETOUR(bool  CDisplay::GenericSphereColl(float,float,float,float,float,float,float *,float *,float *,unsigned char),CDisplay__GenericSphereColl);
#endif
#ifdef CDisplay__FindZoneTopZ
REVERSE_DETOUR(float  CDisplay::FindZoneTopZ(float,float,float),CDisplay__FindZoneTopZ);
#endif
#ifdef CDisplay__GetEnvironment
REVERSE_DETOUR(unsigned char  CDisplay::GetEnvironment(float,float,float,int *),CDisplay__GetEnvironment);
#endif
#ifdef CDisplay__MoveLocalPlayerToSafeCoords
REVERSE_DETOUR(void  CDisplay::MoveLocalPlayerToSafeCoords(void),CDisplay__MoveLocalPlayerToSafeCoords);
#endif
#ifdef CDisplay__SetupEQPlayers
REVERSE_DETOUR(void  CDisplay::SetupEQPlayers(void),CDisplay__SetupEQPlayers);
#endif
#ifdef CDisplay__MoveLight
REVERSE_DETOUR(void  CDisplay::MoveLight(struct T3D_POINTLIGHT *,struct _physicsinfo *),CDisplay__MoveLight);
#endif
#ifdef ZoneNPCLoadTextManager__ZoneNPCLoadTextManager
REVERSE_DETOUR( ZoneNPCLoadTextManager::ZoneNPCLoadTextManager(char *),ZoneNPCLoadTextManager__ZoneNPCLoadTextManager);
#endif
#ifdef ZoneNPCLoadTextManager__dZoneNPCLoadTextManager
REVERSE_DETOUR( ZoneNPCLoadTextManager::~ZoneNPCLoadTextManager(void),ZoneNPCLoadTextManager__dZoneNPCLoadTextManager);
#endif
#ifdef ZoneNPCLoadTextManager__LoadText
REVERSE_DETOUR(void  ZoneNPCLoadTextManager::LoadText(char *),ZoneNPCLoadTextManager__LoadText);
#endif
#ifdef ZoneNPCLoadTextManager__GetNPCCode
REVERSE_DETOUR(char *  ZoneNPCLoadTextManager::GetNPCCode(int),ZoneNPCLoadTextManager__GetNPCCode);
#endif
#ifdef ZoneNPCLoadTextManager__GetS3DName
REVERSE_DETOUR(char *  ZoneNPCLoadTextManager::GetS3DName(int),ZoneNPCLoadTextManager__GetS3DName);
#endif
#ifdef public_key__encrypt
REVERSE_DETOUR(class vlong  public_key::encrypt(class vlong &),public_key__encrypt);
#endif
#ifdef engineInterface__engineInterface
REVERSE_DETOUR( engineInterface::engineInterface(void),engineInterface__engineInterface);
#endif
#ifdef engineInterface__get
REVERSE_DETOUR(class engineInterface * __cdecl engineInterface::get(void),engineInterface__get);
#endif
#ifdef engineInterface__ChangeDag
REVERSE_DETOUR(unsigned long *  engineInterface::ChangeDag(struct T3D_tagWORLD *,struct T3D_DAG *,char *),engineInterface__ChangeDag);
#endif
#ifdef EQ_AltAbility__EQ_AltAbility
REVERSE_DETOUR( EQ_AltAbility::EQ_AltAbility(int),EQ_AltAbility__EQ_AltAbility);
#endif
#ifdef AltAdvManager__AltAdvManager
REVERSE_DETOUR( AltAdvManager::AltAdvManager(void),AltAdvManager__AltAdvManager);
#endif
#ifdef AltAdvManager__IsAbilityReady
REVERSE_DETOUR(bool  AltAdvManager::IsAbilityReady(class EQ_PC *,int const &,int *),AltAdvManager__IsAbilityReady);
#endif
#ifdef AltAdvManager__CalculateHideTimeReduce
REVERSE_DETOUR(int  AltAdvManager::CalculateHideTimeReduce(class EQ_PC *),AltAdvManager__CalculateHideTimeReduce);
#endif
#ifdef AltAdvManager__GetCalculatedTimer
REVERSE_DETOUR(unsigned long  AltAdvManager::GetCalculatedTimer(class EQ_PC *,int),AltAdvManager__GetCalculatedTimer);
#endif
#ifdef AltAdvManager__GetNextAbilityCost
REVERSE_DETOUR(int  AltAdvManager::GetNextAbilityCost(int,int),AltAdvManager__GetNextAbilityCost);
#endif
#ifdef AltAdvManager__TotalPointsInSkill
REVERSE_DETOUR(int  AltAdvManager::TotalPointsInSkill(int,int),AltAdvManager__TotalPointsInSkill);
#endif
#ifdef AltAdvManager__CalculateStalwartEnduranceChance
REVERSE_DETOUR(int  AltAdvManager::CalculateStalwartEnduranceChance(class EQ_PC *),AltAdvManager__CalculateStalwartEnduranceChance);
#endif
#ifdef AltAdvManager__CalculateLoHHarmTouchReuseTimer
REVERSE_DETOUR(int  AltAdvManager::CalculateLoHHarmTouchReuseTimer(class EQ_PC *,int),AltAdvManager__CalculateLoHHarmTouchReuseTimer);
#endif
#ifdef AltAdvManager__CalculateSingingMasteryMod
REVERSE_DETOUR(int  AltAdvManager::CalculateSingingMasteryMod(class EQ_PC *,int),AltAdvManager__CalculateSingingMasteryMod);
#endif
#ifdef AltAdvManager__CalculateInstrumentMasteryMod
REVERSE_DETOUR(int  AltAdvManager::CalculateInstrumentMasteryMod(class EQ_PC *),AltAdvManager__CalculateInstrumentMasteryMod);
#endif
#ifdef AltAdvManager__CalculateFleetOfFoot
REVERSE_DETOUR(int  AltAdvManager::CalculateFleetOfFoot(class EQ_PC *),AltAdvManager__CalculateFleetOfFoot);
#endif
#ifdef AltAdvManager__CalculateNimbleEvasionChance
REVERSE_DETOUR(int  AltAdvManager::CalculateNimbleEvasionChance(class EQ_PC *),AltAdvManager__CalculateNimbleEvasionChance);
#endif
#ifdef AltAdvManager__CalculateDoubleAttackChance
REVERSE_DETOUR(int  AltAdvManager::CalculateDoubleAttackChance(class EQ_PC *,int,unsigned char),AltAdvManager__CalculateDoubleAttackChance);
#endif
#ifdef AltAdvManager__CalculateMitigationBoost
REVERSE_DETOUR(int  AltAdvManager::CalculateMitigationBoost(class EQ_PC *,int),AltAdvManager__CalculateMitigationBoost);
#endif
#ifdef AltAdvManager__CalculateSpellCastingMastery
REVERSE_DETOUR(int  AltAdvManager::CalculateSpellCastingMastery(class EQ_PC *),AltAdvManager__CalculateSpellCastingMastery);
#endif
#ifdef AltAdvManager__CalculateMaxHPAA
REVERSE_DETOUR(int  AltAdvManager::CalculateMaxHPAA(class EQ_PC *,int),AltAdvManager__CalculateMaxHPAA);
#endif
#ifdef AltAdvManager__CalculateMaxStatAA
REVERSE_DETOUR(int  AltAdvManager::CalculateMaxStatAA(class EQ_PC *,int),AltAdvManager__CalculateMaxStatAA);
#endif
#ifdef AltAdvManager__GetAbilityTitle
REVERSE_DETOUR(int  AltAdvManager::GetAbilityTitle(class EQPlayer *),AltAdvManager__GetAbilityTitle);
#endif
#ifdef AltAdvManager__AltSkillReqs
REVERSE_DETOUR(int  AltAdvManager::AltSkillReqs(class EQ_PC *,int),AltAdvManager__AltSkillReqs);
#endif
#ifdef AltAdvManager__GetAALevelNeeded
REVERSE_DETOUR(int  AltAdvManager::GetAALevelNeeded(class EQ_PC *,int),AltAdvManager__GetAALevelNeeded);
#endif
#ifdef AltAdvManager__MeetsPoPLevelReqs
REVERSE_DETOUR(int  AltAdvManager::MeetsPoPLevelReqs(class EQ_PC *,int,int),AltAdvManager__MeetsPoPLevelReqs);
#endif
#ifdef AltAdvManager__CanTrainAbility
REVERSE_DETOUR(int  AltAdvManager::CanTrainAbility(class EQ_PC *,int),AltAdvManager__CanTrainAbility);
#endif
#ifdef AltAdvManager__AbilitiesByClass
REVERSE_DETOUR(int  AltAdvManager::AbilitiesByClass(int,int),AltAdvManager__AbilitiesByClass);
#endif
#ifdef AltAdvManager__GetAbilityReqs
REVERSE_DETOUR(void  AltAdvManager::GetAbilityReqs(char *,int),AltAdvManager__GetAbilityReqs);
#endif
#ifdef EQ_CharacterData__EQ_CharacterDataResetAllMembers
REVERSE_DETOUR(void  EQ_CharacterData::EQ_CharacterDataResetAllMembers(void),EQ_CharacterData__EQ_CharacterDataResetAllMembers);
#endif
#ifdef EQ_Affect__Reset
REVERSE_DETOUR(void  EQ_Affect::Reset(void),EQ_Affect__Reset);
#endif
#ifdef EQ_Character__EQ_Character
REVERSE_DETOUR( EQ_Character::EQ_Character(void),EQ_Character__EQ_Character);
#endif
#ifdef EQ_Character__dEQ_Character
REVERSE_DETOUR( EQ_Character::~EQ_Character(void),EQ_Character__dEQ_Character);
#endif
#ifdef EQ_Character__EQ_CharacterResetAllMembers
REVERSE_DETOUR(void  EQ_Character::EQ_CharacterResetAllMembers(void),EQ_Character__EQ_CharacterResetAllMembers);
#endif
#ifdef EQ_Character__ModifyCurHP
REVERSE_DETOUR(void  EQ_Character::ModifyCurHP(int,class EQPlayer *),EQ_Character__ModifyCurHP);
#endif
#ifdef EQ_Character__normal_to_special
REVERSE_DETOUR(int __cdecl EQ_Character::normal_to_special(int),EQ_Character__normal_to_special);
#endif
#ifdef EQ_Character__IsSpellcaster
REVERSE_DETOUR(int  EQ_Character::IsSpellcaster(void),EQ_Character__IsSpellcaster);
#endif
#ifdef EQ_Character__DoLight
REVERSE_DETOUR(void  EQ_Character::DoLight(unsigned char),EQ_Character__DoLight);
#endif
#ifdef EQ_Character__Skill
REVERSE_DETOUR(int  EQ_Character::Skill(int),EQ_Character__Skill);
#endif
#ifdef EQ_Character__HasSpell
REVERSE_DETOUR(int  EQ_Character::HasSpell(int),EQ_Character__HasSpell);
#endif
#ifdef EQ_Character__ResetCur_HP
REVERSE_DETOUR(void  EQ_Character::ResetCur_HP(int),EQ_Character__ResetCur_HP);
#endif
#ifdef EQ_Character__Cur_HP
REVERSE_DETOUR(int  EQ_Character::Cur_HP(int),EQ_Character__Cur_HP);
#endif
#ifdef EQ_Character__GetHPFromStamina
REVERSE_DETOUR(int  EQ_Character::GetHPFromStamina(int),EQ_Character__GetHPFromStamina);
#endif
#ifdef EQ_Character__Max_HP
REVERSE_DETOUR(int  EQ_Character::Max_HP(int),EQ_Character__Max_HP);
#endif
#ifdef EQ_Character__Cur_Mana
REVERSE_DETOUR(int  EQ_Character::Cur_Mana(void),EQ_Character__Cur_Mana);
#endif
#ifdef EQ_Character__Max_Mana
REVERSE_DETOUR(int  EQ_Character::Max_Mana(void),EQ_Character__Max_Mana);
#endif
#ifdef EQ_Character__IsMage
REVERSE_DETOUR(int  EQ_Character::IsMage(void),EQ_Character__IsMage);
#endif
#ifdef EQ_Character__GetClassACBonus
REVERSE_DETOUR(int  EQ_Character::GetClassACBonus(int),EQ_Character__GetClassACBonus);
#endif
#ifdef EQ_Character__ac
REVERSE_DETOUR(int  EQ_Character::ac(bool),EQ_Character__ac);
#endif
#ifdef EQ_Character__compute_tohit
REVERSE_DETOUR(int  EQ_Character::compute_tohit(unsigned char),EQ_Character__compute_tohit);
#endif
#ifdef EQ_Character__defense_agility_bonus
REVERSE_DETOUR(int  EQ_Character::defense_agility_bonus(void),EQ_Character__defense_agility_bonus);
#endif
#ifdef EQ_Character__compute_defense
REVERSE_DETOUR(int  EQ_Character::compute_defense(void),EQ_Character__compute_defense);
#endif
#ifdef EQ_Character__offense
REVERSE_DETOUR(int  EQ_Character::offense(unsigned char),EQ_Character__offense);
#endif
#ifdef EQ_Character__HasSkill
REVERSE_DETOUR(int  EQ_Character::HasSkill(unsigned char),EQ_Character__HasSkill);
#endif
#ifdef EQ_Character__HasInnateSkill
REVERSE_DETOUR(int  EQ_Character::HasInnateSkill(unsigned char,int),EQ_Character__HasInnateSkill);
#endif
#ifdef EQ_Character__InitMyLanguages
REVERSE_DETOUR(void  EQ_Character::InitMyLanguages(void),EQ_Character__InitMyLanguages);
#endif
#ifdef EQ_Character__BaneDamage
REVERSE_DETOUR(int  EQ_Character::BaneDamage(class EQ_Equipment *),EQ_Character__BaneDamage);
#endif
#ifdef EQ_Character__ElementResistDmg
REVERSE_DETOUR(int  EQ_Character::ElementResistDmg(class EQ_Equipment *,int),EQ_Character__ElementResistDmg);
#endif
#ifdef EQ_Character__save_bash
REVERSE_DETOUR(int  EQ_Character::save_bash(int),EQ_Character__save_bash);
#endif
#ifdef EQ_Character__CapStat
REVERSE_DETOUR(int  EQ_Character::CapStat(int,int),EQ_Character__CapStat);
#endif
#ifdef EQ_Character__CalcFoodDrinkBonus
REVERSE_DETOUR(void  EQ_Character::CalcFoodDrinkBonus(int),EQ_Character__CalcFoodDrinkBonus);
#endif
#ifdef EQ_Character__basesave_magic
REVERSE_DETOUR(int  EQ_Character::basesave_magic(void),EQ_Character__basesave_magic);
#endif
#ifdef EQ_Character__save_magic
REVERSE_DETOUR(int  EQ_Character::save_magic(void),EQ_Character__save_magic);
#endif
#ifdef EQ_Character__basesave_fire
REVERSE_DETOUR(int  EQ_Character::basesave_fire(void),EQ_Character__basesave_fire);
#endif
#ifdef EQ_Character__save_fire
REVERSE_DETOUR(int  EQ_Character::save_fire(void),EQ_Character__save_fire);
#endif
#ifdef EQ_Character__basesave_cold
REVERSE_DETOUR(int  EQ_Character::basesave_cold(void),EQ_Character__basesave_cold);
#endif
#ifdef EQ_Character__save_cold
REVERSE_DETOUR(int  EQ_Character::save_cold(void),EQ_Character__save_cold);
#endif
#ifdef EQ_Character__basesave_disease
REVERSE_DETOUR(int  EQ_Character::basesave_disease(void),EQ_Character__basesave_disease);
#endif
#ifdef EQ_Character__save_disease
REVERSE_DETOUR(int  EQ_Character::save_disease(void),EQ_Character__save_disease);
#endif
#ifdef EQ_Character__basesave_poison
REVERSE_DETOUR(int  EQ_Character::basesave_poison(void),EQ_Character__basesave_poison);
#endif
#ifdef EQ_Character__save_poison
REVERSE_DETOUR(int  EQ_Character::save_poison(void),EQ_Character__save_poison);
#endif
#ifdef EQ_Character__Str
REVERSE_DETOUR(int  EQ_Character::Str(void),EQ_Character__Str);
#endif
#ifdef EQ_Character__Sta
REVERSE_DETOUR(int  EQ_Character::Sta(void),EQ_Character__Sta);
#endif
#ifdef EQ_Character__Cha
REVERSE_DETOUR(int  EQ_Character::Cha(void),EQ_Character__Cha);
#endif
#ifdef EQ_Character__Dex
REVERSE_DETOUR(int  EQ_Character::Dex(void),EQ_Character__Dex);
#endif
#ifdef EQ_Character__Int
REVERSE_DETOUR(int  EQ_Character::Int(void),EQ_Character__Int);
#endif
#ifdef EQ_Character__Agi
REVERSE_DETOUR(int  EQ_Character::Agi(void),EQ_Character__Agi);
#endif
#ifdef EQ_Character__Wis
REVERSE_DETOUR(int  EQ_Character::Wis(void),EQ_Character__Wis);
#endif
#ifdef EQ_Character__ApplyFatigue
REVERSE_DETOUR(int  EQ_Character::ApplyFatigue(int),EQ_Character__ApplyFatigue);
#endif
#ifdef EQ_Character__max_encumbrance
REVERSE_DETOUR(int  EQ_Character::max_encumbrance(void),EQ_Character__max_encumbrance);
#endif
#ifdef EQ_Character__CanUseItem
REVERSE_DETOUR(int  EQ_Character::CanUseItem(class EQ_Item *),EQ_Character__CanUseItem);
#endif
#ifdef EQ_Character__encum_factor
REVERSE_DETOUR(float  EQ_Character::encum_factor(void),EQ_Character__encum_factor);
#endif
#ifdef EQ_Character__cur_encumbrance
REVERSE_DETOUR(int  EQ_Character::cur_encumbrance(void),EQ_Character__cur_encumbrance);
#endif
#ifdef EQ_Character__Race
REVERSE_DETOUR(char *  EQ_Character::Race(int),EQ_Character__Race);
#endif
#ifdef EQ_Character__Class
REVERSE_DETOUR(char *  EQ_Character::Class(int),EQ_Character__Class);
#endif
#ifdef EQ_Character__KunarkClass
REVERSE_DETOUR(char *  EQ_Character::KunarkClass(int,int,int,bool),EQ_Character__KunarkClass);
#endif
#ifdef EQ_Character__ClassMin
REVERSE_DETOUR(unsigned char  EQ_Character::ClassMin(int,int,unsigned char),EQ_Character__ClassMin);
#endif
#ifdef EQ_Character__CheckClass
REVERSE_DETOUR(unsigned char  EQ_Character::CheckClass(int,int),EQ_Character__CheckClass);
#endif
#ifdef EQ_Character__CanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::CanWorship(int,int,unsigned char),EQ_Character__CanWorship);
#endif
#ifdef EQ_Character__HumanCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::HumanCanWorship(unsigned char,unsigned char),EQ_Character__HumanCanWorship);
#endif
#ifdef EQ_Character__BarbarianCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::BarbarianCanWorship(unsigned char,unsigned char),EQ_Character__BarbarianCanWorship);
#endif
#ifdef EQ_Character__EruditeCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::EruditeCanWorship(unsigned char,unsigned char),EQ_Character__EruditeCanWorship);
#endif
#ifdef EQ_Character__ElfCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::ElfCanWorship(unsigned char,unsigned char),EQ_Character__ElfCanWorship);
#endif
#ifdef EQ_Character__HighElfCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::HighElfCanWorship(unsigned char,unsigned char),EQ_Character__HighElfCanWorship);
#endif
#ifdef EQ_Character__DarkElfCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::DarkElfCanWorship(unsigned char,unsigned char),EQ_Character__DarkElfCanWorship);
#endif
#ifdef EQ_Character__HalfElfCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::HalfElfCanWorship(unsigned char,unsigned char),EQ_Character__HalfElfCanWorship);
#endif
#ifdef EQ_Character__DwarfCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::DwarfCanWorship(unsigned char,unsigned char),EQ_Character__DwarfCanWorship);
#endif
#ifdef EQ_Character__TrollCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::TrollCanWorship(unsigned char,unsigned char),EQ_Character__TrollCanWorship);
#endif
#ifdef EQ_Character__OgreCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::OgreCanWorship(unsigned char,unsigned char),EQ_Character__OgreCanWorship);
#endif
#ifdef EQ_Character__HalflingCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::HalflingCanWorship(unsigned char,unsigned char),EQ_Character__HalflingCanWorship);
#endif
#ifdef EQ_Character__GnomeCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::GnomeCanWorship(unsigned char,unsigned char),EQ_Character__GnomeCanWorship);
#endif
#ifdef EQ_Character__IksarCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::IksarCanWorship(unsigned char,unsigned char),EQ_Character__IksarCanWorship);
#endif
#ifdef EQ_Character__VahShirCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::VahShirCanWorship(unsigned char,unsigned char),EQ_Character__VahShirCanWorship);
#endif
#ifdef EQ_Character__FroglockCanWorship
REVERSE_DETOUR(unsigned char  EQ_Character::FroglockCanWorship(unsigned char,unsigned char),EQ_Character__FroglockCanWorship);
#endif
#ifdef EQ_Character__CityCanStart
REVERSE_DETOUR(unsigned char  EQ_Character::CityCanStart(int,int,int,int),EQ_Character__CityCanStart);
#endif
#ifdef EQ_Character__BaseAttr
REVERSE_DETOUR(unsigned char  EQ_Character::BaseAttr(int,unsigned char),EQ_Character__BaseAttr);
#endif
#ifdef EQ_Character__InitSkills
REVERSE_DETOUR(void  EQ_Character::InitSkills(unsigned char,unsigned int),EQ_Character__InitSkills);
#endif
#ifdef EQ_Character__InitInnates
REVERSE_DETOUR(void  EQ_Character::InitInnates(unsigned int,unsigned int),EQ_Character__InitInnates);
#endif
#ifdef EQ_Character__IsSpecialBazaarSpot
REVERSE_DETOUR(int  EQ_Character::IsSpecialBazaarSpot(class EQPlayer *),EQ_Character__IsSpecialBazaarSpot);
#endif
#ifdef EQ_Character__CanSecondaryAttack
REVERSE_DETOUR(unsigned char  EQ_Character::CanSecondaryAttack(class EQPlayer *),EQ_Character__CanSecondaryAttack);
#endif
#ifdef EQ_Character__CanDoubleAttack
REVERSE_DETOUR(unsigned char  EQ_Character::CanDoubleAttack(class EQPlayer *,unsigned char),EQ_Character__CanDoubleAttack);
#endif
#ifdef EQ_Character__AntiTwinkAdj
REVERSE_DETOUR(int  EQ_Character::AntiTwinkAdj(class EQ_Equipment *,int,int),EQ_Character__AntiTwinkAdj);
#endif
#ifdef EQ_Character__GetSkillBaseDamage
REVERSE_DETOUR(unsigned char  EQ_Character::GetSkillBaseDamage(unsigned char,class EQPlayer *),EQ_Character__GetSkillBaseDamage);
#endif
#ifdef EQ_Character__UseSkill
REVERSE_DETOUR(void  EQ_Character::UseSkill(unsigned char,class EQPlayer *),EQ_Character__UseSkill);
#endif
#ifdef EQ_Character__DoIntimidationEvent
REVERSE_DETOUR(void  EQ_Character::DoIntimidationEvent(void),EQ_Character__DoIntimidationEvent);
#endif
#ifdef EQ_Character__DoFishingEvent
REVERSE_DETOUR(void  EQ_Character::DoFishingEvent(void),EQ_Character__DoFishingEvent);
#endif
#ifdef EQ_Character__FindClosest
REVERSE_DETOUR(class EQPlayer *  EQ_Character::FindClosest(int,int,int,int,int),EQ_Character__FindClosest);
#endif
#ifdef EQ_Character__IAmDead
REVERSE_DETOUR(void  EQ_Character::IAmDead(struct _EQMissileHitinfo *,int),EQ_Character__IAmDead);
#endif
#ifdef EQ_Character__TotalOnPerson
REVERSE_DETOUR(long  EQ_Character::TotalOnPerson(void),EQ_Character__TotalOnPerson);
#endif
#ifdef EQ_Character__ItemSold
REVERSE_DETOUR(void  EQ_Character::ItemSold(long),EQ_Character__ItemSold);
#endif
#ifdef EQ_Character__TakeFallDamage
REVERSE_DETOUR(int  EQ_Character::TakeFallDamage(float),EQ_Character__TakeFallDamage);
#endif
#ifdef EQ_Character__IHaveSkill
REVERSE_DETOUR(int  EQ_Character::IHaveSkill(unsigned char),EQ_Character__IHaveSkill);
#endif
#ifdef EQ_Character__NoMezMe
REVERSE_DETOUR(int  EQ_Character::NoMezMe(int,class EQPlayer *,class EQ_Spell *),EQ_Character__NoMezMe);
#endif
#ifdef EQ_Character__NoBashMe
REVERSE_DETOUR(int  EQ_Character::NoBashMe(int),EQ_Character__NoBashMe);
#endif
#ifdef EQ_Character__StunMe
REVERSE_DETOUR(void  EQ_Character::StunMe(unsigned int,bool),EQ_Character__StunMe);
#endif
#ifdef EQ_Character__UnStunMe
REVERSE_DETOUR(void  EQ_Character::UnStunMe(void),EQ_Character__UnStunMe);
#endif
#ifdef EQ_Character__ApplyDamage
REVERSE_DETOUR(int  EQ_Character::ApplyDamage(int,struct _EQMissileHitinfo *,bool,class HateListEntry *,bool),EQ_Character__ApplyDamage);
#endif
#ifdef EQ_Character__NotifyPCAffectChange
REVERSE_DETOUR(void  EQ_Character::NotifyPCAffectChange(int,int),EQ_Character__NotifyPCAffectChange);
#endif
#ifdef EQ_Character__MakeMeVisible
REVERSE_DETOUR(void  EQ_Character::MakeMeVisible(int),EQ_Character__MakeMeVisible);
#endif
#ifdef EQ_Character__UpdateMyVisibleStatus
REVERSE_DETOUR(void  EQ_Character::UpdateMyVisibleStatus(void),EQ_Character__UpdateMyVisibleStatus);
#endif
#ifdef EQ_Character__CanISeeInvis
REVERSE_DETOUR(unsigned char  EQ_Character::CanISeeInvis(void),EQ_Character__CanISeeInvis);
#endif
#ifdef EQ_Character__CanIBreathe
REVERSE_DETOUR(unsigned char  EQ_Character::CanIBreathe(void),EQ_Character__CanIBreathe);
#endif
#ifdef EQ_Character__ProcessEnvironment
REVERSE_DETOUR(void  EQ_Character::ProcessEnvironment(void),EQ_Character__ProcessEnvironment);
#endif
#ifdef EQ_Character__ProcessHungerandThirst
REVERSE_DETOUR(void  EQ_Character::ProcessHungerandThirst(unsigned int),EQ_Character__ProcessHungerandThirst);
#endif
#ifdef EQ_Character__ItemSpellAffects
REVERSE_DETOUR(int  EQ_Character::ItemSpellAffects(int),EQ_Character__ItemSpellAffects);
#endif
#ifdef EQ_Character__ProcessAllStats
REVERSE_DETOUR(void  EQ_Character::ProcessAllStats(void),EQ_Character__ProcessAllStats);
#endif
#ifdef EQ_Character__DoPassageOfTime
REVERSE_DETOUR(void  EQ_Character::DoPassageOfTime(void),EQ_Character__DoPassageOfTime);
#endif
#ifdef EQ_Character__FindItemByClass
REVERSE_DETOUR(unsigned char  EQ_Character::FindItemByClass(int,int *,int *),EQ_Character__FindItemByClass);
#endif
#ifdef EQ_Character__FindItemByRecord
REVERSE_DETOUR(unsigned char  EQ_Character::FindItemByRecord(int,int *,int *),EQ_Character__FindItemByRecord);
#endif
#ifdef EQ_Character__FindItemQty
REVERSE_DETOUR(unsigned char  EQ_Character::FindItemQty(int,int),EQ_Character__FindItemQty);
#endif
#ifdef EQ_Character__CanMedOnHorse
REVERSE_DETOUR(unsigned char  EQ_Character::CanMedOnHorse(void),EQ_Character__CanMedOnHorse);
#endif
#ifdef EQ_Character__ExpendItemCharge
REVERSE_DETOUR(unsigned char  EQ_Character::ExpendItemCharge(int,int),EQ_Character__ExpendItemCharge);
#endif
#ifdef EQ_Character__AutoEat
REVERSE_DETOUR(int  EQ_Character::AutoEat(unsigned char),EQ_Character__AutoEat);
#endif
#ifdef EQ_Character__CheckFoodAndWater
REVERSE_DETOUR(int  EQ_Character::CheckFoodAndWater(void),EQ_Character__CheckFoodAndWater);
#endif
#ifdef EQ_Character__DoMeditation
REVERSE_DETOUR(void  EQ_Character::DoMeditation(void),EQ_Character__DoMeditation);
#endif
#ifdef EQ_Character__SetLocalVar
REVERSE_DETOUR(int  EQ_Character::SetLocalVar(char *,int),EQ_Character__SetLocalVar);
#endif
#ifdef EQ_Character__GetAbility
REVERSE_DETOUR(int  EQ_Character::GetAbility(int)const ,EQ_Character__GetAbility);
#endif
#ifdef EQ_Character__GetIndexSkillMinDamageMod
REVERSE_DETOUR(int  EQ_Character::GetIndexSkillMinDamageMod(int),EQ_Character__GetIndexSkillMinDamageMod);
#endif
#ifdef EQ_Character__GetFocusConserveRegChance
REVERSE_DETOUR(int const  EQ_Character::GetFocusConserveRegChance(class EQ_Spell const *,class EQ_Equipment * *),EQ_Character__GetFocusConserveRegChance);
#endif
#ifdef EQ_Character__GetFocusCastingTimeModifier
REVERSE_DETOUR(int const  EQ_Character::GetFocusCastingTimeModifier(class EQ_Spell const *,class EQ_Equipment * *),EQ_Character__GetFocusCastingTimeModifier);
#endif
#ifdef EQ_Character__GetFocusRangeModifier
REVERSE_DETOUR(int const  EQ_Character::GetFocusRangeModifier(class EQ_Spell const *,class EQ_Equipment * *),EQ_Character__GetFocusRangeModifier);
#endif
#ifdef EQ_Character__GetFocusItem
REVERSE_DETOUR(class EQ_Equipment *  EQ_Character::GetFocusItem(class EQ_Spell const *,int),EQ_Character__GetFocusItem);
#endif
#ifdef EQ_Character__GetFocusEffect
REVERSE_DETOUR(class EQ_Spell *  EQ_Character::GetFocusEffect(class EQ_Spell const *,int),EQ_Character__GetFocusEffect);
#endif
#ifdef EQ_Character__DoesSpellMatchFocusFilters
REVERSE_DETOUR(bool  EQ_Character::DoesSpellMatchFocusFilters(class EQ_Spell const *,class EQ_Spell const *),EQ_Character__DoesSpellMatchFocusFilters);
#endif
#ifdef EQ_Character__GetMyPetPlayer
REVERSE_DETOUR(class EQPlayer *  EQ_Character::GetMyPetPlayer(void),EQ_Character__GetMyPetPlayer);
#endif
#ifdef EQ_Character__GetMaxEffects
REVERSE_DETOUR(unsigned char  EQ_Character::GetMaxEffects(void)const ,EQ_Character__GetMaxEffects);
#endif
#ifdef EQ_Character__GetEffect
REVERSE_DETOUR(class EQ_Affect &  EQ_Character::GetEffect(int),EQ_Character__GetEffect);
#endif
#ifdef EQ_Character__GetEffectId
REVERSE_DETOUR(unsigned int  EQ_Character::GetEffectId(int),EQ_Character__GetEffectId);
#endif
#ifdef EQ_Character__SetEffectId
REVERSE_DETOUR(void  EQ_Character::SetEffectId(unsigned char,unsigned int),EQ_Character__SetEffectId);
#endif
#ifdef EQ_Character__CastSpell
REVERSE_DETOUR(unsigned char  EQ_Character::CastSpell(unsigned char,int,class EQ_Item * *,int),EQ_Character__CastSpell);
#endif
#ifdef EQ_Character__GetBardInstrumentMod
REVERSE_DETOUR(int  EQ_Character::GetBardInstrumentMod(int),EQ_Character__GetBardInstrumentMod);
#endif
#ifdef EQ_Character__CalculateBardSongMod
REVERSE_DETOUR(int  EQ_Character::CalculateBardSongMod(int),EQ_Character__CalculateBardSongMod);
#endif
#ifdef EQ_Character__CastingRequirementsMet
REVERSE_DETOUR(unsigned char  EQ_Character::CastingRequirementsMet(int),EQ_Character__CastingRequirementsMet);
#endif
#ifdef EQ_Character__GetAACastingTimeModifier
REVERSE_DETOUR(int const  EQ_Character::GetAACastingTimeModifier(class EQ_Spell const *),EQ_Character__GetAACastingTimeModifier);
#endif
#ifdef EQ_Character__BardCastBard
REVERSE_DETOUR(int  EQ_Character::BardCastBard(class EQ_Spell const *,int)const ,EQ_Character__BardCastBard);
#endif
#ifdef EQ_Character__IsValidAffect
REVERSE_DETOUR(bool  EQ_Character::IsValidAffect(int),EQ_Character__IsValidAffect);
#endif
#ifdef EQ_Character__LaunchSpell
REVERSE_DETOUR(unsigned char  EQ_Character::LaunchSpell(unsigned char,int,class EQ_Item * *),EQ_Character__LaunchSpell);
#endif
#ifdef EQ_Character__HandleSpecialPCAffects
REVERSE_DETOUR(void  EQ_Character::HandleSpecialPCAffects(int),EQ_Character__HandleSpecialPCAffects);
#endif
#ifdef EQ_Character__CalcAffectChange
REVERSE_DETOUR(int  EQ_Character::CalcAffectChange(class EQ_Spell *,unsigned char,unsigned char,class EQ_Affect *),EQ_Character__CalcAffectChange);
#endif
#ifdef EQ_Character__GetPCSpellAffect
REVERSE_DETOUR(class EQ_Affect *  EQ_Character::GetPCSpellAffect(unsigned char,int *),EQ_Character__GetPCSpellAffect);
#endif
#ifdef EQ_Character__TotalSpellAffects
REVERSE_DETOUR(int  EQ_Character::TotalSpellAffects(unsigned char,bool,int *),EQ_Character__TotalSpellAffects);
#endif
#ifdef EQ_Character__IsSpellAffectingPC
REVERSE_DETOUR(unsigned char  EQ_Character::IsSpellAffectingPC(int),EQ_Character__IsSpellAffectingPC);
#endif
#ifdef EQ_Character__SpellFizzled
REVERSE_DETOUR(unsigned char  EQ_Character::SpellFizzled(unsigned char,class EQ_Spell *),EQ_Character__SpellFizzled);
#endif
#ifdef EQ_Character__ProcessAffects
REVERSE_DETOUR(int  EQ_Character::ProcessAffects(void),EQ_Character__ProcessAffects);
#endif
#ifdef EQ_Character__FindAffectSlot
REVERSE_DETOUR(class EQ_Affect *  EQ_Character::FindAffectSlot(int,class EQPlayer *,int *,int),EQ_Character__FindAffectSlot);
#endif
#ifdef EQ_Character__GetOpenEffectSlot
REVERSE_DETOUR(int  EQ_Character::GetOpenEffectSlot(bool,int),EQ_Character__GetOpenEffectSlot);
#endif
#ifdef EQ_Character__GetFirstEffectSlot
REVERSE_DETOUR(int  EQ_Character::GetFirstEffectSlot(bool),EQ_Character__GetFirstEffectSlot);
#endif
#ifdef EQ_Character__GetLastEffectSlot
REVERSE_DETOUR(int  EQ_Character::GetLastEffectSlot(bool),EQ_Character__GetLastEffectSlot);
#endif
#ifdef EQ_Character__IsStackBlocked
REVERSE_DETOUR(bool  EQ_Character::IsStackBlocked(class EQ_Spell const *),EQ_Character__IsStackBlocked);
#endif
#ifdef EQ_Character__IsSpellTooPowerfull
REVERSE_DETOUR(bool  EQ_Character::IsSpellTooPowerfull(class EQ_Spell *,class EQ_Character *),EQ_Character__IsSpellTooPowerfull);
#endif
#ifdef EQ_Character__HitBySpell
REVERSE_DETOUR(void  EQ_Character::HitBySpell(struct _EQMissileHitinfo *),EQ_Character__HitBySpell);
#endif
#ifdef EQ_Spell__IsStackableDot
REVERSE_DETOUR(bool  EQ_Spell::IsStackableDot(void)const ,EQ_Spell__IsStackableDot);
#endif
#ifdef EQ_Character__EQSPA_Feign_Death
REVERSE_DETOUR(void  EQ_Character::EQSPA_Feign_Death(int),EQ_Character__EQSPA_Feign_Death);
#endif
#ifdef EQ_Character__SpellDuration
REVERSE_DETOUR(int  EQ_Character::SpellDuration(class EQ_Spell const *,unsigned char,unsigned char),EQ_Character__SpellDuration);
#endif
#ifdef EQ_Character__eqspa_change_form
REVERSE_DETOUR(int  EQ_Character::eqspa_change_form(class EQ_Spell *,int,int,class EQ_Affect *),EQ_Character__eqspa_change_form);
#endif
#ifdef EQ_Character__eqspa_movement_rate
REVERSE_DETOUR(void  EQ_Character::eqspa_movement_rate(int),EQ_Character__eqspa_movement_rate);
#endif
#ifdef EQ_Character__eqspa_levitation
REVERSE_DETOUR(void  EQ_Character::eqspa_levitation(void),EQ_Character__eqspa_levitation);
#endif
#ifdef EQ_Character__eqspa_hp
REVERSE_DETOUR(int  EQ_Character::eqspa_hp(unsigned int,class EQ_Affect *,int,class EQ_Spell *),EQ_Character__eqspa_hp);
#endif
#ifdef EQ_Character__eqspa_locate_corpse
REVERSE_DETOUR(void  EQ_Character::eqspa_locate_corpse(void),EQ_Character__eqspa_locate_corpse);
#endif
#ifdef EQ_Character__InSpecialBindSpot
REVERSE_DETOUR(int  EQ_Character::InSpecialBindSpot(class EQPlayer *),EQ_Character__InSpecialBindSpot);
#endif
#ifdef EQ_Character__RemovePCAffect
REVERSE_DETOUR(void  EQ_Character::RemovePCAffect(class EQ_Affect *),EQ_Character__RemovePCAffect);
#endif
#ifdef EQ_Character__RemovePCAffectex
REVERSE_DETOUR(void  EQ_Character::RemovePCAffectex(class EQ_Affect *,int),EQ_Character__RemovePCAffectex);
#endif
#ifdef EQ_Character__StopSpellCast
REVERSE_DETOUR(void  EQ_Character::StopSpellCast(unsigned char),EQ_Character__StopSpellCast);
#endif
#ifdef EQ_Character__StopSpellCast1
REVERSE_DETOUR(void  EQ_Character::StopSpellCast(unsigned char,int),EQ_Character__StopSpellCast1);
#endif
#ifdef EQ_Character__ReCachSpellEffects
REVERSE_DETOUR(void  EQ_Character::ReCachSpellEffects(void),EQ_Character__ReCachSpellEffects);
#endif
#ifdef EQ_Character__ReCachItemEffects
REVERSE_DETOUR(void  EQ_Character::ReCachItemEffects(void),EQ_Character__ReCachItemEffects);
#endif
#ifdef EQ_Character__GetCachEQSPA
REVERSE_DETOUR(int  EQ_Character::GetCachEQSPA(int),EQ_Character__GetCachEQSPA);
#endif
#ifdef EQ_Container__EQ_Container
REVERSE_DETOUR( EQ_Container::EQ_Container(void),EQ_Container__EQ_Container);
#endif
#ifdef EQ_Container__dEQ_Container
REVERSE_DETOUR( EQ_Container::~EQ_Container(void),EQ_Container__dEQ_Container);
#endif
#ifdef EQ_Container__Open
REVERSE_DETOUR(unsigned char  EQ_Container::Open(void),EQ_Container__Open);
#endif
#ifdef EQ_Container__Close
REVERSE_DETOUR(unsigned char  EQ_Container::Close(void),EQ_Container__Close);
#endif
#ifdef EQ_Container__IsOpen
REVERSE_DETOUR(unsigned char  EQ_Container::IsOpen(void),EQ_Container__IsOpen);
#endif
#ifdef EQ_Equipment__EQ_Equipment
REVERSE_DETOUR( EQ_Equipment::EQ_Equipment(void),EQ_Equipment__EQ_Equipment);
#endif
#ifdef EQ_Equipment__IsWeapon
REVERSE_DETOUR(int  EQ_Equipment::IsWeapon(void),EQ_Equipment__IsWeapon);
#endif
#ifdef EQ_Equipment__IsInstrument
REVERSE_DETOUR(int  EQ_Equipment::IsInstrument(void),EQ_Equipment__IsInstrument);
#endif
#ifdef EQ_Equipment__SendTextRequestMsg
REVERSE_DETOUR(void  EQ_Equipment::SendTextRequestMsg(void),EQ_Equipment__SendTextRequestMsg);
#endif
#ifdef EQ_Item__Platinum
REVERSE_DETOUR(int  EQ_Item::Platinum(void),EQ_Item__Platinum);
#endif
#ifdef EQ_Item__Gold
REVERSE_DETOUR(int  EQ_Item::Gold(void),EQ_Item__Gold);
#endif
#ifdef EQ_Item__Silver
REVERSE_DETOUR(int  EQ_Item::Silver(void),EQ_Item__Silver);
#endif
#ifdef EQ_Item__Copper
REVERSE_DETOUR(int  EQ_Item::Copper(void),EQ_Item__Copper);
#endif
#ifdef EQ_Item__ValueSellMerchant
REVERSE_DETOUR(long  EQ_Item::ValueSellMerchant(float,long),EQ_Item__ValueSellMerchant);
#endif
#ifdef EQ_Item__ValueSSell
REVERSE_DETOUR(char *  EQ_Item::ValueSSell(float,long),EQ_Item__ValueSSell);
#endif
#ifdef EQ_Item__ValueSBuy
REVERSE_DETOUR(char *  EQ_Item::ValueSBuy(float,long),EQ_Item__ValueSBuy);
#endif
#ifdef EQ_Item__ValueSRent
REVERSE_DETOUR(char *  EQ_Item::ValueSRent(void),EQ_Item__ValueSRent);
#endif
#ifdef EQ_Item__IsSpecialNoDrop
REVERSE_DETOUR(bool  EQ_Item::IsSpecialNoDrop(void),EQ_Item__IsSpecialNoDrop);
#endif
#ifdef EQ_LoadingS__EQ_LoadingS
REVERSE_DETOUR( EQ_LoadingS::EQ_LoadingS(void),EQ_LoadingS__EQ_LoadingS);
#endif
#ifdef EQ_LoadingS__dEQ_LoadingS
REVERSE_DETOUR( EQ_LoadingS::~EQ_LoadingS(void),EQ_LoadingS__dEQ_LoadingS);
#endif
#ifdef EQ_LoadingS__DrawBackground
REVERSE_DETOUR(void  EQ_LoadingS::DrawBackground(struct T3D_XYZ *),EQ_LoadingS__DrawBackground);
#endif
#ifdef EQ_LoadingS__draw
REVERSE_DETOUR(void  EQ_LoadingS::draw(void),EQ_LoadingS__draw);
#endif
#ifdef EQ_LoadingS__WriteTextHD
REVERSE_DETOUR(void  EQ_LoadingS::WriteTextHD(char *,int,int,int),EQ_LoadingS__WriteTextHD);
#endif
#ifdef EQ_LoadingS__SetProgressBar
REVERSE_DETOUR(void  EQ_LoadingS::SetProgressBar(int,char const *),EQ_LoadingS__SetProgressBar);
#endif
#ifdef EQ_Note__EQ_Note
REVERSE_DETOUR( EQ_Note::EQ_Note(void),EQ_Note__EQ_Note);
#endif
#ifdef EQ_Note__SendTextRequestMsg
REVERSE_DETOUR(void  EQ_Note::SendTextRequestMsg(void),EQ_Note__SendTextRequestMsg);
#endif
#ifdef EQ_PC__EQ_PC
REVERSE_DETOUR( EQ_PC::EQ_PC(class EQ_PC *),EQ_PC__EQ_PC);
#endif
#ifdef EQ_PC__dEQ_PC
REVERSE_DETOUR( EQ_PC::~EQ_PC(void),EQ_PC__dEQ_PC);
#endif
#ifdef EQ_PC__ClearSharedVault
REVERSE_DETOUR(void  EQ_PC::ClearSharedVault(void),EQ_PC__ClearSharedVault);
#endif
#ifdef EQ_PC__IsAGroupMember
REVERSE_DETOUR(int  EQ_PC::IsAGroupMember(char *),EQ_PC__IsAGroupMember);
#endif
#ifdef EQ_PC__CheckForGroupChanges
REVERSE_DETOUR(void  EQ_PC::CheckForGroupChanges(void),EQ_PC__CheckForGroupChanges);
#endif
#ifdef EQ_PC__UnpackMyNetPC
REVERSE_DETOUR(void  EQ_PC::UnpackMyNetPC(char *,int),EQ_PC__UnpackMyNetPC);
#endif
#ifdef EQ_PC__InitPlayerStart
REVERSE_DETOUR(void  EQ_PC::InitPlayerStart(unsigned int,unsigned char,int),EQ_PC__InitPlayerStart);
#endif
#ifdef EQ_PC__EmptyPossessionSlots
REVERSE_DETOUR(void  EQ_PC::EmptyPossessionSlots(void),EQ_PC__EmptyPossessionSlots);
#endif
#ifdef EQ_PC__RefreshMe
REVERSE_DETOUR(void  EQ_PC::RefreshMe(int),EQ_PC__RefreshMe);
#endif
#ifdef EQ_PC__PrepareForRepop
REVERSE_DETOUR(void  EQ_PC::PrepareForRepop(int),EQ_PC__PrepareForRepop);
#endif
#ifdef EQ_PC__RefitNewbieEQ
REVERSE_DETOUR(void  EQ_PC::RefitNewbieEQ(void),EQ_PC__RefitNewbieEQ);
#endif
#ifdef EQ_PC__RemoveMyAffect
REVERSE_DETOUR(unsigned char  EQ_PC::RemoveMyAffect(int),EQ_PC__RemoveMyAffect);
#endif
#ifdef EQ_PC__ProcessFatigue
REVERSE_DETOUR(void  EQ_PC::ProcessFatigue(void),EQ_PC__ProcessFatigue);
#endif
#ifdef EQ_PC__DelLoreItemDup
REVERSE_DETOUR(int  EQ_PC::DelLoreItemDup(int,int,int,class EQ_Item *),EQ_PC__DelLoreItemDup);
#endif
#ifdef EQ_PC__CheckDupLoreItems
REVERSE_DETOUR(int  EQ_PC::CheckDupLoreItems(void),EQ_PC__CheckDupLoreItems);
#endif
#ifdef EQ_PC__CostToTrain
REVERSE_DETOUR(int  EQ_PC::CostToTrain(int,float,int),EQ_PC__CostToTrain);
#endif
#ifdef EQ_PC__checkLang
REVERSE_DETOUR(int  EQ_PC::checkLang(int),EQ_PC__checkLang);
#endif
#ifdef EQ_PC__BitchCanTrain
REVERSE_DETOUR(int  EQ_PC::BitchCanTrain(int,int,int),EQ_PC__BitchCanTrain);
#endif
#ifdef EQ_PC__HandleMoney
REVERSE_DETOUR(int  EQ_PC::HandleMoney(long),EQ_PC__HandleMoney);
#endif
#ifdef EQ_PC__DetermineQuestExpGained
REVERSE_DETOUR(void  EQ_PC::DetermineQuestExpGained(int),EQ_PC__DetermineQuestExpGained);
#endif
#ifdef EQ_PC__ProcessAirSupply
REVERSE_DETOUR(void  EQ_PC::ProcessAirSupply(void),EQ_PC__ProcessAirSupply);
#endif
#ifdef EQ_PC__MaxAirSupply
REVERSE_DETOUR(int  EQ_PC::MaxAirSupply(void),EQ_PC__MaxAirSupply);
#endif
#ifdef EQ_PC__SetFatigue
REVERSE_DETOUR(void  EQ_PC::SetFatigue(int),EQ_PC__SetFatigue);
#endif
#ifdef EQ_PC__numInParty
REVERSE_DETOUR(int  EQ_PC::numInParty(void),EQ_PC__numInParty);
#endif
#ifdef EQ_PC__AtSkillLimit
REVERSE_DETOUR(unsigned char  EQ_PC::AtSkillLimit(int),EQ_PC__AtSkillLimit);
#endif
#ifdef CInvSlot__HandleLButtonDown
REVERSE_DETOUR(void  CInvSlot::HandleLButtonDown(class CXPoint),CInvSlot__HandleLButtonDown);
#endif
#ifdef CInvSlot__HandleLButtonUpAfterHeld
REVERSE_DETOUR(void  CInvSlot::HandleLButtonUpAfterHeld(class CXPoint),CInvSlot__HandleLButtonUpAfterHeld);
#endif
#ifdef CInvSlot__HandleRButtonDown
REVERSE_DETOUR(void  CInvSlot::HandleRButtonDown(class CXPoint),CInvSlot__HandleRButtonDown);
#endif
#ifdef EQ_PC__CheckForLanguageImprovement
REVERSE_DETOUR(void  EQ_PC::CheckForLanguageImprovement(unsigned char,unsigned char),EQ_PC__CheckForLanguageImprovement);
#endif
#ifdef EQ_PC__CheckSkillImprove
REVERSE_DETOUR(void  EQ_PC::CheckSkillImprove(int,float),EQ_PC__CheckSkillImprove);
#endif
#ifdef EQ_PC__GetBodyTint
REVERSE_DETOUR(unsigned long  EQ_PC::GetBodyTint(int),EQ_PC__GetBodyTint);
#endif
#ifdef EQ_PC__GetArmorTint
REVERSE_DETOUR(unsigned long  EQ_PC::GetArmorTint(int),EQ_PC__GetArmorTint);
#endif
#ifdef EQ_PC__SetArmorTint
REVERSE_DETOUR(void  EQ_PC::SetArmorTint(int,unsigned long),EQ_PC__SetArmorTint);
#endif
#ifdef EQ_PC__GetArmorType
REVERSE_DETOUR(int  EQ_PC::GetArmorType(int),EQ_PC__GetArmorType);
#endif
#ifdef EQ_PC__SetArmorType
REVERSE_DETOUR(void  EQ_PC::SetArmorType(int,int),EQ_PC__SetArmorType);
#endif
#ifdef EQ_PC__InitializeNewPCVariables
REVERSE_DETOUR(void  EQ_PC::InitializeNewPCVariables(int),EQ_PC__InitializeNewPCVariables);
#endif
#ifdef EQ_PC__DestroyHeldItemOrMoney
REVERSE_DETOUR(void  EQ_PC::DestroyHeldItemOrMoney(void),EQ_PC__DestroyHeldItemOrMoney);
#endif
#ifdef EQ_Skill__EQ_Skill
REVERSE_DETOUR( EQ_Skill::EQ_Skill(int),EQ_Skill__EQ_Skill);
#endif
#ifdef EqSoundManager__EqSoundManager
//REVERSE_DETOUR( EqSoundManager::EqSoundManager(bool,bool,enum SpeakerType),EqSoundManager__EqSoundManager);
#endif
#ifdef EqSoundManager__dEqSoundManager
REVERSE_DETOUR( EqSoundManager::~EqSoundManager(void),EqSoundManager__dEqSoundManager);
#endif
#ifdef EqSoundManager__LoadGlobalEmitters
REVERSE_DETOUR(void  EqSoundManager::LoadGlobalEmitters(void),EqSoundManager__LoadGlobalEmitters);
#endif
#ifdef EqSoundManager__GetMusicId
REVERSE_DETOUR(int  EqSoundManager::GetMusicId(void),EqSoundManager__GetMusicId);
#endif
#ifdef EqSoundManager__LoadGlobalWaves
REVERSE_DETOUR(void  EqSoundManager::LoadGlobalWaves(void),EqSoundManager__LoadGlobalWaves);
#endif
#ifdef EqSoundManager__LoadListOfWaveFiles
REVERSE_DETOUR(void  EqSoundManager::LoadListOfWaveFiles(char * *,int),EqSoundManager__LoadListOfWaveFiles);
#endif
#ifdef EqSoundManager__WaveLoad
REVERSE_DETOUR(void  EqSoundManager::WaveLoad(char *,int,bool),EqSoundManager__WaveLoad);
#endif
#ifdef EqSoundManager__WaveIsPlaying
REVERSE_DETOUR(bool  EqSoundManager::WaveIsPlaying(int),EqSoundManager__WaveIsPlaying);
#endif
#ifdef EqSoundManager__WavePlay
REVERSE_DETOUR(void  EqSoundManager::WavePlay(int,class SoundControl *),EqSoundManager__WavePlay);
#endif
#ifdef EqSoundManager__WaveStop
REVERSE_DETOUR(void  EqSoundManager::WaveStop(int),EqSoundManager__WaveStop);
#endif
#ifdef EqSoundManager__WaveGet
REVERSE_DETOUR(class SoundAsset *  EqSoundManager::WaveGet(int),EqSoundManager__WaveGet);
#endif
#ifdef EqSoundManager__LoadGlobalMusic
REVERSE_DETOUR(void  EqSoundManager::LoadGlobalMusic(void),EqSoundManager__LoadGlobalMusic);
#endif
#ifdef EqSoundManager__SetMusicSelection
REVERSE_DETOUR(void  EqSoundManager::SetMusicSelection(int,bool),EqSoundManager__SetMusicSelection);
#endif
#ifdef EqSoundManager__GiveTime
REVERSE_DETOUR(void  EqSoundManager::GiveTime(void),EqSoundManager__GiveTime);
#endif
#ifdef EqSoundManager__SetCurrentZone
REVERSE_DETOUR(void  EqSoundManager::SetCurrentZone(char *),EqSoundManager__SetCurrentZone);
#endif
#ifdef FilePath__FilePath
REVERSE_DETOUR( FilePath::FilePath(char const *),FilePath__FilePath);
#endif
#ifdef ShareBase__removeRef
REVERSE_DETOUR(void  ShareBase::removeRef(void),ShareBase__removeRef);
#endif
#ifdef SharedString__SharedString
REVERSE_DETOUR( SharedString::SharedString(char const *),SharedString__SharedString);
#endif
#ifdef SharedString__operator_equal
REVERSE_DETOUR(class SharedString &  SharedString::operator=(class SharedString const &),SharedString__operator_equal);
#endif
#ifdef FilePath__dFilePath
REVERSE_DETOUR( FilePath::~FilePath(void),FilePath__dFilePath);
#endif
#ifdef SharedString__dSharedString
REVERSE_DETOUR( SharedString::~SharedString(void),SharedString__dSharedString);
#endif
#ifdef FilePath__FilePath1
REVERSE_DETOUR( FilePath::FilePath(class SharedString const &),FilePath__FilePath1);
#endif
#ifdef EqSoundManager__LoadOldEmitters
REVERSE_DETOUR(void  EqSoundManager::LoadOldEmitters(void),EqSoundManager__LoadOldEmitters);
#endif
#ifdef EqSoundManager__CreateOldEmitter
//REVERSE_DETOUR(class SoundEmitter *  EqSoundManager::CreateOldEmitter(int,float,float,float,int,int,int,float,int,int,int),EqSoundManager__CreateOldEmitter);
#endif
#ifdef EqSoundManager__GetAsset
REVERSE_DETOUR(class SoundAsset *  EqSoundManager::GetAsset(char *),EqSoundManager__GetAsset);
#endif
#ifdef EqSoundManager__ReleaseZoneSpecificMidi
REVERSE_DETOUR(void  EqSoundManager::ReleaseZoneSpecificMidi(void),EqSoundManager__ReleaseZoneSpecificMidi);
#endif
#ifdef EqSoundManager__ReleaseZoneSpecificWaves
REVERSE_DETOUR(void  EqSoundManager::ReleaseZoneSpecificWaves(void),EqSoundManager__ReleaseZoneSpecificWaves);
#endif
#ifdef EqSoundManager__ReleaseZoneSpecificEmitters
REVERSE_DETOUR(void  EqSoundManager::ReleaseZoneSpecificEmitters(void),EqSoundManager__ReleaseZoneSpecificEmitters);
#endif
#ifdef EqSoundManager__SetEffectsLevel
REVERSE_DETOUR(void  EqSoundManager::SetEffectsLevel(float),EqSoundManager__SetEffectsLevel);
#endif
#ifdef EqSoundManager__SetMixAhead
REVERSE_DETOUR(void  EqSoundManager::SetMixAhead(int),EqSoundManager__SetMixAhead);
#endif
#ifdef EqSoundManager__SetWaveVolume
REVERSE_DETOUR(void  EqSoundManager::SetWaveVolume(float),EqSoundManager__SetWaveVolume);
#endif
#ifdef EqSoundManager__SetMusicVolume
REVERSE_DETOUR(void  EqSoundManager::SetMusicVolume(float),EqSoundManager__SetMusicVolume);
#endif
#ifdef EqSoundManager__GetListenerEnvironment
//REVERSE_DETOUR(enum EnvironmentType  EqSoundManager::GetListenerEnvironment(void),EqSoundManager__GetListenerEnvironment);
#endif
#ifdef EqSoundManager__SetListenerEnvironment
//REVERSE_DETOUR(void  EqSoundManager::SetListenerEnvironment(enum EnvironmentType),EqSoundManager__SetListenerEnvironment);
#endif
#ifdef EqSoundManager__SetListenerEnvironmentLow
REVERSE_DETOUR(void  EqSoundManager::SetListenerEnvironmentLow(void),EqSoundManager__SetListenerEnvironmentLow);
#endif
#ifdef EqSoundManager__SetListenerEnvironmentHigh
REVERSE_DETOUR(void  EqSoundManager::SetListenerEnvironmentHigh(void),EqSoundManager__SetListenerEnvironmentHigh);
#endif
#ifdef EqSoundManager__SetListenerEnvironmentOutside
REVERSE_DETOUR(void  EqSoundManager::SetListenerEnvironmentOutside(void),EqSoundManager__SetListenerEnvironmentOutside);
#endif
#ifdef EqSoundManager__SetListenerLocation
REVERSE_DETOUR(void  EqSoundManager::SetListenerLocation(float,float,float,float),EqSoundManager__SetListenerLocation);
#endif
#ifdef EqSoundManager__EmitterSetRaining
REVERSE_DETOUR(void  EqSoundManager::EmitterSetRaining(bool),EqSoundManager__EmitterSetRaining);
#endif
#ifdef EqSoundManager__EmitterSetWind
REVERSE_DETOUR(void  EqSoundManager::EmitterSetWind(bool),EqSoundManager__EmitterSetWind);
#endif
#ifdef EqSoundManager__EmitterSetNight
REVERSE_DETOUR(void  EqSoundManager::EmitterSetNight(bool),EqSoundManager__EmitterSetNight);
#endif
#ifdef EqSoundManager__EmitterSetUserDisabled
REVERSE_DETOUR(void  EqSoundManager::EmitterSetUserDisabled(bool),EqSoundManager__EmitterSetUserDisabled);
#endif
#ifdef EqSoundManager__EmitterSetIndoors
REVERSE_DETOUR(void  EqSoundManager::EmitterSetIndoors(bool),EqSoundManager__EmitterSetIndoors);
#endif
#ifdef EqSoundManager__UpdateEmitterStates
REVERSE_DETOUR(void  EqSoundManager::UpdateEmitterStates(void),EqSoundManager__UpdateEmitterStates);
#endif
#ifdef EqSoundManager__OldMp3ClearSelections
REVERSE_DETOUR(void  EqSoundManager::OldMp3ClearSelections(void),EqSoundManager__OldMp3ClearSelections);
#endif
#ifdef EqSoundManager__OldMp3Init
REVERSE_DETOUR(void  EqSoundManager::OldMp3Init(void),EqSoundManager__OldMp3Init);
#endif
#ifdef EqSoundManager__OldMp3Terminate
REVERSE_DETOUR(void  EqSoundManager::OldMp3Terminate(void),EqSoundManager__OldMp3Terminate);
#endif
#ifdef EqSoundManager__OldMp3GetSelection
REVERSE_DETOUR(class SoundAsset *  EqSoundManager::OldMp3GetSelection(int),EqSoundManager__OldMp3GetSelection);
#endif
#ifdef EqSoundManager__EmitterLoad
REVERSE_DETOUR(bool  EqSoundManager::EmitterLoad(char *),EqSoundManager__EmitterLoad);
#endif
#ifdef EqSoundManager__EmitterAdd
REVERSE_DETOUR(void  EqSoundManager::EmitterAdd(class EqEmitterData *),EqSoundManager__EmitterAdd);
#endif
#ifdef EqMobileEmitter__EqMobileEmitter
REVERSE_DETOUR( EqMobileEmitter::EqMobileEmitter(class EqSoundManager *),EqMobileEmitter__EqMobileEmitter);
#endif
#ifdef EqMobileEmitter__dEqMobileEmitter
REVERSE_DETOUR( EqMobileEmitter::~EqMobileEmitter(void),EqMobileEmitter__dEqMobileEmitter);
#endif
#ifdef EqMobileEmitter__Move
REVERSE_DETOUR(void  EqMobileEmitter::Move(float,float,float),EqMobileEmitter__Move);
#endif
#ifdef EqMobileEmitter__SetWave
REVERSE_DETOUR(void  EqMobileEmitter::SetWave(int,char *),EqMobileEmitter__SetWave);
#endif
#ifdef EqMobileEmitter__SetNpcHeight
REVERSE_DETOUR(void  EqMobileEmitter::SetNpcHeight(float),EqMobileEmitter__SetNpcHeight);
#endif
#ifdef EqEmitterData__EqEmitterData
REVERSE_DETOUR( EqEmitterData::EqEmitterData(void),EqEmitterData__EqEmitterData);
#endif
#ifdef EqEmitterData__SetLoadString
REVERSE_DETOUR(void  EqEmitterData::SetLoadString(char *),EqEmitterData__SetLoadString);
#endif
#ifdef EQ_Spell__SpellUsesDragonBreathEffect
REVERSE_DETOUR(int  EQ_Spell::SpellUsesDragonBreathEffect(void),EQ_Spell__SpellUsesDragonBreathEffect);
#endif
#ifdef EQ_Spell__EQ_Spell
REVERSE_DETOUR( EQ_Spell::EQ_Spell(char *),EQ_Spell__EQ_Spell);
#endif
#ifdef EQ_Spell__dEQ_Spell
REVERSE_DETOUR( EQ_Spell::~EQ_Spell(void),EQ_Spell__dEQ_Spell);
#endif
#ifdef EQ_Spell__IsSPAIgnoredByStacking
REVERSE_DETOUR(bool __cdecl EQ_Spell::IsSPAIgnoredByStacking(int),EQ_Spell__IsSPAIgnoredByStacking);
#endif
#ifdef EQ_Spell__SpellAffects
REVERSE_DETOUR(unsigned char  EQ_Spell::SpellAffects(int)const ,EQ_Spell__SpellAffects);
#endif
#ifdef EQ_Spell__IsPermIllusionSpell
REVERSE_DETOUR(int  EQ_Spell::IsPermIllusionSpell(void)const ,EQ_Spell__IsPermIllusionSpell);
#endif
#ifdef EQOldPlayerAnimation__InitAnimationData
REVERSE_DETOUR(void __cdecl EQOldPlayerAnimation::InitAnimationData(void),EQOldPlayerAnimation__InitAnimationData);
#endif
#ifdef EQOldPlayerAnimation__PlayAttachmentAnimationTracks
REVERSE_DETOUR(void  EQOldPlayerAnimation::PlayAttachmentAnimationTracks(int,int,bool,bool,float,bool,unsigned char),EQOldPlayerAnimation__PlayAttachmentAnimationTracks);
#endif
#ifdef EQOldPlayerAnimation__EQOldPlayerAnimation
REVERSE_DETOUR( EQOldPlayerAnimation::EQOldPlayerAnimation(class EQPlayer *),EQOldPlayerAnimation__EQOldPlayerAnimation);
#endif
#ifdef EQOldPlayerAnimation__InterruptCurrentAnimation
REVERSE_DETOUR(bool  EQOldPlayerAnimation::InterruptCurrentAnimation(int,unsigned char),EQOldPlayerAnimation__InterruptCurrentAnimation);
#endif
#ifdef EQOldPlayerAnimation__ChangeAttachmentAnimationTrackSpeeds
REVERSE_DETOUR(void  EQOldPlayerAnimation::ChangeAttachmentAnimationTrackSpeeds(bool,float),EQOldPlayerAnimation__ChangeAttachmentAnimationTrackSpeeds);
#endif
#ifdef EQOldPlayerAnimation__IsSocialAnimation
REVERSE_DETOUR(bool  EQOldPlayerAnimation::IsSocialAnimation(int),EQOldPlayerAnimation__IsSocialAnimation);
#endif
#ifdef EQOldPlayerAnimation__IsStandAnimation
REVERSE_DETOUR(bool  EQOldPlayerAnimation::IsStandAnimation(int),EQOldPlayerAnimation__IsStandAnimation);
#endif
#ifdef EQOldPlayerAnimation__IsIdleAnimation
REVERSE_DETOUR(bool  EQOldPlayerAnimation::IsIdleAnimation(int),EQOldPlayerAnimation__IsIdleAnimation);
#endif
#ifdef EQOldPlayerAnimation__AnimationIsAggressive
REVERSE_DETOUR(bool  EQOldPlayerAnimation::AnimationIsAggressive(int),EQOldPlayerAnimation__AnimationIsAggressive);
#endif
#ifdef EQAnimation__EQAnimation
REVERSE_DETOUR( EQAnimation::EQAnimation(void),EQAnimation__EQAnimation);
#endif
#ifdef EQPlayer__DoCamAi
REVERSE_DETOUR(void  EQPlayer::DoCamAi(void),EQPlayer__DoCamAi);
#endif
#ifdef CVector3__Normalize
REVERSE_DETOUR(void  CVector3::Normalize(void),CVector3__Normalize);
#endif
#ifdef CVector3__GetLength
REVERSE_DETOUR(float  CVector3::GetLength(void)const ,CVector3__GetLength);
#endif
#ifdef CVector3__NormalizeAndReturnLength
REVERSE_DETOUR(float  CVector3::NormalizeAndReturnLength(void),CVector3__NormalizeAndReturnLength);
#endif
#ifdef EQEffect__EQEffect
REVERSE_DETOUR( EQEffect::EQEffect(class EQEffect *,char *,int,struct _EQLOC *,class EQPlayer *,class EQMissile *,struct _EQRGB *,float,int,int,float,float),EQEffect__EQEffect);
#endif
#ifdef EQEffect__dEQEffect
REVERSE_DETOUR( EQEffect::~EQEffect(void),EQEffect__dEQEffect);
#endif
#ifdef CEverQuest__msgStartIcon
REVERSE_DETOUR(int  CEverQuest::msgStartIcon(void *),CEverQuest__msgStartIcon);
#endif
#ifdef CEverQuest__msgStartInotes
REVERSE_DETOUR(int  CEverQuest::msgStartInotes(void *),CEverQuest__msgStartInotes);
#endif
#ifdef CEverQuest__msgStartIeq
REVERSE_DETOUR(int  CEverQuest::msgStartIeq(void *),CEverQuest__msgStartIeq);
#endif
#ifdef CEverQuest__HandleItems
REVERSE_DETOUR(int  CEverQuest::HandleItems(void *,int),CEverQuest__HandleItems);
#endif
#ifdef CEverQuest__HandleWorldMessage
REVERSE_DETOUR(unsigned char  CEverQuest::HandleWorldMessage(struct connection_t *,unsigned __int32,char *,unsigned __int32),CEverQuest__HandleWorldMessage);
#endif
#ifdef EQHSprite__EQHSprite
REVERSE_DETOUR( EQHSprite::EQHSprite(char *,struct T3D_tagACTORINSTANCE *,class EQPlayer *),EQHSprite__EQHSprite);
#endif
#ifdef EQHSprite__dEQHSprite
REVERSE_DETOUR( EQHSprite::~EQHSprite(void),EQHSprite__dEQHSprite);
#endif
#ifdef EQHSprite__get_object
REVERSE_DETOUR(class EQHSprite *  EQHSprite::get_object(char *),EQHSprite__get_object);
#endif
#ifdef EQHSprite__GetAnimationTrackPtr
REVERSE_DETOUR(bool  EQHSprite::GetAnimationTrackPtr(char *,char *,int,int,unsigned char,int),EQHSprite__GetAnimationTrackPtr);
#endif
#ifdef EQItemList__EQItemList
REVERSE_DETOUR( EQItemList::EQItemList(void),EQItemList__EQItemList);
#endif
#ifdef EQItemList__dEQItemList
REVERSE_DETOUR( EQItemList::~EQItemList(void),EQItemList__dEQItemList);
#endif
#ifdef EQItemList__get_item
REVERSE_DETOUR(class EQItemList *  EQItemList::get_item(long),EQItemList__get_item);
#endif
#ifdef EQItemList__is_item_actor
REVERSE_DETOUR(class EQItemList *  EQItemList::is_item_actor(struct T3D_tagACTORINSTANCE *),EQItemList__is_item_actor);
#endif
#ifdef public_key__dpublic_key
REVERSE_DETOUR( public_key::~public_key(void),public_key__dpublic_key);
#endif
#ifdef public_key__public_key
REVERSE_DETOUR( public_key::public_key(void),public_key__public_key);
#endif
#ifdef PacketPackerManager__Initialize
REVERSE_DETOUR(void __cdecl PacketPackerManager::Initialize(void),PacketPackerManager__Initialize);
#endif
#ifdef EQMissile__EQMissile
REVERSE_DETOUR( EQMissile::EQMissile(class EQ_Equipment *,class EQPlayer *,class EQMissile *,char *,unsigned char,unsigned int),EQMissile__EQMissile);
#endif
#ifdef EQMissile__dEQMissile
REVERSE_DETOUR( EQMissile::~EQMissile(void),EQMissile__dEQMissile);
#endif
#ifdef EQMissile__CleanUpMyEffects
REVERSE_DETOUR(void  EQMissile::CleanUpMyEffects(void),EQMissile__CleanUpMyEffects);
#endif
#ifdef EQMissile__is_missile_actor
REVERSE_DETOUR(class EQMissile *  EQMissile::is_missile_actor(struct T3D_tagACTORINSTANCE *),EQMissile__is_missile_actor);
#endif
#ifdef EQMissile__HitActor
REVERSE_DETOUR(void  EQMissile::HitActor(struct T3D_tagACTORINSTANCE *,bool),EQMissile__HitActor);
#endif
#ifdef EQMissile__ProcessMissile
REVERSE_DETOUR(void  EQMissile::ProcessMissile(void),EQMissile__ProcessMissile);
#endif
#ifdef EQMissile__MissileAI
REVERSE_DETOUR(void  EQMissile::MissileAI(void),EQMissile__MissileAI);
#endif
#ifdef EQMoneyList__EQMoneyList
REVERSE_DETOUR( EQMoneyList::EQMoneyList(void),EQMoneyList__EQMoneyList);
#endif
#ifdef EQMoneyList__dEQMoneyList
REVERSE_DETOUR( EQMoneyList::~EQMoneyList(void),EQMoneyList__dEQMoneyList);
#endif
#ifdef EQMoneyList__get_money
REVERSE_DETOUR(class EQMoneyList *  EQMoneyList::get_money(long),EQMoneyList__get_money);
#endif
#ifdef CDisplay__MoveMissile
REVERSE_DETOUR(int  CDisplay::MoveMissile(class EQMissile *),CDisplay__MoveMissile);
#endif
#ifdef CDisplay__GetOnActor
REVERSE_DETOUR(void  CDisplay::GetOnActor(struct T3D_tagACTORINSTANCE *,class EQPlayer *),CDisplay__GetOnActor);
#endif
#ifdef EQPlayer__CanIFitHere
REVERSE_DETOUR(bool  EQPlayer::CanIFitHere(float,float,float),EQPlayer__CanIFitHere);
#endif
#ifdef EQPlayer__MovePlayer
REVERSE_DETOUR(int  EQPlayer::MovePlayer(void),EQPlayer__MovePlayer);
#endif
#ifdef bad_word_class__bad_word_class
REVERSE_DETOUR( bad_word_class::bad_word_class(char *),bad_word_class__bad_word_class);
#endif
#ifdef EQObject__EQObject
REVERSE_DETOUR( EQObject::EQObject(class EQObject *,class EQPlayer *,char *,char *),EQObject__EQObject);
#endif
#ifdef EQObject__dEQObject
REVERSE_DETOUR( EQObject::~EQObject(void),EQObject__dEQObject);
#endif
#ifdef EQPlayer__EQPlayer
REVERSE_DETOUR( EQPlayer::EQPlayer(class EQPlayer *,unsigned char,unsigned int,unsigned char,char *),EQPlayer__EQPlayer);
#endif
#ifdef EQPlayer__dEQPlayer
REVERSE_DETOUR( EQPlayer::~EQPlayer(void),EQPlayer__dEQPlayer);
#endif
#ifdef EQPlayer__ResetVariables
REVERSE_DETOUR(void  EQPlayer::ResetVariables(void),EQPlayer__ResetVariables);
#endif
#ifdef EQPlayer__do_change_form
REVERSE_DETOUR(void  EQPlayer::do_change_form(struct chngForm *),EQPlayer__do_change_form);
#endif
#ifdef EQPlayer__DisplayWeaponsAndArmor
REVERSE_DETOUR(void  EQPlayer::DisplayWeaponsAndArmor(void),EQPlayer__DisplayWeaponsAndArmor);
#endif
#ifdef EQPlayer__CleanUpTarget
REVERSE_DETOUR(void  EQPlayer::CleanUpTarget(void),EQPlayer__CleanUpTarget);
#endif
#ifdef EQPlayer__FollowPlayerAI
REVERSE_DETOUR(void  EQPlayer::FollowPlayerAI(void),EQPlayer__FollowPlayerAI);
#endif
#ifdef EQPlayer__TurnOffAutoFollow
REVERSE_DETOUR(void  EQPlayer::TurnOffAutoFollow(void),EQPlayer__TurnOffAutoFollow);
#endif
#ifdef EQPlayer__AimAtTarget
REVERSE_DETOUR(int  EQPlayer::AimAtTarget(class EQPlayer *,class EQMissile *),EQPlayer__AimAtTarget);
#endif
#ifdef EQPlayer__FacePlayer
REVERSE_DETOUR(void  EQPlayer::FacePlayer(class EQPlayer *),EQPlayer__FacePlayer);
#endif
#ifdef EQPlayer__CleanUpVehicle
REVERSE_DETOUR(void  EQPlayer::CleanUpVehicle(void),EQPlayer__CleanUpVehicle);
#endif
#ifdef EQPlayer__CleanUpMyEffects
REVERSE_DETOUR(void  EQPlayer::CleanUpMyEffects(void),EQPlayer__CleanUpMyEffects);
#endif
#ifdef EQPlayer__GetPlayerFromName
REVERSE_DETOUR(class EQPlayer *__cdecl EQPlayer::GetPlayerFromName(char const *),EQPlayer__GetPlayerFromName);
#endif
#ifdef EQPlayer__GetPlayerFromPartialName
REVERSE_DETOUR(class EQPlayer * __cdecl EQPlayer::GetPlayerFromPartialName(char *),EQPlayer__GetPlayerFromPartialName);
#endif
#ifdef EQPlayer__GetClosestPlayerFromPartialName
REVERSE_DETOUR(class EQPlayer * __cdecl EQPlayer::GetClosestPlayerFromPartialName(char *,class EQPlayer *),EQPlayer__GetClosestPlayerFromPartialName);
#endif
#ifdef EQPlayer__IsPlayerActor
REVERSE_DETOUR(class EQPlayer * __cdecl EQPlayer::IsPlayerActor(struct T3D_tagACTORINSTANCE *),EQPlayer__IsPlayerActor);
#endif
#ifdef EQPlayer__TackOnNeuterChar
REVERSE_DETOUR(void __cdecl EQPlayer::TackOnNeuterChar(char *,unsigned int),EQPlayer__TackOnNeuterChar);
#endif
#ifdef EQPlayer__GetActorTag
REVERSE_DETOUR(void  EQPlayer::GetActorTag(char *),EQPlayer__GetActorTag);
#endif
#ifdef EQPlayer__GetPCActorTag
REVERSE_DETOUR(void __cdecl EQPlayer::GetPCActorTag(char *,unsigned int,unsigned char),EQPlayer__GetPCActorTag);
#endif
#ifdef EQPlayer__NotOnSameDeity
REVERSE_DETOUR(int  EQPlayer::NotOnSameDeity(class EQPlayer *,class EQ_Spell *),EQPlayer__NotOnSameDeity);
#endif
#ifdef EQPlayer__SetAnimVariation
REVERSE_DETOUR(void  EQPlayer::SetAnimVariation(void),EQPlayer__SetAnimVariation);
#endif
#ifdef EQPlayer__SetAfk
REVERSE_DETOUR(void  EQPlayer::SetAfk(int),EQPlayer__SetAfk);
#endif
#ifdef EQPlayer__AllowedToAttack
REVERSE_DETOUR(bool  EQPlayer::AllowedToAttack(class EQPlayer *,int),EQPlayer__AllowedToAttack);
#endif
#ifdef EQPlayer__CanIHit
REVERSE_DETOUR(bool  EQPlayer::CanIHit(class EQPlayer *,float),EQPlayer__CanIHit);
#endif
#ifdef EQPlayer__ModifyAttackSpeed
REVERSE_DETOUR(unsigned int  EQPlayer::ModifyAttackSpeed(unsigned int,int),EQPlayer__ModifyAttackSpeed);
#endif
#ifdef EQPlayer__DoAttack
REVERSE_DETOUR(int  EQPlayer::DoAttack(unsigned char,unsigned char,class EQPlayer *),EQPlayer__DoAttack);
#endif
#ifdef EQPlayer__HandleAmmo
REVERSE_DETOUR(unsigned char  EQPlayer::HandleAmmo(void),EQPlayer__HandleAmmo);
#endif
#ifdef EQPlayer__TriggerSpellEffect
REVERSE_DETOUR(void  EQPlayer::TriggerSpellEffect(struct _EQMissileHitinfo *),EQPlayer__TriggerSpellEffect);
#endif
#ifdef EQPlayer__IWasHit
REVERSE_DETOUR(bool  EQPlayer::IWasHit(struct _EQMissileHitinfo *),EQPlayer__IWasHit);
#endif
#ifdef EQPlayer__GetConscious
REVERSE_DETOUR(void  EQPlayer::GetConscious(void),EQPlayer__GetConscious);
#endif
#ifdef EQPlayer__KnockedOut
REVERSE_DETOUR(void  EQPlayer::KnockedOut(void),EQPlayer__KnockedOut);
#endif
#ifdef EQPlayer__IDied
REVERSE_DETOUR(void  EQPlayer::IDied(struct _EQPlayerDeath *),EQPlayer__IDied);
#endif
#ifdef EQPlayer__HandoverControlToZoneserver
REVERSE_DETOUR(void  EQPlayer::HandoverControlToZoneserver(void),EQPlayer__HandoverControlToZoneserver);
#endif
#ifdef EQPlayer__TouchingSwitch
REVERSE_DETOUR(void  EQPlayer::TouchingSwitch(void),EQPlayer__TouchingSwitch);
#endif
#ifdef EQPlayer__MyFeetAreOnGround
REVERSE_DETOUR(bool  EQPlayer::MyFeetAreOnGround(void),EQPlayer__MyFeetAreOnGround);
#endif
#ifdef EQPlayer__IHaveFallen
REVERSE_DETOUR(void  EQPlayer::IHaveFallen(float),EQPlayer__IHaveFallen);
#endif
#ifdef EQPlayer__SkillUsed
REVERSE_DETOUR(unsigned char  EQPlayer::SkillUsed(unsigned char),EQPlayer__SkillUsed);
#endif
#ifdef EQPlayer__BodyEnvironmentChange
REVERSE_DETOUR(void  EQPlayer::BodyEnvironmentChange(unsigned char),EQPlayer__BodyEnvironmentChange);
#endif
#ifdef EQPlayer__FeetEnvironmentChange
REVERSE_DETOUR(void  EQPlayer::FeetEnvironmentChange(unsigned char),EQPlayer__FeetEnvironmentChange);
#endif
#ifdef EQPlayer__HeadEnvironmentChange
REVERSE_DETOUR(void  EQPlayer::HeadEnvironmentChange(unsigned char),EQPlayer__HeadEnvironmentChange);
#endif
#ifdef EQPlayer__LegalPlayerRace
REVERSE_DETOUR(int  EQPlayer::LegalPlayerRace(int),EQPlayer__LegalPlayerRace);
#endif
#ifdef EQPlayer__DeleteMyMissiles
REVERSE_DETOUR(void  EQPlayer::DeleteMyMissiles(void),EQPlayer__DeleteMyMissiles);
#endif
#ifdef EQPlayer__ChangePosition
REVERSE_DETOUR(void  EQPlayer::ChangePosition(unsigned char),EQPlayer__ChangePosition);
#endif
#ifdef EQPlayer__ChangeHeight
REVERSE_DETOUR(void  EQPlayer::ChangeHeight(float),EQPlayer__ChangeHeight);
#endif
#ifdef EQPlayer__PositionOnFloor
REVERSE_DETOUR(void  EQPlayer::PositionOnFloor(void),EQPlayer__PositionOnFloor);
#endif
#ifdef EQPlayer__IsRoleplaying
REVERSE_DETOUR(bool  EQPlayer::IsRoleplaying(void),EQPlayer__IsRoleplaying);
#endif
#ifdef EQPlayer__IsInvited
REVERSE_DETOUR(bool  EQPlayer::IsInvited(void),EQPlayer__IsInvited);
#endif
#ifdef EQPlayer__SetInvited
REVERSE_DETOUR(void  EQPlayer::SetInvited(bool),EQPlayer__SetInvited);
#endif
#ifdef EQPlayer__PlaySoundA
REVERSE_DETOUR(void  EQPlayer::PlaySoundA(int),EQPlayer__PlaySoundA);
#endif
#ifdef EQPlayer__SetSounds
REVERSE_DETOUR(void  EQPlayer::SetSounds(void),EQPlayer__SetSounds);
#endif
#ifdef EQPlayer__SetCurrentLoopSound
REVERSE_DETOUR(void  EQPlayer::SetCurrentLoopSound(int),EQPlayer__SetCurrentLoopSound);
#endif
#ifdef EQPlayer__IsFlyer
REVERSE_DETOUR(bool  EQPlayer::IsFlyer(void),EQPlayer__IsFlyer);
#endif
#ifdef EQPlayer__InitSneakMod
REVERSE_DETOUR(void  EQPlayer::InitSneakMod(void),EQPlayer__InitSneakMod);
#endif
#ifdef EQPlayer__SetHeights
REVERSE_DETOUR(void  EQPlayer::SetHeights(void),EQPlayer__SetHeights);
#endif
#ifdef EQPMInfo__SetApplyGravity
REVERSE_DETOUR(void  EQPMInfo::SetApplyGravity(bool),EQPMInfo__SetApplyGravity);
#endif
#ifdef EQPlayer__GetDefaultHeight
REVERSE_DETOUR(float  EQPlayer::GetDefaultHeight(int,unsigned char),EQPlayer__GetDefaultHeight);
#endif
#ifdef EQPlayer__ComputeSpecialHeights
REVERSE_DETOUR(void __cdecl EQPlayer::ComputeSpecialHeights(int,float *,float *,float *,float *,bool),EQPlayer__ComputeSpecialHeights);
#endif
#ifdef EQPlayer__IsUntexturedHorse
REVERSE_DETOUR(bool  EQPlayer::IsUntexturedHorse(void),EQPlayer__IsUntexturedHorse);
#endif
#ifdef EQPlayer__HasInvalidRiderTexture
REVERSE_DETOUR(bool const  EQPlayer::HasInvalidRiderTexture(void)const ,EQPlayer__HasInvalidRiderTexture);
#endif
#ifdef EQPlayer__ForceInvisible
REVERSE_DETOUR(void  EQPlayer::ForceInvisible(bool),EQPlayer__ForceInvisible);
#endif
#ifdef EQPlayer__MountableRace
REVERSE_DETOUR(int  EQPlayer::MountableRace(void),EQPlayer__MountableRace);
#endif
#ifdef EQPlayer__MakeRiderMountUp
REVERSE_DETOUR(void  EQPlayer::MakeRiderMountUp(void),EQPlayer__MakeRiderMountUp);
#endif
#ifdef EQPlayer__MountEQPlayer
REVERSE_DETOUR(void  EQPlayer::MountEQPlayer(class EQPlayer *),EQPlayer__MountEQPlayer);
#endif
#ifdef EQPlayer__Dismount
REVERSE_DETOUR(void  EQPlayer::Dismount(void),EQPlayer__Dismount);
#endif
#ifdef EQPlayer__GetArmorType
REVERSE_DETOUR(int  EQPlayer::GetArmorType(int),EQPlayer__GetArmorType);
#endif
#ifdef EQPlayer__SetArmorType
REVERSE_DETOUR(void  EQPlayer::SetArmorType(int,int),EQPlayer__SetArmorType);
#endif
#ifdef EQPlayer__GetArmorTint
REVERSE_DETOUR(unsigned long  EQPlayer::GetArmorTint(int),EQPlayer__GetArmorTint);
#endif
#ifdef EQPlayer__SetArmorTint
REVERSE_DETOUR(void  EQPlayer::SetArmorTint(int,unsigned long),EQPlayer__SetArmorTint);
#endif
#ifdef EQPlayer__SetAccel
REVERSE_DETOUR(void  EQPlayer::SetAccel(float,int),EQPlayer__SetAccel);
#endif
#ifdef EQPlayer__SetToRandomRace
REVERSE_DETOUR(void  EQPlayer::SetToRandomRace(void),EQPlayer__SetToRandomRace);
#endif
#ifdef EQPlayer__GetBaseFaceNbr
REVERSE_DETOUR(unsigned char  EQPlayer::GetBaseFaceNbr(int,unsigned char *),EQPlayer__GetBaseFaceNbr);
#endif
#ifdef EQPlayer__HasAttachedBeard
REVERSE_DETOUR(unsigned char  EQPlayer::HasAttachedBeard(void),EQPlayer__HasAttachedBeard);
#endif
#ifdef EQPlayer__HasAttachedHair
REVERSE_DETOUR(unsigned char  EQPlayer::HasAttachedHair(void),EQPlayer__HasAttachedHair);
#endif
#ifdef EQPlayer__SetDefaultFacialFeaturesByFace
REVERSE_DETOUR(void  EQPlayer::SetDefaultFacialFeaturesByFace(int,unsigned char,unsigned char),EQPlayer__SetDefaultFacialFeaturesByFace);
#endif
#ifdef EQPlayer__GetAllowedHairColorIndexRange
REVERSE_DETOUR(void  EQPlayer::GetAllowedHairColorIndexRange(int,int *,int *),EQPlayer__GetAllowedHairColorIndexRange);
#endif
#ifdef EQPlayer__CanBeBald
REVERSE_DETOUR(int  EQPlayer::CanBeBald(void),EQPlayer__CanBeBald);
#endif
#ifdef EQPlayer__ChangeNoGravity
REVERSE_DETOUR(void  EQPlayer::ChangeNoGravity(int),EQPlayer__ChangeNoGravity);
#endif
#ifdef EQPlayer__IdUsed
REVERSE_DETOUR(int  EQPlayer::IdUsed(unsigned int),EQPlayer__IdUsed);
#endif
#ifdef EQPlayer__GetUnusedID
REVERSE_DETOUR(unsigned int  EQPlayer::GetUnusedID(void),EQPlayer__GetUnusedID);
#endif
#ifdef EQPlayer__SetAndReserveID
REVERSE_DETOUR(void  EQPlayer::SetAndReserveID(unsigned int),EQPlayer__SetAndReserveID);
#endif
#ifdef EQPlayer__InitializeIDArray
REVERSE_DETOUR(void  EQPlayer::InitializeIDArray(void),EQPlayer__InitializeIDArray);
#endif
#ifdef EQPlayer__Levitating
REVERSE_DETOUR(int  EQPlayer::Levitating(void),EQPlayer__Levitating);
#endif
#ifdef EQPlayer__SetRace
REVERSE_DETOUR(void  EQPlayer::SetRace(int),EQPlayer__SetRace);
#endif
#ifdef EQPlayer__CanChangeForm
REVERSE_DETOUR(bool  EQPlayer::CanChangeForm(int,unsigned char),EQPlayer__CanChangeForm);
#endif
#ifdef EQPlayer__SetNameSpriteState
REVERSE_DETOUR(int  EQPlayer::SetNameSpriteState(bool),EQPlayer__SetNameSpriteState);
#endif
#ifdef EQPlayer__ChangeBoneStringSprite
REVERSE_DETOUR(struct S3D_STRINGSPRITE *  EQPlayer::ChangeBoneStringSprite(struct T3D_DAG *,char *),EQPlayer__ChangeBoneStringSprite);
#endif
#ifdef EQPlayer__SetNameSpriteTint
REVERSE_DETOUR(bool  EQPlayer::SetNameSpriteTint(void),EQPlayer__SetNameSpriteTint);
#endif
#ifdef EQPlayer__UpdateNameSprite
REVERSE_DETOUR(void  EQPlayer::UpdateNameSprite(void),EQPlayer__UpdateNameSprite);
#endif
#ifdef EQPlayer__UpdateBonePointers
REVERSE_DETOUR(void  EQPlayer::UpdateBonePointers(void),EQPlayer__UpdateBonePointers);
#endif
#ifdef EQPlayer__FindDefaultEyeMaterialIndexes
REVERSE_DETOUR(void  EQPlayer::FindDefaultEyeMaterialIndexes(void),EQPlayer__FindDefaultEyeMaterialIndexes);
#endif
#ifdef EQPlayer__CalcAnimLength
REVERSE_DETOUR(unsigned int  EQPlayer::CalcAnimLength(int),EQPlayer__CalcAnimLength);
#endif
#ifdef EQPlayer__GetAlternateTrackNumber
REVERSE_DETOUR(int  EQPlayer::GetAlternateTrackNumber(int,unsigned char *),EQPlayer__GetAlternateTrackNumber);
#endif
#ifdef EQPlayer__GetAlternateAnimVariation
REVERSE_DETOUR(unsigned char  EQPlayer::GetAlternateAnimVariation(int,unsigned char),EQPlayer__GetAlternateAnimVariation);
#endif
#ifdef EQPlayer__GetRaceSexITOffset
REVERSE_DETOUR(int  EQPlayer::GetRaceSexITOffset(void),EQPlayer__GetRaceSexITOffset);
#endif
#ifdef EQPlayer__UpdatePlayerVisibility
REVERSE_DETOUR(void  EQPlayer::UpdatePlayerVisibility(void),EQPlayer__UpdatePlayerVisibility);
#endif
#ifdef EQPlayer__UpdateAllPlayersVisibility
REVERSE_DETOUR(void __cdecl EQPlayer::UpdateAllPlayersVisibility(void),EQPlayer__UpdateAllPlayersVisibility);
#endif
#ifdef EQPlayer__SetEyeMaterial
REVERSE_DETOUR(int  EQPlayer::SetEyeMaterial(unsigned char,int),EQPlayer__SetEyeMaterial);
#endif
#ifdef EQPlayer__HideOrShowAttachedHair
REVERSE_DETOUR(void  EQPlayer::HideOrShowAttachedHair(void),EQPlayer__HideOrShowAttachedHair);
#endif
#ifdef EQPlayer__SetFHEB
REVERSE_DETOUR(int  EQPlayer::SetFHEB(unsigned char,unsigned char),EQPlayer__SetFHEB);
#endif
#ifdef EQPlayer__SetFHEB_Color
REVERSE_DETOUR(int  EQPlayer::SetFHEB_Color(unsigned char,unsigned char),EQPlayer__SetFHEB_Color);
#endif
#ifdef EQPlayer__SetHairOrBeard
REVERSE_DETOUR(int  EQPlayer::SetHairOrBeard(int),EQPlayer__SetHairOrBeard);
#endif
#ifdef EQPlayer__GetBonePointerByITS
REVERSE_DETOUR(struct T3D_DAG *  EQPlayer::GetBonePointerByITS(int,int),EQPlayer__GetBonePointerByITS);
#endif
#ifdef EQPlayer__UpdateAppearance
REVERSE_DETOUR(void  EQPlayer::UpdateAppearance(void),EQPlayer__UpdateAppearance);
#endif
#ifdef EQPlayer__SetDefaultITAttachments
REVERSE_DETOUR(void  EQPlayer::SetDefaultITAttachments(int),EQPlayer__SetDefaultITAttachments);
#endif
#ifdef EQPlayer__SwapMaterial
REVERSE_DETOUR(int  EQPlayer::SwapMaterial(int,int,int,int,unsigned char),EQPlayer__SwapMaterial);
#endif
#ifdef EQPlayer__SwapFace
REVERSE_DETOUR(int  EQPlayer::SwapFace(int,int),EQPlayer__SwapFace);
#endif
#ifdef EQPlayer__GetAttachedHelmITNum
REVERSE_DETOUR(int  EQPlayer::GetAttachedHelmITNum(int,int *),EQPlayer__GetAttachedHelmITNum);
#endif
#ifdef EQPlayer__SetPlayerConstantAmbient
REVERSE_DETOUR(void  EQPlayer::SetPlayerConstantAmbient(struct T3D_RGB *),EQPlayer__SetPlayerConstantAmbient);
#endif
#ifdef EQPlayer__SwapHead
REVERSE_DETOUR(int  EQPlayer::SwapHead(int,int,unsigned long,int),EQPlayer__SwapHead);
#endif
#ifdef EQPlayer__SetPlayerPitchType
REVERSE_DETOUR(int  EQPlayer::SetPlayerPitchType(void),EQPlayer__SetPlayerPitchType);
#endif
#ifdef EQPlayer__IsValidTeleport
REVERSE_DETOUR(int  EQPlayer::IsValidTeleport(float,float,float,float,float),EQPlayer__IsValidTeleport);
#endif
#ifdef EQPlayer__ReplaceSpecialCloakMaterials
REVERSE_DETOUR(int  EQPlayer::ReplaceSpecialCloakMaterials(void),EQPlayer__ReplaceSpecialCloakMaterials);
#endif
#ifdef EQPlayer__SwapBody
REVERSE_DETOUR(int  EQPlayer::SwapBody(int,int),EQPlayer__SwapBody);
#endif
#ifdef EQPlayer__HandleMaterialEx
REVERSE_DETOUR(void  EQPlayer::HandleMaterialEx(int,unsigned int,unsigned int,unsigned long,int),EQPlayer__HandleMaterialEx);
#endif
#ifdef EQPlayer__UpdateItemSlot
REVERSE_DETOUR(unsigned char  EQPlayer::UpdateItemSlot(unsigned char,char *,int),EQPlayer__UpdateItemSlot);
#endif
#ifdef EQPlayer__SwapNPCMaterials
REVERSE_DETOUR(int  EQPlayer::SwapNPCMaterials(void),EQPlayer__SwapNPCMaterials);
#endif
#ifdef EQPlayer__PutPlayerOnFloor
REVERSE_DETOUR(void  EQPlayer::PutPlayerOnFloor(void),EQPlayer__PutPlayerOnFloor);
#endif
#ifdef EQPlayer__CheckForUnderFloor
REVERSE_DETOUR(void  EQPlayer::CheckForUnderFloor(void),EQPlayer__CheckForUnderFloor);
#endif
#ifdef EQPlayer__DoFloorCheck
REVERSE_DETOUR(void  EQPlayer::DoFloorCheck(void),EQPlayer__DoFloorCheck);
#endif
#ifdef EQPlayer__DoSwimJump
REVERSE_DETOUR(void  EQPlayer::DoSwimJump(unsigned char),EQPlayer__DoSwimJump);
#endif
#ifdef EQPlayer__PushAlongHeading
REVERSE_DETOUR(void  EQPlayer::PushAlongHeading(float),EQPlayer__PushAlongHeading);
#endif
#ifdef EQPlayer__DoTeleport
REVERSE_DETOUR(unsigned char  EQPlayer::DoTeleport(char *,int),EQPlayer__DoTeleport);
#endif
#ifdef EQPlayer__DoTeleportB
//REVERSE_DETOUR(unsigned char  EQPlayer::DoTeleportB(int,float,float,float,float,char *,enum ZONE_REQ_REASON),EQPlayer__DoTeleportB);
#endif
#ifdef EQPlayer__ChangeLight
REVERSE_DETOUR(void  EQPlayer::ChangeLight(void),EQPlayer__ChangeLight);
#endif
#ifdef EQPlayer__GetBoneCoords
REVERSE_DETOUR(bool  EQPlayer::GetBoneCoords(struct T3D_DAG *,struct _EQLOC *),EQPlayer__GetBoneCoords);
#endif
#ifdef EQPlayer__CheckForJump
REVERSE_DETOUR(int  EQPlayer::CheckForJump(void),EQPlayer__CheckForJump);
#endif
#ifdef EQPlayer__GetPlayerFloorHeight
REVERSE_DETOUR(float  EQPlayer::GetPlayerFloorHeight(float,float,float,unsigned char),EQPlayer__GetPlayerFloorHeight);
#endif
#ifdef EQPlayer__UpdatePlayerActor
REVERSE_DETOUR(bool  EQPlayer::UpdatePlayerActor(void),EQPlayer__UpdatePlayerActor);
#endif
#ifdef EQPlayer__GetNearestActorTag
REVERSE_DETOUR(unsigned char  EQPlayer::GetNearestActorTag(char *,void *),EQPlayer__GetNearestActorTag);
#endif
#ifdef EQPlayer__DoItemSlot
REVERSE_DETOUR(void  EQPlayer::DoItemSlot(int),EQPlayer__DoItemSlot);
#endif
#ifdef EQPlayer__DoClassRandomAnimation
REVERSE_DETOUR(void  EQPlayer::DoClassRandomAnimation(void),EQPlayer__DoClassRandomAnimation);
#endif
#ifdef EQPlayer__CreateUserLight
REVERSE_DETOUR(struct T3D_POINTLIGHT *  EQPlayer::CreateUserLight(struct T3D_LIGHTDEFINITION *,int),EQPlayer__CreateUserLight);
#endif
#ifdef EQPlayer__AttachPlayerToPlayerBone
REVERSE_DETOUR(int  EQPlayer::AttachPlayerToPlayerBone(class EQPlayer *,struct T3D_DAG *),EQPlayer__AttachPlayerToPlayerBone);
#endif
#ifdef EQPlayer__IsInvisible
REVERSE_DETOUR(bool  EQPlayer::IsInvisible(class EQPlayer *),EQPlayer__IsInvisible);
#endif
#ifdef EQPlayer__IsAMount
REVERSE_DETOUR(bool  EQPlayer::IsAMount(void),EQPlayer__IsAMount);
#endif
#ifdef EQPMInfo__EQPMInfo
REVERSE_DETOUR( EQPMInfo::EQPMInfo(char *),EQPMInfo__EQPMInfo);
#endif
#ifdef EQPMInfo__dEQPMInfo
REVERSE_DETOUR( EQPMInfo::~EQPMInfo(void),EQPMInfo__dEQPMInfo);
#endif
#ifdef EQSwitch__EQSwitch
REVERSE_DETOUR( EQSwitch::EQSwitch(char *,bool),EQSwitch__EQSwitch);
#endif
#ifdef EQSwitch__EQSwitch1
REVERSE_DETOUR( EQSwitch::EQSwitch(struct OldDiskSwitch *,bool),EQSwitch__EQSwitch1);
#endif
#ifdef EQSwitch__EQSwitch2
REVERSE_DETOUR( EQSwitch::EQSwitch(struct _EQClientSwitch *),EQSwitch__EQSwitch2);
#endif
#ifdef EQSwitch__PreInit
REVERSE_DETOUR(void  EQSwitch::PreInit(void),EQSwitch__PreInit);
#endif
#ifdef EQSwitch__PostInit
REVERSE_DETOUR(void  EQSwitch::PostInit(void),EQSwitch__PostInit);
#endif
#ifdef EQSwitch__dEQSwitch
REVERSE_DETOUR( EQSwitch::~EQSwitch(void),EQSwitch__dEQSwitch);
#endif
#ifdef EQSwitch__ResetSwitchState
REVERSE_DETOUR(void  EQSwitch::ResetSwitchState(unsigned char),EQSwitch__ResetSwitchState);
#endif
#ifdef EQSwitch__RepopSwitch
REVERSE_DETOUR(void  EQSwitch::RepopSwitch(void),EQSwitch__RepopSwitch);
#endif
#ifdef EQSwitch__TopSpeed
REVERSE_DETOUR(float  EQSwitch::TopSpeed(float *),EQSwitch__TopSpeed);
#endif
#ifdef EQSwitch__RepopFrequency
REVERSE_DETOUR(unsigned int  EQSwitch::RepopFrequency(void),EQSwitch__RepopFrequency);
#endif
#ifdef EQSwitch__GetSwitchDamage
REVERSE_DETOUR(int  EQSwitch::GetSwitchDamage(void),EQSwitch__GetSwitchDamage);
#endif
#ifdef EQSwitch__ChangeState
REVERSE_DETOUR(void  EQSwitch::ChangeState(unsigned char,class EQPlayer *,bool),EQSwitch__ChangeState);
#endif
#ifdef EQSwitch__SwitchWasOpened
REVERSE_DETOUR(unsigned char  EQSwitch::SwitchWasOpened(int,int,class EQPlayer *,bool *),EQSwitch__SwitchWasOpened);
#endif
#ifdef EQSwitch__SwitchWasOpenedActual
REVERSE_DETOUR(unsigned char  EQSwitch::SwitchWasOpenedActual(int,int,class EQPlayer *,bool *),EQSwitch__SwitchWasOpenedActual);
#endif
#ifdef EQSwitch__SwitchIsNotUsable
REVERSE_DETOUR(unsigned char  EQSwitch::SwitchIsNotUsable(int),EQSwitch__SwitchIsNotUsable);
#endif
#ifdef EQSwitch__UseSwitch
REVERSE_DETOUR(void  EQSwitch::UseSwitch(unsigned int,int,int),EQSwitch__UseSwitch);
#endif
#ifdef EQSwitch__LoadSwitchSounds
REVERSE_DETOUR(void  EQSwitch::LoadSwitchSounds(int),EQSwitch__LoadSwitchSounds);
#endif
#ifdef EQSwitch__GetCustomMoveDistance
REVERSE_DETOUR(float  EQSwitch::GetCustomMoveDistance(void),EQSwitch__GetCustomMoveDistance);
#endif
#ifdef EqSwitchManager__EqSwitchManager
REVERSE_DETOUR( EqSwitchManager::EqSwitchManager(void),EqSwitchManager__EqSwitchManager);
#endif
#ifdef EqSwitchManager__dEqSwitchManager
REVERSE_DETOUR( EqSwitchManager::~EqSwitchManager(void),EqSwitchManager__dEqSwitchManager);
#endif
#ifdef EqSwitchManager__DeleteAll
REVERSE_DETOUR(void  EqSwitchManager::DeleteAll(void),EqSwitchManager__DeleteAll);
#endif
#ifdef EqSwitchManager__Load
REVERSE_DETOUR(void  EqSwitchManager::Load(char *,bool),EqSwitchManager__Load);
#endif
#ifdef EqSwitchManager__LoadOld
REVERSE_DETOUR(void  EqSwitchManager::LoadOld(char *,bool),EqSwitchManager__LoadOld);
#endif
#ifdef EqSwitchManager__GetCount
REVERSE_DETOUR(int  EqSwitchManager::GetCount(void),EqSwitchManager__GetCount);
#endif
#ifdef EqSwitchManager__GetSwitchByActor
REVERSE_DETOUR(class EQSwitch *  EqSwitchManager::GetSwitchByActor(struct T3D_tagACTORINSTANCE *),EqSwitchManager__GetSwitchByActor);
#endif
#ifdef EqSwitchManager__GetSwitch
REVERSE_DETOUR(class EQSwitch *  EqSwitchManager::GetSwitch(int),EqSwitchManager__GetSwitch);
#endif
#ifdef EqSwitchManager__GetSwitchById
REVERSE_DETOUR(class EQSwitch *  EqSwitchManager::GetSwitchById(int,bool),EqSwitchManager__GetSwitchById);
#endif
#ifdef EqSwitchManager__AddSwitch
REVERSE_DETOUR(void  EqSwitchManager::AddSwitch(class EQSwitch *),EqSwitchManager__AddSwitch);
#endif
#ifdef Util__GetNextToken
REVERSE_DETOUR(int __cdecl Util::GetNextToken(char *,int *,char *),Util__GetNextToken);
#endif
#ifdef Util__GetNextToken1
REVERSE_DETOUR(int __cdecl Util::GetNextToken(char *,short *,char *),Util__GetNextToken1);
#endif
#ifdef Util__GetNextToken2
REVERSE_DETOUR(int __cdecl Util::GetNextToken(char *,char *,char *),Util__GetNextToken2);
#endif
#ifdef Util__GetNextToken3
REVERSE_DETOUR(int __cdecl Util::GetNextToken(char *,unsigned char *,char *),Util__GetNextToken3);
#endif
#ifdef EQUtil__FormatCharName
REVERSE_DETOUR(char * __cdecl EQUtil::FormatCharName(char *,char *,int),EQUtil__FormatCharName);
#endif
#ifdef EQWorldData__EQWorldData
REVERSE_DETOUR( EQWorldData::EQWorldData(void),EQWorldData__EQWorldData);
#endif
#ifdef EQWorldData__AddZone
//REVERSE_DETOUR(bool const  EQWorldData::AddZone(enum EQExpansion,enum EQZoneIndex,char const *,char const *,int,unsigned long,int,int),EQWorldData__AddZone);
#endif
#ifdef EQWorldData__AdvanceTime
REVERSE_DETOUR(void  EQWorldData::AdvanceTime(unsigned int),EQWorldData__AdvanceTime);
#endif
#ifdef EQWorldData__CurrentGameTime
REVERSE_DETOUR(void  EQWorldData::CurrentGameTime(char *),EQWorldData__CurrentGameTime);
#endif
#ifdef EQWorldData__GetFullZoneName
//REVERSE_DETOUR(void  EQWorldData::GetFullZoneName(enum EQZoneIndex,char *),EQWorldData__GetFullZoneName);
#endif
#ifdef EQWorldData__ExpansionZone
//REVERSE_DETOUR(enum EQExpansion const  EQWorldData::ExpansionZone(enum EQZoneIndex)const ,EQWorldData__ExpansionZone);
#endif
#ifdef EQWorldData__IsFlagSet
//REVERSE_DETOUR(bool  EQWorldData::IsFlagSet(enum EQZoneIndex,unsigned long)const,EQWorldData__IsFlagSet);
#endif
#ifdef EQWorldData__IsNewbieZone
//REVERSE_DETOUR(bool  EQWorldData::IsNewbieZone(enum EQZoneIndex)const,EQWorldData__IsNewbieZone);
#endif
#ifdef EQWorldData__IsNoBindZone
//REVERSE_DETOUR(bool  EQWorldData::IsNoBindZone(enum EQZoneIndex)const,EQWorldData__IsNoBindZone);
#endif
#ifdef EQWorldData__IsNoAirZone
//REVERSE_DETOUR(bool  EQWorldData::IsNoAirZone(enum EQZoneIndex)const,EQWorldData__IsNoAirZone);
#endif
#ifdef EQWorldData__GetMinLevel
//REVERSE_DETOUR(int  EQWorldData::GetMinLevel(enum EQZoneIndex)const,EQWorldData__GetMinLevel);
#endif
#ifdef EQWorldData__GetGeometryNameFromIndex
//REVERSE_DETOUR(bool  EQWorldData::GetGeometryNameFromIndex(enum EQZoneIndex,char *)const ,EQWorldData__GetGeometryNameFromIndex);
#endif
#ifdef EQWorldData__GetIndexFromZoneName
//REVERSE_DETOUR(enum EQZoneIndex  EQWorldData::GetIndexFromZoneName(char const *)const ,EQWorldData__GetIndexFromZoneName);
#endif
#ifdef EQZoneInfo__EQZoneInfo
//REVERSE_DETOUR( EQZoneInfo::EQZoneInfo(enum EQExpansion,enum EQZoneIndex,char const *,char const *,int,unsigned long,int,int),EQZoneInfo__EQZoneInfo);
#endif
#ifdef CEverQuest__ChatServerGiveTime
REVERSE_DETOUR(void  CEverQuest::ChatServerGiveTime(void),CEverQuest__ChatServerGiveTime);
#endif
#ifdef CEverQuest__ChatServerNotificationAdd
REVERSE_DETOUR(void  CEverQuest::ChatServerNotificationAdd(bool,char *,char *,int),CEverQuest__ChatServerNotificationAdd);
#endif
#ifdef CEverQuest__ChatServerNotificationFlush
REVERSE_DETOUR(void  CEverQuest::ChatServerNotificationFlush(void),CEverQuest__ChatServerNotificationFlush);
#endif
#ifdef CEverQuest__ChatServerConnect
REVERSE_DETOUR(void  CEverQuest::ChatServerConnect(char *,int,char *,char *),CEverQuest__ChatServerConnect);
#endif
#ifdef CEverQuest__ChatServerMessage
REVERSE_DETOUR(void  CEverQuest::ChatServerMessage(char *),CEverQuest__ChatServerMessage);
#endif
#ifdef CEverQuest__ChatServerDisconnect
REVERSE_DETOUR(void  CEverQuest::ChatServerDisconnect(void),CEverQuest__ChatServerDisconnect);
#endif
#ifdef CEverQuest__ResetVisionRGBs
REVERSE_DETOUR(void  CEverQuest::ResetVisionRGBs(void),CEverQuest__ResetVisionRGBs);
#endif
#ifdef CEverQuest__GetMaxLightRadius
REVERSE_DETOUR(float  CEverQuest::GetMaxLightRadius(void),CEverQuest__GetMaxLightRadius);
#endif
#ifdef CEverQuest__LoadStringTables
REVERSE_DETOUR(void  CEverQuest::LoadStringTables(void),CEverQuest__LoadStringTables);
#endif
#ifdef CEverQuest__CEverQuest
REVERSE_DETOUR( CEverQuest::CEverQuest(struct HWND__ *),CEverQuest__CEverQuest);
#endif
#ifdef CEverQuest__dCEverQuest
REVERSE_DETOUR( CEverQuest::~CEverQuest(void),CEverQuest__dCEverQuest);
#endif
#ifdef CEverQuest__ProcessMBox
REVERSE_DETOUR(int  CEverQuest::ProcessMBox(void),CEverQuest__ProcessMBox);
#endif
#ifdef CEverQuest__UseCharge
REVERSE_DETOUR(void  CEverQuest::UseCharge(unsigned long),CEverQuest__UseCharge);
#endif
#ifdef CEverQuest__LeaveGuildMaster
REVERSE_DETOUR(void  CEverQuest::LeaveGuildMaster(void),CEverQuest__LeaveGuildMaster);
#endif
#ifdef CEverQuest__LeaveBankMode
REVERSE_DETOUR(void  CEverQuest::LeaveBankMode(bool),CEverQuest__LeaveBankMode);
#endif
#ifdef CEverQuest__ReportDeath
REVERSE_DETOUR(void  CEverQuest::ReportDeath(struct _EQPlayerDeath *),CEverQuest__ReportDeath);
#endif
#ifdef CEverQuest__SetDefaultDamageDescByRace
REVERSE_DETOUR(void  CEverQuest::SetDefaultDamageDescByRace(char *,int,unsigned char),CEverQuest__SetDefaultDamageDescByRace);
#endif
#ifdef CEverQuest__ReportSuccessfulHit
REVERSE_DETOUR(void  CEverQuest::ReportSuccessfulHit(struct _EQSuccessfulHit *,unsigned char,int),CEverQuest__ReportSuccessfulHit);
#endif
#ifdef CEverQuest__GetCombatSound
REVERSE_DETOUR(int  CEverQuest::GetCombatSound(class EQPlayer *,class EQPlayer *),CEverQuest__GetCombatSound);
#endif
#ifdef CEverQuest__LocalDeath
REVERSE_DETOUR(void  CEverQuest::LocalDeath(struct _EQPlayerDeath *,unsigned char),CEverQuest__LocalDeath);
#endif
#ifdef CEverQuest__PrepareLocalPCForRepop
REVERSE_DETOUR(void  CEverQuest::PrepareLocalPCForRepop(void),CEverQuest__PrepareLocalPCForRepop);
#endif
#ifdef CEverQuest__SavePCForce
REVERSE_DETOUR(void  CEverQuest::SavePCForce(int),CEverQuest__SavePCForce);
#endif
#ifdef CEverQuest__StartCasting
REVERSE_DETOUR(void  CEverQuest::StartCasting(void *),CEverQuest__StartCasting);
#endif
#ifdef CEverQuest__Consider
REVERSE_DETOUR(void  CEverQuest::Consider(class EQPlayer *,void *),CEverQuest__Consider);
#endif
#ifdef CEverQuest__GetClassDesc
REVERSE_DETOUR(char *  CEverQuest::GetClassDesc(int),CEverQuest__GetClassDesc);
#endif
#ifdef CEverQuest__GetClassThreeLetterCode
REVERSE_DETOUR(char *  CEverQuest::GetClassThreeLetterCode(int),CEverQuest__GetClassThreeLetterCode);
#endif
#ifdef CEverQuest__GetItemClassDesc
REVERSE_DETOUR(char *  CEverQuest::GetItemClassDesc(int),CEverQuest__GetItemClassDesc);
#endif
#ifdef CEverQuest__GetBodyTypeDesc
REVERSE_DETOUR(char *  CEverQuest::GetBodyTypeDesc(int),CEverQuest__GetBodyTypeDesc);
#endif
#ifdef CEverQuest__GetLangDesc
REVERSE_DETOUR(char *  CEverQuest::GetLangDesc(int),CEverQuest__GetLangDesc);
#endif
#ifdef CEverQuest__GetRaceDesc
REVERSE_DETOUR(char *  CEverQuest::GetRaceDesc(int),CEverQuest__GetRaceDesc);
#endif
#ifdef CEverQuest__GetDeityDesc
REVERSE_DETOUR(char *  CEverQuest::GetDeityDesc(int),CEverQuest__GetDeityDesc);
#endif
#ifdef CEverQuest__GetTitleDesc
REVERSE_DETOUR(char *  CEverQuest::GetTitleDesc(int,int,unsigned char),CEverQuest__GetTitleDesc);
#endif
#ifdef CEverQuest__GuildInvite
REVERSE_DETOUR(void  CEverQuest::GuildInvite(char *,char *),CEverQuest__GuildInvite);
#endif
#ifdef CEverQuest__GuildRemove
REVERSE_DETOUR(void  CEverQuest::GuildRemove(char *),CEverQuest__GuildRemove);
#endif
#ifdef CEverQuest__GuildDelete
REVERSE_DETOUR(void  CEverQuest::GuildDelete(void),CEverQuest__GuildDelete);
#endif
#ifdef CEverQuest__GuildStatus
REVERSE_DETOUR(void  CEverQuest::GuildStatus(char *),CEverQuest__GuildStatus);
#endif
#ifdef CEverQuest__GuildLeader
REVERSE_DETOUR(void  CEverQuest::GuildLeader(char *),CEverQuest__GuildLeader);
#endif
#ifdef CEverQuest__GuildSay
REVERSE_DETOUR(void  CEverQuest::GuildSay(char *),CEverQuest__GuildSay);
#endif
#ifdef CEverQuest__Who
REVERSE_DETOUR(void  CEverQuest::Who(char *),CEverQuest__Who);
#endif
#ifdef CEverQuest__GetInnateDesc
REVERSE_DETOUR(char *  CEverQuest::GetInnateDesc(int),CEverQuest__GetInnateDesc);
#endif
#ifdef CEverQuest__InviteOk
REVERSE_DETOUR(void  CEverQuest::InviteOk(char *),CEverQuest__InviteOk);
#endif
#ifdef CEverQuest__doUnInvite
REVERSE_DETOUR(void  CEverQuest::doUnInvite(char *),CEverQuest__doUnInvite);
#endif
#ifdef CEverQuest__Invite
REVERSE_DETOUR(void  CEverQuest::Invite(void),CEverQuest__Invite);
#endif
#ifdef CEverQuest__doInvite
REVERSE_DETOUR(void  CEverQuest::doInvite(unsigned __int32,char *),CEverQuest__doInvite);
#endif
#ifdef CEverQuest__Follow
REVERSE_DETOUR(void  CEverQuest::Follow(void),CEverQuest__Follow);
#endif
#ifdef CEverQuest__Disband
REVERSE_DETOUR(void  CEverQuest::Disband(void),CEverQuest__Disband);
#endif
#ifdef CEverQuest__GuildWar
REVERSE_DETOUR(void  CEverQuest::GuildWar(char *,int),CEverQuest__GuildWar);
#endif
#ifdef CEverQuest__GuildPeace
REVERSE_DETOUR(void  CEverQuest::GuildPeace(char *),CEverQuest__GuildPeace);
#endif
#ifdef CEverQuest__Sit
REVERSE_DETOUR(void  CEverQuest::Sit(void),CEverQuest__Sit);
#endif
#ifdef CEverQuest__Camp
REVERSE_DETOUR(void  CEverQuest::Camp(void),CEverQuest__Camp);
#endif
#ifdef CEverQuest__DropHeldItemOnGround
REVERSE_DETOUR(void  CEverQuest::DropHeldItemOnGround(int),CEverQuest__DropHeldItemOnGround);
#endif
#ifdef CEverQuest__MoveMoney
REVERSE_DETOUR(int  CEverQuest::MoveMoney(int,int,int,int,int,bool),CEverQuest__MoveMoney);
#endif
#ifdef CEverQuest__DropHeldMoneyOnGround
REVERSE_DETOUR(void  CEverQuest::DropHeldMoneyOnGround(int),CEverQuest__DropHeldMoneyOnGround);
#endif
#ifdef CEverQuest__LMouseUp
REVERSE_DETOUR(void  CEverQuest::LMouseUp(int,int),CEverQuest__LMouseUp);
#endif
#ifdef CEverQuest__LeftClickedOnPlayer
REVERSE_DETOUR(void  CEverQuest::LeftClickedOnPlayer(class EQPlayer *),CEverQuest__LeftClickedOnPlayer);
#endif
#ifdef CEverQuest__DropItemOrMoneyOnPlayer
REVERSE_DETOUR(void  CEverQuest::DropItemOrMoneyOnPlayer(class EQPlayer *),CEverQuest__DropItemOrMoneyOnPlayer);
#endif
#ifdef CEverQuest__RightClickedOnPlayer
REVERSE_DETOUR(void  CEverQuest::RightClickedOnPlayer(class EQPlayer *),CEverQuest__RightClickedOnPlayer);
#endif
#ifdef CEverQuest__send_social
REVERSE_DETOUR(void  CEverQuest::send_social(int,char *,char *),CEverQuest__send_social);
#endif
#ifdef CEverQuest__SavePC
REVERSE_DETOUR(void  CEverQuest::SavePC(int,int,unsigned char),CEverQuest__SavePC);
#endif
#ifdef CEverQuest__send_tell
REVERSE_DETOUR(void  CEverQuest::send_tell(char *,char *),CEverQuest__send_tell);
#endif
#ifdef CEverQuest__send_petition
REVERSE_DETOUR(void  CEverQuest::send_petition(void),CEverQuest__send_petition);
#endif
#ifdef CEverQuest__send_private
REVERSE_DETOUR(void  CEverQuest::send_private(void),CEverQuest__send_private);
#endif
#ifdef CEverQuest__WriteIntToClientINI
REVERSE_DETOUR(void  CEverQuest::WriteIntToClientINI(int,char *,char *),CEverQuest__WriteIntToClientINI);
#endif
#ifdef CEverQuest__WriteFloatToClientINI
REVERSE_DETOUR(void  CEverQuest::WriteFloatToClientINI(float,char *,char *),CEverQuest__WriteFloatToClientINI);
#endif
#ifdef CEverQuest__WriteBoolToClientINI
REVERSE_DETOUR(void  CEverQuest::WriteBoolToClientINI(bool,char *,char *),CEverQuest__WriteBoolToClientINI);
#endif
#ifdef CEverQuest__WriteStringToClientINI
REVERSE_DETOUR(void  CEverQuest::WriteStringToClientINI(char *,char *,char *),CEverQuest__WriteStringToClientINI);
#endif
#ifdef CEverQuest__ReadClientINIString
REVERSE_DETOUR(char *  CEverQuest::ReadClientINIString(char *,char *,char *,char *,int),CEverQuest__ReadClientINIString);
#endif
#ifdef CEverQuest__ReadClientINIInt
REVERSE_DETOUR(int  CEverQuest::ReadClientINIInt(char *,char *,int),CEverQuest__ReadClientINIInt);
#endif
#ifdef CEverQuest__ReadClientINIFloat
REVERSE_DETOUR(float  CEverQuest::ReadClientINIFloat(char *,char *,float),CEverQuest__ReadClientINIFloat);
#endif
#ifdef CEverQuest__ReadClientINIBool
REVERSE_DETOUR(bool  CEverQuest::ReadClientINIBool(char *,char *,bool),CEverQuest__ReadClientINIBool);
#endif
#ifdef CEverQuest__WriteIntToUIINI
REVERSE_DETOUR(void  CEverQuest::WriteIntToUIINI(int,char *,char *),CEverQuest__WriteIntToUIINI);
#endif
#ifdef CEverQuest__WriteBoolToUIINI
REVERSE_DETOUR(void  CEverQuest::WriteBoolToUIINI(bool,char *,char *),CEverQuest__WriteBoolToUIINI);
#endif
#ifdef CEverQuest__WriteStringToUIINI
REVERSE_DETOUR(void  CEverQuest::WriteStringToUIINI(char *,char *,char *),CEverQuest__WriteStringToUIINI);
#endif
#ifdef CEverQuest__ReadUIINIString
REVERSE_DETOUR(char *  CEverQuest::ReadUIINIString(char *,char *,char *,char *,int),CEverQuest__ReadUIINIString);
#endif
#ifdef CEverQuest__ReadUIINIInt
REVERSE_DETOUR(int  CEverQuest::ReadUIINIInt(char *,char *,int),CEverQuest__ReadUIINIInt);
#endif
#ifdef CEverQuest__ReadUIINIBool
REVERSE_DETOUR(bool  CEverQuest::ReadUIINIBool(char *,char *,bool),CEverQuest__ReadUIINIBool);
#endif
#ifdef CEverQuest__SaveCamerasToINI
REVERSE_DETOUR(void  CEverQuest::SaveCamerasToINI(void),CEverQuest__SaveCamerasToINI);
#endif
#ifdef CEverQuest__saveOptions
REVERSE_DETOUR(void  CEverQuest::saveOptions(void),CEverQuest__saveOptions);
#endif
#ifdef CEverQuest__saveOptions2
REVERSE_DETOUR(void  CEverQuest::saveOptions2(void),CEverQuest__saveOptions2);
#endif
#ifdef CEverQuest__send_update_filters
REVERSE_DETOUR(void  CEverQuest::send_update_filters(void),CEverQuest__send_update_filters);
#endif
#ifdef CEverQuest__loadOptions
REVERSE_DETOUR(void  CEverQuest::loadOptions(void),CEverQuest__loadOptions);
#endif
#ifdef CEverQuest__DoSplit
REVERSE_DETOUR(void  CEverQuest::DoSplit(char *),CEverQuest__DoSplit);
#endif
#ifdef CEverQuest__BeingIgnored
REVERSE_DETOUR(int  CEverQuest::BeingIgnored(char *),CEverQuest__BeingIgnored);
#endif
#ifdef CEverQuest__IsFriend
REVERSE_DETOUR(int  CEverQuest::IsFriend(char const *),CEverQuest__IsFriend);
#endif
#ifdef CEverQuest__ToggleAutoSplit
REVERSE_DETOUR(void  CEverQuest::ToggleAutoSplit(void),CEverQuest__ToggleAutoSplit);
#endif
#ifdef CEverQuest__procMouse
REVERSE_DETOUR(void  CEverQuest::procMouse(int),CEverQuest__procMouse);
#endif
#ifdef CEverQuest__StripShipName
REVERSE_DETOUR(char *  CEverQuest::StripShipName(char *,char *),CEverQuest__StripShipName);
#endif
#ifdef CEverQuest__trimName
REVERSE_DETOUR(char *  CEverQuest::trimName(char *),CEverQuest__trimName);
#endif
#ifdef CEverQuest__CancelSneakHide
REVERSE_DETOUR(void  CEverQuest::CancelSneakHide(void),CEverQuest__CancelSneakHide);
#endif
#ifdef CEverQuest__stripName
REVERSE_DETOUR(char *  CEverQuest::stripName(char *),CEverQuest__stripName);
#endif
#ifdef CEverQuest__clr_chat_input
REVERSE_DETOUR(void  CEverQuest::clr_chat_input(void),CEverQuest__clr_chat_input);
#endif
#ifdef CEverQuest__dsp_chat
REVERSE_DETOUR(void  CEverQuest::dsp_chat(char const *,int,bool),CEverQuest__dsp_chat);
#endif
#ifdef CEverQuest__dsp_chat1
REVERSE_DETOUR(void  CEverQuest::dsp_chat(char const *),CEverQuest__dsp_chat1);
#endif
#ifdef CEverQuest__DoPercentConvert
REVERSE_DETOUR(void  CEverQuest::DoPercentConvert(char *,bool),CEverQuest__DoPercentConvert);
#endif
#ifdef CEverQuest__Emote
REVERSE_DETOUR(void  CEverQuest::Emote(void),CEverQuest__Emote);
#endif
#ifdef CEverQuest__send_broadcast
REVERSE_DETOUR(void  CEverQuest::send_broadcast(void),CEverQuest__send_broadcast);
#endif
#ifdef CEverQuest__send_chat
REVERSE_DETOUR(void  CEverQuest::send_chat(void),CEverQuest__send_chat);
#endif
#ifdef CEverQuest__send_gsay
REVERSE_DETOUR(void  CEverQuest::send_gsay(void),CEverQuest__send_gsay);
#endif
#ifdef CEverQuest__reqChannel
REVERSE_DETOUR(void  CEverQuest::reqChannel(void),CEverQuest__reqChannel);
#endif
#ifdef CEverQuest__send_shout
REVERSE_DETOUR(void  CEverQuest::send_shout(void),CEverQuest__send_shout);
#endif
#ifdef CEverQuest__send_auction
REVERSE_DETOUR(void  CEverQuest::send_auction(void),CEverQuest__send_auction);
#endif
#ifdef CEverQuest__send_ooc
REVERSE_DETOUR(void  CEverQuest::send_ooc(void),CEverQuest__send_ooc);
#endif
#ifdef CEverQuest__GetCurrentLanguage
REVERSE_DETOUR(int  CEverQuest::GetCurrentLanguage(void),CEverQuest__GetCurrentLanguage);
#endif
#ifdef CEverQuest__SendNewText
REVERSE_DETOUR(void  CEverQuest::SendNewText(int,char *,char *),CEverQuest__SendNewText);
#endif
#ifdef CEverQuest__DisplayScreen
REVERSE_DETOUR(void  CEverQuest::DisplayScreen(char *),CEverQuest__DisplayScreen);
#endif
#ifdef CEverQuest__IsValidName
REVERSE_DETOUR(int  CEverQuest::IsValidName(char *),CEverQuest__IsValidName);
#endif
#ifdef CEverQuest__DoNewCharacterCreation
REVERSE_DETOUR(void  CEverQuest::DoNewCharacterCreation(void),CEverQuest__DoNewCharacterCreation);
#endif
#ifdef CEverQuest__RemoveCharacterOptionFile
REVERSE_DETOUR(void  CEverQuest::RemoveCharacterOptionFile(char *),CEverQuest__RemoveCharacterOptionFile);
#endif
#ifdef CEverQuest__SetDefaultGameValues
REVERSE_DETOUR(void  CEverQuest::SetDefaultGameValues(void),CEverQuest__SetDefaultGameValues);
#endif
#ifdef CEverQuest__SetPlayerAppearanceFromPInfo
REVERSE_DETOUR(void  CEverQuest::SetPlayerAppearanceFromPInfo(class EQPlayer *,int,bool),CEverQuest__SetPlayerAppearanceFromPInfo);
#endif
#ifdef CEverQuest__DoCharacterSelection
REVERSE_DETOUR(void  CEverQuest::DoCharacterSelection(void),CEverQuest__DoCharacterSelection);
#endif
#ifdef CEverQuest__DoLogin
REVERSE_DETOUR(int  CEverQuest::DoLogin(struct HWND__ *,struct HINSTANCE__ *),CEverQuest__DoLogin);
#endif
#ifdef CEverQuest__SetupCharSelectCamera
REVERSE_DETOUR(void  CEverQuest::SetupCharSelectCamera(void),CEverQuest__SetupCharSelectCamera);
#endif
#ifdef CEverQuest__CreateDataSubdirectories
REVERSE_DETOUR(void  CEverQuest::CreateDataSubdirectories(void),CEverQuest__CreateDataSubdirectories);
#endif
#ifdef CEverQuest__CreateFilenameServerCode
REVERSE_DETOUR(void  CEverQuest::CreateFilenameServerCode(char *),CEverQuest__CreateFilenameServerCode);
#endif
#ifdef CEverQuest__CreateIniFilenames
REVERSE_DETOUR(void  CEverQuest::CreateIniFilenames(void),CEverQuest__CreateIniFilenames);
#endif
#ifdef CEverQuest__StartNetworkGame
REVERSE_DETOUR(void  CEverQuest::StartNetworkGame(struct HWND__ *,struct HINSTANCE__ *,char *),CEverQuest__StartNetworkGame);
#endif
#ifdef CEverQuest__GetZoneInfoFromNetwork
REVERSE_DETOUR(void  CEverQuest::GetZoneInfoFromNetwork(char *),CEverQuest__GetZoneInfoFromNetwork);
#endif
#ifdef CEverQuest__EnterZone
REVERSE_DETOUR(void  CEverQuest::EnterZone(struct HWND__ *),CEverQuest__EnterZone);
#endif
#ifdef CEverQuest__Surname
REVERSE_DETOUR(void  CEverQuest::Surname(char *),CEverQuest__Surname);
#endif
#ifdef CEverQuest__Kill
REVERSE_DETOUR(void  CEverQuest::Kill(char *,char *),CEverQuest__Kill);
#endif
#ifdef CEverQuest__UpdateMyAppearance
REVERSE_DETOUR(void  CEverQuest::UpdateMyAppearance(void),CEverQuest__UpdateMyAppearance);
#endif
#ifdef CEverQuest__IFoundMyVehicle
REVERSE_DETOUR(unsigned char  CEverQuest::IFoundMyVehicle(void),CEverQuest__IFoundMyVehicle);
#endif
#ifdef CEverQuest__ProcessLocalPCIni
REVERSE_DETOUR(void  CEverQuest::ProcessLocalPCIni(int),CEverQuest__ProcessLocalPCIni);
#endif
#ifdef CEverQuest__DoMainLoop
REVERSE_DETOUR(void  CEverQuest::DoMainLoop(struct HWND__ *),CEverQuest__DoMainLoop);
#endif
#ifdef CEverQuest__ProcessControls
REVERSE_DETOUR(void  CEverQuest::ProcessControls(void),CEverQuest__ProcessControls);
#endif
#ifdef CEverQuest__TypingMode
REVERSE_DETOUR(int  CEverQuest::TypingMode(void),CEverQuest__TypingMode);
#endif
#ifdef CEverQuest__IsInTypingMode
REVERSE_DETOUR(bool  CEverQuest::IsInTypingMode(void),CEverQuest__IsInTypingMode);
#endif
#ifdef CEverQuest__doInspect
REVERSE_DETOUR(void  CEverQuest::doInspect(class EQPlayer *),CEverQuest__doInspect);
#endif
#ifdef CEverQuest__SendLightInfo
REVERSE_DETOUR(void  CEverQuest::SendLightInfo(class EQPlayer *,unsigned char),CEverQuest__SendLightInfo);
#endif
#ifdef CEverQuest__SetTimedFog
REVERSE_DETOUR(void  CEverQuest::SetTimedFog(int),CEverQuest__SetTimedFog);
#endif
#ifdef CEverQuest__ProcessGame
REVERSE_DETOUR(void  CEverQuest::ProcessGame(struct HWND__ *,struct HINSTANCE__ *),CEverQuest__ProcessGame);
#endif
#ifdef CEverQuest__DoLoadScreenProgressBar
REVERSE_DETOUR(void __cdecl CEverQuest::DoLoadScreenProgressBar(int,char const *,...),CEverQuest__DoLoadScreenProgressBar);
#endif
#ifdef CEverQuest__DoLoadScreen
REVERSE_DETOUR(void  CEverQuest::DoLoadScreen(int),CEverQuest__DoLoadScreen);
#endif
#ifdef CEverQuest__CleanupBadFiles
REVERSE_DETOUR(void  CEverQuest::CleanupBadFiles(void),CEverQuest__CleanupBadFiles);
#endif
#ifdef CEverQuest__CreateInitialActors
REVERSE_DETOUR(void  CEverQuest::CreateInitialActors(void),CEverQuest__CreateInitialActors);
#endif
#ifdef CEverQuest__GetSndDriver
REVERSE_DETOUR(void  CEverQuest::GetSndDriver(void),CEverQuest__GetSndDriver);
#endif
#ifdef CEverQuest__InterpretCmd
REVERSE_DETOUR(void  CEverQuest::InterpretCmd(class EQPlayer *,char *),CEverQuest__InterpretCmd);
#endif
#ifdef CEverQuest__GrabFirstWord
REVERSE_DETOUR(char *  CEverQuest::GrabFirstWord(char *,char *),CEverQuest__GrabFirstWord);
#endif
#ifdef CEverQuest__GrabFirstWord2
REVERSE_DETOUR(char *  CEverQuest::GrabFirstWord2(char *,char *,int),CEverQuest__GrabFirstWord2);
#endif
#ifdef CEverQuest__CopyFirstWord
REVERSE_DETOUR(void  CEverQuest::CopyFirstWord(char *,char *),CEverQuest__CopyFirstWord);
#endif
#ifdef CEverQuest__ApplyPoison
REVERSE_DETOUR(void  CEverQuest::ApplyPoison(unsigned long),CEverQuest__ApplyPoison);
#endif
#ifdef CEverQuest__DeacSpellScreen
REVERSE_DETOUR(void  CEverQuest::DeacSpellScreen(void),CEverQuest__DeacSpellScreen);
#endif
#ifdef CEverQuest__IsZoneAvailable
//REVERSE_DETOUR(enum ZONE_REQ_STATUS  CEverQuest::IsZoneAvailable(char *,enum EQZoneIndex,enum ZONE_REQ_REASON),CEverQuest__IsZoneAvailable);
#endif
#ifdef CEverQuest__MoveToZone
//REVERSE_DETOUR(void  CEverQuest::MoveToZone(enum EQZoneIndex,char *,int,enum ZONE_REQ_REASON),CEverQuest__MoveToZone);
#endif
#ifdef CEverQuest__MoveToZone1
//REVERSE_DETOUR(void  CEverQuest::MoveToZone(char *,char *,int,enum ZONE_REQ_REASON),CEverQuest__MoveToZone1);
#endif
#ifdef CEverQuest__LMouseDown
REVERSE_DETOUR(void  CEverQuest::LMouseDown(int,int),CEverQuest__LMouseDown);
#endif
#ifdef CEverQuest__RMouseDown
REVERSE_DETOUR(void  CEverQuest::RMouseDown(int,int),CEverQuest__RMouseDown);
#endif
#ifdef CEverQuest__RMouseUp
REVERSE_DETOUR(void  CEverQuest::RMouseUp(int,int),CEverQuest__RMouseUp);
#endif
#ifdef CEverQuest__MouseWheelScrolled
REVERSE_DETOUR(void  CEverQuest::MouseWheelScrolled(int),CEverQuest__MouseWheelScrolled);
#endif
#ifdef CEverQuest__ClickedSwitch
REVERSE_DETOUR(class EQSwitch *  CEverQuest::ClickedSwitch(int,int),CEverQuest__ClickedSwitch);
#endif
#ifdef CEverQuest__ClickedPlayer
REVERSE_DETOUR(class EQPlayer *  CEverQuest::ClickedPlayer(int,int),CEverQuest__ClickedPlayer);
#endif
#ifdef CEverQuest__WhatTimeIsIt
REVERSE_DETOUR(void  CEverQuest::WhatTimeIsIt(void),CEverQuest__WhatTimeIsIt);
#endif
#ifdef CEverQuest__FreeSwitches
REVERSE_DETOUR(void  CEverQuest::FreeSwitches(void),CEverQuest__FreeSwitches);
#endif
#ifdef CEverQuest__LoadSwitchesNonAvatar
//REVERSE_DETOUR(void  CEverQuest::LoadSwitchesNonAvatar(enum EQZoneIndex),CEverQuest__LoadSwitchesNonAvatar);
#endif
#ifdef CEverQuest__SetLfgPlayerStatus
REVERSE_DETOUR(void  CEverQuest::SetLfgPlayerStatus(struct LfgPlayerStatus *),CEverQuest__SetLfgPlayerStatus);
#endif
#ifdef CEverQuest__SetLfgGroupStatus
REVERSE_DETOUR(void  CEverQuest::SetLfgGroupStatus(struct LfgGroupStatus *),CEverQuest__SetLfgGroupStatus);
#endif
#ifdef CEverQuest__IssueLfgPlayerQuery
REVERSE_DETOUR(void  CEverQuest::IssueLfgPlayerQuery(struct LfgPlayerQuery *),CEverQuest__IssueLfgPlayerQuery);
#endif
#ifdef CEverQuest__IssueLfgGroupQuery
REVERSE_DETOUR(void  CEverQuest::IssueLfgGroupQuery(struct LfgGroupQuery *),CEverQuest__IssueLfgGroupQuery);
#endif
#ifdef CEverQuest__IssuePetCommand
//REVERSE_DETOUR(void  CEverQuest::IssuePetCommand(enum PetCommandType,int),CEverQuest__IssuePetCommand);
#endif
#ifdef CEverQuest__LootCorpse
REVERSE_DETOUR(int  CEverQuest::LootCorpse(class EQPlayer *,int),CEverQuest__LootCorpse);
#endif
#ifdef CEverQuest__loadSoundsGame
REVERSE_DETOUR(void  CEverQuest::loadSoundsGame(void),CEverQuest__loadSoundsGame);
#endif
#ifdef CEverQuest__GetSingleMessage
REVERSE_DETOUR(char *  CEverQuest::GetSingleMessage(unsigned __int32,int,int *,char *),CEverQuest__GetSingleMessage);
#endif
#ifdef CEverQuest__SetGameState
REVERSE_DETOUR(void  CEverQuest::SetGameState(int),CEverQuest__SetGameState);
#endif
#ifdef CEverQuest__IsOkToTransact
REVERSE_DETOUR(bool  CEverQuest::IsOkToTransact(void),CEverQuest__IsOkToTransact);
#endif
#ifdef CEverQuest__SortSpellLoadouts
REVERSE_DETOUR(void  CEverQuest::SortSpellLoadouts(void),CEverQuest__SortSpellLoadouts);
#endif
#ifdef CEverQuest__saveCustom
REVERSE_DETOUR(void  CEverQuest::saveCustom(void),CEverQuest__saveCustom);
#endif
#ifdef CEverQuest__loadCustomFromINI
REVERSE_DETOUR(void  CEverQuest::loadCustomFromINI(char *),CEverQuest__loadCustomFromINI);
#endif
#ifdef CEverQuest__loadCustom
REVERSE_DETOUR(void  CEverQuest::loadCustom(void),CEverQuest__loadCustom);
#endif
#ifdef CEverQuest__initCustom
REVERSE_DETOUR(void  CEverQuest::initCustom(void),CEverQuest__initCustom);
#endif
#ifdef _EverQuestinfo__SetAutoAttack
REVERSE_DETOUR(void  _EverQuestinfo::SetAutoAttack(bool),_EverQuestinfo__SetAutoAttack);
#endif
#ifdef GrammarRulesClass__GrammarRulesClass
REVERSE_DETOUR( GrammarRulesClass::GrammarRulesClass(void),GrammarRulesClass__GrammarRulesClass);
#endif
#ifdef GrammarRulesClass__Parse
REVERSE_DETOUR(char *  GrammarRulesClass::Parse(char *),GrammarRulesClass__Parse);
#endif
#ifdef GrammarRulesClass__Resolve
REVERSE_DETOUR(char *  GrammarRulesClass::Resolve(int,int,char *,char *),GrammarRulesClass__Resolve);
#endif
#ifdef GrammarRulesClass__RuleEn1
REVERSE_DETOUR(void  GrammarRulesClass::RuleEn1(char *,char *),GrammarRulesClass__RuleEn1);
#endif
#ifdef GrammarRulesClass__RuleEn2
REVERSE_DETOUR(void  GrammarRulesClass::RuleEn2(char *,char *),GrammarRulesClass__RuleEn2);
#endif
#ifdef GrammarRulesClass__RuleEn3
REVERSE_DETOUR(void  GrammarRulesClass::RuleEn3(char *,char *,char *,char *),GrammarRulesClass__RuleEn3);
#endif
#ifdef GrammarRulesClass__RuleEn4
REVERSE_DETOUR(void  GrammarRulesClass::RuleEn4(char *,char *,char *,char *),GrammarRulesClass__RuleEn4);
#endif
#ifdef GrammarRulesClass__RuleKo1
REVERSE_DETOUR(void  GrammarRulesClass::RuleKo1(char *,char *,char *,char *),GrammarRulesClass__RuleKo1);
#endif
#ifdef GrammarRulesClass__RuleFr1
REVERSE_DETOUR(void  GrammarRulesClass::RuleFr1(char *,char *,char *,char *),GrammarRulesClass__RuleFr1);
#endif
#ifdef GrammarRulesClass__RuleDe1
REVERSE_DETOUR(void  GrammarRulesClass::RuleDe1(char *,char *),GrammarRulesClass__RuleDe1);
#endif
#ifdef KeypressHandler__KeypressHandler
REVERSE_DETOUR( KeypressHandler::KeypressHandler(void),KeypressHandler__KeypressHandler);
#endif
#ifdef KeypressHandler__AttachKeyToEqCommand
REVERSE_DETOUR(bool  KeypressHandler::AttachKeyToEqCommand(class KeyCombo const &,unsigned int),KeypressHandler__AttachKeyToEqCommand);
#endif
#ifdef KeypressHandler__AttachAltKeyToEqCommand
REVERSE_DETOUR(bool  KeypressHandler::AttachAltKeyToEqCommand(class KeyCombo const &,unsigned int),KeypressHandler__AttachAltKeyToEqCommand);
#endif
#ifdef KeypressHandler__HandleKeyDown
REVERSE_DETOUR(bool  KeypressHandler::HandleKeyDown(class KeyCombo const &),KeypressHandler__HandleKeyDown);
#endif
#ifdef KeypressHandler__HandleKeyUp
REVERSE_DETOUR(bool  KeypressHandler::HandleKeyUp(class KeyCombo const &),KeypressHandler__HandleKeyUp);
#endif
#ifdef KeypressHandler__GetKeyAttachedToEqCommand
REVERSE_DETOUR(class KeyCombo const &  KeypressHandler::GetKeyAttachedToEqCommand(unsigned int)const ,KeypressHandler__GetKeyAttachedToEqCommand);
#endif
#ifdef KeypressHandler__GetAltKeyAttachedToEqCommand
REVERSE_DETOUR(class KeyCombo const &  KeypressHandler::GetAltKeyAttachedToEqCommand(unsigned int)const ,KeypressHandler__GetAltKeyAttachedToEqCommand);
#endif
#ifdef KeypressHandler__ResetKeysToEqDefaults
REVERSE_DETOUR(void  KeypressHandler::ResetKeysToEqDefaults(void),KeypressHandler__ResetKeysToEqDefaults);
#endif
#ifdef KeypressHandler__MapKeyToEqCommand
REVERSE_DETOUR(bool  KeypressHandler::MapKeyToEqCommand(class KeyCombo const &,int,unsigned int),KeypressHandler__MapKeyToEqCommand);
#endif
#ifdef KeypressHandler__IsReservedKey
REVERSE_DETOUR(bool  KeypressHandler::IsReservedKey(class KeyCombo const &)const ,KeypressHandler__IsReservedKey);
#endif
#ifdef KeypressHandler__LoadAndSetKeymappings
REVERSE_DETOUR(void  KeypressHandler::LoadAndSetKeymappings(void),KeypressHandler__LoadAndSetKeymappings);
#endif
#ifdef KeypressHandler__LoadKeymapping
REVERSE_DETOUR(bool  KeypressHandler::LoadKeymapping(unsigned int,int,class KeyCombo *),KeypressHandler__LoadKeymapping);
#endif
#ifdef KeypressHandler__SaveKeymapping
REVERSE_DETOUR(void  KeypressHandler::SaveKeymapping(unsigned int,class KeyCombo const &,int),KeypressHandler__SaveKeymapping);
#endif
#ifdef KeypressHandler__GetEqCommandSaveName
REVERSE_DETOUR(class CXStr  KeypressHandler::GetEqCommandSaveName(unsigned int,int)const ,KeypressHandler__GetEqCommandSaveName);
#endif
#ifdef KeypressHandler__LoadAndConvertOldKeymappingFormat
REVERSE_DETOUR(bool  KeypressHandler::LoadAndConvertOldKeymappingFormat(unsigned int,int,class KeyCombo *),KeypressHandler__LoadAndConvertOldKeymappingFormat);
#endif
#ifdef KeypressHandler__ClearCommandStateArray
REVERSE_DETOUR(void  KeypressHandler::ClearCommandStateArray(void),KeypressHandler__ClearCommandStateArray);
#endif
#ifdef MemoryPoolManager__MemoryPoolManager
REVERSE_DETOUR( MemoryPoolManager::MemoryPoolManager(void),MemoryPoolManager__MemoryPoolManager);
#endif
#ifdef MemoryPoolManager__dMemoryPoolManager
REVERSE_DETOUR( MemoryPoolManager::~MemoryPoolManager(void),MemoryPoolManager__dMemoryPoolManager);
#endif
#ifdef MemoryPoolManager__Alloc
REVERSE_DETOUR(void *  MemoryPoolManager::Alloc(int),MemoryPoolManager__Alloc);
#endif
#ifdef MemoryPoolManager__Free
REVERSE_DETOUR(void  MemoryPoolManager::Free(void *),MemoryPoolManager__Free);
#endif
#ifdef PacketPackerManager__SetPriority
REVERSE_DETOUR(void  PacketPackerManager::SetPriority(class PacketPacker *,__int64),PacketPackerManager__SetPriority);
#endif
#ifdef PacketPackerManager__RemovePacker
REVERSE_DETOUR(void  PacketPackerManager::RemovePacker(class PacketPacker *),PacketPackerManager__RemovePacker);
#endif
#ifdef PacketPackerManager__UnpackGetFirst
REVERSE_DETOUR(bool __cdecl PacketPackerManager::UnpackGetFirst(struct PacketPackerState *,unsigned __int32,unsigned char *,int),PacketPackerManager__UnpackGetFirst);
#endif
#ifdef PacketPackerManager__UnpackGetNext
REVERSE_DETOUR(bool __cdecl PacketPackerManager::UnpackGetNext(struct PacketPackerState *),PacketPackerManager__UnpackGetNext);
#endif
#ifdef PacketPacker__SendStatUpdate
REVERSE_DETOUR(void  PacketPacker::SendStatUpdate(struct _statUpdate *,bool),PacketPacker__SendStatUpdate);
#endif
#ifdef PacketPacker__FlushPositions
REVERSE_DETOUR(void  PacketPacker::FlushPositions(void),PacketPacker__FlushPositions);
#endif
#ifdef PacketPacker__SendPacket
REVERSE_DETOUR(void  PacketPacker::SendPacket(unsigned __int32,void *,int,bool),PacketPacker__SendPacket);
#endif
#ifdef PacketPacker__AddPacketToBuffer
//REVERSE_DETOUR(void  PacketPacker::AddPacketToBuffer(struct PacketPacker::PacketBuffer *,unsigned __int32,void *,int),PacketPacker__AddPacketToBuffer);
#endif
#ifdef PacketPacker__ScheduleUs
REVERSE_DETOUR(void  PacketPacker::ScheduleUs(void),PacketPacker__ScheduleUs);
#endif
#ifdef PacketPacker__Flush
REVERSE_DETOUR(void  PacketPacker::Flush(void),PacketPacker__Flush);
#endif
#ifdef PacketPacker__FlushBuffer
//REVERSE_DETOUR(void  PacketPacker::FlushBuffer(struct PacketPacker::PacketBuffer *),PacketPacker__FlushBuffer);
#endif
#ifdef PacketPacker__Disassociate
REVERSE_DETOUR(void  PacketPacker::Disassociate(void),PacketPacker__Disassociate);
#endif
#ifdef CResolutionHandler__Init
REVERSE_DETOUR(int __cdecl CResolutionHandler::Init(void),CResolutionHandler__Init);
#endif
#ifdef CResolutionHandler__Shutdown
REVERSE_DETOUR(void __cdecl CResolutionHandler::Shutdown(void),CResolutionHandler__Shutdown);
#endif
#ifdef CResolutionHandler__SaveSettings
REVERSE_DETOUR(void __cdecl CResolutionHandler::SaveSettings(void),CResolutionHandler__SaveSettings);
#endif
#ifdef CResolutionHandler__ToggleScreenMode
REVERSE_DETOUR(void __cdecl CResolutionHandler::ToggleScreenMode(void),CResolutionHandler__ToggleScreenMode);
#endif
#ifdef CResolutionHandler__ChangeToResolution
REVERSE_DETOUR(void __cdecl CResolutionHandler::ChangeToResolution(int,int,int,int,int),CResolutionHandler__ChangeToResolution);
#endif
#ifdef CResolutionHandler__UpdateWindowPosition
REVERSE_DETOUR(void __cdecl CResolutionHandler::UpdateWindowPosition(void),CResolutionHandler__UpdateWindowPosition);
#endif
#ifdef CResolutionHandler__GetDesktopWidth
REVERSE_DETOUR(int __cdecl CResolutionHandler::GetDesktopWidth(void),CResolutionHandler__GetDesktopWidth);
#endif
#ifdef CResolutionHandler__GetDesktopHeight
REVERSE_DETOUR(int __cdecl CResolutionHandler::GetDesktopHeight(void),CResolutionHandler__GetDesktopHeight);
#endif
#ifdef CResolutionHandler__GetDesktopBitsPerPixel
REVERSE_DETOUR(int __cdecl CResolutionHandler::GetDesktopBitsPerPixel(void),CResolutionHandler__GetDesktopBitsPerPixel);
#endif
#ifdef CResolutionHandler__GetDesktopRefreshRate
REVERSE_DETOUR(int __cdecl CResolutionHandler::GetDesktopRefreshRate(void),CResolutionHandler__GetDesktopRefreshRate);
#endif
#ifdef CResolutionHandler__GetWidth
REVERSE_DETOUR(int __cdecl CResolutionHandler::GetWidth(void),CResolutionHandler__GetWidth);
#endif
#ifdef CResolutionHandler__GetHeight
REVERSE_DETOUR(int __cdecl CResolutionHandler::GetHeight(void),CResolutionHandler__GetHeight);
#endif
#ifdef CResolutionHandler__IsFullscreenAvailable
REVERSE_DETOUR(bool __cdecl CResolutionHandler::IsFullscreenAvailable(void),CResolutionHandler__IsFullscreenAvailable);
#endif
#ifdef Util__AllocateString
REVERSE_DETOUR(char * __cdecl Util::AllocateString(char *),Util__AllocateString);
#endif
#ifdef ChannelServerApi__AllocateString
REVERSE_DETOUR(char * __cdecl ChannelServerApi::AllocateString(char *),ChannelServerApi__AllocateString);
#endif
#ifdef SoundManager__SoundManager
//REVERSE_DETOUR( SoundManager::SoundManager(int,int,bool,int,int,bool,enum SpeakerType),SoundManager__SoundManager);
#endif
#ifdef SoundManager__dSoundManager
REVERSE_DETOUR( SoundManager::~SoundManager(void),SoundManager__dSoundManager);
#endif
#ifdef SoundManager__AddPool
//REVERSE_DETOUR(void  SoundManager::AddPool(enum InstanceType,int,int),SoundManager__AddPool);
#endif
#ifdef SoundManager__GiveTime
REVERSE_DETOUR(void  SoundManager::GiveTime(void),SoundManager__GiveTime);
#endif
#ifdef SoundManager__SetMixAhead
REVERSE_DETOUR(void  SoundManager::SetMixAhead(int),SoundManager__SetMixAhead);
#endif
#ifdef SoundManager__GetListenerEnvironment
//REVERSE_DETOUR(enum EnvironmentType  SoundManager::GetListenerEnvironment(void),SoundManager__GetListenerEnvironment);
#endif
#ifdef SoundManager__SetListenerEnvironment
//REVERSE_DETOUR(void  SoundManager::SetListenerEnvironment(enum EnvironmentType),SoundManager__SetListenerEnvironment);
#endif
#ifdef SoundManager__SetListenerLocation
REVERSE_DETOUR(void  SoundManager::SetListenerLocation(float,float,float,float),SoundManager__SetListenerLocation);
#endif
#ifdef SoundManager__GetListenerLocation
REVERSE_DETOUR(void  SoundManager::GetListenerLocation(float *,float *,float *,float *),SoundManager__GetListenerLocation);
#endif
#ifdef SoundManager__BorrowInstance
//REVERSE_DETOUR(class SoundInstance *  SoundManager::BorrowInstance(enum InstanceType,int),SoundManager__BorrowInstance);
#endif
#ifdef SoundManager__ReturnInstance
REVERSE_DETOUR(void  SoundManager::ReturnInstance(class SoundInstance *),SoundManager__ReturnInstance);
#endif
#ifdef SoundManager__AssetGiveTime
REVERSE_DETOUR(void  SoundManager::AssetGiveTime(void),SoundManager__AssetGiveTime);
#endif
#ifdef SoundManager__AssetAdd
REVERSE_DETOUR(void  SoundManager::AssetAdd(class SoundAsset *),SoundManager__AssetAdd);
#endif
#ifdef SoundManager__AssetRemove
REVERSE_DETOUR(void  SoundManager::AssetRemove(class SoundAsset *),SoundManager__AssetRemove);
#endif
#ifdef SoundManager__AssetGet
REVERSE_DETOUR(class SoundAsset *  SoundManager::AssetGet(char *),SoundManager__AssetGet);
#endif
#ifdef SoundManager__StreamingPlay
REVERSE_DETOUR(void  SoundManager::StreamingPlay(char *),SoundManager__StreamingPlay);
#endif
#ifdef SoundManager__StreamingPause
REVERSE_DETOUR(void  SoundManager::StreamingPause(void),SoundManager__StreamingPause);
#endif
#ifdef SoundManager__StreamingStop
REVERSE_DETOUR(void  SoundManager::StreamingStop(void),SoundManager__StreamingStop);
#endif
#ifdef SoundManager__StreamingSetVolumeLevel
REVERSE_DETOUR(void  SoundManager::StreamingSetVolumeLevel(float),SoundManager__StreamingSetVolumeLevel);
#endif
#ifdef SoundManager__StreamingGetVolumeLevel
REVERSE_DETOUR(float  SoundManager::StreamingGetVolumeLevel(void),SoundManager__StreamingGetVolumeLevel);
#endif
#ifdef SoundManager__StreamingSetSongPosition
REVERSE_DETOUR(void  SoundManager::StreamingSetSongPosition(int),SoundManager__StreamingSetSongPosition);
#endif
#ifdef SoundManager__StreamingGetSongPosition
REVERSE_DETOUR(int  SoundManager::StreamingGetSongPosition(void),SoundManager__StreamingGetSongPosition);
#endif
#ifdef SoundManager__StreamingGetSongLength
REVERSE_DETOUR(int  SoundManager::StreamingGetSongLength(void),SoundManager__StreamingGetSongLength);
#endif
#ifdef SoundManager__StreamingStatus
//REVERSE_DETOUR(enum StreamingStatus  SoundManager::StreamingStatus(void),SoundManager__StreamingStatus);
#endif
#ifdef MusicManager__MusicEntry__MusicEntry
//REVERSE_DETOUR( MusicManager::MusicEntry::MusicEntry(int,class SoundAsset *,int,float,int,int,int,int,int,int),MusicManager__MusicEntry__MusicEntry);
#endif
#ifdef MusicManager__MusicEntry__dMusicEntry
//REVERSE_DETOUR( MusicManager::MusicEntry::~MusicEntry(void),MusicManager__MusicEntry__dMusicEntry);
#endif
#ifdef MusicManager__MusicEntry__AdjustVolume
//REVERSE_DETOUR(void  MusicManager::MusicEntry::AdjustVolume(float),MusicManager__MusicEntry__AdjustVolume);
#endif
#ifdef MusicManager__MusicEntry__FadeIn
//REVERSE_DETOUR(void  MusicManager::MusicEntry::FadeIn(float),MusicManager__MusicEntry__FadeIn);
#endif
#ifdef MusicManager__MusicEntry__FadeOut
//REVERSE_DETOUR(void  MusicManager::MusicEntry::FadeOut(bool),MusicManager__MusicEntry__FadeOut);
#endif
#ifdef SoundObject__SoundObject
//REVERSE_DETOUR( SoundObject::SoundObject(void),SoundObject__SoundObject);
#endif
#ifdef SoundObject__Release
//REVERSE_DETOUR(void  SoundObject::Release(void),SoundObject__Release);
#endif
#ifdef SoundInstance__SoundInstance
//REVERSE_DETOUR( SoundInstance::SoundInstance(class SoundManager *),SoundInstance__SoundInstance);
#endif
#ifdef SoundInstance__YourManagerDeleted
//REVERSE_DETOUR(void  SoundInstance::YourManagerDeleted(void),SoundInstance__YourManagerDeleted);
#endif
#ifdef flex_unit__clear
REVERSE_DETOUR(void  flex_unit::clear(void),flex_unit__clear);
#endif
#ifdef WaveInstance__WaveInstance
REVERSE_DETOUR( WaveInstance::WaveInstance(class SoundManager *),WaveInstance__WaveInstance);
#endif
#ifdef Wave3dInstance__Wave3dInstance
REVERSE_DETOUR( Wave3dInstance::Wave3dInstance(class SoundManager *),Wave3dInstance__Wave3dInstance);
#endif
#ifdef MidiInstance__MidiInstance
//REVERSE_DETOUR( MidiInstance::MidiInstance(class SoundManager *),MidiInstance__MidiInstance);
#endif
#ifdef SoundAsset__SoundAsset
//REVERSE_DETOUR( SoundAsset::SoundAsset(class SoundManager *,char *,char *,int),SoundAsset__SoundAsset);
#endif
#ifdef SoundAsset__GetType
//REVERSE_DETOUR(enum AssetType  SoundAsset::GetType(void),SoundAsset__GetType);
#endif
#ifdef SoundAsset__YourManagerDeleted
//REVERSE_DETOUR(void  SoundAsset::YourManagerDeleted(void),SoundAsset__YourManagerDeleted);
#endif
#ifdef SoundAsset__GiveTime
//REVERSE_DETOUR(void  SoundAsset::GiveTime(void),SoundAsset__GiveTime);
#endif
#ifdef SoundAsset__IsPlaying
//REVERSE_DETOUR(bool  SoundAsset::IsPlaying(void),SoundAsset__IsPlaying);
#endif
#ifdef SoundAsset__AdjustVolume
//REVERSE_DETOUR(void  SoundAsset::AdjustVolume(float,int),SoundAsset__AdjustVolume);
#endif
#ifdef SoundAsset__GetName
//REVERSE_DETOUR(char *  SoundAsset::GetName(void),SoundAsset__GetName);
#endif
#ifdef SoundAsset__Play
//REVERSE_DETOUR(class SoundInstance *  SoundAsset::Play(class SoundControl *),SoundAsset__Play);
#endif
#ifdef SoundAsset__Stop
//REVERSE_DETOUR(void  SoundAsset::Stop(void),SoundAsset__Stop);
#endif
#ifdef SoundControl__SoundControl
REVERSE_DETOUR( SoundControl::SoundControl(void),SoundControl__SoundControl);
#endif
#ifdef SoundEmitter__SoundEmitter
//REVERSE_DETOUR( SoundEmitter::SoundEmitter(class EmitterManager *,class SoundAsset *,int),SoundEmitter__SoundEmitter);
#endif
#ifdef SoundEmitter__SoundEmitter1
//REVERSE_DETOUR( SoundEmitter::SoundEmitter(class EmitterManager *,class MusicManager *,int),SoundEmitter__SoundEmitter1);
#endif
#ifdef SoundEmitter__Init
//REVERSE_DETOUR(void  SoundEmitter::Init(void),SoundEmitter__Init);
#endif
#ifdef SoundEmitter__GiveTime
//REVERSE_DETOUR(void  SoundEmitter::GiveTime(void),SoundEmitter__GiveTime);
#endif
#ifdef SoundEmitter__ReleaseLoopingSound
//REVERSE_DETOUR(void  SoundEmitter::ReleaseLoopingSound(void),SoundEmitter__ReleaseLoopingSound);
#endif
#ifdef SoundEmitter__ResetTimer
//REVERSE_DETOUR(void  SoundEmitter::ResetTimer(void),SoundEmitter__ResetTimer);
#endif
#ifdef SoundEmitter__Move
//REVERSE_DETOUR(void  SoundEmitter::Move(float,float,float),SoundEmitter__Move);
#endif
#ifdef SoundEmitter__SetAsset
//REVERSE_DETOUR(void  SoundEmitter::SetAsset(class SoundAsset *),SoundEmitter__SetAsset);
#endif
#ifdef SoundEmitter__Enable
//REVERSE_DETOUR(void  SoundEmitter::Enable(bool),SoundEmitter__Enable);
#endif
#ifdef Mp3Manager__Mp3Manager
REVERSE_DETOUR( Mp3Manager::Mp3Manager(class SoundManager *,class MusicManager *),Mp3Manager__Mp3Manager);
#endif
#ifdef Mp3Manager__dMp3Manager
REVERSE_DETOUR( Mp3Manager::~Mp3Manager(void),Mp3Manager__dMp3Manager);
#endif
#ifdef Mp3Manager__GetSort
//REVERSE_DETOUR(enum Mp3Manager::SortOrder  Mp3Manager::GetSort(void),Mp3Manager__GetSort);
#endif
#ifdef Mp3Manager__Sort
//REVERSE_DETOUR(void  Mp3Manager::Sort(enum Mp3Manager::SortOrder),Mp3Manager__Sort);
#endif
#ifdef Mp3Manager__Stop
REVERSE_DETOUR(void  Mp3Manager::Stop(void),Mp3Manager__Stop);
#endif
#ifdef Mp3Manager__Play
REVERSE_DETOUR(void  Mp3Manager::Play(void),Mp3Manager__Play);
#endif
#ifdef Mp3Manager__Pause
REVERSE_DETOUR(void  Mp3Manager::Pause(void),Mp3Manager__Pause);
#endif
#ifdef Mp3Manager__Status
//REVERSE_DETOUR(enum StreamingStatus  Mp3Manager::Status(void),Mp3Manager__Status);
#endif
#ifdef Mp3Manager__GiveTime
REVERSE_DETOUR(void  Mp3Manager::GiveTime(void),Mp3Manager__GiveTime);
#endif
#ifdef Mp3Manager__Next
REVERSE_DETOUR(void  Mp3Manager::Next(void),Mp3Manager__Next);
#endif
#ifdef Mp3Manager__Back
REVERSE_DETOUR(void  Mp3Manager::Back(void),Mp3Manager__Back);
#endif
#ifdef Mp3Manager__GetSongLength
REVERSE_DETOUR(int  Mp3Manager::GetSongLength(void),Mp3Manager__GetSongLength);
#endif
#ifdef Mp3Manager__GetSongPosition
REVERSE_DETOUR(int  Mp3Manager::GetSongPosition(void),Mp3Manager__GetSongPosition);
#endif
#ifdef Mp3Manager__SetSongPosition
REVERSE_DETOUR(void  Mp3Manager::SetSongPosition(int),Mp3Manager__SetSongPosition);
#endif
#ifdef Mp3Manager__GetName
REVERSE_DETOUR(char *  Mp3Manager::GetName(int),Mp3Manager__GetName);
#endif
#ifdef Mp3Manager__Count
REVERSE_DETOUR(int  Mp3Manager::Count(void),Mp3Manager__Count);
#endif
#ifdef Mp3Manager__SetPosition
REVERSE_DETOUR(void  Mp3Manager::SetPosition(int),Mp3Manager__SetPosition);
#endif
#ifdef Mp3Manager__SetVolumeLevel
REVERSE_DETOUR(void  Mp3Manager::SetVolumeLevel(float),Mp3Manager__SetVolumeLevel);
#endif
#ifdef Mp3Manager__GetVolumeLevel
REVERSE_DETOUR(float  Mp3Manager::GetVolumeLevel(void),Mp3Manager__GetVolumeLevel);
#endif
#ifdef Mp3Manager__DeleteAll
REVERSE_DETOUR(void  Mp3Manager::DeleteAll(void),Mp3Manager__DeleteAll);
#endif
#ifdef Mp3Manager__Delete
REVERSE_DETOUR(void  Mp3Manager::Delete(int),Mp3Manager__Delete);
#endif
#ifdef Mp3Manager__SaveList
REVERSE_DETOUR(void  Mp3Manager::SaveList(char *),Mp3Manager__SaveList);
#endif
#ifdef Mp3Manager__Add
REVERSE_DETOUR(int  Mp3Manager::Add(char *),Mp3Manager__Add);
#endif
#ifdef Mp3Manager__InternalAdd
REVERSE_DETOUR(int  Mp3Manager::InternalAdd(char *,char *,int),Mp3Manager__InternalAdd);
#endif
#ifdef Mp3Manager__Entry__Entry
//REVERSE_DETOUR( Mp3Manager::Entry::Entry(char *,char *,int,int),Mp3Manager__Entry__Entry);
#endif
#ifdef Mp3Manager__Entry__dEntry
//REVERSE_DETOUR( Mp3Manager::Entry::~Entry(void),Mp3Manager__Entry__dEntry);
#endif
#ifdef EmitterManager__EmitterManager
REVERSE_DETOUR( EmitterManager::EmitterManager(class SoundManager *),EmitterManager__EmitterManager);
#endif
#ifdef EmitterManager__dEmitterManager
REVERSE_DETOUR( EmitterManager::~EmitterManager(void),EmitterManager__dEmitterManager);
#endif
#ifdef EmitterManager__Add
//REVERSE_DETOUR(void  EmitterManager::Add(class SoundEmitter *),EmitterManager__Add);
#endif
#ifdef EmitterManager__Remove
//REVERSE_DETOUR(void  EmitterManager::Remove(class SoundEmitter *),EmitterManager__Remove);
#endif
#ifdef EmitterManager__GiveTime
REVERSE_DETOUR(void  EmitterManager::GiveTime(void),EmitterManager__GiveTime);
#endif
#ifdef EmitterManager__GetEffectsLevel
REVERSE_DETOUR(float  EmitterManager::GetEffectsLevel(void),EmitterManager__GetEffectsLevel);
#endif
#ifdef EmitterManager__GetVolumeLevel
REVERSE_DETOUR(float  EmitterManager::GetVolumeLevel(void),EmitterManager__GetVolumeLevel);
#endif
#ifdef EmitterManager__SetEffectsLevel
REVERSE_DETOUR(void  EmitterManager::SetEffectsLevel(float),EmitterManager__SetEffectsLevel);
#endif
#ifdef EmitterManager__GetListenerLocation
REVERSE_DETOUR(void  EmitterManager::GetListenerLocation(float *,float *,float *,float *),EmitterManager__GetListenerLocation);
#endif
#ifdef MusicManager__MusicManager
REVERSE_DETOUR( MusicManager::MusicManager(void),MusicManager__MusicManager);
#endif
#ifdef MusicManager__dMusicManager
REVERSE_DETOUR( MusicManager::~MusicManager(void),MusicManager__dMusicManager);
#endif
#ifdef MusicManager__GiveTime
REVERSE_DETOUR(void  MusicManager::GiveTime(void),MusicManager__GiveTime);
#endif
#ifdef MusicManager__Clear
REVERSE_DETOUR(void  MusicManager::Clear(class SoundAsset *),MusicManager__Clear);
#endif
#ifdef MusicManager__SetVolumeLevel
REVERSE_DETOUR(void  MusicManager::SetVolumeLevel(float),MusicManager__SetVolumeLevel);
#endif
#ifdef MusicManager__Clear1
REVERSE_DETOUR(void  MusicManager::Clear(int),MusicManager__Clear1);
#endif
#ifdef MusicManager__Set
REVERSE_DETOUR(void  MusicManager::Set(int,class SoundAsset *,int,float,int,int,int,int,int,int),MusicManager__Set);
#endif
#ifdef MusicManager__Play
REVERSE_DETOUR(void  MusicManager::Play(int),MusicManager__Play);
#endif
#ifdef MusicManager__Stop
REVERSE_DETOUR(void  MusicManager::Stop(int),MusicManager__Stop);
#endif
#ifdef MusicManager__Enable
REVERSE_DETOUR(void  MusicManager::Enable(bool),MusicManager__Enable);
#endif
#ifdef SpellManager__SpellManager
REVERSE_DETOUR( SpellManager::SpellManager(char *),SpellManager__SpellManager);
#endif
#ifdef SpellManager__dSpellManager
REVERSE_DETOUR( SpellManager::~SpellManager(void),SpellManager__dSpellManager);
#endif
#ifdef CStoryWnd__CStoryWnd
REVERSE_DETOUR( CStoryWnd::CStoryWnd(class CXWnd *),CStoryWnd__CStoryWnd);
#endif
#ifdef CStoryWnd__Init
REVERSE_DETOUR(void  CStoryWnd::Init(void),CStoryWnd__Init);
#endif
#ifdef CStoryWnd__SaveIni
REVERSE_DETOUR(void  CStoryWnd::SaveIni(void),CStoryWnd__SaveIni);
#endif
#ifdef CStoryWnd__ShowAuto
REVERSE_DETOUR(bool  CStoryWnd::ShowAuto(void),CStoryWnd__ShowAuto);
#endif
#ifdef CStoryWnd__HasNew
REVERSE_DETOUR(bool  CStoryWnd::HasNew(void),CStoryWnd__HasNew);
#endif
#ifdef CStoryWnd__Activate
REVERSE_DETOUR(void  CStoryWnd::Activate(void),CStoryWnd__Activate);
#endif
#ifdef CStoryWnd__SelectOldestNew
REVERSE_DETOUR(void  CStoryWnd::SelectOldestNew(void),CStoryWnd__SelectOldestNew);
#endif
#ifdef CStoryWnd__SelectIndex
REVERSE_DETOUR(void  CStoryWnd::SelectIndex(int),CStoryWnd__SelectIndex);
#endif
#ifdef StringItem__StringItem
REVERSE_DETOUR( StringItem::StringItem(void),StringItem__StringItem);
#endif
#ifdef UdpReliableChannel__IncomingQueueEntry__IncomingQueueEntry
//REVERSE_DETOUR( UdpReliableChannel::IncomingQueueEntry::IncomingQueueEntry(void),UdpReliableChannel__IncomingQueueEntry__IncomingQueueEntry);
#endif
#ifdef StringItem__dStringItem
REVERSE_DETOUR( StringItem::~StringItem(void),StringItem__dStringItem);
#endif
#ifdef StringItem__load
REVERSE_DETOUR(int  StringItem::load(struct _iobuf *,int),StringItem__load);
#endif
#ifdef StringTable__StringTable
REVERSE_DETOUR( StringTable::StringTable(void),StringTable__StringTable);
#endif
#ifdef StringTable__dStringTable
REVERSE_DETOUR( StringTable::~StringTable(void),StringTable__dStringTable);
#endif
#ifdef StringTable__checkAlloc
REVERSE_DETOUR(void  StringTable::checkAlloc(void),StringTable__checkAlloc);
#endif
#ifdef StringTable__getString
REVERSE_DETOUR(char *  StringTable::getString(unsigned long,bool *),StringTable__getString);
#endif
#ifdef StringTable__findItem
REVERSE_DETOUR(class StringItem *  StringTable::findItem(unsigned long,int,int),StringTable__findItem);
#endif
#ifdef StringTable__load
REVERSE_DETOUR(int  StringTable::load(char const *,int),StringTable__load);
#endif
#ifdef StringTable__addItem
REVERSE_DETOUR(void  StringTable::addItem(class StringItem *),StringTable__addItem);
#endif
#ifdef UdpIpAddress__UdpIpAddress
REVERSE_DETOUR( UdpIpAddress::UdpIpAddress(unsigned int),UdpIpAddress__UdpIpAddress);
#endif
#ifdef UdpManager__Params__Params
//REVERSE_DETOUR( UdpManager::Params::Params(void),UdpManager__Params__Params);
#endif
#ifdef UdpManager__UdpManager
//REVERSE_DETOUR( UdpManager::UdpManager(struct UdpManager::Params const *),UdpManager__UdpManager);
#endif
#ifdef UdpManager__PoolReturn
//REVERSE_DETOUR(void  UdpManager::PoolReturn(class PooledLogicalPacket *),UdpManager__PoolReturn);
#endif
#ifdef UdpManager__dUdpManager
REVERSE_DETOUR( UdpManager::~UdpManager(void),UdpManager__dUdpManager);
#endif
#ifdef UdpManager__CreateAndBindSocket
REVERSE_DETOUR(void  UdpManager::CreateAndBindSocket(int),UdpManager__CreateAndBindSocket);
#endif
#ifdef UdpManager__CloseSocket
REVERSE_DETOUR(void  UdpManager::CloseSocket(void),UdpManager__CloseSocket);
#endif
#ifdef UdpManager__ProcessDisconnectPending
REVERSE_DETOUR(void  UdpManager::ProcessDisconnectPending(void),UdpManager__ProcessDisconnectPending);
#endif
#ifdef UdpManager__RemoveConnection
REVERSE_DETOUR(void  UdpManager::RemoveConnection(class UdpConnection *),UdpManager__RemoveConnection);
#endif
#ifdef UdpManager__AddConnection
REVERSE_DETOUR(void  UdpManager::AddConnection(class UdpConnection *),UdpManager__AddConnection);
#endif
#ifdef UdpManager__GiveTime
REVERSE_DETOUR(bool  UdpManager::GiveTime(int,bool),UdpManager__GiveTime);
#endif
#ifdef UdpManager__EstablishConnection
REVERSE_DETOUR(class UdpConnection *  UdpManager::EstablishConnection(char const *,int,int),UdpManager__EstablishConnection);
#endif
#ifdef UdpManager__KeepUntilDisconnected
REVERSE_DETOUR(void  UdpManager::KeepUntilDisconnected(class UdpConnection *),UdpManager__KeepUntilDisconnected);
#endif
#ifdef UdpManager__ResetStats
REVERSE_DETOUR(void  UdpManager::ResetStats(void),UdpManager__ResetStats);
#endif
#ifdef UdpManager__ActualReceive
//REVERSE_DETOUR(class UdpManager::PacketHistoryEntry *  UdpManager::ActualReceive(void),UdpManager__ActualReceive);
#endif
#ifdef UdpManager__ActualSend
REVERSE_DETOUR(void  UdpManager::ActualSend(unsigned char const *,int,class UdpIpAddress,int),UdpManager__ActualSend);
#endif
#ifdef UdpManager__ActualSendHelper
REVERSE_DETOUR(void  UdpManager::ActualSendHelper(unsigned char const *,int,class UdpIpAddress,int),UdpManager__ActualSendHelper);
#endif
#ifdef UdpManager__SendPortAlive
REVERSE_DETOUR(void  UdpManager::SendPortAlive(class UdpIpAddress,int),UdpManager__SendPortAlive);
#endif
#ifdef UdpManager__ProcessRawPacket
//REVERSE_DETOUR(void  UdpManager::ProcessRawPacket(class UdpManager::PacketHistoryEntry const *),UdpManager__ProcessRawPacket);
#endif
#ifdef UdpManager__AddressGetConnection
REVERSE_DETOUR(class UdpConnection *  UdpManager::AddressGetConnection(class UdpIpAddress,int)const ,UdpManager__AddressGetConnection);
#endif
#ifdef UdpManager__ConnectCodeGetConnection
REVERSE_DETOUR(class UdpConnection *  UdpManager::ConnectCodeGetConnection(int)const ,UdpManager__ConnectCodeGetConnection);
#endif
#ifdef UdpManager__WrappedBorrow
//REVERSE_DETOUR(class WrappedLogicalPacket *  UdpManager::WrappedBorrow(class LogicalPacket const *),UdpManager__WrappedBorrow);
#endif
#ifdef UdpManager__WrappedCreated
//REVERSE_DETOUR(void  UdpManager::WrappedCreated(class WrappedLogicalPacket *),UdpManager__WrappedCreated);
#endif
#ifdef UdpManager__WrappedDestroyed
//REVERSE_DETOUR(void  UdpManager::WrappedDestroyed(class WrappedLogicalPacket *),UdpManager__WrappedDestroyed);
#endif
#ifdef UdpManager__CreatePacket
REVERSE_DETOUR(class LogicalPacket *  UdpManager::CreatePacket(void const *,int,void const *,int),UdpManager__CreatePacket);
#endif
#ifdef UdpManager__PoolCreated
//REVERSE_DETOUR(void  UdpManager::PoolCreated(class PooledLogicalPacket *),UdpManager__PoolCreated);
#endif
#ifdef UdpManager__PoolDestroyed
//REVERSE_DETOUR(void  UdpManager::PoolDestroyed(class PooledLogicalPacket *),UdpManager__PoolDestroyed);
#endif
#ifdef UdpManager__PacketHistoryEntry__PacketHistoryEntry
//REVERSE_DETOUR( UdpManager::PacketHistoryEntry::PacketHistoryEntry(int),UdpManager__PacketHistoryEntry__PacketHistoryEntry);
#endif
#ifdef UdpManager__PacketHistoryEntry__dPacketHistoryEntry
//REVERSE_DETOUR( UdpManager::PacketHistoryEntry::~PacketHistoryEntry(void),UdpManager__PacketHistoryEntry__dPacketHistoryEntry);
#endif
#ifdef UdpManager__SimulateQueueEntry__dSimulateQueueEntry
//REVERSE_DETOUR( UdpManager::SimulateQueueEntry::~SimulateQueueEntry(void),UdpManager__SimulateQueueEntry__dSimulateQueueEntry);
#endif
#ifdef UdpConnection__UdpConnection
REVERSE_DETOUR( UdpConnection::UdpConnection(class UdpManager *,class UdpIpAddress,int,int),UdpConnection__UdpConnection);
#endif
#ifdef UdpConnection__UdpConnection1
//REVERSE_DETOUR( UdpConnection::UdpConnection(class UdpManager *,class UdpManager::PacketHistoryEntry const *),UdpConnection__UdpConnection1);
#endif
#ifdef UdpConnection__Init
REVERSE_DETOUR(void  UdpConnection::Init(class UdpManager *,class UdpIpAddress,int),UdpConnection__Init);
#endif
#ifdef UdpConnection__dUdpConnection
REVERSE_DETOUR( UdpConnection::~UdpConnection(void),UdpConnection__dUdpConnection);
#endif
#ifdef UdpConnection__PortUnreachable
REVERSE_DETOUR(void  UdpConnection::PortUnreachable(void),UdpConnection__PortUnreachable);
#endif
#ifdef UdpConnection__InternalDisconnect
//REVERSE_DETOUR(void  UdpConnection::InternalDisconnect(int,enum UdpConnection::DisconnectReason),UdpConnection__InternalDisconnect);
#endif
#ifdef UdpConnection__ScheduleTimeNow
REVERSE_DETOUR(void  UdpConnection::ScheduleTimeNow(void),UdpConnection__ScheduleTimeNow);
#endif
#ifdef UdpConnection__SendTerminatePacket
//REVERSE_DETOUR(void  UdpConnection::SendTerminatePacket(int,enum UdpConnection::DisconnectReason),UdpConnection__SendTerminatePacket);
#endif
#ifdef UdpMisc__PutValue32
REVERSE_DETOUR(int __cdecl UdpMisc::PutValue32(void *,unsigned int),UdpMisc__PutValue32);
#endif
#ifdef UdpConnection__SetSilentDisconnect
REVERSE_DETOUR(void  UdpConnection::SetSilentDisconnect(bool),UdpConnection__SetSilentDisconnect);
#endif
#ifdef UdpConnection__Send
//REVERSE_DETOUR(bool  UdpConnection::Send(enum UdpChannel,void const *,int),UdpConnection__Send);
#endif
#ifdef UdpConnection__InternalSend
//REVERSE_DETOUR(bool  UdpConnection::InternalSend(enum UdpChannel,unsigned char const *,int,unsigned char const *,int),UdpConnection__InternalSend);
#endif
#ifdef UdpConnection__PingStatReset
REVERSE_DETOUR(void  UdpConnection::PingStatReset(void),UdpConnection__PingStatReset);
#endif
#ifdef UdpConnection__ProcessRawPacket
//REVERSE_DETOUR(void  UdpConnection::ProcessRawPacket(class UdpManager::PacketHistoryEntry const *),UdpConnection__ProcessRawPacket);
#endif
#ifdef UdpMisc__GetValue24
REVERSE_DETOUR(unsigned int __cdecl UdpMisc::GetValue24(void const *),UdpMisc__GetValue24);
#endif
#ifdef UdpConnection__IsNonEncryptPacket
REVERSE_DETOUR(bool  UdpConnection::IsNonEncryptPacket(unsigned char const *)const ,UdpConnection__IsNonEncryptPacket);
#endif
#ifdef UdpConnection__CallbackRoutePacket
REVERSE_DETOUR(void  UdpConnection::CallbackRoutePacket(unsigned char const *,int),UdpConnection__CallbackRoutePacket);
#endif
#ifdef UdpConnection__CallbackCorruptPacket
//REVERSE_DETOUR(void  UdpConnection::CallbackCorruptPacket(unsigned char const *,int,enum UdpCorruptionReason),UdpConnection__CallbackCorruptPacket);
#endif
#ifdef UdpConnection__ProcessCookedPacket
REVERSE_DETOUR(void  UdpConnection::ProcessCookedPacket(unsigned char const *,int),UdpConnection__ProcessCookedPacket);
#endif
#ifdef UdpMisc__PutValue64
REVERSE_DETOUR(int __cdecl UdpMisc::PutValue64(void *,__int64),UdpMisc__PutValue64);
#endif
#ifdef UdpMisc__GetValue64
REVERSE_DETOUR(__int64 __cdecl UdpMisc::GetValue64(void const *),UdpMisc__GetValue64);
#endif
#ifdef UdpReliableChannel__AckPacket
REVERSE_DETOUR(void  UdpReliableChannel::AckPacket(unsigned char const *,int),UdpReliableChannel__AckPacket);
#endif
#ifdef UdpConnection__GiveTime
REVERSE_DETOUR(void  UdpConnection::GiveTime(void),UdpConnection__GiveTime);
#endif
#ifdef UdpConnection__InternalGiveTime
REVERSE_DETOUR(void  UdpConnection::InternalGiveTime(void),UdpConnection__InternalGiveTime);
#endif
#ifdef UdpConnection__LastReceive
REVERSE_DETOUR(int  UdpConnection::LastReceive(void)const ,UdpConnection__LastReceive);
#endif
#ifdef UdpConnection__ConnectionAge
REVERSE_DETOUR(int  UdpConnection::ConnectionAge(void)const ,UdpConnection__ConnectionAge);
#endif
#ifdef UdpConnection__TotalPendingBytes
REVERSE_DETOUR(int  UdpConnection::TotalPendingBytes(void)const ,UdpConnection__TotalPendingBytes);
#endif
#ifdef UdpConnection__RawSend
REVERSE_DETOUR(void  UdpConnection::RawSend(unsigned char const *,int),UdpConnection__RawSend);
#endif
#ifdef UdpConnection__ExpireSendBin
REVERSE_DETOUR(int  UdpConnection::ExpireSendBin(void),UdpConnection__ExpireSendBin);
#endif
#ifdef UdpConnection__ExpireReceiveBin
REVERSE_DETOUR(int  UdpConnection::ExpireReceiveBin(void),UdpConnection__ExpireReceiveBin);
#endif
#ifdef UdpConnection__PhysicalSend
REVERSE_DETOUR(void  UdpConnection::PhysicalSend(unsigned char const *,int,bool),UdpConnection__PhysicalSend);
#endif
#ifdef UdpMisc__PutValue24
REVERSE_DETOUR(int __cdecl UdpMisc::PutValue24(void *,unsigned int),UdpMisc__PutValue24);
#endif
#ifdef UdpConnection__BufferedSend
REVERSE_DETOUR(unsigned char *  UdpConnection::BufferedSend(unsigned char const *,int,unsigned char const *,int,bool),UdpConnection__BufferedSend);
#endif
#ifdef UdpConnection__FlushMultiBuffer
REVERSE_DETOUR(void  UdpConnection::FlushMultiBuffer(void),UdpConnection__FlushMultiBuffer);
#endif
#ifdef UdpConnection__DecryptNone
REVERSE_DETOUR(int  UdpConnection::DecryptNone(unsigned char *,unsigned char const *,int),UdpConnection__DecryptNone);
#endif
#ifdef UdpConnection__EncryptNone
REVERSE_DETOUR(int  UdpConnection::EncryptNone(unsigned char *,unsigned char const *,int),UdpConnection__EncryptNone);
#endif
#ifdef UdpConnection__EncryptUserSupplied
REVERSE_DETOUR(int  UdpConnection::EncryptUserSupplied(unsigned char *,unsigned char const *,int),UdpConnection__EncryptUserSupplied);
#endif
#ifdef UdpConnection__DecryptUserSupplied
REVERSE_DETOUR(int  UdpConnection::DecryptUserSupplied(unsigned char *,unsigned char const *,int),UdpConnection__DecryptUserSupplied);
#endif
#ifdef UdpConnection__EncryptUserSupplied2
REVERSE_DETOUR(int  UdpConnection::EncryptUserSupplied2(unsigned char *,unsigned char const *,int),UdpConnection__EncryptUserSupplied2);
#endif
#ifdef UdpConnection__DecryptUserSupplied2
REVERSE_DETOUR(int  UdpConnection::DecryptUserSupplied2(unsigned char *,unsigned char const *,int),UdpConnection__DecryptUserSupplied2);
#endif
#ifdef UdpConnection__EncryptXorBuffer
REVERSE_DETOUR(int  UdpConnection::EncryptXorBuffer(unsigned char *,unsigned char const *,int),UdpConnection__EncryptXorBuffer);
#endif
#ifdef UdpConnection__DecryptXorBuffer
REVERSE_DETOUR(int  UdpConnection::DecryptXorBuffer(unsigned char *,unsigned char const *,int),UdpConnection__DecryptXorBuffer);
#endif
#ifdef UdpConnection__EncryptXor
REVERSE_DETOUR(int  UdpConnection::EncryptXor(unsigned char *,unsigned char const *,int),UdpConnection__EncryptXor);
#endif
#ifdef UdpConnection__DecryptXor
REVERSE_DETOUR(int  UdpConnection::DecryptXor(unsigned char *,unsigned char const *,int),UdpConnection__DecryptXor);
#endif
#ifdef UdpConnection__SetupEncryptModel
REVERSE_DETOUR(void  UdpConnection::SetupEncryptModel(void),UdpConnection__SetupEncryptModel);
#endif
#ifdef UdpConnection__GetChannelStatus
//REVERSE_DETOUR(void  UdpConnection::GetChannelStatus(enum UdpChannel,struct UdpConnection::ChannelStatus *)const ,UdpConnection__GetChannelStatus);
#endif
#ifdef UdpReliableChannel__UdpReliableChannel
//REVERSE_DETOUR( UdpReliableChannel::UdpReliableChannel(int,class UdpConnection *,struct UdpManager::ReliableConfig *),UdpReliableChannel__UdpReliableChannel);
#endif
#ifdef UdpReliableChannel__dUdpReliableChannel
REVERSE_DETOUR( UdpReliableChannel::~UdpReliableChannel(void),UdpReliableChannel__dUdpReliableChannel);
#endif
#ifdef UdpReliableChannel__Send
REVERSE_DETOUR(void  UdpReliableChannel::Send(unsigned char const *,int,unsigned char const *,int),UdpReliableChannel__Send);
#endif
#ifdef UdpReliableChannel__FlushCoalesce
REVERSE_DETOUR(void  UdpReliableChannel::FlushCoalesce(void),UdpReliableChannel__FlushCoalesce);
#endif
#ifdef UdpReliableChannel__SendCoalesce
REVERSE_DETOUR(void  UdpReliableChannel::SendCoalesce(unsigned char const *,int,unsigned char const *,int),UdpReliableChannel__SendCoalesce);
#endif
#ifdef UdpReliableChannel__QueueLogicalPacket
REVERSE_DETOUR(void  UdpReliableChannel::QueueLogicalPacket(class LogicalPacket const *),UdpReliableChannel__QueueLogicalPacket);
#endif
#ifdef UdpReliableChannel__PullDown
REVERSE_DETOUR(bool  UdpReliableChannel::PullDown(int),UdpReliableChannel__PullDown);
#endif
#ifdef UdpReliableChannel__GiveTime
REVERSE_DETOUR(int  UdpReliableChannel::GiveTime(void),UdpReliableChannel__GiveTime);
#endif
#ifdef UdpReliableChannel__GetChannelStatus
//REVERSE_DETOUR(void  UdpReliableChannel::GetChannelStatus(struct UdpConnection::ChannelStatus *)const ,UdpReliableChannel__GetChannelStatus);
#endif
#ifdef UdpReliableChannel__ReliablePacket
REVERSE_DETOUR(void  UdpReliableChannel::ReliablePacket(unsigned char const *,int),UdpReliableChannel__ReliablePacket);
#endif
#ifdef UdpReliableChannel__GetReliableIncomingId
REVERSE_DETOUR(__int64  UdpReliableChannel::GetReliableIncomingId(int)const ,UdpReliableChannel__GetReliableIncomingId);
#endif
#ifdef UdpReliableChannel__ProcessPacket
//REVERSE_DETOUR(void  UdpReliableChannel::ProcessPacket(enum UdpReliableChannel::ReliablePacketMode,unsigned char const *,int),UdpReliableChannel__ProcessPacket);
#endif
#ifdef UdpReliableChannel__AckAllPacket
REVERSE_DETOUR(void  UdpReliableChannel::AckAllPacket(unsigned char const *,int),UdpReliableChannel__AckAllPacket);
#endif
#ifdef UdpReliableChannel__Ack
REVERSE_DETOUR(void  UdpReliableChannel::Ack(__int64),UdpReliableChannel__Ack);
#endif
#ifdef UdpReliableChannel__IncomingQueueEntry__dIncomingQueueEntry
//REVERSE_DETOUR( UdpReliableChannel::IncomingQueueEntry::~IncomingQueueEntry(void),UdpReliableChannel__IncomingQueueEntry__dIncomingQueueEntry);
#endif
#ifdef UdpReliableChannel__PhysicalPacket__PhysicalPacket
//REVERSE_DETOUR( UdpReliableChannel::PhysicalPacket::PhysicalPacket(void),UdpReliableChannel__PhysicalPacket__PhysicalPacket);
#endif
#ifdef UdpReliableChannel__PhysicalPacket__dPhysicalPacket
//REVERSE_DETOUR( UdpReliableChannel::PhysicalPacket::~PhysicalPacket(void),UdpReliableChannel__PhysicalPacket__dPhysicalPacket);
#endif
#ifdef LogicalPacket__LogicalPacket
REVERSE_DETOUR( LogicalPacket::LogicalPacket(void),LogicalPacket__LogicalPacket);
#endif
#ifdef SoundObject__AddRef
//REVERSE_DETOUR(void  SoundObject::AddRef(void),SoundObject__AddRef);
#endif
#ifdef Mp3Manager__GetPosition
REVERSE_DETOUR(int  Mp3Manager::GetPosition(void),Mp3Manager__GetPosition);
#endif
#ifdef SimpleLogicalPacket__SimpleLogicalPacket
REVERSE_DETOUR( SimpleLogicalPacket::SimpleLogicalPacket(void const *,int),SimpleLogicalPacket__SimpleLogicalPacket);
#endif
#ifdef EmitterManager__SetVolumeLevel
REVERSE_DETOUR(void  EmitterManager::SetVolumeLevel(float),EmitterManager__SetVolumeLevel);
#endif
#ifdef PooledLogicalPacket__PooledLogicalPacket
//REVERSE_DETOUR( PooledLogicalPacket::PooledLogicalPacket(class UdpManager *,int),PooledLogicalPacket__PooledLogicalPacket);
#endif
#ifdef ChannelServerApi__GetChannelCount
REVERSE_DETOUR(int  ChannelServerApi::GetChannelCount(void),ChannelServerApi__GetChannelCount);
#endif
#ifdef PooledLogicalPacket__SetData
//REVERSE_DETOUR(void  PooledLogicalPacket::SetData(void const *,int,void const *,int),PooledLogicalPacket__SetData);
#endif
#ifdef WrappedLogicalPacket__WrappedLogicalPacket
//REVERSE_DETOUR( WrappedLogicalPacket::WrappedLogicalPacket(class UdpManager *),WrappedLogicalPacket__WrappedLogicalPacket);
#endif
#ifdef UdpManager__WrappedReturn
//REVERSE_DETOUR(void  UdpManager::WrappedReturn(class WrappedLogicalPacket *),UdpManager__WrappedReturn);
#endif
#ifdef WrappedLogicalPacket__SetLogicalPacket
//REVERSE_DETOUR(void  WrappedLogicalPacket::SetLogicalPacket(class LogicalPacket const *),WrappedLogicalPacket__SetLogicalPacket);
#endif
#ifdef UdpManager__SimulateQueueEntry__SimulateQueueEntry
//REVERSE_DETOUR( UdpManager::SimulateQueueEntry::SimulateQueueEntry(unsigned char const *,int,class UdpIpAddress,int),UdpManager__SimulateQueueEntry__SimulateQueueEntry);
#endif
#ifdef UdpMisc__Clock
REVERSE_DETOUR(__int64 __cdecl UdpMisc::Clock(void),UdpMisc__Clock);
#endif
#ifdef UdpMisc__SyncStampShortDeltaTime
REVERSE_DETOUR(int __cdecl UdpMisc::SyncStampShortDeltaTime(unsigned short,unsigned short),UdpMisc__SyncStampShortDeltaTime);
#endif
#ifdef UdpMisc__Random
REVERSE_DETOUR(int __cdecl UdpMisc::Random(int *),UdpMisc__Random);
#endif
#ifdef UdpMisc__Crc32
REVERSE_DETOUR(int __cdecl UdpMisc::Crc32(void const *,int,int),UdpMisc__Crc32);
#endif
#ifdef UdpMisc__PutVariableValue
REVERSE_DETOUR(unsigned int __cdecl UdpMisc::PutVariableValue(void *,unsigned int),UdpMisc__PutVariableValue);
#endif
#ifdef UdpMisc__GetVariableValue
REVERSE_DETOUR(unsigned int __cdecl UdpMisc::GetVariableValue(void const *,unsigned int *),UdpMisc__GetVariableValue);
#endif
#ifdef UdpMisc__CreateQuickLogicalPacket
REVERSE_DETOUR(class LogicalPacket * __cdecl UdpMisc::CreateQuickLogicalPacket(void const *,int,void const *,int),UdpMisc__CreateQuickLogicalPacket);
#endif
#ifdef Util__Stristr
//REVERSE_DETOUR(char * __cdecl Util::Stristr(char *,char *),Util__Stristr);
#endif
#ifdef Util__StripCharacter
//REVERSE_DETOUR(void __cdecl Util::StripCharacter(char *,char),Util__StripCharacter);
#endif
#ifdef Util__ClampLower
//REVERSE_DETOUR(bool __cdecl Util::ClampLower(int *,int),Util__ClampLower);
#endif
#ifdef Util__ClampUpper
//REVERSE_DETOUR(bool __cdecl Util::ClampUpper(int *,int),Util__ClampUpper);
#endif
#ifdef Util__GetNextStringToken
//REVERSE_DETOUR(int __cdecl Util::GetNextStringToken(char *,char *,int,char *,bool),Util__GetNextStringToken);
#endif
#ifdef Util__IsDelimiter
//REVERSE_DETOUR(bool __cdecl Util::IsDelimiter(char,char *),Util__IsDelimiter);
#endif
#ifdef Util__Crc32
//REVERSE_DETOUR(int __cdecl Util::Crc32(void const *,int,int),Util__Crc32);
#endif
#ifdef Util__GetSavePrivateProfileInt
//REVERSE_DETOUR(int __cdecl Util::GetSavePrivateProfileInt(char *,char *,int,char *),Util__GetSavePrivateProfileInt);
#endif
#ifdef Util__PutValueVariable
//REVERSE_DETOUR(int __cdecl Util::PutValueVariable(void *,unsigned int),Util__PutValueVariable);
#endif
#ifdef Util__PutValue32
//REVERSE_DETOUR(unsigned int __cdecl Util::PutValue32(void *,unsigned int),Util__PutValue32);
#endif
#ifdef Util__GetValueVariable
//REVERSE_DETOUR(int __cdecl Util::GetValueVariable(void const *,unsigned int *),Util__GetValueVariable);
#endif
#ifdef TextFileReader__TextFileReader
REVERSE_DETOUR( TextFileReader::TextFileReader(char *,char),TextFileReader__TextFileReader);
#endif
#ifdef TextFileReader__dTextFileReader
REVERSE_DETOUR( TextFileReader::~TextFileReader(void),TextFileReader__dTextFileReader);
#endif
#ifdef TextFileReader__ReadLine
REVERSE_DETOUR(int  TextFileReader::ReadLine(void),TextFileReader__ReadLine);
#endif
#ifdef TextFileReader__GetNextField
REVERSE_DETOUR(int  TextFileReader::GetNextField(char *,int),TextFileReader__GetNextField);
#endif
#ifdef TextFileReader__GetLine
REVERSE_DETOUR(void  TextFileReader::GetLine(char *,int),TextFileReader__GetLine);
#endif
#ifdef TextFileReader__IsOpen
REVERSE_DETOUR(bool  TextFileReader::IsOpen(void),TextFileReader__IsOpen);
#endif
#ifdef flex_unit__get
REVERSE_DETOUR(unsigned int  flex_unit::get(unsigned int)const ,flex_unit__get);
#endif
#ifdef flex_unit__flex_unit
REVERSE_DETOUR( flex_unit::flex_unit(void),flex_unit__flex_unit);
#endif
#ifdef flex_unit__dflex_unit
REVERSE_DETOUR( flex_unit::~flex_unit(void),flex_unit__dflex_unit);
#endif
#ifdef flex_unit__reserve
REVERSE_DETOUR(void  flex_unit::reserve(unsigned int),flex_unit__reserve);
#endif
#ifdef flex_unit__set
REVERSE_DETOUR(void  flex_unit::set(unsigned int,unsigned int),flex_unit__set);
#endif
#ifdef flex_unit__fast_mul
REVERSE_DETOUR(void  flex_unit::fast_mul(class flex_unit &,class flex_unit &,unsigned int),flex_unit__fast_mul);
#endif
#ifdef vlong_value__is_zero
REVERSE_DETOUR(int  vlong_value::is_zero(void)const ,vlong_value__is_zero);
#endif
#ifdef vlong_value__test
REVERSE_DETOUR(int  vlong_value::test(unsigned int)const ,vlong_value__test);
#endif
#ifdef vlong_value__bits
REVERSE_DETOUR(unsigned int  vlong_value::bits(void)const ,vlong_value__bits);
#endif
#ifdef vlong_value__cf
REVERSE_DETOUR(int  vlong_value::cf(class vlong_value &)const ,vlong_value__cf);
#endif
#ifdef vlong_value__shl
REVERSE_DETOUR(void  vlong_value::shl(void),vlong_value__shl);
#endif
#ifdef vlong_value__shr
REVERSE_DETOUR(void  vlong_value::shr(void),vlong_value__shr);
#endif
#ifdef vlong_value__shr1
REVERSE_DETOUR(void  vlong_value::shr(unsigned int),vlong_value__shr1);
#endif
#ifdef vlong_value__add
REVERSE_DETOUR(void  vlong_value::add(class vlong_value &),vlong_value__add);
#endif
#ifdef vlong_value__subtract
REVERSE_DETOUR(void  vlong_value::subtract(class vlong_value &),vlong_value__subtract);
#endif
#ifdef vlong_value__init
REVERSE_DETOUR(void  vlong_value::init(unsigned int),vlong_value__init);
#endif
#ifdef vlong_value__init2
REVERSE_DETOUR(void  vlong_value::init2(unsigned int,unsigned int),vlong_value__init2);
#endif
#ifdef vlong_value__copy
REVERSE_DETOUR(void  vlong_value::copy(class vlong_value &),vlong_value__copy);
#endif
#ifdef vlong_value__vlong_value
REVERSE_DETOUR( vlong_value::vlong_value(void),vlong_value__vlong_value);
#endif
#ifdef vlong_value__mul
REVERSE_DETOUR(void  vlong_value::mul(class vlong_value &,class vlong_value &),vlong_value__mul);
#endif
#ifdef vlong_value__divide
REVERSE_DETOUR(void  vlong_value::divide(class vlong_value &,class vlong_value &,class vlong_value &),vlong_value__divide);
#endif
#ifdef vlong_value__dvlong_value
REVERSE_DETOUR( vlong_value::~vlong_value(void),vlong_value__dvlong_value);
#endif
#ifdef vlong__docopy
REVERSE_DETOUR(void  vlong::docopy(void),vlong__docopy);
#endif
#ifdef vlong__cf
//REVERSE_DETOUR(int  vlong::cf(class vlong)const ,vlong__cf);
#endif
#ifdef vlong__vlong
REVERSE_DETOUR( vlong::vlong(unsigned __int64),vlong__vlong);
#endif
#ifdef vlong__vlong1
REVERSE_DETOUR( vlong::vlong(class vlong const &),vlong__vlong1);
#endif
#ifdef vlong__operator_equal
REVERSE_DETOUR(class vlong &  vlong::operator=(class vlong),vlong__operator_equal);
#endif
#ifdef vlong__dvlong
REVERSE_DETOUR( vlong::~vlong(void),vlong__dvlong);
#endif
#ifdef vlong__operator_plus_equal
REVERSE_DETOUR(class vlong &  vlong::operator+=(class vlong const &),vlong__operator_plus_equal);
#endif
#ifdef vlong__operator_minus_equal
REVERSE_DETOUR(class vlong &  vlong::operator-=(class vlong const &),vlong__operator_minus_equal);
#endif
#ifdef monty__monty
REVERSE_DETOUR( monty::monty(class vlong const &),monty__monty);
#endif
#ifdef monty__mul
REVERSE_DETOUR(void  monty::mul(class vlong &,class vlong const &),monty__mul);
#endif
#ifdef monty__exp
REVERSE_DETOUR(class vlong  monty::exp(class vlong const &,class vlong const &),monty__exp);
#endif
#ifdef monty__dmonty
REVERSE_DETOUR( monty::~monty(void),monty__dmonty);
#endif
#ifdef ZlibUtil__zcalloc
REVERSE_DETOUR(void * __cdecl ZlibUtil::zcalloc(void *,unsigned int,unsigned int),ZlibUtil__zcalloc);
#endif
#ifdef ZlibUtil__zfree
REVERSE_DETOUR(void __cdecl ZlibUtil::zfree(void *,void *),ZlibUtil__zfree);
#endif
#ifdef ZlibUtil__zcompress
REVERSE_DETOUR(int __cdecl ZlibUtil::zcompress(unsigned char *,unsigned long *,unsigned char const *,unsigned long,int),ZlibUtil__zcompress);
#endif
#ifdef ZlibUtil__zuncompress
REVERSE_DETOUR(int __cdecl ZlibUtil::zuncompress(unsigned char *,unsigned long *,unsigned char const *,unsigned long),ZlibUtil__zuncompress);
#endif
#ifdef ZlibUtil__Compress
REVERSE_DETOUR(int __cdecl ZlibUtil::Compress(char const *,int,char *,int,int),ZlibUtil__Compress);
#endif
#ifdef ZlibUtil__Decompress
REVERSE_DETOUR(int __cdecl ZlibUtil::Decompress(char const *,int,char *,int),ZlibUtil__Decompress);
#endif
#ifdef PackFS__PackFS
REVERSE_DETOUR( PackFS::PackFS(void),PackFS__PackFS);
#endif
#ifdef PackFS__addFileSystem
//REVERSE_DETOUR(bool  PackFS::addFileSystem(class FilePath),PackFS__addFileSystem);
#endif
#ifdef PackFS__removeFileSystem
REVERSE_DETOUR(void  PackFS::removeFileSystem(class FilePath),PackFS__removeFileSystem);
#endif
#ifdef SharedString___updateTag
REVERSE_DETOUR(void  SharedString::_updateTag(void)const ,SharedString___updateTag);
#endif
#ifdef FilePath__FilePath2
REVERSE_DETOUR( FilePath::FilePath(void),FilePath__FilePath2);
#endif
#ifdef PackFile__dPackFile
REVERSE_DETOUR( PackFile::~PackFile(void),PackFile__dPackFile);
#endif
#ifdef PackFile__close
REVERSE_DETOUR(void  PackFile::close(void),PackFile__close);
#endif
#ifdef _PackFileData__d_PackFileData
REVERSE_DETOUR( _PackFileData::~_PackFileData(void),_PackFileData__d_PackFileData);
#endif
#ifdef PackFile__length
REVERSE_DETOUR(int  PackFile::length(void)const ,PackFile__length);
#endif
#ifdef PackFile__read
REVERSE_DETOUR(int  PackFile::read(void * const,int),PackFile__read);
#endif
#ifdef PackFS__openFile
//REVERSE_DETOUR(bool  PackFS::openFile(class FilePath,class PackFile *)const ,PackFS__openFile);
#endif
#ifdef CRC32Generator__generateCRC32
REVERSE_DETOUR(unsigned int  CRC32Generator::generateCRC32(unsigned char const *,unsigned int)const ,CRC32Generator__generateCRC32);
#endif
#ifdef CRC32Generator__updateCRC32
REVERSE_DETOUR(unsigned int  CRC32Generator::updateCRC32(unsigned int,unsigned char const *,unsigned int)const ,CRC32Generator__updateCRC32);
#endif
#ifdef CSidlScreenWnd__dCSidlScreenWnd
REVERSE_DETOUR( CSidlScreenWnd::~CSidlScreenWnd(void),CSidlScreenWnd__dCSidlScreenWnd);
#endif
#ifdef CSidlScreenWnd__WndNotification
REVERSE_DETOUR( int CSidlScreenWnd::WndNotification(class CXWnd *,unsigned __int32,void *),CSidlScreenWnd__WndNotification);
#endif
#ifdef CSidlScreenWnd__CSidlScreenWnd
REVERSE_DETOUR( CSidlScreenWnd::CSidlScreenWnd(class CXWnd *,unsigned __int32,class CXRect,class CXStr),CSidlScreenWnd__CSidlScreenWnd);
#endif
#ifdef CSidlScreenWnd__CSidlScreenWnd1
REVERSE_DETOUR( CSidlScreenWnd::CSidlScreenWnd(class CXWnd *x,class CXStr,int,char *),CSidlScreenWnd__CSidlScreenWnd1);
#endif
#ifdef CSidlScreenWnd__CSidlScreenWnd2
REVERSE_DETOUR( CSidlScreenWnd::CSidlScreenWnd(class CXWnd *x,class CXStr),CSidlScreenWnd__CSidlScreenWnd2);
#endif
#ifdef CSidlScreenWnd__Init
REVERSE_DETOUR(void  CSidlScreenWnd::Init(class CXWnd *,unsigned __int32,class CXRect,class CXStr,int,char *),CSidlScreenWnd__Init);
#endif
#ifdef CSidlScreenWnd__Init1
REVERSE_DETOUR(void  CSidlScreenWnd::Init(class CXWnd *,class CXStr,int,char *),CSidlScreenWnd__Init1);
#endif
#ifdef CSidlScreenWnd__SetScreen
REVERSE_DETOUR(void  CSidlScreenWnd::SetScreen(class CXStr*),CSidlScreenWnd__SetScreen);
#endif
#ifdef CSidlScreenWnd__LoadSidlScreen
REVERSE_DETOUR(void  CSidlScreenWnd::LoadSidlScreen(void),CSidlScreenWnd__LoadSidlScreen);
#endif
#ifdef CSidlScreenWnd__CalculateVSBRange
REVERSE_DETOUR(void  CSidlScreenWnd::CalculateVSBRange(void),CSidlScreenWnd__CalculateVSBRange);
#endif
#ifdef CSidlScreenWnd__CalculateHSBRange
REVERSE_DETOUR(void  CSidlScreenWnd::CalculateHSBRange(void),CSidlScreenWnd__CalculateHSBRange);
#endif
#ifdef CSidlScreenWnd__DrawSidlPiece
REVERSE_DETOUR(int  CSidlScreenWnd::DrawSidlPiece(class CScreenPieceTemplate *,class CXRect,class CXRect)const ,CSidlScreenWnd__DrawSidlPiece);
#endif
#ifdef CSidlScreenWnd__GetSidlPiece
REVERSE_DETOUR(class CScreenPieceTemplate *  CSidlScreenWnd::GetSidlPiece(class CXStr)const ,CSidlScreenWnd__GetSidlPiece);
#endif
#ifdef CSidlScreenWnd__GetSidlPieceRect
REVERSE_DETOUR(class CXRect  CSidlScreenWnd::GetSidlPieceRect(class CScreenPieceTemplate *,class CXRect)const ,CSidlScreenWnd__GetSidlPieceRect);
#endif
#ifdef CSidlScreenWnd__AddButtonToRadioGroup
REVERSE_DETOUR(void  CSidlScreenWnd::AddButtonToRadioGroup(class CXStr,class CButtonWnd *),CSidlScreenWnd__AddButtonToRadioGroup);
#endif
#ifdef CRadioGroup__CRadioGroup
REVERSE_DETOUR( CRadioGroup::CRadioGroup(class CXStr),CRadioGroup__CRadioGroup);
#endif
#ifdef CRadioGroup__GetName
REVERSE_DETOUR(class CXStr  CRadioGroup::GetName(void)const ,CRadioGroup__GetName);
#endif
#ifdef CSidlScreenWnd__CreateChildrenFromSidl
REVERSE_DETOUR(void  CSidlScreenWnd::CreateChildrenFromSidl(void),CSidlScreenWnd__CreateChildrenFromSidl);
#endif
#ifdef CSidlScreenWnd__StoreIniVis
REVERSE_DETOUR(void  CSidlScreenWnd::StoreIniVis(void),CSidlScreenWnd__StoreIniVis);
#endif
#ifdef CSidlScreenWnd__EnableIniStorage
REVERSE_DETOUR(void  CSidlScreenWnd::EnableIniStorage(int,char *),CSidlScreenWnd__EnableIniStorage);
#endif
#ifdef CSidlScreenWnd__ConvertToRes
REVERSE_DETOUR(int  CSidlScreenWnd::ConvertToRes(int,int,int,int),CSidlScreenWnd__ConvertToRes);
#endif
#ifdef CSidlScreenWnd__GetChildItem
REVERSE_DETOUR(class CXWnd *  CSidlScreenWnd::GetChildItem(class CXStr&)const ,CSidlScreenWnd__GetChildItem);
#endif
#ifdef CSidlScreenWnd__LoadIniListWnd
REVERSE_DETOUR(void  CSidlScreenWnd::LoadIniListWnd(class CListWnd *,char *),CSidlScreenWnd__LoadIniListWnd);
#endif
#ifdef CSidlScreenWnd__StoreIniListWnd
REVERSE_DETOUR(void  CSidlScreenWnd::StoreIniListWnd(class CListWnd const *,char *),CSidlScreenWnd__StoreIniListWnd);
#endif
#ifdef CXWndDrawTemplate__CXWndDrawTemplate
REVERSE_DETOUR( CXWndDrawTemplate::CXWndDrawTemplate(void),CXWndDrawTemplate__CXWndDrawTemplate);
#endif
#ifdef CUITextureInfo__CUITextureInfo1
REVERSE_DETOUR( CUITextureInfo::CUITextureInfo(void),CUITextureInfo__CUITextureInfo1);
#endif
#ifdef CButtonDrawTemplate__CButtonDrawTemplate
REVERSE_DETOUR( CButtonDrawTemplate::CButtonDrawTemplate(void),CButtonDrawTemplate__CButtonDrawTemplate);
#endif
#ifdef CScrollbarTemplate__dCScrollbarTemplate
REVERSE_DETOUR( CScrollbarTemplate::~CScrollbarTemplate(void),CScrollbarTemplate__dCScrollbarTemplate);
#endif
#ifdef CXWndDrawTemplate__dCXWndDrawTemplate
REVERSE_DETOUR( CXWndDrawTemplate::~CXWndDrawTemplate(void),CXWndDrawTemplate__dCXWndDrawTemplate);
#endif
#ifdef CButtonDrawTemplate__GetSize
REVERSE_DETOUR(class CXSize  CButtonDrawTemplate::GetSize(void)const ,CButtonDrawTemplate__GetSize);
#endif
#ifdef CXWnd__CXWnd
REVERSE_DETOUR( CXWnd::CXWnd(class CXWnd *,unsigned __int32,class CXRect),CXWnd__CXWnd);
#endif
#ifdef CXWnd__IsType
//REVERSE_DETOUR(bool  CXWnd::IsType(enum EWndRuntimeType)const ,CXWnd__IsType);
#endif
#ifdef CXWnd__SetFocus
REVERSE_DETOUR(class CXWnd *  CXWnd::SetFocus(void),CXWnd__SetFocus);
#endif
#ifdef CXWnd__ClrFocus
REVERSE_DETOUR(void  CXWnd::ClrFocus(void),CXWnd__ClrFocus);
#endif
#ifdef CXWnd__HasFocus
REVERSE_DETOUR(bool  CXWnd::HasFocus(void)const ,CXWnd__HasFocus);
#endif
#ifdef CXWnd__Show
REVERSE_DETOUR(int  CXWnd::Show(bool,bool),CXWnd__Show);
#endif
#ifdef CXWnd__DrawCloseBox
REVERSE_DETOUR(int  CXWnd::DrawCloseBox(void)const ,CXWnd__DrawCloseBox);
#endif
#ifdef CXWnd__DrawMinimizeBox
REVERSE_DETOUR(int  CXWnd::DrawMinimizeBox(void)const ,CXWnd__DrawMinimizeBox);
#endif
#ifdef CXWnd__DrawTileBox
REVERSE_DETOUR(int  CXWnd::DrawTileBox(void)const ,CXWnd__DrawTileBox);
#endif
#ifdef CXWnd__DrawVScrollbar
REVERSE_DETOUR(int  CXWnd::DrawVScrollbar(int,int,int)const ,CXWnd__DrawVScrollbar);
#endif
#ifdef CXRect__CXRect
REVERSE_DETOUR( CXRect::CXRect(int,int,int,int),CXRect__CXRect);
#endif
#ifdef CXRect__operator_equal
REVERSE_DETOUR(class CXRect &  CXRect::operator=(class CXRect const &),CXRect__operator_equal);
#endif
#ifdef CXWnd__DrawHScrollbar
REVERSE_DETOUR(int  CXWnd::DrawHScrollbar(int,int,int)const ,CXWnd__DrawHScrollbar);
#endif
#ifdef CXWnd__Refade
REVERSE_DETOUR(void  CXWnd::Refade(void),CXWnd__Refade);
#endif
#ifdef CXWnd__Move
REVERSE_DETOUR(int  CXWnd::Move(class CXPoint),CXWnd__Move);
#endif
#ifdef CXWnd__Move1
REVERSE_DETOUR(int  CXWnd::Move(class CXRect),CXWnd__Move1);
#endif
#ifdef CXPoint__operator_equal
REVERSE_DETOUR(class CXPoint  CXPoint::operator=(class CXPoint),CXPoint__operator_equal);
#endif
#ifdef CXWnd__ProcessTransition
REVERSE_DETOUR(int  CXWnd::ProcessTransition(void),CXWnd__ProcessTransition);
#endif
#ifdef CXWnd__BringToTop
REVERSE_DETOUR(void  CXWnd::BringToTop(bool),CXWnd__BringToTop);
#endif
#ifdef CXWnd__StartFade
REVERSE_DETOUR(void  CXWnd::StartFade(unsigned char,unsigned __int32),CXWnd__StartFade);
#endif
#ifdef CXWnd__Minimize
REVERSE_DETOUR(int  CXWnd::Minimize(bool),CXWnd__Minimize);
#endif
#ifdef CXWnd__IsReallyVisible
REVERSE_DETOUR(bool  CXWnd::IsReallyVisible(void)const ,CXWnd__IsReallyVisible);
#endif
#ifdef CXWnd__GetNextChildWnd
REVERSE_DETOUR(class CXWnd *  CXWnd::GetNextChildWnd(class CXWnd *)const ,CXWnd__GetNextChildWnd);
#endif
#ifdef CXWnd__GetChildWndAt
REVERSE_DETOUR(class CXWnd *  CXWnd::GetChildWndAt(class CXPoint)const ,CXWnd__GetChildWndAt);
#endif
#ifdef CXWnd__GetFirstChildWnd
REVERSE_DETOUR(class CXWnd *  CXWnd::GetFirstChildWnd(void)const ,CXWnd__GetFirstChildWnd);
#endif
#ifdef CXWnd__GetNextSib
REVERSE_DETOUR(class CXWnd *  CXWnd::GetNextSib(void)const ,CXWnd__GetNextSib);
#endif
#ifdef CXWnd__DoAllDrawing
REVERSE_DETOUR(int  CXWnd::DoAllDrawing(void)const ,CXWnd__DoAllDrawing);
#endif
#ifdef CXWnd__DrawLasso
REVERSE_DETOUR(int __cdecl CXWnd::DrawLasso(class CXRect,unsigned long,class CXRect),CXWnd__DrawLasso);
#endif
#ifdef CXWnd__DrawChildren
REVERSE_DETOUR(int  CXWnd::DrawChildren(void)const ,CXWnd__DrawChildren);
#endif
#ifdef CXWnd__BringChildWndToTop
REVERSE_DETOUR(void  CXWnd::BringChildWndToTop(class CXWnd *),CXWnd__BringChildWndToTop);
#endif
#ifdef CXWnd__DrawColoredRect
REVERSE_DETOUR(int __cdecl CXWnd::DrawColoredRect(class CXRect,unsigned long,class CXRect),CXWnd__DrawColoredRect);
#endif
#ifdef CXWnd__GetTooltipRect
REVERSE_DETOUR(class CXRect __cdecl CXWnd::GetTooltipRect(class CXSize),CXWnd__GetTooltipRect);
#endif
#ifdef CXWnd__GetTooltipRect1
REVERSE_DETOUR(class CXRect __cdecl CXWnd::GetTooltipRect(class CXPoint,class CXSize),CXWnd__GetTooltipRect1);
#endif
#ifdef CXWnd__DrawTooltipAtPoint
REVERSE_DETOUR(void  CXWnd::DrawTooltipAtPoint(class CXPoint)const ,CXWnd__DrawTooltipAtPoint);
#endif
#ifdef CXWnd__Bottom
REVERSE_DETOUR(void  CXWnd::Bottom(void),CXWnd__Bottom);
#endif
#ifdef CXWnd__Center
REVERSE_DETOUR(void  CXWnd::Center(void),CXWnd__Center);
#endif
#ifdef CXWnd__Right
REVERSE_DETOUR(void  CXWnd::Right(void),CXWnd__Right);
#endif
#ifdef CXWnd__Left
REVERSE_DETOUR(void  CXWnd::Left(void),CXWnd__Left);
#endif
#ifdef CXWnd__SetLookLikeParent
REVERSE_DETOUR(void  CXWnd::SetLookLikeParent(void),CXWnd__SetLookLikeParent);
#endif
#ifdef CXWnd__GetClientClipRect
REVERSE_DETOUR(class CXRect  CXWnd::GetClientClipRect(void)const ,CXWnd__GetClientClipRect);
#endif
#ifdef CXWnd__GetScreenClipRect
REVERSE_DETOUR(class CXRect  CXWnd::GetScreenClipRect(void)const ,CXWnd__GetScreenClipRect);
#endif
#ifdef CXWnd__IsActive
REVERSE_DETOUR(bool  CXWnd::IsActive(void)const ,CXWnd__IsActive);
#endif
#ifdef CXWnd__IsDescendantOf
REVERSE_DETOUR(bool  CXWnd::IsDescendantOf(class CXWnd const *)const ,CXWnd__IsDescendantOf);
#endif
#ifdef CXWnd__GetBorderFrame
REVERSE_DETOUR(class CTAFrameDraw const *  CXWnd::GetBorderFrame(void)const ,CXWnd__GetBorderFrame);
#endif
#ifdef CXWnd__GetTitlebarHeader
REVERSE_DETOUR(class CTAFrameDraw const *  CXWnd::GetTitlebarHeader(void)const ,CXWnd__GetTitlebarHeader);
#endif
#ifdef CXWnd__GetCloseBoxTemplate
REVERSE_DETOUR(class CButtonDrawTemplate const *  CXWnd::GetCloseBoxTemplate(void)const ,CXWnd__GetCloseBoxTemplate);
#endif
#ifdef CXWnd__GetMinimizeBoxTemplate
REVERSE_DETOUR(class CButtonDrawTemplate const *  CXWnd::GetMinimizeBoxTemplate(void)const ,CXWnd__GetMinimizeBoxTemplate);
#endif
#ifdef CXWnd__GetTileBoxTemplate
REVERSE_DETOUR(class CButtonDrawTemplate const *  CXWnd::GetTileBoxTemplate(void)const ,CXWnd__GetTileBoxTemplate);
#endif
#ifdef CXWnd__GetRelativeRect
REVERSE_DETOUR(class CXRect  CXWnd::GetRelativeRect(void)const ,CXWnd__GetRelativeRect);
#endif
#ifdef CXWnd__GetScreenRect
REVERSE_DETOUR(class CXRect  CXWnd::GetScreenRect(void)const ,CXWnd__GetScreenRect);
#endif
#ifdef CXWnd__Resize
REVERSE_DETOUR(int  CXWnd::Resize(int,int),CXWnd__Resize);
#endif
#ifdef CXWnd__GetChildItem
REVERSE_DETOUR(class CXWnd *  CXWnd::GetChildItem(class CXStr)const ,CXWnd__GetChildItem);
#endif
#ifdef CXWnd__SetZLayer
REVERSE_DETOUR(void  CXWnd::SetZLayer(int),CXWnd__SetZLayer);
#endif
#ifdef CXWnd__SetFirstChildPointer
REVERSE_DETOUR(void  CXWnd::SetFirstChildPointer(class CXWnd *),CXWnd__SetFirstChildPointer);
#endif
#ifdef CXWnd__SetNextSibPointer
REVERSE_DETOUR(void  CXWnd::SetNextSibPointer(class CXWnd *),CXWnd__SetNextSibPointer);
#endif
#ifdef CXWnd__SetMouseOver
REVERSE_DETOUR(void  CXWnd::SetMouseOver(bool),CXWnd__SetMouseOver);
#endif
#ifdef CXWnd__SetKeyTooltip
REVERSE_DETOUR(void  CXWnd::SetKeyTooltip(int,int),CXWnd__SetKeyTooltip);
#endif
#ifdef CXWnd__GetXMLTooltip
REVERSE_DETOUR(class CXStr  CXWnd::GetXMLTooltip(void)const ,CXWnd__GetXMLTooltip);
#endif
#ifdef CMutexSyncCounted__CMutexSyncCounted
REVERSE_DETOUR( CMutexSyncCounted::CMutexSyncCounted(void),CMutexSyncCounted__CMutexSyncCounted);
#endif
#ifdef CMutexSyncCounted__dCMutexSyncCounted
REVERSE_DETOUR( CMutexSyncCounted::~CMutexSyncCounted(void),CMutexSyncCounted__dCMutexSyncCounted);
#endif
#ifdef CMutexLockCounted__dCMutexLockCounted
REVERSE_DETOUR( CMutexLockCounted::~CMutexLockCounted(void),CMutexLockCounted__dCMutexLockCounted);
#endif
#ifdef CXStr__AssureCopy
REVERSE_DETOUR(void  CXStr::AssureCopy(void),CXStr__AssureCopy);
#endif
#ifdef CXStr__Assure
//REVERSE_DETOUR(void  CXStr::Assure(long,enum EStringEncoding),CXStr__Assure);
#endif
#ifdef CXStr__AllocRepNoLock
//REVERSE_DETOUR(struct CStrRep *  CXStr::AllocRepNoLock(long,enum EStringEncoding),CXStr__AllocRepNoLock);
#endif
#ifdef CXStr__FreeRep
REVERSE_DETOUR(void  CXStr::FreeRep(struct CStrRep *),CXStr__FreeRep);
#endif
#ifdef CXStr__FreeRepNoLock
REVERSE_DETOUR(void  CXStr::FreeRepNoLock(struct CStrRep *),CXStr__FreeRepNoLock);
#endif
#ifdef CXStr__CXStr2
REVERSE_DETOUR( CXStr::CXStr(char),CXStr__CXStr2);
#endif
#ifdef CXStr__CXStr3
REVERSE_DETOUR( CXStr::CXStr(char const *),CXStr__CXStr3);
#endif
#ifdef CXStr__CXStr4
REVERSE_DETOUR( CXStr::CXStr(char const *,int),CXStr__CXStr4);
#endif
#ifdef CXStr__CXStr5
REVERSE_DETOUR( CXStr::CXStr(unsigned short const *),CXStr__CXStr5);
#endif
#ifdef CXStr__CXStr6
REVERSE_DETOUR( CXStr::CXStr(int,int,char),CXStr__CXStr6);
#endif
#ifdef CXStr__operator_equal
REVERSE_DETOUR(class CXStr &  CXStr::operator=(class CXStr const &),CXStr__operator_equal);
#endif
#ifdef CXStr__operator_equal1
REVERSE_DETOUR(class CXStr &  CXStr::operator=(char const *),CXStr__operator_equal1);
#endif
#ifdef CXStr__GetChar
REVERSE_DETOUR(char  CXStr::GetChar(long)const ,CXStr__GetChar);
#endif
#ifdef CXStr__SetChar
REVERSE_DETOUR(char  CXStr::SetChar(long,char),CXStr__SetChar);
#endif
#ifdef CXStr__GetUnicode
REVERSE_DETOUR(unsigned short  CXStr::GetUnicode(long)const ,CXStr__GetUnicode);
#endif
#ifdef CXStr__SetUnicode
REVERSE_DETOUR(unsigned short  CXStr::SetUnicode(long,unsigned short),CXStr__SetUnicode);
#endif
#ifdef CXStr__Compare
//REVERSE_DETOUR(int  CXStr::Compare(class CXStr const &,enum CompareCode)const ,CXStr__Compare);
#endif
#ifdef CXStr__CompareN
//REVERSE_DETOUR(int  CXStr::CompareN(class CXStr const &,int,enum CompareCode)const ,CXStr__CompareN);
#endif
#ifdef CXStr__operator_equal_equal
REVERSE_DETOUR(int  CXStr::operator==(class CXStr const &)const ,CXStr__operator_equal_equal);
#endif
#ifdef CXStr__operator_equal_equal1
REVERSE_DETOUR(int  CXStr::operator==(char const *)const ,CXStr__operator_equal_equal1);
#endif
#ifdef CXStr__operatort_
REVERSE_DETOUR(int  CXStr::operator>(class CXStr const &)const ,CXStr__operatort_);
#endif
#ifdef CXStr__BlankPreAllocate
REVERSE_DETOUR(void  CXStr::BlankPreAllocate(int),CXStr__BlankPreAllocate);
#endif
#ifdef CXStr__operator_plus_equal
REVERSE_DETOUR(void  CXStr::operator+=(class CXStr const &),CXStr__operator_plus_equal);
#endif
#ifdef CXStr__operator_plus_equal1
REVERSE_DETOUR(void  CXStr::operator+=(char const *),CXStr__operator_plus_equal1);
#endif
#ifdef CXStr__operator_plus_equal2
REVERSE_DETOUR(void  CXStr::operator+=(char),CXStr__operator_plus_equal2);
#endif
#ifdef CXStr__operator_plus_equal3
REVERSE_DETOUR(void  CXStr::operator+=(unsigned short),CXStr__operator_plus_equal3);
#endif
#ifdef CXStr__Delete
REVERSE_DETOUR(void  CXStr::Delete(long,long),CXStr__Delete);
#endif
#ifdef CXStr__Insert
REVERSE_DETOUR(void  CXStr::Insert(long,char),CXStr__Insert);
#endif
#ifdef CXStr__Insert1
REVERSE_DETOUR(void  CXStr::Insert(long,class CXStr const &),CXStr__Insert1);
#endif
#ifdef CXStr__Copy
REVERSE_DETOUR(class CXStr  CXStr::Copy(long,long)const ,CXStr__Copy);
#endif
#ifdef CXStr__CopySelf
REVERSE_DETOUR(void  CXStr::CopySelf(long,long),CXStr__CopySelf);
#endif
#ifdef CXStr__StripTrailing
REVERSE_DETOUR(void  CXStr::StripTrailing(char),CXStr__StripTrailing);
#endif
#ifdef CXStr__StripLeading
REVERSE_DETOUR(void  CXStr::StripLeading(char),CXStr__StripLeading);
#endif
#ifdef CXStr__StripAll
REVERSE_DETOUR(void  CXStr::StripAll(char),CXStr__StripAll);
#endif
#ifdef CXStr__Strip
REVERSE_DETOUR(void  CXStr::Strip(char),CXStr__Strip);
#endif
#ifdef CXStr__GetEncoding
//REVERSE_DETOUR(enum EStringEncoding  CXStr::GetEncoding(void)const ,CXStr__GetEncoding);
#endif
#ifdef CXStr__SetEncoding
//REVERSE_DETOUR(void  CXStr::SetEncoding(enum EStringEncoding),CXStr__SetEncoding);
#endif
#ifdef CXStr__operator_char_p
//REVERSE_DETOUR( CXStr::operator char *(void)const ,CXStr__operator_char_p);
#endif
#ifdef CXStr__operator_unsigned_short_p
//REVERSE_DETOUR( CXStr::operator unsigned short *(void)const ,CXStr__operator_unsigned_short_p);
#endif
#ifdef CXStr__SetUpperCase
REVERSE_DETOUR(void  CXStr::SetUpperCase(void),CXStr__SetUpperCase);
#endif
#ifdef CXStr__SetLowerCase
REVERSE_DETOUR(void  CXStr::SetLowerCase(void),CXStr__SetLowerCase);
#endif
#ifdef CXStr__ConvertToInt
REVERSE_DETOUR(int  CXStr::ConvertToInt(void),CXStr__ConvertToInt);
#endif
#ifdef CXStr__PrintString
REVERSE_DETOUR(int __cdecl CXStr::PrintString(char const *,...),CXStr__PrintString);
#endif
#ifdef CXStr__FindLast
REVERSE_DETOUR(bool  CXStr::FindLast(char,int &),CXStr__FindLast);
#endif
#ifdef CXStr__Find
REVERSE_DETOUR(bool  CXStr::Find(char,int &),CXStr__Find);
#endif
#ifdef CXStr__Find1
REVERSE_DETOUR(bool  CXStr::Find(unsigned short,int &),CXStr__Find1);
#endif
#ifdef CXStr__Find2
REVERSE_DETOUR(bool  CXStr::Find(class CXStr const &,int &),CXStr__Find2);
#endif
#ifdef CXStr__AddCr
REVERSE_DETOUR(void  CXStr::AddCr(void),CXStr__AddCr);
#endif
#ifdef CXStr__Utf8ToUnicode
REVERSE_DETOUR(int __cdecl CXStr::Utf8ToUnicode(char const *,unsigned short *,int),CXStr__Utf8ToUnicode);
#endif
#ifdef CXStr__LenUnicodeToUtf8
REVERSE_DETOUR(int __cdecl CXStr::LenUnicodeToUtf8(unsigned short const *),CXStr__LenUnicodeToUtf8);
#endif
#ifdef CXStr__UnicodeToUtf8
REVERSE_DETOUR(int __cdecl CXStr::UnicodeToUtf8(unsigned short const *,char *,int),CXStr__UnicodeToUtf8);
#endif
#ifdef CListWnd__CListWnd
REVERSE_DETOUR( CListWnd::CListWnd(class CXWnd *,unsigned __int32,class CXRect),CListWnd__CListWnd);
#endif
#ifdef CListWnd__GetCurSel
REVERSE_DETOUR(int  CListWnd::GetCurSel(void)const,CListWnd__GetCurSel);
#endif
#ifdef CListWnd__GetCurCol
REVERSE_DETOUR(int  CListWnd::GetCurCol(void)const ,CListWnd__GetCurCol);
#endif
#ifdef CListWnd__GetItemData
REVERSE_DETOUR(unsigned __int32  CListWnd::GetItemData(int)const ,CListWnd__GetItemData);
#endif
#ifdef CListWnd__GetItemText
REVERSE_DETOUR(class CXStr  CListWnd::GetItemText(int,int)const ,CListWnd__GetItemText);
#endif
#ifdef CListWnd__GetItemIcon
REVERSE_DETOUR(class CTextureAnimation const *  CListWnd::GetItemIcon(int,int)const ,CListWnd__GetItemIcon);
#endif
#ifdef CListWnd__GetItemColor
REVERSE_DETOUR(unsigned long  CListWnd::GetItemColor(int,int)const ,CListWnd__GetItemColor);
#endif
#ifdef CListWnd__GetColumnFlags
REVERSE_DETOUR(unsigned __int32  CListWnd::GetColumnFlags(int)const ,CListWnd__GetColumnFlags);
#endif
#ifdef CListWnd__GetColumnWidth
REVERSE_DETOUR(int  CListWnd::GetColumnWidth(int)const ,CListWnd__GetColumnWidth);
#endif
#ifdef CListWnd__SetColumnWidth
REVERSE_DETOUR(void  CListWnd::SetColumnWidth(int,int),CListWnd__SetColumnWidth);
#endif
#ifdef CListWnd__ShiftColumnSeparator
REVERSE_DETOUR(void  CListWnd::ShiftColumnSeparator(int,int),CListWnd__ShiftColumnSeparator);
#endif
#ifdef CListWnd__GetColumnMinWidth
REVERSE_DETOUR(int  CListWnd::GetColumnMinWidth(int)const ,CListWnd__GetColumnMinWidth);
#endif
#ifdef CListWnd__GetColumnJustification
REVERSE_DETOUR(int  CListWnd::GetColumnJustification(int)const ,CListWnd__GetColumnJustification);
#endif
#ifdef CListWnd__SetColumnJustification
REVERSE_DETOUR(void  CListWnd::SetColumnJustification(int,int),CListWnd__SetColumnJustification);
#endif
#ifdef CListWnd__GetColumnLabel
REVERSE_DETOUR(class CXStr  CListWnd::GetColumnLabel(int)const ,CListWnd__GetColumnLabel);
#endif
#ifdef CListWnd__GetColumnAnimation
REVERSE_DETOUR(class CTextureAnimation const *  CListWnd::GetColumnAnimation(int)const ,CListWnd__GetColumnAnimation);
#endif
#ifdef CListWnd__GetColumnAnimationSelected
REVERSE_DETOUR(class CTextureAnimation const *  CListWnd::GetColumnAnimationSelected(int)const ,CListWnd__GetColumnAnimationSelected);
#endif
#ifdef CListWnd__GetColumnAnimationMouseOver
REVERSE_DETOUR(class CTextureAnimation const *  CListWnd::GetColumnAnimationMouseOver(int)const ,CListWnd__GetColumnAnimationMouseOver);
#endif
#ifdef CListWnd__AddLine
REVERSE_DETOUR(int  CListWnd::AddLine(class SListWndLine const *),CListWnd__AddLine);
#endif
#ifdef CListWnd__AddString
REVERSE_DETOUR(int  CListWnd::AddString(class CXStr,unsigned long,unsigned __int32,class CTextureAnimation const *),CListWnd__AddString);
#endif
#ifdef CListWnd__RemoveString
REVERSE_DETOUR(void  CListWnd::RemoveString(int),CListWnd__RemoveString);
#endif
#ifdef CListWnd__RemoveLine
REVERSE_DETOUR(void  CListWnd::RemoveLine(int),CListWnd__RemoveLine);
#endif
#ifdef CListWnd__SetCurSel
REVERSE_DETOUR(void  CListWnd::SetCurSel(int),CListWnd__SetCurSel);
#endif
#ifdef CListWnd__ToggleSel
REVERSE_DETOUR(void  CListWnd::ToggleSel(int),CListWnd__ToggleSel);
#endif
#ifdef CListWnd__ExtendSel
REVERSE_DETOUR(void  CListWnd::ExtendSel(int),CListWnd__ExtendSel);
#endif
#ifdef CListWnd__ClearAllSel
REVERSE_DETOUR(void  CListWnd::ClearAllSel(void),CListWnd__ClearAllSel);
#endif
#ifdef CListWnd__ClearSel
REVERSE_DETOUR(void  CListWnd::ClearSel(int),CListWnd__ClearSel);
#endif
#ifdef CListWnd__SetItemData
REVERSE_DETOUR(void  CListWnd::SetItemData(int,unsigned __int32),CListWnd__SetItemData);
#endif
#ifdef CListWnd__SetItemText
REVERSE_DETOUR(void  CListWnd::SetItemText(int,int,class CXStr),CListWnd__SetItemText);
#endif
#ifdef CListWnd__SetItemColor
REVERSE_DETOUR(void  CListWnd::SetItemColor(int,int,unsigned long),CListWnd__SetItemColor);
#endif
#ifdef CListWnd__IsLineEnabled
REVERSE_DETOUR(bool  CListWnd::IsLineEnabled(int)const ,CListWnd__IsLineEnabled);
#endif
#ifdef CListWnd__EnableLine
REVERSE_DETOUR(void  CListWnd::EnableLine(int,bool),CListWnd__EnableLine);
#endif
#ifdef CListWnd__AddColumn
REVERSE_DETOUR(int  CListWnd::AddColumn(class CXStr,int,unsigned __int32,unsigned __int32),CListWnd__AddColumn);
#endif
#ifdef CListWnd__AddColumn1
REVERSE_DETOUR(int  CListWnd::AddColumn(class CXStr,class CTextureAnimation *,int,unsigned __int32,unsigned __int32,class CTextureAnimation *,class CTextureAnimation *),CListWnd__AddColumn1);
#endif
#ifdef SListWndColumn__SListWndColumn
REVERSE_DETOUR( SListWndColumn::SListWndColumn(class CXStr,int,class CTextureAnimation *,unsigned __int32,unsigned __int32,class CTextureAnimation *,class CTextureAnimation *),SListWndColumn__SListWndColumn);
#endif
#ifdef SLinkInfo__dSLinkInfo
//REVERSE_DETOUR( SLinkInfo::~SLinkInfo(void),SLinkInfo__dSLinkInfo);
#endif
#ifdef SListWndCellEditUpdate__dSListWndCellEditUpdate
REVERSE_DETOUR( SListWndCellEditUpdate::~SListWndCellEditUpdate(void),SListWndCellEditUpdate__dSListWndCellEditUpdate);
#endif
#ifdef SListWndColumn__dSListWndColumn
REVERSE_DETOUR( SListWndColumn::~SListWndColumn(void),SListWndColumn__dSListWndColumn);
#endif
#ifdef CListWnd__SetColumnLabel
REVERSE_DETOUR(void  CListWnd::SetColumnLabel(int,class CXStr),CListWnd__SetColumnLabel);
#endif
#ifdef CXRect__CXRect1
REVERSE_DETOUR( CXRect::CXRect(void),CXRect__CXRect1);
#endif
#ifdef CListWnd__GetItemHeight
REVERSE_DETOUR(int  CListWnd::GetItemHeight(int)const ,CListWnd__GetItemHeight);
#endif
#ifdef CListWnd__CalculateLineHeights
REVERSE_DETOUR(void  CListWnd::CalculateLineHeights(void),CListWnd__CalculateLineHeights);
#endif
#ifdef CListWnd__CalculateVSBRange
REVERSE_DETOUR(void  CListWnd::CalculateVSBRange(void),CListWnd__CalculateVSBRange);
#endif
#ifdef CListWnd__CalculateFirstVisibleLine
REVERSE_DETOUR(void  CListWnd::CalculateFirstVisibleLine(void),CListWnd__CalculateFirstVisibleLine);
#endif
#ifdef CListWnd__EnsureVisible
REVERSE_DETOUR(void  CListWnd::EnsureVisible(int),CListWnd__EnsureVisible);
#endif
#ifdef CListWnd__GetItemRect
REVERSE_DETOUR(class CXRect  CListWnd::GetItemRect(int,int)const ,CListWnd__GetItemRect);
#endif
#ifdef CListWnd__GetItemAtPoint
REVERSE_DETOUR(int  CListWnd::GetItemAtPoint(class CXPoint)const ,CListWnd__GetItemAtPoint);
#endif
#ifdef CListWnd__GetItemAtPoint1
REVERSE_DETOUR(void  CListWnd::GetItemAtPoint(class CXPoint,int *,int *)const ,CListWnd__GetItemAtPoint1);
#endif
#ifdef CListWnd__CloseAndUpdateEditWindow
REVERSE_DETOUR(void  CListWnd::CloseAndUpdateEditWindow(void),CListWnd__CloseAndUpdateEditWindow);
#endif
#ifdef CListWnd__SetColors
REVERSE_DETOUR(void  CListWnd::SetColors(unsigned long,unsigned long,unsigned long),CListWnd__SetColors);
#endif
#ifdef CListWnd__GetSeparatorRect
REVERSE_DETOUR(class CXRect  CListWnd::GetSeparatorRect(int)const ,CListWnd__GetSeparatorRect);
#endif
#ifdef SListWndSortInfo__dSListWndSortInfo
REVERSE_DETOUR( SListWndSortInfo::~SListWndSortInfo(void),SListWndSortInfo__dSListWndSortInfo);
#endif
#ifdef CListWnd__GetHeaderRect
REVERSE_DETOUR(class CXRect  CListWnd::GetHeaderRect(int)const ,CListWnd__GetHeaderRect);
#endif
#ifdef SListWndLine__SListWndLine
REVERSE_DETOUR( SListWndLine::SListWndLine(void),SListWndLine__SListWndLine);
#endif
#ifdef SListWndCell__operator_equal
REVERSE_DETOUR(struct SListWndCell &  SListWndCell::operator=(struct SListWndCell const &),SListWndCell__operator_equal);
#endif
#ifdef SListWndLine__operator_equal
REVERSE_DETOUR(class SListWndLine &  SListWndLine::operator=(class SListWndLine const &),SListWndLine__operator_equal);
#endif
#ifdef CScreenPieceTemplate__CScreenPieceTemplate
REVERSE_DETOUR( CScreenPieceTemplate::CScreenPieceTemplate(class CParamScreenPiece *),CScreenPieceTemplate__CScreenPieceTemplate);
#endif
#ifdef CScreenPieceTemplate__IsType
REVERSE_DETOUR(bool  CScreenPieceTemplate::IsType(unsigned __int32)const ,CScreenPieceTemplate__IsType);
#endif
#ifdef CStaticScreenPieceTemplate__CStaticScreenPieceTemplate
REVERSE_DETOUR( CStaticScreenPieceTemplate::CStaticScreenPieceTemplate(class CParamStaticScreenPiece *),CStaticScreenPieceTemplate__CStaticScreenPieceTemplate);
#endif
#ifdef CStaticAnimationTemplate__CStaticAnimationTemplate
REVERSE_DETOUR( CStaticAnimationTemplate::CStaticAnimationTemplate(class CParamStaticAnimation *),CStaticAnimationTemplate__CStaticAnimationTemplate);
#endif
#ifdef CStaticTextTemplate__CStaticTextTemplate
REVERSE_DETOUR( CStaticTextTemplate::CStaticTextTemplate(class CParamStaticText *),CStaticTextTemplate__CStaticTextTemplate);
#endif
#ifdef CStaticTextTemplate__SetText
REVERSE_DETOUR(class CXStr  CStaticTextTemplate::SetText(class CXStr),CStaticTextTemplate__SetText);
#endif
#ifdef CStaticFrameTemplate__CStaticFrameTemplate
REVERSE_DETOUR( CStaticFrameTemplate::CStaticFrameTemplate(class CParamStaticFrame *),CStaticFrameTemplate__CStaticFrameTemplate);
#endif
#ifdef CStaticHeaderTemplate__CStaticHeaderTemplate
REVERSE_DETOUR( CStaticHeaderTemplate::CStaticHeaderTemplate(class CParamStaticHeader *),CStaticHeaderTemplate__CStaticHeaderTemplate);
#endif
#ifdef CControlTemplate__CControlTemplate
REVERSE_DETOUR( CControlTemplate::CControlTemplate(class CParamControl *),CControlTemplate__CControlTemplate);
#endif
#ifdef CListboxColumnTemplate__CListboxColumnTemplate
REVERSE_DETOUR( CListboxColumnTemplate::CListboxColumnTemplate(class CParamListboxColumn *),CListboxColumnTemplate__CListboxColumnTemplate);
#endif
#ifdef CListboxTemplate__CListboxTemplate
REVERSE_DETOUR( CListboxTemplate::CListboxTemplate(class CParamListbox *),CListboxTemplate__CListboxTemplate);
#endif
#ifdef CListboxColumnTemplate__dCListboxColumnTemplate
REVERSE_DETOUR( CListboxColumnTemplate::~CListboxColumnTemplate(void),CListboxColumnTemplate__dCListboxColumnTemplate);
#endif
#ifdef CButtonTemplate__CButtonTemplate
REVERSE_DETOUR( CButtonTemplate::CButtonTemplate(class CParamButton *),CButtonTemplate__CButtonTemplate);
#endif
#ifdef CGaugeTemplate__CGaugeTemplate
REVERSE_DETOUR( CGaugeTemplate::CGaugeTemplate(class CParamGauge *),CGaugeTemplate__CGaugeTemplate);
#endif
#ifdef CSpellGemTemplate__CSpellGemTemplate
REVERSE_DETOUR( CSpellGemTemplate::CSpellGemTemplate(class CParamSpellGem *),CSpellGemTemplate__CSpellGemTemplate);
#endif
#ifdef CInvSlotTemplate__CInvSlotTemplate
REVERSE_DETOUR( CInvSlotTemplate::CInvSlotTemplate(class CParamInvSlot *),CInvSlotTemplate__CInvSlotTemplate);
#endif
#ifdef CEditboxTemplate__CEditboxTemplate
REVERSE_DETOUR( CEditboxTemplate::CEditboxTemplate(class CParamEditbox *),CEditboxTemplate__CEditboxTemplate);
#endif
#ifdef CSliderTemplate__CSliderTemplate
REVERSE_DETOUR( CSliderTemplate::CSliderTemplate(class CParamSlider *),CSliderTemplate__CSliderTemplate);
#endif
#ifdef CLabelTemplate__CLabelTemplate
REVERSE_DETOUR( CLabelTemplate::CLabelTemplate(class CParamLabel *),CLabelTemplate__CLabelTemplate);
#endif
#ifdef CSTMLboxTemplate__CSTMLboxTemplate
REVERSE_DETOUR( CSTMLboxTemplate::CSTMLboxTemplate(class CParamSTMLbox *),CSTMLboxTemplate__CSTMLboxTemplate);
#endif
#ifdef CComboboxTemplate__CComboboxTemplate
REVERSE_DETOUR( CComboboxTemplate::CComboboxTemplate(class CParamCombobox *),CComboboxTemplate__CComboboxTemplate);
#endif
#ifdef CPageTemplate__CPageTemplate
REVERSE_DETOUR( CPageTemplate::CPageTemplate(class CParamPage *),CPageTemplate__CPageTemplate);
#endif
#ifdef CTabBoxTemplate__CTabBoxTemplate
REVERSE_DETOUR( CTabBoxTemplate::CTabBoxTemplate(class CParamTabBox *),CTabBoxTemplate__CTabBoxTemplate);
#endif
#ifdef CScreenTemplate__CScreenTemplate
REVERSE_DETOUR( CScreenTemplate::CScreenTemplate(class CParamScreen *),CScreenTemplate__CScreenTemplate);
#endif
#ifdef CStmlWnd__CStmlWnd
REVERSE_DETOUR( CStmlWnd::CStmlWnd(class CXWnd *,unsigned __int32,class CXRect),CStmlWnd__CStmlWnd);
#endif
#ifdef CStmlWnd__InitializeTextLine
REVERSE_DETOUR(void  CStmlWnd::InitializeTextLine(class SParseVariables *,int),CStmlWnd__InitializeTextLine);
#endif
#ifdef CStmlWnd__AddTextPieceToLine
REVERSE_DETOUR(void  CStmlWnd::AddTextPieceToLine(class SParseVariables *),CStmlWnd__AddTextPieceToLine);
#endif
#ifdef CStmlWnd__MakeStmlColorTag
REVERSE_DETOUR(class CXStr __cdecl CStmlWnd::MakeStmlColorTag(unsigned long),CStmlWnd__MakeStmlColorTag);
#endif
#ifdef CTextureAnimation__GetName
REVERSE_DETOUR(class CXStr  CTextureAnimation::GetName(void)const ,CTextureAnimation__GetName);
#endif
#ifdef CStmlWnd__MakeWndNotificationTag
REVERSE_DETOUR(class CXStr __cdecl CStmlWnd::MakeWndNotificationTag(unsigned __int32,class CXStr&,class CXStr&),CStmlWnd__MakeWndNotificationTag);
#endif
#ifdef CStmlWnd__ParseTagColor
REVERSE_DETOUR(void  CStmlWnd::ParseTagColor(class CXStr,unsigned long *)const ,CStmlWnd__ParseTagColor);
#endif
#ifdef CStmlWnd__ParseTagFace
REVERSE_DETOUR(void  CStmlWnd::ParseTagFace(class CXStr,class CTextureFont const * *)const ,CStmlWnd__ParseTagFace);
#endif
#ifdef CStmlWnd__ParseTagAlign
//REVERSE_DETOUR(void  CStmlWnd::ParseTagAlign(class CXStr,enum ESTMLAlign *)const ,CStmlWnd__ParseTagAlign);
#endif
#ifdef SAmpersandEntry__SAmpersandEntry
REVERSE_DETOUR( SAmpersandEntry::SAmpersandEntry(class CXStr,char),SAmpersandEntry__SAmpersandEntry);
#endif
#ifdef CButtonDrawTemplate__dCButtonDrawTemplate
REVERSE_DETOUR( CButtonDrawTemplate::~CButtonDrawTemplate(void),CButtonDrawTemplate__dCButtonDrawTemplate);
#endif
#ifdef CGaugeDrawTemplate__dCGaugeDrawTemplate
REVERSE_DETOUR( CGaugeDrawTemplate::~CGaugeDrawTemplate(void),CGaugeDrawTemplate__dCGaugeDrawTemplate);
#endif
#ifdef CSpellGemDrawTemplate__dCSpellGemDrawTemplate
REVERSE_DETOUR( CSpellGemDrawTemplate::~CSpellGemDrawTemplate(void),CSpellGemDrawTemplate__dCSpellGemDrawTemplate);
#endif
#ifdef CTAFrameDraw__dCTAFrameDraw
REVERSE_DETOUR( CTAFrameDraw::~CTAFrameDraw(void),CTAFrameDraw__dCTAFrameDraw);
#endif
#ifdef SAmpersandEntry__dSAmpersandEntry
REVERSE_DETOUR( SAmpersandEntry::~SAmpersandEntry(void),SAmpersandEntry__dSAmpersandEntry);
#endif
#ifdef STempTableCell__dSTempTableCell
REVERSE_DETOUR( STempTableCell::~STempTableCell(void),STempTableCell__dSTempTableCell);
#endif
#ifdef CXStr__Blank
REVERSE_DETOUR(void  CXStr::Blank(void),CXStr__Blank);
#endif
#ifdef CStmlWnd__ParseAmpersand
REVERSE_DETOUR(bool  CStmlWnd::ParseAmpersand(class CXStr&,char *)const ,CStmlWnd__ParseAmpersand);
#endif
#ifdef CStmlWnd__ParseLinkTarget
//REVERSE_DETOUR(void  CStmlWnd::ParseLinkTarget(class CXStr,enum ESTMLTargetValue *)const ,CStmlWnd__ParseLinkTarget);
#endif
#ifdef CStmlWnd__FastForwardPastSpaces
REVERSE_DETOUR(unsigned short  CStmlWnd::FastForwardPastSpaces(class CXStr&,int *),CStmlWnd__FastForwardPastSpaces);
#endif
#ifdef CStmlWnd__FastForwardPastSpacesAndQuotes
REVERSE_DETOUR(unsigned short  CStmlWnd::FastForwardPastSpacesAndQuotes(class CXStr&,int *),CStmlWnd__FastForwardPastSpacesAndQuotes);
#endif
#ifdef CStmlWnd__GetNextTagPiece
REVERSE_DETOUR(unsigned short  CStmlWnd::GetNextTagPiece(class CXStr&,class CXStr *,int *,bool (__cdecl*)(unsigned short),bool),CStmlWnd__GetNextTagPiece);
#endif
#ifdef CStmlWnd__IsCharacterNotQuotes
REVERSE_DETOUR(bool __cdecl CStmlWnd::IsCharacterNotQuotes(unsigned short),CStmlWnd__IsCharacterNotQuotes);
#endif
#ifdef CStmlWnd__FastForwardPastQuotesAndGetNextTagPiece
REVERSE_DETOUR(unsigned short  CStmlWnd::FastForwardPastQuotesAndGetNextTagPiece(class CXStr&,class CXStr *,int *,bool),CStmlWnd__FastForwardPastQuotesAndGetNextTagPiece);
#endif
#ifdef CStmlWnd__FastForwardToEndOfTag
REVERSE_DETOUR(unsigned short  CStmlWnd::FastForwardToEndOfTag(class CXStr&,class CXStr *,int *,char),CStmlWnd__FastForwardToEndOfTag);
#endif
#ifdef CStmlWnd__InitializeTempVariables
REVERSE_DETOUR(void  CStmlWnd::InitializeTempVariables(class SParseVariables *,class CXRect),CStmlWnd__InitializeTempVariables);
#endif
#ifdef CStmlWnd__InitializeWindowVariables
REVERSE_DETOUR(void  CStmlWnd::InitializeWindowVariables(void),CStmlWnd__InitializeWindowVariables);
#endif
#ifdef CStmlWnd__ResetTempVariablesForNewLine
REVERSE_DETOUR(void  CStmlWnd::ResetTempVariablesForNewLine(class SParseVariables *),CStmlWnd__ResetTempVariablesForNewLine);
#endif
#ifdef CStmlWnd__GetNextChar
REVERSE_DETOUR(unsigned short  CStmlWnd::GetNextChar(int *,class CXStr&),CStmlWnd__GetNextChar);
#endif
#ifdef CStmlWnd__GetThisChar
REVERSE_DETOUR(unsigned short  CStmlWnd::GetThisChar(int,class CXStr&),CStmlWnd__GetThisChar);
#endif
#ifdef CStmlWnd__IsCharacterNotEquals
REVERSE_DETOUR(bool __cdecl CStmlWnd::IsCharacterNotEquals(unsigned short),CStmlWnd__IsCharacterNotEquals);
#endif
#ifdef CStmlWnd__IsCharacterNotASpaceAndNotNULL
REVERSE_DETOUR(bool __cdecl CStmlWnd::IsCharacterNotASpaceAndNotNULL(unsigned short),CStmlWnd__IsCharacterNotASpaceAndNotNULL);
#endif
#ifdef SParseVariables__dSParseVariables
REVERSE_DETOUR( SParseVariables::~SParseVariables(void),SParseVariables__dSParseVariables);
#endif
#ifdef SFormattedText__dSFormattedText
REVERSE_DETOUR( SFormattedText::~SFormattedText(void),SFormattedText__dSFormattedText);
#endif
#ifdef CStmlWnd__ParseSTMLHead
REVERSE_DETOUR(void  CStmlWnd::ParseSTMLHead(class CXStr&),CStmlWnd__ParseSTMLHead);
#endif
#ifdef CStmlWnd__ParseSTMLTable
REVERSE_DETOUR(void  CStmlWnd::ParseSTMLTable(class CXStr&,int *,class CXStr&,class SParseVariables *),CStmlWnd__ParseSTMLTable);
#endif
#ifdef STempTable__dSTempTable
REVERSE_DETOUR( STempTable::~STempTable(void),STempTable__dSTempTable);
#endif
#ifdef STable__STable
REVERSE_DETOUR( STable::STable(void),STable__STable);
#endif
#ifdef STable__dSTable
REVERSE_DETOUR( STable::~STable(void),STable__dSTable);
#endif
#ifdef STableCell__dSTableCell
REVERSE_DETOUR( STableCell::~STableCell(void),STableCell__dSTableCell);
#endif
#ifdef CStmlWnd__ParseSTMLTableAttributes
REVERSE_DETOUR(void  CStmlWnd::ParseSTMLTableAttributes(class CXStr,class STable *),CStmlWnd__ParseSTMLTableAttributes);
#endif
#ifdef CStmlWnd__GetVisiableText
REVERSE_DETOUR(class CXStr  CStmlWnd::GetVisiableText(class CXStr&,class CXRect)const ,CStmlWnd__GetVisiableText);
#endif
#ifdef CStmlWnd__ForceParseNow
REVERSE_DETOUR(void  CStmlWnd::ForceParseNow(void),CStmlWnd__ForceParseNow);
#endif
#ifdef CStmlWnd__CalculateVSBRange
REVERSE_DETOUR(void  CStmlWnd::CalculateVSBRange(int),CStmlWnd__CalculateVSBRange);
#endif
#ifdef CStmlWnd__CalculateHSBRange
REVERSE_DETOUR(void  CStmlWnd::CalculateHSBRange(int),CStmlWnd__CalculateHSBRange);
#endif
#ifdef CStmlReport__GetReport
REVERSE_DETOUR(class CXStr  CStmlReport::GetReport(void)const ,CStmlReport__GetReport);
#endif
#ifdef CStmlWnd__CompleteParse
REVERSE_DETOUR(void  CStmlWnd::CompleteParse(void),CStmlWnd__CompleteParse);
#endif
#ifdef CStmlWnd__StripFirstSTMLLines
REVERSE_DETOUR(void  CStmlWnd::StripFirstSTMLLines(int),CStmlWnd__StripFirstSTMLLines);
#endif
#ifdef CStmlWnd__ActivateLink
//REVERSE_DETOUR(void  CStmlWnd::ActivateLink(class SLinkInfo),CStmlWnd__ActivateLink);
#endif
#ifdef SLinkInfo__SLinkInfo
//REVERSE_DETOUR( SLinkInfo::SLinkInfo(class SLinkInfo const &),SLinkInfo__SLinkInfo);
#endif
#ifdef CStmlWnd__CanBreakAtCharacter
REVERSE_DETOUR(bool __cdecl CStmlWnd::CanBreakAtCharacter(unsigned short),CStmlWnd__CanBreakAtCharacter);
#endif
#ifdef CStmlWnd__ActivateLinkFile
//REVERSE_DETOUR(void  CStmlWnd::ActivateLinkFile(class SLinkInfo),CStmlWnd__ActivateLinkFile);
#endif
#ifdef CStmlWnd__ActivateLinkMessageId
//REVERSE_DETOUR(void  CStmlWnd::ActivateLinkMessageId(class SLinkInfo),CStmlWnd__ActivateLinkMessageId);
#endif
#ifdef CStmlWnd__ActivateLinkReport
//REVERSE_DETOUR(void  CStmlWnd::ActivateLinkReport(class SLinkInfo,bool),CStmlWnd__ActivateLinkReport);
#endif
#ifdef CStmlWnd__ActivateLinkWndNotify
//REVERSE_DETOUR(void  CStmlWnd::ActivateLinkWndNotify(class SLinkInfo),CStmlWnd__ActivateLinkWndNotify);
#endif
#ifdef CStmlWnd__LoadPage
//REVERSE_DETOUR(void  CStmlWnd::LoadPage(class CXStr,enum ESTMLTargetValue,bool),CStmlWnd__LoadPage);
#endif
#ifdef CStmlWnd__AddLinkToHistory
//REVERSE_DETOUR(void  CStmlWnd::AddLinkToHistory(class SLinkInfo,class CXStr),CStmlWnd__AddLinkToHistory);
#endif
#ifdef SLinkInfo__operator_equal
//REVERSE_DETOUR(class SLinkInfo &  SLinkInfo::operator=(class SLinkInfo const &),SLinkInfo__operator_equal);
#endif
#ifdef CStmlWnd__UpdateHistoryString
REVERSE_DETOUR(void  CStmlWnd::UpdateHistoryString(__int32,class CXStr&),CStmlWnd__UpdateHistoryString);
#endif
#ifdef CStmlWnd__SetSTMLText
//REVERSE_DETOUR(void  CStmlWnd::SetSTMLText(class CXStr,bool,class SLinkInfo *),CStmlWnd__SetSTMLText);
#endif
#ifdef SLinkInfo__SLinkInfo1
//REVERSE_DETOUR( SLinkInfo::SLinkInfo(void),SLinkInfo__SLinkInfo1);
#endif
#ifdef CStmlWnd__SetSTMLTextWithoutHistory
REVERSE_DETOUR(void  CStmlWnd::SetSTMLTextWithoutHistory(class CXStr),CStmlWnd__SetSTMLTextWithoutHistory);
#endif
#ifdef CStmlWnd__GoToBackHistoryLink
REVERSE_DETOUR(void  CStmlWnd::GoToBackHistoryLink(void),CStmlWnd__GoToBackHistoryLink);
#endif
#ifdef CStmlWnd__CanGoBackward
REVERSE_DETOUR(bool  CStmlWnd::CanGoBackward(void),CStmlWnd__CanGoBackward);
#endif
#ifdef CStmlWnd__IsLinkActive
//REVERSE_DETOUR(bool  CStmlWnd::IsLinkActive(class SLinkInfo)const,CStmlWnd__IsLinkActive);
#endif
#ifdef CXStr__GetLength
REVERSE_DETOUR(long  CXStr::GetLength(void)const ,CXStr__GetLength);
#endif
#ifdef STextLine__STextLine
REVERSE_DETOUR( STextLine::STextLine(void),STextLine__STextLine);
#endif
#ifdef STextLine__dSTextLine
REVERSE_DETOUR( STextLine::~STextLine(void),STextLine__dSTextLine);
#endif
#ifdef STempTableCell__STempTableCell
REVERSE_DETOUR( STempTableCell::STempTableCell(void),STempTableCell__STempTableCell);
#endif
#ifdef STempTableRow__STempTableRow
REVERSE_DETOUR( STempTableRow::STempTableRow(void),STempTableRow__STempTableRow);
#endif
#ifdef STempTableRow__dSTempTableRow
REVERSE_DETOUR( STempTableRow::~STempTableRow(void),STempTableRow__dSTempTableRow);
#endif
#ifdef STextLine__operator_equal
REVERSE_DETOUR(class STextLine &  STextLine::operator=(class STextLine const &),STextLine__operator_equal);
#endif
#ifdef SHistoryElement__SHistoryElement
REVERSE_DETOUR( SHistoryElement::SHistoryElement(void),SHistoryElement__SHistoryElement);
#endif
#ifdef SHistoryElement__dSHistoryElement
REVERSE_DETOUR( SHistoryElement::~SHistoryElement(void),SHistoryElement__dSHistoryElement);
#endif
#ifdef SFormattedText__SFormattedText
REVERSE_DETOUR( SFormattedText::SFormattedText(void),SFormattedText__SFormattedText);
#endif
#ifdef STable__operator_equal
REVERSE_DETOUR(class STable &  STable::operator=(class STable const &),STable__operator_equal);
#endif
#ifdef STableCell__STableCell
REVERSE_DETOUR( STableCell::STableCell(void),STableCell__STableCell);
#endif
#ifdef CTabWnd__CTabWnd
REVERSE_DETOUR( CTabWnd::CTabWnd(class CXWnd *,unsigned __int32,class CXRect,class CTabBoxTemplate *),CTabWnd__CTabWnd);
#endif
#ifdef CTabWnd__GetNumTabs
REVERSE_DETOUR(int  CTabWnd::GetNumTabs(void)const ,CTabWnd__GetNumTabs);
#endif
#ifdef CTabWnd__GetCurrentTabIndex
REVERSE_DETOUR(int  CTabWnd::GetCurrentTabIndex(void)const ,CTabWnd__GetCurrentTabIndex);
#endif
#ifdef CTabWnd__GetCurrentPage
REVERSE_DETOUR(class CPageWnd *  CTabWnd::GetCurrentPage(void)const ,CTabWnd__GetCurrentPage);
#endif
#ifdef CTabWnd__GetTabRect
REVERSE_DETOUR(class CXRect  CTabWnd::GetTabRect(int)const ,CTabWnd__GetTabRect);
#endif
#ifdef CTabWnd__GetTabInnerRect
REVERSE_DETOUR(class CXRect  CTabWnd::GetTabInnerRect(int)const ,CTabWnd__GetTabInnerRect);
#endif
#ifdef CTabWnd__GetPageClientRect
REVERSE_DETOUR(class CXRect  CTabWnd::GetPageClientRect(void)const ,CTabWnd__GetPageClientRect);
#endif
#ifdef CTabWnd__GetPageInnerRect
REVERSE_DETOUR(class CXRect  CTabWnd::GetPageInnerRect(void)const ,CTabWnd__GetPageInnerRect);
#endif
#ifdef CTabWnd__SetPage
REVERSE_DETOUR(void  CTabWnd::SetPage(int,bool),CTabWnd__SetPage);
#endif
#ifdef CTabWnd__SetPage1
REVERSE_DETOUR(void  CTabWnd::SetPage(class CPageWnd *,bool),CTabWnd__SetPage1);
#endif
#ifdef CTabWnd__InsertPage
REVERSE_DETOUR(void  CTabWnd::InsertPage(class CPageWnd *,int),CTabWnd__InsertPage);
#endif
#ifdef CTabWnd__SetPageRect
REVERSE_DETOUR(void  CTabWnd::SetPageRect(class CXRect),CTabWnd__SetPageRect);
#endif
#ifdef CXWnd__Tile
REVERSE_DETOUR(int  CXWnd::Tile(bool),CXWnd__Tile);
#endif
#ifdef CTabWnd__UpdatePage
REVERSE_DETOUR(void  CTabWnd::UpdatePage(void),CTabWnd__UpdatePage);
#endif
#ifdef CTabWnd__IndexInBounds
REVERSE_DETOUR(bool  CTabWnd::IndexInBounds(int)const ,CTabWnd__IndexInBounds);
#endif
#ifdef CTabWnd__GetPageFromTabIndex
REVERSE_DETOUR(class CPageWnd *  CTabWnd::GetPageFromTabIndex(int)const ,CTabWnd__GetPageFromTabIndex);
#endif
#ifdef CTabWnd__GetPageFromTabPoint
REVERSE_DETOUR(class CPageWnd *  CTabWnd::GetPageFromTabPoint(class CXPoint)const ,CTabWnd__GetPageFromTabPoint);
#endif
#ifdef CTabWnd__DrawTab
REVERSE_DETOUR(int  CTabWnd::DrawTab(int)const ,CTabWnd__DrawTab);
#endif
#ifdef CPageWnd__GetTabText
REVERSE_DETOUR(class CXStr  CPageWnd::GetTabText(void)const ,CPageWnd__GetTabText);
#endif
#ifdef CTabWnd__DrawCurrentPage
REVERSE_DETOUR(int  CTabWnd::DrawCurrentPage(void)const ,CTabWnd__DrawCurrentPage);
#endif
#ifdef CXMLSOMDocumentBase__Init
REVERSE_DETOUR(void  CXMLSOMDocumentBase::Init(void),CXMLSOMDocumentBase__Init);
#endif
#ifdef CXMLSOMNodePtr__Assure
REVERSE_DETOUR(void  CXMLSOMNodePtr::Assure(void)const ,CXMLSOMNodePtr__Assure);
#endif
#ifdef CXMLSOMDocumentBase__CursorInit
REVERSE_DETOUR(void  CXMLSOMDocumentBase::CursorInit(void),CXMLSOMDocumentBase__CursorInit);
#endif
#ifdef CXMLSOMNode__CXMLSOMNode
REVERSE_DETOUR( CXMLSOMNode::CXMLSOMNode(void),CXMLSOMNode__CXMLSOMNode);
#endif
#ifdef CXMLSOMDocumentBase__Cursor
REVERSE_DETOUR(class CXMLSOMCursor &  CXMLSOMDocumentBase::Cursor(void),CXMLSOMDocumentBase__Cursor);
#endif
#ifdef CXMLSOMDocumentBase__CursorParent
REVERSE_DETOUR(class CXMLSOMCursor &  CXMLSOMDocumentBase::CursorParent(void),CXMLSOMDocumentBase__CursorParent);
#endif
#ifdef CXMLSOMDocumentBase__CursorNewChild
REVERSE_DETOUR(void  CXMLSOMDocumentBase::CursorNewChild(void),CXMLSOMDocumentBase__CursorNewChild);
#endif
#ifdef CXMLSOMDocumentBase__CursorNewSibling
REVERSE_DETOUR(void  CXMLSOMDocumentBase::CursorNewSibling(void),CXMLSOMDocumentBase__CursorNewSibling);
#endif
#ifdef CXMLSOMNodePtr__operator_equal
REVERSE_DETOUR(class CXMLSOMNodePtr &  CXMLSOMNodePtr::operator=(class CXMLSOMNodePtr const &),CXMLSOMNodePtr__operator_equal);
#endif
#ifdef CXMLSOMDocumentBase__CursorSetPtr
//REVERSE_DETOUR(void  CXMLSOMDocumentBase::CursorSetPtr(class CXMLSOMNodePtr),CXMLSOMDocumentBase__CursorSetPtr);
#endif
#ifdef CXMLSOMNodePtr__operator_minust_
REVERSE_DETOUR(class CXMLSOMNode *  CXMLSOMNodePtr::operator->(void)const ,CXMLSOMNodePtr__operator_minust_);
#endif
#ifdef CXMLSOMDocumentBase__CursorPush
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::CursorPush(void),CXMLSOMDocumentBase__CursorPush);
#endif
#ifdef CXMLSOMDocumentBase__CursorPop
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::CursorPop(void),CXMLSOMDocumentBase__CursorPop);
#endif
#ifdef CXMLSOMDocumentBase__CursorNextSibling
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::CursorNextSibling(void),CXMLSOMDocumentBase__CursorNextSibling);
#endif
#ifdef CXMLSOMDocumentBase__CursorNextInOrder
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::CursorNextInOrder(void),CXMLSOMDocumentBase__CursorNextInOrder);
#endif
#ifdef CXMLSOMDocumentBase__CursorFind
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::CursorFind(class CXStr),CXMLSOMDocumentBase__CursorFind);
#endif
#ifdef CXMLSOMDocumentBase__GetAttrValueStr
REVERSE_DETOUR(class CXStr  CXMLSOMDocumentBase::GetAttrValueStr(class CXStr),CXMLSOMDocumentBase__GetAttrValueStr);
#endif
#ifdef CXMLSOMDocumentBase__GetAttrValueStr1
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::GetAttrValueStr(class CXStr,class CXStr &),CXMLSOMDocumentBase__GetAttrValueStr1);
#endif
#ifdef CXMLSOMDocumentBase__GetAttrValueInt
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::GetAttrValueInt(class CXStr,__int32 &),CXMLSOMDocumentBase__GetAttrValueInt);
#endif
#ifdef CXMLSOMCursorSave__dCXMLSOMCursorSave
REVERSE_DETOUR( CXMLSOMCursorSave::~CXMLSOMCursorSave(void),CXMLSOMCursorSave__dCXMLSOMCursorSave);
#endif
#ifdef CXMLSOMDocumentBase__CursorFieldFind
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::CursorFieldFind(class CXStr),CXMLSOMDocumentBase__CursorFieldFind);
#endif
#ifdef CXMLSOMDocumentBase__GetValue
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::GetValue(class CXStr,class CXStr &),CXMLSOMDocumentBase__GetValue);
#endif
#ifdef CXMLSOMDocumentBase__GetValue1
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::GetValue(class CXStr,__int32 &),CXMLSOMDocumentBase__GetValue1);
#endif
#ifdef CXMLSOMDocumentBase__GetValue2
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::GetValue(class CXStr,bool &),CXMLSOMDocumentBase__GetValue2);
#endif
#ifdef CXMLSOMDocumentBase__FieldParseClassItem
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::FieldParseClassItem(class CXStr,class CXStr &,class CXStr &),CXMLSOMDocumentBase__FieldParseClassItem);
#endif
#ifdef CXMLSOMDocumentBase__FieldParseItemOfClass
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::FieldParseItemOfClass(class CXStr,class CXStr,__int32 &,__int32 &),CXMLSOMDocumentBase__FieldParseItemOfClass);
#endif
#ifdef CXMLSOMDocumentBase__SetValue
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::SetValue(class CXStr,class CXStr),CXMLSOMDocumentBase__SetValue);
#endif
#ifdef CXMLSOMDocumentBase__SetValue1
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::SetValue(class CXStr,__int32),CXMLSOMDocumentBase__SetValue1);
#endif
#ifdef CXMLSOMDocumentBase__SetValue2
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::SetValue(class CXStr,bool),CXMLSOMDocumentBase__SetValue2);
#endif
#ifdef CXMLSOMDocumentBase__XMLReadNoValidate
REVERSE_DETOUR(int  CXMLSOMDocumentBase::XMLReadNoValidate(class CXStr,class CXStr,class CXStr),CXMLSOMDocumentBase__XMLReadNoValidate);
#endif
#ifdef CXMLSOMDocumentBase__XMLRead
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::XMLRead(class CXStr*,class CXStr*,class CXStr*),CXMLSOMDocumentBase__XMLRead);
#endif
#ifdef CXMLSOMDocumentBase__XMLProcessComposite
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::XMLProcessComposite(class CXStr,class CXStr),CXMLSOMDocumentBase__XMLProcessComposite);
#endif
#ifdef CXMLSOMDocumentBase__SetErrorMsg
REVERSE_DETOUR(void  CXMLSOMDocumentBase::SetErrorMsg(class CXStr),CXMLSOMDocumentBase__SetErrorMsg);
#endif
#ifdef CXMLSOMDocumentBase__GetErrorMsg
REVERSE_DETOUR(class CXStr  CXMLSOMDocumentBase::GetErrorMsg(void)const ,CXMLSOMDocumentBase__GetErrorMsg);
#endif
#ifdef CXMLSOMSchema__CXMLSOMSchema
REVERSE_DETOUR( CXMLSOMSchema::CXMLSOMSchema(void),CXMLSOMSchema__CXMLSOMSchema);
#endif
#ifdef CXMLSOMSchema__dCXMLSOMSchema
REVERSE_DETOUR( CXMLSOMSchema::~CXMLSOMSchema(void),CXMLSOMSchema__dCXMLSOMSchema);
#endif
#ifdef CXMLSOMCursorTraverseChildren__dCXMLSOMCursorTraverseChildren
REVERSE_DETOUR( CXMLSOMCursorTraverseChildren::~CXMLSOMCursorTraverseChildren(void),CXMLSOMCursorTraverseChildren__dCXMLSOMCursorTraverseChildren);
#endif
#ifdef CXMLSOMDocumentBase__XMLMerge
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::XMLMerge(class CXMLSOMDocumentBase &),CXMLSOMDocumentBase__XMLMerge);
#endif
#ifdef CXMLSOMCursorTraverseChildren__Cursor
REVERSE_DETOUR(class CXMLSOMCursor &  CXMLSOMCursorTraverseChildren::Cursor(void),CXMLSOMCursorTraverseChildren__Cursor);
#endif
#ifdef CXMLSOMDocumentBase__SetErrorMsgAtLine
REVERSE_DETOUR(void  CXMLSOMDocumentBase::SetErrorMsgAtLine(class CXStr,int,class CXStr),CXMLSOMDocumentBase__SetErrorMsgAtLine);
#endif
#ifdef CXMLSOMDocumentBase__SetErrorMsgAtCursor
REVERSE_DETOUR(void  CXMLSOMDocumentBase::SetErrorMsgAtCursor(class CXStr),CXMLSOMDocumentBase__SetErrorMsgAtCursor);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaSimpleTypeNode
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::ValidateSchemaSimpleTypeNode(class CXMLSOMSimpleType &),CXMLSOMDocumentBase__ValidateSchemaSimpleTypeNode);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaElementType
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::ValidateSchemaElementType(void),CXMLSOMDocumentBase__ValidateSchemaElementType);
#endif
#ifdef CXMLSOMElementType__dCXMLSOMElementType
REVERSE_DETOUR( CXMLSOMElementType::~CXMLSOMElementType(void),CXMLSOMElementType__dCXMLSOMElementType);
#endif
#ifdef CXMLSOMElement__dCXMLSOMElement
REVERSE_DETOUR( CXMLSOMElement::~CXMLSOMElement(void),CXMLSOMElement__dCXMLSOMElement);
#endif
#ifdef CXMLSOMAttributeType__dCXMLSOMAttributeType
REVERSE_DETOUR( CXMLSOMAttributeType::~CXMLSOMAttributeType(void),CXMLSOMAttributeType__dCXMLSOMAttributeType);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaSimpleType
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::ValidateSchemaSimpleType(void),CXMLSOMDocumentBase__ValidateSchemaSimpleType);
#endif
#ifdef CXMLSOMSimpleType__dCXMLSOMSimpleType
REVERSE_DETOUR( CXMLSOMSimpleType::~CXMLSOMSimpleType(void),CXMLSOMSimpleType__dCXMLSOMSimpleType);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaDefinition
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::ValidateSchemaDefinition(void),CXMLSOMDocumentBase__ValidateSchemaDefinition);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaCategories
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::ValidateSchemaCategories(void),CXMLSOMDocumentBase__ValidateSchemaCategories);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaTypeRefs
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::ValidateSchemaTypeRefs(void),CXMLSOMDocumentBase__ValidateSchemaTypeRefs);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchema
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::ValidateSchema(void),CXMLSOMDocumentBase__ValidateSchema);
#endif
#ifdef CXMLSOMDocumentBase__ValidateDataElements
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::ValidateDataElements(class CXMLSOMElementType &),CXMLSOMDocumentBase__ValidateDataElements);
#endif
#ifdef CXMLSOMDocumentBase__ValidateData
REVERSE_DETOUR(bool  CXMLSOMDocumentBase::ValidateData(void),CXMLSOMDocumentBase__ValidateData);
#endif
#ifdef CXMLSOMElementType__GetItemIdx
REVERSE_DETOUR(int  CXMLSOMElementType::GetItemIdx(class CXStr),CXMLSOMElementType__GetItemIdx);
#endif
#ifdef CXMLSOMSchema__GetElementTypeIdx
REVERSE_DETOUR(int  CXMLSOMSchema::GetElementTypeIdx(class CXStr),CXMLSOMSchema__GetElementTypeIdx);
#endif
#ifdef CXMLSOMSchema__IsDerivedFrom
REVERSE_DETOUR(bool  CXMLSOMSchema::IsDerivedFrom(class CXStr,class CXStr),CXMLSOMSchema__IsDerivedFrom);
#endif
#ifdef CXMLSOMSchema__FindElementType
REVERSE_DETOUR(bool  CXMLSOMSchema::FindElementType(class CXStr),CXMLSOMSchema__FindElementType);
#endif
#ifdef CXMLSOMSchema__FindSimpleType
REVERSE_DETOUR(bool  CXMLSOMSchema::FindSimpleType(class CXStr),CXMLSOMSchema__FindSimpleType);
#endif
#ifdef CXMLSOMSchema__FindItem
REVERSE_DETOUR(bool  CXMLSOMSchema::FindItem(class CXStr,class CXStr),CXMLSOMSchema__FindItem);
#endif
#ifdef CXMLSOMSchema__AddItem
REVERSE_DETOUR(bool  CXMLSOMSchema::AddItem(class CXStr,class CXStr),CXMLSOMSchema__AddItem);
#endif
#ifdef CXMLSOMNode__FreeAllAllocs
REVERSE_DETOUR(void __cdecl CXMLSOMNode::FreeAllAllocs(void),CXMLSOMNode__FreeAllAllocs);
#endif
#ifdef CXMLSOMNode__operator_new
REVERSE_DETOUR(void * __cdecl CXMLSOMNode::operator new(unsigned int),CXMLSOMNode__operator_new);
#endif
#ifdef CMutexLock__dCMutexLock
REVERSE_DETOUR( CMutexLock::~CMutexLock(void),CMutexLock__dCMutexLock);
#endif
#ifdef CXMLSOMNode__operator_delete
REVERSE_DETOUR(void __cdecl CXMLSOMNode::operator delete(void *),CXMLSOMNode__operator_delete);
#endif
#ifdef CKeyCXStrValueInt32__CKeyCXStrValueInt32
REVERSE_DETOUR( CKeyCXStrValueInt32::CKeyCXStrValueInt32(void),CKeyCXStrValueInt32__CKeyCXStrValueInt32);
#endif
#ifdef CXMLSOMCursor__CXMLSOMCursor
REVERSE_DETOUR( CXMLSOMCursor::CXMLSOMCursor(void),CXMLSOMCursor__CXMLSOMCursor);
#endif
#ifdef CXMLSOMNodePtr__CXMLSOMNodePtr
REVERSE_DETOUR( CXMLSOMNodePtr::CXMLSOMNodePtr(void),CXMLSOMNodePtr__CXMLSOMNodePtr);
#endif
#ifdef CXMLSOMAttribute__operator_equal
REVERSE_DETOUR(class CXMLSOMAttribute &  CXMLSOMAttribute::operator=(class CXMLSOMAttribute const &),CXMLSOMAttribute__operator_equal);
#endif
#ifdef CXMLSOMCursor__operator_equal
REVERSE_DETOUR(class CXMLSOMCursor &  CXMLSOMCursor::operator=(class CXMLSOMCursor const &),CXMLSOMCursor__operator_equal);
#endif
#ifdef CXMLSOMAttribute__CXMLSOMAttribute
REVERSE_DETOUR( CXMLSOMAttribute::CXMLSOMAttribute(void),CXMLSOMAttribute__CXMLSOMAttribute);
#endif
#ifdef CXMLSOMSimpleType__CXMLSOMSimpleType
REVERSE_DETOUR( CXMLSOMSimpleType::CXMLSOMSimpleType(void),CXMLSOMSimpleType__CXMLSOMSimpleType);
#endif
#ifdef CXMLSOMElementType__CXMLSOMElementType
REVERSE_DETOUR( CXMLSOMElementType::CXMLSOMElementType(void),CXMLSOMElementType__CXMLSOMElementType);
#endif
#ifdef CXMLSOMAttributeType__operator_equal
REVERSE_DETOUR(class CXMLSOMAttributeType &  CXMLSOMAttributeType::operator=(class CXMLSOMAttributeType const &),CXMLSOMAttributeType__operator_equal);
#endif
#ifdef CXMLSOMElement__operator_equal
REVERSE_DETOUR(class CXMLSOMElement &  CXMLSOMElement::operator=(class CXMLSOMElement const &),CXMLSOMElement__operator_equal);
#endif
#ifdef CXMLSOMAttributeType__CXMLSOMAttributeType
REVERSE_DETOUR( CXMLSOMAttributeType::CXMLSOMAttributeType(void),CXMLSOMAttributeType__CXMLSOMAttributeType);
#endif
#ifdef CXMLSOMElement__CXMLSOMElement
REVERSE_DETOUR( CXMLSOMElement::CXMLSOMElement(void),CXMLSOMElement__CXMLSOMElement);
#endif
#ifdef KeyCombo__KeyCombo
REVERSE_DETOUR( KeyCombo::KeyCombo(void),KeyCombo__KeyCombo);
#endif
#ifdef KeyCombo__KeyCombo1
REVERSE_DETOUR( KeyCombo::KeyCombo(unsigned char,bool,bool,bool),KeyCombo__KeyCombo1);
#endif
#ifdef KeyCombo__KeyCombo2
REVERSE_DETOUR( KeyCombo::KeyCombo(int),KeyCombo__KeyCombo2);
#endif
#ifdef KeyCombo__KeyCombo3
REVERSE_DETOUR( KeyCombo::KeyCombo(unsigned int,unsigned int,bool,bool,bool),KeyCombo__KeyCombo3);
#endif
#ifdef KeyCombo__GetKey
REVERSE_DETOUR(unsigned int  KeyCombo::GetKey(void)const ,KeyCombo__GetKey);
#endif
#ifdef KeyCombo__UsesCtrl
REVERSE_DETOUR(bool  KeyCombo::UsesCtrl(void)const ,KeyCombo__UsesCtrl);
#endif
#ifdef KeyCombo__UsesShift
REVERSE_DETOUR(bool  KeyCombo::UsesShift(void)const ,KeyCombo__UsesShift);
#endif
#ifdef KeyCombo__UsesAlt
REVERSE_DETOUR(bool  KeyCombo::UsesAlt(void)const ,KeyCombo__UsesAlt);
#endif
#ifdef KeyCombo__GetTextDescription
REVERSE_DETOUR(class CXStr  KeyCombo::GetTextDescription(void)const ,KeyCombo__GetTextDescription);
#endif
#ifdef KeyCombo__GetPrintableLetter
REVERSE_DETOUR(bool  KeyCombo::GetPrintableLetter(unsigned short *)const ,KeyCombo__GetPrintableLetter);
#endif
#ifdef KeyCombo__operator_equal_equal
REVERSE_DETOUR(int  KeyCombo::operator==(class KeyCombo const &)const ,KeyCombo__operator_equal_equal);
#endif
#ifdef KeyCombo__operator_equal
REVERSE_DETOUR(class KeyCombo const &  KeyCombo::operator=(int),KeyCombo__operator_equal);
#endif
#ifdef KeyCombo__operator_int
//REVERSE_DETOUR( KeyCombo::operator int(void)const ,KeyCombo__operator_int);
#endif
#ifdef KeyCombo__GetVirtualKeyFromScanCode
REVERSE_DETOUR(bool  KeyCombo::GetVirtualKeyFromScanCode(unsigned char,int *)const ,KeyCombo__GetVirtualKeyFromScanCode);
#endif
#ifdef KeyCombo__GetPrintableLetterFromScanCode
REVERSE_DETOUR(bool  KeyCombo::GetPrintableLetterFromScanCode(unsigned char,bool,bool,unsigned short *)const ,KeyCombo__GetPrintableLetterFromScanCode);
#endif
#ifdef KeyCombo__GetScanCodeFromVirtualKey
REVERSE_DETOUR(bool  KeyCombo::GetScanCodeFromVirtualKey(unsigned int,unsigned int,unsigned char *)const ,KeyCombo__GetScanCodeFromVirtualKey);
#endif
#ifdef KeyCombo__GetPrintableLetterFromVirtualKey
REVERSE_DETOUR(bool  KeyCombo::GetPrintableLetterFromVirtualKey(unsigned int,unsigned int,bool,bool,unsigned short *)const ,KeyCombo__GetPrintableLetterFromVirtualKey);
#endif
#ifdef CButtonWnd__CButtonWnd
REVERSE_DETOUR( CButtonWnd::CButtonWnd(class CXWnd *,unsigned __int32,class CXRect,class CXPoint,class CXSize,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *),CButtonWnd__CButtonWnd);
#endif
#ifdef CXWnd__IsEnabled
REVERSE_DETOUR(bool  CXWnd::IsEnabled(void)const ,CXWnd__IsEnabled);
#endif
#ifdef CButtonWnd__SetCheck
REVERSE_DETOUR(void  CButtonWnd::SetCheck(bool),CButtonWnd__SetCheck);
#endif
#ifdef CComboWnd__CComboWnd
//REVERSE_DETOUR( CComboWnd::CComboWnd(class CXWnd *,unsigned __int32,class CXRect,int,class CButtonDrawTemplate,class CListWnd *),CComboWnd__CComboWnd);
#endif
#ifdef CXWnd__GetWidth
REVERSE_DETOUR(int  CXWnd::GetWidth(void)const ,CXWnd__GetWidth);
#endif
#ifdef CComboWnd__GetListRect
REVERSE_DETOUR(class CXRect  CComboWnd::GetListRect(void)const ,CComboWnd__GetListRect);
#endif
#ifdef CComboWnd__SetColors
REVERSE_DETOUR(void  CComboWnd::SetColors(unsigned long,unsigned long,unsigned long),CComboWnd__SetColors);
#endif
#ifdef CComboWnd__InsertChoice
REVERSE_DETOUR(void  CComboWnd::InsertChoice(class CXStr),CComboWnd__InsertChoice);
#endif
#ifdef CComboWnd__SetChoice
REVERSE_DETOUR(void  CComboWnd::SetChoice(int),CComboWnd__SetChoice);
#endif
#ifdef CComboWnd__GetItemCount
REVERSE_DETOUR(int  CComboWnd::GetItemCount(void),CComboWnd__GetItemCount);
#endif
#ifdef CComboWnd__GetCurChoice
REVERSE_DETOUR(int  CComboWnd::GetCurChoice(void)const ,CComboWnd__GetCurChoice);
#endif
#ifdef CComboWnd__GetCurChoiceText
REVERSE_DETOUR(class CXStr  CComboWnd::GetCurChoiceText(void)const ,CComboWnd__GetCurChoiceText);
#endif
#ifdef CComboWnd__DeleteAll
REVERSE_DETOUR(void  CComboWnd::DeleteAll(void),CComboWnd__DeleteAll);
#endif
#ifdef CComboWnd__GetButtonRect
REVERSE_DETOUR(class CXRect  CComboWnd::GetButtonRect(void)const ,CComboWnd__GetButtonRect);
#endif
#ifdef CComboWnd__GetTextRect
REVERSE_DETOUR(class CXRect  CComboWnd::GetTextRect(void)const ,CComboWnd__GetTextRect);
#endif
#ifdef CXWndManager__CXWndManager
REVERSE_DETOUR( CXWndManager::CXWndManager(class CSidlManager *),CXWndManager__CXWndManager);
#endif
#ifdef CXWndManager__DestroyAllWindows
REVERSE_DETOUR(void  CXWndManager::DestroyAllWindows(void),CXWndManager__DestroyAllWindows);
#endif
#ifdef CXWndManager__DrawWindows
REVERSE_DETOUR(int  CXWndManager::DrawWindows(void)const ,CXWndManager__DrawWindows);
#endif
#ifdef CXWndManager__DrawCursor
REVERSE_DETOUR(int  CXWndManager::DrawCursor(void)const ,CXWndManager__DrawCursor);
#endif
#ifdef CXWndManager__AddWnd
REVERSE_DETOUR(int  CXWndManager::AddWnd(class CXWnd *),CXWndManager__AddWnd);
#endif
#ifdef CXWndManager__RemoveWnd
REVERSE_DETOUR(int  CXWndManager::RemoveWnd(class CXWnd *),CXWndManager__RemoveWnd);
#endif
#ifdef CXWndManager__CheckInvalidateLastFoundWnd
REVERSE_DETOUR(void  CXWndManager::CheckInvalidateLastFoundWnd(void),CXWndManager__CheckInvalidateLastFoundWnd);
#endif
#ifdef CXWndManager__GetKeyboardFlags
REVERSE_DETOUR(unsigned __int32  CXWndManager::GetKeyboardFlags(void)const ,CXWndManager__GetKeyboardFlags);
#endif
#ifdef CXWndManager__FlushKeyboardFlags
REVERSE_DETOUR(void  CXWndManager::FlushKeyboardFlags(void),CXWndManager__FlushKeyboardFlags);
#endif
#ifdef CXWndManager__UpdateChildAndSiblingInfo
REVERSE_DETOUR(void  CXWndManager::UpdateChildAndSiblingInfo(void),CXWndManager__UpdateChildAndSiblingInfo);
#endif
#ifdef CXWndManager__HandleKeyboardMsg
REVERSE_DETOUR(int  CXWndManager::HandleKeyboardMsg(unsigned __int32,bool),CXWndManager__HandleKeyboardMsg);
#endif
#ifdef CXWndManager__OkayToSendMouseMessage
REVERSE_DETOUR(bool  CXWndManager::OkayToSendMouseMessage(class CXWnd *)const,CXWndManager__OkayToSendMouseMessage);
#endif
#ifdef CXWndManager__HandleMouseMove
REVERSE_DETOUR(int  CXWndManager::HandleMouseMove(class CXPoint),CXWndManager__HandleMouseMove);
#endif
#ifdef CXWndManager__HandleWheelMove
REVERSE_DETOUR(int  CXWndManager::HandleWheelMove(int),CXWndManager__HandleWheelMove);
#endif
#ifdef CXWndManager__HandleLButtonDown
REVERSE_DETOUR(int  CXWndManager::HandleLButtonDown(class CXPoint),CXWndManager__HandleLButtonDown);
#endif
#ifdef CXWndManager__IsWindowPieceDown
REVERSE_DETOUR(bool  CXWndManager::IsWindowPieceDown(class CXWnd const *,int)const ,CXWndManager__IsWindowPieceDown);
#endif
#ifdef CXWndManager__OnWindowCloseBox
REVERSE_DETOUR(int  CXWndManager::OnWindowCloseBox(class CXWnd *),CXWndManager__OnWindowCloseBox);
#endif
#ifdef CXWndManager__OnWindowMinimizeBox
REVERSE_DETOUR(int  CXWndManager::OnWindowMinimizeBox(class CXWnd *),CXWndManager__OnWindowMinimizeBox);
#endif
#ifdef CXWndManager__OnWindowTileBox
REVERSE_DETOUR(int  CXWndManager::OnWindowTileBox(class CXWnd *),CXWndManager__OnWindowTileBox);
#endif
#ifdef CXWndManager__HandleLButtonHeld
REVERSE_DETOUR(int  CXWndManager::HandleLButtonHeld(class CXPoint),CXWndManager__HandleLButtonHeld);
#endif
#ifdef CXWndManager__HandleLButtonUpAfterHeld
REVERSE_DETOUR(int  CXWndManager::HandleLButtonUpAfterHeld(class CXPoint),CXWndManager__HandleLButtonUpAfterHeld);
#endif
#ifdef CXWndManager__HandleRButtonHeld
REVERSE_DETOUR(int  CXWndManager::HandleRButtonHeld(class CXPoint),CXWndManager__HandleRButtonHeld);
#endif
#ifdef CXWndManager__HandleRButtonUpAfterHeld
REVERSE_DETOUR(int  CXWndManager::HandleRButtonUpAfterHeld(class CXPoint),CXWndManager__HandleRButtonUpAfterHeld);
#endif
#ifdef CXWndManager__HandleLButtonUp
REVERSE_DETOUR(int  CXWndManager::HandleLButtonUp(class CXPoint),CXWndManager__HandleLButtonUp);
#endif
#ifdef CXWndManager__HandleRButtonDown
REVERSE_DETOUR(int  CXWndManager::HandleRButtonDown(class CXPoint),CXWndManager__HandleRButtonDown);
#endif
#ifdef CXWndManager__HandleRButtonUp
REVERSE_DETOUR(int  CXWndManager::HandleRButtonUp(class CXPoint),CXWndManager__HandleRButtonUp);
#endif
#ifdef CXWndManager__FindWnd
REVERSE_DETOUR(class CXWnd *  CXWndManager::FindWnd(class CXPoint,int *)const,CXWndManager__FindWnd);
#endif
#ifdef CXWndManager__GetCursorToDisplay
REVERSE_DETOUR(class CTextureAnimation const *  CXWndManager::GetCursorToDisplay(void)const ,CXWndManager__GetCursorToDisplay);
#endif
#ifdef CXWndManager__SetFocusWnd
REVERSE_DETOUR(class CXWnd *  CXWndManager::SetFocusWnd(class CXWnd *),CXWndManager__SetFocusWnd);
#endif
#ifdef CXWndManager__GetFocusWnd
REVERSE_DETOUR(class CXWnd *  CXWndManager::GetFocusWnd(void)const ,CXWndManager__GetFocusWnd);
#endif
#ifdef CXWndManager__ProcessFrame
REVERSE_DETOUR(int  CXWndManager::ProcessFrame(void),CXWndManager__ProcessFrame);
#endif
#ifdef CXWndManager__OnWindowShown
REVERSE_DETOUR(void  CXWndManager::OnWindowShown(class CXWnd *,bool),CXWndManager__OnWindowShown);
#endif
#ifdef CXWndManager__BringWndToTop
REVERSE_DETOUR(void  CXWndManager::BringWndToTop(class CXWnd *,bool),CXWndManager__BringWndToTop);
#endif
#ifdef CXWndManager__NotifyAllWindows
REVERSE_DETOUR(int  CXWndManager::NotifyAllWindows(class CXWnd *,unsigned __int32,void *),CXWndManager__NotifyAllWindows);
#endif
#ifdef CXWndManager__CleanupWindows
REVERSE_DETOUR(void  CXWndManager::CleanupWindows(void),CXWndManager__CleanupWindows);
#endif
#ifdef CXWndManager__GetFirstChildWnd
REVERSE_DETOUR(class CXWnd *  CXWndManager::GetFirstChildWnd(class CXWnd const *)const ,CXWndManager__GetFirstChildWnd);
#endif
#ifdef CXWndManager__GetNextSib
REVERSE_DETOUR(class CXWnd *  CXWndManager::GetNextSib(class CXWnd const *)const ,CXWndManager__GetNextSib);
#endif
#ifdef CXWndManager__ActivateWnd
REVERSE_DETOUR(int  CXWndManager::ActivateWnd(class CXWnd *),CXWndManager__ActivateWnd);
#endif
#ifdef CXWndManager__IsWindowActive
REVERSE_DETOUR(bool  CXWndManager::IsWindowActive(class CXWnd const *)const ,CXWndManager__IsWindowActive);
#endif
#ifdef CXWndManager__IsWindowMovingOrSizing
REVERSE_DETOUR(bool  CXWndManager::IsWindowMovingOrSizing(class CXWnd *)const ,CXWndManager__IsWindowMovingOrSizing);
#endif
#ifdef CXWndManager__AddFont
REVERSE_DETOUR(int  CXWndManager::AddFont(class CTextureFont *),CXWndManager__AddFont);
#endif
#ifdef CXWndManager__GetFont1
REVERSE_DETOUR(class CTextureFont *  CXWndManager::GetFont(class CXStr),CXWndManager__GetFont1);
#endif
#ifdef CXWndManager__SetSystemFont
REVERSE_DETOUR(void  CXWndManager::SetSystemFont(class CTextureFont *),CXWndManager__SetSystemFont);
#endif
#ifdef CXWndManager__SetGlobalFadeDuration
REVERSE_DETOUR(void  CXWndManager::SetGlobalFadeDuration(unsigned __int32),CXWndManager__SetGlobalFadeDuration);
#endif
#ifdef CXWndManager__GetGlobalFadeDuration
REVERSE_DETOUR(unsigned __int32  CXWndManager::GetGlobalFadeDuration(void)const ,CXWndManager__GetGlobalFadeDuration);
#endif
#ifdef CXWndManager__SetGlobalFadeDelay
REVERSE_DETOUR(void  CXWndManager::SetGlobalFadeDelay(unsigned long),CXWndManager__SetGlobalFadeDelay);
#endif
#ifdef CXWndManager__GetGlobalFadeDelay
REVERSE_DETOUR(unsigned long  CXWndManager::GetGlobalFadeDelay(void)const ,CXWndManager__GetGlobalFadeDelay);
#endif
#ifdef CXWndManager__SetGlobalAlpha
REVERSE_DETOUR(void  CXWndManager::SetGlobalAlpha(unsigned char),CXWndManager__SetGlobalAlpha);
#endif
#ifdef CXWndManager__GetGlobalAlpha
REVERSE_DETOUR(unsigned char  CXWndManager::GetGlobalAlpha(void)const ,CXWndManager__GetGlobalAlpha);
#endif
#ifdef CXWndManager__SetGlobalFadeToAlpha
REVERSE_DETOUR(void  CXWndManager::SetGlobalFadeToAlpha(unsigned char),CXWndManager__SetGlobalFadeToAlpha);
#endif
#ifdef CXWndManager__GetGlobalFadeToAlpha
REVERSE_DETOUR(unsigned char  CXWndManager::GetGlobalFadeToAlpha(void)const ,CXWndManager__GetGlobalFadeToAlpha);
#endif
#ifdef CXWndManager__IsAllValid
REVERSE_DETOUR(bool  CXWndManager::IsAllValid(void),CXWndManager__IsAllValid);
#endif
#ifdef CEditWnd__CEditWnd
//REVERSE_DETOUR( CEditWnd::CEditWnd(class CXWnd *,unsigned __int32,class CXRect,unsigned __int32),CEditWnd__CEditWnd);
#endif
#ifdef CEditWnd__GetLineForPrintableChar
REVERSE_DETOUR(int  CEditWnd::GetLineForPrintableChar(int)const ,CEditWnd__GetLineForPrintableChar);
#endif
#ifdef CEditWnd__GetLineLength
REVERSE_DETOUR(int  CEditWnd::GetLineLength(int)const ,CEditWnd__GetLineLength);
#endif
#ifdef CEditWnd__FillIndexArray
REVERSE_DETOUR(void  CEditWnd::FillIndexArray(class CXStr)const ,CEditWnd__FillIndexArray);
#endif
#ifdef CEditWnd__SelectableCharFromPoint
REVERSE_DETOUR(int  CEditWnd::SelectableCharFromPoint(class CXPoint)const ,CEditWnd__SelectableCharFromPoint);
#endif
#ifdef CEditWnd__AddItemTag
REVERSE_DETOUR(void  CEditWnd::AddItemTag(int,char *,int),CEditWnd__AddItemTag);
#endif
#ifdef CEditWnd__ProcessText
REVERSE_DETOUR(void  CEditWnd::ProcessText(void),CEditWnd__ProcessText);
#endif
#ifdef CEditWnd__GetCharIndexPt
REVERSE_DETOUR(class CXPoint  CEditWnd::GetCharIndexPt(int)const ,CEditWnd__GetCharIndexPt);
#endif
#ifdef CEditWnd__GetSelStartPt
REVERSE_DETOUR(class CXPoint  CEditWnd::GetSelStartPt(void)const ,CEditWnd__GetSelStartPt);
#endif
#ifdef CEditWnd__GetSelEndPt
REVERSE_DETOUR(class CXPoint  CEditWnd::GetSelEndPt(void)const ,CEditWnd__GetSelEndPt);
#endif
#ifdef CEditWnd__FilterInputStr
REVERSE_DETOUR(void  CEditWnd::FilterInputStr(class CXStr &),CEditWnd__FilterInputStr);
#endif
#ifdef CEditWnd__ReplaceSelection
REVERSE_DETOUR(void  CEditWnd::ReplaceSelection(class CXStr,bool),CEditWnd__ReplaceSelection);
#endif
#ifdef CEditWnd__ReplaceSelection1
REVERSE_DETOUR(void  CEditWnd::ReplaceSelection(char,bool),CEditWnd__ReplaceSelection1);
#endif
#ifdef CEditWnd__CalculateScrollRange
REVERSE_DETOUR(void  CEditWnd::CalculateScrollRange(void),CEditWnd__CalculateScrollRange);
#endif
#ifdef CEditWnd__EnsureCaretVisible
REVERSE_DETOUR(void  CEditWnd::EnsureCaretVisible(void),CEditWnd__EnsureCaretVisible);
#endif
#ifdef CEditWnd__SetEditable
REVERSE_DETOUR(void  CEditWnd::SetEditable(bool),CEditWnd__SetEditable);
#endif
#ifdef CEditWnd__GetSTMLSafeText
REVERSE_DETOUR(class CXStr  CEditWnd::GetSTMLSafeText(void),CEditWnd__GetSTMLSafeText);
#endif
#ifdef CEditWnd__ConvertIndexPrintableToTagged
REVERSE_DETOUR(int  CEditWnd::ConvertIndexPrintableToTagged(int),CEditWnd__ConvertIndexPrintableToTagged);
#endif
#ifdef CEditWnd__ConvertIndexTaggedToPrintable
REVERSE_DETOUR(int  CEditWnd::ConvertIndexTaggedToPrintable(int),CEditWnd__ConvertIndexTaggedToPrintable);
#endif
#ifdef CTextureFont__GetWidth
REVERSE_DETOUR(int  CTextureFont::GetWidth(unsigned short)const ,CTextureFont__GetWidth);
#endif
#ifdef CTextureFont__GetKerning
REVERSE_DETOUR(int  CTextureFont::GetKerning(unsigned short,unsigned short)const ,CTextureFont__GetKerning);
#endif
#ifdef CTextureFont__GetTextExtent
REVERSE_DETOUR(int  CTextureFont::GetTextExtent(class CXStr)const ,CTextureFont__GetTextExtent);
#endif
#ifdef CTextureFont__GetHeight
REVERSE_DETOUR(int  CTextureFont::GetHeight(void)const ,CTextureFont__GetHeight);
#endif
#ifdef CTextureFont__GetName
REVERSE_DETOUR(class CXStr  CTextureFont::GetName(void)const ,CTextureFont__GetName);
#endif
#ifdef CTextureFont__DrawWrappedText
REVERSE_DETOUR(int  CTextureFont::DrawWrappedText(class CXStr,int,int,int,class CXRect,unsigned long,unsigned short,int)const ,CTextureFont__DrawWrappedText);
#endif
#ifdef CTextureFont__DrawWrappedText1
REVERSE_DETOUR(int  CTextureFont::DrawWrappedText(class CXStr,class CXRect,class CXRect,unsigned long,unsigned short,int)const ,CTextureFont__DrawWrappedText1);
#endif
#ifdef CTextureAnimation__CTextureAnimation
REVERSE_DETOUR( CTextureAnimation::CTextureAnimation(void),CTextureAnimation__CTextureAnimation);
#endif
#ifdef CTextureAnimation__CTextureAnimation1
REVERSE_DETOUR( CTextureAnimation::CTextureAnimation(class CXStr),CTextureAnimation__CTextureAnimation1);
#endif
#ifdef CUITexturePiece__CUITexturePiece1
REVERSE_DETOUR( CUITexturePiece::CUITexturePiece(class CUITexturePiece const &),CUITexturePiece__CUITexturePiece1);
#endif
#ifdef CTextureAnimation__AddFrame
REVERSE_DETOUR(int  CTextureAnimation::AddFrame(class CUITextureInfo const *,class CXRect,unsigned __int32,class CXPoint),CTextureAnimation__AddFrame);
#endif
#ifdef CUITexturePiece__CUITexturePiece2
//REVERSE_DETOUR( CUITexturePiece::CUITexturePiece(class CUITextureInfo,class CXRect),CUITexturePiece__CUITexturePiece2);
#endif
#ifdef CUITextureInfo__CUITextureInfo2
REVERSE_DETOUR( CUITextureInfo::CUITextureInfo(class CUITextureInfo const &),CUITextureInfo__CUITextureInfo2);
#endif
#ifdef CTextureAnimation__AddFrame1
//REVERSE_DETOUR(int  CTextureAnimation::AddFrame(class CUITexturePiece,unsigned __int32,class CXPoint),CTextureAnimation__AddFrame1);
#endif
#ifdef STextureAnimationFrame__STextureAnimationFrame1
REVERSE_DETOUR( STextureAnimationFrame::STextureAnimationFrame(class CUITexturePiece,unsigned __int32,class CXPoint),STextureAnimationFrame__STextureAnimationFrame1);
#endif
#ifdef CUITextureInfo__CUITextureInfo3
REVERSE_DETOUR( CUITextureInfo::CUITextureInfo(unsigned __int32,int),CUITextureInfo__CUITextureInfo3);
#endif
#ifdef CTextureAnimation__AddBlankFrame
REVERSE_DETOUR(int  CTextureAnimation::AddBlankFrame(unsigned __int32,class CXPoint),CTextureAnimation__AddBlankFrame);
#endif
#ifdef CTextureAnimation__SetCurFrame
REVERSE_DETOUR(void  CTextureAnimation::SetCurFrame(int),CTextureAnimation__SetCurFrame);
#endif
#ifdef CTextureAnimation__GetCurFrame
REVERSE_DETOUR(int  CTextureAnimation::GetCurFrame(void)const ,CTextureAnimation__GetCurFrame);
#endif
#ifdef CTextureAnimation__Draw
REVERSE_DETOUR(int  CTextureAnimation::Draw(class CXRect,class CXRect,unsigned long,unsigned long)const ,CTextureAnimation__Draw);
#endif
#ifdef CTextureAnimation__Draw1
REVERSE_DETOUR(int  CTextureAnimation::Draw(class CXPoint,class CXRect,unsigned long,unsigned long)const ,CTextureAnimation__Draw1);
#endif
#ifdef CTextureAnimation__GetHotspot
REVERSE_DETOUR(class CXPoint  CTextureAnimation::GetHotspot(void)const ,CTextureAnimation__GetHotspot);
#endif
#ifdef CTextureAnimation__SetCurCell
REVERSE_DETOUR(void  CTextureAnimation::SetCurCell(int),CTextureAnimation__SetCurCell);
#endif
#ifdef CTextureAnimation__Preload
REVERSE_DETOUR(int  CTextureAnimation::Preload(void),CTextureAnimation__Preload);
#endif
#ifdef CUITextureInfo__operator_equal
REVERSE_DETOUR(class CUITextureInfo &  CUITextureInfo::operator=(class CUITextureInfo const &),CUITextureInfo__operator_equal);
#endif
#ifdef CSidlManager__CSidlManager
REVERSE_DETOUR( CSidlManager::CSidlManager(void),CSidlManager__CSidlManager);
#endif
#ifdef CSidlManager__GetPointFromParamPoint
REVERSE_DETOUR(class CXPoint __cdecl CSidlManager::GetPointFromParamPoint(class CParamPoint const &),CSidlManager__GetPointFromParamPoint);
#endif
#ifdef CSidlManager__GetSizeFromParamSize
REVERSE_DETOUR(class CXSize __cdecl CSidlManager::GetSizeFromParamSize(class CParamSize const &),CSidlManager__GetSizeFromParamSize);
#endif
#ifdef CSidlManager__GetRectFromParamPointSize
REVERSE_DETOUR(class CXRect __cdecl CSidlManager::GetRectFromParamPointSize(class CParamPoint const &,class CParamSize const &),CSidlManager__GetRectFromParamPointSize);
#endif
#ifdef CSidlManager__GetD3DCOLOR
REVERSE_DETOUR(unsigned long __cdecl CSidlManager::GetD3DCOLOR(class CParamRGB const &),CSidlManager__GetD3DCOLOR);
#endif
#ifdef CSidlManager__GetButtonDrawTemplateFromParamButtonDrawTemplate
REVERSE_DETOUR(class CButtonDrawTemplate  CSidlManager::GetButtonDrawTemplateFromParamButtonDrawTemplate(class CParamButtonDrawTemplate const &)const ,CSidlManager__GetButtonDrawTemplateFromParamButtonDrawTemplate);
#endif
#ifdef CSidlManager__GetGaugeDrawTemplateFromParamGaugeDrawTemplate
REVERSE_DETOUR(class CGaugeDrawTemplate  CSidlManager::GetGaugeDrawTemplateFromParamGaugeDrawTemplate(class CParamGaugeDrawTemplate const &)const ,CSidlManager__GetGaugeDrawTemplateFromParamGaugeDrawTemplate);
#endif
#ifdef CSidlManager__GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate
REVERSE_DETOUR(class CSpellGemDrawTemplate  CSidlManager::GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate(class CParamSpellGemDrawTemplate const &)const ,CSidlManager__GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate);
#endif
#ifdef CSidlManager__DeleteContents
REVERSE_DETOUR(void  CSidlManager::DeleteContents(void),CSidlManager__DeleteContents);
#endif
#ifdef CParamScrollbarDrawTemplate__operator_equal
REVERSE_DETOUR(class CParamScrollbarDrawTemplate &  CParamScrollbarDrawTemplate::operator=(class CParamScrollbarDrawTemplate const &),CParamScrollbarDrawTemplate__operator_equal);
#endif
#ifdef CParamFrameTemplate__operator_equal
REVERSE_DETOUR(class CParamFrameTemplate &  CParamFrameTemplate::operator=(class CParamFrameTemplate const &),CParamFrameTemplate__operator_equal);
#endif
#ifdef CParamButtonDrawTemplate__operator_equal
REVERSE_DETOUR(class CParamButtonDrawTemplate &  CParamButtonDrawTemplate::operator=(class CParamButtonDrawTemplate const &),CParamButtonDrawTemplate__operator_equal);
#endif
#ifdef CParamClass__operator_equal
REVERSE_DETOUR(class CParamClass &  CParamClass::operator=(class CParamClass const &),CParamClass__operator_equal);
#endif
#ifdef CParamRGB__operator_equal
REVERSE_DETOUR(class CParamRGB &  CParamRGB::operator=(class CParamRGB const &),CParamRGB__operator_equal);
#endif
#ifdef CParam__operator_equal
REVERSE_DETOUR(class CParam &  CParam::operator=(class CParam const &),CParam__operator_equal);
#endif
#ifdef CXMLData__operator_equal
REVERSE_DETOUR(class CXMLData &  CXMLData::operator=(class CXMLData const &),CXMLData__operator_equal);
#endif
#ifdef CTAFrameDraw__GetName
REVERSE_DETOUR(class CXStr  CTAFrameDraw::GetName(void)const ,CTAFrameDraw__GetName);
#endif
#ifdef CScreenPieceTemplate__GetName
REVERSE_DETOUR(class CXStr  CScreenPieceTemplate::GetName(void)const ,CScreenPieceTemplate__GetName);
#endif
#ifdef CSidlManager__LoadSidl
REVERSE_DETOUR(void  CSidlManager::LoadSidl(class CXStr,class CXStr,class CXStr),CSidlManager__LoadSidl);
#endif
#ifdef CUITextureInfo__CUITextureInfo4
REVERSE_DETOUR( CUITextureInfo::CUITextureInfo(class CXStr,class CXSize),CUITextureInfo__CUITextureInfo4);
#endif
#ifdef CSidlManager__CreateTextureAnimationFromSidlAnimation
REVERSE_DETOUR(class CTextureAnimation  CSidlManager::CreateTextureAnimationFromSidlAnimation(class CParamUi2DAnimation const *)const ,CSidlManager__CreateTextureAnimationFromSidlAnimation);
#endif
#ifdef CSidlManager__CreateTAFrameDrawFromSidlFrame
REVERSE_DETOUR(class CTAFrameDraw  CSidlManager::CreateTAFrameDrawFromSidlFrame(class CParamFrameTemplate const *)const ,CSidlManager__CreateTAFrameDrawFromSidlFrame);
#endif
#ifdef CSidlManager__GetScrollbarTemplateFromParamScrollbarTemplate
REVERSE_DETOUR(class CScrollbarTemplate  CSidlManager::GetScrollbarTemplateFromParamScrollbarTemplate(class CParamScrollbarDrawTemplate const &)const ,CSidlManager__GetScrollbarTemplateFromParamScrollbarTemplate);
#endif
#ifdef CScrollbarTemplate__CScrollbarTemplate
REVERSE_DETOUR( CScrollbarTemplate::CScrollbarTemplate(class CScrollbarTemplate const &),CScrollbarTemplate__CScrollbarTemplate);
#endif
#ifdef CSidlManager__GetSliderDrawTemplateFromParamSliderDrawTemplate
REVERSE_DETOUR(class CSliderDrawTemplate  CSidlManager::GetSliderDrawTemplateFromParamSliderDrawTemplate(class CParamSliderDrawTemplate const &)const ,CSidlManager__GetSliderDrawTemplateFromParamSliderDrawTemplate);
#endif
#ifdef CButtonDrawTemplate__CButtonDrawTemplate1
REVERSE_DETOUR( CButtonDrawTemplate::CButtonDrawTemplate(class CButtonDrawTemplate const &),CButtonDrawTemplate__CButtonDrawTemplate1);
#endif
#ifdef CSliderDrawTemplate__dCSliderDrawTemplate
REVERSE_DETOUR( CSliderDrawTemplate::~CSliderDrawTemplate(void),CSliderDrawTemplate__dCSliderDrawTemplate);
#endif
#ifdef CSidlManager__CreateDrawTemplateFromParamWindowDrawTemplate
REVERSE_DETOUR(class CXWndDrawTemplate  CSidlManager::CreateDrawTemplateFromParamWindowDrawTemplate(class CParamWindowDrawTemplate const *)const ,CSidlManager__CreateDrawTemplateFromParamWindowDrawTemplate);
#endif
#ifdef CScrollbarTemplate__CScrollbarTemplate1
REVERSE_DETOUR( CScrollbarTemplate::CScrollbarTemplate(void),CScrollbarTemplate__CScrollbarTemplate1);
#endif
#ifdef CXWndDrawTemplate__CXWndDrawTemplate1
REVERSE_DETOUR( CXWndDrawTemplate::CXWndDrawTemplate(class CXWndDrawTemplate const &),CXWndDrawTemplate__CXWndDrawTemplate1);
#endif
#ifdef CTAFrameDraw__CTAFrameDraw
REVERSE_DETOUR( CTAFrameDraw::CTAFrameDraw(class CTAFrameDraw const &),CTAFrameDraw__CTAFrameDraw);
#endif
#ifdef CSidlManager__CreateScreenPieceTemplateFromParamScreenPiece
REVERSE_DETOUR(class CScreenPieceTemplate *  CSidlManager::CreateScreenPieceTemplateFromParamScreenPiece(class CParamScreenPiece const *)const ,CSidlManager__CreateScreenPieceTemplateFromParamScreenPiece);
#endif
#ifdef CSidlManager__GetParsingErrorMsg
REVERSE_DETOUR(class CXStr  CSidlManager::GetParsingErrorMsg(void)const ,CSidlManager__GetParsingErrorMsg);
#endif
#ifdef CSidlManager__GetScreenPieceEnum
//REVERSE_DETOUR(enum EStaticScreenPieceClasses  CSidlManager::GetScreenPieceEnum(class CScreenPieceTemplate *)const ,CSidlManager__GetScreenPieceEnum);
#endif
#ifdef CSidlManager__FindAnimation
REVERSE_DETOUR(class CTextureAnimation *  CSidlManager::FindAnimation(unsigned __int32)const ,CSidlManager__FindAnimation);
#endif
#ifdef CSidlManager__FindAnimation1
REVERSE_DETOUR(class CTextureAnimation *  CSidlManager::FindAnimation(class CXStr)const ,CSidlManager__FindAnimation1);
#endif
#ifdef CSidlManager__FindFrameDraw
REVERSE_DETOUR(class CTAFrameDraw *  CSidlManager::FindFrameDraw(unsigned __int32)const ,CSidlManager__FindFrameDraw);
#endif
#ifdef CSidlManager__FindDrawTemplate
REVERSE_DETOUR(class CXWndDrawTemplate *  CSidlManager::FindDrawTemplate(unsigned __int32)const ,CSidlManager__FindDrawTemplate);
#endif
#ifdef CSidlManager__FindDrawTemplate1
REVERSE_DETOUR(class CXWndDrawTemplate *  CSidlManager::FindDrawTemplate(class CXStr)const ,CSidlManager__FindDrawTemplate1);
#endif
#ifdef CSidlManager__FindScreenPieceTemplate
REVERSE_DETOUR(class CScreenPieceTemplate *  CSidlManager::FindScreenPieceTemplate(unsigned __int32)const ,CSidlManager__FindScreenPieceTemplate);
#endif
#ifdef CSidlManager__FindScreenPieceTemplate1
REVERSE_DETOUR(class CScreenPieceTemplate *  CSidlManager::FindScreenPieceTemplate(class CXStr)const ,CSidlManager__FindScreenPieceTemplate1);
#endif
#ifdef CSidlManager__AddAnimationInOrder
REVERSE_DETOUR(void  CSidlManager::AddAnimationInOrder(class CTextureAnimation *),CSidlManager__AddAnimationInOrder);
#endif
#ifdef CSidlManager__AddDrawTemplateInOrder
REVERSE_DETOUR(void  CSidlManager::AddDrawTemplateInOrder(class CXWndDrawTemplate *),CSidlManager__AddDrawTemplateInOrder);
#endif
#ifdef CSidlManager__AddTAFrameDrawInOrder
REVERSE_DETOUR(void  CSidlManager::AddTAFrameDrawInOrder(class CTAFrameDraw *),CSidlManager__AddTAFrameDrawInOrder);
#endif
#ifdef CSidlManager__AddScreenPieceTemplateInOrder
REVERSE_DETOUR(void  CSidlManager::AddScreenPieceTemplateInOrder(class CScreenPieceTemplate *),CSidlManager__AddScreenPieceTemplateInOrder);
#endif
#ifdef CSidlManager__FindTexture
REVERSE_DETOUR(class CUITextureInfo *  CSidlManager::FindTexture(class CXStr)const ,CSidlManager__FindTexture);
#endif
#ifdef CSidlManager__FindTexture1
REVERSE_DETOUR(class CUITextureInfo *  CSidlManager::FindTexture(unsigned __int32)const ,CSidlManager__FindTexture1);
#endif
#ifdef CSidlManager__FindButtonDrawTemplate
REVERSE_DETOUR(class CButtonDrawTemplate *  CSidlManager::FindButtonDrawTemplate(unsigned __int32)const ,CSidlManager__FindButtonDrawTemplate);
#endif
#ifdef CSidlManager__FindSliderDrawTemplate
REVERSE_DETOUR(class CSliderDrawTemplate *  CSidlManager::FindSliderDrawTemplate(class CXStr)const ,CSidlManager__FindSliderDrawTemplate);
#endif
#ifdef CSidlManager__FindSliderDrawTemplate1
REVERSE_DETOUR(class CSliderDrawTemplate *  CSidlManager::FindSliderDrawTemplate(unsigned __int32)const ,CSidlManager__FindSliderDrawTemplate1);
#endif
#ifdef CSidlManager__CreateXWndFromTemplate
REVERSE_DETOUR(class CXWnd *  CSidlManager::CreateXWndFromTemplate(class CXWnd *,class CControlTemplate *),CSidlManager__CreateXWndFromTemplate);
#endif
#ifdef CTAFrameDraw__GetAnimation
REVERSE_DETOUR(class CTextureAnimation *  CTAFrameDraw::GetAnimation(int)const ,CTAFrameDraw__GetAnimation);
#endif
#ifdef CXWnd__SetXMLTooltip
REVERSE_DETOUR(void  CXWnd::SetXMLTooltip(class CXStr),CXWnd__SetXMLTooltip);
#endif
#ifdef CSidlManager__TranslateString
REVERSE_DETOUR(class CXStr __cdecl CSidlManager::TranslateString(class CXStr),CSidlManager__TranslateString);
#endif
#ifdef CXMLEnumInfo__dCXMLEnumInfo
REVERSE_DETOUR( CXMLEnumInfo::~CXMLEnumInfo(void),CXMLEnumInfo__dCXMLEnumInfo);
#endif
#ifdef CXMLDataClass__dCXMLDataClass
REVERSE_DETOUR( CXMLDataClass::~CXMLDataClass(void),CXMLDataClass__dCXMLDataClass);
#endif
#ifdef CTAFrameDraw__CTAFrameDraw1
REVERSE_DETOUR( CTAFrameDraw::CTAFrameDraw(class CXStr),CTAFrameDraw__CTAFrameDraw1);
#endif
#ifdef CTAFrameDraw__Set
REVERSE_DETOUR(void  CTAFrameDraw::Set(class CTextureAnimation * * const),CTAFrameDraw__Set);
#endif
#ifdef CTAFrameDraw__Draw
REVERSE_DETOUR(int  CTAFrameDraw::Draw(class CXRect,class CXRect)const ,CTAFrameDraw__Draw);
#endif
#ifdef CTAFrameDraw__Draw1
REVERSE_DETOUR(int  CTAFrameDraw::Draw(class CXRect,class CXRect,int)const ,CTAFrameDraw__Draw1);
#endif
#ifdef CTAFrameDraw__GetHitTestRect
REVERSE_DETOUR(class CXRect  CTAFrameDraw::GetHitTestRect(class CXRect,int)const ,CTAFrameDraw__GetHitTestRect);
#endif
#ifdef CTAFrameDraw__GetPieceRect
REVERSE_DETOUR(class CXRect  CTAFrameDraw::GetPieceRect(class CXRect,int)const ,CTAFrameDraw__GetPieceRect);
#endif
#ifdef CTAFrameDraw__IsHorizontal
REVERSE_DETOUR(bool  CTAFrameDraw::IsHorizontal(void)const ,CTAFrameDraw__IsHorizontal);
#endif
#ifdef CTAFrameDraw__IsVertical
REVERSE_DETOUR(bool  CTAFrameDraw::IsVertical(void)const ,CTAFrameDraw__IsVertical);
#endif
#ifdef CTAFrameDraw__GetExtent
REVERSE_DETOUR(int  CTAFrameDraw::GetExtent(void)const ,CTAFrameDraw__GetExtent);
#endif
#ifdef CTAFrameDraw__GetMinLength
REVERSE_DETOUR(int  CTAFrameDraw::GetMinLength(void)const ,CTAFrameDraw__GetMinLength);
#endif
#ifdef CTAFrameDraw__GetInnerRect
REVERSE_DETOUR(class CXRect  CTAFrameDraw::GetInnerRect(class CXRect)const ,CTAFrameDraw__GetInnerRect);
#endif
#ifdef CSpellGemWnd__CSpellGemWnd
REVERSE_DETOUR( CSpellGemWnd::CSpellGemWnd(class CXWnd *,unsigned __int32,class CXRect,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,int,int,unsigned long),CSpellGemWnd__CSpellGemWnd);
#endif
#ifdef CSpellGemWnd__Init
REVERSE_DETOUR(void  CSpellGemWnd::Init(void),CSpellGemWnd__Init);
#endif
#ifdef CSpellGemWnd__SetSpellIconIndex
REVERSE_DETOUR(void  CSpellGemWnd::SetSpellIconIndex(int),CSpellGemWnd__SetSpellIconIndex);
#endif
#ifdef CSpellGemWnd__SetSpellGemTint
REVERSE_DETOUR(void  CSpellGemWnd::SetSpellGemTint(unsigned long),CSpellGemWnd__SetSpellGemTint);
#endif
#ifdef CSpellGemWnd__SetGemTintStage
REVERSE_DETOUR(void  CSpellGemWnd::SetGemTintStage(int),CSpellGemWnd__SetGemTintStage);
#endif
#ifdef CSpellGemWnd__SetCheck
REVERSE_DETOUR(void  CSpellGemWnd::SetCheck(bool),CSpellGemWnd__SetCheck);
#endif
#ifdef CSliderWnd__CSliderWnd
REVERSE_DETOUR( CSliderWnd::CSliderWnd(class CXWnd *,unsigned __int32,class CXRect,class CSliderTemplate *),CSliderWnd__CSliderWnd);
#endif
#ifdef CSliderWnd__SetValue
REVERSE_DETOUR(void  CSliderWnd::SetValue(int),CSliderWnd__SetValue);
#endif
#ifdef CSliderWnd__SetNumTicks
REVERSE_DETOUR(void  CSliderWnd::SetNumTicks(int),CSliderWnd__SetNumTicks);
#endif
#ifdef CSliderWnd__UpdateThumb
REVERSE_DETOUR(void  CSliderWnd::UpdateThumb(void),CSliderWnd__UpdateThumb);
#endif
#ifdef CSliderWnd__UpdateMiddleRange
REVERSE_DETOUR(void  CSliderWnd::UpdateMiddleRange(void),CSliderWnd__UpdateMiddleRange);
#endif
#ifdef CSliderWnd__GetValue
REVERSE_DETOUR(int  CSliderWnd::GetValue(void)const,CSliderWnd__GetValue);
#endif
#ifdef CSliderWnd__GetMiddleRangeRect
REVERSE_DETOUR(class CXRect  CSliderWnd::GetMiddleRangeRect(void)const ,CSliderWnd__GetMiddleRangeRect);
#endif
#ifdef CSliderWnd__GetEndCapLeftRect
REVERSE_DETOUR(class CXRect  CSliderWnd::GetEndCapLeftRect(void)const ,CSliderWnd__GetEndCapLeftRect);
#endif
#ifdef CSliderWnd__GetEndCapRightRect
REVERSE_DETOUR(class CXRect  CSliderWnd::GetEndCapRightRect(void)const ,CSliderWnd__GetEndCapRightRect);
#endif
#ifdef CSliderWnd__GetThumbRect
REVERSE_DETOUR(class CXRect  CSliderWnd::GetThumbRect(void)const ,CSliderWnd__GetThumbRect);
#endif
#ifdef CSliderWnd__SetThumbToOffset
REVERSE_DETOUR(void  CSliderWnd::SetThumbToOffset(int),CSliderWnd__SetThumbToOffset);
#endif
#ifdef CSliderWnd__DrawMiddleRange
REVERSE_DETOUR(int  CSliderWnd::DrawMiddleRange(void)const ,CSliderWnd__DrawMiddleRange);
#endif
#ifdef CSliderWnd__DrawEndCapLeft
REVERSE_DETOUR(int  CSliderWnd::DrawEndCapLeft(void)const ,CSliderWnd__DrawEndCapLeft);
#endif
#ifdef CSliderWnd__DrawEndCapRight
REVERSE_DETOUR(int  CSliderWnd::DrawEndCapRight(void)const ,CSliderWnd__DrawEndCapRight);
#endif
#ifdef CSliderWnd__DrawThumb
REVERSE_DETOUR(int  CSliderWnd::DrawThumb(void)const ,CSliderWnd__DrawThumb);
#endif
#ifdef CXWnd__DrawRaisedRect
REVERSE_DETOUR(int __cdecl CXWnd::DrawRaisedRect(class CXRect,class CXRect),CXWnd__DrawRaisedRect);
#endif
#ifdef CXWnd__DrawSunkenRect
REVERSE_DETOUR(int __cdecl CXWnd::DrawSunkenRect(class CXRect,class CXRect),CXWnd__DrawSunkenRect);
#endif
#ifdef CEditBaseWnd__SetSel
REVERSE_DETOUR(void  CEditBaseWnd::SetSel(int,int),CEditBaseWnd__SetSel);
#endif
#ifdef CInvSlotWnd__CInvSlotWnd
REVERSE_DETOUR( CInvSlotWnd::CInvSlotWnd(class CXWnd *,unsigned __int32,class CXRect,class CTextureAnimation *,int,int,int),CInvSlotWnd__CInvSlotWnd);
#endif
#ifdef CInvSlotWnd__SetInvSlot
REVERSE_DETOUR(void  CInvSlotWnd::SetInvSlot(class CInvSlot *),CInvSlotWnd__SetInvSlot);
#endif
#ifdef CLabel__CLabel
REVERSE_DETOUR( CLabel::CLabel(class CXWnd *,unsigned __int32,class CXRect,int),CLabel__CLabel);
#endif
#ifdef CLabel__SetNoWrap
REVERSE_DETOUR(void  CLabel::SetNoWrap(bool),CLabel__SetNoWrap);
#endif
#ifdef CLabel__SetAlignRight
REVERSE_DETOUR(void  CLabel::SetAlignRight(bool),CLabel__SetAlignRight);
#endif
#ifdef CLabel__SetAlignCenter
REVERSE_DETOUR(void  CLabel::SetAlignCenter(bool),CLabel__SetAlignCenter);
#endif
#ifdef CIMEManager__CIMEManager
REVERSE_DETOUR( CIMEManager::CIMEManager(struct HWND__ *),CIMEManager__CIMEManager);
#endif
#ifdef CIMEManager__dCIMEManager
REVERSE_DETOUR( CIMEManager::~CIMEManager(void),CIMEManager__dCIMEManager);
#endif
#ifdef CIMEManager__handleWndProc
REVERSE_DETOUR(int  CIMEManager::handleWndProc(unsigned int,unsigned int,long),CIMEManager__handleWndProc);
#endif
#ifdef CIMEManager__handleAddChar
REVERSE_DETOUR(int  CIMEManager::handleAddChar(unsigned short),CIMEManager__handleAddChar);
#endif
#ifdef CIMEManager__handleInputComposition
REVERSE_DETOUR(int  CIMEManager::handleInputComposition(long),CIMEManager__handleInputComposition);
#endif
#ifdef CIMEManager__handleEndComposition
REVERSE_DETOUR(int  CIMEManager::handleEndComposition(void),CIMEManager__handleEndComposition);
#endif
#ifdef CIMEManager__handleStartComposition
REVERSE_DETOUR(int  CIMEManager::handleStartComposition(void),CIMEManager__handleStartComposition);
#endif
#ifdef CIMEManager__handleOpenCandidates
REVERSE_DETOUR(int  CIMEManager::handleOpenCandidates(void),CIMEManager__handleOpenCandidates);
#endif
#ifdef CIMEManager__handleChangeCandidates
REVERSE_DETOUR(int  CIMEManager::handleChangeCandidates(void),CIMEManager__handleChangeCandidates);
#endif
#ifdef CIMEManager__handleCloseCandidates
REVERSE_DETOUR(int  CIMEManager::handleCloseCandidates(void),CIMEManager__handleCloseCandidates);
#endif
#ifdef CIMEManager__handleImeStatusChanged
REVERSE_DETOUR(int  CIMEManager::handleImeStatusChanged(void),CIMEManager__handleImeStatusChanged);
#endif
#ifdef CIMEManager__handleImeChanged
REVERSE_DETOUR(int  CIMEManager::handleImeChanged(void),CIMEManager__handleImeChanged);
#endif
#ifdef CIMEManager__setInputEditWnd
REVERSE_DETOUR(int  CIMEManager::setInputEditWnd(class CEditWnd *),CIMEManager__setInputEditWnd);
#endif
#ifdef CIMEManager__turnImeOn
REVERSE_DETOUR(void  CIMEManager::turnImeOn(void),CIMEManager__turnImeOn);
#endif
#ifdef CIMEManager__turnImeOff
REVERSE_DETOUR(void  CIMEManager::turnImeOff(void),CIMEManager__turnImeOff);
#endif
#ifdef CIMEManager__imeIsOn
REVERSE_DETOUR(bool  CIMEManager::imeIsOn(void)const ,CIMEManager__imeIsOn);
#endif
#ifdef CIMEManager__imeIsOff
REVERSE_DETOUR(bool  CIMEManager::imeIsOff(void)const ,CIMEManager__imeIsOff);
#endif
#ifdef CIMEManager__enableIme
REVERSE_DETOUR(void  CIMEManager::enableIme(bool),CIMEManager__enableIme);
#endif
#ifdef CIMEManager__queryImeLanguage
REVERSE_DETOUR(int  CIMEManager::queryImeLanguage(void)const ,CIMEManager__queryImeLanguage);
#endif
#ifdef CIMEManager__queryImeProperties
REVERSE_DETOUR(int  CIMEManager::queryImeProperties(void)const ,CIMEManager__queryImeProperties);
#endif
#ifdef CIMEManager__setInputState
REVERSE_DETOUR(void  CIMEManager::setInputState(int),CIMEManager__setInputState);
#endif
#ifdef CIMEManager__getInputState
REVERSE_DETOUR(int  CIMEManager::getInputState(void)const ,CIMEManager__getInputState);
#endif
#ifdef CIMEManager__getInputLanguage
REVERSE_DETOUR(int  CIMEManager::getInputLanguage(void)const ,CIMEManager__getInputLanguage);
#endif
#ifdef CIMEManager__getImeProperties
REVERSE_DETOUR(int  CIMEManager::getImeProperties(void)const ,CIMEManager__getImeProperties);
#endif
#ifdef CIMEManager__getWindowHandle
REVERSE_DETOUR(struct HWND__ *  CIMEManager::getWindowHandle(void)const ,CIMEManager__getWindowHandle);
#endif
#ifdef CUITextureInfo__Draw
REVERSE_DETOUR(int  CUITextureInfo::Draw(class CXRect,class CXRect,class CXRect,unsigned long,unsigned long)const ,CUITextureInfo__Draw);
#endif
#ifdef CUITextureInfo__Draw1
REVERSE_DETOUR(int  CUITextureInfo::Draw(class CXRect,class CXRect,class CXRect,unsigned long *,unsigned long *)const ,CUITextureInfo__Draw1);
#endif
#ifdef CUITexturePiece__Draw
REVERSE_DETOUR(int  CUITexturePiece::Draw(class CXRect,class CXRect,unsigned long,unsigned long)const ,CUITexturePiece__Draw);
#endif
#ifdef CUITexturePiece__Draw1
REVERSE_DETOUR(int  CUITexturePiece::Draw(class CXRect,class CXRect,class CXRect,unsigned long,unsigned long)const ,CUITexturePiece__Draw1);
#endif
#ifdef CUITextureInfo__Tile
REVERSE_DETOUR(int  CUITextureInfo::Tile(class CXRect,unsigned long,unsigned long)const ,CUITextureInfo__Tile);
#endif
#ifdef CUITextureInfo__Tile1
REVERSE_DETOUR(int  CUITextureInfo::Tile(class CXRect,unsigned long *,unsigned long *)const ,CUITextureInfo__Tile1);
#endif
#ifdef CUITextureInfo__Preload
REVERSE_DETOUR(int  CUITextureInfo::Preload(void),CUITextureInfo__Preload);
#endif
#ifdef CXMLDataPtr__SetNewPtr
REVERSE_DETOUR(void  CXMLDataPtr::SetNewPtr(class CXMLData *),CXMLDataPtr__SetNewPtr);
#endif
#ifdef CXMLEnumInfo__GetStreamSize
REVERSE_DETOUR(int  CXMLEnumInfo::GetStreamSize(void),CXMLEnumInfo__GetStreamSize);
#endif
#ifdef CXMLEnumInfo__ReadFromStream
REVERSE_DETOUR(void  CXMLEnumInfo::ReadFromStream(class CMemoryStream &),CXMLEnumInfo__ReadFromStream);
#endif
#ifdef CMemoryStream__GetString
REVERSE_DETOUR(void  CMemoryStream::GetString(class CXStr &),CMemoryStream__GetString);
#endif
#ifdef CXMLEnumInfo__WriteToStream
REVERSE_DETOUR(void  CXMLEnumInfo::WriteToStream(class CMemoryStream &),CXMLEnumInfo__WriteToStream);
#endif
#ifdef CXMLDataClass__GetNumLeaf
REVERSE_DETOUR(int  CXMLDataClass::GetNumLeaf(void),CXMLDataClass__GetNumLeaf);
#endif
#ifdef CXMLDataClass__GetStreamSize
REVERSE_DETOUR(int  CXMLDataClass::GetStreamSize(void),CXMLDataClass__GetStreamSize);
#endif
#ifdef CXMLDataClass__ReadFromStream
REVERSE_DETOUR(void  CXMLDataClass::ReadFromStream(class CMemoryStream &,class CXMLDataManager &),CXMLDataClass__ReadFromStream);
#endif
#ifdef CXMLDataClass__WriteToStream
REVERSE_DETOUR(void  CXMLDataClass::WriteToStream(class CMemoryStream &),CXMLDataClass__WriteToStream);
#endif
#ifdef CXMLDataManager__CXMLDataManager
REVERSE_DETOUR( CXMLDataManager::CXMLDataManager(void),CXMLDataManager__CXMLDataManager);
#endif
#ifdef CXMLDataManager__GetXMLData
REVERSE_DETOUR(class CXMLData *  CXMLDataManager::GetXMLData(int,int),CXMLDataManager__GetXMLData);
#endif
#ifdef CXMLDataManager__GetXMLData1
REVERSE_DETOUR(class CXMLData *  CXMLDataManager::GetXMLData(class CXStr,class CXStr),CXMLDataManager__GetXMLData1);
#endif
#ifdef CXMLDataManager__GetNumClass
REVERSE_DETOUR(int  CXMLDataManager::GetNumClass(void),CXMLDataManager__GetNumClass);
#endif
#ifdef CXMLDataManager__GetNumItem
REVERSE_DETOUR(int  CXMLDataManager::GetNumItem(int),CXMLDataManager__GetNumItem);
#endif
#ifdef CXMLDataManager__GetClassIdx
REVERSE_DETOUR(int  CXMLDataManager::GetClassIdx(class CXStr),CXMLDataManager__GetClassIdx);
#endif
#ifdef CXMLDataManager__GetItemIdx
REVERSE_DETOUR(int  CXMLDataManager::GetItemIdx(int,class CXStr),CXMLDataManager__GetItemIdx);
#endif
#ifdef CXMLDataPtr__Free
REVERSE_DETOUR(void  CXMLDataPtr::Free(void),CXMLDataPtr__Free);
#endif
#ifdef CXMLDataManager__AddToSuperType
//REVERSE_DETOUR(void  CXMLDataManager::AddToSuperType(class CXStr,class CXMLDataPtr),CXMLDataManager__AddToSuperType);
#endif
#ifdef CXMLDataPtr__operator_equal
REVERSE_DETOUR(class CXMLDataPtr &  CXMLDataPtr::operator=(class CXMLDataPtr const &),CXMLDataPtr__operator_equal);
#endif
#ifdef CXMLDataManager__IsDerivedFrom
REVERSE_DETOUR(bool  CXMLDataManager::IsDerivedFrom(int,int),CXMLDataManager__IsDerivedFrom);
#endif
#ifdef CXMLDataManager__SetEnumHash
REVERSE_DETOUR(void  CXMLDataManager::SetEnumHash(void),CXMLDataManager__SetEnumHash);
#endif
#ifdef CXMLDataManager__ReadFromXMLSOM
REVERSE_DETOUR(bool  CXMLDataManager::ReadFromXMLSOM(class CXMLSOMDocument &),CXMLDataManager__ReadFromXMLSOM);
#endif
#ifdef CXMLDataPtr__CXMLDataPtr
REVERSE_DETOUR( CXMLDataPtr::CXMLDataPtr(void),CXMLDataPtr__CXMLDataPtr);
#endif
#ifdef CXMLDataClass__CXMLDataClass
REVERSE_DETOUR( CXMLDataClass::CXMLDataClass(void),CXMLDataClass__CXMLDataClass);
#endif
#ifdef CXMLEnumInfo__CXMLEnumInfo
REVERSE_DETOUR( CXMLEnumInfo::CXMLEnumInfo(void),CXMLEnumInfo__CXMLEnumInfo);
#endif
#ifdef CStmlReport__CreateReport
REVERSE_DETOUR(class CStmlReport * __cdecl CStmlReport::CreateReport(class CXStr),CStmlReport__CreateReport);
#endif
#ifdef CXFileXML__Load
REVERSE_DETOUR(bool  CXFileXML::Load(char *),CXFileXML__Load);
#endif
#ifdef CParseTokXML__GetEntityRef
REVERSE_DETOUR(bool  CParseTokXML::GetEntityRef(char &),CParseTokXML__GetEntityRef);
#endif
#ifdef CParseTokXML__NextToken
//REVERSE_DETOUR(enum ETokTypeXML  CParseTokXML::NextToken(void),CParseTokXML__NextToken);
#endif
#ifdef CParseTokensXML__SetError
REVERSE_DETOUR(void __cdecl CParseTokensXML::SetError(char const *,...),CParseTokensXML__SetError);
#endif
#ifdef CParseTokensXML__GetCurFile
REVERSE_DETOUR(class CXStr  CParseTokensXML::GetCurFile(void),CParseTokensXML__GetCurFile);
#endif
#ifdef CParseTokensXML__Accept
//REVERSE_DETOUR(bool  CParseTokensXML::Accept(enum ETokTypeXML),CParseTokensXML__Accept);
#endif
#ifdef CXMLSOMParser__ParseProcess
REVERSE_DETOUR(bool  CXMLSOMParser::ParseProcess(void),CXMLSOMParser__ParseProcess);
#endif
#ifdef CXMLSOMParser__ParseNameSpaceToken
REVERSE_DETOUR(bool  CXMLSOMParser::ParseNameSpaceToken(class CXStr &),CXMLSOMParser__ParseNameSpaceToken);
#endif
#ifdef CXMLSOMParser__ParseStartTag
REVERSE_DETOUR(bool  CXMLSOMParser::ParseStartTag(bool &),CXMLSOMParser__ParseStartTag);
#endif
#ifdef CXMLSOMParser__ParseEndTag
REVERSE_DETOUR(bool  CXMLSOMParser::ParseEndTag(class CXStr),CXMLSOMParser__ParseEndTag);
#endif
#ifdef CXMLSOMParser__ParseNodeList
REVERSE_DETOUR(bool  CXMLSOMParser::ParseNodeList(void),CXMLSOMParser__ParseNodeList);
#endif
#ifdef CXMLSOMParser__ParseNode
REVERSE_DETOUR(bool  CXMLSOMParser::ParseNode(void),CXMLSOMParser__ParseNode);
#endif
#ifdef CXMLSOMParser__ParseDocument
REVERSE_DETOUR(bool  CXMLSOMParser::ParseDocument(void),CXMLSOMParser__ParseDocument);
#endif
#ifdef CParseTokensXML__StartFileBased
REVERSE_DETOUR(bool  CParseTokensXML::StartFileBased(class CXStr),CParseTokensXML__StartFileBased);
#endif
#ifdef CXFileXML__dCXFileXML
REVERSE_DETOUR( CXFileXML::~CXFileXML(void),CXFileXML__dCXFileXML);
#endif
#ifdef CTokenXML__dCTokenXML
REVERSE_DETOUR( CTokenXML::~CTokenXML(void),CTokenXML__dCTokenXML);
#endif
#ifdef CXMLSOMParser__ParseFile
REVERSE_DETOUR(bool  CXMLSOMParser::ParseFile(class CXStr),CXMLSOMParser__ParseFile);
#endif
#ifdef CParseTokensXML__dCParseTokensXML
REVERSE_DETOUR( CParseTokensXML::~CParseTokensXML(void),CParseTokensXML__dCParseTokensXML);
#endif
#ifdef CXMLSOMParser__dCXMLSOMParser
REVERSE_DETOUR( CXMLSOMParser::~CXMLSOMParser(void),CXMLSOMParser__dCXMLSOMParser);
#endif
#ifdef CParseTokXML__dCParseTokXML
REVERSE_DETOUR( CParseTokXML::~CParseTokXML(void),CParseTokXML__dCParseTokXML);
#endif
#ifdef CClickStickInfo__CClickStickInfo
REVERSE_DETOUR( CClickStickInfo::CClickStickInfo(void),CClickStickInfo__CClickStickInfo);
#endif
#ifdef CDIMap__CDIMap
REVERSE_DETOUR( CDIMap::CDIMap(void),CDIMap__CDIMap);
#endif
#ifdef CXStr__CheckNoLock
REVERSE_DETOUR(void  CXStr::CheckNoLock(void),CXStr__CheckNoLock);
#endif
#ifdef CDIMap__dCDIMap
REVERSE_DETOUR( CDIMap::~CDIMap(void),CDIMap__dCDIMap);
#endif
#ifdef CIMECandidateList__dCIMECandidateList
REVERSE_DETOUR( CIMECandidateList::~CIMECandidateList(void),CIMECandidateList__dCIMECandidateList);
#endif
#ifdef CDIMap__LoadMappingFromFile
REVERSE_DETOUR(void  CDIMap::LoadMappingFromFile(char *),CDIMap__LoadMappingFromFile);
#endif
#ifdef CHashCXStrInt32__CHashCXStrInt32
REVERSE_DETOUR( CHashCXStrInt32::CHashCXStrInt32(void),CHashCXStrInt32__CHashCXStrInt32);
#endif
#ifdef CHashCXStrInt32__dCHashCXStrInt32
REVERSE_DETOUR( CHashCXStrInt32::~CHashCXStrInt32(void),CHashCXStrInt32__dCHashCXStrInt32);
#endif
#ifdef CHashCXStrInt32__KeyToBin
REVERSE_DETOUR(int  CHashCXStrInt32::KeyToBin(class CXStr const &)const ,CHashCXStrInt32__KeyToBin);
#endif
#ifdef CHashCXStrInt32__LookUp
REVERSE_DETOUR(bool  CHashCXStrInt32::LookUp(class CXStr const &,int &)const ,CHashCXStrInt32__LookUp);
#endif
#ifdef CHashCXStrInt32__Insert
REVERSE_DETOUR(bool  CHashCXStrInt32::Insert(class CXStr const &,int),CHashCXStrInt32__Insert);
#endif
#ifdef CHashCXStrInt32__Reset
REVERSE_DETOUR(void  CHashCXStrInt32::Reset(void),CHashCXStrInt32__Reset);
#endif
#ifdef CParamPoint__operator_equal
REVERSE_DETOUR(class CParamPoint &  CParamPoint::operator=(class CParamPoint const &),CParamPoint__operator_equal);
#endif
#ifdef CParamSize__operator_equal
REVERSE_DETOUR(class CParamSize &  CParamSize::operator=(class CParamSize const &),CParamSize__operator_equal);
#endif
#ifdef CParamGaugeDrawTemplate__operator_equal
REVERSE_DETOUR(class CParamGaugeDrawTemplate &  CParamGaugeDrawTemplate::operator=(class CParamGaugeDrawTemplate const &),CParamGaugeDrawTemplate__operator_equal);
#endif
#ifdef CParamSpellGemDrawTemplate__operator_equal
REVERSE_DETOUR(class CParamSpellGemDrawTemplate &  CParamSpellGemDrawTemplate::operator=(class CParamSpellGemDrawTemplate const &),CParamSpellGemDrawTemplate__operator_equal);
#endif
#ifdef CParamScreenPiece__operator_equal
REVERSE_DETOUR(class CParamScreenPiece &  CParamScreenPiece::operator=(class CParamScreenPiece const &),CParamScreenPiece__operator_equal);
#endif
#ifdef CParamControl__operator_equal
REVERSE_DETOUR(class CParamControl &  CParamControl::operator=(class CParamControl const &),CParamControl__operator_equal);
#endif
#ifdef CParamSliderDrawTemplate__operator_equal
REVERSE_DETOUR(class CParamSliderDrawTemplate &  CParamSliderDrawTemplate::operator=(class CParamSliderDrawTemplate const &),CParamSliderDrawTemplate__operator_equal);
#endif
#ifdef CParamStaticText__operator_equal
REVERSE_DETOUR(class CParamStaticText &  CParamStaticText::operator=(class CParamStaticText const &),CParamStaticText__operator_equal);
#endif
#ifdef CParamStaticAnimation__operator_equal
REVERSE_DETOUR(class CParamStaticAnimation &  CParamStaticAnimation::operator=(class CParamStaticAnimation const &),CParamStaticAnimation__operator_equal);
#endif
#ifdef CParamStaticFrame__operator_equal
REVERSE_DETOUR(class CParamStaticFrame &  CParamStaticFrame::operator=(class CParamStaticFrame const &),CParamStaticFrame__operator_equal);
#endif
#ifdef CParamStaticHeader__operator_equal
REVERSE_DETOUR(class CParamStaticHeader &  CParamStaticHeader::operator=(class CParamStaticHeader const &),CParamStaticHeader__operator_equal);
#endif
#ifdef CParamListboxColumn__operator_equal
REVERSE_DETOUR(class CParamListboxColumn &  CParamListboxColumn::operator=(class CParamListboxColumn const &),CParamListboxColumn__operator_equal);
#endif
#ifdef CParamListbox__operator_equal
REVERSE_DETOUR(class CParamListbox &  CParamListbox::operator=(class CParamListbox const &),CParamListbox__operator_equal);
#endif
#ifdef CParamButton__operator_equal
REVERSE_DETOUR(class CParamButton &  CParamButton::operator=(class CParamButton const &),CParamButton__operator_equal);
#endif
#ifdef CParamGauge__operator_equal
REVERSE_DETOUR(class CParamGauge &  CParamGauge::operator=(class CParamGauge const &),CParamGauge__operator_equal);
#endif
#ifdef CParamSpellGem__operator_equal
REVERSE_DETOUR(class CParamSpellGem &  CParamSpellGem::operator=(class CParamSpellGem const &),CParamSpellGem__operator_equal);
#endif
#ifdef CParamInvSlot__operator_equal
REVERSE_DETOUR(class CParamInvSlot &  CParamInvSlot::operator=(class CParamInvSlot const &),CParamInvSlot__operator_equal);
#endif
#ifdef CParamEditbox__operator_equal
REVERSE_DETOUR(class CParamEditbox &  CParamEditbox::operator=(class CParamEditbox const &),CParamEditbox__operator_equal);
#endif
#ifdef CParamSlider__operator_equal
REVERSE_DETOUR(class CParamSlider &  CParamSlider::operator=(class CParamSlider const &),CParamSlider__operator_equal);
#endif
#ifdef CParamLabel__operator_equal
REVERSE_DETOUR(class CParamLabel &  CParamLabel::operator=(class CParamLabel const &),CParamLabel__operator_equal);
#endif
#ifdef CParamCombobox__operator_equal
REVERSE_DETOUR(class CParamCombobox &  CParamCombobox::operator=(class CParamCombobox const &),CParamCombobox__operator_equal);
#endif
#ifdef CParamPage__operator_equal
REVERSE_DETOUR(class CParamPage &  CParamPage::operator=(class CParamPage const &),CParamPage__operator_equal);
#endif
#ifdef CParamTabBox__operator_equal
REVERSE_DETOUR(class CParamTabBox &  CParamTabBox::operator=(class CParamTabBox const &),CParamTabBox__operator_equal);
#endif
#ifdef CParamScreen__operator_equal
REVERSE_DETOUR(class CParamScreen &  CParamScreen::operator=(class CParamScreen const &),CParamScreen__operator_equal);
#endif
#ifdef CParamSuiteDefaults__operator_equal
REVERSE_DETOUR(class CParamSuiteDefaults &  CParamSuiteDefaults::operator=(class CParamSuiteDefaults const &),CParamSuiteDefaults__operator_equal);
#endif
#ifdef CParamClass__CParamClass
REVERSE_DETOUR( CParamClass::CParamClass(void),CParamClass__CParamClass);
#endif
#ifdef CParamRGB__CParamRGB
REVERSE_DETOUR( CParamRGB::CParamRGB(void),CParamRGB__CParamRGB);
#endif
#ifdef CParamPoint__CParamPoint
REVERSE_DETOUR( CParamPoint::CParamPoint(void),CParamPoint__CParamPoint);
#endif
#ifdef CParamSize__CParamSize
REVERSE_DETOUR( CParamSize::CParamSize(void),CParamSize__CParamSize);
#endif
#ifdef CParamTextureInfo__CParamTextureInfo
REVERSE_DETOUR( CParamTextureInfo::CParamTextureInfo(void),CParamTextureInfo__CParamTextureInfo);
#endif
#ifdef CXMLSOMCursorSaveFast__dCXMLSOMCursorSaveFast
REVERSE_DETOUR( CXMLSOMCursorSaveFast::~CXMLSOMCursorSaveFast(void),CXMLSOMCursorSaveFast__dCXMLSOMCursorSaveFast);
#endif
#ifdef CParamFrame__CParamFrame
REVERSE_DETOUR( CParamFrame::CParamFrame(void),CParamFrame__CParamFrame);
#endif
#ifdef CParamUi2DAnimation__CParamUi2DAnimation
REVERSE_DETOUR( CParamUi2DAnimation::CParamUi2DAnimation(void),CParamUi2DAnimation__CParamUi2DAnimation);
#endif
#ifdef CParamButtonDrawTemplate__CParamButtonDrawTemplate
REVERSE_DETOUR( CParamButtonDrawTemplate::CParamButtonDrawTemplate(void),CParamButtonDrawTemplate__CParamButtonDrawTemplate);
#endif
#ifdef CParamGaugeDrawTemplate__CParamGaugeDrawTemplate
REVERSE_DETOUR( CParamGaugeDrawTemplate::CParamGaugeDrawTemplate(void),CParamGaugeDrawTemplate__CParamGaugeDrawTemplate);
#endif
#ifdef CParamSpellGemDrawTemplate__CParamSpellGemDrawTemplate
REVERSE_DETOUR( CParamSpellGemDrawTemplate::CParamSpellGemDrawTemplate(void),CParamSpellGemDrawTemplate__CParamSpellGemDrawTemplate);
#endif
#ifdef CParamFrameTemplate__CParamFrameTemplate
REVERSE_DETOUR( CParamFrameTemplate::CParamFrameTemplate(void),CParamFrameTemplate__CParamFrameTemplate);
#endif
#ifdef CParamScrollbarDrawTemplate__CParamScrollbarDrawTemplate
REVERSE_DETOUR( CParamScrollbarDrawTemplate::CParamScrollbarDrawTemplate(void),CParamScrollbarDrawTemplate__CParamScrollbarDrawTemplate);
#endif
#ifdef CParamWindowDrawTemplate__CParamWindowDrawTemplate
REVERSE_DETOUR( CParamWindowDrawTemplate::CParamWindowDrawTemplate(void),CParamWindowDrawTemplate__CParamWindowDrawTemplate);
#endif
#ifdef CParamSliderDrawTemplate__CParamSliderDrawTemplate
REVERSE_DETOUR( CParamSliderDrawTemplate::CParamSliderDrawTemplate(void),CParamSliderDrawTemplate__CParamSliderDrawTemplate);
#endif
#ifdef CParamScreenPiece__CParamScreenPiece
REVERSE_DETOUR( CParamScreenPiece::CParamScreenPiece(void),CParamScreenPiece__CParamScreenPiece);
#endif
#ifdef CParamStaticScreenPiece__CParamStaticScreenPiece
REVERSE_DETOUR( CParamStaticScreenPiece::CParamStaticScreenPiece(void),CParamStaticScreenPiece__CParamStaticScreenPiece);
#endif
#ifdef CParamStaticAnimation__CParamStaticAnimation
REVERSE_DETOUR( CParamStaticAnimation::CParamStaticAnimation(void),CParamStaticAnimation__CParamStaticAnimation);
#endif
#ifdef CParamStaticText__CParamStaticText
REVERSE_DETOUR( CParamStaticText::CParamStaticText(void),CParamStaticText__CParamStaticText);
#endif
#ifdef CParamStaticFrame__CParamStaticFrame
REVERSE_DETOUR( CParamStaticFrame::CParamStaticFrame(void),CParamStaticFrame__CParamStaticFrame);
#endif
#ifdef CParamStaticHeader__CParamStaticHeader
REVERSE_DETOUR( CParamStaticHeader::CParamStaticHeader(void),CParamStaticHeader__CParamStaticHeader);
#endif
#ifdef CParamControl__CParamControl
REVERSE_DETOUR( CParamControl::CParamControl(void),CParamControl__CParamControl);
#endif
#ifdef CParamListboxColumn__CParamListboxColumn
REVERSE_DETOUR( CParamListboxColumn::CParamListboxColumn(void),CParamListboxColumn__CParamListboxColumn);
#endif
#ifdef CParamListbox__CParamListbox
REVERSE_DETOUR( CParamListbox::CParamListbox(void),CParamListbox__CParamListbox);
#endif
#ifdef CParamButton__CParamButton
REVERSE_DETOUR( CParamButton::CParamButton(void),CParamButton__CParamButton);
#endif
#ifdef CParamGauge__CParamGauge
REVERSE_DETOUR( CParamGauge::CParamGauge(void),CParamGauge__CParamGauge);
#endif
#ifdef CParamSpellGem__CParamSpellGem
REVERSE_DETOUR( CParamSpellGem::CParamSpellGem(void),CParamSpellGem__CParamSpellGem);
#endif
#ifdef CParamInvSlot__CParamInvSlot
REVERSE_DETOUR( CParamInvSlot::CParamInvSlot(void),CParamInvSlot__CParamInvSlot);
#endif
#ifdef CParamEditbox__CParamEditbox
REVERSE_DETOUR( CParamEditbox::CParamEditbox(void),CParamEditbox__CParamEditbox);
#endif
#ifdef CParamSlider__CParamSlider
REVERSE_DETOUR( CParamSlider::CParamSlider(void),CParamSlider__CParamSlider);
#endif
#ifdef CParamLabel__CParamLabel
REVERSE_DETOUR( CParamLabel::CParamLabel(void),CParamLabel__CParamLabel);
#endif
#ifdef CParamSTMLbox__CParamSTMLbox
REVERSE_DETOUR( CParamSTMLbox::CParamSTMLbox(void),CParamSTMLbox__CParamSTMLbox);
#endif
#ifdef CParamCombobox__CParamCombobox
REVERSE_DETOUR( CParamCombobox::CParamCombobox(void),CParamCombobox__CParamCombobox);
#endif
#ifdef CParamPage__CParamPage
REVERSE_DETOUR( CParamPage::CParamPage(void),CParamPage__CParamPage);
#endif
#ifdef CParamTabBox__CParamTabBox
REVERSE_DETOUR( CParamTabBox::CParamTabBox(void),CParamTabBox__CParamTabBox);
#endif
#ifdef CParamScreen__CParamScreen
REVERSE_DETOUR( CParamScreen::CParamScreen(void),CParamScreen__CParamScreen);
#endif
#ifdef CParamSuiteDefaults__CParamSuiteDefaults
REVERSE_DETOUR( CParamSuiteDefaults::CParamSuiteDefaults(void),CParamSuiteDefaults__CParamSuiteDefaults);
#endif
#ifdef CXMLData__CXMLData
REVERSE_DETOUR( CXMLData::CXMLData(void),CXMLData__CXMLData);
#endif
#ifdef CPageWnd__CPageWnd
REVERSE_DETOUR( CPageWnd::CPageWnd(class CXWnd *,unsigned __int32,class CXRect,class CXStr,class CPageTemplate *),CPageWnd__CPageWnd);
#endif
#ifdef CGaugeWnd__CGaugeWnd
REVERSE_DETOUR( CGaugeWnd::CGaugeWnd(class CXWnd *,unsigned __int32,class CXRect,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,int,unsigned long,unsigned long,bool,int,int,int,int),CGaugeWnd__CGaugeWnd);
#endif
#ifdef CGaugeWnd__CalcFillRect
REVERSE_DETOUR(class CXRect  CGaugeWnd::CalcFillRect(class CXRect *,int)const ,CGaugeWnd__CalcFillRect);
#endif
#ifdef CGaugeWnd__CalcLinesFillRect
REVERSE_DETOUR(class CXRect  CGaugeWnd::CalcLinesFillRect(class CXRect *,int)const ,CGaugeWnd__CalcLinesFillRect);
#endif
#ifdef CGaugeWnd__SpecialToolTip
REVERSE_DETOUR(void  CGaugeWnd::SpecialToolTip(void),CGaugeWnd__SpecialToolTip);
#endif
#ifdef CCheckBoxWnd__CCheckBoxWnd
REVERSE_DETOUR( CCheckBoxWnd::CCheckBoxWnd(class CXWnd *,unsigned __int32,class CXRect,class CXPoint,class CXSize,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *,class CTextureAnimation *),CCheckBoxWnd__CCheckBoxWnd);
#endif
#ifdef CCheckBoxWnd__SetRadioLook
REVERSE_DETOUR(void  CCheckBoxWnd::SetRadioLook(void),CCheckBoxWnd__SetRadioLook);
#endif
#ifdef CIMEStatusBar__CIMEStatusBar
REVERSE_DETOUR( CIMEStatusBar::CIMEStatusBar(class CIMEManager *),CIMEStatusBar__CIMEStatusBar);
#endif
#ifdef CIMEStatusBar__show
REVERSE_DETOUR(int  CIMEStatusBar::show(class CIMEComposition const *),CIMEStatusBar__show);
#endif
#ifdef CIMEStatusBar__update
REVERSE_DETOUR(int  CIMEStatusBar::update(void),CIMEStatusBar__update);
#endif
#ifdef CIMEStatusBar__hide
REVERSE_DETOUR(int  CIMEStatusBar::hide(void),CIMEStatusBar__hide);
#endif
#ifdef CIMEStatusBar__handleChineseSimplifiedStatusChange
REVERSE_DETOUR(void  CIMEStatusBar::handleChineseSimplifiedStatusChange(unsigned long),CIMEStatusBar__handleChineseSimplifiedStatusChange);
#endif
#ifdef CIMEStatusBar__handleChineseTraditionalStatusChange
REVERSE_DETOUR(void  CIMEStatusBar::handleChineseTraditionalStatusChange(unsigned long),CIMEStatusBar__handleChineseTraditionalStatusChange);
#endif
#ifdef CIMEStatusBar__handleJapaneseStatusChange
REVERSE_DETOUR(void  CIMEStatusBar::handleJapaneseStatusChange(unsigned long),CIMEStatusBar__handleJapaneseStatusChange);
#endif
#ifdef CIMEStatusBar__handleKoreanStatusChange
REVERSE_DETOUR(void  CIMEStatusBar::handleKoreanStatusChange(unsigned long),CIMEStatusBar__handleKoreanStatusChange);
#endif
#ifdef CIMEStatusBar__repositionStatusWindow
REVERSE_DETOUR(int  CIMEStatusBar::repositionStatusWindow(void),CIMEStatusBar__repositionStatusWindow);
#endif
#ifdef CIMECandidateList__CIMECandidateList
REVERSE_DETOUR( CIMECandidateList::CIMECandidateList(class CIMEManager *),CIMECandidateList__CIMECandidateList);
#endif
#ifdef CIMECandidateList__show
REVERSE_DETOUR(int  CIMECandidateList::show(class CIMEComposition const *)const ,CIMECandidateList__show);
#endif
#ifdef CIMECandidateList__repositionImeCandidateList
REVERSE_DETOUR(int  CIMECandidateList::repositionImeCandidateList(int,int)const ,CIMECandidateList__repositionImeCandidateList);
#endif
#ifdef CIMEComposition__CIMEComposition
REVERSE_DETOUR( CIMEComposition::CIMEComposition(class CIMEManager *),CIMEComposition__CIMEComposition);
#endif
#ifdef CIMEComposition__dCIMEComposition
REVERSE_DETOUR( CIMEComposition::~CIMEComposition(void),CIMEComposition__dCIMEComposition);
#endif
#ifdef CIMEComposition__addInputChar
REVERSE_DETOUR(int  CIMEComposition::addInputChar(unsigned short),CIMEComposition__addInputChar);
#endif
#ifdef CIMEComposition__addInputString
REVERSE_DETOUR(int  CIMEComposition::addInputString(unsigned short *,int),CIMEComposition__addInputString);
#endif
#ifdef CIMEComposition__addInputString1
REVERSE_DETOUR(int  CIMEComposition::addInputString(class CXStr const &,int),CIMEComposition__addInputString1);
#endif
#ifdef CIMEComposition__addStringFromIme
REVERSE_DETOUR(int  CIMEComposition::addStringFromIme(long),CIMEComposition__addStringFromIme);
#endif
#ifdef CIMEComposition__directToEditWnd
REVERSE_DETOUR(void  CIMEComposition::directToEditWnd(class CEditWnd *),CIMEComposition__directToEditWnd);
#endif
#ifdef CIMEComposition__getCursorPoint
REVERSE_DETOUR(class CXPoint  CIMEComposition::getCursorPoint(void)const ,CIMEComposition__getCursorPoint);
#endif
#ifdef CIMEComposition__getCompositionArea
REVERSE_DETOUR(class CXRect  CIMEComposition::getCompositionArea(void)const ,CIMEComposition__getCompositionArea);
#endif
#ifdef CIMEComposition__repositionImeCompositionWindow
REVERSE_DETOUR(int  CIMEComposition::repositionImeCompositionWindow(int,int)const ,CIMEComposition__repositionImeCompositionWindow);
#endif
#ifdef CIMEComposition__allocateImeCompositionString
REVERSE_DETOUR(unsigned short *  CIMEComposition::allocateImeCompositionString(long)const ,CIMEComposition__allocateImeCompositionString);
#endif
#ifdef CIMEComposition__allocateImeCompositionAttributes
REVERSE_DETOUR(struct CompAttr *  CIMEComposition::allocateImeCompositionAttributes(void)const ,CIMEComposition__allocateImeCompositionAttributes);
#endif
#ifdef CIMEComposition__getCompositionInsertIndex
REVERSE_DETOUR(int  CIMEComposition::getCompositionInsertIndex(void)const ,CIMEComposition__getCompositionInsertIndex);
#endif
#ifdef CIMEComposition__handleImeComposing
REVERSE_DETOUR(int  CIMEComposition::handleImeComposing(void),CIMEComposition__handleImeComposing);
#endif
#ifdef CIMEComposition__applyJapaneseComposingRules
REVERSE_DETOUR(int  CIMEComposition::applyJapaneseComposingRules(class CXStr *),CIMEComposition__applyJapaneseComposingRules);
#endif
#ifdef CIMEComposition__applyChineseComposingRules
REVERSE_DETOUR(int  CIMEComposition::applyChineseComposingRules(class CXStr *),CIMEComposition__applyChineseComposingRules);
#endif
#ifdef CIMEComposition__applyKoreanComposingRules
REVERSE_DETOUR(int  CIMEComposition::applyKoreanComposingRules(class CXStr *),CIMEComposition__applyKoreanComposingRules);
#endif
#ifdef CIMEComposition__addCompositionHighlights
REVERSE_DETOUR(int  CIMEComposition::addCompositionHighlights(void),CIMEComposition__addCompositionHighlights);
#endif
#ifdef CIMEComposition__handleImeResult
REVERSE_DETOUR(int  CIMEComposition::handleImeResult(void),CIMEComposition__handleImeResult);
#endif
#ifdef CIMEComposition__backupCurrentText
REVERSE_DETOUR(void  CIMEComposition::backupCurrentText(void),CIMEComposition__backupCurrentText);
#endif
#ifdef CIMEComposition__revertToBackupText
REVERSE_DETOUR(void  CIMEComposition::revertToBackupText(void),CIMEComposition__revertToBackupText);
#endif
#ifdef CMemoryStream__GetStringSize
REVERSE_DETOUR(int __cdecl CMemoryStream::GetStringSize(class CXStr &),CMemoryStream__GetStringSize);
#endif
#ifdef CMemoryStream__PutString
REVERSE_DETOUR(void  CMemoryStream::PutString(class CXStr &),CMemoryStream__PutString);
#endif
#ifdef CMemoryStream__GetString1
REVERSE_DETOUR(class CXStr  CMemoryStream::GetString(void),CMemoryStream__GetString1);
#endif
#ifdef CXMLSOMDocument__GetValueObjectId
REVERSE_DETOUR(bool  CXMLSOMDocument::GetValueObjectId(class CXStr,class CXStr,unsigned __int32 &),CXMLSOMDocument__GetValueObjectId);
#endif
#ifdef CXMLSOMDocument__SetValueObjectId
REVERSE_DETOUR(bool  CXMLSOMDocument::SetValueObjectId(class CXStr,class CXStr,unsigned __int32),CXMLSOMDocument__SetValueObjectId);
#endif
#ifdef CXMLSOMDocument__FieldParseItemOfClass
REVERSE_DETOUR(bool  CXMLSOMDocument::FieldParseItemOfClass(class CXStr,class CXStr,unsigned __int32 &),CXMLSOMDocument__FieldParseItemOfClass);
#endif
#ifdef EQOldPlayerAnimation__mAnimationPrefix
REVERSE_DETOUR(char (* EQOldPlayerAnimation::mAnimationPrefix)[20],EQOldPlayerAnimation__mAnimationPrefix);
#endif
#ifdef CTextOverlay__DisplayText
REVERSE_DETOUR(void CTextOverlay::DisplayText(char *,int,int,int,int,int,int),CTextOverlay__DisplayText);
#endif
