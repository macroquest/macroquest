/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "pch.h"
#include "UI.h"
#include "EQClasses.h"
#include "Globals.h"

namespace eqlib {

//============================================================================
// Statics
//============================================================================

CButtonWnd::VirtualFunctionTable* CButtonWnd::sm_vftable = nullptr;
CListWnd::VirtualFunctionTable* CListWnd::sm_vftable = nullptr;
CSidlScreenWnd::VirtualFunctionTable* MapViewMap::sm_vftable = nullptr;

//============================================================================
// CEQSuiteTextureLoader
//============================================================================

#ifdef CEQSuiteTextureLoader__dCEQSuiteTextureLoader_x
FUNCTION_AT_ADDRESS(CEQSuiteTextureLoader::~CEQSuiteTextureLoader(), CEQSuiteTextureLoader__dCEQSuiteTextureLoader);
#endif
#ifdef CEQSuiteTextureLoader__CreateTexture_x
FUNCTION_AT_ADDRESS(unsigned int CEQSuiteTextureLoader::CreateTexture(const CUITextureInfo&), CEQSuiteTextureLoader__CreateTexture);
#endif
#ifdef CEQSuiteTextureLoader__UnloadAllTextures_x
FUNCTION_AT_ADDRESS(void CEQSuiteTextureLoader::UnloadAllTextures(), CEQSuiteTextureLoader__UnloadAllTextures);
#endif
#ifdef CEQSuiteTextureLoader__GetTexture_x
FUNCTION_AT_ADDRESS(BMI* CEQSuiteTextureLoader::GetTexture(const CUITextureInfo& ti), CEQSuiteTextureLoader__GetTexture);
#endif
#ifdef CEQSuiteTextureLoader__GetDefaultUIPath_x
FUNCTION_AT_ADDRESS(const CXStr& CEQSuiteTextureLoader::GetDefaultUIPath(int DirType) const, CEQSuiteTextureLoader__GetDefaultUIPath);
#endif
#ifdef CEQSuiteTextureLoader__CEQSuiteTextureLoader_x
FUNCTION_AT_ADDRESS(CEQSuiteTextureLoader::CEQSuiteTextureLoader(), CEQSuiteTextureLoader__CEQSuiteTextureLoader);
#endif

//============================================================================
// CTextureFont
//============================================================================

#ifdef CTextureFont__GetWidth_x
FUNCTION_AT_ADDRESS(int CTextureFont::GetWidth(unsigned short) const, CTextureFont__GetWidth);
#endif
#ifdef CTextureFont__GetKerning_x
FUNCTION_AT_ADDRESS(int CTextureFont::GetKerning(unsigned short, unsigned short) const, CTextureFont__GetKerning);
#endif
#ifdef CTextureFont__GetTextExtent_x
FUNCTION_AT_ADDRESS(int CTextureFont::GetTextExtent(const CXStr&), CTextureFont__GetTextExtent);
#endif
#ifdef CTextureFont__GetHeight_x
FUNCTION_AT_ADDRESS(int CTextureFont::GetHeight() const, CTextureFont__GetHeight);
#endif
#ifdef CTextureFont__GetName_x
FUNCTION_AT_ADDRESS(CXStr CTextureFont::GetName() const, CTextureFont__GetName);
#endif
#ifdef CTextureFont__DrawWrappedText_x
FUNCTION_AT_ADDRESS(int CTextureFont::DrawWrappedText(const CXStr&, int, int, int, const CXRect&, COLORREF, uint16_t, int) const, CTextureFont__DrawWrappedText);
#endif
#ifdef CTextureFont__DrawWrappedText1_x
FUNCTION_AT_ADDRESS(int CTextureFont::DrawWrappedText(const CXStr&, const CXRect&, const CXRect&, COLORREF, uint16_t, int) const, CTextureFont__DrawWrappedText1);
#endif
#ifdef CTextureFont__DrawWrappedText2_x
FUNCTION_AT_ADDRESS(int CTextureFont::DrawWrappedText(CTextObjectInterface*, const CXStr&, const CXRect&, const CXRect&, COLORREF, uint16_t, int) const, CTextureFont__DrawWrappedText);
#endif

//============================================================================
// CXMLDataManager
//============================================================================

#ifdef CXMLDataManager__GetXMLData_x
FUNCTION_AT_ADDRESS(CXMLData* CXMLDataManager::GetXMLData(int, int) const, CXMLDataManager__GetXMLData);
#endif
#ifdef CXMLDataManager__GetXMLData1_x
FUNCTION_AT_ADDRESS(CXMLData* CXMLDataManager::GetXMLData(CXStr, CXStr), CXMLDataManager__GetXMLData1);
#endif
#ifdef CXMLDataManager__GetNumClass_x
FUNCTION_AT_ADDRESS(int CXMLDataManager::GetNumClass(), CXMLDataManager__GetNumClass);
#endif
#ifdef CXMLDataManager__GetNumItem_x
FUNCTION_AT_ADDRESS(int CXMLDataManager::GetNumItem(int), CXMLDataManager__GetNumItem);
#endif
#ifdef CXMLDataManager__GetClassIdx_x
FUNCTION_AT_ADDRESS(int CXMLDataManager::GetClassIdx(CXStr), CXMLDataManager__GetClassIdx);
#endif
#ifdef CXMLDataManager__GetItemIdx_x
FUNCTION_AT_ADDRESS(int CXMLDataManager::GetItemIdx(int, CXStr), CXMLDataManager__GetItemIdx);
#endif
#ifdef CXMLDataManager__AddToSuperType_x
//FUNCTION_AT_ADDRESS(void CXMLDataManager::AddToSuperType(CXStr, CXMLDataPtr), CXMLDataManager__AddToSuperType);
#endif
#ifdef CXMLDataManager__IsDerivedFrom_x
FUNCTION_AT_ADDRESS(bool CXMLDataManager::IsDerivedFrom(int, int), CXMLDataManager__IsDerivedFrom);
#endif
#ifdef CXMLDataManager__SetEnumHash_x
FUNCTION_AT_ADDRESS(void CXMLDataManager::SetEnumHash(), CXMLDataManager__SetEnumHash);
#endif
#ifdef CXMLDataManager__ReadFromXMLSOM_x
FUNCTION_AT_ADDRESS(bool CXMLDataManager::ReadFromXMLSOM(CXMLSOMDocument&), CXMLDataManager__ReadFromXMLSOM);
#endif

#ifdef CXMLSOMDocumentBase__XMLRead_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::XMLRead(const CXStr&, const CXStr&, const CXStr&), CXMLSOMDocumentBase__XMLRead);
#endif

// MISC


#ifdef CWndDisplayManager__FindWindowA_x
FUNCTION_AT_ADDRESS(int CWndDisplayManager::FindWindow(bool bNewWnd), CWndDisplayManager__FindWindowA);
#endif

#ifdef CItemDisplayManager__CreateWindowInstance_x
FUNCTION_AT_ADDRESS(int CItemDisplayManager::CreateWindowInstance(), CItemDisplayManager__CreateWindowInstance);
#endif


//============================================================================
// CRadioGroup
//============================================================================

CRadioGroup::CRadioGroup(CXStr name)
	: Name(name)
{
}

CRadioGroup::~CRadioGroup()
{
	for (int i = 0; i < Buttons.GetLength(); ++i)
	{
		if (Buttons[i])
		{
			Buttons[i]->SetRadioGroup(nullptr);
		}
	}
}

//============================================================================
// CButtonWnd
//============================================================================

// Class virtuals
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetRadioGroup(CRadioGroup*), CButtonWnd, SetRadioGroup);
FORWARD_FUNCTION_TO_VTABLE(int CButtonWnd::DrawWndText(const CXRect&, const CXRect&), CButtonWnd, DrawWndText);
FORWARD_FUNCTION_TO_VTABLE(int CButtonWnd::DrawCooldown(), CButtonWnd, DrawCooldown);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetCheck(bool, bool), CButtonWnd, SetCheck);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetCoolDownCompletionTimeDelta(uint32_t, uint32_t), CButtonWnd, SetCoolDownCompletionTimeDelta);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetCoolDownCompletionTime(uint32_t, uint32_t), CButtonWnd, SetCoolDownCompletionTime);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetCoolDownCompletionTime(__time32_t, uint32_t), CButtonWnd, SetCoolDownCompletionTime2);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetCoolDownBeginTime(uint32_t, uint32_t), CButtonWnd, SetCoolDownBeginTime);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetCoolDownUpdatedBeginTime(uint32_t, uint32_t), CButtonWnd, SetCoolDownUpdatedBeginTime);
FORWARD_FUNCTION_TO_VTABLE(uint32_t CButtonWnd::GetCoolDownBeginTime() const, CButtonWnd, SetCoolDownUpdatedBeginTime);
FORWARD_FUNCTION_TO_VTABLE(uint32_t CButtonWnd::GetCoolDownTotalDuration() const, CButtonWnd, GetCoolDownTotalDuration);
FORWARD_FUNCTION_TO_VTABLE(uint32_t CButtonWnd::GetCoolDownTimeRemaining() const, CButtonWnd, GetCoolDownTimeRemaining);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::ClearCoolDownCompletionTime(), CButtonWnd, ClearCoolDownCompletionTime);

// Overridden virtuals
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::Draw(), CButtonWnd, CXWnd, Draw);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::DrawTooltipAtPoint(const CXPoint& pos, const CXStr& tooltip) const, CButtonWnd, CXWnd, DrawTooltipAtPoint);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleLButtonDown(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleLButtonDown);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleLButtonUp(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleLButtonUp);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleLButtonHeld(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleLButtonHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleLButtonUpAfterHeld(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleLButtonUpAfterHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleRButtonDown(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleRButtonDown);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleRButtonUp(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleRButtonUp);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleRButtonHeld(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleRButtonHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleRButtonUpAfterHeld(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleRButtonUpAfterHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleMouseMove(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleMouseMove);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::OnProcessFrame(), CButtonWnd, CXWnd, OnProcessFrame);
FORWARD_FUNCTION_TO_VTABLE2(bool CButtonWnd::IsPointTransparent(const CXPoint& point) const, CButtonWnd, CXWnd, IsPointTransparent);
FORWARD_FUNCTION_TO_VTABLE2(void CButtonWnd::SetAttributesFromSidl(CParamScreenPiece*), CButtonWnd, CXWnd, SetAttributesFromSidl);


//============================================================================
// CCheckBoxWnd
//============================================================================

#ifdef CCheckBoxWnd__CCheckBoxWnd_x
FUNCTION_AT_ADDRESS(CCheckBoxWnd::CCheckBoxWnd(CXWnd*, uint32_t, CXRect, class CXPoint, CXSize, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*), CCheckBoxWnd__CCheckBoxWnd);
#endif
#ifdef CCheckBoxWnd__SetRadioLook_x
FUNCTION_AT_ADDRESS(void CCheckBoxWnd::SetRadioLook(), CCheckBoxWnd__SetRadioLook);
#endif

//============================================================================
// CComboWnd
//============================================================================

#ifdef CComboWnd__GetListRect_x
FUNCTION_AT_ADDRESS(CXRect CComboWnd::GetListRect(bool) const, CComboWnd__GetListRect);
#endif
#ifdef CComboWnd__SetColors_x
FUNCTION_AT_ADDRESS(void CComboWnd::SetColors(COLORREF, COLORREF, COLORREF), CComboWnd__SetColors);
#endif
#ifdef CComboWnd__InsertChoice_x
FUNCTION_AT_ADDRESS(void CComboWnd::InsertChoice(const CXStr&, uint32_t), CComboWnd__InsertChoice);
#endif
#ifdef CComboWnd__SetChoice_x
FUNCTION_AT_ADDRESS(void CComboWnd::SetChoice(int), CComboWnd__SetChoice);
#endif
#ifdef CComboWnd__GetItemCount_x
FUNCTION_AT_ADDRESS(int CComboWnd::GetItemCount(), CComboWnd__GetItemCount);
#endif
#ifdef CComboWnd__GetCurChoice_x
FUNCTION_AT_ADDRESS(int CComboWnd::GetCurChoice() const, CComboWnd__GetCurChoice);
#endif
#ifdef CComboWnd__GetCurChoiceText_x
FUNCTION_AT_ADDRESS(CXStr CComboWnd::GetCurChoiceText() const, CComboWnd__GetCurChoiceText);
#endif
#ifdef CComboWnd__DeleteAll_x
FUNCTION_AT_ADDRESS(void CComboWnd::DeleteAll(), CComboWnd__DeleteAll);
#endif
#ifdef CComboWnd__GetTextRect_x
FUNCTION_AT_ADDRESS(CXRect CComboWnd::GetTextRect() const, CComboWnd__GetTextRect);
#endif

//============================================================================
// CEditWnd
//============================================================================

// CEditBaseWnd
#ifdef CEditBaseWnd__SetMaxChars_x
FUNCTION_AT_ADDRESS(void CEditBaseWnd::SetMaxChars(int), CEditBaseWnd__SetMaxChars);
#endif
#ifdef CEditBaseWnd__SetSel_x
FUNCTION_AT_ADDRESS(void CEditBaseWnd::SetSel(int, int), CEditBaseWnd__SetSel);
#endif


// CEditWnd
#ifdef CEditWnd__CEditWnd_x
//FUNCTION_AT_ADDRESS(CEditWnd::CEditWnd(CXWnd*, uint32_t, CXRect, uint32_t), CEditWnd__CEditWnd);
#endif
#ifdef CEditWnd__GetLineForPrintableChar_x
FUNCTION_AT_ADDRESS(int CEditWnd::GetLineForPrintableChar(int) const, CEditWnd__GetLineForPrintableChar);
#endif
#ifdef CEditWnd__GetLineLength_x
FUNCTION_AT_ADDRESS(int CEditWnd::GetLineLength(int) const, CEditWnd__GetLineLength);
#endif
#ifdef CEditWnd__FillIndexArray_x
FUNCTION_AT_ADDRESS(void CEditWnd::FillIndexArray(CXStr) const, CEditWnd__FillIndexArray);
#endif
#ifdef CEditWnd__SelectableCharFromPoint_x
FUNCTION_AT_ADDRESS(int CEditWnd::SelectableCharFromPoint(CXPoint) const, CEditWnd__SelectableCharFromPoint);
#endif
#ifdef CEditWnd__AddItemTag_x
FUNCTION_AT_ADDRESS(void CEditWnd::AddItemTag(int, char*, int), CEditWnd__AddItemTag);
#endif
#ifdef CEditWnd__ProcessText_x
FUNCTION_AT_ADDRESS(void CEditWnd::ProcessText(), CEditWnd__ProcessText);
#endif
#ifdef CEditWnd__GetCharIndexPt_x
FUNCTION_AT_ADDRESS(CXPoint CEditWnd::GetCharIndexPt(int) const, CEditWnd__GetCharIndexPt);
#endif
#ifdef CEditWnd__GetSelStartPt_x
FUNCTION_AT_ADDRESS(CXPoint CEditWnd::GetSelStartPt() const, CEditWnd__GetSelStartPt);
#endif
#ifdef CEditWnd__GetSelEndPt_x
FUNCTION_AT_ADDRESS(CXPoint CEditWnd::GetSelEndPt() const, CEditWnd__GetSelEndPt);
#endif
#ifdef CEditWnd__FilterInputStr_x
FUNCTION_AT_ADDRESS(void CEditWnd::FilterInputStr(CXStr&), CEditWnd__FilterInputStr);
#endif
#ifdef CEditWnd__CalculateScrollRange_x
FUNCTION_AT_ADDRESS(void CEditWnd::CalculateScrollRange(), CEditWnd__CalculateScrollRange);
#endif
#ifdef CEditWnd__EnsureCaretVisible_x
FUNCTION_AT_ADDRESS(void CEditWnd::EnsureCaretVisible(), CEditWnd__EnsureCaretVisible);
#endif
#ifdef CEditWnd__SetEditable_x
FUNCTION_AT_ADDRESS(void CEditWnd::SetEditable(bool), CEditWnd__SetEditable);
#endif
#ifdef CEditWnd__GetSTMLSafeText_x
FUNCTION_AT_ADDRESS(CXStr CEditWnd::GetSTMLSafeText(), CEditWnd__GetSTMLSafeText);
#endif
#ifdef CEditWnd__SetWindowTextA_x
FUNCTION_AT_ADDRESS(void CEditWnd::SetWindowTextA(const CXStr& Str), CEditWnd__SetWindowTextA);
#endif
#ifdef CEditWnd__ConvertIndexPrintableToTagged_x
FUNCTION_AT_ADDRESS(int CEditWnd::ConvertIndexPrintableToTagged(int), CEditWnd__ConvertIndexPrintableToTagged);
#endif
#ifdef CEditWnd__ConvertIndexTaggedToPrintable_x
FUNCTION_AT_ADDRESS(int CEditWnd::ConvertIndexTaggedToPrintable(int), CEditWnd__ConvertIndexTaggedToPrintable);
#endif
#ifdef CEditWnd__GetCaretPt_x
FUNCTION_AT_ADDRESS(CXPoint CEditWnd::GetCaretPt() const, CEditWnd__GetCaretPt);
#endif

void CEditBaseWnd::SetMaxChars(int maxChars)
{
	MaxChars = maxChars;

	if (maxChars < (int)InputText.length())
	{
		SetWindowText(InputText);
	}
}

//============================================================================
// CGuageWnd
//============================================================================

#ifdef CGaugeWnd__CGaugeWnd_x
FUNCTION_AT_ADDRESS(CGaugeWnd::CGaugeWnd(CXWnd*, uint32_t, CXRect, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, int, unsigned long, unsigned long, bool, int, int, int, int), CGaugeWnd__CGaugeWnd);
#endif
#ifdef CGaugeWnd__CalcFillRect_x
FUNCTION_AT_ADDRESS(CXRect CGaugeWnd::CalcFillRect(CXRect*, int) const, CGaugeWnd__CalcFillRect);
#endif
#ifdef CGaugeWnd__CalcLinesFillRect_x
FUNCTION_AT_ADDRESS(CXRect CGaugeWnd::CalcLinesFillRect(CXRect*, int) const, CGaugeWnd__CalcLinesFillRect);
#endif
#ifdef CGaugeWnd__SpecialToolTip_x
FUNCTION_AT_ADDRESS(void CGaugeWnd::SpecialToolTip(), CGaugeWnd__SpecialToolTip);
#endif

//============================================================================
// CHotButton
//============================================================================

#ifdef CHotButton__SetButtonSize_x
FUNCTION_AT_ADDRESS(void CHotButton::SetButtonSize(int percent, bool bUpdateParent), CHotButton__SetButtonSize);
#endif

//============================================================================
// CLabel
//============================================================================

#ifdef CLabel__CLabel_x
FUNCTION_AT_ADDRESS(CLabel::CLabel(CXWnd*, uint32_t, CXRect*, int), CLabel__CLabel);
#endif
#ifdef CLabel__SetNoWrap_x
FUNCTION_AT_ADDRESS(void CLabel::SetNoWrap(bool), CLabel__SetNoWrap);
#endif
#ifdef CLabel__SetAlignRight_x
FUNCTION_AT_ADDRESS(void CLabel::SetAlignRight(bool), CLabel__SetAlignRight);
#endif
#ifdef CLabel__SetAlignCenter_x
FUNCTION_AT_ADDRESS(void CLabel::SetAlignCenter(bool), CLabel__SetAlignCenter);
#endif

//============================================================================
// CListWnd
//============================================================================

// class virtuals
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::OnHeaderClick(CXPoint), CListWnd, OnHeaderClick);
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::DrawColumnSeparators() const, CListWnd, DrawColumnSeparators);
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::DrawSeparator(int index) const, CListWnd, DrawSeparator);
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::DrawLine(int index) const, CListWnd, DrawLine);
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::DrawHeader() const, CListWnd, DrawHeader);
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::DrawItem(int index, int, int) const, CListWnd, DrawItem);
FORWARD_FUNCTION_TO_VTABLE(void CListWnd::DeleteAll(), CListWnd, DeleteAll);
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::Compare(const SListWndLine&, const SListWndLine&) const, CListWnd, Compare);
FORWARD_FUNCTION_TO_VTABLE(void CListWnd::Sort(), CListWnd, Sort);

// overrides
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::Draw(), CListWnd, CXWnd, Draw);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::DrawBackground() const, CListWnd, CXWnd, DrawBackground);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::DrawTooltip(const CXWnd* wnd) const, CListWnd, CXWnd, DrawTooltip);
FORWARD_FUNCTION_TO_VTABLE2(HCURSOR CListWnd::GetCursorToDisplay() const, CListWnd, CXWnd, GetCursorToDisplay);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleLButtonDown(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleLButtonDown);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleLButtonUp(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleLButtonUp);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleLButtonHeld(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleLButtonHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleLButtonUpAfterHeld(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleLButtonUpAfterHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleRButtonDown(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleRButtonDown);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleRButtonUp(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleRButtonUp);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleRButtonHeld(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleRButtonHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleRButtonUpAfterHeld(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleRButtonUpAfterHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleMouseMove(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleMouseMove);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::WndNotification(CXWnd* sender, uint32_t message, void* data), CListWnd, CXWnd, WndNotification);
FORWARD_FUNCTION_TO_VTABLE2(void CListWnd::OnWndNotification(), CListWnd, CXWnd, OnWndNotification);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::OnMove(const CXRect& rect), CListWnd, CXWnd, OnMove);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::OnResize(int w, int h), CListWnd, CXWnd, OnResize);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::OnVScroll(EScrollCode code, int pos), CListWnd, CXWnd, OnVScroll);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::OnHScroll(EScrollCode code, int pos), CListWnd, CXWnd, OnHScroll);
FORWARD_FUNCTION_TO_VTABLE2(CXRect CListWnd::GetHitTestRect(int code) const, CListWnd, CXWnd, GetHitTestRect);
FORWARD_FUNCTION_TO_VTABLE2(CXRect CListWnd::GetClientClipRect() const, CListWnd, CXWnd, GetClientClipRect);
FORWARD_FUNCTION_TO_VTABLE2(CXWnd* CListWnd::GetChildWndAt(const CXPoint& pos, bool, bool) const, CListWnd, CXWnd, GetChildWndAt);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::SetVScrollPos(int pos), CListWnd, CXWnd, SetVScrollPos);

