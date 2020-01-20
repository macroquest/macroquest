#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2FloatType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2FloatType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<FloatMembers>(pMember->ID))
	{
	case Deci:
		sprintf_s(DataTypeTemp, "%.1f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Centi:
		sprintf_s(DataTypeTemp, "%.2f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Milli:
		sprintf_s(DataTypeTemp, "%.3f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Int:
		Dest.Type = pIntType;
		Dest.Int = (int)(VarPtr.Float);
		return true;

	case Precision:
		Dest.Type = pStringType;
		if (IsNumber(Index))
		{
			sprintf_s(DataTypeTemp, "%.*f", GetIntFromString(Index, 3), VarPtr.Float);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Raw:
		Dest.Type = pIntType;
		Dest.DWord = VarPtr.DWord;
		return true;

	default: break;
	}

	return false;
}

