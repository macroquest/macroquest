#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2CharSelectListType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2CharSelectListType::FindMember(Member);
	if (!pMember)
		return false;

	EVERQUEST* pEQ = pEverQuest;

	switch (static_cast<CharSelectListMembers>(pMember->ID))
	{
	case Name:
		Dest.Type = pStringType;
		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			strcpy_s(DataTypeTemp, pEQ->pCharSelectPlayerArray[VarPtr.Int].Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Level:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			Dest.DWord = pEQ->pCharSelectPlayerArray[VarPtr.Int].Level;
			return true;
		}
		return false;

	case Class:
		Dest.DWord = 0;
		Dest.Type = pStringType;

		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			strcpy_s(DataTypeTemp, GetClassDesc(pEQ->pCharSelectPlayerArray[VarPtr.Int].Class));
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Race:
		Dest.DWord = 0;
		Dest.Type = pStringType;

		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			strcpy_s(DataTypeTemp, pEverQuest->GetRaceDesc(pEQ->pCharSelectPlayerArray[VarPtr.Int].Race));
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ZoneID:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pEQ && VarPtr.Int < pEQ->pCharSelectPlayerArray.Count)
		{
			int zoneid = pEQ->pCharSelectPlayerArray[VarPtr.Int].CurZoneID;
			Dest.DWord = (zoneid & 0x7FFF);

			return true;
		}
		return false;

	case Count:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pEQ)
		{
			Dest.DWord = pEQ->pCharSelectPlayerArray.Count;
		}
		return true;

	default: break;
	}

	return false;
}