#ifdef CListWnd__CListWnd_x
CONSTRUCTOR_AT_ADDRESS(CListWnd::CListWnd(CXWnd*, uint32_t, CXRect const&), CListWnd__CListWnd);
#endif
#ifdef CListWnd__dCListWnd_x
FUNCTION_AT_ADDRESS(CListWnd::~CListWnd(), CListWnd__dCListWnd);
#endif
#ifdef CListWnd__GetCurSel_x
FUNCTION_AT_ADDRESS(int CListWnd::GetCurSel() const, CListWnd__GetCurSel);
#endif
#ifdef CListWnd__GetCurCol_x
FUNCTION_AT_ADDRESS(int CListWnd::GetCurCol() const, CListWnd__GetCurCol);
#endif
#ifdef CListWnd__GetItemData_x
FUNCTION_AT_ADDRESS(uint64_t CListWnd::GetItemData(int) const, CListWnd__GetItemData);
#endif
#ifdef CListWnd__GetItemText_x
FUNCTION_AT_ADDRESS(CXStr CListWnd::GetItemText(int, int) const, CListWnd__GetItemText);
#endif
#ifdef CListWnd__GetItemIcon_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CListWnd::GetItemIcon(int, int) const, CListWnd__GetItemIcon);
#endif
#ifdef CListWnd__GetItemColor_x
FUNCTION_AT_ADDRESS(unsigned long CListWnd::GetItemColor(int, int) const, CListWnd__GetItemColor);
#endif
#ifdef CListWnd__GetColumnFlags_x
FUNCTION_AT_ADDRESS(uint32_t CListWnd::GetColumnFlags(int) const, CListWnd__GetColumnFlags);
#endif
#ifdef CListWnd__GetColumnWidth_x
FUNCTION_AT_ADDRESS(int CListWnd::GetColumnWidth(int) const, CListWnd__GetColumnWidth);
#endif
#ifdef CListWnd__SetColumnWidth_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnWidth(int, int), CListWnd__SetColumnWidth);
#endif
#ifdef CListWnd__ShiftColumnSeparator_x
FUNCTION_AT_ADDRESS(void CListWnd::ShiftColumnSeparator(int, int), CListWnd__ShiftColumnSeparator);
#endif
#ifdef CListWnd__GetColumnMinWidth_x
FUNCTION_AT_ADDRESS(int CListWnd::GetColumnMinWidth(int) const, CListWnd__GetColumnMinWidth);
#endif
#ifdef CListWnd__GetColumnTooltip_x
FUNCTION_AT_ADDRESS(CXStr CListWnd::GetColumnTooltip(int) const, CListWnd__GetColumnTooltip);
#endif
#ifdef CListWnd__GetColumnJustification_x
FUNCTION_AT_ADDRESS(int CListWnd::GetColumnJustification(int) const, CListWnd__GetColumnJustification);
#endif
#ifdef CListWnd__SetColumnJustification_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnJustification(int, int), CListWnd__SetColumnJustification);
#endif
#ifdef CListWnd__GetColumnLabel_x
FUNCTION_AT_ADDRESS(CXStr CListWnd::GetColumnLabel(int) const, CListWnd__GetColumnLabel);
#endif
#ifdef CListWnd__GetColumnAnimation_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CListWnd::GetColumnAnimation(int) const, CListWnd__GetColumnAnimation);
#endif
#ifdef CListWnd__GetColumnAnimationSelected_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CListWnd::GetColumnAnimationSelected(int) const, CListWnd__GetColumnAnimationSelected);
#endif
#ifdef CListWnd__GetColumnAnimationMouseOver_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CListWnd::GetColumnAnimationMouseOver(int) const, CListWnd__GetColumnAnimationMouseOver);
#endif
#ifdef CListWnd__AddLine_x
FUNCTION_AT_ADDRESS(int CListWnd::AddLine(SListWndLine*), CListWnd__AddLine);
#endif
#ifdef CListWnd__AddString_x
FUNCTION_AT_ADDRESS(int CListWnd::AddString(const CXStr& Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr), CListWnd__AddString);
#endif
#ifdef CListWnd__RemoveString_x
FUNCTION_AT_ADDRESS(void CListWnd::RemoveString(int), CListWnd__RemoveString);
#endif
#ifdef CListWnd__InsertLine_x
FUNCTION_AT_ADDRESS(void CListWnd::InsertLine(int ID, SListWndLine* rEntry), CListWnd__InsertLine);
#endif
#ifdef CListWnd__RemoveLine_x
FUNCTION_AT_ADDRESS(void CListWnd::RemoveLine(int), CListWnd__RemoveLine);
#endif
#ifdef CListWnd__SetCurSel_x
FUNCTION_AT_ADDRESS(void CListWnd::SetCurSel(int), CListWnd__SetCurSel);
#endif
#ifdef CListWnd__ToggleSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ToggleSel(int), CListWnd__ToggleSel);
#endif
#ifdef CListWnd__ExtendSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ExtendSel(int), CListWnd__ExtendSel);
#endif
#ifdef CListWnd__ClearAllSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ClearAllSel(), CListWnd__ClearAllSel);
#endif
#ifdef CListWnd__ClearSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ClearSel(int), CListWnd__ClearSel);
#endif
#ifdef CListWnd__SetColumnsSizable_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnsSizable(bool), CListWnd__SetColumnsSizable);
#endif
#ifdef CListWnd__GetItemWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CListWnd::GetItemWnd(int Index, int SubItem) const, CListWnd__GetItemWnd);
#endif
#ifdef CListWnd__SetItemIcon_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemIcon(int Index, int SubItem, const CTextureAnimation* pTA), CListWnd__SetItemIcon);
#endif
#ifdef CListWnd__CalculateCustomWindowPositions_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateCustomWindowPositions(), CListWnd__CalculateCustomWindowPositions);
#endif
#ifdef CListWnd__SetItemWnd_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemWnd(int Index, int SubItem, CXWnd* pWnd), CListWnd__SetItemWnd);
#endif
#ifdef CListWnd__SetItemData_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemData(int, uint64_t), CListWnd__SetItemData);
#endif
#ifdef CListWnd__SetItemText_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemText(int, int, const CXStr&), CListWnd__SetItemText);
#endif
#ifdef CListWnd__SetItemColor_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemColor(int, int, unsigned long), CListWnd__SetItemColor);
#endif
#ifdef CListWnd__IsLineEnabled_x
FUNCTION_AT_ADDRESS(bool CListWnd::IsLineEnabled(int) const, CListWnd__IsLineEnabled);
#endif
#ifdef CListWnd__EnableLine_x
FUNCTION_AT_ADDRESS(void CListWnd::EnableLine(int, bool), CListWnd__EnableLine);
#endif
#ifdef CListWnd__AddColumn_x
FUNCTION_AT_ADDRESS(int CListWnd::AddColumn(const CXStr&, int, uint32_t, uint32_t), CListWnd__AddColumn);
#endif
#ifdef CListWnd__AddColumn1_x
// CListWnd::AddColumn implemented in ExceptionsDisabled.cpp
#endif
#ifdef CListWnd__SetColumnLabel_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnLabel(int, const CXStr&), CListWnd__SetColumnLabel);
#endif
#ifdef CListWnd__GetItemHeight_x
FUNCTION_AT_ADDRESS(int CListWnd::GetItemHeight(int) const, CListWnd__GetItemHeight);
#endif
#ifdef CListWnd__CalculateLineHeights_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateLineHeights(), CListWnd__CalculateLineHeights);
#endif
#ifdef CListWnd__CalculateVSBRange_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateVSBRange(), CListWnd__CalculateVSBRange);
#endif
#ifdef CListWnd__CalculateFirstVisibleLine_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateFirstVisibleLine(), CListWnd__CalculateFirstVisibleLine);
#endif
#ifdef CListWnd__EnsureVisible_x
FUNCTION_AT_ADDRESS(void CListWnd::EnsureVisible(int), CListWnd__EnsureVisible);
#endif
#ifdef CListWnd__GetItemRect_x
FUNCTION_AT_ADDRESS(CXRect CListWnd::GetItemRect(int, int) const, CListWnd__GetItemRect);
#endif
#ifdef CListWnd__GetItemAtPoint_x
FUNCTION_AT_ADDRESS(int CListWnd::GetItemAtPoint(const CXPoint&) const, CListWnd__GetItemAtPoint);
#endif
#ifdef CListWnd__GetItemAtPoint1_x
FUNCTION_AT_ADDRESS(void CListWnd::GetItemAtPoint(const CXPoint&, int*, int*) const, CListWnd__GetItemAtPoint1);
#endif
#ifdef CListWnd__CloseAndUpdateEditWindow_x
FUNCTION_AT_ADDRESS(void CListWnd::CloseAndUpdateEditWindow(), CListWnd__CloseAndUpdateEditWindow);
#endif
#ifdef CListWnd__SetColors_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColors(unsigned long, unsigned long, unsigned long), CListWnd__SetColors);
#endif
#ifdef CListWnd__GetSeparatorRect_x
FUNCTION_AT_ADDRESS(CXRect CListWnd::GetSeparatorRect(int) const, CListWnd__GetSeparatorRect);
#endif
#ifdef CListWnd__GetHeaderRect_x
FUNCTION_AT_ADDRESS(CXRect CListWnd::GetHeaderRect(int) const, CListWnd__GetHeaderRect);
#endif

int CListWnd::AddString(const char* Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr)
{
	return AddString(CXStr(Str), Color, Data, pTa, TooltipStr);
}

int CListWnd::IndexOf(int column, const std::function<bool(const CXStr)>& predicate)
{
	for (auto row = 0; row < ItemsArray.GetLength(); row++)
	{
		if (predicate(GetItemText(row, column)))
			return row;
	}

	return -1;
}

int CListWnd::IndexOf(const std::function<bool(const CXStr)>& predicate)
{
	return IndexOf(0, predicate);
}

bool CListWnd::Contains(int column, const std::function<bool(const CXStr)>& predicate)
{
	return IndexOf(column, predicate) != -1;
}

bool CListWnd::Contains(const std::function<bool(const CXStr)>& predicate)
{
	return IndexOf(0, predicate) != -1;
}

#if 0 // apparently we already have this as an import
CXWnd* CListWnd::GetItemWnd(int Index, int SubItem) const
{
	if (Index < 0 || Index >= ItemsArray.GetLength())
		return nullptr;

	const SListWndLine& line = ItemsArray[Index];

	if (SubItem < 0 || SubItem >= line.Cells.GetLength())
		return nullptr;

	if (line.Cells[SubItem].pWnd != nullptr)
		return line.Cells[SubItem].pWnd->GetFirstChildWnd();

	return nullptr;
}
#endif

//============================================================================
// CPageWnd
//============================================================================

#ifdef CPageWnd__CPageWnd_x
FUNCTION_AT_ADDRESS(CPageWnd::CPageWnd(CXWnd*, uint32_t, CXRect, class CXStr, CPageTemplate*), CPageWnd__CPageWnd);
#endif
#ifdef CPageWnd__FlashTab_x
FUNCTION_AT_ADDRESS(void CPageWnd::FlashTab(bool, int) const, CPageWnd__FlashTab);
#endif
#ifdef CPageWnd__GetTabText_x
FUNCTION_AT_ADDRESS(CXStr CPageWnd::GetTabText(bool) const, CPageWnd__GetTabText);
#endif
#ifdef CPageWnd__SetTabText_x
FUNCTION_AT_ADDRESS(void CPageWnd::SetTabText(CXStr&) const, CPageWnd__SetTabText);
#endif


//============================================================================
// CSliderWnd
//============================================================================

#ifdef CSliderWnd__CSliderWnd_x
FUNCTION_AT_ADDRESS(CSliderWnd::CSliderWnd(CXWnd*, uint32_t, CXRect, CSliderTemplate*), CSliderWnd__CSliderWnd);
#endif
#ifdef CSliderWnd__SetValue_x
FUNCTION_AT_ADDRESS(void CSliderWnd::SetValue(int), CSliderWnd__SetValue);
#endif
#ifdef CSliderWnd__SetNumTicks_x
FUNCTION_AT_ADDRESS(void CSliderWnd::SetNumTicks(int), CSliderWnd__SetNumTicks);
#endif
#ifdef CSliderWnd__UpdateThumb_x
FUNCTION_AT_ADDRESS(void CSliderWnd::UpdateThumb(), CSliderWnd__UpdateThumb);
#endif
#ifdef CSliderWnd__UpdateMiddleRange_x
FUNCTION_AT_ADDRESS(void CSliderWnd::UpdateMiddleRange(), CSliderWnd__UpdateMiddleRange);
#endif
#ifdef CSliderWnd__GetValue_x
FUNCTION_AT_ADDRESS(int CSliderWnd::GetValue() const, CSliderWnd__GetValue);
#endif
#ifdef CSliderWnd__GetMiddleRangeRect_x
FUNCTION_AT_ADDRESS(CXRect CSliderWnd::GetMiddleRangeRect() const, CSliderWnd__GetMiddleRangeRect);
#endif
#ifdef CSliderWnd__GetEndCapLeftRect_x
FUNCTION_AT_ADDRESS(CXRect CSliderWnd::GetEndCapLeftRect() const, CSliderWnd__GetEndCapLeftRect);
#endif
#ifdef CSliderWnd__GetEndCapRightRect_x
FUNCTION_AT_ADDRESS(CXRect CSliderWnd::GetEndCapRightRect() const, CSliderWnd__GetEndCapRightRect);
#endif
#ifdef CSliderWnd__GetThumbRect_x
FUNCTION_AT_ADDRESS(CXRect CSliderWnd::GetThumbRect() const, CSliderWnd__GetThumbRect);
#endif
#ifdef CSliderWnd__SetThumbToOffset_x
FUNCTION_AT_ADDRESS(void CSliderWnd::SetThumbToOffset(int), CSliderWnd__SetThumbToOffset);
#endif
#ifdef CSliderWnd__DrawMiddleRange_x
FUNCTION_AT_ADDRESS(int CSliderWnd::DrawMiddleRange() const, CSliderWnd__DrawMiddleRange);
#endif
#ifdef CSliderWnd__DrawEndCapLeft_x
FUNCTION_AT_ADDRESS(int CSliderWnd::DrawEndCapLeft() const, CSliderWnd__DrawEndCapLeft);
#endif
#ifdef CSliderWnd__DrawEndCapRight_x
FUNCTION_AT_ADDRESS(int CSliderWnd::DrawEndCapRight() const, CSliderWnd__DrawEndCapRight);
#endif
#ifdef CSliderWnd__DrawThumb_x
FUNCTION_AT_ADDRESS(int CSliderWnd::DrawThumb() const, CSliderWnd__DrawThumb);
#endif

//============================================================================
// CStmlWnd
//============================================================================

#ifdef CStmlWnd__GetSTMLText_x
FUNCTION_AT_ADDRESS(CXStr CStmlWnd::GetSTMLText() const, CStmlWnd__GetSTMLText);
#endif
#ifdef CStmlWnd__CStmlWnd_x
FUNCTION_AT_ADDRESS(CStmlWnd::CStmlWnd(CXWnd*, uint32_t, CXRect), CStmlWnd__CStmlWnd);
#endif
#ifdef CStmlWnd__InitializeTextLine_x
FUNCTION_AT_ADDRESS(void CStmlWnd::InitializeTextLine(SParseVariables*, int), CStmlWnd__InitializeTextLine);
#endif
#ifdef CStmlWnd__AddTextPieceToLine_x
FUNCTION_AT_ADDRESS(void CStmlWnd::AddTextPieceToLine(SParseVariables*), CStmlWnd__AddTextPieceToLine);
#endif
#ifdef CStmlWnd__MakeStmlColorTag_x
FUNCTION_AT_ADDRESS(CXStr __cdecl CStmlWnd::MakeStmlColorTag(unsigned long), CStmlWnd__MakeStmlColorTag);
#endif
#ifdef CStmlWnd__MakeWndNotificationTag_x
FUNCTION_AT_ADDRESS(CXStr CStmlWnd::MakeWndNotificationTag(uint32_t, const CXStr&, const CXStr&), CStmlWnd__MakeWndNotificationTag);
#endif
#ifdef CStmlWnd__ParseTagColor_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ParseTagColor(CXStr, unsigned long*) const, CStmlWnd__ParseTagColor);
#endif
#ifdef CStmlWnd__ParseTagFace_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ParseTagFace(CXStr, CTextureFont const**) const, CStmlWnd__ParseTagFace);
#endif
#ifdef CStmlWnd__ParseAmpersand_x
FUNCTION_AT_ADDRESS(bool CStmlWnd::ParseAmpersand(CXStr&, char*) const, CStmlWnd__ParseAmpersand);
#endif
#ifdef CStmlWnd__FastForwardPastSpaces_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::FastForwardPastSpaces(CXStr&, int*), CStmlWnd__FastForwardPastSpaces);
#endif
#ifdef CStmlWnd__FastForwardPastSpacesAndQuotes_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::FastForwardPastSpacesAndQuotes(CXStr&, int*), CStmlWnd__FastForwardPastSpacesAndQuotes);
#endif
#ifdef CStmlWnd__GetNextTagPiece_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::GetNextTagPiece(const CXStr&, CXStr*, int*, bool (*)(unsigned short), bool), CStmlWnd__GetNextTagPiece);
#endif
#ifdef CStmlWnd__IsCharacterNotQuotes_x
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::IsCharacterNotQuotes(unsigned short), CStmlWnd__IsCharacterNotQuotes);
#endif
#ifdef CStmlWnd__FastForwardPastQuotesAndGetNextTagPiece_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::FastForwardPastQuotesAndGetNextTagPiece(CXStr&, CXStr*, int*, bool), CStmlWnd__FastForwardPastQuotesAndGetNextTagPiece);
#endif
#ifdef CStmlWnd__FastForwardToEndOfTag_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::FastForwardToEndOfTag(const CXStr&, CXStr*, int*, char), CStmlWnd__FastForwardToEndOfTag);
#endif
#ifdef CStmlWnd__InitializeTempVariables_x
FUNCTION_AT_ADDRESS(void CStmlWnd::InitializeTempVariables(SParseVariables*, CXRect), CStmlWnd__InitializeTempVariables);
#endif
#ifdef CStmlWnd__InitializeWindowVariables_x
FUNCTION_AT_ADDRESS(void CStmlWnd::InitializeWindowVariables(), CStmlWnd__InitializeWindowVariables);
#endif
#ifdef CStmlWnd__ResetTempVariablesForNewLine_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ResetTempVariablesForNewLine(SParseVariables*), CStmlWnd__ResetTempVariablesForNewLine);
#endif
#ifdef CStmlWnd__GetNextChar_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::GetNextChar(int*, CXStr&), CStmlWnd__GetNextChar);
#endif
#ifdef CStmlWnd__GetThisChar_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::GetThisChar(int, CXStr&), CStmlWnd__GetThisChar);
#endif
#ifdef CStmlWnd__IsCharacterNotEquals_x
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::IsCharacterNotEquals(unsigned short), CStmlWnd__IsCharacterNotEquals);
#endif
#ifdef CStmlWnd__IsCharacterNotASpaceAndNotNULL_x
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::IsCharacterNotASpaceAndNotNULL(unsigned short), CStmlWnd__IsCharacterNotASpaceAndNotNULL);
#endif
#ifdef CStmlWnd__ParseSTMLHead_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ParseSTMLHead(CXStr&), CStmlWnd__ParseSTMLHead);
#endif
#ifdef CStmlWnd__ParseSTMLTable_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ParseSTMLTable(CXStr&, int*, CXStr&, SParseVariables*), CStmlWnd__ParseSTMLTable);
#endif
#ifdef CStmlWnd__ParseSTMLTableAttributes_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ParseSTMLTableAttributes(CXStr, STable*), CStmlWnd__ParseSTMLTableAttributes);
#endif
#ifdef CStmlWnd__ForceParseNow_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ForceParseNow(), CStmlWnd__ForceParseNow);
#endif
#ifdef CStmlWnd__CalculateVSBRange_x
FUNCTION_AT_ADDRESS(void CStmlWnd::CalculateVSBRange(int), CStmlWnd__CalculateVSBRange);
#endif
#ifdef CStmlWnd__CalculateHSBRange_x
FUNCTION_AT_ADDRESS(void CStmlWnd::CalculateHSBRange(int), CStmlWnd__CalculateHSBRange);
#endif
#ifdef CStmlWnd__CompleteParse_x
FUNCTION_AT_ADDRESS(void CStmlWnd::CompleteParse(), CStmlWnd__CompleteParse);
#endif
#ifdef CStmlWnd__StripFirstSTMLLines_x
FUNCTION_AT_ADDRESS(void CStmlWnd::StripFirstSTMLLines(int), CStmlWnd__StripFirstSTMLLines);
#endif
#ifdef CStmlWnd__CanBreakAtCharacter_x
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::CanBreakAtCharacter(unsigned short), CStmlWnd__CanBreakAtCharacter);
#endif
#ifdef CStmlWnd__UpdateHistoryString_x
FUNCTION_AT_ADDRESS(void CStmlWnd::UpdateHistoryString(int32_t, const CXStr&), CStmlWnd__UpdateHistoryString);
#endif
#ifdef CStmlWnd__SetSTMLTextWithoutHistory_x
FUNCTION_AT_ADDRESS(void CStmlWnd::SetSTMLTextWithoutHistory(CXStr), CStmlWnd__SetSTMLTextWithoutHistory);
#endif
#ifdef CStmlWnd__GoToBackHistoryLink_x
FUNCTION_AT_ADDRESS(void CStmlWnd::GoToBackHistoryLink(), CStmlWnd__GoToBackHistoryLink);
#endif
#ifdef CStmlWnd__CanGoBackward_x
FUNCTION_AT_ADDRESS(bool CStmlWnd::CanGoBackward(), CStmlWnd__CanGoBackward);
#endif

