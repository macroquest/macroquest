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
class MQ2CorpseType *pCorpseType=0;
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
	pCorpseType = new MQ2CorpseType;
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
	delete pCorpseType;
}

bool MQ2FloatType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((FloatMembers)pMember->ID)
	{
	case Deci:
		sprintf(DataTypeTemp,"%.1f",VarPtr.Float);
		Dest.Type=pStringType;
		Dest.Ptr=&DataTypeTemp[0];
		return true;
	case Centi:
		sprintf(DataTypeTemp,"%.2f",VarPtr.Float);
		Dest.Type=pStringType;
		Dest.Ptr=&DataTypeTemp[0];
		return true;
	case Milli:
		sprintf(DataTypeTemp,"%.3f",VarPtr.Float);
		Dest.Type=pStringType;
		Dest.Ptr=&DataTypeTemp[0];
		return true;
	case Int:
		Dest.Type=pIntType;
		Dest.Int=(int)(VarPtr.Float);
		return true;
	case Precision:
		if (Index[0]>='0' && Index[0]<='9')
		{
			sprintf(DataTypeTemp,"%.*f",atoi(Index),VarPtr.Float);
			Dest.Type=pStringType;
			Dest.Ptr=&DataTypeTemp[0];
			return true;
		}
		return false;
	}
	return false;
}

bool MQ2IntType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
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
		Dest.Float=(FLOAT)1.0f*(VarPtr.Int);
		Dest.Type=pFloatType;
		return true;
	case Hex:
		sprintf(DataTypeTemp,"%x",VarPtr.Int);
		Dest.Ptr=&DataTypeTemp[0],
		Dest.Type=pStringType;
		return true;
	case Reverse:
		{
			Dest.Array[0]=VarPtr.Array[3];
			Dest.Array[1]=VarPtr.Array[2];
			Dest.Array[2]=VarPtr.Array[1];
			Dest.Array[3]=VarPtr.Array[0];
			Dest.Type=pIntType;
		}
		return true;
	}
	return false;
}

bool MQ2SpawnType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	if (!VarPtr.Ptr)
		return false;
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
#define pSpawn ((PSPAWNINFO)VarPtr.Ptr)
	switch((SpawnMembers)pMember->ID)
	{
	case Level:
		Dest.DWord=pSpawn->Level;
		Dest.Type=pIntType;
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
		switch(GetSpawnType(pSpawn))
		{
		case MOUNT:
			Dest.Ptr="Mount";
			Dest.Type=pStringType;
			return true;
		case NPC:
			Dest.Ptr="NPC";
			Dest.Type=pStringType;
			return true;
		case PC:
			Dest.Ptr="PC";
			Dest.Type=pStringType;
			return true;
		case TRIGGER:
			Dest.Ptr="Trigger";
			Dest.Type=pStringType;
			return true;
		case PET:
			Dest.Ptr="Pet";
			Dest.Type=pStringType;
			return true;
		case ITEM:
			Dest.Ptr="Item";
			Dest.Type=pStringType;
			return true;
		case CORPSE:
			Dest.Ptr="Corpse";
			Dest.Type=pStringType;
			return true;
		}
		return false;
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
	case Distance:
		Dest.Float=GetDistance(pSpawn->X,pSpawn->Y);
		Dest.Type=pFloatType;
		return true;
	case Distance3D:
		Dest.Float=DistanceToSpawn3D((PSPAWNINFO)pCharSpawn,pSpawn);
		Dest.Type=pFloatType;
		return true;
	case DistancePredict:
		Dest.Float=EstimatedDistanceToSpawn((PSPAWNINFO)pCharSpawn,pSpawn);
		Dest.Type=pFloatType;
		return true;
	case DistanceX:
		Dest.Float=(FLOAT)fabs(((PSPAWNINFO)pCharSpawn)->X-pSpawn->X);
		Dest.Type=pFloatType;
		return true;
	case DistanceY:
		Dest.Float=(FLOAT)fabs(((PSPAWNINFO)pCharSpawn)->Y-pSpawn->Y);
		Dest.Type=pFloatType;
		return true;
	case DistanceZ:
		Dest.Float=(FLOAT)fabs(((PSPAWNINFO)pCharSpawn)->Z-pSpawn->Z);
		Dest.Type=pFloatType;
		return true;
	case HeadingTo:
        Dest.Float=(FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - pSpawn->Y, pSpawn->X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
        if (Dest.Float<0.0f) 
			Dest.Float += 360.0f;
		else if (Dest.Float>=360.0f) 
			Dest.Float -= 360.0f;
		Dest.Type=pFloatType;
		return true;
	case Casting:
		if (Dest.Ptr=GetSpellByID(pSpawn->pActorInfo->CastingSpellID))
		{
			Dest.Type=pSpellType;
			return true;
		}
		return false;
	case Mount:
		if (Dest.Ptr=pSpawn->pActorInfo->Mount)
		{
			Dest.Type=pSpawnType;
			return true;
		}
		return false;
	}
	return false;
#undef pSpawn
}

