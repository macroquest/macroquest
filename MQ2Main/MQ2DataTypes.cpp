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
class MQ2SkillType *pSkillType=0;
class MQ2AltAbilityType *pAltAbilityType=0;
class MQ2GroundType *pGroundType=0;
class MQ2SwitchType *pSwitchType=0;
class MQ2CorpseType *pCorpseType=0;
class MQ2MacroType *pMacroType=0;
class MQ2MacroQuestType *pMacroQuestType=0;
class MQ2MathType *pMathType=0;
class MQ2WindowType *pWindowType=0;
class MQ2MerchantType *pMerchantType=0;
class MQ2ZoneType *pZoneType=0;
class MQ2CurrentZoneType *pCurrentZoneType=0;
class MQ2ItemType *pItemType=0;
class MQ2DeityType *pDeityType=0;
class MQ2ArgbType *pArgbType=0;
class MQ2TypeType *pTypeType=0;
class MQ2TimeType *pTimeType=0;
class MQ2HeadingType *pHeadingType=0;
class MQ2InvSlotType *pInvSlotType=0;

class MQ2ArrayType *pArrayType=0;
class MQ2TimerType *pTimerType=0;

class MQ2PluginType *pPluginType=0;

class MQ2RaidType *pRaidType=0;
class MQ2RaidMemberType *pRaidMemberType=0;


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
	pCurrentZoneType = new MQ2CurrentZoneType;
	pTypeType = new MQ2TypeType;
	pTimeType = new MQ2TimeType;
	pHeadingType = new MQ2HeadingType;
	pInvSlotType = new MQ2InvSlotType;
	pArrayType = new MQ2ArrayType;
	pTimerType = new MQ2TimerType;
	pPluginType = new MQ2PluginType;
	pSkillType = new MQ2SkillType;
	pAltAbilityType = new MQ2AltAbilityType;
	pRaidType = new MQ2RaidType;
	pRaidMemberType = new MQ2RaidMemberType;


	// NOTE: SetInheritance does NOT make it inherit, just notifies the syntax checker...
	pCharacterType->SetInheritance(pSpawnType);
	pBuffType->SetInheritance(pSpellType);
	pCurrentZoneType->SetInheritance(pZoneType);
	pRaidMemberType->SetInheritance(pSpawnType);
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
	delete pCurrentZoneType;
	delete pTypeType;
	delete pTimeType;
	delete pHeadingType;
	delete pArrayType;
	delete pTimerType;
	delete pPluginType;
	delete pSkillType;
	delete pAltAbilityType;
	delete pRaidType;
	delete pRaidMemberType;
}

bool MQ2FloatType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	PMQ2TYPEMEMBER pMember=MQ2FloatType::FindMember(Member);
	if (!pMember)
	{
		return false;
	}

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
		if (IsNumber(Index))
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
	PMQ2TYPEMEMBER pMember=MQ2IntType::FindMember(Member);
	if (!pMember)
	{
		return false;
	}

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
	PMQ2TYPEMEMBER pMember=MQ2SpawnType::FindMember(Member);
	if (!pMember)
	{
		return false;
	}
	PSPAWNINFO pSpawn=(PSPAWNINFO)VarPtr.Ptr;
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
	case DisplayName:
		Dest.Ptr=&pSpawn->DisplayedName[0];
		Dest.Type=pStringType;
		return true;
	case E:
		Dest.Type=pFloatType;
		Dest.Float=-pSpawn->X;
		return true;
	case W:
	case X:
		Dest.Type=pFloatType;
		Dest.Float=pSpawn->X; 
		return true;
	case S:
		Dest.Type=pFloatType;
		Dest.Float=-pSpawn->Y;
		return true;
	case N:
	case Y:
		Dest.Type=pFloatType;
		Dest.Float=pSpawn->Y; 
		return true;
	case D:
		Dest.Type=pFloatType;
		Dest.Float=-pSpawn->Z;
		return true;
	case U:
	case Z:
		Dest.Type=pFloatType;
		Dest.Float=pSpawn->Z;
		return true;
	case Next:
		if (Dest.Ptr=pSpawn->pNext)
		{
			Dest.Type=pSpawnType;
			return true;
		}
		return false;
	case Prev:
		if (Dest.Ptr=pSpawn->pPrev)
		{
			Dest.Type=pSpawnType;
			return true;
		}
		return false;
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
		if (pSpawn->AARank!=0xFF)
			Dest.Int=pSpawn->AARank;
		else
			Dest.Int=0;
		Dest.Type=pIntType;
		return true;
	case Speed:
		Dest.Float=FindSpeed(pSpawn);
		Dest.Type=pFloatType;
		return true;
	case Heading:
		Dest.Float=pSpawn->Heading*0.703125f;
		Dest.Type=pHeadingType;
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
	case Invis:
		Dest.DWord=pSpawn->HideMode;
		Dest.Type=pBoolType;
		return true;
	case Height:
		Dest.Float=pSpawn->AvatarHeight;
		Dest.Type=pFloatType;
		return true;
	case MaxRange:
		if (GetSpawnType(pSpawn)!=ITEM)
		{
			Dest.Float=get_melee_range((EQPlayer*)pSpawn,(EQPlayer*)pSpawn); 
			Dest.Type=pFloatType;
			return true;
		}
		return false;
	case MaxRangeTo:
		if (GetSpawnType(pSpawn)!=ITEM)
		{
			Dest.Float=get_melee_range(pLocalPlayer,(EQPlayer*)pSpawn); 
			Dest.Type=pFloatType;
			return true;
		}
		return false;
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
		case UNTARGETABLE:
			Dest.Ptr="Untargetable";
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
		case CHEST:
			Dest.Ptr="Chest";
			Dest.Type=pStringType;
			return true;
		case TRAP:
			Dest.Ptr="Trap";
			Dest.Type=pStringType;
			return true;
		case TRIGGER:
			Dest.Ptr="Trigger";
			Dest.Type=pStringType;
			return true;
		case TIMER:
			Dest.Ptr="Timer";
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
		if (pSpawn->pCharInfo && pSpawn->pCharInfo->Stunned==1)
		{
			Dest.Ptr="STUN";
		}
		else
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
	case Standing:
		Dest.DWord=pSpawn->StandState==STANDSTATE_STAND;
		Dest.Type=pBoolType;
		return true;
	case Sitting:
		Dest.DWord=pSpawn->StandState==STANDSTATE_SIT;
		Dest.Type=pBoolType;
		return true;
	case Ducking:
		Dest.DWord=pSpawn->StandState==STANDSTATE_DUCK;
		Dest.Type=pBoolType;
		return true;
	case Feigning:
		Dest.DWord=pSpawn->StandState==STANDSTATE_FEIGN;
		Dest.Type=pBoolType;
		return true;
	case Binding:
		Dest.DWord=pSpawn->StandState==STANDSTATE_BIND;
		Dest.Type=pBoolType;
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
	case DistanceW:
	case DistanceX:
		Dest.Float=(FLOAT)fabs(((PSPAWNINFO)pCharSpawn)->X-pSpawn->X);
		Dest.Type=pFloatType;
		return true;
	case DistanceN:
	case DistanceY:
		Dest.Float=(FLOAT)fabs(((PSPAWNINFO)pCharSpawn)->Y-pSpawn->Y);
		Dest.Type=pFloatType;
		return true;
	case DistanceU:
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
		Dest.Type=pHeadingType;
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
	case Swimming:
		Dest.DWord=(pSpawn->pActorInfo->Swimming==5);
		Dest.Type=pBoolType;
		return true;
	case FeetWet:
		Dest.DWord=(pSpawn->pActorInfo->FeetWet==5);
		Dest.Type=pBoolType;
		return true;
	case Underwater:
		Dest.DWord=(pSpawn->pActorInfo->UnderWater==5);
		Dest.Type=pBoolType;
		return true;
	case Animation:
		Dest.DWord=pSpawn->pActorInfo->Animation;
		Dest.Type=pIntType;
		return true;
	case Holding:
		Dest.DWord=pSpawn->Holding;
		Dest.Type=pIntType;
		return true;
	case Look:
		Dest.Float=pSpawn->CameraAngle;
		Dest.Type=pFloatType;
		return true;
	case xConColor:
		switch(ConColor(pSpawn))
		{
        case CONCOLOR_GREEN:
            Dest.Ptr="GREEN";
			break;
        case CONCOLOR_LIGHTBLUE:
            Dest.Ptr="LIGHT BLUE";
			break;
        case CONCOLOR_BLUE:
            Dest.Ptr="BLUE";
			break;
        case CONCOLOR_BLACK:
            Dest.Ptr="WHITE";
			break;
        case CONCOLOR_YELLOW:
            Dest.Ptr="YELLOW";
			break;
        case CONCOLOR_RED:
		default:
			Dest.Ptr="RED";
			break;
		}
		Dest.Type=pStringType;
		return true;
	case Invited:
		Dest.DWord=(pSpawn->pActorInfo->InvitedToGroup);
		Dest.Type=pBoolType;
		return true;
	case NearestSpawn:
		if (pSpawn==(PSPAWNINFO)pCharSpawn)
		{
			return (dataNearestSpawn(Index,Dest)!=0);// use top-level object if it's you
		}
		if (Index[0])
		{
			PCHAR pSearch;
			unsigned long nth;
			SEARCHSPAWN ssSpawn;
			ClearSearchSpawn(&ssSpawn);
			ssSpawn.FRadius=999999.0f;
			if (pSearch=strchr(Index,','))
			{
				*pSearch=0;
				++pSearch;
				ParseSearchSpawn(pSearch,&ssSpawn);
				nth=atoi(Index);
			}
			else
			{
				if (IsNumber(Index))
				{
					nth=atoi(Index);
				}
				else
				{
					nth=1;
					ParseSearchSpawn(Index,&ssSpawn);
				}
			}
			if (Dest.Ptr=NthNearestSpawn(&ssSpawn,nth,pSpawn))
			{
				Dest.Type=pSpawnType;
				return true;
			}
		}
		return false;
	case Trader:
		Dest.DWord=pSpawn->pActorInfo->Trader;
		Dest.Type=pBoolType;
		return true;
	case AFK:
		Dest.DWord=pSpawn->AFK;
		Dest.Type=pBoolType;
		return true;
	case LFG:
		Dest.DWord=pSpawn->LFG;
		Dest.Type=pBoolType;
		return true;
	case Linkdead:
		Dest.DWord=pSpawn->Linkdead;
		Dest.Type=pBoolType;
		return true;
	case AATitle:
		if (Dest.Ptr=pEverQuest->GetTitleDesc(pSpawn->Class,pSpawn->AARank,pSpawn->Gender))
		{
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case xGroupLeader:
		Dest.DWord=(pSpawn->Type==SPAWN_PLAYER && !stricmp(GroupLeader,pSpawn->Name));
		Dest.Type=pBoolType;
		return true;
	case Assist:
		if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn)
		{
			DWORD nAssist;
			PACTORINFO pCharActor=GetCharInfo()->pSpawn->pActorInfo;
//			for (nAssist=0 ; nAssist < 1 ; nAssist++)
			{
				if (pCharActor->pGroupAssistNPC[0]==pSpawn)
				{
					Dest.DWord=1;
					Dest.Type=pBoolType;
					return true;
				}
			}
			for (nAssist=0 ; nAssist < 3 ; nAssist++)
			{
				if (pCharActor->pRaidAssistNPC[nAssist]==pSpawn)
				{
					Dest.DWord=1;
					Dest.Type=pBoolType;
					return true;
				}
			}
		}
		Dest.DWord=0;
		Dest.Type=pBoolType;
		return true;
	case Mark:
		if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn)
		{
			DWORD nMark;
			PACTORINFO pCharActor=GetCharInfo()->pSpawn->pActorInfo;
			for (nMark=0 ; nMark < 3 ; nMark++)
			{
				if (pCharActor->pRaidMarkNPC[nMark]==pSpawn)
				{
					Dest.DWord=nMark+1;
					Dest.Type=pIntType;
					return true;
				}
			}
			for (nMark=0 ; nMark < 3 ; nMark++)
			{
				if (pCharActor->pGroupMarkNPC[nMark]==pSpawn)
				{
					Dest.DWord=nMark+1;
					Dest.Type=pIntType;
					return true;
				}
			}
		}
		return false;
	case Anonymous:
		Dest.DWord=(pSpawn->Anon==1);
		Dest.Type=pBoolType;
		return true;
	case Roleplaying:
		Dest.DWord=(pSpawn->Anon==2);
		Dest.Type=pBoolType;
		return true;
	case xLineOfSight:
		Dest.DWord=(LineOfSight(GetCharInfo()->pSpawn,pSpawn));
		Dest.Type=pBoolType;
		return true;
	}
	return false;
}