//============================================================================
// CTabWnd
//============================================================================

#ifdef CTabWnd__CTabWnd_x
FUNCTION_AT_ADDRESS(CTabWnd::CTabWnd(CXWnd* pParent, UINT uId, RECT* rect, CTabBoxTemplate* pTabContents), CTabWnd__CTabWnd);
#endif
#ifdef CTabWnd__GetNumTabs_x
FUNCTION_AT_ADDRESS(int CTabWnd::GetNumTabs() const, CTabWnd__GetNumTabs);
#endif
#ifdef CTabWnd__GetCurrentPage_x
FUNCTION_AT_ADDRESS(CPageWnd* CTabWnd::GetCurrentPage() const, CTabWnd__GetCurrentPage);
#endif
#ifdef CTabWnd__GetTabRect_x
FUNCTION_AT_ADDRESS(CXRect CTabWnd::GetTabRect(int) const, CTabWnd__GetTabRect);
#endif
#ifdef CTabWnd__GetTabInnerRect_x
FUNCTION_AT_ADDRESS(CXRect CTabWnd::GetTabInnerRect(int) const, CTabWnd__GetTabInnerRect);
#endif
#ifdef CTabWnd__GetPageClientRect_x
FUNCTION_AT_ADDRESS(CXRect CTabWnd::GetPageClientRect() const, CTabWnd__GetPageClientRect);
#endif
#ifdef CTabWnd__GetPageInnerRect_x
FUNCTION_AT_ADDRESS(CXRect CTabWnd::GetPageInnerRect() const, CTabWnd__GetPageInnerRect);
#endif
#ifdef CTabWnd__SetPage_x
FUNCTION_AT_ADDRESS(void CTabWnd::SetPage(int, bool, bool, bool), CTabWnd__SetPage);
#endif
#ifdef CTabWnd__SetPage1_x
FUNCTION_AT_ADDRESS(bool CTabWnd::SetPage(CPageWnd*, bool, bool), CTabWnd__SetPage1);
#endif
#ifdef CTabWnd__InsertPage_x
FUNCTION_AT_ADDRESS(void CTabWnd::InsertPage(CPageWnd*, int), CTabWnd__InsertPage);
#endif
#ifdef CTabWnd__SetPageRect_x
FUNCTION_AT_ADDRESS(void CTabWnd::SetPageRect(const CXRect&), CTabWnd__SetPageRect);
#endif
#ifdef CTabWnd__UpdatePage_x
FUNCTION_AT_ADDRESS(void CTabWnd::UpdatePage(), CTabWnd__UpdatePage);
#endif
#ifdef CTabWnd__GetPageFromTabIndex_x
FUNCTION_AT_ADDRESS(CPageWnd* CTabWnd::GetPageFromTabIndex(int) const, CTabWnd__GetPageFromTabIndex);
#endif
#ifdef CTabWnd__GetCurrentTabIndex_x
FUNCTION_AT_ADDRESS(int CTabWnd::GetCurrentTabIndex() const, CTabWnd__GetCurrentTabIndex);
#endif
#ifdef CTabWnd__IndexInBounds_x
FUNCTION_AT_ADDRESS(bool CTabWnd::IndexInBounds(int) const, CTabWnd__IndexInBounds);
#endif
#ifdef CTabWnd__GetPageFromTabPoint_x
FUNCTION_AT_ADDRESS(CPageWnd* CTabWnd::GetPageFromTabPoint(CXPoint) const, CTabWnd__GetPageFromTabPoint);
#endif
#ifdef CTabWnd__DrawTab_x
FUNCTION_AT_ADDRESS(int CTabWnd::DrawTab(int) const, CTabWnd__DrawTab);
#endif
#ifdef CTabWnd__DrawCurrentPage_x
FUNCTION_AT_ADDRESS(int CTabWnd::DrawCurrentPage() const, CTabWnd__DrawCurrentPage);
#endif

//============================================================================
// CAAWnd
//============================================================================

#ifdef CAAWnd__ShowAbility_x
FUNCTION_AT_ADDRESS(bool CAAWnd::ShowAbility(int), CAAWnd__ShowAbility);
#endif
#ifdef CAAWnd__Update_x
FUNCTION_AT_ADDRESS(void CAAWnd::Update(bool), CAAWnd__Update);
#endif
#ifdef CAAWnd__UpdateSelected_x
FUNCTION_AT_ADDRESS(void CAAWnd::UpdateSelected(void), CAAWnd__UpdateSelected);
#endif

//============================================================================
// CActionsWnd
//============================================================================

#ifdef CActionsWnd__MainPageActivate_x
FUNCTION_AT_ADDRESS(int CActionsWnd::MainPageActivate(), CActionsWnd__MainPageActivate);
#endif
#ifdef CActionsWnd__MainPageDeactivate_x
FUNCTION_AT_ADDRESS(int CActionsWnd::MainPageDeactivate(), CActionsWnd__MainPageDeactivate);
#endif
#ifdef CActionsWnd__SocialsPageDeactivate_x
FUNCTION_AT_ADDRESS(int CActionsWnd::SocialsPageDeactivate(), CActionsWnd__SocialsPageDeactivate);
#endif

//============================================================================
// CAdvancedLootWnd
//============================================================================

#ifdef CAdvancedLootWnd__DoAdvLootAction_x
FUNCTION_AT_ADDRESS(void CAdvancedLootWnd::DoAdvLootAction(int, const CXStr&, bool, int), CAdvancedLootWnd__DoAdvLootAction);
#endif
#ifdef CAdvancedLootWnd__DoSharedAdvLootAction_x
FUNCTION_AT_ADDRESS(void CAdvancedLootWnd::DoSharedAdvLootAction(AdvancedLootItem* pLootItem, const CXStr& Assignee, bool Action, int Quantity), CAdvancedLootWnd__DoSharedAdvLootAction);
#endif

//============================================================================
// CBankWnd
//============================================================================

#ifdef CBankWnd__ClickedMoneyButton_x
FUNCTION_AT_ADDRESS(void CBankWnd::ClickedMoneyButton(int, int), CBankWnd__ClickedMoneyButton);
#endif
#ifdef CBankWnd__GetBankQtyFromCoinType_x
FUNCTION_AT_ADDRESS(long CBankWnd::GetBankQtyFromCoinType(int), CBankWnd__GetBankQtyFromCoinType);
#endif
#ifdef CBankWnd__UpdateMoneyDisplay_x
FUNCTION_AT_ADDRESS(void CBankWnd::UpdateMoneyDisplay(), CBankWnd__UpdateMoneyDisplay);
#endif
#ifdef CBankWnd__GetNumBankSlots_x
FUNCTION_AT_ADDRESS(int CBankWnd::GetNumBankSlots() const, CBankWnd__GetNumBankSlots);
#endif

//============================================================================
// CBazaarSearchWnd
//============================================================================

#ifdef CBazaarSearchWnd__UpdatePlayerUpdateButton_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::UpdatePlayerUpdateButton(bool), CBazaarSearchWnd__UpdatePlayerUpdateButton);
#endif
#ifdef CBazaarSearchWnd__UpdatePlayerCombo_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::UpdatePlayerCombo(), CBazaarSearchWnd__UpdatePlayerCombo);
#endif
#ifdef CBazaarSearchWnd__Activate_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::Activate(), CBazaarSearchWnd__Activate);
#endif
#ifdef CBazaarSearchWnd__GetPriceString_x
FUNCTION_AT_ADDRESS(char* CBazaarSearchWnd::GetPriceString(unsigned long), CBazaarSearchWnd__GetPriceString);
#endif
#ifdef CBazaarSearchWnd__SortItemList_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::SortItemList(int), CBazaarSearchWnd__SortItemList);
#endif
#ifdef CBazaarSearchWnd__AddItemtoList_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::AddItemtoList(char*, unsigned long, char*, int, int), CBazaarSearchWnd__AddItemtoList);
#endif
#ifdef CBazaarSearchWnd__UpdateComboButtons_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::UpdateComboButtons(), CBazaarSearchWnd__UpdateComboButtons);
#endif
#ifdef CBazaarSearchWnd__HandleBazaarMsg_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::HandleBazaarMsg(char*, int), CBazaarSearchWnd__HandleBazaarMsg);
#endif
#ifdef CBazaarSearchWnd__doQuery_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::doQuery(), CBazaarSearchWnd__doQuery);
#endif

//============================================================================
// CBazaarWnd
//============================================================================

#ifdef CBazaarWnd__CreateBZRIniFilename_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::CreateBZRIniFilename(), CBazaarWnd__CreateBZRIniFilename);
#endif
#ifdef CBazaarWnd__AddBazaarText_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::AddBazaarText(char*, int), CBazaarWnd__AddBazaarText);
#endif
#ifdef CBazaarWnd__ReturnItemByIndex_x
FUNCTION_AT_ADDRESS(EQ_Item* CBazaarWnd::ReturnItemByIndex(int), CBazaarWnd__ReturnItemByIndex);
#endif
#ifdef CBazaarWnd__GetPriceString_x
FUNCTION_AT_ADDRESS(char* CBazaarWnd::GetPriceString(unsigned long), CBazaarWnd__GetPriceString);
#endif
#ifdef CBazaarWnd__HandleTraderMsg_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::HandleTraderMsg(char*), CBazaarWnd__HandleTraderMsg);
#endif
#ifdef CBazaarWnd__RebuildItemArray_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::RebuildItemArray(), CBazaarWnd__RebuildItemArray);
#endif
#ifdef CBazaarWnd__BuildBazaarItemArray_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::BuildBazaarItemArray(), CBazaarWnd__BuildBazaarItemArray);
#endif
#ifdef CBazaarWnd__AddEquipmentToBazaarArray_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::AddEquipmentToBazaarArray(EQ_Item*, int, unsigned long), CBazaarWnd__AddEquipmentToBazaarArray);
#endif
#ifdef CBazaarWnd__Activate_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::Activate(), CBazaarWnd__Activate);
#endif
#ifdef CBazaarWnd__UpdatePriceButtons_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::UpdatePriceButtons(), CBazaarWnd__UpdatePriceButtons);
#endif
#ifdef CBazaarWnd__StoreSelectedPrice_x
FUNCTION_AT_ADDRESS(bool CBazaarWnd::StoreSelectedPrice(), CBazaarWnd__StoreSelectedPrice);
#endif
#ifdef CBazaarWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::UpdateButtons(), CBazaarWnd__UpdateButtons);
#endif
#ifdef CBazaarWnd__SelectBazaarSlotItem_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::SelectBazaarSlotItem(int, CTextureAnimation*), CBazaarWnd__SelectBazaarSlotItem);
#endif
#ifdef CBazaarWnd__SetMoneyButton_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::SetMoneyButton(int, int), CBazaarWnd__SetMoneyButton);
#endif
#ifdef CBazaarWnd__GetQtyFromCoinType_x
FUNCTION_AT_ADDRESS(long CBazaarWnd::GetQtyFromCoinType(int), CBazaarWnd__GetQtyFromCoinType);
#endif
#ifdef CBazaarWnd__ClickedMoneyButton_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::ClickedMoneyButton(int, int), CBazaarWnd__ClickedMoneyButton);
#endif
#ifdef CBazaarWnd__GetPrice_x
FUNCTION_AT_ADDRESS(unsigned long CBazaarWnd::GetPrice(), CBazaarWnd__GetPrice);
#endif
#ifdef CBazaarWnd__UpdateBazaarListtoServer_x
FUNCTION_AT_ADDRESS(int CBazaarWnd::UpdateBazaarListtoServer(), CBazaarWnd__UpdateBazaarListtoServer);
#endif
#ifdef CBazaarWnd__ToggleBzrItemActive_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::ToggleBzrItemActive(int, bool), CBazaarWnd__ToggleBzrItemActive);
#endif

//============================================================================
// CBodyTintWnd
//============================================================================

#ifdef CBodyTintWnd__GetTintChangeCount_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::GetTintChangeCount(), CBodyTintWnd__GetTintChangeCount);
#endif
#ifdef CBodyTintWnd__GetReagentCount_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::GetReagentCount(), CBodyTintWnd__GetReagentCount);
#endif
#ifdef CBodyTintWnd__BuildRBGTooltip_x
FUNCTION_AT_ADDRESS(char* CBodyTintWnd::BuildRBGTooltip(unsigned long, char* const), CBodyTintWnd__BuildRBGTooltip);
#endif
#ifdef CBodyTintWnd__GetItemTint_x
FUNCTION_AT_ADDRESS(unsigned long CBodyTintWnd::GetItemTint(int), CBodyTintWnd__GetItemTint);
#endif
#ifdef CBodyTintWnd__SetSlotLabels_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::SetSlotLabels(bool), CBodyTintWnd__SetSlotLabels);
#endif
#ifdef CBodyTintWnd__UpdateLocalTintColor_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::UpdateLocalTintColor(unsigned long), CBodyTintWnd__UpdateLocalTintColor);
#endif
#ifdef CBodyTintWnd__UpdateMaterialTintLocal_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::UpdateMaterialTintLocal(unsigned long), CBodyTintWnd__UpdateMaterialTintLocal);
#endif
#ifdef CBodyTintWnd__UpdateLabelsAndButtons_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::UpdateLabelsAndButtons(), CBodyTintWnd__UpdateLabelsAndButtons);
#endif
#ifdef CBodyTintWnd__GetButtonTint_x
FUNCTION_AT_ADDRESS(unsigned long CBodyTintWnd::GetButtonTint(int), CBodyTintWnd__GetButtonTint);
#endif
#ifdef CBodyTintWnd__StoreModifiedBodyTints_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::StoreModifiedBodyTints(), CBodyTintWnd__StoreModifiedBodyTints);
#endif
#ifdef CBodyTintWnd__ResetToOrigBodyTints_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::ResetToOrigBodyTints(), CBodyTintWnd__ResetToOrigBodyTints);
#endif

//============================================================================
// CCastSpellWnd
//============================================================================

#ifdef CCastSpellWnd__CCastSpellWnd_x
FUNCTION_AT_ADDRESS(CCastSpellWnd::CCastSpellWnd(CXWnd*), CCastSpellWnd__CCastSpellWnd);
#endif
#ifdef CCastSpellWnd__Init_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::Init(), CCastSpellWnd__Init);
#endif
#ifdef CCastSpellWnd__Activate_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::Activate(), CCastSpellWnd__Activate);
#endif
#ifdef CCastSpellWnd__HandleSpellInfoDisplay_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::HandleSpellInfoDisplay(CXWnd*), CCastSpellWnd__HandleSpellInfoDisplay);
#endif
#ifdef CCastSpellWnd__HandleSpellLeftClick_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::HandleSpellLeftClick(int), CCastSpellWnd__HandleSpellLeftClick);
#endif
#ifdef CCastSpellWnd__Unmemorize_x
FUNCTION_AT_ADDRESS(void __cdecl CCastSpellWnd::Unmemorize(int), CCastSpellWnd__Unmemorize);
#endif
#ifdef CCastSpellWnd__UnmemorizeList_x
FUNCTION_AT_ADDRESS(void __cdecl CCastSpellWnd::UnmemorizeList(int*, int), CCastSpellWnd__UnmemorizeList);
#endif
#ifdef CCastSpellWnd__HandleSpellRightClick_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::HandleSpellRightClick(int), CCastSpellWnd__HandleSpellRightClick);
#endif
#ifdef CCastSpellWnd__ForgetMemorizedSpell_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::ForgetMemorizedSpell(int), CCastSpellWnd__ForgetMemorizedSpell);
#endif
#ifdef CCastSpellWnd__IsBardSongPlaying_x
FUNCTION_AT_ADDRESS(bool CCastSpellWnd::IsBardSongPlaying(), CCastSpellWnd__IsBardSongPlaying);
#endif
#ifdef CCastSpellWnd__RefreshSpellGemButtons_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::RefreshSpellGemButtons(), CCastSpellWnd__RefreshSpellGemButtons);
#endif
#ifdef CCastSpellWnd__UpdateSpellGems_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::UpdateSpellGems(int), CCastSpellWnd__UpdateSpellGems);
#endif
#ifdef CCastSpellWnd__UpdateSpellGemTooltips_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::UpdateSpellGemTooltips(int), CCastSpellWnd__UpdateSpellGemTooltips);
#endif
#ifdef CCastSpellWnd__GetSpellGemColor_x
FUNCTION_AT_ADDRESS(unsigned long CCastSpellWnd::GetSpellGemColor(EQ_Spell*), CCastSpellWnd__GetSpellGemColor);
#endif
#ifdef CCastSpellWnd__SpellBookDeactivating_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::SpellBookDeactivating(), CCastSpellWnd__SpellBookDeactivating);
#endif
#ifdef CCastSpellWnd__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::KeyMapUpdated(), CCastSpellWnd__KeyMapUpdated);
#endif
#ifdef CCastSpellWnd__ClearSpellCategories_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::ClearSpellCategories(), CCastSpellWnd__ClearSpellCategories);
#endif
#ifdef CCastSpellWnd__RecacheCategorizedSpells_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::RecacheCategorizedSpells(), CCastSpellWnd__RecacheCategorizedSpells);
#endif
#ifdef CCastSpellWnd__MakeSpellSelectMenu_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::MakeSpellSelectMenu(), CCastSpellWnd__MakeSpellSelectMenu);
#endif
#ifdef CCastSpellWnd__CategorizeSpell_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::CategorizeSpell(int, int, int, int), CCastSpellWnd__CategorizeSpell);
#endif
#ifdef CCastSpellWnd__RecacheLoadoutContextMenu_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::RecacheLoadoutContextMenu(), CCastSpellWnd__RecacheLoadoutContextMenu);
#endif

//============================================================================
// CCharacterCreation
//============================================================================

#ifdef CCharacterCreation__CCharacterCreation_x
FUNCTION_AT_ADDRESS(CCharacterCreation::CCharacterCreation(CXWnd*), CCharacterCreation__CCharacterCreation);
#endif
#ifdef CCharacterCreation__Init_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::Init(), CCharacterCreation__Init);
#endif
#ifdef CCharacterCreation__Activate_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::Activate(), CCharacterCreation__Activate);
#endif
#ifdef CCharacterCreation__NameGenerated_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::NameGenerated(char*), CCharacterCreation__NameGenerated);
#endif
#ifdef CCharacterCreation__DoBackButton_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::DoBackButton(), CCharacterCreation__DoBackButton);
#endif
#ifdef CCharacterCreation__DoNextButton_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::DoNextButton(), CCharacterCreation__DoNextButton);
#endif
#ifdef CCharacterCreation__DoStatButton_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::DoStatButton(int), CCharacterCreation__DoStatButton);
#endif
#ifdef CCharacterCreation__ActivateScreen_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::ActivateScreen(int), CCharacterCreation__ActivateScreen);
#endif
#ifdef CCharacterCreation__RandomizeCharacter_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::RandomizeCharacter(bool, bool), CCharacterCreation__RandomizeCharacter);
#endif
#ifdef CCharacterCreation__RandomizeFacialFeatures_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::RandomizeFacialFeatures(), CCharacterCreation__RandomizeFacialFeatures);
#endif
#ifdef CCharacterCreation__InitStats_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::InitStats(bool), CCharacterCreation__InitStats);
#endif
#ifdef CCharacterCreation__InitNewPC_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::InitNewPC(), CCharacterCreation__InitNewPC);
#endif
#ifdef CCharacterCreation__InitStartingCities_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::InitStartingCities(), CCharacterCreation__InitStartingCities);
#endif
#ifdef CCharacterCreation__SetNewPCDeityFromBtnIndex_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::SetNewPCDeityFromBtnIndex(int), CCharacterCreation__SetNewPCDeityFromBtnIndex);
#endif
#ifdef CCharacterCreation__UpdatePlayerFromNewPC_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::UpdatePlayerFromNewPC(), CCharacterCreation__UpdatePlayerFromNewPC);
#endif
#ifdef CCharacterCreation__UpdateScreenZeroButtons_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::UpdateScreenZeroButtons(bool), CCharacterCreation__UpdateScreenZeroButtons);
#endif
#ifdef CCharacterCreation__GetRaceButtonIndex_x
FUNCTION_AT_ADDRESS(int CCharacterCreation::GetRaceButtonIndex(int), CCharacterCreation__GetRaceButtonIndex);
#endif
#ifdef CCharacterCreation__GetClassButtonIndex_x
FUNCTION_AT_ADDRESS(int CCharacterCreation::GetClassButtonIndex(int), CCharacterCreation__GetClassButtonIndex);
#endif
#ifdef CCharacterCreation__IsLackingExpansion_x
FUNCTION_AT_ADDRESS(bool CCharacterCreation::IsLackingExpansion(bool, bool), CCharacterCreation__IsLackingExpansion);
#endif
#ifdef CCharacterCreation__SelectStartingCity_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::SelectStartingCity(int), CCharacterCreation__SelectStartingCity);
#endif
#ifdef CCharacterCreation__SelectedRaceButton_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::SelectedRaceButton(int), CCharacterCreation__SelectedRaceButton);
#endif
#ifdef CCharacterCreation__SelectedClassButton_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::SelectedClassButton(int), CCharacterCreation__SelectedClassButton);
#endif
#ifdef CCharacterCreation__SetPlayerAppearanceFromNewPC_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::SetPlayerAppearanceFromNewPC(EQPlayer*, EQ_PC*, bool), CCharacterCreation__SetPlayerAppearanceFromNewPC);
#endif
#ifdef CCharacterCreation__HandleNameApprovalResponse_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::HandleNameApprovalResponse(int), CCharacterCreation__HandleNameApprovalResponse);
#endif
#ifdef CCharacterCreation__SubmitNameToWorld_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::SubmitNameToWorld(), CCharacterCreation__SubmitNameToWorld);
#endif
#ifdef CCharacterCreation__FinalizeNewPCAndSendToWorld_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::FinalizeNewPCAndSendToWorld(), CCharacterCreation__FinalizeNewPCAndSendToWorld);
#endif
#ifdef CCharacterCreation__GetCharCreateText_x
FUNCTION_AT_ADDRESS(char* CCharacterCreation::GetCharCreateText(char*, int, int, int, int), CCharacterCreation__GetCharCreateText);
#endif