bool MQ2BuffType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pBuff ((PSPELLBUFF)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	if ((int)pBuff->SpellID<=0)
		return false;
	unsigned long N=MemberMap[Member];
	if (!N)
	{
		if (PSPELL pSpell=GetSpellByID(pBuff->SpellID))
		{
			return pSpellType->GetMember(*(MQ2VARPTR*)&pSpell,Member,Index,Dest);
		}
		return false;
	}
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	
	static CHAR Temp[128];
	switch((BuffMembers)pMember->ID)
	{
	case ID:
		Dest.DWord=pBuff->SpellID;
		Dest.Type=pIntType;
		return true;
	case Level:
		Dest.DWord=pBuff->Level;
		Dest.Type=pIntType;
		return true;
	case Spell:
		if (Dest.Ptr=GetSpellByID(pBuff->SpellID))
		{
			Dest.Type=pSpellType;
			return true;
		}
		return false;
	case Mod:
		Dest.Float=(((float)pBuff->Modifier)/10.0f);
		Dest.Type=pFloatType;
		return true;
	case Duration:
		Dest.DWord=pBuff->Duration;
		Dest.Type=pTicksType;
		return true;
	case Dar:
		Dest.DWord=pBuff->DamageAbsorbRemaining;
		Dest.Type=pIntType;
		return true;
	}
	return false;
#undef pBuff
}