bool MQ2BuffType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pBuff ((PSPELLBUFF)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	if ((int)pBuff->SpellID<=0)
		return false;
	PMQ2TYPEMEMBER pMember=MQ2BuffType::FindMember(Member);
	if (!pMember)
	{
		if (PSPELL pSpell=GetSpellByID(pBuff->SpellID))
		{
			return pSpellType->GetMember(*(MQ2VARPTR*)&pSpell,Member,Index,Dest);
		}
	}
	
	static CHAR Temp[128];
	switch((BuffMembers)pMember->ID)
	{
	case ID:
		{
			PCHARINFO pChar=GetCharInfo();
			unsigned long N=0;
			for (N = 0 ; N < 6 ; N++)
			{
				if (&pChar->ShortBuff[N]==pBuff)
				{
					Dest.DWord=N+1;
					Dest.Type=pIntType;
					return true;
				}
			}
			for (N = 0 ; N < 15 ; N++)
			{
				if (&pChar->Buff[N]==pBuff)
				{
					Dest.DWord=N+1;
					Dest.Type=pIntType;
					return true;
				}
			}
		}
		return false;
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
		if (Dest.Float!=1.0f)
		{
			Dest.Type=pFloatType;
			return true;
		}
		return false;
	case Duration:
		Dest.DWord=pBuff->Duration+1;// 0 is actually 6 seconds ;)
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
	PMQ2TYPEMEMBER pMember=MQ2StringType::FindMember(Member);
	if (!pMember)
	{
		return false;
	}

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
			int Len=atoi(Index);
			if (Len==0)
				return false;
			if (Len>0)
			{
				unsigned long StrLen=strlen((char *)VarPtr.Ptr);
				if ((unsigned long)Len>StrLen)
					Len=StrLen;
				memmove(DataTypeTemp,(char *)VarPtr.Ptr,Len);
				DataTypeTemp[Len]=0;
				Dest.Ptr=&DataTypeTemp[0];
				Dest.Type=pStringType;
			}
			else
			{
				Len=-Len;
				unsigned long StrLen=strlen((char *)VarPtr.Ptr);
				if ((unsigned long)Len>=StrLen)
				{
					Dest.Ptr="";
					Dest.Type=pStringType;
					return true;
				}
				memmove(DataTypeTemp,(char *)VarPtr.Ptr,StrLen-Len);
				DataTypeTemp[StrLen-Len]=0;
				Dest.Ptr=&DataTypeTemp[0];
				Dest.Type=pStringType;
			}
		}
		return true;
	case Right:
		if (!Index[0])
			return false;
		{	
			int Len=atoi(Index);
			if (Len==0)
				return false;
			if (Len<0)
			{
				Len=-Len;
				unsigned long StrLen=strlen((char *)VarPtr.Ptr);
				if ((unsigned long)Len>=StrLen)
				{
					Dest.Ptr="";
					Dest.Type=pStringType;
					return true;
				}
				char *pStart=(char*)VarPtr.Ptr;
				pStart=&pStart[Len];
				Len=StrLen-Len;
				memmove(DataTypeTemp,pStart,Len+1);
				Dest.Ptr=&DataTypeTemp[0];
				Dest.Type=pStringType;
			}
			else
			{
				char *pStart=(char*)VarPtr.Ptr;
				pStart=&pStart[strlen(pStart)-Len];
				if (pStart<VarPtr.Ptr)
					pStart=(char*)VarPtr.Ptr;
				memmove(DataTypeTemp,pStart,Len+1);
				Dest.Ptr=&DataTypeTemp[0];
				Dest.Type=pStringType;
			}
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
				Dest.DWord=(pFound-&A[0])+1;
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
		if (Index[0])
		{
			Dest.Int=stricmp((char*)VarPtr.Ptr,Index);
			Dest.Type=pIntType;
			return true;
		}
		return false;
	case CompareCS:
		if (Index[0])
		{
			Dest.Int=strcmp((char*)VarPtr.Ptr,Index);
			Dest.Type=pIntType;
			return true;
		}
		return false;
	case Mid:
		{
			if (PCHAR pComma=strchr(Index,','))
			{
				*pComma=0;
				pComma++;
				PCHAR pStr=(char *)VarPtr.Ptr;
				unsigned long nStart=atoi(Index)-1;
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
	case Equal:
		if (Index[0])
		{
			Dest.DWord=(stricmp((char*)VarPtr.Ptr,Index)==0);
			Dest.Type=pBoolType;
			return true;
		}
		return false;
	case NotEqual:
		if (Index[0])
		{
			Dest.DWord=(stricmp((char*)VarPtr.Ptr,Index)!=0);
			Dest.Type=pBoolType;
			return true;
		}
		return false;
	case EqualCS:
		if (Index[0])
		{
			Dest.DWord=(strcmp((char*)VarPtr.Ptr,Index)==0);
			Dest.Type=pBoolType;
			return true;
		}
		return false;
	case NotEqualCS:
		if (Index[0])
		{
			Dest.DWord=(strcmp((char*)VarPtr.Ptr,Index)!=0);
			Dest.Type=pBoolType;
			return true;
		}
		return false;
	case Count:
		if (Index[0])
		{
			Dest.DWord=0;
			PCHAR pLast=(PCHAR)VarPtr.Ptr-1;
			while(pLast=strchr(&pLast[1],Index[0]))
				Dest.DWord++;
			Dest.Type=pIntType;
			return true;
		}
		return false;
	case Arg:
		if (IsNumberToComma(Index))
		{
			CHAR Temp[MAX_STRING]={0};
			strcpy(Temp,(char *)VarPtr.Ptr);
			if (PCHAR pComma=strchr(Index,','))
			{
				*pComma=0;
				GetArg(DataTypeTemp,Temp,atoi(Index),FALSE,FALSE,FALSE,pComma[1]);
				*pComma=',';
				if (DataTypeTemp[0])
				{
					Dest.Ptr=&DataTypeTemp[0];
					Dest.Type=pStringType;
					return true;
				}
			}
			else
			{
				GetArg(DataTypeTemp,Temp,atoi(Index));
				if (DataTypeTemp[0])
				{
					Dest.Ptr=&DataTypeTemp[0];
					Dest.Type=pStringType;
					return true;
				}
			}
		}
		return false;
	case Token:
		if (IsNumberToComma(Index))
		{
			DWORD N=atoi(Index);
			if (!N)
				return false;
//			CHAR Temp[MAX_STRING]={0};
//			strcpy(Temp,(char *)VarPtr.Ptr);
			if (PCHAR pComma=strchr(Index,','))
			{
				*pComma=0;
				PCHAR pPos=(PCHAR)VarPtr.Ptr;//strchr((char *)VarPtr.Ptr,pComma[1]);
				N--;
				while(N && pPos)
				{
					pPos=strchr(&pPos[1],pComma[1]);
					N--;
				}
				*pComma=',';
				if (pPos)
				{
					if (pPos!=(PCHAR)VarPtr.Ptr)
						pPos++;
					PCHAR pEnd=strchr(&pPos[0],pComma[1]);
					if (pEnd)
					{
						if (pEnd!=pPos)
						{
							strncpy(DataTypeTemp,pPos,pEnd-pPos);
							DataTypeTemp[pEnd-pPos]=0;
						}
						else
							DataTypeTemp[0]=0;
					}
					else
						strcpy(DataTypeTemp,pPos);
					// allows empty returned strings
					Dest.Ptr=&DataTypeTemp[0];
					Dest.Type=pStringType;
					return true;
				}
			}
		}
		return false;
	}
	return false;
}
bool MQ2CharacterType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	#define pChar ((PCHARINFO)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMEMBER pMember=MQ2CharacterType::FindMember(Member);
	if (!pMember)
	{
		return pSpawnType->GetMember(*(MQ2VARPTR*)&pChar->pSpawn,Member,Index,Dest);
	}
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
	case PctExp:
		Dest.Float=(float)pChar->Exp/3.30f;
		Dest.Type=pFloatType;
		return true;
	case PctAAExp:
		Dest.Float=(float)pChar->AAExp/3.30f;
		Dest.Type=pFloatType;
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
		{
			if (unsigned long Temp=GetMaxMana())
				Dest.DWord=pChar->Mana*100/Temp;
			else
				Dest.DWord=0;
			Dest.Type=pIntType;
		}
		return true;
	case CountBuffs:
		Dest.DWord=0;
		{
			for (unsigned long nBuff=0 ; nBuff<15 ; nBuff++)
			{
				if (pChar->Buff[nBuff].SpellID>0)
					Dest.DWord++;
			}
			Dest.Type=pIntType;
		}
		return true;
	case Buff:
		if (!Index[0])
			return false;
		if (IsNumber(Index))
		{
			unsigned long nBuff=atoi(Index)-1;
			if (nBuff>=15)
				return false;
			if (pChar->Buff[nBuff].SpellID<=0)
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
		return false;
	case Song:
		if (!Index[0])
			return false;
		if (IsNumber(Index))
		{
			unsigned long nBuff=atoi(Index)-1;
			if (nBuff>=6)
				return false;
			if (pChar->ShortBuff[nBuff].SpellID<=0)
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
	case MaxEndurance:
		Dest.DWord=GetMaxEndurance();
		Dest.Type=pIntType;
		return true;
	case PctEndurance:
		{
			if (unsigned long Temp=GetMaxEndurance())
				Dest.DWord=(pChar->Endurance*100)/Temp;
			else
				Dest.DWord=0;
			Dest.Type=pIntType;
		}
		return true;
	case GukEarned:
		return false;//TODO
//		Dest.DWord=pChar->GukEarned;
		Dest.Type=pIntType;
		return true;
	case MMEarned:
		return false;//TODO
//		Dest.DWord=pChar->MMEarned;
		Dest.Type=pIntType;
		return true;
	case RujEarned:
		return false;//TODO
//		Dest.DWord=pChar->RujEarned;
		Dest.Type=pIntType;
		return true;
	case TakEarned:
		return false;//TODO
//		Dest.DWord=pChar->TakEarned;
		Dest.Type=pIntType;
		return true;
	case MirEarned:
		return false;//TODO
//		Dest.DWord=pChar->MirEarned;
		Dest.Type=pIntType;
		return true;
	case LDoNPoints:
		return false;//TODO
//		Dest.DWord=pChar->LDoNPoints;
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
			if (IsNumber(Index))
			{
				unsigned long nSlot=atoi(Index)%0x1E;
				if (nSlot<0x1E)
				{
					if (Dest.Ptr=pChar->InventoryArray[nSlot])
					{
						Dest.Type=pItemType;
						return true;
					}
				}
			}
			else
			{
				for (unsigned long nSlot=0 ; szItemSlot[nSlot] ; nSlot++)
				{
					if (!stricmp(Index,szItemSlot[nSlot]))
					{
						if (Dest.Ptr=pChar->InventoryArray[nSlot])
						{
							Dest.Type=pItemType;
							return true;
						}
					}
				}
			}
		}
		return false;
	case Bank:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				unsigned long nSlot=atoi(Index)-1;
				if (nSlot<NUM_BANK_SLOTS)
				{
					if (Dest.Ptr=pChar->Bank[nSlot])
					{
						Dest.Type=pItemType;
						return true;
					}
				}
			}
		}
		return false;
	case PlatinumShared:
		Dest.DWord=pChar->BankSharedPlat;
		Dest.Type=pIntType;
		return true;
	case Cash:
		Dest.DWord=pChar->Plat*1000+pChar->Gold*100+pChar->Silver*10+pChar->Copper;
		Dest.Type=pIntType;
		return true;
	case Platinum:
		Dest.DWord=pChar->Plat;
		Dest.Type=pIntType;
		return true;
	case Gold:
		Dest.DWord=pChar->Gold;
		Dest.Type=pIntType;
		return true;
	case Silver:
		Dest.DWord=pChar->Silver;
		Dest.Type=pIntType;
		return true;
	case Copper:
		Dest.DWord=pChar->Copper;
		Dest.Type=pIntType;
		return true;
	case CashBank:
		Dest.DWord=pChar->BankPlat*1000+pChar->BankGold*100+pChar->BankSilver*10+pChar->BankCopper;
		Dest.Type=pIntType;
		return true;
	case PlatinumBank:
		Dest.DWord=pChar->BankPlat;
		Dest.Type=pIntType;
		return true;
	case GoldBank:
		Dest.DWord=pChar->BankGold;
		Dest.Type=pIntType;
		return true;
	case SilverBank:
		Dest.DWord=pChar->BankSilver;
		Dest.Type=pIntType;
		return true;
	case CopperBank:
		Dest.DWord=pChar->BankCopper;
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
		Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[pChar->ZoneBoundId];
		Dest.Type=pZoneType;
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
		Dest.DWord=pChar->GroupMember1[0];
		Dest.Type=pBoolType;
		return true;
	case Gem:
		if (!Index[0])
			return false;
		if (IsNumber(Index))
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
	case CombatAbility:
		if (!Index[0])
			return false;
		if (IsNumber(Index))
		{
			// number
			unsigned long nCombatAbility=atoi(Index)-1;
			if (nCombatAbility<50)
			{
				if (Dest.Ptr=GetSpellByID(pChar->CombatAbilities[nCombatAbility]))
				{
					Dest.Type=pSpellType;
					return true;
				}
			}
		}
		else
		{
			// name
			for (unsigned long nCombatAbility=0 ; nCombatAbility < 50 ; nCombatAbility++)
			{
				if (PSPELL pSpell=GetSpellByID(pChar->CombatAbilities[nCombatAbility]))
				{
					if (!stricmp(Index,pSpell->Name))
					{
						Dest.DWord=nCombatAbility+1;
						Dest.Type=pIntType;
						return true;
					}
				}
			}
		}
		return false;
	case CombatAbilityTimer:
		// in progress...
		return false;
	case Moving:
		Dest.DWord=((((gbMoving) && ((PSPAWNINFO)pCharSpawn)->SpeedRun==0.0f) && (pChar->pSpawn->pActorInfo->Mount ==  NULL )) || (fabs(FindSpeed((PSPAWNINFO)pCharSpawn)) > 0.0f ));
		Dest.Type=pBoolType;
		return true;
	case Hunger:
		Dest.DWord=pChar->hungerlevel;
		Dest.Type=pIntType;
		return true;
	case Thirst:
		Dest.DWord=pChar->thirstlevel;
		Dest.Type=pIntType;
		return true;
		/*
	case AltAbilityTimer:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				unsigned long nAbility=atoi(Index);
				if (nAbility<NUM_ALT_ABILITIES)
				{
					if (pCharData->GetAbility(nAbility))
					{
						pAltAdvManager->IsAbilityReady(pPCData,nAbility,&Dest.Int);
						if (Dest.Int<0)
							return false;
						Dest.Int/=6;
						Dest.Type=pTicksType;
						return true;
					}
				}
			}
			else
			{
				// by name
				for (unsigned long nAbility=0 ; nAbility<NUM_ALT_ABILITIES ; nAbility++)
				{
					if (PALTABILITY pAbility=((PALTADVMGR)pAltAdvManager)->Abilities[nAbility])
					{
						if (PCHAR pName=pStringTable->getString(pAbility->nName,0))
						{
							if (!stricmp(Index,pName))
							{
								if (pCharData->GetAbility(nAbility))
								{
									pAltAdvManager->IsAbilityReady(pPCData,nAbility,&Dest.Int);
									if (Dest.Int<0)
										return false;
									Dest.Int/=6;
									Dest.Type=pTicksType;
									return true;
								}
								return false;
							}
						}
					}
				}
			}
		}
		return false;
	case AltAbilityReady:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				unsigned long nAbility=atoi(Index);
				if (nAbility<NUM_ALT_ABILITIES)
				{
					if (pCharData->GetAbility(nAbility))
					{
						Dest.DWord=pAltAdvManager->IsAbilityReady(pPCData,nAbility,0);
						Dest.Type=pBoolType;
						return true;
					}
				}
			}
			else
			{
				// by name
				for (unsigned long nAbility=0 ; nAbility<NUM_ALT_ABILITIES ; nAbility++)
				{
					if (PALTABILITY pAbility=((PALTADVMGR)pAltAdvManager)->Abilities[nAbility])
					{
						if (PCHAR pName=pStringTable->getString(pAbility->nName,0))
						{
							if (!stricmp(Index,pName))
							{
								if (pCharData->GetAbility(nAbility))
								{
									Dest.DWord=pAltAdvManager->IsAbilityReady(pPCData,nAbility,0);
									Dest.Type=pBoolType;
									return true;
								}
								return false;
							}
						}
					}
				}
			}
		}
		return false;
*/
	case AltAbility:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				unsigned long nAbility=atoi(Index);
				if (nAbility<NUM_ALT_ABILITIES)
				{
					Dest.DWord=pCharData->GetAbility(nAbility);
					Dest.Type=pIntType;
					return true;
				}
			}
			else
			{
				// by name
				for (unsigned long nAbility=0 ; nAbility<NUM_ALT_ABILITIES ; nAbility++)
				{
					if (PALTABILITY pAbility=((PALTADVMGR)pAltAdvManager)->Abilities[nAbility])
					{
						if (PCHAR pName=pStringTable->getString(pAbility->nName,0))
						{
							if (!stricmp(Index,pName))
							{
								Dest.DWord=pCharData->GetAbility(nAbility);
								Dest.Type=pIntType;
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	case Skill:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				unsigned long nSkill=atoi(Index)-1;
				if (nSkill<0x64)
				{
					Dest.DWord=pChar->Skill[nSkill];
					Dest.Type=pIntType;
					return true;
				}
			}
			else
			{
				// name
				for (DWORD nSkill=0;szSkills[nSkill];nSkill++)
					if (!stricmp(Index,szSkills[nSkill]))
					{
						Dest.DWord=pChar->Skill[nSkill];
						Dest.Type=pIntType;
						return true;
					}
			}
		}
		return false;
	case Ability:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				if (unsigned long nSkill=atoi(Index))
				{
					if (nSkill<7)
					{
						nSkill+=3;
					}
					else if (nSkill<11)
					{
						nSkill-=7;
					}
					else
						return false;
                    if (EQADDR_DOABILITYLIST[nSkill]!=0xFFFFFFFF)
					{
						Dest.Ptr=szSkills[EQADDR_DOABILITYLIST[nSkill]];
						Dest.Type=pStringType;
						return true;
					}
				}
			}
			else
			{
				// name
				for (DWORD nSkill=0;szSkills[nSkill];nSkill++)
					if (!stricmp(Index,szSkills[nSkill]))
					{
						// found name
						if (pChar->Skill[nSkill]>252)
							return false;
						for (DWORD nAbility=0;nAbility<10;nAbility++)
						if (EQADDR_DOABILITYLIST[nAbility] == nSkill) 
						{
							if (nAbility<4)
								nAbility+=7;
							else
								nAbility-=3;
							Dest.DWord=nAbility;
							Dest.Type=pIntType;
							return true;
						}
					}
			}
		}
		return false;
	case AbilityReady:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				if (unsigned long nSkill=atoi(Index))
				{
					if (nSkill<7)
					{
						nSkill+=3;
					}
					else if (nSkill<11)
					{
						nSkill-=7;
					}
					else
						return false;
					/**/
                    if (EQADDR_DOABILITYLIST[nSkill]!=0xFFFFFFFF)
					{
						if (SkillDict[EQADDR_DOABILITYLIST[nSkill]]->AltTimer==2)
							Dest.DWord=gbAltTimerReady;
						else
							Dest.DWord=EQADDR_DOABILITYAVAILABLE[EQADDR_DOABILITYLIST[nSkill]];
						Dest.Type=pBoolType;
						return true;
					}
				}
			}
			else
			{
				// name
				for (DWORD nSkill=0;szSkills[nSkill];nSkill++)
					if (!stricmp(Index,szSkills[nSkill]))
					{
						// found name
						if (pChar->Skill[nSkill]>252)
							return false;
						for (DWORD nAbility=0;nAbility<10;nAbility++)
						if (EQADDR_DOABILITYLIST[nAbility] == nSkill) 
						{
							if (nAbility<4)
								nAbility+=7;
							else
								nAbility-=3;
							if (SkillDict[nSkill]->AltTimer==2)
								Dest.DWord=gbAltTimerReady;
							else
								Dest.DWord=EQADDR_DOABILITYAVAILABLE[nSkill];
							Dest.Type=pBoolType;
							return true;
						}
					}
			}
		}
		return false;
	case RangedReady:
		Dest.DWord=gbRangedAttackReady;
		Dest.Type=pBoolType;
		return true;
	case AltTimerReady:
		Dest.DWord=gbAltTimerReady;
		Dest.Type=pBoolType;
		return true;
	case Book:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				unsigned long nSpell=atoi(Index)-1;
				if (nSpell<NUM_BOOK_SLOTS)
				if (Dest.Ptr=GetSpellByID(pChar->SpellBook[nSpell]))
				{
					Dest.Type=pSpellType;
					return true;
				}
			}
			else
			{
				// name
				for (DWORD nSpell=0 ; nSpell < NUM_BOOK_SLOTS ; nSpell++)
                if (pChar->SpellBook[nSpell] != 0xFFFFFFFF)
				{
					if (!stricmp(GetSpellNameByID(pChar->SpellBook[nSpell]),Index))
					{
						Dest.DWord=nSpell+1;
						Dest.Type=pIntType;
						return true;
					}
				}
			}
		}
		return false;
	case SpellReady:
		if (pCastSpellWnd && Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				unsigned long nGem=atoi(Index)-1;
				if (nGem<8)
				{
					Dest.DWord = (((PEQCASTSPELLWINDOW)pCastSpellWnd)->SpellSlots[nGem]->spellstate==0);
					Dest.Type=pBoolType;
					return true;
				}
			}
			else
			{
				for (unsigned long nGem=0 ; nGem < 8 ; nGem++)
				{
					if (PSPELL pSpell=GetSpellByID(pChar->MemorizedSpells[nGem]))
					{
						if (!stricmp(Index,pSpell->Name))
						{
							Dest.DWord = (((PEQCASTSPELLWINDOW)pCastSpellWnd)->SpellSlots[nGem]->spellstate==0);
							Dest.Type=pBoolType;
							return true;
						}
					}
				}
			}
		}
		return false;
	case PetBuff:
		if (!Index[0] || !pPetInfoWnd)
			return false;