//============================================================================
// CCharacterListWnd
//============================================================================

#ifdef CCharacterListWnd__EnableButtons_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::EnableButtons(bool), CCharacterListWnd__EnableButtons);
#endif
#ifdef CCharacterListWnd__EnableEqMovementCommands_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::EnableEqMovementCommands(bool), CCharacterListWnd__EnableEqMovementCommands);
#endif
#ifdef CCharacterListWnd__EnterWorld_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::EnterWorld(), CCharacterListWnd__EnterWorld);
#endif
#ifdef CCharacterListWnd__Quit_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::Quit(), CCharacterListWnd__Quit);
#endif
#ifdef CCharacterListWnd__UpdateList_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::UpdateList(bool), CCharacterListWnd__UpdateList);
#endif
#ifdef CCharacterListWnd__EnterExplorationMode_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::EnterExplorationMode(), CCharacterListWnd__EnterExplorationMode);
#endif
#ifdef CCharacterListWnd__LeaveExplorationMode_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::LeaveExplorationMode(), CCharacterListWnd__LeaveExplorationMode);
#endif
#ifdef CCharacterListWnd__IsValidCharacterSelected_x
FUNCTION_AT_ADDRESS(int CCharacterListWnd::IsValidCharacterSelected(), CCharacterListWnd__IsValidCharacterSelected);
#endif
#ifdef CCharacterListWnd__IsEmptyCharacterSlot_x
FUNCTION_AT_ADDRESS(int CCharacterListWnd::IsEmptyCharacterSlot(int), CCharacterListWnd__IsEmptyCharacterSlot);
#endif
#ifdef CCharacterListWnd__NumberOfCharacters_x
FUNCTION_AT_ADDRESS(int CCharacterListWnd::NumberOfCharacters(), CCharacterListWnd__NumberOfCharacters);
#endif
#ifdef CCharacterListWnd__IsEvil_x
FUNCTION_AT_ADDRESS(unsigned char CCharacterListWnd::IsEvil(int, int, int), CCharacterListWnd__IsEvil);
#endif
#ifdef CCharacterListWnd__SelectCharacter_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::SelectCharacter(int, bool, bool), CCharacterListWnd__SelectCharacter);
#endif
#ifdef CCharacterListWnd__SetLoadZonePlayerLocation_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::SetLoadZonePlayerLocation(), CCharacterListWnd__SetLoadZonePlayerLocation);
#endif
#ifdef CCharacterListWnd__DeleteCharacter_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::DeleteCharacter(), CCharacterListWnd__DeleteCharacter);
#endif
#ifdef CCharacterListWnd__UpdateButtonNames_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::UpdateButtonNames(), CCharacterListWnd__UpdateButtonNames);
#endif
#ifdef CCharacterListWnd__SetLocationByClass_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::SetLocationByClass(EQPlayer*, bool, int), CCharacterListWnd__SetLocationByClass);
#endif
#ifdef CCharacterListWnd__CreateExplorationModePlayers_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::CreateExplorationModePlayers(), CCharacterListWnd__CreateExplorationModePlayers);
#endif
#ifdef CCharacterListWnd__RemoveExplorationModePlayers_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::RemoveExplorationModePlayers(), CCharacterListWnd__RemoveExplorationModePlayers);
#endif
#ifdef CCharacterListWnd__SetRoomLocationByIndex_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::SetRoomLocationByIndex(int, EQPlayer*), CCharacterListWnd__SetRoomLocationByIndex);
#endif
#ifdef CCharacterListWnd__SwitchModel_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::SwitchModel(EQPlayer*, unsigned char, int, unsigned char, unsigned char), CCharacterListWnd__SwitchModel);
#endif

//============================================================================
// CColorPickerWnd
//============================================================================

#ifdef CColorPickerWnd__CColorPickerWnd_x
FUNCTION_AT_ADDRESS(CColorPickerWnd::CColorPickerWnd(CXWnd*), CColorPickerWnd__CColorPickerWnd);
#endif
#ifdef CColorPickerWnd__SetTemplateColor_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::SetTemplateColor(int, unsigned long), CColorPickerWnd__SetTemplateColor);
#endif
#ifdef CColorPickerWnd__Activate_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::Activate(CXWnd*, unsigned long), CColorPickerWnd__Activate);
#endif
#ifdef CColorPickerWnd__SetCurrentColor_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::SetCurrentColor(unsigned long), CColorPickerWnd__SetCurrentColor);
#endif
#ifdef CColorPickerWnd__UpdateCurrentColor_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::UpdateCurrentColor(), CColorPickerWnd__UpdateCurrentColor);
#endif
#ifdef CColorPickerWnd__CheckMaxEditWnd_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::CheckMaxEditWnd(), CColorPickerWnd__CheckMaxEditWnd);
#endif
#ifdef CColorPickerWnd__UpdateEditWndFromSlider_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::UpdateEditWndFromSlider(CSliderWnd*, CEditWnd*, int*), CColorPickerWnd__UpdateEditWndFromSlider);
#endif
#ifdef CColorPickerWnd__UpdateSliderFromEditWnd_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::UpdateSliderFromEditWnd(CSliderWnd*, CEditWnd*, int*), CColorPickerWnd__UpdateSliderFromEditWnd);
#endif
#ifdef CColorPickerWnd__Open_x
FUNCTION_AT_ADDRESS(int CColorPickerWnd::Open(CXWnd* pwndCaller, D3DCOLOR CurrentColor), CColorPickerWnd__Open);
#endif

//============================================================================
// CCombatSkillsSelectWnd
//============================================================================

#ifdef CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x
FUNCTION_AT_ADDRESS(bool CCombatSkillsSelectWnd::ShouldDisplayThisSkill(int), CCombatSkillsSelectWnd__ShouldDisplayThisSkill);
#endif

//============================================================================
// CCompassWnd
//============================================================================

#ifdef CCompassWnd__CCompassWnd_x
FUNCTION_AT_ADDRESS(CCompassWnd::CCompassWnd(CXWnd*), CCompassWnd__CCompassWnd);
#endif
#ifdef CCompassWnd__Activate_x
FUNCTION_AT_ADDRESS(void CCompassWnd::Activate(), CCompassWnd__Activate);
#endif
#ifdef CCompassWnd__PickNewTarget_x
FUNCTION_AT_ADDRESS(void CCompassWnd::PickNewTarget(), CCompassWnd__PickNewTarget);
#endif
#ifdef CCompassWnd__SetSpeed_x
FUNCTION_AT_ADDRESS(void CCompassWnd::SetSpeed(), CCompassWnd__SetSpeed);
#endif
#ifdef CCompassWnd__SenseHeading_x
FUNCTION_AT_ADDRESS(void CCompassWnd::SenseHeading(), CCompassWnd__SenseHeading);
#endif

//============================================================================
// CConfirmationDialog
//============================================================================

#ifdef CConfirmationDialog__CConfirmationDialog_x
FUNCTION_AT_ADDRESS(CConfirmationDialog::CConfirmationDialog(CXWnd*), CConfirmationDialog__CConfirmationDialog);
#endif
#ifdef CConfirmationDialog__Init_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::Init(), CConfirmationDialog__Init);
#endif
#ifdef CConfirmationDialog__Activate_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::Activate(int, unsigned int, const char*, int, int, int, int), CConfirmationDialog__Activate);
#endif
#ifdef CConfirmationDialog__Deactivate_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::Deactivate(), CConfirmationDialog__Deactivate);
#endif
#ifdef CConfirmationDialog__ExpireCurrentDialog_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::ExpireCurrentDialog(), CConfirmationDialog__ExpireCurrentDialog);
#endif
#ifdef CConfirmationDialog__HandleButtonYesPressed_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::HandleButtonYesPressed(), CConfirmationDialog__HandleButtonYesPressed);
#endif
#ifdef CConfirmationDialog__HandleButtonNoPressed_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::HandleButtonNoPressed(), CConfirmationDialog__HandleButtonNoPressed);
#endif
#ifdef CConfirmationDialog__HandleButtonOkPressed_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::HandleButtonOkPressed(), CConfirmationDialog__HandleButtonOkPressed);
#endif
#ifdef CConfirmationDialog__ProcessYes_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::ProcessYes(), CConfirmationDialog__ProcessYes);
#endif
#ifdef CConfirmationDialog__ResetFocusOnClose_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::ResetFocusOnClose(), CConfirmationDialog__ResetFocusOnClose);
#endif
#ifdef CConfirmationDialog__ProcessNo_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::ProcessNo(int), CConfirmationDialog__ProcessNo);
#endif
#ifdef CConfirmationDialog__SetNameApprovalData_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::SetNameApprovalData(char*, char*, int, int, char*), CConfirmationDialog__SetNameApprovalData);
#endif
#ifdef CConfirmationDialog__WndNotification_x
FUNCTION_AT_ADDRESS(int CConfirmationDialog::WndNotification(CXWnd*, uint32_t, void*), CConfirmationDialog__WndNotification);
#endif

//============================================================================
// CContainerWnd
//============================================================================

// CContainerWnd
#ifdef CContainerWnd__CContainerWnd_x
FUNCTION_AT_ADDRESS(CContainerWnd::CContainerWnd(CXWnd*), CContainerWnd__CContainerWnd);
#endif
#ifdef CContainerWnd__Activate_x
FUNCTION_AT_ADDRESS(void CContainerWnd::Activate(), CContainerWnd__Activate);
#endif
#ifdef CContainerWnd__HandleCombine_x
FUNCTION_AT_ADDRESS(void CContainerWnd::HandleCombine(), CContainerWnd__HandleCombine);
#endif
#ifdef CContainerWnd__SetContainer_x
FUNCTION_AT_ADDRESS(void CContainerWnd::SetContainer(CONTENTS*& pContainer, const ItemGlobalIndex& location), CContainerWnd__SetContainer);
#endif
#ifdef CContainerWnd__CheckCloseable_x
FUNCTION_AT_ADDRESS(void CContainerWnd::CheckCloseable(), CContainerWnd__CheckCloseable);
#endif
#ifdef CContainerWnd__ContainsNoDrop_x
FUNCTION_AT_ADDRESS(bool CContainerWnd::ContainsNoDrop(), CContainerWnd__ContainsNoDrop);
#endif

// CContainerMgr
#ifdef CContainerMgr__GetFreeContainerWnd_x
FUNCTION_AT_ADDRESS(CContainerWnd* CContainerMgr::GetFreeContainerWnd(), CContainerMgr__GetFreeContainerWnd);
#endif
#ifdef CContainerMgr__OpenExperimentContainer_x
FUNCTION_AT_ADDRESS(void CContainerMgr::OpenExperimentContainer(const VePointer<CONTENTS>& pCont, const ItemGlobalIndex& Location), CContainerMgr__OpenExperimentContainer);
#endif
#ifdef CContainerMgr__CContainerMgr_x
FUNCTION_AT_ADDRESS(CContainerMgr::CContainerMgr(), CContainerMgr__CContainerMgr);
#endif
#ifdef CContainerMgr__Process_x
FUNCTION_AT_ADDRESS(void CContainerMgr::Process(), CContainerMgr__Process);
#endif
#ifdef CContainerMgr__OpenWorldContainer_x
FUNCTION_AT_ADDRESS(void CContainerMgr::OpenWorldContainer(EQ_Container*, unsigned long), CContainerMgr__OpenWorldContainer);
#endif
#ifdef CContainerMgr__SetWorldContainerItem_x
FUNCTION_AT_ADDRESS(void CContainerMgr::SetWorldContainerItem(EQ_Item*, int), CContainerMgr__SetWorldContainerItem);
#endif
#ifdef CContainerMgr__GetWorldContainerItem_x
FUNCTION_AT_ADDRESS(EQ_Item* CContainerMgr::GetWorldContainerItem(int), CContainerMgr__GetWorldContainerItem);
#endif
#ifdef CContainerMgr__ClearWorldContainerItems_x
FUNCTION_AT_ADDRESS(void CContainerMgr::ClearWorldContainerItems(), CContainerMgr__ClearWorldContainerItems);
#endif
#ifdef CContainerMgr__OpenContainer_x
FUNCTION_AT_ADDRESS(void CContainerMgr::OpenContainer(CONTENTS**, const ItemGlobalIndex&, bool), CContainerMgr__OpenContainer);
#endif
#ifdef CContainerMgr__CloseEQContainer_x
FUNCTION_AT_ADDRESS(void CContainerMgr::CloseEQContainer(EQ_Container*), CContainerMgr__CloseEQContainer);
#endif
#ifdef CContainerMgr__CloseContainer_x
FUNCTION_AT_ADDRESS(void CContainerMgr::CloseContainer(CONTENTS**, bool), CContainerMgr__CloseContainer);
#endif
#ifdef CContainerMgr__CloseAllContainers_x
FUNCTION_AT_ADDRESS(bool CContainerMgr::CloseAllContainers(), CContainerMgr__CloseAllContainers);
#endif

//============================================================================
// CContextMenuManager
//============================================================================

#ifdef CContextMenuManager__RemoveMenu_x
FUNCTION_AT_ADDRESS(int CContextMenuManager::RemoveMenu(int, bool), CContextMenuManager__RemoveMenu);
#endif
#ifdef CContextMenuManager__AddMenu_x
FUNCTION_AT_ADDRESS(int CContextMenuManager::AddMenu(CContextMenu*), CContextMenuManager__AddMenu);
#endif
#ifdef CContextMenuManager__PopupMenu_x
FUNCTION_AT_ADDRESS(int CContextMenuManager::PopupMenu(int, CXPoint const&, CXWnd*), CContextMenuManager__PopupMenu);
#endif
#ifdef CContextMenuManager__Flush_x
FUNCTION_AT_ADDRESS(void CContextMenuManager::Flush(), CContextMenuManager__Flush);
#endif
#ifdef CContextMenuManager__CreateDefaultMenu_x
FUNCTION_AT_ADDRESS(void CContextMenuManager::CreateDefaultMenu(), CContextMenuManager__CreateDefaultMenu);
#endif
#ifdef CContextMenuManager__WarnDefaultMenu_x
FUNCTION_AT_ADDRESS(void CContextMenuManager::WarnDefaultMenu(CXWnd*), CContextMenuManager__WarnDefaultMenu);
#endif
#ifdef CContextMenuManager__HandleWindowMenuCommands_x
FUNCTION_AT_ADDRESS(int CContextMenuManager::HandleWindowMenuCommands(CXWnd*, int), CContextMenuManager__HandleWindowMenuCommands);
#endif
#ifdef CContextMenuManager__GetMenu_x
FUNCTION_AT_ADDRESS(CContextMenu* CContextMenuManager::GetMenu(int), CContextMenuManager__GetMenu);
#endif

//============================================================================
// CContextMenu
//============================================================================

// todo: fixme
#ifdef CContextMenu__CContextMenu_x
//CONSTRUCTOR_AT_ADDRESS(CContextMenu::CContextMenu(CXWnd* pParent, uint32_t MenuID, const CXRect& rect), CContextMenu__CContextMenu);
#endif
#ifdef CContextMenu__dCContextMenu_x
//FUNCTION_AT_ADDRESS(CContextMenu::~CContextMenu(), CContextMenu__dCContextMenu);
#endif
#ifdef CContextMenu__AddMenuItem_x
FUNCTION_AT_ADDRESS(int CContextMenu::AddMenuItem(const CXStr&, unsigned int, bool, COLORREF, bool), CContextMenu__AddMenuItem);
#endif
#ifdef CContextMenu__AddSeparator_x
FUNCTION_AT_ADDRESS(int CContextMenu::AddSeparator(), CContextMenu__AddSeparator);
#endif
#ifdef CContextMenu__RemoveAllMenuItems_x
FUNCTION_AT_ADDRESS(void CContextMenu::RemoveAllMenuItems(), CContextMenu__RemoveAllMenuItems);
#endif
#ifdef CContextMenu__RemoveMenuItem_x
FUNCTION_AT_ADDRESS(void CContextMenu::RemoveMenuItem(int), CContextMenu__RemoveMenuItem);
#endif
#ifdef CContextMenu__EnableMenuItem_x
FUNCTION_AT_ADDRESS(void CContextMenu::EnableMenuItem(int, bool), CContextMenu__EnableMenuItem);
#endif
#ifdef CContextMenu__CheckMenuItem_x
FUNCTION_AT_ADDRESS(void CContextMenu::CheckMenuItem(int, bool, bool), CContextMenu__CheckMenuItem);
#endif
#ifdef CContextMenu__Activate_x
FUNCTION_AT_ADDRESS(void CContextMenu::Activate(CXPoint, int, int), CContextMenu__Activate);
#endif
#ifdef CContextMenu__SetMenuItem_x
FUNCTION_AT_ADDRESS(void CContextMenu::SetMenuItem(int, const CXStr&, bool, COLORREF, bool), CContextMenu__SetMenuItem);
#endif

//============================================================================
// CCursorAttachment
//============================================================================

#ifdef CCursorAttachment__CCursorAttachment_x
FUNCTION_AT_ADDRESS(CCursorAttachment::CCursorAttachment(CXWnd*), CCursorAttachment__CCursorAttachment);
#endif
#ifdef CCursorAttachment__DrawButtonText_x
FUNCTION_AT_ADDRESS(void CCursorAttachment::DrawButtonText() const, CCursorAttachment__DrawButtonText);
#endif
#ifdef CCursorAttachment__DrawQuantity_x
FUNCTION_AT_ADDRESS(void CCursorAttachment::DrawQuantity() const, CCursorAttachment__DrawQuantity);
#endif
#ifdef CCursorAttachment__IsOkToActivate_x
FUNCTION_AT_ADDRESS(bool CCursorAttachment::IsOkToActivate(int), CCursorAttachment__IsOkToActivate);
#endif
#ifdef CCursorAttachment__RemoveAttachment_x
FUNCTION_AT_ADDRESS(bool CCursorAttachment::RemoveAttachment(), CCursorAttachment__RemoveAttachment);
#endif
#ifdef CCursorAttachment__AttachToCursor_x
FUNCTION_AT_ADDRESS(void CCursorAttachment::AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation* pTABG, ECursorAttachmentType Type, int Index, const char* Assigned_Name, const char* Name, int Qty, int IconID), CCursorAttachment__AttachToCursor);
#endif
#ifdef CCursorAttachment__AttachToCursor1_x
FUNCTION_AT_ADDRESS(void CCursorAttachment::AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation* pTABG, ECursorAttachmentType Type, int Index, const EqItemGuid& ItemGuid, int ItemID, const char* Assigned_Name, const char* Name, int Qty, int IconID), CCursorAttachment__AttachToCursor1);
#endif
#ifdef CCursorAttachment__Deactivate_x
FUNCTION_AT_ADDRESS(void CCursorAttachment::Deactivate(), CCursorAttachment__Deactivate);
#endif

//============================================================================
// CFileSelectionWnd
//============================================================================

#ifdef CFileSelectionWnd__Open_x
FUNCTION_AT_ADDRESS(int CFileSelectionWnd::Open(CXWnd* pWnd, int flags), CFileSelectionWnd__Open);
#endif

//============================================================================
// CFindItemWnd
//============================================================================

#ifdef CFindItemWnd__CFindItemWnd_x
CONSTRUCTOR_AT_ADDRESS(CFindItemWnd::CFindItemWnd(CXWnd*), CFindItemWnd__CFindItemWnd);
#endif
#ifdef CFindItemWnd__Update_x
FUNCTION_AT_ADDRESS(void CFindItemWnd::Update(), CFindItemWnd__Update);
#endif
#ifdef CFindItemWnd__PickupSelectedItem_x
FUNCTION_AT_ADDRESS(void CFindItemWnd::PickupSelectedItem(), CFindItemWnd__PickupSelectedItem);
#endif

