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

#include "pch.h"
#include "EQLib.h"

namespace eqlib {

eqAllocFn eqAlloc = nullptr;
eqFreeFn eqFree = nullptr;

namespace SoeUtil {

void* Alloc(int bytes, int align) { return 0; }
void Free(void* p, int align) {}

}

FUNCTION_AT_VARIABLE_ADDRESS(void* eqAllocImpl(size_t), __eq_new);
FUNCTION_AT_VARIABLE_ADDRESS(void eqFreeImpl(void*), __eq_delete);


void InitializeEQLib()
{
	eqAlloc = eqAllocImpl;
	eqFree = eqFreeImpl;

	InitializeGlobals();

	InitializeUI();
	InitializeCXWnd();
	InitializeCXStr();
}

void InitializeEQLibForTesting()
{
	eqAlloc = malloc;
	eqFree = free;
}

void ShutdownEQLib()
{
	ShutdownCXStr();
}

} // namespace eqlib