#define pPetInfoWindow ((PEQPETINFOWINDOW)pPetInfoWnd)
		if (IsNumber(Index))
		{
			unsigned long nBuff=atoi(Index)-1;
			if (nBuff>29)
				return false;
			if (pPetInfoWindow->Buff[nBuff]==0xFFFFFFFF || pPetInfoWindow->Buff[nBuff]==0)
				return false;
			if (Dest.Ptr=GetSpellByID(pPetInfoWindow->Buff[nBuff]))
			{
				Dest.Type=pSpellType;
				return true;
			}
		}
		else
		{
			for (unsigned long nBuff=0 ; nBuff < 29 ; nBuff++)
			{
				if (PSPELL pSpell=GetSpellByID(pPetInfoWindow->Buff[nBuff]))
				{
					if (!stricmp(Index,pSpell->Name))
					{
						Dest.DWord=nBuff+1;
						Dest.Type=pIntType;
						return true;
					}
				}
			}
		}
#undef pPetInfoWindow
		return false;
	case GroupLeaderExp:
		Dest.DWord=pChar->GroupLeadershipExp;
		Dest.Type=pIntType;
		return true;
	case RaidLeaderExp:
		Dest.DWord=pChar->RaidLeadershipExp;
		Dest.Type=pIntType;
		return true;
	case PctGroupLeaderExp:
		Dest.Float=(float)pChar->GroupLeadershipExp/10.0f;
		Dest.Type=pFloatType;
		return true;
	case PctRaidLeaderExp:
		Dest.Float=(float)pChar->RaidLeadershipExp/10.0f;
		Dest.Type=pFloatType;
		return true;
	case GroupLeaderPoints:
		Dest.DWord=pChar->GroupLeadershipPoints;
		Dest.Type=pIntType;
		return true;
	case RaidLeaderPoints:
		Dest.DWord=pChar->RaidLeadershipPoints;
		Dest.Type=pIntType;
		return true;
	case Stunned:
		Dest.DWord=(pChar->Stunned==1);
		Dest.Type=pBoolType;
		return true;
	case LargestFreeInventory:
		{
		Dest.DWord=0;
		Dest.Type=pIntType;
		for (DWORD slot=22;slot<30;slot++) 
		{
			if (PCONTENTS pItem = pChar->InventoryArray[slot]) 
			{
				if (pItem->Item->Type==ITEMTYPE_PACK && pItem->Item->SizeCapacity>Dest.DWord) 
				{
					for (DWORD pslot=0;pslot<(pItem->Item->Slots);pslot++) 
					{
						if (!pItem->Contents[pslot])
						{
							Dest.DWord=pItem->Item->SizeCapacity;
							break;// break the loop for this pack
						}
					}
				}
			} 
			else 
			{
				Dest.DWord=4;
				return true;
			}
		}
		}
		return true;
	case FreeInventory:
		if (Index[0])
		{
			DWORD nSize=atoi(Index);
			if (nSize>4)
				nSize=4;
			Dest.DWord=0;
			for (DWORD slot=22;slot<30;slot++) 
			{
				if (PCONTENTS pItem = pChar->InventoryArray[slot]) 
				{
					if (pItem->Item->Type==ITEMTYPE_PACK && pItem->Item->SizeCapacity>=nSize) 
					{
						for (DWORD pslot=0;pslot<(pItem->Item->Slots);pslot++) 
						{
							if (!pItem->Contents[pslot]) 
								Dest.DWord++;
						}
					}
				} 
				else 
				{
					Dest.DWord++;
				}
			}
			Dest.Type=pIntType; 
			return true;
		}
		else
		{
			Dest.DWord=0;
			for (DWORD slot=22;slot<30;slot++) 
			{
				if (PCONTENTS pItem = pChar->InventoryArray[slot]) 
				{
					if (pItem->Item->Type==ITEMTYPE_PACK) 
					{
						for (DWORD pslot=0;pslot<(pItem->Item->Slots);pslot++) 
						{
							if (!pItem->Contents[pslot]) 
								Dest.DWord++;
						}
					}
				} 
				else 
				{
					Dest.DWord++;
				}
			}
			Dest.Type=pIntType; 
			return true;
		}
	case Drunk:
		Dest.DWord=pChar->Drunkenness;
		Dest.Type=pIntType;
		return true;
	case TargetOfTarget:
		if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn)
		if (Dest.Ptr=pChar->pSpawn->pActorInfo->pTargetOfTarget)
		{
			Dest.Type=pSpawnType;
			return true;
		}
		return false;
	case RaidAssistTarget:
		if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn)
		if (Index[0] && IsNumber(Index))
		{
			DWORD N=atoi(Index)-1;
			if (N>=3)
				return false;
			if (Dest.Ptr=pChar->pSpawn->pActorInfo->pRaidAssistNPC[N])
			{
				Dest.Type=pSpawnType;
				return true;
			}
		}
		return false;
	case GroupAssistTarget:
		if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn)
		{
			if (Dest.Ptr=pChar->pSpawn->pActorInfo->pGroupAssistNPC[0])
			{
				Dest.Type=pSpawnType;
				return true;
			}
		}
		return false;
	case RaidMarkNPC:
		if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn)
		if (Index[0] && IsNumber(Index))
		{
			DWORD N=atoi(Index)-1;
			if (N>=3)
				return false;
			if (Dest.Ptr=pChar->pSpawn->pActorInfo->pRaidMarkNPC[N])
			{
				Dest.Type=pSpawnType;
				return true;
			}
		}
		return false;
	case GroupMarkNPC:
		if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn)
		if (Index[0] && IsNumber(Index))
		{
			DWORD N=atoi(Index)-1;
			if (N>=3)
				return false;
			if (Dest.Ptr=pChar->pSpawn->pActorInfo->pGroupMarkNPC[N])
			{
				Dest.Type=pSpawnType;
				return true;
			}
		}
		return false;
		/*
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
	PMQ2TYPEMEMBER pMember=MQ2SpellType::FindMember(Member);
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
		if (!Index[0] && GetCharInfo()->pSpawn)
		{
			Dest.DWord=pSpell->Level[GetCharInfo()->pSpawn->Class-1];
			Dest.Type=pIntType;
			return true;
		}
		else
		{
			if (IsNumber(Index))
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
		Dest.Type=pIntType;
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
	PMQ2TYPEMEMBER pMember=MQ2ItemType::FindMember(Member);
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
		Dest.DWord=!pItem->Item->NoDrop;
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
	case Container:
		if (pItem->Item->Type == ITEMTYPE_PACK)
		{
			Dest.DWord=pItem->Item->Slots;
		}
		else
			Dest.DWord=0;
		Dest.Type=pIntType;
		return true;
	case Items:
		if (pItem->Item->Type == ITEMTYPE_PACK)
		{
			Dest.DWord=0;
			for (unsigned long N=0 ; N < pItem->Item->Slots ; N++)
			{
				if (pItem->Contents[N])
					Dest.DWord++;
			}
			Dest.Type=pIntType;
			return true;
		}
		return false;
	case Item:
		if (pItem->Item->Type == ITEMTYPE_PACK && IsNumber(Index))
		{
			unsigned long N=atoi(Index);
			N--;
			if (N<pItem->Item->Slots)
			{
				if (Dest.Ptr=pItem->Contents[N])
				{
					Dest.Type=pItemType;
					return true;
				}
			}
		}
		return false;
	case Stackable:
		Dest.DWord=pItem->Item->Stackable;
		Dest.Type=pBoolType;
		return true;
	case InvSlot:
		Dest.Int=FindInvSlotForContents(pItem);
		if (Dest.Int>=0)
		{
			Dest.Type=pInvSlotType;
			return true;
		}
		return false;
	case BuyPrice:
		if (pActiveMerchant)
		{
			Dest.DWord=pItem->Price;
			Dest.Type=pIntType;
			return true;
		}
		return false;
	case SellPrice:
		if (pActiveMerchant)
		{
			Dest.DWord=(DWORD)((FLOAT)pItem->Item->Cost*(1.0f/((PEQMERCHWINDOW)pMerchantWnd)->Markup));
			Dest.Type=pIntType;
			return true;
		}
		return false;
	case WornSlot:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				DWORD Count=atoi(Index);
				if (!Count)
					return false;
				DWORD cmp=pItem->Item->EquipSlots;
				for (DWORD N = 0 ; N < 32 ; N++)
				{
					if (cmp&(1<<N))
					{
						Count--;
						if (Count==0)
						{
							Dest.DWord=N;
							Dest.Type=pInvSlotType;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				DWORD nInvSlot=ItemSlotMap[Index];
				if ((nInvSlot || !stricmp(Index,"charm")) && nInvSlot<32)
				{
					Dest.DWord=(pItem->Item->EquipSlots&(1<<nInvSlot));
					Dest.Type=pBoolType;
					return true;
				}
			}
		}
		return false;
	case WornSlots:
		{
			Dest.DWord=0;
			// count bits
			DWORD cmp=pItem->Item->EquipSlots;
			for (DWORD N = 0 ; N < 32 ; N++)
			{
				if (cmp&(1<<N))
					Dest.DWord++;
			}
			Dest.Type=pIntType;
			return true;
		}
	case CastTime:
		Dest.Float=(FLOAT)pItem->Item->CastTime/1000;
		Dest.Type=pFloatType;
		return true;
	case Spell:
		if (Dest.Ptr=GetSpellByID(pItem->Item->SpellId))
		{
			Dest.Type=pSpellType;
			return true;
		}
		return false;
	case EffectType:
		// 0 = combat
		// 1 = click inventory
		// 2 = ?
		// 3 = ?
		// 4 = click worn
		if (GetSpellByID(pItem->Item->SpellId))
		{
			switch(pItem->Item->EffectType)
			{
			case 0:
				Dest.Ptr="Combat";
				break;
			case 1:
				Dest.Ptr="Click Inventory";
				break;
			case 2:
				Dest.Ptr="Worn";
				break;
			case 3:
				Dest.Ptr="Unknown-3";
				break;
			case 4:
				Dest.Ptr="Click Worn";
				break;
			case 5:
				Dest.Ptr="Click Inventory";
				break;
			default:
				Dest.Ptr="Unknown";
				break;
			}
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case InstrumentMod:
		Dest.Float=((FLOAT)pItem->Item->InstrumentMod)/10.0f;
		Dest.Type=pFloatType;
		return true;
	case Tribute:
		Dest.DWord=pItem->Item->Favor;
		Dest.Type=pIntType;
		return true;
	/*
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
	PMQ2TYPEMEMBER pMember=MQ2MathType::FindMember(Member);
	if (!pMember)
		return false;

	if (!Index[0])
		return false;
	DOUBLE CalcResult;
	switch((MathMembers)pMember->ID)
	{
	case Abs:
		if (Calculate(Index,CalcResult))
		{
			Dest.Float=(FLOAT)CalcResult;
			if (Dest.Float<0)
				Dest.Float*=-1;
			Dest.Type=pFloatType;
			return true;
		}
		return false;
	case Rand:
		Dest.DWord=atol(Index);
		if (Dest.DWord==0 || Dest.DWord==0xFFFFFFFF)
			return false;
		Dest.DWord=rand() % Dest.DWord;
		Dest.Type=pIntType;
		return true;
	case Sqrt:
		if (Calculate(Index,CalcResult))
		{
			Dest.Float=(FLOAT)sqrt(CalcResult);
			Dest.Type=pFloatType;
			return true;
		}
		return false;
	case Calc:
		if (Calculate(Index,CalcResult))
		{
			Dest.Float=(FLOAT)CalcResult;
			Dest.Type=pFloatType;
			return true;
		}
		return false;
	case Sin:
		if (Calculate(Index,CalcResult))
		{
			Dest.Float=(float)sin(CalcResult/DegToRad);
			Dest.Type=pFloatType;
			return true;
		}
		return false;
	case Cos:
		if (Calculate(Index,CalcResult))
		{
			Dest.Float=(float)cos(CalcResult/DegToRad);
			Dest.Type=pFloatType;
			return true;
		}
		return false;
	case Tan:
		if (Calculate(Index,CalcResult))
		{
			Dest.Float=(float)tan(CalcResult/DegToRad);
			Dest.Type=pFloatType;
			return true;
		}
		return false;
	case Asin:
		if (Calculate(Index,CalcResult))
		{
			Dest.Float=(float)(asin(CalcResult)*DegToRad);
			Dest.Type=pFloatType;
			return true;
		}
		return false;
	case Acos:
		if (Calculate(Index,CalcResult))
		{
			Dest.Float=(float)(acos(CalcResult)*DegToRad);
			Dest.Type=pFloatType;
			return true;
		}
		return false;
	case Atan:
		if (Calculate(Index,CalcResult))
		{
			Dest.Float=(float)(atan(CalcResult)*DegToRad);
			Dest.Type=pFloatType;
			return true;
		}
		return false;
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
	case Distance:
		if (Index[0])
		{
			FLOAT P1[3];
			FLOAT P2[3];
			P1[0]=P2[0]=((PSPAWNINFO)pCharSpawn)->Y;
			P1[1]=P2[1]=((PSPAWNINFO)pCharSpawn)->X;
			P1[2]=P2[2]=((PSPAWNINFO)pCharSpawn)->Z;
			if (PCHAR pColon=strchr(Index,':'))
			{
				*pColon=0;
				if (PCHAR pComma=strchr(&pColon[1],','))
				{
					*pComma=0;
					P2[0]=(FLOAT)atof(&pColon[1]);
					*pComma=',';
					if (PCHAR pComma2=strchr(&pComma[1],','))
					{
						*pComma2=0;
						P2[1]=(FLOAT)atof(&pComma[1]);
						*pComma2=',';
						P2[2]=(FLOAT)atof(&pComma2[1]);
					}
					else
					{
						P2[1]=(FLOAT)atof(&pComma[1]);
					}
				}
				else
					P2[0]=(FLOAT)atof(&pColon[1]);
			}


			if (PCHAR pComma=strchr(Index,','))
			{
				*pComma=0;
				P1[0]=(FLOAT)atof(Index);
				*pComma=',';
				if (PCHAR pComma2=strchr(&pComma[1],','))
				{
					*pComma2=0;
					P1[1]=(FLOAT)atof(&pComma[1]);
					*pComma2=',';
					P1[2]=(FLOAT)atof(&pComma2[1]);
				}
				else
				{
					P1[1]=(FLOAT)atof(&pComma[1]);
				}
			}
			else
				P1[0]=(FLOAT)atof(Index);

			DebugSpew("GetDistance3D(%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f)",P1[0],P1[1],P1[2],P2[0],P2[1],P2[2]);
			Dest.Float=(FLOAT)GetDistance3D(P1[0],P1[1],P1[2],P2[0],P2[1],P2[2]);
			Dest.Type=pFloatType;
			return true;
		}
		return false;
	}
	return false;
}
bool MQ2WindowType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pWnd ((PCSIDLWND)VarPtr.Ptr)
	PMQ2TYPEMEMBER pMember=MQ2WindowType::FindMember(Member);
	if (!pMember)
		return false;

	switch((WindowMembers)pMember->ID)
	{
	case Open:
		Dest.DWord=pWnd->Show;
		Dest.Type=pBoolType;
		return true;
	case Child:
		if (Dest.Ptr=((CSidlScreenWnd*)VarPtr.Ptr)->GetChildItem(Index))
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
	case Checked:
		Dest.Int=pWnd->Checked;
		Dest.Type=pBoolType;
		return true;
	case Highlighted:
		Dest.Int=pWnd->Highlighted;
		Dest.Type=pBoolType;
		return true;
	case Enabled:
		Dest.Int=(pWnd->Enabled!=0);
		Dest.Type=pBoolType;
		return true;
	case Style:
		Dest.DWord=pWnd->WindowStyle;
		Dest.Type=pIntType;
		return true;
	case List:
		if (((CXWnd*)pWnd)->GetType()==UI_Combobox)
			VarPtr.Ptr=pWnd->SidlText;
		else if (((CXWnd*)pWnd)->GetType()!=UI_Listbox)
			return false;
		if (IsNumber(Index))
		{
			unsigned long nIndex=atoi(Index);
			if (!nIndex)
				return false;
			nIndex--;
			CXStr Str=((CListWnd*)pWnd)->GetItemText(nIndex,0);
			GetCXStr(Str.Ptr,DataTypeTemp,MAX_STRING);
			Dest.Ptr=&DataTypeTemp[0];
			Dest.Type=pStringType;
			return true;
		}
		else
		{
			// name
			BOOL bEqual=false;
			CHAR Name[MAX_STRING]={0};
			if (Index[0]=='=')
			{
				bEqual=true;
				strcpy(Name,&Index[1]);
			}
			else
				strcpy(Name,Index);
			strlwr(Name);
			unsigned long nIndex=0;
			while(1)
			{
				CXStr Str=((CListWnd*)pWnd)->GetItemText(nIndex,0);
				GetCXStr(Str.Ptr,DataTypeTemp,MAX_STRING);
				if (DataTypeTemp[0]==0)
					return false;
				
				if (bEqual)
				{
					if (!stricmp(DataTypeTemp,Name))
					{
						Dest.DWord=nIndex+1;
						Dest.Type=pIntType;
						return true;
					}
				}
				else
				{
					strlwr(DataTypeTemp);
					if (strstr(DataTypeTemp,Name))
					{
						Dest.DWord=nIndex+1;
						Dest.Type=pIntType;
						return true;
					}
				}
				nIndex++;
			} 
		}
		return false;
	case Name:
		{
			if (CXMLData *pXMLData=((CXWnd*)pWnd)->GetXMLData())
			{
				if (GetCXStr(pXMLData->Name.Ptr,DataTypeTemp,MAX_STRING))
				{
					Dest.Ptr=&DataTypeTemp[0];
					Dest.Type=pStringType;
					return true;
				}
			}
		}
		return false;
	case ScreenID:
		{
			if (CXMLData *pXMLData=((CXWnd*)pWnd)->GetXMLData())
			{
				if (GetCXStr(pXMLData->ScreenID.Ptr,DataTypeTemp,MAX_STRING))
				{
					Dest.Ptr=&DataTypeTemp[0];
					Dest.Type=pStringType;
					return true;
				}
			}
		}
		return false;
	case Type:
		{
			if (CXMLData *pXMLData=((CXWnd*)pWnd)->GetXMLData())
			{
				if (GetCXStr(pXMLData->TypeName.Ptr,DataTypeTemp,MAX_STRING))
				{
					Dest.Ptr=&DataTypeTemp[0];
					Dest.Type=pStringType;
					return true;
				}
			}
		}
		return false;
	case Items:
		if (((CXWnd*)pWnd)->GetType()==UI_Listbox)
		{
			Dest.DWord=((CSidlScreenWnd*)pWnd)->SlotID;
			Dest.Type=pIntType;
		}
		else if (((CXWnd*)pWnd)->GetType()==UI_Combobox)
		{
			Dest.DWord=((CSidlScreenWnd*)pWnd->SidlText)->SlotID;
			Dest.Type=pIntType;
		}
		return true;
	}

	return false;
#undef pWnd
}
bool MQ2CurrentZoneType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pZone ((PZONEINFO)pZoneInfo)
	PMQ2TYPEMEMBER pMember=MQ2CurrentZoneType::FindMember(Member);
	if (!pMember)
		return false;

//		return pZoneType->GetMember(*(MQ2VARPTR*)&((PWORLDDATA)pWorldData)->ZoneArray[GetCharInfo()->zoneId],Member,Index,Dest);
	switch((CurrentZoneMembers)pMember->ID)
	{
   case ID:
		Dest.Int = GetCharInfo()->zoneId;
		Dest.Type=pIntType;
		return true; 
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
#if 0
	case SafeN:
	case SafeY:
		Dest.Float=pZone->SafeYLoc;
		Dest.Type=pFloatType;
		return true;
	case SafeW:
	case SafeX:
		Dest.Float=pZone->SafeXLoc;
		Dest.Type=pFloatType;
		return true;
	case SafeU:
	case SafeZ:
		Dest.Float=pZone->SafeZLoc;
		Dest.Type=pFloatType;
		return true;
#endif
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

bool MQ2ZoneType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pZone ((PZONELIST)VarPtr.Ptr)
	PMQ2TYPEMEMBER pMember=MQ2ZoneType::FindMember(Member);
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
   case ID:
      Dest.Int=pZone->Id;
      Dest.Type=pIntType;
      return true;
   }
      return false;
#undef pZone
} 

bool MQ2BodyType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	PMQ2TYPEMEMBER pMember=MQ2BodyType::FindMember(Member);
	if (!pMember)
		return false;
	switch((BodyMembers)pMember->ID)
	{
	case ID:
		Dest.Ptr=VarPtr.Ptr;
		Dest.Type=pIntType;
		return true;
	case Name:
		Dest.Ptr=GetBodyTypeDesc(VarPtr.DWord);
		Dest.Type=pStringType;
		return true;
	}
	return false;
}
bool MQ2DeityType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	PMQ2TYPEMEMBER pMember=MQ2DeityType::FindMember(Member);
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
	PMQ2TYPEMEMBER pMember=MQ2ClassType::FindMember(Member);
	if (!pMember)
		return false;
	switch((ClassMembers)pMember->ID)
	{
	case ID:
		Dest.Ptr=VarPtr.Ptr;
		Dest.Type=pIntType;
		return true;
	case Name:
		Dest.Ptr=GetClassDesc(VarPtr.DWord);
		Dest.Type=pStringType;
		return true;
	case ShortName:
		Dest.Ptr=pEverQuest->GetClassThreeLetterCode(VarPtr.DWord);
		Dest.Type=pStringType;
		return true;
	case CanCast:
		if (VarPtr.DWord<=16)
		{
			Dest.DWord=ClassInfo[VarPtr.DWord].CanCast;
			Dest.Type=pBoolType;
			return true;
		}
		return false;
	case PureCaster:
		if (VarPtr.DWord<=16)
		{
			Dest.DWord=ClassInfo[VarPtr.DWord].PureCaster;
			Dest.Type=pBoolType;
			return true;
		}
		return false;
	case PetClass:
		if (VarPtr.DWord<=16)
		{
			Dest.DWord=ClassInfo[VarPtr.DWord].PetClass;
			Dest.Type=pBoolType;
			return true;
		}
		return false;
	case DruidType:
		if (VarPtr.DWord<=16)
		{
			Dest.DWord=ClassInfo[VarPtr.DWord].DruidType;
			Dest.Type=pBoolType;
			return true;
		}
		return false;
	case ShamanType:
		if (VarPtr.DWord<=16)
		{
			Dest.DWord=ClassInfo[VarPtr.DWord].ShamanType;
			Dest.Type=pBoolType;
			return true;
		}
		return false;
	case NecromancerType:
		if (VarPtr.DWord<=16)
		{
			Dest.DWord=ClassInfo[VarPtr.DWord].NecroType;
			Dest.Type=pBoolType;
			return true;
		}
		return false;
	case ClericType:
		if (VarPtr.DWord<=16)
		{
			Dest.DWord=ClassInfo[VarPtr.DWord].ClericType;
			Dest.Type=pBoolType;
			return true;
		}
		return false;
	}
	return false;
}
bool MQ2RaceType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	PMQ2TYPEMEMBER pMember=MQ2RaceType::FindMember(Member);
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
	PMQ2TYPEMEMBER pMember=MQ2SwitchType::FindMember(Member);
	if (!pMember)
		return false;
	switch((SwitchMembers)pMember->ID)
	{
	case ID:
		Dest.DWord=pSwitch->ID;
		Dest.Type=pIntType;
		return true;
	case W:
	case X:
		Dest.Float=pSwitch->X;
		Dest.Type=pFloatType;
		return true;
	case N:
	case Y:
		Dest.Float=pSwitch->Y;
		Dest.Type=pFloatType;
		return true;
	case U:
	case Z:
		Dest.Float=pSwitch->Z;
		Dest.Type=pFloatType;
		return true;
	case DefaultW:
	case DefaultX:
		Dest.Float=pSwitch->DefaultX;
		Dest.Type=pFloatType;
		return true;
	case DefaultN:
	case DefaultY:
		Dest.Float=pSwitch->DefaultY;
		Dest.Type=pFloatType;
		return true;
	case DefaultU:
	case DefaultZ:
		Dest.Float=pSwitch->DefaultZ;
		Dest.Type=pFloatType;
		return true;
	case Heading:
		Dest.Float=pSwitch->Heading*0.703125f;
		Dest.Type=pHeadingType;
		return true;
	case DefaultHeading:
		Dest.Float=pSwitch->DefaultHeading*0.703125f;
		Dest.Type=pHeadingType;
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
		Dest.Type=pHeadingType;
		return true;
	case Name:
		Dest.Ptr=&pSwitch->Name[0];
		Dest.Type=pStringType;
		return true;
	case Distance:
		Dest.Float=GetDistance(pSwitch->X,pSwitch->Y);
		Dest.Type=pFloatType;
		return true;
	case xLineOfSight:
		Dest.DWord=(CastRay(GetCharInfo()->pSpawn,pSwitch->Y,pSwitch->X,pSwitch->Z));
		Dest.Type=pBoolType;
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
	PMQ2TYPEMEMBER pMember=MQ2GroundType::FindMember(Member);
	if (!pMember)
		return false;
	switch((GroundMembers)pMember->ID)
	{
	case ID:
		Dest.DWord=pGround->ID;
		Dest.Type=pIntType;
		return true;
	case W:
	case X:
		Dest.Float=pGround->X;
		Dest.Type=pFloatType;
		return true;
	case N:
	case Y:
		Dest.Float=pGround->Y;
		Dest.Type=pFloatType;
		return true;
	case U:
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
		Dest.Type=pHeadingType;
		return true;
	case Distance:
		Dest.Float=GetDistance(pGround->X,pGround->Y);
		Dest.Type=pFloatType;
		return true;
	case HeadingTo:
        Dest.Float=(FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - pGround->Y, pGround->X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
        if (Dest.Float<0.0f) 
			Dest.Float += 360.0f;
		else if (Dest.Float>=360.0f) 
			Dest.Float -= 360.0f;
		Dest.Type=pHeadingType;
		return true;
	case xLineOfSight:
		Dest.DWord=(CastRay(GetCharInfo()->pSpawn,pGround->Y,pGround->X,pGround->Z));
		Dest.Type=pBoolType;
		return true;
	}
	return false;
#undef pGround
}
bool MQ2MacroType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	if (!gMacroStack)
		return false;
	PMQ2TYPEMEMBER pMember=MQ2MacroType::FindMember(Member);
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
	case Return:
		Dest.Ptr=&DataTypeTemp[0];
		strcpy(DataTypeTemp,gMacroStack->Return);
		Dest.Type=pStringType;
		return true;
	case Params:
		Dest.DWord=0;
		{
			PDATAVAR pVar=gMacroStack->Parameters;
			while(pVar)
			{
				Dest.DWord++;
				pVar=pVar->pNext;
			}
		}
		Dest.Type=pIntType;
		return true;
	/*
		TypeMember(Param);
	/**/
	}
	return false;
}
bool MQ2MacroQuestType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	PMQ2TYPEMEMBER pMember=MQ2MacroQuestType::FindMember(Member);
	if (!pMember)
		return false;
	switch((MacroQuestMembers)pMember->ID)
	{
	case GameState:
		if (gGameState==GAMESTATE_CHARSELECT)
			Dest.Ptr="CHARSELECT";
		else if (gGameState==GAMESTATE_INGAME)
			Dest.Ptr="INGAME";
		else
			Dest.Ptr="UNKNOWN";
		Dest.Type=pStringType;
		return true;
	case LoginName:
		{
			if (PCHAR pTemp=GetLoginName())
			{
				strcpy(DataTypeTemp,pTemp);
				free(pTemp);
				Dest.Ptr=&DataTypeTemp[0];
				Dest.Type=pStringType;
				return true;
			}
		}
		return false;
	case Server:
		if (EQADDR_SERVERNAME[0])
		{
			Dest.Ptr=EQADDR_SERVERNAME;
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case LastCommand:
		if (szLastCommand[0])
		{
			Dest.Ptr=&szLastCommand[0];
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case LastTell:
		if (EQADDR_LASTTELL[0])
		{
			Dest.Ptr=&EQADDR_LASTTELL[0];
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case Error:
		if (gszLastNormalError[0])// QUIT SETTING THIS MANUALLY, USE MacroError, FatalError, ETC
		{
			Dest.Ptr=&gszLastNormalError[0];
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case SyntaxError:
		if (gszLastSyntaxError[0])
		{
			Dest.Ptr=&gszLastSyntaxError[0];
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case MQ2DataError:
		if (gszLastMQ2DataError[0])
		{
			Dest.Ptr=&gszLastMQ2DataError[0];
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case Running:
		Dest.DWord=(DWORD)clock();
		Dest.Type=pIntType;
		return true;
	case MouseX:
		Dest.DWord=((PMOUSEINFO)EQADDR_MOUSE)->X;
		Dest.Type=pIntType;
		return true;
	case MouseY:
		Dest.DWord=((PMOUSEINFO)EQADDR_MOUSE)->Y;
		Dest.Type=pIntType;
		return true;
	}
	return false;
}
bool MQ2TypeType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pType ((MQ2Type*)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMEMBER pMember=MQ2TypeType::FindMember(Member);
	if (!pMember)
		return false;
	switch((TypeMembers)pMember->ID)
	{
	case Name:
		Dest.Ptr=pType->GetName();
		Dest.Type=pStringType;
		return true;
	case TypeMember:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// name by number
				if (Dest.Ptr=pType->GetMemberName(atoi(Index)))
				{
					Dest.Type=pStringType;
					return true;
				}
			}
			else
			{
				// number by name
				if (pType->GetMemberID(Index,Dest.DWord))
				{
					Dest.Type=pIntType;
					return true;
				}
			}
		}
		return false;
	}
	return false;
#undef pType
}

bool MQ2TimeType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pTime ((struct tm *)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMEMBER pMember=MQ2TimeType::FindMember(Member);
	if (!pMember)
		return false;
	switch((TimeMembers)pMember->ID)
	{
	case Hour:
		Dest.DWord=pTime->tm_hour;
		Dest.Type=pIntType;
		return true;
	case Minute:
		Dest.DWord=pTime->tm_min;
		Dest.Type=pIntType;
		return true;
	case Second:
		Dest.DWord=pTime->tm_sec;
		Dest.Type=pIntType;
		return true;
	case DayOfWeek:
		Dest.DWord=pTime->tm_wday+1;
		Dest.Type=pIntType;
		return true;
	case Day:
		Dest.DWord=pTime->tm_mday;
		Dest.Type=pIntType;
		return true;
	case Month:
		Dest.DWord=pTime->tm_mon+1;
		Dest.Type=pIntType;
		return true;
	case Year:
		Dest.DWord=pTime->tm_year+1900;
		Dest.Type=pIntType;
		return true;
	case Time12:
		{
			unsigned long Hour=pTime->tm_hour%12;
			if (!Hour)
				Hour=12;
			sprintf(DataTypeTemp,"%02d:%02d:%02d",Hour,pTime->tm_min, pTime->tm_sec);
			Dest.Ptr=&DataTypeTemp[0],
			Dest.Type=pStringType; 
		}
		return true;
	case Time24:
		sprintf(DataTypeTemp,"%02d:%02d:%02d",pTime->tm_hour,pTime->tm_min, pTime->tm_sec);
		Dest.Ptr=&DataTypeTemp[0],
		Dest.Type=pStringType; 
		return true;
	case Date:
		sprintf(DataTypeTemp,"%02d/%02d/%04d",pTime->tm_mon+1,pTime->tm_mday, pTime->tm_year+1900);
		Dest.Ptr=&DataTypeTemp[0],
		Dest.Type=pStringType; 
		return true;
	case Night:
		Dest.DWord=((pTime->tm_hour<7) || (pTime->tm_hour>18));
		Dest.Type=pBoolType;
		return true;
	case SecondsSinceMidnight:
		Dest.DWord=pTime->tm_hour*3600+pTime->tm_min*60+pTime->tm_sec;
		Dest.Type=pIntType;
		return true;
	}
	return false;
#undef GetTime
}

bool MQ2HeadingType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	PMQ2TYPEMEMBER pMember=MQ2HeadingType::FindMember(Member);
	if (!pMember)
		return false;
	FLOAT Heading=360.0f-VarPtr.Float;
	switch((HeadingMembers)pMember->ID)
	{
	case Clock:
		{
			Dest.Int=((int)Heading)+15;
			Dest.DWord=((int)Dest.Int/30)%12;
			if (Dest.DWord==0)
				Dest.DWord=12;
			Dest.Type=pIntType;
			return true;
		}
	case Degrees:
		Dest.Float=Heading;
		Dest.Type=pFloatType;
		return true;
	case DegreesCCW:
		Dest.Float=VarPtr.Float;
		Dest.Type=pFloatType;
		return true;
	case ShortName:
		Dest.Ptr=szHeadingNormalShort[(INT)(Heading/ 22.5f + 0.5f)%16];
		Dest.Type=pStringType;
		return true;
	case Name:
		Dest.Ptr=szHeadingNormal[(INT)(Heading/ 22.5f + 0.5f)%16];
		Dest.Type=pStringType;
		return true;
	}
	return false;
}

bool MQ2CorpseType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	if (!pActiveCorpse || !pLootWnd)
		return false;
#define pLoot ((PEQLOOTWINDOW)pLootWnd)
	PMQ2TYPEMEMBER pMember=MQ2CorpseType::FindMember(Member);
	if (!pMember)
	{
		return pSpawnType->GetMember(*(MQ2VARPTR*)&pActiveCorpse,Member,Index,Dest);
	}

	switch((CorpseMembers)pMember->ID)
	{
	case Open:
		Dest.DWord=1; // obviously, since we're this far ;)
		Dest.Type=pBoolType;
		return true;
	case Item:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				unsigned long nIndex=atoi(Index)-1;
				if (nIndex<31)
				{
					if (Dest.Ptr=pLoot->ItemDesc[nIndex])
					{
						Dest.Type=pItemType;
						return true;
					}
				}
			}
			else
			{
				// name
				BOOL bExact=FALSE;
				PCHAR pName=Index;
				if (*pName=='=')
				{
					bExact=TRUE;
					pName++;
				}
				strlwr(pName);
				CHAR Temp[MAX_STRING]={0};
				for (unsigned long nIndex = 0 ; nIndex < 31 ; nIndex++)
				{
					if (PCONTENTS pContents=pLoot->ItemDesc[nIndex])
					{
						if (bExact)
						{
							if (!stricmp(pName,pContents->Item->Name))
							{
								Dest.Ptr=pContents;
								Dest.Type=pItemType;
								return true;
							}
						}
						else
						{
							if(strstr(strlwr(strcpy(Temp,pContents->Item->Name)),pName))
							{
								Dest.Ptr=pContents;
								Dest.Type=pItemType;
								return true;
							}
						}
					}
				}

			}
		}
		return false;
	case Items:
		{
			Dest.DWord=0;
			for (unsigned long N = 0 ; N < 31 ; N++)
			{
				if (pLoot->ItemDesc[N])
					Dest.DWord++;
			}
			Dest.Type=pIntType;
			return true;
		}
	}
	return false;
