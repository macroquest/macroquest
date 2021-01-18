/*
 * MacroQuest: The extension platform for EverQuest
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

#if __has_include("../../MQ2Auth.h")
DWORD gh;
LRESULT CALLBACK proc(int nCode, WPARAM wParam, LPARAM lParam)
{
	return ::CallNextHookEx((HHOOK)gh, nCode, wParam, lParam);
}
using FNCB = DWORD(*)(DWORD, HINSTANCE, DWORD&);

namespace mq
{
	extern "C" HINSTANCE ghInstance;
}

#define MQ2AUTH(z)                                                    \
    extern "C" __declspec(dllexport) void z(DWORD x)                  \
    {                                                                 \
        FNCB f = (FNCB)x;                                             \
        f((DWORD)proc, mq::ghInstance, gh);                           \
    }

#include "../../MQ2Auth.h"

#else
#error "Missing MQ2Auth.h - be sure to run MQ2Auth to generate it"
#endif
