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

#include "UI.h"
#include "EQClasses.h"

namespace eqlib {

CScreenPieceTemplate* CSidlManager::FindScreenPieceTemplate(const char* str)
{
	return FindScreenPieceTemplate(CXStr(str));
}

void CComboWnd::InsertChoice(char* str)
{
	InsertChoice(str, 0);
}

#if !defined(ROF2EMU) && !defined(UFEMU)
int CListWnd::AddString(const char* Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr)
#else
int CListWnd::AddString(const char* Str, COLORREF Color, uint32_t Data, const CTextureAnimation* pTa, const char* TooltipStr)
#endif
{
	return AddString(CXStr(Str), Color, Data, pTa, TooltipStr);
}

void CEditBaseWnd::SetMaxChars(int maxChars)
{
	MaxChars = maxChars;

	if (maxChars < (int)InputText.length())
	{
		SetWindowText(InputText);
	}
}

} // namespace eqlib

using namespace eqlib;
