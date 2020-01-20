#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2EvolvingItemType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CONTENTS* pItem = reinterpret_cast<CONTENTS*>(VarPtr.Ptr);
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2EvolvingItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<EvolvingItemMembers>(pMember->ID))
	{
	case ExpOn:
		Dest.DWord = true; // its always on after 2019-02-14 test patch
		Dest.Type = pBoolType;
		return true;

	case ExpPct:
		if (pItem->pEvolutionData)
		{
			Dest.Float = (float)pItem->pEvolutionData->EvolvingExpPct;
			Dest.Type = pFloatType;
			return true;
		}
		break;

	case Level:
		if (pItem->pEvolutionData)
		{
			Dest.Int = pItem->pEvolutionData->EvolvingCurrentLevel;
			Dest.Type = pIntType;
			return true;
		}
		break;

	case MaxLevel:
		if (pItem->pEvolutionData)
		{
			Dest.Int = pItem->pEvolutionData->EvolvingMaxLevel;
			Dest.Type = pIntType;
			return true;
		}
		break;

	default: break;
	}

	return false;
}

