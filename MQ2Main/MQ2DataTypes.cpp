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
class MQ2GroundType *pGroundType=0;
class MQ2SwitchType *pSwitchType=0;

class MQ2MacroType *pMacroType=0;
class MQ2MacroQuestType *pMacroQuestType=0;
class MQ2MathType *pMathType=0;
class MQ2WindowType *pWindowType=0;
class MQ2MerchantType *pMerchantType=0;
class MQ2ZoneType *pZoneType=0;

CHAR DataTypeTemp[MAX_STRING]={0};

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
	pGroundType = new MQ2GroundType;
	pSwitchType = new MQ2SwitchType;
	pMacroType = new MQ2MacroType;
	pMacroQuestType = new MQ2MacroQuestType;
	pMathType = new MQ2MathType;
	pWindowType = new MQ2WindowType;
	pMerchantType = new MQ2MerchantType;
	pZoneType = new MQ2ZoneType;
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
	delete pGroundType;
	delete pSwitchType;
	delete pMacroType;
	delete pMacroQuestType;
	delete pMathType;
	delete pWindowType;
	delete pMerchantType;
	delete pZoneType;
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
		Dest.DWord=pSpawn->Level;
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
		return true;
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
		if (((PSPELLBUFF)Ptr)->SpellID==0xFFFFFFFF)
			return false;
		Dest.DWord=((PSPELLBUFF)Ptr)->Level;
		Dest.Type=pIntType;
		return true;
	case Spell:
		if (((PSPELLBUFF)Ptr)->SpellID==0xFFFFFFFF)
			return false;
		Dest.Ptr=GetSpellByID(((PSPELLBUFF)Ptr)->SpellID);
		Dest.Type=pSpellType;
		return true;
	case Mod:
		if (((PSPELLBUFF)Ptr)->SpellID==0xFFFFFFFF)
			return false;
		Dest.Float=(((float)((PSPELLBUFF)Ptr)->Modifier)/10.0f);
		Dest.Type=pFloatType;
		return true;
	case Duration:
		if (((PSPELLBUFF)Ptr)->SpellID==0xFFFFFFFF)
			return false;
		Dest.DWord=((PSPELLBUFF)Ptr)->Duration;
		Dest.Type=pTicksType;
		return true;
	}
	return false;
}

bool MQ2StringType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
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
	switch((StringMembers)pMember->ID)
	{
	case Length:
		Dest.DWord=strlen((const char *)Ptr);
		Dest.Type=pIntType;
		return true;
	case Left:
		if (!Index)
			return false;
		{
			unsigned long Len=atoi(Index);
			memmove(DataTypeTemp,(char *)Ptr,Len);
			DataTypeTemp[Len]=0;
			Dest.Ptr=&DataTypeTemp[0];
			Dest.Type=pStringType;
		}
		return true;
	case Right:
		if (!Index)
			return false;
		{	
			// index=5

			// 01234567
			// abcdefg
			unsigned long Len=atoi(Index);
			char *pStart=(char*)Ptr;
			pStart=&pStart[strlen(pStart)-Len];
			if (pStart<Ptr)
				pStart=(char*)Ptr;
			memmove(DataTypeTemp,pStart,Len+1);
			Dest.Ptr=&DataTypeTemp[0];
			Dest.Type=pStringType;
		}
		return true;
	case Find:
		if (!Index)
			return false;
		{
			char A[MAX_STRING]={0};
			char B[MAX_STRING]={0};
			strcpy(A,(char*)Ptr);
			strcpy(B,(char*)Index);
			strlwr(A);
			strlwr(B);
			if (char *pFound=strstr(A,B))
			{
				Dest.DWord=pFound-&A[0];
				Dest.Type=pIntType;
				return true;
			}
		}
		return false;
	case Upper:
		strcpy(DataTypeTemp,(char*)Ptr);
		strupr(DataTypeTemp);
		Dest.Ptr=&DataTypeTemp[0];
		Dest.Type=pStringType;
		return true;
	case Lower:
		strcpy(DataTypeTemp,(char*)Ptr);
		strlwr(DataTypeTemp);
		Dest.Ptr=&DataTypeTemp[0];
		Dest.Type=pStringType;
		return true;
	case Arg:
	case Mid:
		return false;
	}
	return false;
}
bool MQ2CharacterType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	#define pChar ((PCHARINFO)Ptr)
	if (!Ptr)
		return false;
	unsigned long N=MemberMap[Member];
	if (!N)
		return pSpawnType->GetMember(pChar->pSpawn,Member,Index,Dest);
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((CharacterMembers)pMember->ID)
	{
	case ID:
		Dest.DWord=pChar->pSpawn->SpawnID;
		Dest.Type=pIntType;
		return true;
	case Name:
		Dest.Ptr=&pChar->Name[0];
		Dest.Type=pStringType;
		return true;
	case Level:
		Dest.DWord=pChar->Level;
		Dest.Type=pIntType;
		return true;
	case Exp:
		Dest.DWord=pChar->Exp;
		Dest.Type=pIntType;
		return true;
	case Spawn:
		Dest.Ptr=pChar->pSpawn;
		Dest.Type=pSpawnType;
		return true;
	case CurrentHPs:
		Dest.DWord=pChar->pSpawn->HPCurrent;
		Dest.Type=pIntType;
		return true;
	case MaxHPs:
		Dest.Type=pIntType;
		Dest.Int=pChar->pSpawn->HPMax;
		return true;
	case PctHPs:
		Dest.Type=pIntType;
		Dest.Int=pChar->pSpawn->HPCurrent*100/pChar->pSpawn->HPMax;
		return true;
	case CurrentMana:
		Dest.DWord=pChar->Mana;
		Dest.Type=pIntType;
		return true;
	case MaxMana:
		Dest.DWord=GetMaxMana();
		Dest.Type=pIntType;
		return true;
	case PctMana:
		Dest.DWord=pChar->Mana*100/GetMaxMana();
		Dest.Type=pIntType;
		return true;
	case Buff:
		if (Index)
		{
			unsigned long nBuff=atoi(Index)-1;
			if (nBuff>16)
				return false;
			Dest.Ptr=&pChar->Buff[Buff];
			Dest.Type=pBuffType;
			return true;
		}
		return false;
	case Song:
		if (Index)
		{
			unsigned long nBuff=atoi(Index)-1;
			if (nBuff>6)
				return false;
			Dest.Ptr=&pChar->Buff[Buff];
			Dest.Type=pBuffType;
			return true;
		}
		return false;
		/*
		Dar=6,
		AAExp=7,
		AAPoints=8,
		AARank=9,
		HPRegen=12,
		ManaRegen=16,
		Buff=18,
		Song=19,
		Book=20,
		Skill=21,
		Ability=22,
		Surname=23,
		Cash=24,
		CashBank=25,
		PlatShared=26,
		Grouped=27,
		HPBonus=28,
		ManaBonus=29,
		GukEarned=30,
		MMEarned=31,
		RujEarned=32,
		TakEarned=33,
		LDonPoints=34,
		CurrentFavor=35,
		CareerFavor=36,
		Endurance=37,
		/**/
	}
	return false;
#undef pChar
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
bool MQ2SwitchType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2GroundType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2MacroType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2MacroQuestType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2MathType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2MerchantType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2WindowType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2ZoneType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}

