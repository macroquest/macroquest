#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2DZMemberType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	auto* pDynamicZoneMember = reinterpret_cast<DynamicZonePlayerInfo*>(VarPtr.Ptr);
	if (pDynamicZoneMember)
		return false;

	MQTypeMember* pMember = MQ2DZMemberType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<DZMemberTypeMembers>(pMember->ID))
	{
	case Name:
		strcpy_s(DataTypeTemp, pDynamicZoneMember->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Flagged:
		Dest.DWord = pDynamicZoneMember->bFlagged;
		Dest.Type = pBoolType;

	case Status:
		strcpy_s(DataTypeTemp, "Unknown");
		switch (pDynamicZoneMember->Status)
		{
		case 0:
			strcpy_s(DataTypeTemp, "Unknown");
			break;
		case 1:
			strcpy_s(DataTypeTemp, "Online");
			break;
		case 2:
			strcpy_s(DataTypeTemp, "Offline");
			break;
		case 3:
			strcpy_s(DataTypeTemp, "In Dynamic Zone");
			break;
		case 4:
			strcpy_s(DataTypeTemp, "Link Dead");
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

