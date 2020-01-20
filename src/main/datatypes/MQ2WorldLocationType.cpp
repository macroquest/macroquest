#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2WorldLocationType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2WorldLocationType::FindMember(Member);
	if (!pMember)
		return false;

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return false;

	uint32_t index = VarPtr.DWord;

	switch (static_cast<WorldLocationTypeMembers>(pMember->ID))
	{
	case ID: {
		int zindex = pProfile->BoundLocations[index].ZoneBoundID;
		Dest.DWord = zindex;
		Dest.Type = pIntType;
		return true;
	}

	case Zone: {
		Dest.Type = pZoneType;

		int zindex = pProfile->BoundLocations[index].ZoneBoundID & 0x7FFF;
		if (zindex < MAX_ZONES)
		{
			Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[zindex];
		}

		if (!Dest.Ptr)
			return false;
		return true;
	}

	case Y:
		Dest.Float = pProfile->BoundLocations[index].ZoneBoundY;
		Dest.Type = pFloatType;
		return true;

	case X:
		Dest.Float = pProfile->BoundLocations[index].ZoneBoundX;
		Dest.Type = pFloatType;
		return true;

	case Z:
		Dest.Float = pProfile->BoundLocations[index].ZoneBoundZ;
		Dest.Type = pFloatType;
		return true;

	case Heading:
		Dest.Float = pProfile->BoundLocations[index].ZoneBoundHeading;
		Dest.Type = pFloatType;
		return true;

	default: break;
	};

	return false;
}

