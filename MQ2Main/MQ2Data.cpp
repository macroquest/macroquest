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


BOOL dataSpawn(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		if (Ret.Ptr=GetSpawnByID(atoi(szIndex)))
		{
			Ret.Type=pSpawnType;
			return true;
		}
	}
	// No spawn

	return false;
}

BOOL dataCharacter(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (pCharData)
	{
		Ret.Ptr=pCharData;
		Ret.Type=pCharacterType;
		return true;
	}
	return false;
}