//============================================================================
// CGemsGameWnd
//============================================================================

#ifdef CGemsGameWnd__CGemsGameWnd_x
FUNCTION_AT_ADDRESS(CGemsGameWnd::CGemsGameWnd(CXWnd*), CGemsGameWnd__CGemsGameWnd);
#endif
#ifdef CGemsGameWnd__Init_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::Init(), CGemsGameWnd__Init);
#endif
#ifdef CGemsGameWnd__Activate_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::Activate(), CGemsGameWnd__Activate);
#endif
#ifdef CGemsGameWnd__Restart_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::Restart(), CGemsGameWnd__Restart);
#endif
#ifdef CGemsGameWnd__AdvanceToNextWave_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::AdvanceToNextWave(), CGemsGameWnd__AdvanceToNextWave);
#endif
#ifdef CGemsGameWnd__DoMatchScore_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::DoMatchScore(int), CGemsGameWnd__DoMatchScore);
#endif
#ifdef CGemsGameWnd__DrawSpellGem_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::DrawSpellGem(int, CXRect, int, bool) const, CGemsGameWnd__DrawSpellGem);
#endif
#ifdef CGemsGameWnd__SetPause_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::SetPause(bool), CGemsGameWnd__SetPause);
#endif
#ifdef CGemsGameWnd__TogglePause_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::TogglePause(), CGemsGameWnd__TogglePause);
#endif
#ifdef CGemsGameWnd__SetNextUpdate_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::SetNextUpdate(), CGemsGameWnd__SetNextUpdate);
#endif
#ifdef CGemsGameWnd__GetRndBlockImage_x
FUNCTION_AT_ADDRESS(int CGemsGameWnd::GetRndBlockImage(), CGemsGameWnd__GetRndBlockImage);
#endif
#ifdef CGemsGameWnd__BadSpecial_x
FUNCTION_AT_ADDRESS(bool CGemsGameWnd::BadSpecial(int) const, CGemsGameWnd__BadSpecial);
#endif
#ifdef CGemsGameWnd__ActivateSpecialMode_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::ActivateSpecialMode(int), CGemsGameWnd__ActivateSpecialMode);
#endif
#ifdef CGemsGameWnd__GetNextBlock_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::GetNextBlock(), CGemsGameWnd__GetNextBlock);
#endif
#ifdef CGemsGameWnd__MoveCurBlock_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::MoveCurBlock(int), CGemsGameWnd__MoveCurBlock);
#endif
#ifdef CGemsGameWnd__ProcessMoveCurBlock_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::ProcessMoveCurBlock(int), CGemsGameWnd__ProcessMoveCurBlock);
#endif
#ifdef CGemsGameWnd__LegalBlockMove_x
FUNCTION_AT_ADDRESS(bool CGemsGameWnd::LegalBlockMove(int, int, int, int, bool), CGemsGameWnd__LegalBlockMove);
#endif
#ifdef CGemsGameWnd__MarkHigherBlocksFalling_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::MarkHigherBlocksFalling(int, int), CGemsGameWnd__MarkHigherBlocksFalling);
#endif
#ifdef CGemsGameWnd__ClearBlock_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::ClearBlock(struct _GemsBlock*), CGemsGameWnd__ClearBlock);
#endif
#ifdef CGemsGameWnd__ClearHighScores_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::ClearHighScores(), CGemsGameWnd__ClearHighScores);
#endif
#ifdef CGemsGameWnd__ReadHighScores_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::ReadHighScores(), CGemsGameWnd__ReadHighScores);
#endif
#ifdef CGemsGameWnd__WriteHighScores_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::WriteHighScores(), CGemsGameWnd__WriteHighScores);
#endif
#ifdef CGemsGameWnd__CheckForNewHighScore_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::CheckForNewHighScore(), CGemsGameWnd__CheckForNewHighScore);
#endif
#ifdef CGemsGameWnd__ProcessMatches_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::ProcessMatches(int), CGemsGameWnd__ProcessMatches);
#endif
#ifdef CGemsGameWnd__CheckForMatches_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::CheckForMatches(int, int), CGemsGameWnd__CheckForMatches);
#endif
#ifdef CGemsGameWnd__MakeBlockDrop_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::MakeBlockDrop(int, int, int), CGemsGameWnd__MakeBlockDrop);
#endif
#ifdef CGemsGameWnd__Update_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::Update(), CGemsGameWnd__Update);
#endif
#ifdef CGemsGameWnd__UpdateDisplay_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::UpdateDisplay(), CGemsGameWnd__UpdateDisplay);
#endif

//============================================================================
// CGiveWnd
//============================================================================

#ifdef CGiveWnd__CGiveWnd_x
FUNCTION_AT_ADDRESS(CGiveWnd::CGiveWnd(CXWnd*), CGiveWnd__CGiveWnd);
#endif
#ifdef CGiveWnd__Activate_x
FUNCTION_AT_ADDRESS(void CGiveWnd::Activate(), CGiveWnd__Activate);
#endif
#ifdef CGiveWnd__UpdateGiveDisplay_x
FUNCTION_AT_ADDRESS(void CGiveWnd::UpdateGiveDisplay(), CGiveWnd__UpdateGiveDisplay);
#endif

//============================================================================
// CGroupWnd
//============================================================================

#ifdef CGroupWnd__CGroupWnd_x
FUNCTION_AT_ADDRESS(CGroupWnd::CGroupWnd(CXWnd*), CGroupWnd__CGroupWnd);
#endif
#ifdef CGroupWnd__Init_x
FUNCTION_AT_ADDRESS(void CGroupWnd::Init(), CGroupWnd__Init);
#endif
#ifdef CGroupWnd__Activate_x
FUNCTION_AT_ADDRESS(void CGroupWnd::Activate(), CGroupWnd__Activate);
#endif
#ifdef CGroupWnd__SetInvited_x
FUNCTION_AT_ADDRESS(void CGroupWnd::SetInvited(bool), CGroupWnd__SetInvited);
#endif
#ifdef CGroupWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CGroupWnd::UpdateButtons(), CGroupWnd__UpdateButtons);
#endif
#ifdef CGroupWnd__UpdateDisplay_x
FUNCTION_AT_ADDRESS(void CGroupWnd::UpdateDisplay(int Index, PSPAWNINFO groupmember, COLORREF NameColor, UINT RoleBits), CGroupWnd__UpdateDisplay);
#endif
#ifdef CGroupWnd__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void CGroupWnd::KeyMapUpdated(), CGroupWnd__KeyMapUpdated);
#endif
#ifdef CGroupWnd__CreateLocalMenu_x
FUNCTION_AT_ADDRESS(void CGroupWnd::CreateLocalMenu(), CGroupWnd__CreateLocalMenu);
#endif
#ifdef CGroupWnd__UpdateContextMenu_x
FUNCTION_AT_ADDRESS(void CGroupWnd::UpdateContextMenu(), CGroupWnd__UpdateContextMenu);
#endif

//============================================================================
// CGuildMgmtWnd
//============================================================================

#ifdef CGuildMgmtWnd__CGuildMgmtWnd_x
FUNCTION_AT_ADDRESS(CGuildMgmtWnd::CGuildMgmtWnd(CXWnd*), CGuildMgmtWnd__CGuildMgmtWnd);
#endif
#ifdef CGuildMgmtWnd__Init_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::Init(), CGuildMgmtWnd__Init);
#endif
#ifdef CGuildMgmtWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::UpdateButtons(), CGuildMgmtWnd__UpdateButtons);
#endif
#ifdef CGuildMgmtWnd__Clean_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::Clean(), CGuildMgmtWnd__Clean);
#endif
#ifdef CGuildMgmtWnd__SetMOTD_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::SetMOTD(char*, char*), CGuildMgmtWnd__SetMOTD);
#endif
#ifdef CGuildMgmtWnd__SetPlayerCount_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::SetPlayerCount(int), CGuildMgmtWnd__SetPlayerCount);
#endif
#ifdef CGuildMgmtWnd__CreatePersonalNotesFilename_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::CreatePersonalNotesFilename(), CGuildMgmtWnd__CreatePersonalNotesFilename);
#endif
#ifdef CGuildMgmtWnd__LoadPersonalNotes_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::LoadPersonalNotes(), CGuildMgmtWnd__LoadPersonalNotes);
#endif
#ifdef CGuildMgmtWnd__SavePersonalNotes_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::SavePersonalNotes(), CGuildMgmtWnd__SavePersonalNotes);
#endif
#ifdef CGuildMgmtWnd__GetPersonalNote_x
FUNCTION_AT_ADDRESS(char* CGuildMgmtWnd::GetPersonalNote(char*), CGuildMgmtWnd__GetPersonalNote);
#endif
#ifdef CGuildMgmtWnd__SetPersonalNote_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::SetPersonalNote(char*, char*), CGuildMgmtWnd__SetPersonalNote);
#endif
#ifdef CGuildMgmtWnd__AddMember_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::AddMember(GuildMember*), CGuildMgmtWnd__AddMember);
#endif
#ifdef CGuildMgmtWnd__RemoveMember_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::RemoveMember(GuildMember*), CGuildMgmtWnd__RemoveMember);
#endif
#ifdef CGuildMgmtWnd__RenameMember_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::RenameMember(char*, char*), CGuildMgmtWnd__RenameMember);
#endif
#ifdef CGuildMgmtWnd__UpdateListMember_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::UpdateListMember(GuildMember*, int), CGuildMgmtWnd__UpdateListMember);
#endif
#ifdef CGuildMgmtWnd__FindListMember_x
FUNCTION_AT_ADDRESS(int CGuildMgmtWnd::FindListMember(GuildMember*), CGuildMgmtWnd__FindListMember);
#endif
#ifdef CGuildMgmtWnd__Activate_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::Activate(), CGuildMgmtWnd__Activate);
#endif
#ifdef CGuildMgmtWnd__CleanAndRefillListWnd_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::CleanAndRefillListWnd(bool), CGuildMgmtWnd__CleanAndRefillListWnd);
#endif
#ifdef CGuildMgmtWnd__SortList_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::SortList(int, bool), CGuildMgmtWnd__SortList);
#endif
#ifdef CGuildMgmtWnd__DumpToFile_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::DumpToFile(char*), CGuildMgmtWnd__DumpToFile);
#endif
#ifdef CGuildMgmtWnd__LoadINI_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::LoadINI(), CGuildMgmtWnd__LoadINI);
#endif

//============================================================================
// CHelpWnd
//============================================================================

#ifdef CHelpWnd__CHelpWnd_x
FUNCTION_AT_ADDRESS(CHelpWnd::CHelpWnd(CXWnd*), CHelpWnd__CHelpWnd);
#endif

//============================================================================
// CHtmlWnd & components
//============================================================================

// CHtmlWnd
#ifdef CHtmlWnd__SetClientCallbacks_x
FUNCTION_AT_ADDRESS(void CHtmlWnd::SetClientCallbacks(libMozilla::ICallback*), CHtmlWnd__SetClientCallbacks);
#endif
#ifdef CHtmlWnd__AddObserver_x
FUNCTION_AT_ADDRESS(void CHtmlWnd::AddObserver(IObserver*), CHtmlWnd__AddObserver);
#endif
#ifdef CHtmlWnd__RemoveObserver_x
FUNCTION_AT_ADDRESS(void CHtmlWnd::RemoveObserver(IObserver*), CHtmlWnd__RemoveObserver);
#endif

// libMozilla::Window
#ifdef Window__getProgress_x
FUNCTION_AT_ADDRESS(float libMozilla::Window::getProgress(bool& bIsLoading), Window__getProgress);
#endif
#ifdef Window__getStatus_x
FUNCTION_AT_ADDRESS(const wchar_t* libMozilla::Window::getStatus() const, Window__getStatus);
#endif
#ifdef Window__getURI_x
FUNCTION_AT_ADDRESS(const char* libMozilla::Window::getURI() const, Window__getURI);
#endif

// CWebManager
#ifdef CWebManager__CreateHtmlWnd_x
FUNCTION_AT_ADDRESS(CHtmlWnd* CWebManager::CreateHtmlWnd(const char*, const char*, const char*, bool, const char*), CWebManager__CreateHtmlWnd);
#endif

//============================================================================
// CHotButtonWnd
//============================================================================

#ifdef CHotButtonWnd__CHotButtonWnd_x
FUNCTION_AT_ADDRESS(CHotButtonWnd::CHotButtonWnd(CXWnd*), CHotButtonWnd__CHotButtonWnd);
#endif
#ifdef CHotButtonWnd__UpdatePage_x
FUNCTION_AT_ADDRESS(void CHotButtonWnd::UpdatePage(), CHotButtonWnd__UpdatePage);
#endif
#ifdef CHotButtonWnd__DoHotButton_x
FUNCTION_AT_ADDRESS(void CHotButtonWnd::DoHotButton(int, int, int), CHotButtonWnd__DoHotButton);
#endif
#ifdef CHotButtonWnd__DoHotButtonRightClick_x
FUNCTION_AT_ADDRESS(void CHotButtonWnd::DoHotButtonRightClick(int), CHotButtonWnd__DoHotButtonRightClick);
#endif

//============================================================================
// CInspectWnd
//============================================================================

#ifdef CInspectWnd__CInspectWnd_x
FUNCTION_AT_ADDRESS(CInspectWnd::CInspectWnd(CXWnd*), CInspectWnd__CInspectWnd);
#endif
#ifdef CInspectWnd__Init_x
FUNCTION_AT_ADDRESS(void CInspectWnd::Init(), CInspectWnd__Init);
#endif
#ifdef CInspectWnd__Activate_x
FUNCTION_AT_ADDRESS(void CInspectWnd::Activate(struct _inspect*), CInspectWnd__Activate);
#endif
#ifdef CInspectWnd__AcceptInspectText_x
FUNCTION_AT_ADDRESS(void CInspectWnd::AcceptInspectText(), CInspectWnd__AcceptInspectText);
#endif
#ifdef CInspectWnd__PlayerBeingDeleted_x
FUNCTION_AT_ADDRESS(void CInspectWnd::PlayerBeingDeleted(EQPlayer*), CInspectWnd__PlayerBeingDeleted);
#endif

//============================================================================
// CInventoryWnd
//============================================================================

#ifdef CInventoryWnd__CInventoryWnd_x
FUNCTION_AT_ADDRESS(CInventoryWnd::CInventoryWnd(CXWnd*), CInventoryWnd__CInventoryWnd);
#endif
#ifdef CInventoryWnd__Init_x
FUNCTION_AT_ADDRESS(void CInventoryWnd::Init(), CInventoryWnd__Init);
#endif
#ifdef CInventoryWnd__Activate_x
FUNCTION_AT_ADDRESS(void CInventoryWnd::Activate(), CInventoryWnd__Activate);
#endif
#ifdef CInventoryWnd__DestroyHeld_x
FUNCTION_AT_ADDRESS(void CInventoryWnd::DestroyHeld(), CInventoryWnd__DestroyHeld);
#endif
#ifdef CInventoryWnd__ClickedMoneyButton_x
FUNCTION_AT_ADDRESS(void CInventoryWnd::ClickedMoneyButton(int, int), CInventoryWnd__ClickedMoneyButton);
#endif
#ifdef CInventoryWnd__GetInventoryQtyFromCoinType_x
FUNCTION_AT_ADDRESS(long CInventoryWnd::GetInventoryQtyFromCoinType(int), CInventoryWnd__GetInventoryQtyFromCoinType);
#endif
#ifdef CInventoryWnd__UpdateMoneyDisplay_x
FUNCTION_AT_ADDRESS(void CInventoryWnd::UpdateMoneyDisplay(), CInventoryWnd__UpdateMoneyDisplay);
#endif

//============================================================================
// CInvSlotWnd
//============================================================================

#ifdef CInvSlot__CInvSlot_x
FUNCTION_AT_ADDRESS(CInvSlot::CInvSlot(), CInvSlot__CInvSlot);
#endif
#ifdef CInvSlot__GetItemBase_x
FUNCTION_AT_ADDRESS(void CInvSlot::GetItemBase(CONTENTS**), CInvSlot__GetItemBase);
#endif
#ifdef CInvSlot__UpdateItem_x
FUNCTION_AT_ADDRESS(void CInvSlot::UpdateItem(), CInvSlot__UpdateItem);
#endif
#ifdef CInvSlot__SetInvSlotWnd_x
FUNCTION_AT_ADDRESS(void CInvSlot::SetInvSlotWnd(CInvSlotWnd*), CInvSlot__SetInvSlotWnd);
#endif
#ifdef CInvSlot__SetItem_x
FUNCTION_AT_ADDRESS(void CInvSlot::SetItem(EQ_Item*), CInvSlot__SetItem);
#endif
#ifdef CInvSlot__SliderComplete_x
FUNCTION_AT_ADDRESS(void CInvSlot::SliderComplete(int), CInvSlot__SliderComplete);
#endif
#ifdef CInvSlot__HandleLButtonUp_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleLButtonUp(CXPoint, bool), CInvSlot__HandleLButtonUp);
#endif
#ifdef CInvSlot__HandleLButtonHeld_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleLButtonHeld(CXPoint), CInvSlot__HandleLButtonHeld);
#endif
#ifdef CInvSlot__DoDrinkEatPoison_x
FUNCTION_AT_ADDRESS(void CInvSlot::DoDrinkEatPoison(EQ_Item*, int), CInvSlot__DoDrinkEatPoison);
#endif
#ifdef CInvSlot__HandleRButtonUp_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleRButtonUp(const CXPoint&), CInvSlot__HandleRButtonUp);
#endif
#ifdef CInvSlot__HandleRButtonHeld_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleRButtonHeld(CXPoint), CInvSlot__HandleRButtonHeld);
#endif
#ifdef CInvSlot__HandleRButtonUpAfterHeld_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleRButtonUpAfterHeld(CXPoint), CInvSlot__HandleRButtonUpAfterHeld);
#endif
#ifdef CInvSlot__IllegalBigBank_x
FUNCTION_AT_ADDRESS(bool CInvSlot::IllegalBigBank(int), CInvSlot__IllegalBigBank);
#endif
#ifdef CInvSlot__HandleLButtonDown_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleLButtonDown(CXPoint), CInvSlot__HandleLButtonDown);
#endif
#ifdef CInvSlot__HandleLButtonUpAfterHeld_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleLButtonUpAfterHeld(CXPoint), CInvSlot__HandleLButtonUpAfterHeld);
#endif
#ifdef CInvSlot__HandleRButtonDown_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleRButtonDown(CXPoint), CInvSlot__HandleRButtonDown);
#endif

//============================================================================
// CInvSlotMgr
//============================================================================

#ifdef CInvSlotMgr__Process_x
FUNCTION_AT_ADDRESS(void CInvSlotMgr::Process(), CInvSlotMgr__Process);
#endif
#ifdef CInvSlotMgr__CInvSlotMgr_x
FUNCTION_AT_ADDRESS(CInvSlotMgr::CInvSlotMgr(), CInvSlotMgr__CInvSlotMgr);
#endif
#ifdef CInvSlotMgr__MoveItem_x
FUNCTION_AT_ADDRESS(bool CInvSlotMgr::MoveItem(const ItemGlobalIndex& from, const ItemGlobalIndex& to, bool bDebugOut, bool CombineIsOk, bool MoveFromIntoToBag, bool MoveToIntoFromBag), CInvSlotMgr__MoveItem);
#endif
#ifdef CInvSlotMgr__CreateInvSlot_x
FUNCTION_AT_ADDRESS(CInvSlot* CInvSlotMgr::CreateInvSlot(CInvSlotWnd*), CInvSlotMgr__CreateInvSlot);
#endif
#ifdef CInvSlotMgr__FindInvSlot_x
FUNCTION_AT_ADDRESS(CInvSlot* CInvSlotMgr::FindInvSlot(int, int, ItemContainerInstance, bool), CInvSlotMgr__FindInvSlot);
#endif
#ifdef CInvSlotMgr__SelectSlot_x
FUNCTION_AT_ADDRESS(void CInvSlotMgr::SelectSlot(CInvSlot*), CInvSlotMgr__SelectSlot);
#endif
#ifdef CInvSlotMgr__UpdateSlots_x
FUNCTION_AT_ADDRESS(void CInvSlotMgr::UpdateSlots(), CInvSlotMgr__UpdateSlots);
#endif

//============================================================================
// CInvSlot
//============================================================================

#ifdef CInvSlotWnd__CInvSlotWnd_x
CONSTRUCTOR_AT_ADDRESS(CInvSlotWnd::CInvSlotWnd(CXWnd* pParent, uint32_t ID, CXRect rect,
	CTextureAnimation* ptaBackground, const ItemGlobalIndex& itemLocation, int ItemOffsetX, int ItemOffsetY), CInvSlotWnd__CInvSlotWnd);
#endif
#ifdef CInvSlotWnd__SetInvSlot_x
FUNCTION_AT_ADDRESS(void CInvSlotWnd::SetInvSlot(CInvSlot*), CInvSlotWnd__SetInvSlot);
#endif
#ifdef CInvSlotWnd__DrawTooltip_x
FUNCTION_AT_ADDRESS(int CInvSlotWnd::DrawTooltip(const CXWnd*) const, CInvSlotWnd__DrawTooltip);
#endif

//============================================================================
// CItemDisplayWnd
//============================================================================