bool MQ2StringType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	if (!VarPtr.Ptr)
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
		Dest.DWord=strlen((const char *)VarPtr.Ptr);
		Dest.Type=pIntType;
		return true;
	case Left:
		if (!Index[0])
			return false;
		{
			unsigned long Len=atoi(Index);
			unsigned long StrLen=strlen((char *)VarPtr.Ptr);
			if (Len>StrLen)
				Len=StrLen;
			memmove(DataTypeTemp,(char *)VarPtr.Ptr,Len);
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
			char *pStart=(char*)VarPtr.Ptr;
			pStart=&pStart[strlen(pStart)-Len];
			if (pStart<VarPtr.Ptr)
				pStart=(char*)VarPtr.Ptr;
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
			strcpy(A,(char*)VarPtr.Ptr);
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
		strcpy(DataTypeTemp,(char*)VarPtr.Ptr);
		strupr(DataTypeTemp);
		Dest.Ptr=&DataTypeTemp[0];
		Dest.Type=pStringType;
		return true;
	case Lower:
		strcpy(DataTypeTemp,(char*)VarPtr.Ptr);
		strlwr(DataTypeTemp);
		Dest.Ptr=&DataTypeTemp[0];
		Dest.Type=pStringType;
		return true;
	case Compare:
		Dest.Int=stricmp((char*)VarPtr.Ptr,Index);
		Dest.Type=pIntType;
		return true;
	case CompareCS:
		Dest.Int=strcmp((char*)VarPtr.Ptr,Index);
		Dest.Type=pIntType;
		return true;
	case Mid:
		{
			if (PCHAR pComma=strchr(Index,','))
			{
				*pComma=0;
				pComma++;
				PCHAR pStr=(char *)VarPtr.Ptr;
				unsigned long nStart=atoi(Index);
				unsigned long Len=atoi(pComma);
				if (nStart>=strlen(pStr))
				{
					Dest.Ptr="";
					Dest.Type=pStringType;
					return true;
				}
				pStr+=nStart;
				unsigned long StrLen=strlen(pStr);
				if (Len>StrLen)
					Len=StrLen;
				memmove(DataTypeTemp,pStr,Len);
				DataTypeTemp[Len]=0;
				Dest.Ptr=&DataTypeTemp[0];
				Dest.Type=pStringType;
				return true;
			}
		}
		return false;
	/*
	Arg
	/**/
	}
	return false;
}
bool MQ2CharacterType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	#define pChar ((PCHARINFO)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	unsigned long N=MemberMap[Member];
	if (!N)
		return pSpawnType->GetMember(*(MQ2VARPTR*)&pChar->pSpawn,Member,Index,Dest);
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
		if (!Index[0])
			return false;
		if (Index[0]>='0' && Index[0]<='9')
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
		else
		{
			for (unsigned long nBuff=0 ; nBuff < 15 ; nBuff++)
			{
				if (PSPELL pSpell=GetSpellByID(pChar->Buff[nBuff].SpellID))
				{
					if (!stricmp(Index,pSpell->Name))
					{
						Dest.Ptr=&pChar->Buff[nBuff];
						Dest.Type=pBuffType;
						return true;
					}
				}
			}
		}
	case Song:
		if (!Index[0])
			return false;
		if (Index[0]>='0' && Index[0]<='9')
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
		else
		{
			for (unsigned long nBuff=0 ; nBuff < 6 ; nBuff++)
			{
				if (PSPELL pSpell=GetSpellByID(pChar->ShortBuff[nBuff].SpellID))
				{
					if (!stricmp(Index,pSpell->Name))
					{
						Dest.Ptr=&pChar->ShortBuff[nBuff];
						Dest.Type=pBuffType;
						return true;
					}
				}
			}
		}
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
		Dest.Ptr=GetFullZone(pChar->ZoneBoundId);
		Dest.Type=pStringType;
		return true;
	case Combat:
		Dest.DWord=*EQADDR_ATTACK;
		Dest.Type=pBoolType;
		return true;
	case HPRegen:
		Dest.DWord=HealthGained;
		Dest.Type=pIntType;
		return true;
	case ManaRegen:
		Dest.DWord=ManaGained;
		Dest.Type=pIntType;
		return true;
	case Dar:
		Dest.DWord=0;
		{
			for (unsigned long k=0; k<15 ; k++)
				Dest.DWord+=pChar->Buff[k].DamageAbsorbRemaining;
		}
		Dest.Type=pIntType;
		return true;
	case Grouped:
		Dest.DWord=pChar->Grouped;
		Dest.Type=pBoolType;
		return true;
	case Gem:
		if (!Index[0])
			return false;
		if (Index[0]>='0' && Index[0]<='9')
		{
			// number
			unsigned long nGem=atoi(Index)-1;
			if (nGem<8)
			{
				if (Dest.Ptr=GetSpellByID(pChar->MemorizedSpells[nGem]))
				{
					Dest.Type=pSpellType;
					return true;
				}
			}
		}
		else
		{
			// name
			for (unsigned long nGem=0 ; nGem < 8 ; nGem++)
			{
				if (PSPELL pSpell=GetSpellByID(pChar->MemorizedSpells[nGem]))
				{
					if (!stricmp(Index,pSpell->Name))
					{
						Dest.DWord=nGem+1;
						Dest.Type=pIntType;
						return true;
					}
				}
			}
		}
		return false;
		/*
		Book=20,
		Skill=21,
		Ability=22,
		FreeInventory
		SpellReady
		GroupLeaderExp=46,
		RaidLeaderExp=47,
		GroupLeaderPoints=48,
		RaidLeaderPoints=49,
		Drunk,
		STR=51,
		STA=52,
		CHA=53,
		DEX=54,
		INT=55,
		AGI=56,
		WIS=57,
		svMagic=58,
		svFire=59,
		svCold=60,
		svPoison=61,
		svDisease=62
		Hunger
		Thirst
		/**/
	}
	return false;
