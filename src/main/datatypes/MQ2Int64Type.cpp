#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;
//----------------------------------------------------------------------------
// MQ2Int64Type

bool MQ2Int64Type::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2Int64Type::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<Int64Members>(pMember->ID))
	{
	case Float:
		Dest.Float = (float)1.0f * (VarPtr.Int64);
		Dest.Type = pFloatType;
		return true;

	case Double:
		Dest.Double = (double)1.0f * (VarPtr.Int64);
		Dest.Type = pDoubleType;
		return true;

	case Hex:
		sprintf_s(DataTypeTemp, "0x%llX", VarPtr.Int64);
		Dest.Ptr = &DataTypeTemp[0],
			Dest.Type = pStringType;
		return true;

	case Reverse:
		Dest.FullArray[0] = VarPtr.FullArray[7];
		Dest.FullArray[1] = VarPtr.FullArray[6];
		Dest.FullArray[2] = VarPtr.FullArray[5];
		Dest.FullArray[3] = VarPtr.FullArray[4];
		Dest.FullArray[4] = VarPtr.FullArray[3];
		Dest.FullArray[5] = VarPtr.FullArray[2];
		Dest.FullArray[6] = VarPtr.FullArray[1];
		Dest.FullArray[7] = VarPtr.FullArray[0];
		Dest.Type = pInt64Type;
		return true;

	case LowPart:
		Dest.DWord = LODWORD(VarPtr.UInt64);
		Dest.Type = pIntType;
		return true;

	case HighPart:
		Dest.DWord = HIDWORD(VarPtr.UInt64);
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

