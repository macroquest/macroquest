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

extern CHAR DataTypeTemp[MAX_STRING];

BOOL dataSpawn(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		if (szIndex[0]>='0' && szIndex[0]<='9')
		{
			if (Ret.Ptr=GetSpawnByID(atoi(szIndex)))
			{
				Ret.Type=pSpawnType;
				return true;
			}
		}
		else
		{
			// set up search spawn
			SEARCHSPAWN ssSpawn;
			ClearSearchSpawn(&ssSpawn);
			ParseSearchSpawn(szIndex,&ssSpawn);
			if (Ret.Ptr=SearchThroughSpawns(&ssSpawn,(PSPAWNINFO)pCharSpawn))
			{
				Ret.Type=pSpawnType;
				return true;
			}
		}
	}
	// No spawn

	return false;
}

BOOL dataTarget(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (pTarget)
	{
		Ret.Ptr=pTarget;
		Ret.Type=pSpawnType;
		return true;
	}
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

BOOL dataSpell(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		if (szIndex[0]>='0' && szIndex[0]<='9')
		{
			if (Ret.Ptr=GetSpellByID(atoi(szIndex)))
			{
				Ret.Type=pSpellType;
				return true;
			}
		}
		else
		{
			if (Ret.Ptr=GetSpellByName(szIndex))
			{
				Ret.Type=pSpellType;
				return true;
			}
		}
	}
   return false;
} 

BOOL dataSwitch(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (pDoorTarget)
	{
		Ret.Ptr=pDoorTarget;
		Ret.Type=pSwitchType;
		return true;
	}
	return false;
}

BOOL dataGroundItem(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (pGroundTarget)
	{
		Ret.Ptr=pGroundTarget;
		Ret.Type=pGroundType;
		return true;
	}
	return false;
}

BOOL dataMerchant(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (pActiveMerchant)
	{
		Ret.Ptr=pActiveMerchant;
		Ret.Type=pMerchantType;
		return true;
	}
	return false;
}

BOOL dataWindow(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		if (Ret.Ptr=FindMQ2Window(szIndex))
		{
			Ret.Type=pWindowType;
			return true;
		}
	}
	return false;
}

BOOL dataMacro(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (gRunning)
	{
		Ret.Ptr=0;
		Ret.Type=pMacroType;
		return true;
	}
	return false;
}

BOOL dataMacroQuest(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	Ret.Ptr=0;
	Ret.Type=pMacroQuestType;
	return true;
}

BOOL dataMath(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	Ret.Ptr=0;
	Ret.Type=pMathType;
	return true;
}

BOOL dataZone(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	Ret.DWord=instEQZoneInfo;
	Ret.Type=pZoneType;
	return true;
}

BOOL dataInt(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	Ret.DWord=atol(szIndex);
	Ret.Type=pIntType;
	return true;
}

BOOL dataString(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	strcpy(DataTypeTemp,szIndex);
	Ret.Ptr=&DataTypeTemp[0];
	Ret.Type=pStringType;
	return true;
}

BOOL dataFloat(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	Ret.Float=(FLOAT)atof(szIndex);
	Ret.Type=pFloatType;
	return true;
}

BOOL dataBool(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	Ret.DWord=(strcmp(szIndex,"NULL") && 
				strcmp(szIndex,"FALSE") &&
				strcmp(szIndex,"0"));
	Ret.Type=pBoolType;
	return true;
}

BOOL dataGroup(PCHAR szIndex, MQ2TYPEVAR &Ret)
{
	if (szIndex[0])
	{
		DWORD N=atoi(szIndex);
		if (N>5)
			return false;
		for (unsigned long i=0; i<5 ; i++)
		{
			if (EQADDR_GROUPCOUNT[i])
			{
				N--;
				if (N==0)
				{
					Ret.Ptr=ppGroup[i];
					Ret.Type=pSpawnType;
					return true;
				}
			}
		}
		return false;
	}
	else
	{
		Ret.DWord=0;
		for (int index=0;index<5;index++) 
			if (EQADDR_GROUPCOUNT[index]) 
				Ret.DWord++;
		Ret.Type=pIntType;
		return true;
	}
	return false;
}