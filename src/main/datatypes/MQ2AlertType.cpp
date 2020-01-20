#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

MQ2AlertType::MQ2AlertType() : MQ2Type("alert")
{
	TypeMember(List);
	TypeMember(Size);
}

// /echo ${Alert[a].List[b].bGM}
// /echo ${Alert[a].Size}
// /echo ${Alert}
bool MQ2AlertType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!CAlerts.AlertExist(VarPtr.DWord))
		return false;

	MQTypeMember* pMember = MQ2AlertType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<AlertTypeMembers>(pMember->ID))
	{
	case List:
		if (IsNumber(Index))
		{
			Dest.DWord = MAKELONG(VarPtr.DWord, GetIntFromString(Index, 0));
			Dest.Type = pAlertListType;
			return true;
		}
		break;

	case Size:
		Dest.Type = pIntType;
		Dest.DWord = CAlerts.GetCount(VarPtr.DWord);
		return true;

	default: break;
	}

	return false;
}

bool MQ2AlertType::ToString(MQVarPtr VarPtr, char* Destination)
{
	std::vector<MQSpawnSearch> ss;

	if (CAlerts.GetAlert(VarPtr.DWord, ss))
	{
		_itoa_s(ss.size(), Destination, MAX_STRING, 10);
		return true;
	}

	return false;
}

