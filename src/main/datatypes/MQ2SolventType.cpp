#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2SolventType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	int itemid = VarPtr.DWord;
	if (itemid == -1)
		itemid = 52023;

	MQTypeMember* pMember = MQ2SolventType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<SolventTypeMembers>(pMember->ID))
	{
	case Name:
		strcpy_s(DataTypeTemp, GetAugmentNameByID(itemid));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ID:
		Dest.DWord = itemid;
		Dest.Type = pIntType;
		return true;

	case Item: // do we have this solvent?
		Dest.Type = pItemType;
		if (CONTENTS* pItem = FindItemByID(itemid))
		{
			Dest.Ptr = pItem;
			return true;
		}
		return false;

	case Count: // do we have this solvent and if so how many?
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (CONTENTS* pCont = FindItemByID(itemid))
		{
			if (PITEMINFO pItem = GetItemFromContents(pCont))
			{
				Dest.DWord = FindItemCountByName(pItem->Name);
			}
		}
		return true;

	default: break;
	};

	return false;
}

