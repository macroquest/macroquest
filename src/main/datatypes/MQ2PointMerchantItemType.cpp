#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2PointMerchantItemType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pMerchantWnd)
		return false;

	if (VarPtr.Int < 0 || VarPtr.Int > pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer.GetSize())
		return false;

	int index = VarPtr.Int;
	MQTypeMember* pMember = MQ2PointMerchantItemType::FindMember(Member);

	if (!pMember)
		return false;

	ITEMINFO* pItem = nullptr;
	CONTENTS* pCont = nullptr;
	if (pCont = pMerchantWnd->PageHandlers[RegularMerchantPage]->ItemContainer[index].pCont)
	{
		pItem = GetItemFromContents(pCont);
	}

	if (!pItem)
		return false;

	switch (static_cast<PointMerchantItemMembers>(pMember->ID))
	{
	case Name:
		strcpy_s(DataTypeTemp, pItem->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case ItemID:
		Dest.Int = pCont->ID;
		Dest.Type = pIntType;
		return true;

	case Price:
		if (pItem->LDTheme)
			Dest.Int64 = pItem->LDCost;
		else
			Dest.Int64 = pCont->Price;
		Dest.Type = pInt64Type;
		return true;

	case ThemeID:
		Dest.Int = pItem->LDTheme;
		Dest.Type = pIntType;
		return true;

	case IsStackable:
		Dest.Int = ((EQ_Item*)pCont)->IsStackable();
		Dest.Type = pBoolType;
		return true;

	case IsLore:
		Dest.Int = pItem->Lore;
		Dest.Type = pBoolType;
		return true;

	case RaceMask:
		Dest.Int = pItem->Races;
		Dest.Type = pIntType;
		return true;

	case ClassMask:
		Dest.Int = pItem->Classes;
		Dest.Type = pIntType;
		return true;

	case CanUse:
		Dest.Int = pCharData->CanUseItem(&pCont, false, false);
		Dest.Type = pBoolType;
		return true;
	}
	return false;
}

