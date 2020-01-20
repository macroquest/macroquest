#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2ZoneType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	ZONELIST* pZone = static_cast<ZONELIST*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	MQTypeMember* pMember = MQ2ZoneType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ZoneMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, pZone->LongName);
		Dest.Ptr = &DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case ShortName:
		strcpy_s(DataTypeTemp, pZone->ShortName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ID:
		Dest.Int = pZone->Id & 0x7FFF;
		Dest.Type = pIntType;
		return true;

	case ZoneFlags:
		Dest.Int = pZone->ZoneFlags;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

