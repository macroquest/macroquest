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


/* OTHER FUNCTIONS IMPORTED FROM EQ */
#ifdef __CastRay_x
FUNCTION_AT_ADDRESS(int CastRay(SPAWNINFO*, float y, float x, float z), __CastRay);
#endif
#ifdef __CastRay2_x
FUNCTION_AT_ADDRESS(int CastRayLoc(const CVector3& SourcePos, int Race, float DestX, float DestY, float DestZ), __CastRay2);
#endif
#ifdef __CleanItemTags_x
FUNCTION_AT_ADDRESS(CXStr CleanItemTags(const CXStr& In, bool bFlag), __CleanItemTags);
#endif
#ifdef __HeadingDiff_x
FUNCTION_AT_ADDRESS(float HeadingDiff(float h1, float h2, float* DiffOut), __HeadingDiff);
#endif
#ifdef __FixHeading_x
FUNCTION_AT_ADDRESS(float FixHeading(float Heading), __FixHeading);
#endif
#ifdef __get_bearing_x
FUNCTION_AT_ADDRESS(float get_bearing(float x1, float y1, float x2, float y2), __get_bearing)
#endif
#ifdef Util__FastTime_x
FUNCTION_AT_ADDRESS(unsigned long  GetFastTime(), Util__FastTime);
#endif
#ifdef __GetXTargetType_x
FUNCTION_AT_ADDRESS(const char* __stdcall GetXtargetType(DWORD type), __GetXTargetType);
#endif
#ifdef __EQGetTime_x
FUNCTION_AT_ADDRESS(DWORD EQGetTime(), __EQGetTime);
#endif
#ifdef __msg_successful_hit_x
FUNCTION_AT_ADDRESS(void msg_successful_hit(struct _EQSuccessfulHit*), __msg_successful_hit);
#endif
#ifdef __STMLToText_x
FUNCTION_AT_ADDRESS(CXStr STMLToText(const CXStr&, bool), __STMLToText);
#endif
#ifdef __GetAnimationCache_x
FUNCTION_AT_ADDRESS(IconCache* GetAnimationCache(int index), __GetAnimationCache);
#endif
#ifdef __SaveColors_x
FUNCTION_AT_ADDRESS(void SaveColors(int, int, int, int), __SaveColors);
#endif
#ifdef __ExecuteCmd_x
FUNCTION_AT_ADDRESS(bool EQExecuteCmd(unsigned int command, bool keyDown, void* data, const KeyCombo* combo), __ExecuteCmd);
#endif
#ifdef __FlushDxKeyboard_x
FUNCTION_AT_ADDRESS(void FlushDxKeyboard(), __FlushDxKeyboard);
#endif


} // namespace eqlib
