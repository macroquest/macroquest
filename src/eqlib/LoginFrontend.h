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

#pragma once

#include "Common.h"

namespace eqlib {

//----------------------------------------------------------------------------

// Types used by the frontend a.k.a. eqmain.dll

class [[offsetcomments]] LoginController
{
public:
	EQLIB_OBJECT LoginController(HINSTANCE hInstance, HWND hWnd);
	EQLIB_OBJECT ~LoginController();

	EQLIB_OBJECT void Startup();
	EQLIB_OBJECT void Shutdown();
	EQLIB_OBJECT void GiveTime();

	EQLIB_OBJECT int ProcessKeyboardEvents();
	EQLIB_OBJECT int ProcessMouseEvents();
	EQLIB_OBJECT int FlushDxKeyboard();


/*0x00*/ IDirectInput8A*          pDI;
/*0x04*/ IDirectInputDevice8A*    pDIKeyboard;
/*0x08*/ IDirectInputDevice8A*    pDIMouse;
/*0x0c*/ HWND                     hWnd;
/*0x10*/ HINSTANCE                hInstance;
/*0x14*/ bool                     bIsKeyboardActive;
/*0x15*/ bool                     bIsMouseActive;
/*0x18*/ uint32_t                 Unknown0x18;
/*0x1c*/ int                      LastInputKey;
/*0x20*/
};


//----------------------------------------------------------------------------

} // namespace eqlib