#undef pChar
}
bool MQ2SpellType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pSpell ((PSPELL)VarPtr.Ptr)
	if (!VarPtr.Ptr)
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
	case MyCastTime:
		Dest.Float=(FLOAT)(pCharData->GetFocusCastingTimeModifier((EQ_Spell*)pSpell,0)+pSpell->CastTime)/1000.0f;
		Dest.Type=pFloatType;
		return true;
	case Duration:
		Dest.DWord=GetSpellDuration(pSpell,(PSPAWNINFO)pCharSpawn);
		Dest.Type=pTicksType;
		return true;
	}
	return false;
#undef pSpell
}

bool MQ2ItemType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pItem ((PCONTENTS)VarPtr.Ptr)
	if (!VarPtr.Ptr)
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
	/*
		Price=15,
		Haste=16,
		Endurance=17,
		Attack=18,
		HPRegen=19,
		ManaRegen=20,
		DamShield=21,
		WeightReduction=22,
		SizeCapacity=23,
		Combinable=24,
		Skill=25,
		Avoidance=26,
		SpellShield=27,
		StrikeThrough=28,
		StunResist=29,
		Shielding=30,
		FocusID=31,
		ProcRate=32,
		Quality=33,
		LDoNCost=34,
		AugRestrictions=35,
		AugType=36,
		AugSlot1=37,
		AugSlot2=38,
		AugSlot3=39,
		AugSlot4=40,
		AugSlot5=41,
		Damage=42,
		Range=43,
		DMGBonus=44,
		RecommendedLevel=45,
		RecommendedSkill=46,
		Delay=47,
		Light=48,
		Level=49,
		BaneDMG=50,
		Proc=51,
		SkillModValue=52,
		InstrumentType=53,
		InstrumentMod=54,
		RequiredLevel=55,
		BaneDMGType=56,
		AC=57,
		HP=58,
		Mana=59,
		STR=60,
		STA=61,
		AGI=62,
		DEX=63,
		CHA=64,
		INT=65,
		WIS=66,
		svCold=67,
		svFire=68,
		svMagic=69,
		svDisease=70,
		svPoison=71,
		Summoned=72,
		Artifact=73,
		PendingLore=74,
		LoreText=75,
	/**/
	}
	return false;
#undef pItem
}

bool MQ2MathType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
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
bool MQ2WindowType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pWnd ((PCSIDLWND)VarPtr.Ptr)
	if (!VarPtr.Ptr)
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
		if (Dest.Ptr=((CSidlScreenWnd*)VarPtr.Ptr)->GetChildItem(CXStr(Index)))
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
	case FirstChild:
		if (Dest.Ptr=pWnd->pChildren)
		{
			Dest.Type=pWindowType;
			return true;
		}
		return false;
	case Next:
		if (Dest.Ptr=pWnd->pSiblings)
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
	case Children:
		Dest.DWord=pWnd->HasChildren;
		Dest.Type=pBoolType;
		return true;
	case Siblings:
		Dest.DWord=pWnd->HasSiblings;
		Dest.Type=pBoolType;
		return true;
	case Minimized:
		Dest.DWord=pWnd->Minimized;
		Dest.Type=pBoolType;
		return true;
	case MouseOver:
		Dest.DWord=pWnd->MouseOver;
		Dest.Type=pBoolType;
		return true;
	case X:
		Dest.DWord=pWnd->Location.left;
		Dest.Type=pIntType;
		return true;
	case Y:
		Dest.DWord=pWnd->Location.top;
		Dest.Type=pIntType;
		return true;
	case Width:
		Dest.DWord=pWnd->Location.right-pWnd->Location.left;
		Dest.Type=pIntType;
		return true;
	case Height:
		Dest.DWord=pWnd->Location.bottom-pWnd->Location.top;
		Dest.Type=pIntType;
		return true;
	case BGColor:
		Dest.Argb=pWnd->BGColor;
		Dest.Type=pArgbType;
		return true;
	case Text:
		GetCXStr(pWnd->WindowText,DataTypeTemp,MAX_STRING);
		Dest.Ptr=&DataTypeTemp[0];
		Dest.Type=pStringType;
		return true;
	case Tooltip:
		GetCXStr(pWnd->Tooltip,DataTypeTemp,MAX_STRING);
		Dest.Ptr=&DataTypeTemp[0];
		Dest.Type=pStringType;
		return true;
	}

	return false;
