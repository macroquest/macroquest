/*****************************************************************************
    eqlib.dll: MacroQuest's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic

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

#include "stdafx.h"
#include "MQ2Main.h"

// CEverQuest
REVERSE_DETOUR(void CEverQuest::dsp_chat(char const *,int,bool),[EQADDR_DSPCHAT]);

// CEQCharacter
REVERSE_DETOUR(int EQ_Character::Cur_HP(int),[EQADDR_GETCURHP]);
REVERSE_DETOUR(int EQ_Character::Max_HP(int),[EQADDR_GETMAXHP]);
REVERSE_DETOUR(int EQ_Character::Max_Mana(void),[EQADDR_MAXMANA]);

// CXWnd
REVERSE_VIRTUAL_DETOUR(bool CXWnd::IsValid(void)const,0);
//REVERSE_VIRTUAL_DETOUR(void CXWnd::SetWindowTextA(class CXStr),0x108);
// ^^ requires CXStr de/constructors

// CItemDisplayWnd
REVERSE_DETOUR(void CItemDisplayWnd::SetItem(class EQ_Item *,bool),[EQADDR_ITEMDISPLAYSETITEM]);

// CXStr
REVERSE_DETOUR(void CXStr::operator+=(char const *),[EQADDR_CXSTRAPPEND]);
REVERSE_DETOUR(class CXStr & CXStr::operator=(char const *),[EQADDR_CXSTRSET]);

// CChatManager
REVERSE_DETOUR(unsigned long CChatManager::GetRGBAFromIndex(int),[EQADDR_CCHATMANAGERGETRGBAFROMINDEX]);
REVERSE_DETOUR(int CChatManager::InitContextMenu(class CChatWindow *),[EQADDR_CHATMANAGERINITCONTEXTMENU]);


//class CXSize CStmlWnd::AppendSTML(class CXStr);