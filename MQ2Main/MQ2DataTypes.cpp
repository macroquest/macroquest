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

class MQ2FloatType *pFloatType=0;
class MQ2IntType *pIntType=0;
class MQ2ByteType *pByteType=0;
class MQ2StringType *pStringType=0;
class MQ2SpawnType *pSpawnType=0;
class MQ2BuffType *pBuffType=0;
class MQ2SpellType *pSpellType=0;
class MQ2TicksType *pTicksType=0;
class MQ2CharacterType *pCharacterType=0;

void InitializeMQ2DataTypes()
{
	pFloatType = new MQ2FloatType;
	pIntType = new MQ2IntType;
	pByteType = new MQ2ByteType;
	pStringType = new MQ2StringType;
	pSpawnType = new MQ2SpawnType;
	pSpellType = new MQ2SpellType;
	pBuffType = new MQ2BuffType;
	pTicksType = new MQ2TicksType;
	pCharacterType = new MQ2CharacterType;
}

void ShutdownMQ2DataTypes()
{
	delete pSpawnType;
	delete pFloatType;
	delete pIntType;
	delete pByteType;
	delete pStringType;
	delete pBuffType;
	delete pSpellType;
	delete pTicksType;
	delete pCharacterType;
}

bool MQ2SpawnType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((SpawnMembers)pMember->ID)
	{
	case Level:
		Dest.Type=pByteType;
		Dest.Ptr=(void*)((PSPAWNINFO)Ptr)->Level;
		return true;
	case ID:
		Dest.Type=pIntType;
		Dest.Ptr=(void*)((PSPAWNINFO)Ptr)->SpawnID;
		return true;
	case Name:
		Dest.Type=pStringType;
		Dest.Ptr=&((PSPAWNINFO)Ptr)->Name[0];
		return true;
	}
	return false;
}

bool MQ2BuffType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	static CHAR Temp[128];
	switch((BuffMembers)pMember->ID)
	{
	case ID:
		Dest.Ptr=(PVOID)((PSPELLBUFF)Ptr)->SpellID;
		Dest.Type=pIntType;
		return true;
	case Level:
		Dest.Ptr=(PVOID)((PSPELLBUFF)Ptr)->Level;
		Dest.Type=pIntType;
		return true;
	case Spell:
		return true;
	case Mod:
		return true;
	case Duration:
		Dest.Ptr=(PVOID)((PSPELLBUFF)Ptr)->Duration;
		Dest.Type=pTicksType;
		return true;
	}
	return false;
}