#undef pLoot
}

bool MQ2MerchantType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	if (!pActiveMerchant || !pMerchantWnd)
		return false;
#define pMerch ((PEQMERCHWINDOW)pMerchantWnd)
	PMQ2TYPEMEMBER pMember=MQ2MerchantType::FindMember(Member);
	if (!pMember)
	{
		return pSpawnType->GetMember(*(MQ2VARPTR*)&pActiveMerchant,Member,Index,Dest);
	}

	switch((MerchantMembers)pMember->ID)
	{
	case Open:
		Dest.DWord=1; // obviously, since we're this far ;)
		Dest.Type=pBoolType;
		return true;
	case Item:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				unsigned long nIndex=atoi(Index)-1;
				if (nIndex<80)
				{
					if (Dest.Ptr=pMerch->ItemDesc[nIndex])
					{
						Dest.Type=pItemType;
						return true;
					}
				}
			}
			else
			{
				// name
				BOOL bExact=FALSE;
				PCHAR pName=Index;
				if (*pName=='=')
				{
					bExact=TRUE;
					pName++;
				}
				strlwr(pName);
				CHAR Temp[MAX_STRING]={0};
				for (unsigned long nIndex = 0 ; nIndex < 80 ; nIndex++)
				{
					if (PCONTENTS pContents=pMerch->ItemDesc[nIndex])
					{
						if (bExact)
						{
							if (!stricmp(pName,pContents->Item->Name))
							{
								Dest.Ptr=pContents;
								Dest.Type=pItemType;
								return true;
							}
						}
						else
						{
							if(strstr(strlwr(strcpy(Temp,pContents->Item->Name)),pName))
							{
								Dest.Ptr=pContents;
								Dest.Type=pItemType;
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	case Items:
		{
			Dest.DWord=0;
			for (unsigned long N = 0 ; N < 80 ; N++)
			{
				if (pMerch->ItemDesc[N])
					Dest.DWord++;
			}
			Dest.Type=pIntType;
			return true;
		}
	case Markup:
		Dest.Float=pMerch->Markup;
		Dest.Type=pFloatType;
		return true;
	}
	return false;
#undef pMerch
}
bool MQ2InvSlotType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define nInvSlot (VarPtr.Int)
	PMQ2TYPEMEMBER pMember=MQ2InvSlotType::FindMember(Member);
	if (!pMember)
		return false;
	switch((InvSlotMembers)pMember->ID)
	{
	case ID:
		Dest.DWord=VarPtr.Int;
		Dest.Type=pIntType;
		return true;
	case Item:
		{
			if (CInvSlot *pSlot=pInvSlotMgr->FindInvSlot(nInvSlot))
			{
				if (((PEQINVSLOT)pSlot)->ppContents)
				{
					if (Dest.Ptr=*((PEQINVSLOT)pSlot)->ppContents)
					{
						Dest.Type=pItemType;
						return true;
					}
				}
			}
			else
			{
				PCHARINFO pCharInfo=(PCHARINFO)pCharData;
				if (nInvSlot>=251 && nInvSlot<361)
				{
					unsigned long nPack=(nInvSlot-251)/10;
					unsigned long nSlot=(nInvSlot-1)%10;
					if (PCONTENTS pPack=pCharInfo->Inventory.Pack[nPack])
					if (pPack->Item->Type==ITEMTYPE_PACK && nSlot<pPack->Item->Slots)
					{
						if (Dest.Ptr=pPack->Contents[nSlot])
						{
							Dest.Type=pItemType;
							return true;
						}
					}
				} 
				else if (nInvSlot>=2031 && nInvSlot<2191)
				{
					unsigned long nPack=(nInvSlot-2031)/10;
					unsigned long nSlot=(nInvSlot-1)%10;
					if (PCONTENTS pPack=pCharInfo->Bank[nPack])
					if (pPack->Item->Type==ITEMTYPE_PACK && nSlot<pPack->Item->Slots)
					{
						if (Dest.Ptr=pPack->Contents[nSlot])
						{
							Dest.Type=pItemType;
							return true;
						}
					}
				}
				else if (nInvSlot>=2531 && nInvSlot<2551)
				{
					unsigned long nPack=16+((nInvSlot-2531)/10);
					unsigned long nSlot=(nInvSlot-1)%10;
					if (PCONTENTS pPack=pCharInfo->Bank[nPack])
					if (pPack->Item->Type==ITEMTYPE_PACK && nSlot<pPack->Item->Slots)
					{
						if (Dest.Ptr=pPack->Contents[nSlot])
						{
							Dest.Type=pItemType;
							return true;
						}
					}
				}
				else if (nInvSlot>=2000 && nInvSlot<=2015)
				{
					if (Dest.Ptr=pCharInfo->Bank[nInvSlot-2000])
					{
						Dest.Type=pItemType;
						return true;
					}
				}
				else if (nInvSlot==2500 || nInvSlot==2501)
				{
					if (Dest.Ptr=pCharInfo->Bank[nInvSlot-2500+16])
					{
						Dest.Type=pItemType;
						return true;
					}
				}
			}
		}
		return false;
	case Pack:
		if (nInvSlot>=251 && nInvSlot<361)
		{
			Dest.DWord=((nInvSlot-251)/10)+22;
			Dest.Type=pInvSlotType;
			return true;
		}
		else if (nInvSlot>=2031 && nInvSlot<2191)
		{
			Dest.DWord=((nInvSlot-2031)/10)+2000;
			Dest.Type=pInvSlotType;
			return true;
		}
		else if (nInvSlot>=2531 && nInvSlot<2551)
		{
			Dest.DWord=((nInvSlot-2531)/10)+2500;
			Dest.Type=pInvSlotType;
			return true;
		}
		return false;
	case Slot:
		{
			if (nInvSlot>=251 && nInvSlot<361)
			{
				Dest.DWord=(nInvSlot-251)%10;
				Dest.Type=pIntType;
				return true;
			}
			else if (nInvSlot>=2031 && nInvSlot<2191)
			{
				Dest.DWord=(nInvSlot-2031)%10;
				Dest.Type=pIntType;
				return true;
			}
			else if (nInvSlot>=2531 && nInvSlot<2551)
			{
				Dest.DWord=(nInvSlot-2531)%10;
				Dest.Type=pIntType;
				return true;
			}			
		}
		return false;
	case Name:
		if (nInvSlot>=0 && nInvSlot<30) 
        {
            Dest.Ptr=szItemSlot[nInvSlot];
            Dest.Type=pStringType;
            return true;
        }
		if (nInvSlot>=22 && nInvSlot<30)
		{
			sprintf(DataTypeTemp,"pack%d",nInvSlot-21);
			Dest.Ptr=&DataTypeTemp[0];
			Dest.Type=pStringType;
			return true;
		}
		else if (nInvSlot>=2000 && nInvSlot<2016)
		{
			sprintf(DataTypeTemp,"bank%d",nInvSlot-1999);
			Dest.Ptr=&DataTypeTemp[0];
			Dest.Type=pStringType;
			return true;
		}
		else if (nInvSlot>=2500 && nInvSlot<2502)
		{
			sprintf(DataTypeTemp,"sharedbank%d",nInvSlot-2499);
			Dest.Ptr=&DataTypeTemp[0];
			Dest.Type=pStringType;
			return true;
		}
		else if (nInvSlot>=5000 && nInvSlot<5032)
		{
			sprintf(DataTypeTemp,"loot%d",nInvSlot-4999);
			Dest.Ptr=&DataTypeTemp[0];
			Dest.Type=pStringType;
			return true;
		}
		else if (nInvSlot>=3000 && nInvSlot<3009)
		{
			sprintf(DataTypeTemp,"trade%d",nInvSlot-2999);
			Dest.Ptr=&DataTypeTemp[0];
			Dest.Type=pStringType;
			return true;
		}
		else if (nInvSlot>=4000 && nInvSlot<4009)
		{
			sprintf(DataTypeTemp,"enviro%d",nInvSlot-3999);
			Dest.Ptr=&DataTypeTemp[0];
			Dest.Type=pStringType;
			return true;
		}
		else if (nInvSlot>=6000 && nInvSlot<6080)
		{
			sprintf(DataTypeTemp,"merchant%d",nInvSlot-5999);
			Dest.Ptr=&DataTypeTemp[0];
			Dest.Type=pStringType;
			return true;
		}
		else if (nInvSlot>=7000 && nInvSlot<7089)
		{
			sprintf(DataTypeTemp,"bazaar%d",nInvSlot-6999);
			Dest.Ptr=&DataTypeTemp[0];
			Dest.Type=pStringType;
			return true;
		}
		else if (nInvSlot>=8000 && nInvSlot<8031)
		{
			sprintf(DataTypeTemp,"inspect%d",nInvSlot-7999);
			Dest.Ptr=&DataTypeTemp[0];
			Dest.Type=pStringType;
			return true;
		}
		return false;
	}

	return false;
#undef nInvSlot
}


bool MQ2ArrayType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pArray ((CDataArray*)VarPtr.Ptr)
	if (!pArray)
		return false;
	PMQ2TYPEMEMBER pMember=MQ2ArrayType::FindMember(Member);
	if (!pMember)
		return false;
	switch((ArrayMembers)pMember->ID)
	{
	case Dimensions:
		Dest.DWord=pArray->nExtents;
		Dest.Type=pIntType;
		return true;
	case Size:
		if (Index[0])
		{
			DWORD N=atoi(Index)-1;
			if (N<pArray->nExtents)
			{
				Dest.DWord=pArray->pExtents[N];
				Dest.Type=pIntType;
				return true;
			}
		}
		else
		{
			Dest.DWord=pArray->TotalElements;
			Dest.Type=pIntType;
			return true;
		}
		return false;
	}
	return false;
#undef pArray
}

bool MQ2TimerType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pTimer ((PMQTIMER)VarPtr.Ptr)
	if (!pTimer)
		return false;
	PMQ2TYPEMEMBER pMember=MQ2TimerType::FindMember(Member);
	if (!pMember)
		return false;
	switch((TimerMembers)pMember->ID)
	{
	case Value:
		Dest.DWord=pTimer->Current;
		Dest.Type=pIntType;
		return true;
	case OriginalValue:
		Dest.DWord=pTimer->Original;
		Dest.Type=pIntType;
		return true;
	}
	return false;
#undef pTimer
}

