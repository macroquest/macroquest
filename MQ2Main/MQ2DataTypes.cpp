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
class MQ2BoolType *pBoolType=0;
class MQ2StringType *pStringType=0;
class MQ2SpawnType *pSpawnType=0;
class MQ2BuffType *pBuffType=0;
class MQ2SpellType *pSpellType=0;
class MQ2TicksType *pTicksType=0;
class MQ2CharacterType *pCharacterType=0;
class MQ2ClassType *pClassType=0;
class MQ2RaceType *pRaceType=0;
class MQ2BodyType *pBodyType=0;

class MQ2GroundType *pGroundType=0;
class MQ2SwitchType *pSwitchType=0;

class MQ2MacroType *pMacroType=0;
class MQ2MacroQuestType *pMacroQuestType=0;
class MQ2MathType *pMathType=0;
class MQ2WindowType *pWindowType=0;
class MQ2MerchantType *pMerchantType=0;
class MQ2ZoneType *pZoneType=0;
class MQ2ItemType *pItemType=0;
class MQ2DeityType *pDeityType=0;
class MQ2ArgbType *pArgbType=0;

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
	pItemType = new MQ2ItemType;
	pBoolType = new MQ2BoolType;
	pBodyType = new MQ2BodyType;
	pDeityType = new MQ2DeityType;
	pArgbType = new MQ2ArgbType;
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
	delete pItemType;
	delete pBoolType;
	delete pBodyType;
	delete pDeityType;
	delete pArgbType;
}

