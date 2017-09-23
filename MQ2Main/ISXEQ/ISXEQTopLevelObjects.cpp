/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

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

#include "..\MQ2Main.h"

#define TLO(funcname) bool funcname(int argc, char *argv[], LSTYPEVAR &Ret)

TLO(dataNearestDoor)
{
   DWORD Count = 0;
   FLOAT cDistance = 100000.0f;
    PDOORTABLE pDoorTable = (PDOORTABLE)pSwitchMgr;

   if (pDoorTable->NumEntries)
   {
      for (Count=0; Count<pDoorTable->NumEntries; Count++) {
         FLOAT Distance = GetDistance(pDoorTable->pDoor[Count]->X, pDoorTable->pDoor[Count]->Y);
         if (Distance<cDistance) {
            pDoorTarget = pDoorTable->pDoor[Count];
            cDistance=Distance;
         }
      }
      Ret.Ptr=pDoorTarget;
      Ret.Type=pSwitchType;
      return true;
   }
   return false;
}