bool MQ2PluginType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
#define pPlugin ((PMQPLUGIN)VarPtr.Ptr)
	if (!pPlugin)
		return false;
	PMQ2TYPEMEMBER pMember=MQ2PluginType::FindMember(Member);
	if (!pMember)
		return false;
	switch((PluginMembers)pMember->ID)
	{
	case Name:
		Dest.Ptr=pPlugin->szFilename;
		Dest.Type=pStringType;
		return true;
	}
	return false;
#undef pPlugin
}

bool MQ2SkillType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	if (!VarPtr.Ptr)
		return false;
	PSKILL pSkill=*(PSKILL*)VarPtr.Ptr;
	if (!pSkill)
		return false;
	PMQ2TYPEMEMBER pMember=MQ2SkillType::FindMember(Member);
	if (!pMember)
		return false;
	switch((SkillMembers)pMember->ID)
	{
	case Name:
		if (Dest.Ptr=pStringTable->getString(pSkill->nName,0))
		{
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case ID:
		Dest.DWord=(((PSKILL*)VarPtr.Ptr-SkillDict))+1;
		Dest.Type=pIntType;
		return true;
	case Accuracy:
		Dest.Float=pSkill->Accuracy;
		Dest.Type=pFloatType;
		return true;
	case ReuseTime:
		Dest.DWord=pSkill->ReuseTimer;
		Dest.Type=pIntType;
		return true;
	case AltTimer:
		Dest.DWord=pSkill->AltTimer;
		Dest.Type=pIntType;
		return true;
	case MinLevel:
		if (Index[0])
		{
			return false;
		}
		else
		{
			Dest.DWord=pSkill->MinLevel[((PCHARINFO)pCharData)->Class];
			Dest.Type=pIntType;
			return true;
		}
	case StartingSkill:
		if (Index[0])
		{
			return false;
		}
		else
		{
			Dest.DWord=pSkill->StartingSkill[((PCHARINFO)pCharData)->Class];
			Dest.Type=pIntType;
			return true;
		}
	case SkillCapPre50:
		if (Index[0])
		{
			return false;
		}
		else
		{
			Dest.DWord=pSkill->SkillCapsPre50[((PCHARINFO)pCharData)->Class];
			Dest.Type=pIntType;
			return true;
		}
	case SkillCapPost50:
		if (Index[0])
		{
			return false;
		}
		else
		{
			Dest.DWord=pSkill->SkillCapsPost50[((PCHARINFO)pCharData)->Class];
			Dest.Type=pIntType;
			return true;
		}
	}
	return false;
}

