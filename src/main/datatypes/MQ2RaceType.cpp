#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2RaceType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2RaceType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<RaceMembers>(pMember->ID))
	{
	case ID:
		Dest.Ptr = VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, pEverQuest->GetRaceDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