#ifdef CItemDisplayWnd__UpdateStrings_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::UpdateStrings(), CItemDisplayWnd__UpdateStrings);
#endif
#ifdef CItemDisplayWnd__InsertAugmentRequest_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::InsertAugmentRequest(int AugSlot), CItemDisplayWnd__InsertAugmentRequest);
#endif
#ifdef CItemDisplayWnd__RemoveAugmentRequest_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::RemoveAugmentRequest(int AugSlot), CItemDisplayWnd__RemoveAugmentRequest);
#endif
#ifdef CItemDisplayWnd__RequestConvertItem_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::RequestConvertItem(), CItemDisplayWnd__RequestConvertItem);
#endif
#ifdef CItemDisplayWnd__CItemDisplayWnd_x
//CONSTRUCTOR_AT_ADDRESS(CItemDisplayWnd::CItemDisplayWnd(CXWnd*), CItemDisplayWnd__CItemDisplayWnd);
#endif
#ifdef CItemDisplayWnd__dCItemDisplayWnd_x
//FUNCTION_AT_ADDRESS(CItemDisplayWnd::~CItemDisplayWnd(), CItemDisplayWnd__dCItemDisplayWnd);
#endif
#ifdef CItemDisplayWnd__SetItem_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::SetItem(CONTENTS** pCont, int flags), CItemDisplayWnd__SetItem);
#endif
#ifdef CItemDisplayWnd__AboutToShow_x
FUNCTION_AT_ADDRESS(bool CItemDisplayWnd::AboutToShow(), CItemDisplayWnd__AboutToShow);
#endif
#ifdef CItemDisplayWnd__WndNotification_x
FUNCTION_AT_ADDRESS(int CItemDisplayWnd::WndNotification(CXWnd*, uint32_t, void*), CItemDisplayWnd__WndNotification);
#endif
#ifdef CItemDisplayWnd__SetItemText_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::SetItemText(char*), CItemDisplayWnd__SetItemText);
#endif
#ifdef CItemDisplayWnd__GetSizeString_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::GetSizeString(int, char*), CItemDisplayWnd__GetSizeString);
#endif
#ifdef CItemDisplayWnd__CreateRaceString_x
FUNCTION_AT_ADDRESS(CXStr CItemDisplayWnd::CreateRaceString(EQ_Equipment*), CItemDisplayWnd__CreateRaceString);
#endif
#ifdef CItemDisplayWnd__CreateClassString_x
FUNCTION_AT_ADDRESS(CXStr CItemDisplayWnd::CreateClassString(EQ_Equipment*), CItemDisplayWnd__CreateClassString);
#endif
#ifdef CItemDisplayWnd__CreateMealSizeString_x
FUNCTION_AT_ADDRESS(CXStr CItemDisplayWnd::CreateMealSizeString(EQ_Equipment*), CItemDisplayWnd__CreateMealSizeString);
#endif
#ifdef CItemDisplayWnd__CreateModString_x
FUNCTION_AT_ADDRESS(CXStr CItemDisplayWnd::CreateModString(EQ_Equipment*, int, int, int*), CItemDisplayWnd__CreateModString);
#endif
#ifdef CItemDisplayWnd__CreateEquipmentStatusString_x
FUNCTION_AT_ADDRESS(CXStr CItemDisplayWnd::CreateEquipmentStatusString(EQ_Item*), CItemDisplayWnd__CreateEquipmentStatusString);
#endif
#ifdef CItemDisplayWnd__SetSpell_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::SetSpell(int SpellID, bool HasSpellDescr, int), CItemDisplayWnd__SetSpell);
#endif

//============================================================================
// CKeyRingWnd
//============================================================================

#ifdef CKeyRingWnd__ExecuteRightClick_x
FUNCTION_AT_ADDRESS(int CKeyRingWnd::ExecuteRightClick(KeyRingType keyRingType, const VePointer<CONTENTS>& pItem, int index), CKeyRingWnd__ExecuteRightClick);
#endif

//============================================================================
// CLootWnd
//============================================================================

#ifdef CLootWnd__CLootWnd_x
FUNCTION_AT_ADDRESS(CLootWnd::CLootWnd(CXWnd*), CLootWnd__CLootWnd);
#endif
#ifdef CLootWnd__Init_x
FUNCTION_AT_ADDRESS(void CLootWnd::Init(), CLootWnd__Init);
#endif
#ifdef CLootWnd__Activate_x
FUNCTION_AT_ADDRESS(void CLootWnd::Activate(unsigned char, long, long, long, long), CLootWnd__Activate);
#endif
#ifdef CLootWnd__Deactivate1_x
FUNCTION_AT_ADDRESS(void CLootWnd::Deactivate(bool), CLootWnd__Deactivate1);
#endif
#ifdef CLootWnd__LootAll_x
FUNCTION_AT_ADDRESS(void CLootWnd::LootAll(bool), CLootWnd__LootAll);
#endif
#ifdef CLootWnd__FinalizeLoot_x
FUNCTION_AT_ADDRESS(void CLootWnd::FinalizeLoot(), CLootWnd__FinalizeLoot);
#endif
#ifdef CLootWnd__AddEquipmentToLootArray_x
FUNCTION_AT_ADDRESS(void CLootWnd::AddEquipmentToLootArray(EQ_Item*), CLootWnd__AddEquipmentToLootArray);
#endif
#ifdef CLootWnd__AddNoteToLootArray_x
FUNCTION_AT_ADDRESS(void CLootWnd::AddNoteToLootArray(EQ_Item*), CLootWnd__AddNoteToLootArray);
#endif
#ifdef CLootWnd__AddContainerToLootArray_x
FUNCTION_AT_ADDRESS(void CLootWnd::AddContainerToLootArray(EQ_Item*), CLootWnd__AddContainerToLootArray);
#endif
#ifdef CLootWnd__RequestLootSlot_x
FUNCTION_AT_ADDRESS(void CLootWnd::RequestLootSlot(int, bool), CLootWnd__RequestLootSlot);
#endif
#ifdef CLootWnd__SlotLooted_x
FUNCTION_AT_ADDRESS(void CLootWnd::SlotLooted(int), CLootWnd__SlotLooted);
#endif

//============================================================================
// CMapViewWnd
//============================================================================

// CMapViewWnd
#ifdef CMapViewWnd__IsMappingEnabled_x
FUNCTION_AT_ADDRESS(bool CMapViewWnd::IsMappingEnabled(), CMapViewWnd__IsMappingEnabled);
#endif
#ifdef CMapViewWnd__CMapViewWnd_x
CONSTRUCTOR_AT_ADDRESS(CMapViewWnd::CMapViewWnd(CXWnd*), CMapViewWnd__CMapViewWnd);
#endif
#ifdef CMapViewWnd__Init_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::Init(), CMapViewWnd__Init);
#endif
#ifdef CMapViewWnd__Activate_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::Activate(), CMapViewWnd__Activate);
#endif
#ifdef CMapViewWnd__ActivateAutoMapping_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::ActivateAutoMapping(), CMapViewWnd__ActivateAutoMapping);
#endif
#ifdef CMapViewWnd__DeactivateAutoMapping_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::DeactivateAutoMapping(), CMapViewWnd__DeactivateAutoMapping);
#endif

// MapViewMap virtual override implementations
FORWARD_FUNCTION_TO_VTABLE2(int MapViewMap::PostDraw(), MapViewMap, CXWnd, PostDraw);
FORWARD_FUNCTION_TO_VTABLE2(int MapViewMap::HandleLButtonDown(const CXPoint&, uint32_t), MapViewMap, CXWnd, HandleLButtonDown);
FORWARD_FUNCTION_TO_VTABLE2(int MapViewMap::HandleLButtonUp(const CXPoint&, uint32_t), MapViewMap, CXWnd, HandleLButtonUp);
FORWARD_FUNCTION_TO_VTABLE2(int MapViewMap::HandleLButtonUpAfterHeld(const CXPoint&, uint32_t), MapViewMap, CXWnd, HandleLButtonUpAfterHeld);
FORWARD_FUNCTION_TO_VTABLE2(int MapViewMap::HandleRButtonDown(const CXPoint&, uint32_t), MapViewMap, CXWnd, HandleRButtonDown);
FORWARD_FUNCTION_TO_VTABLE2(int MapViewMap::HandleWheelMove(const CXPoint&, int, uint32_t), MapViewMap, CXWnd, HandleWheelMove);

#ifdef MapViewMap__MapViewMap_x
CONSTRUCTOR_AT_ADDRESS(MapViewMap::MapViewMap(), MapViewMap__MapViewMap);
#endif
#ifdef CMapViewWnd__HandleLButtonDown_x
FUNCTION_AT_ADDRESS(int MapViewMap::HandleLButtonDown(const CXPoint&, uint32_t), CMapViewWnd__HandleLButtonDown);
#endif
#ifdef MapViewMap__Clear_x
FUNCTION_AT_ADDRESS(void MapViewMap::Clear(), MapViewMap__Clear);
#endif
#ifdef MapViewMap__StartLine_x
FUNCTION_AT_ADDRESS(void MapViewMap::StartLine(float, float, float), MapViewMap__StartLine);
#endif
#ifdef MapViewMap__EndLine_x
FUNCTION_AT_ADDRESS(void MapViewMap::EndLine(float, float, float), MapViewMap__EndLine);
#endif
#ifdef MapViewMap__RemoveLine_x
FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLine(), MapViewMap__RemoveLine);
#endif
#ifdef MapViewMap__AddPoint_x
FUNCTION_AT_ADDRESS(void MapViewMap::AddPoint(float, float, float), MapViewMap__AddPoint);
#endif
#ifdef MapViewMap__AddLabel_x
FUNCTION_AT_ADDRESS(void MapViewMap::AddLabel(float, float, float, unsigned long, int, char*), MapViewMap__AddLabel);
#endif
#ifdef MapViewMap__RecalcLabelExtents_x
FUNCTION_AT_ADDRESS(void MapViewMap::RecalcLabelExtents(struct _mapviewlabel*), MapViewMap__RecalcLabelExtents);
#endif
#ifdef MapViewMap__RemoveLabel_x
FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLabel(), MapViewMap__RemoveLabel);
#endif
#ifdef MapViewMap__MoveLabel_x
FUNCTION_AT_ADDRESS(void MapViewMap::MoveLabel(struct _mapviewlabel*, float, float, float), MapViewMap__MoveLabel);
#endif
#ifdef MapViewMap__CalcLabelRenderOffsets_x
FUNCTION_AT_ADDRESS(void MapViewMap::CalcLabelRenderOffsets(CXRect), MapViewMap__CalcLabelRenderOffsets);
#endif
#ifdef MapViewMap__IsLayerVisible_x
FUNCTION_AT_ADDRESS(bool MapViewMap::IsLayerVisible(int), MapViewMap__IsLayerVisible);
#endif
#ifdef MapViewMap__PointInMapViewArea_x
FUNCTION_AT_ADDRESS(bool MapViewMap::PointInMapViewArea(CXPoint, CXRect), MapViewMap__PointInMapViewArea);
#endif
#ifdef MapViewMap__PreCalcRenderValues_x
FUNCTION_AT_ADDRESS(void MapViewMap::PreCalcRenderValues(), MapViewMap__PreCalcRenderValues);
#endif
#ifdef MapViewMap__TransformPoint_x
FUNCTION_AT_ADDRESS(void MapViewMap::TransformPoint(struct T3D_XYZ*), MapViewMap__TransformPoint);
#endif
#ifdef MapViewMap__Draw_x
FUNCTION_AT_ADDRESS(void MapViewMap::Draw(CXRect), MapViewMap__Draw);
#endif
#ifdef MapViewMap__DrawClippedLine_x
FUNCTION_AT_ADDRESS(bool MapViewMap::DrawClippedLine(struct T3D_XYZ*, struct T3D_RGB, CXRect), MapViewMap__DrawClippedLine);
#endif
#ifdef MapViewMap__Save_x
FUNCTION_AT_ADDRESS(void MapViewMap::Save(char*), MapViewMap__Save);
#endif
#ifdef MapViewMap__SaveEx_x
FUNCTION_AT_ADDRESS(void MapViewMap::SaveEx(char*, int), MapViewMap__SaveEx);
#endif
#ifdef MapViewMap__Load_x
FUNCTION_AT_ADDRESS(void MapViewMap::Load(char*), MapViewMap__Load);
#endif
#ifdef MapViewMap__LoadEx_x
FUNCTION_AT_ADDRESS(bool MapViewMap::LoadEx(char*, int), MapViewMap__LoadEx);
#endif
#ifdef MapViewMap__GetCurrentColor_x
FUNCTION_AT_ADDRESS(unsigned long MapViewMap::GetCurrentColor(), MapViewMap__GetCurrentColor);
#endif
#ifdef MapViewMap__SetCurrentColor_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetCurrentColor(unsigned long), MapViewMap__SetCurrentColor);
#endif
#ifdef MapViewMap__SetMarkedLine_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetMarkedLine(struct _mapviewline*), MapViewMap__SetMarkedLine);
#endif
#ifdef MapViewMap__SetMarkedLineColor_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetMarkedLineColor(unsigned long), MapViewMap__SetMarkedLineColor);
#endif
#ifdef MapViewMap__GetMarkedLineColor_x
FUNCTION_AT_ADDRESS(unsigned long MapViewMap::GetMarkedLineColor(), MapViewMap__GetMarkedLineColor);
#endif
#ifdef MapViewMap__ClearActiveLayer_x
FUNCTION_AT_ADDRESS(void MapViewMap::ClearActiveLayer(), MapViewMap__ClearActiveLayer);
#endif
#ifdef MapViewMap__RemoveLine1_x
FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLine(struct _mapviewline*), MapViewMap__RemoveLine1);
#endif
#ifdef MapViewMap__RemoveLabel1_x
FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLabel(struct _mapviewlabel*), MapViewMap__RemoveLabel1);
#endif
#ifdef MapViewMap__JoinLinesAtIntersect_x
FUNCTION_AT_ADDRESS(void MapViewMap::JoinLinesAtIntersect(bool), MapViewMap__JoinLinesAtIntersect);
#endif
#ifdef MapViewMap__SetZoneExtents_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetZoneExtents(int, int, int, int), MapViewMap__SetZoneExtents);
#endif
#ifdef MapViewMap__SetZoom_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetZoom(float), MapViewMap__SetZoom);
#endif
#ifdef MapViewMap__GetMinZ_x
FUNCTION_AT_ADDRESS(int MapViewMap::GetMinZ(), MapViewMap__GetMinZ);
#endif
#ifdef MapViewMap__GetMaxZ_x
FUNCTION_AT_ADDRESS(int MapViewMap::GetMaxZ(), MapViewMap__GetMaxZ);
#endif
#ifdef MapViewMap__GetWorldCoordinates_x
FUNCTION_AT_ADDRESS(void MapViewMap::GetWorldCoordinates(CVector3&), MapViewMap__GetWorldCoordinates);
#endif


//============================================================================
// CMerchantWnd
//============================================================================

#ifdef CMerchantWnd__CMerchantWnd_x
FUNCTION_AT_ADDRESS(CMerchantWnd::CMerchantWnd(CXWnd*), CMerchantWnd__CMerchantWnd);
#endif
#ifdef CMerchantWnd__Activate_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::Activate(EQPlayer*, float), CMerchantWnd__Activate);
#endif
#ifdef CMerchantWnd__HandleBuy_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::HandleBuy(int), CMerchantWnd__HandleBuy);
#endif
#ifdef CMerchantWnd__HandleSell_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::HandleSell(int), CMerchantWnd__HandleSell);
#endif
#ifdef CMerchantWnd__UpdateBuySellButtons_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::UpdateBuySellButtons(), CMerchantWnd__UpdateBuySellButtons);
#endif
#ifdef CMerchantWnd__SelectBuySellSlot_x
FUNCTION_AT_ADDRESS(int CMerchantWnd::SelectBuySellSlot(const ItemGlobalIndex&, int Unknown), CMerchantWnd__SelectBuySellSlot);
#endif
#ifdef CMerchantWnd__DisplayBuyOrSellPrice_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::DisplayBuyOrSellPrice(bool, EQ_Item*), CMerchantWnd__DisplayBuyOrSellPrice);
#endif
#ifdef CMerchantWnd__PurchasePageHandler__RequestGetItem_x
//FUNCTION_AT_ADDRESS(bool CMerchantWnd::PurchasePageHandler::RequestGetItem(int), CMerchantWnd__PurchasePageHandler__RequestGetItem);
#endif
#ifdef CMerchantWnd__FinishBuyingItem_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::FinishBuyingItem(struct _sell_msg*), CMerchantWnd__FinishBuyingItem);
#endif
#ifdef CMerchantWnd__PurchasePageHandler__RequestPutItem_x
//FUNCTION_AT_ADDRESS(void CMerchantWnd::PurchasePageHandler::RequestPutItem(int), CMerchantWnd__PurchasePageHandler__RequestPutItem);
#endif
#ifdef CMerchantWnd__FinishSellingItem_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::FinishSellingItem(struct _sell_msg*), CMerchantWnd__FinishSellingItem);
#endif
#ifdef CMerchantWnd__AddEquipmentToMercArray_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::AddEquipmentToMercArray(EQ_Equipment*), CMerchantWnd__AddEquipmentToMercArray);
#endif
#ifdef CMerchantWnd__AddNoteToMercArray_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::AddNoteToMercArray(EQ_Note*), CMerchantWnd__AddNoteToMercArray);
#endif
#ifdef CMerchantWnd__AddContainerToMercArray_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::AddContainerToMercArray(EQ_Container*), CMerchantWnd__AddContainerToMercArray);
#endif
#ifdef CMerchantWnd__ClearMerchantSlot_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::ClearMerchantSlot(int), CMerchantWnd__ClearMerchantSlot);
#endif

//============================================================================
// CMusicPlayerWnd
//============================================================================

#ifdef CMusicPlayerWnd__AutoStart_x
FUNCTION_AT_ADDRESS(void CMusicPlayerWnd::AutoStart(), CMusicPlayerWnd__AutoStart);
#endif
#ifdef CMusicPlayerWnd__Update_x
FUNCTION_AT_ADDRESS(void CMusicPlayerWnd::Update(), CMusicPlayerWnd__Update);
#endif
#ifdef CMusicPlayerWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CMusicPlayerWnd::UpdateButtons(), CMusicPlayerWnd__UpdateButtons);
#endif

//============================================================================
// CNoteWnd
//============================================================================

#ifdef CNoteWnd__CheckNote_x
FUNCTION_AT_ADDRESS(bool CNoteWnd::CheckNote(EQ_Note*), CNoteWnd__CheckNote);
#endif
#ifdef CNoteWnd__SetNote_x
FUNCTION_AT_ADDRESS(void CNoteWnd::SetNote(char*), CNoteWnd__SetNote);
#endif

//============================================================================
// COptionsWnd
//============================================================================