bool MQ2AltAbilityType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	if (!VarPtr.Ptr)
		return false;
	PALTABILITY pAbility=*(PALTABILITY*)VarPtr.Ptr;
	if (!pAbility)
		return false;
	PMQ2TYPEMEMBER pMember=MQ2AltAbilityType::FindMember(Member);
	if (!pMember)
		return false;
	switch((AltAbilityMembers)pMember->ID)
	{
	case Name:
		if (Dest.Ptr=pStringTable->getString(pAbility->nName,0))
		{
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case ShortName:
		if (Dest.Ptr=pStringTable->getString(pAbility->nShortName,0))
		{
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case Description:
		if (Dest.Ptr=pStringTable->getString(pAbility->nDesc,0))
		{
			Dest.Type=pStringType;
			return true;
		}
		return false;
	case ID:
		Dest.DWord=(((PALTABILITY*)VarPtr.Ptr-&((PALTADVMGR)pAltAdvManager)->Abilities[0]));
		Dest.Type=pIntType;
		return true;
	case ReuseTime:
		Dest.DWord=pAbility->ReuseTimer;
		Dest.Type=pIntType;
		return true;
	case MinLevel:
		Dest.DWord=pAbility->MinLevel;
		Dest.Type=pIntType;
		return true;
	case Cost:
		Dest.DWord=pAbility->Cost;
		Dest.Type=pIntType;
		return true;
	case Spell:
		if (Dest.Ptr=GetSpellByID(pAbility->SpellID))
		{
			Dest.Type=pSpellType;
			return true;
		}
		return false;
	case RequiresAbility:
		if (pAbility->RequiresAbility>0)
		{
			if (Dest.Ptr=&((PALTADVMGR)pAltAdvManager)->Abilities[pAbility->RequiresAbility])
			{
				Dest.Type=pAltAbilityType;
				return true;
			}
		}
		return false;
	case RequiresAbilityPoints:
		Dest.DWord=pAbility->RequiresAbilityPoints;
		Dest.Type=pIntType;
		return true;
	case MaxRank:
		Dest.DWord=pAbility->MaxRank;
		Dest.Type=pIntType;
		return true;
//	case AARankRequired:
//		Dest.DWord=pAbility->AARankRequired;
//		Dest.Type=pIntType;
//		return true;
	case Type:
		Dest.DWord=pAbility->Type;
		Dest.Type=pIntType;
		return true;
	}
	return false;
}

bool MQ2RaidType::GetMember(MQ2VARPTR VarPtr, PCHAR sMember, PCHAR Index, MQ2TYPEVAR &Dest)
{
	if (!pRaid)
		return false;
	PMQ2TYPEMEMBER pMember=MQ2RaidType::FindMember(sMember);
	if (!pMember)
		return false;
	switch((RaidMembers)pMember->ID)
	{
	case Member:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				DWORD Count=atoi(Index);
				if (!Count || Count>pRaid->RaidMemberCount)
					return false;
				for (DWORD nMember = 0 ; nMember < 72 ; nMember++)
				{
					if (pRaid->RaidMemberUsed[nMember])
					{
						Count--;
						if (!Count)
						{
							Dest.DWord=nMember+1;
							Dest.Type=pRaidMemberType;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				for (DWORD nMember=0 ; nMember < 72 ; nMember++)
				{
					if (pRaid->RaidMemberUsed[nMember] && !stricmp(pRaid->RaidMember[nMember].Name,Index))
					{
						Dest.DWord=nMember+1;
						Dest.Type=pRaidMemberType;
						return true;
					}
				}
			}
		}
		return false;
	case Members:
		Dest.DWord=pRaid->RaidMemberCount;
		Dest.Type=pIntType;
		return true;
	case Target:
		Dest.DWord=pRaid->RaidTarget+1;
		Dest.Type=pRaidMemberType;
		return true;
	case Leader:
		{
			for (DWORD nMember=0 ; nMember < 72 ; nMember++)
			{
				if (pRaid->RaidMemberUsed[nMember] && !stricmp(pRaid->RaidMember[nMember].Name,pRaid->RaidLeaderName))
				{
					Dest.DWord=nMember+1;
					Dest.Type=pRaidMemberType;
					return true;
				}
			}
		}
		return false;
	case TotalLevels:
		Dest.DWord=pRaid->TotalRaidMemberLevels;
		Dest.Type=pIntType;
		return true;
	case AverageLevel:
		Dest.Float=(FLOAT)pRaid->TotalRaidMemberLevels/(FLOAT)pRaid->RaidMemberCount;
		Dest.Type=pFloatType;
		return true;
	case LootType:
		Dest.DWord=pRaid->LootType;
		Dest.Type=pIntType;
		return true;
	case Looters:
		{
			Dest.DWord=0;
			for (unsigned long N = 0 ; N < 0x13 ; N++)
			{
				if (pRaid->RaidLooters[N][0])
					Dest.DWord++;
			}
			Dest.Type=pIntType;
			return true;
		}
	case Looter:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				DWORD Count=atoi(Index);
				if (!Count)
					return 0;
				for (DWORD nLooter=0; nLooter<0x13 ; nLooter++)
				{
					if (pRaid->RaidLooters[nLooter][0])
					{
						Count--;
						if (Count==0)
						{
							Dest.Ptr=&pRaid->RaidLooters[nLooter][0];
							Dest.Type=pStringType;
							return true;
						}
					}
				}
			}
			// by name?
		}
		return false;
	}
	/**/
	return false;
}

