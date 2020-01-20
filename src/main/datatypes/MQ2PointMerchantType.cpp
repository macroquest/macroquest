#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2PointMerchantType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pMerchantWnd)
		return false;

	MQTypeMember* pMember = MQ2PointMerchantType::FindMember(Member);
	if (!pMember)
	{
		MQVarPtr data;
		data.Ptr = pActiveMerchant;

		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<PointMerchantMembers>(pMember->ID))
	{
	case Item:
		Dest.Int = 0;
		Dest.Type = pPointMerchantItemType;
		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index >= 0 && index < pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer.GetSize())
			{
				Dest.Int = index;
				return true;
			}
		}
		else
		{
			if (Index[0] != '\0')
			{
				for (int i = 0; i < pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer.GetSize(); i++)
				{
					auto name = GetItemFromContents(pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer[i].pCont)->Name;
					if (!_stricmp(name, Index))
					{
						Dest.Int = i;
						return true;
					}
				}
			}
		}

	default: break;
	}

	return false;
}

