#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2BandolierItemType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (BandolierItemInfo* ptr = (BandolierItemInfo*)VarPtr.Ptr)
	{
		MQTypeMember* pMember = MQ2BandolierItemType::FindMember(Member);
		if (pMember)
		{
			switch (static_cast<BandolierItemTypeMembers>(pMember->ID))
			{
			case xIndex:
				Dest.DWord = VarPtr.HighPart;
				Dest.Type = pIntType;
				return true;

			case IconID:
				Dest.DWord = ptr->IconID;
				Dest.Type = pIntType;
				return true;

			case ID:
				Dest.DWord = ptr->ItemID;
				Dest.Type = pIntType;
				return true;

			case Name:
				strcpy_s(DataTypeTemp, ptr->Name);
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;

			default: break;
			};

			return false;
		}
	}
	return false;
}