bool MQ2IntType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((IntMembers)pMember->ID)
	{
	case Float:
		Dest.Float=(FLOAT)((int)Ptr);
		Dest.Type=pFloatType;
		return true;
	case Hex:
		sprintf(DataTypeTemp,"%x",Ptr);
		Dest.Ptr=&DataTypeTemp[0],
		Dest.Type=pStringType;
		return true;
	}
	return false;
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
	switch((SpawnMembers)pMember->ID)
	{
	case Level:
		Dest.DWord=pSpawn->Level;
		Dest.Type=pByteType;
		return true;
	case ID:
		Dest.Type=pIntType;
		Dest.DWord=pSpawn->SpawnID;
		return true;
	case Name:
		Dest.Type=pStringType;
		Dest.Ptr=&pSpawn->Name[0];
		return true;
	case Surname:
		Dest.Type=pStringType;
		Dest.Ptr=&pSpawn->Lastname[0];
		return true;
	case CleanName:
		strcpy(DataTypeTemp,pSpawn->Name);
		CleanupName(DataTypeTemp,FALSE);
		Dest.Type=pStringType;
		Dest.Ptr=&DataTypeTemp[0];
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
	case AARank:
		Dest.Int=pSpawn->AARank;
		Dest.Type=pIntType;
		return true;
	case Speed:
		Dest.Float=FindSpeed(pSpawn);
		Dest.Type=pFloatType;
		return true;
	case Heading:
		Dest.Float=pSpawn->Heading*0.703125f;
		Dest.Type=pFloatType;
		return true;
	case Pet:
        if (Dest.Ptr=GetSpawnByID(pSpawn->pActorInfo->PetID))
		{
			Dest.Type=pSpawnType;
			return true;
		}
		return false;
	case Master:
        if (Dest.Ptr=GetSpawnByID(pSpawn->MasterID))
		{
			Dest.Type=pSpawnType;
			return true;
		}
		return false;
	case Gender:
		Dest.Ptr=szGender[pSpawn->Gender];
		Dest.Type=pStringType;
		return true;
	case Race:
		Dest.DWord=pSpawn->Race;
		Dest.Type=pRaceType;
		return true;
	case Class:
		Dest.DWord=pSpawn->Class;
		Dest.Type=pClassType;
		return true;
	case Body:
		Dest.DWord=pSpawn->BodyType;
		Dest.Type=pBodyType;
		return true;
	case GM:
		Dest.DWord=pSpawn->GM;
		Dest.Type=pBoolType;
		return true;
	case Levitating:
		Dest.DWord=(pSpawn->Levitate==2);
		Dest.Type=pBoolType;
		return true;
	case Sneaking:
		Dest.DWord=pSpawn->Sneak;
		Dest.Type=pBoolType;
		return true;
	case Height:
		Dest.Float=pSpawn->AvatarHeight;
		Dest.Type=pFloatType;
		return true;
	case MaxRange:
		Dest.Float=(float)((pSpawn->AvatarHeight+((PSPAWNINFO)pCharSpawn)->AvatarHeight)*1.3333333333);
		Dest.Type=pFloatType;
		return true;
	case Guild:
		if (pSpawn->GuildID < MAX_GUILDS)
		{
			Dest.Ptr=GetGuildByID(pSpawn->GuildID);
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case GuildStatus:
		if (pSpawn->GuildID < MAX_GUILDS)
		{
			Dest.Ptr=szGuildStatus[pSpawn->GuildStatus];
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case Type:
		if (pSpawn->Type < 6)
		{
			Dest.Ptr=szSpawnType[pSpawn->Type];
		}
		else
			Dest.Ptr="Unknown";
		Dest.Type=pStringType;
		return true;
	case Light:
		Dest.Ptr=GetLightForSpawn(pSpawn);
		Dest.Type=pStringType;
		return true;
	case State:
        switch (pSpawn->StandState) {
            case STANDSTATE_STAND:
                Dest.Ptr="STAND";
                break;
            case STANDSTATE_SIT:
                Dest.Ptr="SIT";
                break;
            case STANDSTATE_DUCK:
                Dest.Ptr="DUCK";
                break;
            case STANDSTATE_BIND:
                Dest.Ptr="BIND";
                break;
            case STANDSTATE_FEIGN:
                Dest.Ptr="FEIGN";
                break;
            case STANDSTATE_DEAD:
                Dest.Ptr="DEAD";
                break;
            default:
                Dest.Ptr="UNKNOWN";
                break;
		}
		Dest.Type=pStringType;
		return true;
	case Deity:
		Dest.DWord=pSpawn->Deity;
		Dest.Type=pDeityType;
		return true;
	case Zone:
		Dest.Ptr=GetFullZone(pSpawn->Zone);
		Dest.Type=pStringType;
		return true;
/*
	static enum SpawnMembers
	{
		DistanceX=7,
		DistanceY=8,
		DistanceZ=9,
		Distance=10,
		Distance3D=11,
		DistancePredict=12,
		HeadingTo=19,
	};
/**/
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
		if (!Index[0])
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
		if (!Index[0])
			return false;
		{	
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
		if (!Index[0])
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
	case Surname:
		Dest.Ptr=&pChar->Lastname[0];
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
		if (Index[0])
		{
			unsigned long nBuff=atoi(Index)-1;
			if (nBuff>16)
				return false;
			if (pChar->Buff[nBuff].SpellID==0xFFFFFFFF || pChar->Buff[nBuff].SpellID==0)
				return false;
			Dest.Ptr=&pChar->Buff[nBuff];
			Dest.Type=pBuffType;
			return true;
		}
		return false;
	case Song:
		if (Index[0])
		{
			unsigned long nBuff=atoi(Index)-1;
			if (nBuff>6)
				return false;
			if (pChar->ShortBuff[nBuff].SpellID==0xFFFFFFFF || pChar->ShortBuff[nBuff].SpellID==0x0)
				return false;

			Dest.Ptr=&pChar->ShortBuff[nBuff];
			Dest.Type=pBuffType;
			return true;
		}
		return false;
	case HPBonus:
		Dest.DWord=pChar->HPBonus;
		Dest.Type=pIntType;
		return true;
	case ManaBonus:
		Dest.DWord=pChar->ManaBonus;
		Dest.Type=pIntType;
		return true;
	case Endurance:
		Dest.DWord=pChar->Endurance;
		Dest.Type=pIntType;
		return true;
	case GukEarned:
		Dest.DWord=pChar->GukEarned;
		Dest.Type=pIntType;
		return true;
	case MMEarned:
		Dest.DWord=pChar->MMEarned;
		Dest.Type=pIntType;
		return true;
	case RujEarned:
		Dest.DWord=pChar->RujEarned;
		Dest.Type=pIntType;
		return true;
	case TakEarned:
		Dest.DWord=pChar->TakEarned;
		Dest.Type=pIntType;
		return true;
	case MirEarned:
		Dest.DWord=pChar->MirEarned;
		Dest.Type=pIntType;
		return true;
	case LDoNPoints:
		Dest.DWord=pChar->LDoNPoints;
		Dest.Type=pIntType;
		return true;
	case CurrentFavor:
		Dest.DWord=pChar->CurrFavor;
		Dest.Type=pIntType;
		return true;
	case CareerFavor:
		Dest.DWord=pChar->CareerFavor;
		Dest.Type=pIntType;
		return true;
	case Inventory:
		if (Index[0])
		{
			if (Index[0]>='0' && Index[0]<='9')
			{
				unsigned long nSlot=atoi(Index)-1;
				if (nSlot<0x1E)
				{
					Dest.Ptr=pChar->InventoryArray[nSlot];
					Dest.Type=pItemType;
					return true;
				}
			}
		}
		return false;
	case Bank:
		if (Index[0])
		{
			if (Index[0]>='0' && Index[0]<='9')
			{
				unsigned long nSlot=atoi(Index)-1;
				if (nSlot<NUM_BANK_SLOTS)
				{
					Dest.Ptr=pChar->Bank[nSlot];
					Dest.Type=pItemType;
					return true;
				}
			}
		}
		return false;
	case PlatShared:
		Dest.DWord=pChar->BankSharedPlat;
		Dest.Type=pIntType;
		return true;
	case Cash:
		Dest.DWord=pChar->Plat*1000+pChar->Gold*100+pChar->Silver*10+pChar->Copper;
		Dest.Type=pIntType;
		return true;
	case CashBank:
		Dest.DWord=pChar->BankPlat*1000+pChar->BankGold*100+pChar->BankSilver*10+pChar->BankCopper;
		Dest.Type=pIntType;
		return true;
	case AAExp:
		Dest.DWord=pChar->AAExp;
		Dest.Type=pIntType;
		return true;
	case AAPoints:
		Dest.DWord=pChar->AAPoints;
		Dest.Type=pIntType;
		return true;
	case Bound:
		Dest.Ptr=GetFullZone(((PCHARINFO)pCharData)->ZoneBoundId);
		Dest.Type=pStringType;
		return true;
		/*
		Dar=6,
		HPRegen=12,
		ManaRegen=16,
		Book=20,
		Skill=21,
		Ability=22,
		Grouped=27,
		/**/
	}
	return false;
#undef pChar
}
bool MQ2SpellType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pSpell ((PSPELL)Ptr)
	if (!Ptr)
		return false;
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((SpellMembers)pMember->ID)
	{
	case ID:
		Dest.DWord=pSpell->ID;
		Dest.Type=pIntType;
		return true;
	case Name:
		Dest.Ptr=&pSpell->Name[0];
		Dest.Type=pStringType;
		return true;
	case Level:
		if (!Index[0])
		{
			Dest.DWord=pSpell->Level[GetCharInfo()->pSpawn->Class-1];
			Dest.Type=pIntType;
			return true;
		}
		else
		{
			if (Index[0]>='0' && Index[0]<='9')
			{
				unsigned long nIndex=atoi(Index)-1;
				Dest.DWord=pSpell->Level[nIndex];
				Dest.Type=pIntType;
				return true;
			}
		}
		return false;
	case Mana:
		Dest.DWord=pSpell->Mana;
		Dest.Type=pSpellType;
		return true;
	case ResistAdj:
		Dest.DWord=pSpell->ResistAdj;
		Dest.Type=pIntType;
		return true;
	case Range:
		Dest.Float=pSpell->Range;
		Dest.Type=pFloatType;
		return true;
	case AERange:
		Dest.Float=pSpell->AERange;
		Dest.Type=pFloatType;
		return true;
	case PushBack:
		Dest.Float=pSpell->PushBack;
		Dest.Type=pFloatType;
		return true;
	case CastTime:
		Dest.Float=(FLOAT)pSpell->CastTime/1000;
		Dest.Type=pFloatType;
		return true;
	case RecoveryTime:
	case FizzleTime:
		Dest.Float=(FLOAT)pSpell->FizzleTime/1000;
		Dest.Type=pFloatType;
		return true;
	case RecastTime:
		Dest.Float=(FLOAT)pSpell->RecastTime/1000;
		Dest.Type=pFloatType;
		return true;
	case ResistType:
		switch(pSpell->Resist)
		{
			case 6:	Dest.Ptr="Chromatic"; break;
			case 5:	Dest.Ptr="Disease"; break;
			case 4:	Dest.Ptr="Poison"; break;
			case 3:	Dest.Ptr="Cold"; break;
			case 2:	Dest.Ptr="Fire"; break;
			case 1:	Dest.Ptr="Magic"; break;
			case 0:	Dest.Ptr="Unresistable"; break;
			default: Dest.Ptr="Unknown"; break;
		}
		Dest.Type=pStringType;
		return true;
	case SpellType:
		switch(pSpell->SpellType)
		{
			case 2: Dest.Ptr="Beneficial(Group)"; break;
			case 1: Dest.Ptr="Beneficial"; break;
			case 0: Dest.Ptr="Detrimental"; break;
			default: Dest.Ptr="Unknown"; break;
		}
		Dest.Type=pStringType;
		return true;
	case TargetType:
		switch(pSpell->TargetType)
		{
			case 41: Dest.Ptr="Group v2"; break;
			case 40: Dest.Ptr="AE PC v2"; break;
			case 25: Dest.Ptr="AE Summoned"; break;
			case 24: Dest.Ptr="AE Undead"; break;
			case 20: Dest.Ptr="Targeted AE Tap"; break;
			case 18: Dest.Ptr="Uber Dragons"; break;
			case 17: Dest.Ptr="Uber Giants"; break;
			case 16: Dest.Ptr="Plant"; break;
			case 15: Dest.Ptr="Corpse"; break;
			case 14: Dest.Ptr="Pet"; break;
			case 13: Dest.Ptr="LifeTap"; break;
			case 11: Dest.Ptr="Summoned"; break;
			case 10: Dest.Ptr="Undead"; break;
			case  9: Dest.Ptr="Animal"; break;
			case  8: Dest.Ptr="Targeted AE"; break;
			case  6: Dest.Ptr="Self"; break;
			case  5: Dest.Ptr="Single"; break;
			case  4: Dest.Ptr="PB AE"; break;
			case  3: Dest.Ptr="Group v1"; break;
			case  2: Dest.Ptr="AE PC v1"; break;
			case  1: Dest.Ptr="Line of Sight"; break;
			default: Dest.Ptr="Unknown"; break;
		}
		Dest.Type=pStringType;
		return true;
	case Skill:
		Dest.Ptr=szSkills[pSpell->Skill];
		Dest.Type=pStringType;
		return true;
		/*
		MyCastTime=12,
		Duration=15,
		/**/
	}
	return false;
#undef pSpell
}

bool MQ2ItemType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pItem ((PCONTENTS)Ptr)
	if (!Ptr)
		return false;
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((ItemMembers)pMember->ID)
	{
	case ID:
		Dest.DWord=pItem->Item->ItemNumber;
		Dest.Type=pIntType;
		return true;
	case Name:
		Dest.Ptr=&pItem->Item->Name[0];
		Dest.Type=pStringType;
		return true;
	case Lore:
		Dest.DWord=(pItem->Item->LoreName[0]=='*');
		Dest.Type=pBoolType;
		return true;
	case NoDrop:
		Dest.DWord=pItem->Item->NoDrop;
		Dest.Type=pBoolType;
		return true;
	case NoRent:
		Dest.DWord=pItem->Item->NoRent;
		Dest.Type=pBoolType;
		return true;
	case Magic:
		Dest.DWord=((pItem->Item->Type == ITEMTYPE_NORMAL) && (pItem->Item->Magic));
		Dest.Type=pBoolType;
		return true;
	case Value:
		Dest.DWord=pItem->Item->Cost;
		Dest.Type=pIntType;
		return true;
	case Size:
		Dest.DWord=pItem->Item->Size;
		Dest.Type=pIntType;
		return true;
	case Weight:
		Dest.DWord=pItem->Item->Weight;
		Dest.Type=pIntType;
		return true;
	case Stack:
		if ((pItem->Item->Type != ITEMTYPE_NORMAL) || (pItem->Item->Stackable!=1))
			Dest.DWord=1;
		else
			Dest.DWord=pItem->StackCount;
		Dest.Type=pIntType;
		return true;
	case Type:
		if (pItem->Item->Type == ITEMTYPE_NORMAL) 
		{
            if ((pItem->Item->ItemType < MAX_ITEMTYPES) && (szItemTypes[pItem->Item->ItemType] != NULL)) 
			{
				Dest.Ptr=szItemTypes[pItem->Item->ItemType];
            } 
			else 
			{
				Dest.Ptr=&DataTypeTemp[0];
                sprintf(DataTypeTemp,"*UnknownType%d",pItem->Item->ItemType);
            }
        }
        else if (pItem->Item->Type == ITEMTYPE_PACK) 
		{
            if ((pItem->Item->Combine < MAX_COMBINES) && (szCombineTypes[pItem->Item->Combine] != NULL)) 
			{
                Dest.Ptr=szCombineTypes[pItem->Item->Combine];
            } 
			else 
			{
				Dest.Ptr=&DataTypeTemp[0];
                sprintf(DataTypeTemp,"*UnknownCombine%d",pItem->Item->Combine);
            }
        }
        else if (pItem->Item->Type == ITEMTYPE_BOOK)
            Dest.Ptr="Book";
		Dest.Type=pStringType;
		return true;
	case Charges:
		if (pItem->Item->Type != ITEMTYPE_NORMAL)
			Dest.DWord=0;
		else
			Dest.DWord=pItem->Charges;
		Dest.Type=pIntType;
		return true;
	case LDoNTheme:
		Dest.Ptr=szTheme[pItem->Item->LDTheme];
		Dest.Type=pStringType;
		return true;
	case DMGBonusType:
		Dest.Ptr=szDmgBonusType[pItem->Item->DmgBonusType];
		Dest.Type=pStringType;
		return true;
	}
	return false;
#undef pItem
}

