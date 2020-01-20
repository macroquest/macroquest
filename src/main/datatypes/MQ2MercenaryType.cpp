#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2MercenaryType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	SPAWNINFO* pSpawn = reinterpret_cast<SPAWNINFO*>(VarPtr.Ptr);
	if (!pSpawn)
		return false;

	MQTypeMember* pMember = MQ2MercenaryType::FindMember(Member);
	if (!pMember)
	{
		if (!pSpawn->SpawnID)
			return false;

		return pSpawnType->GetMember(VarPtr, Member, Index, Dest);
	}

	switch (static_cast<MercenaryMembers>(pMember->ID))
	{
	case AAPoints:
		Dest.DWord = GetCharInfo()->MercAAPoints;
		Dest.Type = pIntType;
		return true;

	case Stance:
		strcpy_s(DataTypeTemp, "NULL");
		if (pMercInfo->HaveMerc)
		{
			for (int n = 0; n < pMercInfo->NumStances; n++)
			{
				if (pMercInfo->pMercStanceData[n]->nStance == pMercInfo->ActiveStance)
				{
					strcpy_s(DataTypeTemp, pCDBStr->GetString(pMercInfo->pMercStanceData[n]->nDbStance, eMercenaryStanceName));
					break;
				}
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case State:
		switch (pMercInfo->MercState)
		{
		case 0:
			strcpy_s(DataTypeTemp, "DEAD");
			break;

		case 1:
			strcpy_s(DataTypeTemp, "SUSPENDED");
			break;

		case 5:
			if (pMercInfo->HaveMerc) {
				strcpy_s(DataTypeTemp, "ACTIVE");
			}
			else {
				strcpy_s(DataTypeTemp, "NOMERC");
			}
			break;

		default:
			strcpy_s(DataTypeTemp, "UNKNOWN");
			break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case StateID:
		Dest.DWord = pMercInfo->MercState;
		Dest.Type = pIntType;
		return true;

	case xIndex:
		Dest.DWord = pMercInfo->CurrentMercIndex + 1;
		Dest.Type = pIntType;
		return true;

#ifdef MULETESTING
		//work in progress -eqmule Aug 03 2015
	case CurrentHPs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->CurrHP;
			return true;
		}
		return false;
	case MaxHPs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->MaxHP;
			return true;
		}
		return false;
	case PctHPs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			LONG maxhp = pStats->MaxHP;
			if (maxhp != 0)
				Dest.Int = pStats->CurrHP * 100 / maxhp;
			return true;
		}
		return false;
	case CurrentMana:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->CurrMana;
			return true;
		}
		return false;
	case MaxMana:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->MaxMana;
			return true;
		}
		return false;
	case PctMana:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			if (unsigned long Temp = pStats->MaxMana) {
				Dest.Int = pStats->CurrMana * 100 / Temp;
				return true;
			}
		}
		return false;
	case AC:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->AC;
			return true;
		}
		return false;
	case AGI:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->AGI;
			return true;
		}
		return false;
	case Attack:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->Attack;
			return true;
		}
		return false;
	case CHA:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->CHA;
			return true;
		}
		return false;
	case CombatEnduranceRegen:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->CombatEnduranceRegen;
			return true;
		}
		return false;
	case CombatHPRegen:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->CombatHPRegen;
			return true;
		}
		return false;
	case CurrentEndurance:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->CurrEndurance;
			return true;
		}
		return false;
	case MaxEndurance:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->MaxEndurance;
			return true;
		}
		return false;
	case PctEndurance:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			if (unsigned long Temp = pStats->MaxEndurance)
				Dest.Int = (pStats->CurrEndurance * 100) / Temp;
			return true;
		}
		return false;
	case DEX:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->DEX;
			return true;
		}
		return false;
	case Haste:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->Haste;
			return true;
		}
		return false;
	case HealAmount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->HealAmount;
			return true;
		}
		return false;
	case INT:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->INT;
			return true;
		}
		return false;
	case SpellDamage:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->SpellDamage;
			return true;
		}
		return false;
	case STA:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->STA;
			return true;
		}
		return false;
	case STR:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->STR;
			return true;
		}
		return false;
	case WIS:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->WIS;
			return true;
		}
		return false;
#endif
	default: break;
	}

	return false;
}