#undef pWnd
}
bool MQ2ZoneType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pZone ((PZONEINFO)pZoneInfo)
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((ZoneMembers)pMember->ID)
	{
	case Name:
		Dest.Ptr=&pZone->LongName[0];
		Dest.Type=pStringType;
		return true;
	case ShortName:
		Dest.Ptr=&pZone->ShortName[0];
		Dest.Type=pStringType;
		return true;
	case Type:
		Dest.DWord=pZone->ZoneType;
		Dest.Type=pIntType;
		return true;
	case Gravity:
		Dest.Float=pZone->ZoneGravity;
		Dest.Type=pFloatType;
		return true;
	case SkyType:
		Dest.DWord=pZone->SkyType;
		Dest.Type=pIntType;
		return true;
	case SafeY:
		Dest.Float=pZone->SafeYLoc;
		Dest.Type=pFloatType;
		return true;
	case SafeX:
		Dest.Float=pZone->SafeXLoc;
		Dest.Type=pFloatType;
		return true;
	case SafeZ:
		Dest.Float=pZone->SafeZLoc;
		Dest.Type=pFloatType;
		return true;
	case MinClip:
		Dest.Float=pZone->MinClip;
		Dest.Type=pFloatType;
		return true;
	case MaxClip:
		Dest.Float=pZone->MaxClip;
		Dest.Type=pFloatType;
		return true;
	}
	return false;