bool MQ2MathType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	if (!Index[0])
		return false;
	switch((MathMembers)pMember->ID)
	{
	case Abs:
		Dest.Float=(FLOAT)Calculate(Index);
		if (Dest.Float<0)
			Dest.Float*=-1;
		Dest.Type=pFloatType;
		return true;
	case Rand:
		Dest.DWord=atol(Index);
		if (Dest.DWord==0 || Dest.DWord==0xFFFFFFFF)
			return false;
		Dest.DWord=rand() % Dest.DWord;
		Dest.Type=pIntType;
		return true;
	case Calc:
		Dest.Float=(float)Calculate(Index);
		Dest.Type=pFloatType;
		return true;
	case Sin:
		Dest.Float=(float)sin(Calculate(Index)/DegToRad);
		Dest.Type=pFloatType;
		return true;
	case Cos:
		Dest.Float=(float)cos(Calculate(Index)/DegToRad);
		Dest.Type=pFloatType;
		return true;
	case Tan:
		Dest.Float=(float)tan(Calculate(Index)/DegToRad);
		Dest.Type=pFloatType;
		return true;
	case Asin:
		Dest.Float=(float)(asin(Calculate(Index))*DegToRad);
		Dest.Type=pFloatType;
		return true;
	case Acos:
		Dest.Float=(float)(acos(Calculate(Index))*DegToRad);
		Dest.Type=pFloatType;
		return true;
	case Atan:
		Dest.Float=(float)(atan(Calculate(Index))*DegToRad);
		Dest.Type=pFloatType;
		return true;
	case Not:
		Dest.DWord=~atol(Index);
		Dest.Type=pIntType;
		return true;
	case Hex:
		sprintf(DataTypeTemp,"%x",atol(Index));
		Dest.Ptr=&DataTypeTemp[0];
		Dest.Type=pStringType;
		return true;
	case Dec:
		sscanf(Index,"%x",&Dest.DWord);
		Dest.Type=pIntType;
		return true;
	}
	return false;
}
bool MQ2MerchantType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2WindowType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pWnd ((PCSIDLWND)Ptr)
	if (!Ptr)
		return false;
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((WindowMembers)pMember->ID)
	{
	case Open:
		Dest.DWord=pWnd->Show;
		Dest.Type=pBoolType;
		return true;
	case Child:
		if (Dest.Ptr=((CSidlScreenWnd*)Ptr)->GetChildItem(CXStr(Index)))
		{
			Dest.Type=pWindowType;
			return true;
		}
		return false;
	case Parent:
		if (Dest.Ptr=pWnd->pParentWindow)
		{
			Dest.Type=pWindowType;
			return true;
		}
		return false;
	case VScrollMax:
		Dest.DWord=pWnd->VScrollMax;
		Dest.Type=pIntType;
		return true;
	case VScrollPos:
		Dest.DWord=pWnd->VScrollPos;
		Dest.Type=pIntType;
		return true;
	case VScrollPct:
		Dest.DWord=(pWnd->VScrollPos*100)/pWnd->VScrollMax;
		Dest.Type=pIntType;
		return true;
	case HScrollMax:
		Dest.DWord=pWnd->HScrollMax;
		Dest.Type=pIntType;
		return true;
	case HScrollPos:
		Dest.DWord=pWnd->HScrollPos;
		Dest.Type=pIntType;
		return true;
	case HScrollPct:
		Dest.DWord=(pWnd->HScrollPos*100)/pWnd->HScrollMax;
		Dest.Type=pIntType;
		return true;
	}

	return false;
#undef pWnd
}
bool MQ2ZoneType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2BodyType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2DeityType::GetMember(void *Ptr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
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
