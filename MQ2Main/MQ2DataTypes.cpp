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
class MQ2ClassType *pClassType=0;
class MQ2RaceType *pRaceType=0;

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
	pClassType=new MQ2ClassType;
	pRaceType=new MQ2RaceType;
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
	delete pClassType;
	delete pRaceType;
}

bool MQ2SpawnType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	if (!Ptr)
		return false;
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
#define pSpawn ((PSPAWNINFO)Ptr)
/*
	static enum SpawnMembers
	{
		DistanceX=7,
		DistanceY=8,
		DistanceZ=9,
		Distance=10,
		Distance3D=11,
		DistancePredict=12,
		Heading=15,
		Speed=16,
		Levitating=17,
		Sneaking=18,
		HeadingTo=19,
		Light=20,
		Body=21,
		State=22,
		Deity=26,
		DeityTeam=27,
		Type=28,
		CleanName=29,
		Surname=30,
		Guild=31,
		GuildStatus=32,
		Master=33,
		Pet=34,
		Race=35,
		Class=36,
		ShortClass=37,
		Gender=38,
		GM=39,
		Height=40,
		MaxRange=41,
	};
/**/
	switch((SpawnMembers)pMember->ID)
	{
	case Level:
		Dest.Type=pByteType;
		Dest.Byte=pSpawn->Level;
		return true;
	case ID:
		Dest.Type=pIntType;
		Dest.DWord=pSpawn->SpawnID;
		return true;
	case Name:
		Dest.Type=pStringType;
		Dest.Ptr=&pSpawn->Name[0];
		return true;
	case X:
		Dest.Type=pFloatType;
		Dest.Float=pSpawn->X;
		return true;
	case Y:
		Dest.Type=pFloatType;
		Dest.Float=pSpawn->Y;
		return true;
	case Z:
		Dest.Type=pFloatType;
		Dest.Float=pSpawn->Z;
		return true;
	case Next:
		Dest.Type=pSpawnType;
		Dest.Ptr=pSpawn->pNext;
		return true;
	case Prev:
		Dest.Type=pSpawnType;
		Dest.Ptr=pSpawn->pPrev;
		return true;
	case CurrentHPs:
		Dest.Type=pIntType;
		Dest.Int=pSpawn->HPCurrent;
		return true;
	case MaxHPs:
		Dest.Type=pIntType;
		Dest.Int=pSpawn->HPMax;
		return true;
	case PctHPs:
		Dest.Type=pIntType;
		Dest.Int=pSpawn->HPCurrent*100/pSpawn->HPMax;
		break;
	}
	return false;
#undef pSpawn
}

bool MQ2BuffType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	if (!Ptr)
		return false;
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
		Dest.DWord=((PSPELLBUFF)Ptr)->SpellID;
		Dest.Type=pIntType;
		return true;
	case Level:
		Dest.DWord=((PSPELLBUFF)Ptr)->Level;
		Dest.Type=pIntType;
		return true;
	case Spell:
		Dest.Ptr=GetSpellByID(((PSPELLBUFF)Ptr)->SpellID);
		Dest.Type=pSpellType;
		return true;
	case Mod:
		Dest.Float=(((float)((PSPELLBUFF)Ptr)->Modifier)/10.0f);
		Dest.Type=pFloatType;
		return true;
	case Duration:
		Dest.DWord=((PSPELLBUFF)Ptr)->Duration;
		Dest.Type=pTicksType;
		return true;
	}
	return false;
}

bool MQ2StringType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
/*
		Arg=1,
		Mid=2,
		Left=3,
		Right=4,
		Find=5,
		Length=6,
		Upper=7,
		Lower=8,
/**/
	if (!Ptr)
		return false;
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	static CHAR Temp[MAX_STRING];
	switch((StringMembers)pMember->ID)
	{
	case Arg:
	case Mid:
	case Left:
	case Right:
	case Find:
	case Length:
	case Upper:
	case Lower:
		return false;
	}
	return false;
}
bool MQ2CharacterType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2SpellType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}

bool MQ2ItemType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}

bool MQ2ClassType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2RaceType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
