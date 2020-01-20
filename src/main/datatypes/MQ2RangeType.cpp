#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2RangeType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2RangeType::FindMember(Member);
	if (!pMember)
		return false;
	if (!Index[0])
		return false;

	int P1 = 0;
	int P2 = 0;
	int P3 = 0;

	switch (static_cast<RangeMembers>(pMember->ID))
	{
	case Inside:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			if (char* pColon = strchr(Index, ':'))
			{
				*pColon = 0;
				P3 = GetIntFromString(&pColon[1], P3);
				if (char* pComma = strchr(Index, ','))
				{
					*pComma = 0;
					P2 = GetIntFromString(&pComma[1], P2);
					P1 = GetIntFromString(Index, P1);

					if (P3 > P1 && P3 < P2)
					{
						Dest.DWord = true;
						return true;
					}
				}
			}
		}
		return true;

	case Between:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (Index[0]) {
			if (char* pColon = strchr(Index, ':'))
			{
				*pColon = 0;
				P3 = GetIntFromString(&pColon[1], P3);
				if (char* pComma = strchr(Index, ','))
				{
					*pComma = 0;
					P2 = GetIntFromString(&pComma[1], P2);
					P1 = GetIntFromString(Index, P1);

					if (P3 >= P1 && P3 <= P2)
					{
						Dest.DWord = true;
						return true;
					}
				}
			}
		}
		return true;

	default: break;
	}

	return false;
}

