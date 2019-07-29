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

// this file exists specifically to define the naked functions that error our when exceptions
// are enabled. We don't actually need exceptions for these functions because EQ will implement
// the necessary exception handling mechanisms -- we just need to call into its functions.

// C++ exception handler used, but unwind semantics are not enabled.
#pragma warning(disable : 4530)

#include "UI.h"
#include "EQClasses.h"
#include "Globals.h"

namespace eqlib {

// CListWnd
#ifdef CListWnd__AddColumn1_x
FUNCTION_AT_ADDRESS(int CListWnd::AddColumn(const CXStr& Label, CTextureAnimation* pTA, int Width, uint32_t Flags, CXStr Tooltip, uint32_t Type, CTextureAnimation* pTASelected, CTextureAnimation* pTAMouseOver, bool bResizeable, tagSIZE TextureSize, tagPOINT TextureOffset), CListWnd__AddColumn1);
#endif

// CChatWindow
#ifdef CChatWindow__AddHistory_x
FUNCTION_AT_ADDRESS(void CChatWindow::AddHistory(CXStr), CChatWindow__AddHistory);
#endif

} // namespace eqlib