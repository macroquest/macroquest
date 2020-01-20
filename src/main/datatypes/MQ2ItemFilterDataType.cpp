#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2ItemFilterDataType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	ItemFilterData* pItem = (ItemFilterData*)VarPtr.Ptr;
	if (!pItem)
		return false;

	MQTypeMember* pMember = MQ2ItemFilterDataType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ItemFilterDataMembers>(pMember->ID))
	{
	case Name:
		Dest.Type = pStringType;
		if (pItem && pItem->Name[0])
		{
			strcpy_s(DataTypeTemp, pItem->Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case ID:
		Dest.DWord = pItem->ID;
		Dest.Type = pIntType;
		return true;

	case AutoRoll:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bAutoRoll = (pItem->Types & (1 << 0)) != 0;
			Dest.DWord = bAutoRoll;
		}
		return true;

	case Need:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bNeed = (pItem->Types & (1 << 1)) != 0;
			Dest.DWord = bNeed;
		}
		return true;

	case Greed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bGreed = (pItem->Types & (1 << 2)) != 0;
			Dest.DWord = bGreed;
		}
		return true;

	case Never:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem)
		{
			bool bNever = (pItem->Types & (1 << 3)) != 0;
			Dest.DWord = bNever;
		}
		return true;

	case IconID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem)
		{
			Dest.DWord = pItem->Icon;
			return true;
		}
		return false;

	case Types:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem)
		{
			Dest.DWord = pItem->Types;
			return true;
		}
		return false;

	default: break;
	}
	return false;
}