#undef pZone
}
bool MQ2BodyType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((BodyMembers)pMember->ID)
	{
	case ID:
		Dest.Ptr=VarPtr.Ptr;
		Dest.Type=pIntType;
		return true;
	case Name:
		Dest.Ptr=pEverQuest->GetBodyTypeDesc(VarPtr.DWord);
		Dest.Type=pStringType;
		return true;
	}
	return false;
}
bool MQ2DeityType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((DeityMembers)pMember->ID)
	{
	case ID:
		Dest.Ptr=VarPtr.Ptr;
		Dest.Type=pIntType;
		return true;
	case Name:
		Dest.Ptr=pEverQuest->GetDeityDesc(VarPtr.DWord);
		Dest.Type=pStringType;
		return true;
	case Team:
		Dest.Ptr=szDeityTeam[GetDeityTeamByID(VarPtr.DWord)];
		Dest.Type=pStringType;
		return true;
	}
	return false;
}
bool MQ2ClassType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((ClassMembers)pMember->ID)
	{
	case ID:
		Dest.Ptr=VarPtr.Ptr;
		Dest.Type=pIntType;
		return true;
	case Name:
		Dest.Ptr=pEverQuest->GetClassDesc(VarPtr.DWord);
		Dest.Type=pStringType;
		return true;
	case ShortName:
		Dest.Ptr=pEverQuest->GetClassThreeLetterCode(VarPtr.DWord);
		Dest.Type=pStringType;
		return true;
	}
	return false;
}
bool MQ2RaceType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((RaceMembers)pMember->ID)
	{
	case ID:
		Dest.Ptr=VarPtr.Ptr;
		Dest.Type=pIntType;
		return true;
	case Name:
		Dest.Ptr=pEverQuest->GetRaceDesc(VarPtr.DWord);
		Dest.Type=pStringType;
		return true;
	}
	return false;
}
bool MQ2SwitchType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pSwitch ((PDOOR)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((SwitchMembers)pMember->ID)
	{
	case ID:
		Dest.DWord=pSwitch->ID;
		Dest.Type=pIntType;
		return true;
	case X:
		Dest.Float=pSwitch->X;
		Dest.Type=pFloatType;
		return true;
	case Y:
		Dest.Float=pSwitch->Y;
		Dest.Type=pFloatType;
		return true;
	case Z:
		Dest.Float=pSwitch->Z;
		Dest.Type=pFloatType;
		return true;
	case DefaultX:
		Dest.Float=pSwitch->DefaultX;
		Dest.Type=pFloatType;
		return true;
	case DefaultY:
		Dest.Float=pSwitch->DefaultY;
		Dest.Type=pFloatType;
		return true;
	case DefaultZ:
		Dest.Float=pSwitch->DefaultZ;
		Dest.Type=pFloatType;
		return true;
	case Heading:
		Dest.Float=pSwitch->Heading*0.703125f;
		Dest.Type=pFloatType;
		return true;
	case DefaultHeading:
		Dest.Float=pSwitch->DefaultHeading*0.703125f;
		Dest.Type=pFloatType;
		return true;
	case Open:
		Dest.DWord=((pSwitch->DefaultHeading != pSwitch->Heading) ||
                (pSwitch->DefaultZ != pSwitch->Z));
		Dest.Type=pBoolType;
		return true;
	case HeadingTo:
        Dest.Float=(FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - pSwitch->Y, pSwitch->X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
        if (Dest.Float<0.0f) 
			Dest.Float += 360.0f;
		else if (Dest.Float>=360.0f) 
			Dest.Float -= 360.0f;
		Dest.Type=pFloatType;
		return true;
	case Name:
		Dest.Ptr=&pSwitch->Name[0];
		Dest.Type=pStringType;
		return true;
	case Distance:
		Dest.Float=GetDistance(pSwitch->X,pSwitch->Y);
		Dest.Type=pFloatType;
		return true;
	}
	return false;
#undef pSwitch
}
bool MQ2GroundType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pGround ((PGROUNDITEM)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((GroundMembers)pMember->ID)
	{
	case ID:
		Dest.DWord=pGround->ID;
		Dest.Type=pIntType;
		return true;
	case X:
		Dest.Float=pGround->X;
		Dest.Type=pFloatType;
		return true;
	case Y:
		Dest.Float=pGround->Y;
		Dest.Type=pFloatType;
		return true;
	case Z:
		Dest.Float=pGround->Z;
		Dest.Type=pFloatType;
		return true;
	case Name:
		Dest.Ptr=&pGround->Name[0];
		Dest.Type=pStringType;
		return true;
	case Heading:
		Dest.Float=pGround->Heading*0.703125f;
		Dest.Type=pStringType;
		return true;
	case Distance:
		Dest.Float=GetDistance(pGround->X,pGround->Y);
		Dest.Type=pFloatType;
		return true;
	}
	return false;
#undef pGround
}
bool MQ2MacroType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	if (!gMacroStack)
		return false;
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((MacroMembers)pMember->ID)
	{
	case Name:
		Dest.Ptr=&gszMacroName[0];
		Dest.Type=pStringType;
		return true;
	case RunTime:
		Dest.DWord=(DWORD)((GetTickCount()-gRunning)/1000);
		Dest.Type=pIntType;
		return true;
	case Defined:
		if (!Index[0])
			return false;
		Dest.DWord=IsVariableDefined(Index);
		Dest.Type=pBoolType;
		return true;
	case Return:
		Dest.Ptr=&DataTypeTemp[0];
		strcpy(DataTypeTemp,gMacroStack->Return);
		Dest.Type=pStringType;
		return true;
	}
	return false;
}
bool MQ2MacroQuestType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	unsigned long N=MemberMap[Member];
	if (!N)
		return false;
	N--;
	PMQ2TYPEMEMBER pMember=Members[N];
	if (!pMember)
		return false;
	switch((MacroQuestMembers)pMember->ID)
	{
	case GameState:
		if (GameState==GAMESTATE_CHARSELECT)
			Dest.Ptr="CHARSELECT";
		else if (GameState==GAMESTATE_INGAME)
			Dest.Ptr="INGAME";
		else
			Dest.Ptr="UNKNOWN";
		Dest.Type=pStringType;
		return true;
	case LoginName:
		if (Dest.Ptr=GetLoginName())
		{
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case Server:
		Dest.Ptr=EQADDR_SERVERNAME;
		Dest.Type=pStringType;
		return true;
	case LastCommand:
		Dest.Ptr=&szLastCommand[0];
		Dest.Type=pStringType;
		return true;
	case LastTell:
		if (EQADDR_LASTTELL[0])
		{
			Dest.Ptr=&EQADDR_LASTTELL[0];
			Dest.Type=pStringType;
			return true;
		}
		return false;
	}
	return false;
}
bool MQ2CorpseType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}
bool MQ2MerchantType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	return false;
}

