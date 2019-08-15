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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "Common.h"
#include "Allocator.h"
#include "UI.h"
#include "CXWnd.h"

namespace eqlib {

eqAllocFn eqAlloc = nullptr;
eqFreeFn eqFree = nullptr;

namespace SoeUtil {

void* Alloc(int bytes, int align) { return 0; }
void Free(void* p, int align) {}

}

void InitializeEQLib()
{
	InitializeUI();
	InitializeCXWnd();
}

void InitializeEQLibForTesting()
{
	eqAlloc = malloc;
	eqFree = free;
}

} // namespace eqlib
