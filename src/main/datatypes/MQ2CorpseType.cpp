#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2CorpseType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pActiveCorpse || !pLootWnd)
		return false;

	MQTypeMember* pMember = MQ2CorpseType::FindMember(Member);
	if (!pMember)
	{
		MQVarPtr data;
		data.Ptr = pActiveCorpse;
		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<CorpseMembers>(pMember->ID))
	{
	case Open:
		Dest.DWord = 1; // obviously, since we're this far
		Dest.Type = pBoolType;
		return true;

	case Item:
		Dest.Type = pItemType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nIndex = GetIntFromString(Index, 0) - 1;
				if (nIndex < 0 || nIndex >= NUM_INV_SLOTS)
					return false;

				if (Dest.Ptr = pLootWnd->pInventoryArray->InventoryArray[nIndex])
				{
					return true;
				}
			}
			else
			{
				// name
				bool bExact = false;
				char* pName1 = Index;
				if (*pName1 == '=')
				{
					bExact = true;
					pName1++;
				}

				for (int nIndex = 0; nIndex < NUM_INV_SLOTS; nIndex++)
				{
					if (CONTENTS* pContents = pLootWnd->pInventoryArray->InventoryArray[nIndex])
					{
						const char* itemName = GetItemFromContents(pContents)->Name;

						if (bExact)
						{
							if (ci_equals(itemName, pName1))
							{
								Dest.Ptr = pContents;
								return true;
							}
						}
						else
						{
							if (ci_find_substr(itemName, pName1) != -1)
							{
								Dest.Ptr = pContents;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case Items:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (int index = 0; index < 31; index++)
		{
			if (pLootWnd->pInventoryArray->InventoryArray[index])
				Dest.DWord++;
		}
		return true;

	default: break;
	}

	return false;
}