#ifdef COptionsWnd__FillChatFilterList_x
FUNCTION_AT_ADDRESS(void COptionsWnd::FillChatFilterList(), COptionsWnd__FillChatFilterList);
#endif
#ifdef COptionsWnd__SyncGeneralPage_x
FUNCTION_AT_ADDRESS(void COptionsWnd::SyncGeneralPage(), COptionsWnd__SyncGeneralPage);
#endif
#ifdef COptionsWnd__SyncDisplayPage_x
FUNCTION_AT_ADDRESS(void COptionsWnd::SyncDisplayPage(), COptionsWnd__SyncDisplayPage);
#endif
#ifdef COptionsWnd__SyncMousePage_x
FUNCTION_AT_ADDRESS(void COptionsWnd::SyncMousePage(), COptionsWnd__SyncMousePage);
#endif
#ifdef COptionsWnd__SyncChatPage_x
FUNCTION_AT_ADDRESS(void COptionsWnd::SyncChatPage(), COptionsWnd__SyncChatPage);
#endif
#ifdef COptionsWnd__SyncColorPage_x
FUNCTION_AT_ADDRESS(void COptionsWnd::SyncColorPage(), COptionsWnd__SyncColorPage);
#endif
#ifdef COptionsWnd__InitKeyboardPage_x
FUNCTION_AT_ADDRESS(void COptionsWnd::InitKeyboardPage(), COptionsWnd__InitKeyboardPage);
#endif
#ifdef COptionsWnd__InitKeyboardAssignments_x
FUNCTION_AT_ADDRESS(void COptionsWnd::InitKeyboardAssignments(), COptionsWnd__InitKeyboardAssignments);
#endif
#ifdef COptionsWnd__RefreshCurrentKeyboardAssignmentList_x
FUNCTION_AT_ADDRESS(void COptionsWnd::RefreshCurrentKeyboardAssignmentList(), COptionsWnd__RefreshCurrentKeyboardAssignmentList);
#endif
#ifdef COptionsWnd__AddKeyboardAssignment_x
FUNCTION_AT_ADDRESS(void COptionsWnd::AddKeyboardAssignment(int, int, int), COptionsWnd__AddKeyboardAssignment);
#endif
#ifdef COptionsWnd__ResetKeysToDefault_x
FUNCTION_AT_ADDRESS(void COptionsWnd::ResetKeysToDefault(), COptionsWnd__ResetKeysToDefault);
#endif
#ifdef COptionsWnd__RedirectOnProcessFrameTo_x
FUNCTION_AT_ADDRESS(int COptionsWnd::RedirectOnProcessFrameTo(CPageWnd*), COptionsWnd__RedirectOnProcessFrameTo);
#endif
#ifdef COptionsWnd__RedirectWndNotificationTo_x
FUNCTION_AT_ADDRESS(int COptionsWnd::RedirectWndNotificationTo(CPageWnd*, CXWnd*, uint32_t, void*), COptionsWnd__RedirectWndNotificationTo);
#endif
#ifdef COptionsWnd__RedirectHandleKeyboardMsgTo_x
FUNCTION_AT_ADDRESS(int COptionsWnd::RedirectHandleKeyboardMsgTo(CPageWnd*, uint32_t, uint32_t, bool), COptionsWnd__RedirectHandleKeyboardMsgTo);
#endif
#ifdef COptionsWnd__RedirectDeactivateTo_x
FUNCTION_AT_ADDRESS(int COptionsWnd::RedirectDeactivateTo(CPageWnd*), COptionsWnd__RedirectDeactivateTo);
#endif
#ifdef COptionsWnd__GeneralPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int COptionsWnd::GeneralPageOnProcessFrame(), COptionsWnd__GeneralPageOnProcessFrame);
#endif
#ifdef COptionsWnd__GeneralPageWndNotification_x
FUNCTION_AT_ADDRESS(int COptionsWnd::GeneralPageWndNotification(CXWnd*, uint32_t, void*), COptionsWnd__GeneralPageWndNotification);
#endif
#ifdef COptionsWnd__DisplayPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int COptionsWnd::DisplayPageOnProcessFrame(), COptionsWnd__DisplayPageOnProcessFrame);
#endif
#ifdef COptionsWnd__DisplayPageWndNotification_x
FUNCTION_AT_ADDRESS(int COptionsWnd::DisplayPageWndNotification(CXWnd*, uint32_t, void*), COptionsWnd__DisplayPageWndNotification);
#endif
#ifdef COptionsWnd__MousePageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int COptionsWnd::MousePageOnProcessFrame(), COptionsWnd__MousePageOnProcessFrame);
#endif
#ifdef COptionsWnd__MousePageWndNotification_x
FUNCTION_AT_ADDRESS(int COptionsWnd::MousePageWndNotification(CXWnd*, uint32_t, void*), COptionsWnd__MousePageWndNotification);
#endif
#ifdef COptionsWnd__KeyboardPageWndNotification_x
FUNCTION_AT_ADDRESS(int COptionsWnd::KeyboardPageWndNotification(CXWnd*, uint32_t, void*), COptionsWnd__KeyboardPageWndNotification);
#endif
#ifdef COptionsWnd__KeyboardPageHandleKeyboardMsg_x
FUNCTION_AT_ADDRESS(int COptionsWnd::KeyboardPageHandleKeyboardMsg(uint32_t, uint32_t, bool), COptionsWnd__KeyboardPageHandleKeyboardMsg);
#endif
#ifdef COptionsWnd__KeyboardPageDeactivate_x
FUNCTION_AT_ADDRESS(int COptionsWnd::KeyboardPageDeactivate(), COptionsWnd__KeyboardPageDeactivate);
#endif
#ifdef COptionsWnd__KeyboardPageCancelKeypressAssignment_x
FUNCTION_AT_ADDRESS(void COptionsWnd::KeyboardPageCancelKeypressAssignment(), COptionsWnd__KeyboardPageCancelKeypressAssignment);
#endif
#ifdef COptionsWnd__ChatPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int COptionsWnd::ChatPageOnProcessFrame(), COptionsWnd__ChatPageOnProcessFrame);
#endif
#ifdef COptionsWnd__ColorPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int COptionsWnd::ColorPageOnProcessFrame(), COptionsWnd__ColorPageOnProcessFrame);
#endif
#ifdef COptionsWnd__ChatPageWndNotification_x
FUNCTION_AT_ADDRESS(int COptionsWnd::ChatPageWndNotification(CXWnd*, uint32_t, void*), COptionsWnd__ChatPageWndNotification);
#endif
#ifdef COptionsWnd__ColorPageWndNotification_x
FUNCTION_AT_ADDRESS(int COptionsWnd::ColorPageWndNotification(CXWnd*, uint32_t, void*), COptionsWnd__ColorPageWndNotification);
#endif
#ifdef COptionsWnd__RestoreDefaultColors_x
FUNCTION_AT_ADDRESS(void COptionsWnd::RestoreDefaultColors(), COptionsWnd__RestoreDefaultColors);
#endif
#ifdef COptionsWnd__SetBagOptions_x
FUNCTION_AT_ADDRESS(void COptionsWnd::SetBagOptions(int, int), COptionsWnd__SetBagOptions);
#endif
#ifdef COptionsWnd__KeyboardPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int COptionsWnd::KeyboardPageOnProcessFrame(), COptionsWnd__KeyboardPageOnProcessFrame);
#endif

//============================================================================
// CPetInfoWnd
//============================================================================

//============================================================================
// CPlayerNotesWnd
//============================================================================

#ifdef CPlayerNotesWnd__SaveNotes_x
FUNCTION_AT_ADDRESS(void CPlayerNotesWnd::SaveNotes(), CPlayerNotesWnd__SaveNotes);
#endif
#ifdef CPlayerNotesWnd__AppendText_x
FUNCTION_AT_ADDRESS(void CPlayerNotesWnd::AppendText(char*), CPlayerNotesWnd__AppendText);
#endif

//============================================================================
// CPlayerWnd
//============================================================================

#ifdef CPlayerWnd__CreateLocalMenu_x
FUNCTION_AT_ADDRESS(void CPlayerWnd::CreateLocalMenu(), CPlayerWnd__CreateLocalMenu);
#endif
#ifdef CPlayerWnd__UpdateContextMenu_x
FUNCTION_AT_ADDRESS(void CPlayerWnd::UpdateContextMenu(), CPlayerWnd__UpdateContextMenu);
#endif

//============================================================================
// CQuantityWnd
//============================================================================

#ifdef CQuantityWnd__CheckMaxEditWnd_x
FUNCTION_AT_ADDRESS(void CQuantityWnd::CheckMaxEditWnd(), CQuantityWnd__CheckMaxEditWnd);
#endif
#ifdef CQuantityWnd__Open_x
FUNCTION_AT_ADDRESS(void CQuantityWnd::Open(CXWnd*, int, int, int, int, int, int, bool), CQuantityWnd__Open);
#endif
#ifdef CQuantityWnd__UpdateEditWndFromSlider_x
FUNCTION_AT_ADDRESS(void CQuantityWnd::UpdateEditWndFromSlider(), CQuantityWnd__UpdateEditWndFromSlider);
#endif
#ifdef CQuantityWnd__UpdateSliderFromEditWnd_x
FUNCTION_AT_ADDRESS(void CQuantityWnd::UpdateSliderFromEditWnd(), CQuantityWnd__UpdateSliderFromEditWnd);
#endif

//============================================================================
// CRaidOptionsWnd
//============================================================================

#ifdef CRaidOptionsWnd__AddLooterToList_x
FUNCTION_AT_ADDRESS(void CRaidOptionsWnd::AddLooterToList(char*), CRaidOptionsWnd__AddLooterToList);
#endif
#ifdef CRaidOptionsWnd__ClearLooterList_x
FUNCTION_AT_ADDRESS(void CRaidOptionsWnd::ClearLooterList(), CRaidOptionsWnd__ClearLooterList);
#endif
#ifdef CRaidOptionsWnd__UpdateComponents_x
FUNCTION_AT_ADDRESS(void CRaidOptionsWnd::UpdateComponents(), CRaidOptionsWnd__UpdateComponents);
#endif
#ifdef CRaidOptionsWnd__InitializeClassColors_x
FUNCTION_AT_ADDRESS(void CRaidOptionsWnd::InitializeClassColors(), CRaidOptionsWnd__InitializeClassColors);
#endif

//============================================================================
// CRaidWnd
//============================================================================

#ifdef CRaidWnd__AddPlayertoList_x
FUNCTION_AT_ADDRESS(void CRaidWnd::AddPlayertoList(char*, char*, char*, char*, int, int, bool), CRaidWnd__AddPlayertoList);
#endif
#ifdef CRaidWnd__RemovePlayerFromList_x
FUNCTION_AT_ADDRESS(void CRaidWnd::RemovePlayerFromList(char*, int), CRaidWnd__RemovePlayerFromList);
#endif
#ifdef CRaidWnd__SetRaidCount_x
FUNCTION_AT_ADDRESS(void CRaidWnd::SetRaidCount(int), CRaidWnd__SetRaidCount);
#endif
#ifdef CRaidWnd__ClearPlayerList_x
FUNCTION_AT_ADDRESS(void CRaidWnd::ClearPlayerList(), CRaidWnd__ClearPlayerList);
#endif
#ifdef CRaidWnd__AddSeparator_x
FUNCTION_AT_ADDRESS(void CRaidWnd::AddSeparator(), CRaidWnd__AddSeparator);
#endif
#ifdef CRaidWnd__SetRaidMemberRank_x
FUNCTION_AT_ADDRESS(void CRaidWnd::SetRaidMemberRank(char*, char*, int), CRaidWnd__SetRaidMemberRank);
#endif
#ifdef CRaidWnd__ChangePosition_x
FUNCTION_AT_ADDRESS(void CRaidWnd::ChangePosition(char*, int, int, int, bool), CRaidWnd__ChangePosition);
#endif
#ifdef CRaidWnd__ChangeRaidGroupLeader_x
FUNCTION_AT_ADDRESS(void CRaidWnd::ChangeRaidGroupLeader(char*, int, char*), CRaidWnd__ChangeRaidGroupLeader);
#endif
#ifdef CRaidWnd__UpdateMemberName_x
FUNCTION_AT_ADDRESS(void CRaidWnd::UpdateMemberName(char*, char*, int), CRaidWnd__UpdateMemberName);
#endif
#ifdef CRaidWnd__SetRaidTarget_x
FUNCTION_AT_ADDRESS(void CRaidWnd::SetRaidTarget(char*, int, char*, int), CRaidWnd__SetRaidTarget);
#endif
#ifdef CRaidWnd__UpdateLevelAverage_x
FUNCTION_AT_ADDRESS(void CRaidWnd::UpdateLevelAverage(int), CRaidWnd__UpdateLevelAverage);
#endif
#ifdef CRaidWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CRaidWnd::UpdateButtons(), CRaidWnd__UpdateButtons);
#endif
#ifdef CRaidWnd__InitializeClassColors_x
FUNCTION_AT_ADDRESS(void CRaidWnd::InitializeClassColors(), CRaidWnd__InitializeClassColors);
#endif
#ifdef CRaidWnd__SetPlayerClassColor_x
FUNCTION_AT_ADDRESS(void CRaidWnd::SetPlayerClassColor(int, int, int), CRaidWnd__SetPlayerClassColor);
#endif
#ifdef CRaidWnd__SetPlayerClassColor1_x
FUNCTION_AT_ADDRESS(void CRaidWnd::SetPlayerClassColor(char*, int, int), CRaidWnd__SetPlayerClassColor1);
#endif
#ifdef CRaidWnd__SetClassColor_x
FUNCTION_AT_ADDRESS(void CRaidWnd::SetClassColor(int, unsigned long), CRaidWnd__SetClassColor);
#endif
#ifdef CRaidWnd__ResortRaidGroupList_x
FUNCTION_AT_ADDRESS(void CRaidWnd::ResortRaidGroupList(int, int), CRaidWnd__ResortRaidGroupList);
#endif
#ifdef CRaidWnd__FindOpenIndexInGroup_x
FUNCTION_AT_ADDRESS(int CRaidWnd::FindOpenIndexInGroup(int), CRaidWnd__FindOpenIndexInGroup);
#endif
#ifdef CRaidWnd__FindIndexNotInGroupList_x
FUNCTION_AT_ADDRESS(int CRaidWnd::FindIndexNotInGroupList(char*), CRaidWnd__FindIndexNotInGroupList);
#endif
#ifdef CRaidWnd__FindPlayerIndexInGroup_x
FUNCTION_AT_ADDRESS(int CRaidWnd::FindPlayerIndexInGroup(char*, int), CRaidWnd__FindPlayerIndexInGroup);
#endif

//============================================================================
// CSelectorWnd
//============================================================================

#ifdef CSelectorWnd__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void CSelectorWnd::KeyMapUpdated(), CSelectorWnd__KeyMapUpdated);
#endif

//============================================================================
// CSkillsSelectWnd
//============================================================================

#ifdef CSkillsSelectWnd__Refresh_x
FUNCTION_AT_ADDRESS(void CSkillsSelectWnd::Refresh(), CSkillsSelectWnd__Refresh);
#endif
#ifdef CSkillsSelectWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void CSkillsSelectWnd::UpdateAll(), CSkillsSelectWnd__UpdateAll);
#endif
#ifdef CSkillsSelectWnd__UpdateSkill_x
FUNCTION_AT_ADDRESS(void CSkillsSelectWnd::UpdateSkill(int), CSkillsSelectWnd__UpdateSkill);
#endif
#ifdef CSkillsSelectWnd__SetTypesToDisplay_x
FUNCTION_AT_ADDRESS(void CSkillsSelectWnd::SetTypesToDisplay(int), CSkillsSelectWnd__SetTypesToDisplay);
#endif

//============================================================================
// CSkillsWnd
//============================================================================

#ifdef CSkillsWnd__SkillImproveOccurred_x
FUNCTION_AT_ADDRESS(void CSkillsWnd::SkillImproveOccurred(int), CSkillsWnd__SkillImproveOccurred);
#endif
#ifdef CSkillsWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void CSkillsWnd::UpdateAll(), CSkillsWnd__UpdateAll);
#endif
#ifdef CSkillsWnd__UpdateSkill_x
FUNCTION_AT_ADDRESS(void CSkillsWnd::UpdateSkill(int), CSkillsWnd__UpdateSkill);
#endif

//============================================================================
// CStoryWnd
//============================================================================

#ifdef CStoryWnd__SaveIni_x
FUNCTION_AT_ADDRESS(void CStoryWnd::SaveIni(), CStoryWnd__SaveIni);
#endif
#ifdef CStoryWnd__ShowAuto_x
FUNCTION_AT_ADDRESS(bool CStoryWnd::ShowAuto(), CStoryWnd__ShowAuto);
#endif
#ifdef CStoryWnd__HasNew_x
FUNCTION_AT_ADDRESS(bool CStoryWnd::HasNew(), CStoryWnd__HasNew);
#endif
#ifdef CStoryWnd__Activate_x
FUNCTION_AT_ADDRESS(void CStoryWnd::Activate(), CStoryWnd__Activate);
#endif
#ifdef CStoryWnd__SelectOldestNew_x
FUNCTION_AT_ADDRESS(void CStoryWnd::SelectOldestNew(), CStoryWnd__SelectOldestNew);
#endif
#ifdef CStoryWnd__SelectIndex_x
FUNCTION_AT_ADDRESS(void CStoryWnd::SelectIndex(int), CStoryWnd__SelectIndex);
#endif

//============================================================================
// CSocialEditWnd
//============================================================================

#ifdef CSocialEditWnd__ClickedAccept_x
FUNCTION_AT_ADDRESS(void CSocialEditWnd::ClickedAccept(), CSocialEditWnd__ClickedAccept);
#endif
#ifdef CSocialEditWnd__ClickedClear_x
FUNCTION_AT_ADDRESS(void CSocialEditWnd::ClickedClear(), CSocialEditWnd__ClickedClear);
#endif
#ifdef CSocialEditWnd__ClickedTextColorButton_x
FUNCTION_AT_ADDRESS(void CSocialEditWnd::ClickedTextColorButton(int), CSocialEditWnd__ClickedTextColorButton);
#endif
#ifdef CSocialEditWnd__GetSocialTextColor_x
FUNCTION_AT_ADDRESS(unsigned long CSocialEditWnd::GetSocialTextColor(int), CSocialEditWnd__GetSocialTextColor);
#endif
#ifdef CSocialEditWnd__UpdateControlsFromSocial_x
FUNCTION_AT_ADDRESS(void CSocialEditWnd::UpdateControlsFromSocial(), CSocialEditWnd__UpdateControlsFromSocial);
#endif

//============================================================================
// CSpellBookWnd
//============================================================================

#ifdef CSpellBookWnd__GetBookSlot_x
FUNCTION_AT_ADDRESS(int __cdecl CSpellBookWnd::GetBookSlot(int), CSpellBookWnd__GetBookSlot);
#endif
#ifdef CSpellBookWnd__MemorizeSet_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::MemorizeSet(int*, int), CSpellBookWnd__MemorizeSet);
#endif
#ifdef CSpellBookWnd__ContinueSetMem_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::ContinueSetMem(), CSpellBookWnd__ContinueSetMem);
#endif
#ifdef CSpellBookWnd__DelayedSpellMem_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::DelayedSpellMem(int, int, int), CSpellBookWnd__DelayedSpellMem);
#endif
#ifdef CSpellBookWnd__EndSetMem_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::EndSetMem(), CSpellBookWnd__EndSetMem);
#endif
#ifdef CSpellBookWnd__AutoMemSpell_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::AutoMemSpell(int, int), CSpellBookWnd__AutoMemSpell);
#endif
#ifdef CSpellBookWnd__HandleLeftClickOnSpell_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::HandleLeftClickOnSpell(int), CSpellBookWnd__HandleLeftClickOnSpell);
#endif
#ifdef CSpellBookWnd__HandleRightClickOnSpell_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::HandleRightClickOnSpell(int), CSpellBookWnd__HandleRightClickOnSpell);
#endif
#ifdef CSpellBookWnd__CanStartMemming_x
FUNCTION_AT_ADDRESS(bool CSpellBookWnd::CanStartMemming(int), CSpellBookWnd__CanStartMemming);
#endif
#ifdef CSpellBookWnd__StartSpellMemorizationDrag_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::StartSpellMemorizationDrag(int, CButtonWnd*), CSpellBookWnd__StartSpellMemorizationDrag);
#endif
#ifdef CSpellBookWnd__StartSpellMemorization_x
FUNCTION_AT_ADDRESS(bool CSpellBookWnd::StartSpellMemorization(int, int, bool), CSpellBookWnd__StartSpellMemorization);
#endif
#ifdef CSpellBookWnd__FinishMemorizing_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::FinishMemorizing(int, int), CSpellBookWnd__FinishMemorizing);
#endif
#ifdef CSpellBookWnd__GetSpellMemTicksLeft_x
FUNCTION_AT_ADDRESS(int CSpellBookWnd::GetSpellMemTicksLeft(), CSpellBookWnd__GetSpellMemTicksLeft);
#endif
#ifdef CSpellBookWnd__StartSpellScribe_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::StartSpellScribe(int), CSpellBookWnd__StartSpellScribe);
#endif
#ifdef CSpellBookWnd__FinishScribing_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::FinishScribing(int, int), CSpellBookWnd__FinishScribing);
#endif
#ifdef CSpellBookWnd__GetSpellScribeTicksLeft_x
FUNCTION_AT_ADDRESS(int CSpellBookWnd::GetSpellScribeTicksLeft(), CSpellBookWnd__GetSpellScribeTicksLeft);
#endif
#ifdef CSpellBookWnd__SwapSpellBookSlots_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::SwapSpellBookSlots(int, int), CSpellBookWnd__SwapSpellBookSlots);
#endif
#ifdef CSpellBookWnd__HandleSpellInfoDisplay_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::HandleSpellInfoDisplay(CXWnd*), CSpellBookWnd__HandleSpellInfoDisplay);
#endif
#ifdef CSpellBookWnd__DisplaySpellInfo_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::DisplaySpellInfo(int), CSpellBookWnd__DisplaySpellInfo);
#endif
#ifdef CSpellBookWnd__TurnToPage_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::TurnToPage(int), CSpellBookWnd__TurnToPage);
#endif
#ifdef CSpellBookWnd__UpdateSpellBookDisplay_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::UpdateSpellBookDisplay(), CSpellBookWnd__UpdateSpellBookDisplay);
#endif
#ifdef CSpellBookWnd__StopSpellBookAction_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::StopSpellBookAction(), CSpellBookWnd__StopSpellBookAction);
#endif
#ifdef CSpellBookWnd__GetSpellDeletionConfirmation_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::GetSpellDeletionConfirmation(int), CSpellBookWnd__GetSpellDeletionConfirmation);
#endif
#ifdef CSpellBookWnd__RequestSpellDeletion_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::RequestSpellDeletion(int), CSpellBookWnd__RequestSpellDeletion);
#endif
#ifdef CSpellBookWnd__DeleteSpellFromBook_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::DeleteSpellFromBook(int, int), CSpellBookWnd__DeleteSpellFromBook);
#endif

//============================================================================
// CSpellGemWnd
//============================================================================

#ifdef CSpellGemWnd__CSpellGemWnd_x
FUNCTION_AT_ADDRESS(CSpellGemWnd::CSpellGemWnd(CXWnd*, uint32_t, CXRect, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, int, int, unsigned long), CSpellGemWnd__CSpellGemWnd);
#endif
#ifdef CSpellGemWnd__SetSpellIconIndex_x
FUNCTION_AT_ADDRESS(void CSpellGemWnd::SetSpellIconIndex(int), CSpellGemWnd__SetSpellIconIndex);
#endif
#ifdef CSpellGemWnd__SetSpellGemTint_x
FUNCTION_AT_ADDRESS(void CSpellGemWnd::SetSpellGemTint(unsigned long), CSpellGemWnd__SetSpellGemTint);
#endif
#ifdef CSpellGemWnd__SetGemTintStage_x
FUNCTION_AT_ADDRESS(void CSpellGemWnd::SetGemTintStage(int), CSpellGemWnd__SetGemTintStage);
#endif
#ifdef CSpellGemWnd__SetCheck_x
FUNCTION_AT_ADDRESS(void CSpellGemWnd::SetCheck(bool), CSpellGemWnd__SetCheck);
#endif

