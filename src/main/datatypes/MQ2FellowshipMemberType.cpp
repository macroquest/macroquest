#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2FellowshipMemberType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	FELLOWSHIPMEMBER* pFellowshipMember = reinterpret_cast<FELLOWSHIPMEMBER*>(VarPtr.Ptr);
	if (!pFellowshipMember)
		return false;

	MQTypeMember* pMember = MQ2FellowshipMemberType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<FMTypeMembers>(pMember->ID))
	{
	case Zone:
		if (int zoneID = (pFellowshipMember->ZoneID & 0x7FFF))
		{
			if (zoneID < MAX_ZONES && pWorldData)
			{
				Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[zoneID];
				Dest.Type = pZoneType;
				return true;
			}
		}
		return false;

	case Level:
		Dest.DWord = pFellowshipMember->Level;
		Dest.Type = pIntType;
		return true;

	case Class:
		Dest.DWord = pFellowshipMember->Class;
		Dest.Type = pClassType;
		return true;

	case LastOn:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (pFellowshipMember->LastOn)
		{
			Dest.DWord = (GetFastTime() - pFellowshipMember->LastOn) / 6;
			return true;
		}
		return false;

	case Name:
		strcpy_s(DataTypeTemp, pFellowshipMember->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	default: break;
	}

	return false;
}

