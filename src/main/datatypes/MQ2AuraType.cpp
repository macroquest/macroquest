#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2AuraType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	AURAINFO* pAura = (AURAINFO*)VarPtr.Ptr;
	if (!pAura)
		return false;

	int index = VarPtr.HighPart;

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2AuraType::FindMember(Member);
	if (pMember)
	{
		switch (static_cast<AuraTypeMembers>(pMember->ID))
		{
		case ID:
			Dest.DWord = index + 1;
			Dest.Type = pIntType;
			return true;

		case Find: {
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (!Index[0])
				return false;

			int pos = ci_find_substr(pAura->Name, Index);
			if (pos != -1)
			{
				Dest.DWord = pos + 1;
				return true;
			}

			return false;
		}

		case Name:
			strcpy_s(DataTypeTemp, pAura->Name);
			Dest.Ptr = DataTypeTemp;
			Dest.Type = pStringType;
			return true;

		case SpawnID:
			Dest.DWord = pAura->SpawnID;
			Dest.Type = pIntType;
			return true;

		default: break;
		};

		return false;
	}

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2AuraType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<AuraTypeMethods>(pMethod->ID))
		{
		case Remove:
			if (!pAuraWnd)
				break;

			if (CListWnd* clist = (CListWnd*)pAuraWnd->GetChildItem("AuraList"))
			{
				if (index > clist->ItemsArray.Count)
					break;

				clist->SetCurSel(index);
				pAuraWnd->WndNotification(clist, XWM_MENUSELECT, (void*)1);
				return true;
			}
			break;
		}
		return false;
	}

	return false;
}