//============================================================================
// CTargetWnd
//============================================================================

#ifdef CTargetWnd__RefreshTargetBuffs_x
FUNCTION_AT_ADDRESS(void CTargetWnd::RefreshTargetBuffs(CUnSerializeBuffer&), CTargetWnd__RefreshTargetBuffs);
#endif
#ifdef CTargetWnd__HandleBuffRemoveRequest_x
FUNCTION_AT_ADDRESS(void CTargetWnd::HandleBuffRemoveRequest(CXWnd*), CTargetWnd__HandleBuffRemoveRequest);
#endif
#ifdef CTargetWnd__GetBuffCaster_x
FUNCTION_AT_ADDRESS(CXStr* CTargetWnd::GetBuffCaster(int), CTargetWnd__GetBuffCaster);
#endif


//============================================================================
// CTaskWnd
//============================================================================

#ifdef CTaskWnd__UpdateTaskTimers_x
FUNCTION_AT_ADDRESS(int CTaskWnd::UpdateTaskTimers(unsigned long), CTaskWnd__UpdateTaskTimers);
#endif
#ifdef CTaskWnd__ConfirmAbandonTask_x
FUNCTION_AT_ADDRESS(void CTaskWnd::ConfirmAbandonTask(int), CTaskWnd__ConfirmAbandonTask);
#endif

//============================================================================
// CTextEntryWnd
//============================================================================

#ifdef CTextEntryWnd__CTextEntryWnd_x
FUNCTION_AT_ADDRESS(CTextEntryWnd::CTextEntryWnd(CXWnd*), CTextEntryWnd__CTextEntryWnd);
#endif
#ifdef CTextEntryWnd__Activate_x
FUNCTION_AT_ADDRESS(void CTextEntryWnd::Activate(CXWnd*, int, char*, int, int, char*), CTextEntryWnd__Activate);
#endif
#ifdef CTextEntryWnd__Callback_x
FUNCTION_AT_ADDRESS(void CTextEntryWnd::Callback(bool), CTextEntryWnd__Callback);
#endif
#ifdef CTextEntryWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CTextEntryWnd::UpdateButtons(), CTextEntryWnd__UpdateButtons);
#endif
#ifdef CTextEntryWnd__GetEntryText_x
FUNCTION_AT_ADDRESS(CXStr CTextEntryWnd::GetEntryText(), CTextEntryWnd__GetEntryText);
#endif

//============================================================================
// CTipWnd
//============================================================================

#ifdef CTipWnd__CTipWnd_x
FUNCTION_AT_ADDRESS(CTipWnd::CTipWnd(CXWnd*, int), CTipWnd__CTipWnd);
#endif
#ifdef CTipWnd__Activate_x
FUNCTION_AT_ADDRESS(bool CTipWnd::Activate(int, bool), CTipWnd__Activate);
#endif
#ifdef CTipWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CTipWnd::UpdateButtons(), CTipWnd__UpdateButtons);
#endif
#ifdef CTipWnd__InitializeTipSettings_x
FUNCTION_AT_ADDRESS(void CTipWnd::InitializeTipSettings(), CTipWnd__InitializeTipSettings);
#endif
#ifdef CTipWnd__CleanDayTips_x
FUNCTION_AT_ADDRESS(void CTipWnd::CleanDayTips(), CTipWnd__CleanDayTips);
#endif
#ifdef CTipWnd__SelectRandomTip_x
FUNCTION_AT_ADDRESS(int CTipWnd::SelectRandomTip(), CTipWnd__SelectRandomTip);
#endif
#ifdef CTipWnd__SetTOTD_x
FUNCTION_AT_ADDRESS(void CTipWnd::SetTOTD(int), CTipWnd__SetTOTD);
#endif
#ifdef CTipWnd__IsRecentTOTD_x
FUNCTION_AT_ADDRESS(bool CTipWnd::IsRecentTOTD(int), CTipWnd__IsRecentTOTD);
#endif
#ifdef CTipWnd__AddContextTip_x
FUNCTION_AT_ADDRESS(void CTipWnd::AddContextTip(int), CTipWnd__AddContextTip);
#endif
#ifdef CTipWnd__ShowHistoryTip_x
FUNCTION_AT_ADDRESS(void CTipWnd::ShowHistoryTip(int), CTipWnd__ShowHistoryTip);
#endif
#ifdef CTipWnd__LoadINISettings_x
FUNCTION_AT_ADDRESS(void CTipWnd::LoadINISettings(), CTipWnd__LoadINISettings);
#endif
#ifdef CTipWnd__LoadDayTips_x
FUNCTION_AT_ADDRESS(void CTipWnd::LoadDayTips(), CTipWnd__LoadDayTips);
#endif

//============================================================================
// CTrackingWnd
//============================================================================

#ifdef CTrackingWnd__CTrackingWnd_x
FUNCTION_AT_ADDRESS(CTrackingWnd::CTrackingWnd(CXWnd*), CTrackingWnd__CTrackingWnd);
#endif
#ifdef CTrackingWnd__Init_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::Init(), CTrackingWnd__Init);
#endif
#ifdef CTrackingWnd__Activate_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::Activate(), CTrackingWnd__Activate);
#endif
#ifdef CTrackingWnd__NotifyServerOfTrackingTarget_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::NotifyServerOfTrackingTarget(int), CTrackingWnd__NotifyServerOfTrackingTarget);
#endif
#ifdef CTrackingWnd__UpdateTrackingControls_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::UpdateTrackingControls(), CTrackingWnd__UpdateTrackingControls);
#endif
#ifdef CTrackingWnd__GetTrackColor_x
FUNCTION_AT_ADDRESS(unsigned long CTrackingWnd::GetTrackColor(int), CTrackingWnd__GetTrackColor);
#endif
#ifdef CTrackingWnd__UpdateTrackingList_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::UpdateTrackingList(bool), CTrackingWnd__UpdateTrackingList);
#endif
#ifdef CTrackingWnd__GenerateTrackingList_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::GenerateTrackingList(), CTrackingWnd__GenerateTrackingList);
#endif
#ifdef CTrackingWnd__SetTrackingList_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::SetTrackingList(struct TrackingHit*, int), CTrackingWnd__SetTrackingList);
#endif
#ifdef CTrackingWnd__DoTrackSort_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::DoTrackSort(bool), CTrackingWnd__DoTrackSort);
#endif
#ifdef CTrackingWnd__DoTrackFilter_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::DoTrackFilter(bool), CTrackingWnd__DoTrackFilter);
#endif
#ifdef CTrackingWnd__RemovePlayerFromTracking_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::RemovePlayerFromTracking(EQPlayer*), CTrackingWnd__RemovePlayerFromTracking);
#endif
#ifdef CTrackingWnd__RemovePlayerFromTracking1_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::RemovePlayerFromTracking(int), CTrackingWnd__RemovePlayerFromTracking1);
#endif
#ifdef CTrackingWnd__RemoveFromListWndByData_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::RemoveFromListWndByData(unsigned int), CTrackingWnd__RemoveFromListWndByData);
#endif
#ifdef CTrackingWnd__GetListIdByData_x
FUNCTION_AT_ADDRESS(int CTrackingWnd::GetListIdByData(unsigned int), CTrackingWnd__GetListIdByData);
#endif

//============================================================================
// CTradeWnd
//============================================================================

#ifdef CTradeWnd__CTradeWnd_x
FUNCTION_AT_ADDRESS(CTradeWnd::CTradeWnd(CXWnd*), CTradeWnd__CTradeWnd);
#endif
#ifdef CTradeWnd__Init_x
FUNCTION_AT_ADDRESS(void CTradeWnd::Init(), CTradeWnd__Init);
#endif
#ifdef CTradeWnd__Activate_x
FUNCTION_AT_ADDRESS(void CTradeWnd::Activate(EQPlayer*, bool), CTradeWnd__Activate);
#endif
#ifdef CTradeWnd__ClickedCancelButton_x
FUNCTION_AT_ADDRESS(void CTradeWnd::ClickedCancelButton(), CTradeWnd__ClickedCancelButton);
#endif
#ifdef CTradeWnd__ClickedTradeButton_x
FUNCTION_AT_ADDRESS(void CTradeWnd::ClickedTradeButton(), CTradeWnd__ClickedTradeButton);
#endif
#ifdef CTradeWnd__ClickedMoneyButton_x
FUNCTION_AT_ADDRESS(void CTradeWnd::ClickedMoneyButton(int), CTradeWnd__ClickedMoneyButton);
#endif
#ifdef CTradeWnd__UpdateTradeDisplay_x
FUNCTION_AT_ADDRESS(void CTradeWnd::UpdateTradeDisplay(), CTradeWnd__UpdateTradeDisplay);
#endif
#ifdef CTradeWnd__IsMyTradeSlot_x
FUNCTION_AT_ADDRESS(bool CTradeWnd::IsMyTradeSlot(int, bool*), CTradeWnd__IsMyTradeSlot);
#endif
#ifdef CTradeWnd__TradeItemChanged_x
FUNCTION_AT_ADDRESS(void CTradeWnd::TradeItemChanged(int, int), CTradeWnd__TradeItemChanged);
#endif
#ifdef CTradeWnd__CompleteTrade_x
FUNCTION_AT_ADDRESS(void CTradeWnd::CompleteTrade(), CTradeWnd__CompleteTrade);
#endif
#ifdef CTradeWnd__AddEquipmentToHisTradeArray_x
FUNCTION_AT_ADDRESS(void CTradeWnd::AddEquipmentToHisTradeArray(EQ_Equipment*), CTradeWnd__AddEquipmentToHisTradeArray);
#endif
#ifdef CTradeWnd__AddNoteToHisTradeArray_x
FUNCTION_AT_ADDRESS(void CTradeWnd::AddNoteToHisTradeArray(EQ_Note*), CTradeWnd__AddNoteToHisTradeArray);
#endif
#ifdef CTradeWnd__AddContainerToHisTradeArray_x
FUNCTION_AT_ADDRESS(void CTradeWnd::AddContainerToHisTradeArray(EQ_Container*), CTradeWnd__AddContainerToHisTradeArray);
#endif
#ifdef CTradeWnd__DeleteItemFromHisTradeArray_x
FUNCTION_AT_ADDRESS(void CTradeWnd::DeleteItemFromHisTradeArray(int), CTradeWnd__DeleteItemFromHisTradeArray);
#endif
#ifdef CTradeWnd__DropItemIntoTrade_x
FUNCTION_AT_ADDRESS(void CTradeWnd::DropItemIntoTrade(), CTradeWnd__DropItemIntoTrade);
#endif
#ifdef CTradeWnd__SetMyReadyTrade_x
FUNCTION_AT_ADDRESS(void CTradeWnd::SetMyReadyTrade(bool), CTradeWnd__SetMyReadyTrade);
#endif
#ifdef CTradeWnd__SetHisReadyTrade_x
FUNCTION_AT_ADDRESS(void CTradeWnd::SetHisReadyTrade(bool), CTradeWnd__SetHisReadyTrade);
#endif
#ifdef CTradeWnd__SetHisMoney_x
FUNCTION_AT_ADDRESS(void CTradeWnd::SetHisMoney(int, long), CTradeWnd__SetHisMoney);
#endif

//============================================================================
// CTradeWnd
//============================================================================

#ifdef CTrainWnd__CTrainWnd_x
FUNCTION_AT_ADDRESS(CTrainWnd::CTrainWnd(CXWnd*), CTrainWnd__CTrainWnd);
#endif
#ifdef CTrainWnd__Activate_x
FUNCTION_AT_ADDRESS(void CTrainWnd::Activate(), CTrainWnd__Activate);
#endif
#ifdef CTrainWnd__UpdateRight_x
FUNCTION_AT_ADDRESS(void CTrainWnd::UpdateRight(), CTrainWnd__UpdateRight);
#endif
#ifdef CTrainWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void CTrainWnd::UpdateAll(bool), CTrainWnd__UpdateAll);
#endif
#ifdef CTrainWnd__SkillName_x
FUNCTION_AT_ADDRESS(char* CTrainWnd::SkillName(int), CTrainWnd__SkillName);
#endif
#ifdef CTrainWnd__SkillValue_x
FUNCTION_AT_ADDRESS(int CTrainWnd::SkillValue(int), CTrainWnd__SkillValue);
#endif
#ifdef CTrainWnd__SwapSkill_x
FUNCTION_AT_ADDRESS(void CTrainWnd::SwapSkill(int, int), CTrainWnd__SwapSkill);
#endif
#ifdef CTrainWnd__SortNames_x
FUNCTION_AT_ADDRESS(void CTrainWnd::SortNames(int), CTrainWnd__SortNames);
#endif
#ifdef CTrainWnd__SortSkill_x
FUNCTION_AT_ADDRESS(void CTrainWnd::SortSkill(int), CTrainWnd__SortSkill);
#endif
#ifdef CTrainWnd__UpdateSkill_x
FUNCTION_AT_ADDRESS(void CTrainWnd::UpdateSkill(int), CTrainWnd__UpdateSkill);
#endif
#ifdef CTrainWnd__SkillChanged_x
FUNCTION_AT_ADDRESS(void CTrainWnd::SkillChanged(int), CTrainWnd__SkillChanged);
#endif
#ifdef CTrainWnd__SetGMData_x
FUNCTION_AT_ADDRESS(void CTrainWnd::SetGMData(int*, unsigned char*, float), CTrainWnd__SetGMData);
#endif
#ifdef CTrainWnd__Train_x
FUNCTION_AT_ADDRESS(void CTrainWnd::Train(), CTrainWnd__Train);
#endif

//============================================================================
// CVideoModesWnd
//============================================================================

#ifdef CVideoModesWnd__Update_x
FUNCTION_AT_ADDRESS(void CVideoModesWnd::Update(), CVideoModesWnd__Update);
#endif
#ifdef CVideoModesWnd__UpdateSelection_x
FUNCTION_AT_ADDRESS(void CVideoModesWnd::UpdateSelection(unsigned int), CVideoModesWnd__UpdateSelection);
#endif
#ifdef CVideoModesWnd__RestoreOldMode_x
FUNCTION_AT_ADDRESS(void CVideoModesWnd::RestoreOldMode(), CVideoModesWnd__RestoreOldMode);
#endif

//============================================================================
// CChatWindowManager
//============================================================================

#ifdef CChatWindowManager__FreeChatWindow_x
FUNCTION_AT_ADDRESS(void CChatWindowManager::FreeChatWindow(CChatWindow*), CChatWindowManager__FreeChatWindow);
#endif
#ifdef CChatWindowManager__GetRGBAFromIndex_x
FUNCTION_AT_ADDRESS(COLORREF CChatWindowManager::GetRGBAFromIndex(int), CChatWindowManager__GetRGBAFromIndex);
#endif
#ifdef CChatWindowManager__InitContextMenu_x
FUNCTION_AT_ADDRESS(int CChatWindowManager::InitContextMenu(CChatWindow*), CChatWindowManager__InitContextMenu);
#endif
#ifdef CChatWindowManager__GetLockedActiveChatWindow_x
FUNCTION_AT_ADDRESS(CChatWindow* CChatWindowManager::GetLockedActiveChatWindow(), CChatWindowManager__GetLockedActiveChatWindow);
#endif
#ifdef CChatWindowManager__SetLockedActiveChatWindow_x
FUNCTION_AT_ADDRESS(void CChatWindowManager::SetLockedActiveChatWindow(CChatWindow*), CChatWindowManager__SetLockedActiveChatWindow);
#endif
#ifdef CChatWindowManager__CreateChatWindow_x
FUNCTION_AT_ADDRESS(void CChatWindowManager::CreateChatWindow(CXWnd* pParentWnd, int ID, char* Name, int Language, int DefaultChannel,
	int ChatChannel, char* szTellTarget, int FontStyle, bool bScrollbar, bool bHighLight, COLORREF HighlightColor), CChatWindowManager__CreateChatWindow);
#endif

//============================================================================
// CChatWindow
//============================================================================

#ifdef CChatWindow__CChatWindow_x
CONSTRUCTOR_AT_ADDRESS(CChatWindow::CChatWindow(CXWnd*), CChatWindow__CChatWindow);
#endif
#ifdef CChatWindow__AddOutputText_x
FUNCTION_AT_ADDRESS(void CChatWindow::AddOutputText(PCXSTR, int), CChatWindow__AddOutputText);
#endif
#ifdef CChatWindow__HistoryBack_x
FUNCTION_AT_ADDRESS(void CChatWindow::HistoryBack(), CChatWindow__HistoryBack);
#endif
#ifdef CChatWindow__HistoryForward_x
FUNCTION_AT_ADDRESS(void CChatWindow::HistoryForward(), CChatWindow__HistoryForward);
#endif
#ifdef CChatWindow__AddHistory_x
// defined in ExceptionsDisabled.cpp
#endif
#ifdef CChatWindow__GetInputText_x
FUNCTION_AT_ADDRESS(CXStr CChatWindow::GetInputText(), CChatWindow__GetInputText);
#endif
#ifdef CChatWindow__PageUp_x
FUNCTION_AT_ADDRESS(void CChatWindow::PageUp(), CChatWindow__PageUp);
#endif
#ifdef CChatWindow__PageDown_x
FUNCTION_AT_ADDRESS(void CChatWindow::PageDown(), CChatWindow__PageDown);
#endif
#ifdef CChatWindow__SetChatFont_x
FUNCTION_AT_ADDRESS(void CChatWindow::SetChatFont(int), CChatWindow__SetChatFont);
#endif
#ifdef CChatWindow__Clear_x
FUNCTION_AT_ADDRESS(void CChatWindow::Clear(), CChatWindow__Clear);
#endif
#ifdef CChatWindow__GetInputWnd_x
FUNCTION_AT_ADDRESS(CEditWnd* CChatWindow::GetInputWnd(), CChatWindow__GetInputWnd);
#endif
#ifdef CChatWindow__WndNotification_x
FUNCTION_AT_ADDRESS(int CChatWindow::WndNotification(CXWnd*, uint32_t, void*), CChatWindow__WndNotification);
#endif


//============================================================================
// CSidlManagerBase
//============================================================================

#ifdef CSidlManagerBase__FindButtonDrawTemplate_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate* CSidlManagerBase::FindButtonDrawTemplate(uint32_t) const, CSidlManagerBase__FindButtonDrawTemplate);
#endif
#ifdef CSidlManagerBase__FindButtonDrawTemplate1_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate* CSidlManagerBase::FindButtonDrawTemplate(const CXStr& Name) const, CSidlManagerBase__FindButtonDrawTemplate1);
#endif
#ifdef CSidlManagerBase__FindAnimation1_x
FUNCTION_AT_ADDRESS(CTextureAnimation* CSidlManagerBase::FindAnimation(const CXStr&) const, CSidlManagerBase__FindAnimation1);
#endif
#ifdef CSidlManagerBase__FindScreenPieceTemplate_x
FUNCTION_AT_ADDRESS(CScreenPieceTemplate* CSidlManagerBase::FindScreenPieceTemplate(uint32_t) const, CSidlManagerBase__FindScreenPieceTemplate);
#endif
#ifdef CSidlManagerBase__FindScreenPieceTemplate1_x
FUNCTION_AT_ADDRESS(CScreenPieceTemplate* CSidlManagerBase::FindScreenPieceTemplate(const CXStr&) const, CSidlManagerBase__FindScreenPieceTemplate1);
#endif
#ifdef CSidlManagerBase__CreateXWndFromTemplate_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManagerBase::CreateXWndFromTemplate(CXWnd*, CControlTemplate*, bool), CSidlManagerBase__CreateXWndFromTemplate);
#endif
#ifdef CSidlManagerBase__CreateXWndFromTemplate1_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManagerBase::CreateXWndFromTemplate(CXWnd*, const CXStr&), CSidlManagerBase__CreateXWndFromTemplate1);
#endif
#ifdef CSidlManagerBase__CreateXWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManagerBase::CreateXWnd(CXWnd* pwndParent, CControlTemplate* pControl), CSidlManagerBase__CreateXWnd);
#endif

CXMLParamManager* CSidlManagerBase::GetParamManager()
{
	return &XMLDataMgr;
}

//============================================================================
// CSidlManager
//============================================================================

#ifdef CSidlManager__CreateHotButtonWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManager::CreateHotButtonWnd(CXWnd* pwndParent, CControlTemplate* pControl), CSidlManager__CreateHotButtonWnd);
#endif

//============================================================================
// CascadeItemBase and friends
//============================================================================

CascadeItemCommand::CascadeItemCommand(int icon, const char* text, int command)
{
	m_icon = icon;
	m_text = text;
	m_command = command;

	// Get KeyCombo for the command
	if (command >= 0 && command < nEQMappableCommands)
	{
		const KeyCombo combo = pKeypressHandler->NormalKey[command];

		m_text = CXStr{ text } +" <" + combo.GetTextDescription() + ">";
	}
}

void CascadeItemCommand::ExecuteCommand()
{
	EQExecuteCmd(m_command, true, nullptr, nullptr);
}

//============================================================================

//----------------------------------------------------------------------------

void InitializeUI()
{
	CButtonWnd::sm_vftable = reinterpret_cast<CButtonWnd::VirtualFunctionTable*>(CButtonWnd__vftable);
	CListWnd::sm_vftable = reinterpret_cast<CListWnd::VirtualFunctionTable*>(CListWnd__vftable);
	MapViewMap::sm_vftable = reinterpret_cast<CSidlScreenWnd::VirtualFunctionTable*>(MapViewMap__vftable);
}

} // namespace eqlib