bool MQ2RaidMemberType::GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
{
	DWORD nRaidMember=VarPtr.DWord-1;
	if (VarPtr.DWord>=72)
		return false;
	if (!pRaid->RaidMemberUsed[nRaidMember])
		return false;
	PEQRAIDMEMBER pRaidMember=&pRaid->RaidMember[nRaidMember];
	PMQ2TYPEMEMBER pMember=MQ2RaidMemberType::FindMember(Member);
	if (!pMember)
	{
		return pSpawnType->GetMember(*(MQ2VARPTR*)&SpawnByName[pRaidMember->Name],Member,Index,Dest);
	}

	switch((RaidMemberMembers)pMember->ID)
	{
	case Name:
		Dest.Ptr=pRaidMember->Name;
		Dest.Type=pStringType;
		return true;
	case Group:
		Dest.DWord=pRaidMember->GroupNumber+1;
		Dest.Type=pIntType;
		return true;
	case GroupLeader:
		Dest.DWord=pRaidMember->GroupLeader;
		Dest.Type=pBoolType;
		return true;
	case RaidLeader:
		Dest.DWord=pRaidMember->RaidLeader;
		Dest.Type=pBoolType;
		return true;
	case Looter:
		if (pRaidMember->RaidLeader)
		{
			Dest.DWord=1;
			Dest.Type=pBoolType;
			return true;
		}
		if (pRaid->LootType==2)
		{
			Dest.DWord=pRaidMember->GroupLeader;
			Dest.Type=pBoolType;
			return true;
		}
		if (pRaid->LootType==3)
		{
			for (DWORD N = 0 ; N < 0x13 ; N++)
			{
				if (!stricmp(pRaid->RaidLooters[N],pRaidMember->Name))
				{
					Dest.DWord=1;
					Dest.Type=pBoolType;
					return true;
				}
			}
		}
		Dest.DWord=0;
		Dest.Type=pBoolType;
		return true;
	case Spawn:
		if (Dest.Ptr=SpawnByName[pRaidMember->Name])
		{
			Dest.Type=pSpawnType;
			return true;
		}
		return false;
	case Level:
		Dest.DWord=atoi(pRaidMember->Level);
		Dest.Type=pIntType;
		return true;
	case Class:
		Dest.DWord=pRaidMember->nClass;
		Dest.Type=pClassType;
		return true;
		/*
		{
			if (PSPAWNINFO pSpawn=SpawnByName[pRaidMember->Name])
			{
				Dest.DWord=pSpawn->Class;
				Dest.Type=pIntType;
				return true;
			}
			pCharData->KunarkClass(0,0,0x18C,1);
		}
		return false;
		/**/
	}
	return false;
}
